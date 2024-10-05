#!/usr/bin/perl
push(@INC,"/usr/lib/perl5");
require("flush.pl");

# LINUX DISASSEMBLER 2.01
# (C) SiuL+Hacky Aug 1998

use strict;
use warnings;

my $f_input = $ARGV[0];
my $f_output = $ARGV[1];

printflush(*STDOUT, "\nCreating disassembled file ...");

my $return = system("objdump -d -T -x --prefix-addresses $f_input > $f_output" . "2");

if ($return != 0) {
    print "\nERROR OPENING OBJDUMP $return";
    print "\nUsage: dasm exe_file dasm_file";
    print "\nBe sure to get objdump in your path. Check also file permissions\n";
    exit(1);
}

open(INPUT, "<", "$f_output" . "2");

printflush(*STDOUT, "\nReading strings ...");
$_ = <INPUT>;

while (!/.rodata/) {
    $_ = <INPUT>;
}
my ($rubbish, $rest) = split(/\.rodata/, $_, 2);
($rubbish, $rest) = split(/0/, $rest, 2);

my @numbers = split(/  /, $rest, 5);

my $size = hex($numbers[0]);
my $starting_address = hex($numbers[1]);
my $end_address = $starting_address + $size;
my $offset = hex($numbers[3]);

open(CODIGO, "<", $f_input);
seek(CODIGO, $offset, 0);
read(CODIGO, my $cadena, $size);
close(CODIGO);

$_ = <INPUT>;

while (defined($_ = <INPUT>)) {  
    last if /SYMBOL TABLE/;
}


printflush(*STDOUT, "\nProcessing symbol table ...");
$_ = <INPUT>;

my %symbol_table;
while (!/^\n/) {
    my @st_element = split(/ /, $_);
    $_ = $st_element[$#st_element];
    chop;
    $symbol_table{$st_element[0]} = $_;
    $_ = <INPUT>;
}

while (!/\.text/) {
    $_ = <INPUT>;
}

printflush(*STDOUT, "\nProcessing jmps and calls ...");

my %salto;
my %call;

while (<INPUT>) {
    $_ =~ s/<//g;
    $_ =~ s/  / /g;
    if (/j/) {
        my ($direccion, $inst, $destino) = split(/ /, $_, 3);
        $destino =~ s/ //g;
        chomp($destino);
        $salto{$destino} .= ($direccion . " ; ");
    } elsif (/call/) {
        my ($direccion, $inst, $destino) = split(/ /, $_, 3);
        $destino =~ s/ //g;
        chomp($destino);
        $call{$destino} .= ($direccion . " ; ");
    }
}

seek(INPUT, 0, 0);
printflush(*STDOUT, "\nWriting references ...\n");

open(OUTPUT, ">", $f_output) || die "Error opening write file\n";
print OUTPUT "FILE REFERENCED\n\n";

while (!/Disassembly of section .text:/) {
    $_ = <INPUT>;
    print OUTPUT;
}

my $char = ".";
my $counter = 0;

while (<INPUT>) {
    $counter++;
    if (($counter % 400) == 0) {
        printflush(*STDOUT, $char);
        if (($counter % 4000) == 0) {
            printflush(*STDOUT, "\r");
            $char = $char eq "." ? " " : ".";
        }
    }
    
    my $copia = $_;
    $_ =~ s/<//g;
    $_ =~ s/  / /g;

    my ($direccion, $inst, $destino) = split(/ /, $_, 3);

    if (defined($symbol_table{$direccion})) {
        print OUTPUT "\n";
        print OUTPUT "---- Function : " . $symbol_table{$direccion} . " ----\n";
    }

    if (/call/) {
        $destino =~ s/ //g;
        chomp($destino);
        if (defined($symbol_table{$destino})) {
            print OUTPUT "\n";
            print OUTPUT "Reference to function : " . $symbol_table{$destino} . "\n\n";
        }
    }
    
    if (defined($salto{$direccion})) {
        print OUTPUT "\n";
        print OUTPUT "Referenced from jump at " . $salto{$direccion} . "\n\n";
    }
    
    if (defined($call{$direccion})) {
        print OUTPUT "\n";
        print OUTPUT "Referenced from call at " . $call{$direccion} . "\n\n";
    }
    
    if (/\$/) {
        my ($instruccion, $operand) = split(/\$/, $_, 2);

        if (!/push/) {
            ($operand) = split(/\,/, $operand, 2);
        }

        chomp($operand);
        my $offset = hex($operand);

        if (($offset <= $end_address) && ($offset >= $starting_address)) {
            my $auxiliar = substr($cadena, $offset - $starting_address);
            my $length = index($auxiliar, pack("x"));
            $auxiliar = substr($auxiliar, 0, $length);
            $auxiliar =~ s/\n//g;
            print OUTPUT "\nPossible reference to string:\n\"$auxiliar\"\n\n";
        }
    }

    print OUTPUT $copia;
}

close(INPUT);
close(OUTPUT);
print "\n";
system("rm " . $f_output . "2");
