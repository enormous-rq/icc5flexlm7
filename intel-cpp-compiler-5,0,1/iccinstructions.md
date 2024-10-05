[[Go back]](../README.md)

Translated from `http://www-bl20.spring8.or.jp/oboegaki/intel_linux.html#v5` [See original](origiccinstructions_japanese.html). V6 instructions can be ignored as I'm only interested in V5.

---

*Let's run Intel's compiler on RedHat Linux.*

*Intel is offering C++ and Fortran compilers for Linux for free. (Limited to non-commercial versions without support.) The performance as a compiler should be good, so this is a very attractive offer. I downloaded it as soon as I knew it was free, but it was quite challenging to get it running, so I decided to leave a memo.*

[Version 5](#version-5-instructions)
- [Download (no longer avail)](#1-first-download)
- [Install](#2-installing-the-compiler)
- [Setting environment variables](#3-setting-environment-variables)
- [License file](#4-placing-the-license-file)
- [Start daemon + script](#5-starting-the-daemon-auto-start-setup)

[Version 6](#version-60-instructions)

Machine Configuration

- Pentium 4 1.7GHz
- Memory 512MB
- HDD 60GB
- OS RedHat 7.1 (English version)
All work was done as root.

---

# Version 5 Instructions

### 1. First, download.

Visit Intel Developer Software, provide your name and email address, and you can download the packages. I downloaded the following two:

- C++: `cc010911rh71.tar`
- Fortran: `fc010821rh71.tar`

Simultaneously, a license file is sent to the registered email address.

- C++: `l_cpp.lic`
- Fortran: `l_for.lic`

Here's what the license file contents look like. Please check each yourself. (However, some license content has been changed.)

**l_cpp.lic**

```
FEATURE l_cpp intelpto 5.01 permanent uncounted BXXXXBBXXXX1 \
       HOSTID=ANY SN=NCOfx wpmb SIGN=DXXXX9EXXXX6
```

**l_cpp.lic**

```
FEATURE l_for intelpto 5.01 permanent uncounted 3YYYY55YYYYB \
       HOSTID=ANY SN=NCOfx wpmb SIGN=7YYYY2BYYYY0
```

### 2. Installing the Compiler

First, extract the files in an appropriate directory.

```
% tar xfv cc010911rh71.tar
```

After extraction, you get:
```
clicense
install
intel-icc-5.0.1-129.i386.rpm
intel-ldb-5.0.1-119.i386.rpm
intel-subh-5.0.1-118.i386.rpm
intel-xenv64-5.0.1-35.ia64.rpm
intel-ecc64-5.0.1-71.ia64.rpm
lgpltext
```

Then, run:

```
% ./install
```

You are asked:

```
Which of the following would you like to install?  
1. Intel(R) C++ Compiler for 32-bit applications, Version 5.0.1 Build 010730D0  
2. Linux Application Debugger, Version 5.0.1, Build 20010720.  
x. Exit.
```

Of course, you select 1. Read the notes carefully, "accept", and proceed with all default settings. Also, install the debugger.

Ensure /opt/intel/compiler50 and /opt/intel/licenses are expanded. Similarly, install Fortran.

### 3. Setting Environment Variables

Assuming the shell is tcsh, add the following two lines to ~/.cshrc.

```
setenv PATH ${PATH}:${HOME}:/usr/local/bin:/opt/intel/compiler50/ia32/bin  
source /opt/intel/compiler50/ia32/bin/iccvars.csh
```

Note! The last line of iccvars.csh might be incorrect.

Incorrect:
```setenv INTEL_FLEXLM_LICENSE=/opt/intel/licenses```
Correct:
```setenv INTEL_FLEXLM_LICENSE /opt/intel/licenses```

Correct this (maybe the creator confused it with bash). According to the manual:

```setenv INTEL_FLEXLM_LICENSE /opt/intel/licenses/license.dat```

Writing the full name is typical. (FLEXlm End Users Guide "3.1.2 Setting the Path with an Environment Variable"). Bash is not well understood, so it's omitted here...

### 4. Placing the License File

This compiler is free, but must be used while running the license program as a daemon. This is where the file sent by email is used. However, it cannot be used as is.

According to the "FLEXlm End Users Guide (English)" found at Intel's URL, you need to add the following two lines (FLEXlm End Users Guide "3.3 Sample License File").
```
SERVER machine_name MAC_address port_number  
DAEMON intelpto /opt/intel/compiler50/flexlm/intelpto
```
Essentially, a license.dat was created in /opt/intel/license.

*license.dat* !!! If you're getting a file format error in the lmgrd log, try naming the file license.lic
```
SERVER coffee BBAABBAABBAA 12000  
DAEMON intelpto /opt/intel/compiler50/flexlm/intelpto  
FEATURE l_cpp intelpto 5.01 permanent uncounted BXXXXBBXXXX1 HOSTID=ANY SN=NCOfx wpmb SIGN=DXXXX9EXXXX6  
```
In this case, the machine name is coffee, and its MAC address is BB:AA:BB:AA:BB:AA. Assign a port number that doesn't conflict with others. Since Fortran is also used, its license file is written consecutively. This way of writing is sufficient. (FLEXlm End Users Guide "3.2 License File Format").

### 5. Starting the Daemon (Auto-Start Setup)

After logging in, start the license program with:
```
% /opt/intel/compiler50/flexlm/lmgrd -c /opt/intel/licenses/license.dat -l /opt/intel/licenses/license.log
```
However, it's tedious to run this every time, so set it to start upon machine boot. 

Create a file called `lmgrd` (`chmod 755`) in `/etc/rc.d/init.d` and start it at runlevel 3 and 5.

```
% touch /etc/rc.d/init.d/lmgrd
% chmod 755 /etc/rc.d/init.d/lmgrd
% vi /etc/rc.d/init.d/lmgrd
```

With `vi` open, press `i` to go into insert mode and add the following script:

```
#! /bin/sh
#

# Source function library.
. /etc/rc.d/init.d/functions

# See how we were called.
case "$1" in
  start)
        echo -n "Starting lmgrd: "
        daemon /opt/intel/compiler50/flexlm/lmgrd -c /opt/intel/licenses/license.dat -l /opt/intel/licenses/license.log

        echo
        touch /var/lock/subsys/lmgrd
        ;;
  stop)
        echo -n "Stopping lmgrd: "
        killproc lmgrd

        echo
        rm -f /var/lock/subsys/lmgrd
        ;;
  status)
        status lmgrd
        ;;
  restart|reload)
        $0 stop
        $0 start
        ;;
  *)
        echo "Usage: lmgrd {start|stop|status|restart}"
        exit 1
esac

exit 0
```

Press your escape button exit insert mode and type `:wq` to save/write to the file.

After creating this, link it in two locations:
- `/etc/rc.d/rc3.d`
- `/etc/rc.d/rc5.d`

Avoid conflicts by appropriately choosing S98.
```
% ln -s ../init.d/lmgrd S98lmgrd
% /etc/rc.d/init.d/lmgrd start
```

If the process is running with `ps -ef`, it is mostly fine. Reboot here to check if the daemon runs automatically and if the environment variables are properly reflected.

### 6. Let's Try Using It.

Once this setup is done, if new users are added, completing "3. Setting Environment Variables" will suffice. Now do your best.

---

# Version 6.0 Instructions

**Steps up to 2 are the same as version 5.0**

### 3. Setting Environment Variables

Add to `~/.cshrc:`
```
setenv PATH ${PATH}:${HOME}:/usr/local/bin:/opt/intel/compiler60/ia32/bin  
source /opt/intel/compiler60/ia32/bin/iccvars.csh
```
### 4. License File

Simply copy the license file attached in the email:
```
% cp l_cpp_01234567.lic /opt/intel/licenses  
% cp l_for_76543210.lic /opt/intel/licenses
```
No need to worry about the daemon anymore. It has become much simpler...

If there are any mistakes, please contact Uesugi.

---

The above has been translated from this page `http://www-bl20.spring8.or.jp/oboegaki/intel_linux.html#v5`
[See original](origiccinstructions_japanese.html)