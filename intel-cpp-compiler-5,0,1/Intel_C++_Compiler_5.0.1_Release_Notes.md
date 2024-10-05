[[Go back]](../README.md) 

Below is the release notes that I believe lives somewhere in the installed dirs. Can also be seen [here](http://laplace.phas.ubc.ca/Doc/intel50/CRelnotes.htm).

---

# Intel(R) C++ Compiler 5.0.1 for Linux Release Notes


### Contents
[[Overview]](#overview) [[What's New]](#whats-new) [[Package Contents]](#package-contents) [[Documentation]](#documentation) [[System Requirements]](#system-requirements) [[Installation]](#installation-notes) [[Known Limitations]](#known-limitations) [[Resolved Issues]](#resolved-customer-support-issues) [[Technical Support and Feedback]](#technical-support-and-feedback)

---

### Overview

This product provides tools for Linux\* software developers to create applications to run on IA-32 and Intel(R) Itanium(TM)-based systems. It consists of the following:

*   The Intel(R) C++ compiler for IA-32 based applications: icc.
*   The Intel(R) C++ compiler for Itanium-based applications: ecc.
*   The Linux Application Debugger 5.0 for IA-32 based applications: ldb.
*   The Intel Itanium Assembler 5.0 to produce Itanium-based applications: ias
*   The product documentation.

Note, the Intel C++ compiler for Itanium-based applications, ecc, is available as a cross compiler that runs on an IA-32 system and a native compiler that runs on an Itanium processor system. Future product releases may not contain the cross compiler for Itanium-based applications.

The paper, _Optimizing Applications with the Intel(R) C++ and Fortran Compilers for Linux\*_ , explains how to use the Intel compilers to optimize for the Pentium(R) 4 and Itanium processors and is available at [http://www.intel.com/software/products/compilers/c50/linux](http://www.intel.com/software/products/compilers/c50/linux). Additional information on the Intel Software Development Products is available at [http://www.intel.com/software/products/](http://www.intel.com/software/products/).

  

#### Compatibility with the GNU Compilers

The compilers have substantial compatibility with the GNU gcc compiler although this initial product release is not fully compatible with gcc. Additional details on the compatibility with gcc is available at [http://www.intel.com/software/products/compilers/c50/linux](http://www.intel.com/software/products/compilers/c50/linux).

*   **Source Compatibility:** The Intel compilers support the ANSI C and C++ standards. Some, but not all, of the GNU C language extensions are supported and because of this, the Linux kernel cannot be built with the Intel compilers for Linux.
*   **Binary Compatibility:** C language object files are compatible with object files or libraries compiled with gcc and the GNU glibc C language library is used in this product.
*   **Binary Compatibility:** C++ object files are not binary compatible with the GNU g++ compiler. One cannot link applications with C++ modules compiled with the Intel C++ compiler and the g++ compiler. The Intel C++ compiler for Itanium-based applications supports the C++ ABI for the Itanium architecture which, when fully implemented by compiler vendors, will allow C++ objects files and libraries to be compatible with different compilers. Details can be found in the paper, _Intel(R) Itanium(tm) Processor-specific Application Binary Interface(ABI),_ available for download on [http://developer.intel.com/design/ia-64/](http://developer.intel.com/design/ia-64/)
*   **Compiler Options Compatibility:** Some of the common gcc command line options are supported although not all are supported. Additional details are available at [http://www.intel.com/software/products/compilers/c50/linux](http://www.intel.com/software/products/compilers/c50/linux).

The following list has additional comments on the compiler package. See the [Known Limitations](#Known_Limitations) section for additional information.

*   The compilers do not support all of the GNU C language extensions. Since many standard GNU header files use these extensions, modified versions of these headers files which do not use these GNU extensions are redistributed with the compilers. The files are in the 'Substitute Header' package for the IA-32 based applications and 'Cross Environment' package for Itanium-based applications.
*   The 'Cross Environment' package contains the cross-linker for Itanium-based applications, and libraries and include files for Itanium-based operating system. These libraries and include files are provided in this distribution for your convenience, and are not supported or maintained by Intel. The sources for this build were obtained from [http://www.redhat.com/](http://www.redhat.com/). The package and documentation may be redistributed and/or modified under the terms of the GNU General Public License or the GNU Lesser General Public License as published by the Free Software Foundation. Specific terms are available online at [http://www.gnu.org](http://www.gnu.org) or from the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

  
---

### What's New

The Intel compilers for Linux support different Linux distributions depending on the package you install from the CD-ROM or download from our webstore. All of the different versions of the compiler are available on the CD-ROM. In addition, all of the different versions of the compiler are available for download from the Intel(R) Premier Support web site, see the [Technical Support and Feedback](#Technical_Support_and) section of this document for details on support.

The first package contains:

*   C++ compiler for IA-32 based applications running on Red Hat\* 6.2.
*   C++ native compiler for Itanium-based applications running on Turbolinux\* for Intel Itanium-based systems.
*   C++ cross compiler for Itanium-based applications running on IA-32 system with Red Hat 6.2 to generate applications running on Turbolinux for Intel Itanium-based systems.

The second package contains:

*   C++ compiler for IA-32 based applications running on Red Hat 7.1.
*   C++ native compiler for Itanium-based applications running on Red Hat 7.1 Beta for Intel Itanium-based systems.
*   Note, this package does not contain a cross compiler for Itanium-based applications.

The compilers have been validated to run on the following Linux distributions: Red Hat 6.2 and Red Hat 7.1 for IA-32 processors and Turbolinux Beta 3 and Red Hat 7.1 Beta for Intel Itanium-based systems. Notes on using the Intel compilers for Linux on different Linux distributions are available online at [http://www.intel.com/software/products/compilers/c50/linux/platformnotes.htm](http://www.intel.com/software/products/compilers/c50/linux/platformnotes.htm).

It is important to install the correct version of the compiler for your Linux distribution. For instance, the compiler for Red Hat 6.2 will not run under Red Hat 7.1 and simple `hello world` programs will not build.

The Linux Application Debugger 5.0 for IA-32 based applications (ldb) is available to debug C++ and Fortran applications. The ldb debugger provides improved debugging capabilities for Fortran applications, as well as features to display the MMX(TM), Streaming SIMD Extensions (SSE) and SSE2 registers in different formats. It also allows the modification of the floating point registers. It can be used from the command line, from within emacs or using [DDD](http://www.gnu.org/software/ddd/), the Data Display Debugger utility.

The Intel compilers for Linux running on IA-32 processors uses the GlobeTrotter\* FLEXlm\* electronic licensing technology. You need to obtain and install a valid license before the compilers can be successfully invoked from an IA-32 based system. The cross-compiler, which runs on an IA-32 based processor and generates Itanium-based applications, also requires a valid license. The native compiler for Itanium processors does not require a license. Instructions on installing the FLEXlm license are provided in the email sent to you with the license key. Detailed instructions for using FLEXlm are available online at [http://www.intel.com/software/products/compilers/c50/linux/FlexInstallProd.html](http://www.intel.com/software/products/compilers/c50/linux/FlexInstallProd.html). If you have a problem with installing or using a license, please submit an issue to Premier Support. See the [Technical Support and Feedback](#Technical_Support_and) section of this document for details on support.

---

### Package Contents

##### Intel C++ Compiler for IA-32 Based Applications

The Intel C++ compiler for IA-32 based applications contains the following components:

*   Intel C++ Compiler 5.0.1 for Linux for IA-32 applications: icc and icpc for C and C++ source files, respectively.
*   The C++ name demangler utility: iccfilt.
*   Linux Application Debugger 5.0 for IA-32 based applications: ldb
*   Substitute headers for use with the Intel C++ compiler.
*   The product documentation.

##### Intel C++ Compiler for Itanium-Based Applications

The Intel C++ compiler for Itanium-based applications contains the following components:

*   C++ cross compiler for Itanium-based applications: ecc and ecpc for C and C++ source files, respectively. The cross compiler runs on an IA-32 based computer.
*   Native C++ compiler for Itanium-based applications: ecc and ecpc for C and C++ source files, respectively. The native compiler runs on a computer with an Itanium processor.
*   The C++ name demangler utility: eccfilt.
*   Itanium Assembler 5.0 to produce Itanium-based applications: ias.
*   Cross environment which includes substitute header files, libraries and binary utilities such as ld, and ar. Only the basic system libraries are distributed. If your application needs to link additional libraries, the additional libraries need to be copied from the Itanium processor machine to the IA-32 software development machine.
*   The product documentation.
*   Note, there is no Linux Application Debugger 5.0 for Itanium-based applications.

Direct object generation is supported by the icc compiler, but not by the ecc compiler. The ecc compiler generates assembler files, then invokes the assembler to generate object files. Currently, assembler files produced by the ecc compiler will only assemble with the Intel assembler, ias.

##### Compiler Drivers

The IA-32 `icc` compiler driver is provided for C language files and the `icpc` compiler driver for the C++ language. The compilers for Itanium-based applications use `ecc` and `ecpc` for the C and C++ languages, respectively. The compiler driver determines the language to use based on the filename extension. When compiling preprocessed files (`*.i`), the `ecc (icc)` driver assumes the C language and `ecpc (icpc)` assumes the C++ language. It is recommend to use the C++ compiler drivers for C++ applications.

---

### Documentation

The compiler and assembler documentation is presented in HTML format with full navigation, search, and hypertext capabilities and is viewable with your web browser. The documents also have PDF versions for easier printing via [acroread\*, the Acrobat\* Reader for Linux](http://www.adobe.com/products/acrobat/readstep2.html).

The documentation is installed in the `<install-dir>/compiler50/docs` directory. Also, an HTML index document can be found at `<install-dir>/compiler50/docs/ccompindex.htm`. For information on the GNU glibc C language library, documentation can be obtained from the Linux OS vendor or from the GNU web site, [www.gnu.org](http://www.gnu.org).

### Viewing HTML Documentation

To view the HTML documentation with the Netscape\* browser, the following options need to be enabled:

> Edit-->Preferences-->Advanced-->enable Java  
> Edit-->Preferences-->Advanced-->enable JavaScript  
> Edit-->Preferences-->Advanced-->enable stylesheets

### Viewing PDF Documentation Files

You can read the PDF files using the `xpdf` utility or install [acroread, the Acrobat\* Reader for Linux](http://www.adobe.com/products/acrobat/readstep2.html). It is recommended to view the PDF documentation with Acrobat running within Netscape as this provides additional navigation features. To enable Netscape to start acroread, acroread needs to be installed in a directory searched by your PATH environment variable and you need to edit the browser's preferences. **NOTE: If acroread isn't configured correctly, you can overwrite the PDF files, requiring you to reinstall them.** If improperly configured, the acroread browser may prompt you to Save-As file, which if you click OK can overwrite the PDF documentation files.

Perform these steps needed to update your preferences for acroread:

> Edit-->Preferences-->Navigator--> Applications  
> Description: Portable Document Format  
> MIMEType: application/pdf  
> Suffixes: pdf  
> Application: acroread %s  

Another method to configure acroread is to add the following entry in the file .mailcap in your home directory:

> application/pdf; acroread %s

Depending on your version of the Netscape browser, you might need to disable (turn OFF) the "Automatically load images" option or the browser will freeze when you open the HTML documentation files, this means that you will then need to click on the images in the documentation if you want to see them while paging through the documentation with the browser. Turn OFF this option by clicking on: Edit-->Preferences-->Advanced-->Automatically load images and other data types.

---

### System Requirements

##### IA-32 Processor System Requirements

Note, the IA-32 compiler and the cross-compiler for Itanium-based systems are run on a IA-32 based system.

*   A computer based on a Pentium processor or subsequent IA-32 based processor. (Pentium 4 processor recommended)
*   128 MB of RAM   (256 MB recommended).
*   100 MB of disk space
*   Red Hat Linux 6.2 or Red Hat 7.1

##### Itanium Processor System Requirements

Note, the native compilers for Itanium-based systems run on an Itanium-based system.

*   A computer with an Itanium processor.
*   256 MB of RAM
*   100 MB of disk space
*   Turbolinux for Intel Itanium-based systems or Red Hat 7.1 Beta for Intel Itanium-based systems.
*   If running the cross compiler for Itanium-based applications, an IA-32 based system is required running Red Hat 6.2.

##### Support for Additional Linux Distributions

The compilers have been validated to run on the following Linux distributions: Red Hat 6.2 and Red Hat 7.1 for IA-32 processors and Turbolinux Beta 3 and Red Hat 7.1 Beta for Intel Itanium-based systems. Notes on using the Intel compilers for Linux on different Linux distributions are available online at [http://www.intel.com/software/products/compilers/c50/linux/platformnotes.htm](http://www.intel.com/software/products/compilers/c50/linux/platformnotes.htm).

---

### Installation Notes

This section describes the installation of the IA-32 compiler and the cross compiler for Itanium-based applications on an IA-32 system followed by a section on how to install the native compiler for Itanium-based applications.

##### Installing IA-32 Compiler and Cross Compiler for Itanium-based Applications

Perform the following steps to install the IA-32 compiler and the cross compiler for Itanium-based applications, both run on an IA-32 based system.

1.  Download the compiler package, selecting the package for the correct Linux distribution or insert the product CD-ROM which contains both packages. For the CD-ROM, the file README.TXT on the CD-ROM explains the Linux distributions supported and which directory on the CD-ROM to run the install from.
2.  To install the compiler package, performing the following instructions:
    1.  If you downloaded the compiler, untar the compiler package in a directory to which you have write access.
    2.  Become the root user, needed to run the rpm command, and execute the install script in the directory where the tar file was extracted.  
        `./install`  
        If you do not have access to the root account, it is possible to install the compiler without root access by unpacking the RPM files with rpm2cpio and editing the iccvars.sh (.csh) and eccvars.sh (.csh) files to include the directory where the compiler is installed and the location of the FLEXlm license file. The install script automates this procedure.
    3.  The Intel software products already installed will be listed, followed by a menu of products to install which includes:
        *   Intel Compiler for Itanium architecture
        *   Intel Compiler for 32-bit applications
        *   Linux Application Debugger
    4.  Select a package to install it. All necessary packages needed to use the product will also be installed. If a RPM package has already been installed, the install script will report this and say that the installation failed. It will then continue to the next RPM package that needs to be installed to use the product. The default RPM options `-U --replacefiles` are recommended to force the update of existing files. The recommended installation directory is `/opt/intel`.
    5.  After installation, the Intel packages installed will be redisplayed, followed by a redisplay of the install menu. Enter 'x' to exit the install script.
3.  Setup the environment for the compiler via the script iccvars.sh (.csh) for IA-32 based applications and eccvars.sh (.csh) for Itanium-based applications.
4.  Install the FLEXlm license in the directory pointed to by the `INTEL_FLEXLM_LICENSE` variable, the default location is `/opt/intel/licenses`. If you downloaded the product, the license file will be sent via email. If you purchased the CD-ROM version of the compiler, the license file is available on the CD-ROM in the main directory. Additional instructions on using the FLEXlm license manager can be found at [http://www.intel.com/software/products/compilers/f50/linux/FlexInstallProd.html](http://www.intel.com/software/products/compilers/f50/linux/FlexInstallProd.html).
5.  Run the compiler.

##### Installing the Native Compiler for Itanium-based Applications

Perform these steps to install the native compiler for Itanium-based applications. Note a FLEXlm license file is not required to use the native Itanium-based compiler.

1.  Download the compiler package, selecting the package for the correct Linux distribution or insert the product CD-ROM which contains both packages. For the CD-ROM, the file README.TXT on the CD-ROM explains the Linux distributions supported and which directory on the CD-ROM to run the install from.
2.  To install the compiler package, performing the following instructions:
    1.  If you downloaded the compiler, untar the compiler package in a directory to which you have write access.
    2.  Become the root user, needed to run the rpm command, and execute the install script.  
        `./install`  
        If you do not have access to the root account, it is possible to install the compiler without root access by unpacking the RPM files with rpm2cpio and editing the iccvars.sh (.csh) and eccvars.sh (.csh) files to include the directory where the compiler is installed. The install script automates this procedure.
    3.  The Intel software products already installed will be listed, followed by a menu of products to install which includes:
        *   Intel Compiler for Itanium architecture
    4.  Select a package to install it. All necessary packages needed to use the product will also be installed. If a RPM package has already been installed, the install script will report this and say that the installation failed. It will then continue to the next RPM package that needs to be installed to use the product. The default RPM options `-U --replacefiles` are recommended to force the update of existing files. The recommended installation directory is `/opt/intel`.
    5.  After installation, the Intel packages installed will be redisplayed, followed by a redisplay of the install menu. Enter 'x' to exit the install script.
3.  Setup the environment for the compiler via the script eccvars.sh (.csh) located in `<install-dir>/compiler50/ia64/bin/`
4.  Run the compiler.

##### Compiler Environment and configuration scripts

The tools in this product rely on the environment variables IA32ROOT, IA64ROOT, LD\_LIBRARY\_PATH, and INTEL\_FLEXLM\_LICENSE. The installation script (`install`) creates the compiler environment script files that set these variables and modifies the PATH variable to add the appropriate directories for the Intel compilers. These variables must be set correctly for the compiler to function properly; executing the script files before invoking the compilers will set them correctly.

Note: The script to setup the cross compiler for Itanium-based applications, that runs on an IA-32 system to generate Itanium-based applications, modifies the PATH variable so that the cross linker that will create Itanium-based applications will be called instead of the standard IA-32 system linker so you will not be able to link IA-32 executables without modifying your environment variables. This applies to linking IA-32 based applications with the Intel compiles or other compilers such as the GNU gcc compilers. Using separate command windows to build IA-32 applications and Itanium-based applications with the cross compiler will avoid the problem of having to modify your environment variables.

The names and locations of these scripts are:

*   <install-dir>/compiler50/ia32/bin/iccvars.sh(.csh)  
    To produce IA-32 applications
*   <install-dir>/compiler50/ia64/bin/eccvars.sh(.csh)  
    To produce Itanium-based applications

The installation program also creates compiler configuration files named `<install-dir>/compiler50/ia32/bin/icc.cfg` and `<install-dir>/compiler50/ia64/bin/ecc.cfg` that contain common settings for all compilations. You can edit these files to add additional default options. Note, if you install a compile update package, you need to save the configuration file if you have modified it to another filename so that the installation doesn't overwrite your modified file.

Please register for support after you install this product. See [Technical Support and Feedback](#Technical_Support_and) for registration instructions.

--- 

### Installation Warnings


##### Installation Warning for RPM 4.0.2

The installation script, `install`, cannot install to a non-default directory when running RPM 4.0.2. This is the version of RPM that is distributed with Red Hat 7.1. For this reason, you currently must install the compilers in the default directory, `/opt/intel` when running RPM 4.0.2. Please see the FAQ's for the C++ Linux compiler at [http://support.intel.com/support/performancetools/c/v5/linux](http://support.intel.com/support/performancetools/c/v5/linux) for more information on this issue.

##### Installation Warning for Intel C++ and Fortran compilers in Different Directories

It is not recommended to install the Intel C++ compiler for Linux and the Intel Fortran compiler for Linux in different directories The two compiler packages share common files and the default RPM options in the `install` script prevent the compilers to work correctly when installed in different directories. For this reason, it is recommended to install the compilers in the same directory.

##### Uninstalling the compilers

To uninstall the compilers, you need to become the root user to run RPM. An `uninstall` script is provided to uninstall the compiler packages.

*   To uninstall the Intel compilers for IA-32 applications, run the script in `<install-dir>/compiler50/ia32/bin/uninstall`
*   To uninstall the Intel compilers for Itanium-based applications, run the script in `<install-dir>/compiler50/ia64/bin/uninstall`

---

### Known Limitations

Please click on the appropriate link below to see additional notes and known limitations in the latest version of the compiler.

*   [Intel C++ Compiler to produce IA-32 applications](notes/icc_issues.txt).
*   [Intel C++ Compiler to produce Itanium-based applications](notes/ecc_issues.txt).

---

### Resolved Customer Support Issues

Please click on the appropriate link below to see which issues have been resolved in the latest version of the compiler.

*   [Intel C++ Compiler to produce IA-32 applications](notes/icc_fixes.txt) or
*   [Intel C++ Compiler to produce Itanium-based applications](notes/ecc_fixes.txt).

---

### Technical Support and Feedback

Your feedback is very important to us. To receive technical support for the tools provided in this product and technical information including FAQ's and compiler updates, you need to be registered for an Intel Premier Support account on our secure web site, [https://premier.intel.com/](https://premier.intel.com/).

If you currently have a Premier Support account for any other product, or do not have a Premier Support account at all, you must register for access to support for this product, "Intel C++ Compiler for Linux\*". You can register for an Intel Premier Support account at [http://support.intel.com/support/go/C/QuAD.htm](http://support.intel.com/support/go/C/QuAD.htm). Compiler support information, including top technical issues, is available at [http://support.intel.com/support/performancetools/c](http://support.intel.com/support/performancetools/c).

--- 

### Submitting Issues

To submit an issue via the Intel Premier Support website, perform the following steps:

1.  Go to [https://premier.intel.com/](https://premier.intel.com/). You need to have Java\* and Javascript\* enabled in your web browser to submit an issue.
2.  Type in your Login and Password. Both are case-sensitive.
3.  Click the "Submit" button.
4.  Read the Confidentiality Statement and click the "I Accept" button.
5.  Click on the "Go" button next to the "Product" drop-down list.
6.  Click on the "Submit Issue" link in the left navigation bar.
7.  Choose "Initiatives, technologies & tools" from the "Product Type" drop-down list.
8.  If this is a software or license-related issue choose " Intel(R) C++ Compiler" from the "Product Name" drop-down list. If this is a hardware-related issue with an Itanium-based system choose "Workstation SDV (Itanium(TM) Processor)" or "Server SDV (Itanium(TM) Processor)" from the "Product Name" drop-down list.
9.  Enter your question and complete the fields in the windows that follow to successfully submit the issue.

Please follow these guidelines when forming your problem report or product suggestion:

*   Describe your difficulty or suggestion. For problem reports please be as specific as possible, so we may reproduce the problem. For compiler problem reports, please include the compiler options and a small test case.
*   Describe your system configuration information. Be sure to include specific information that may be applicable to your setup: operating system, versions of glibc and kernel, name and version number of installed applications, and anything else that may be relevant to helping us address your issue.
*   Include the package ID for the component your support issue concerns. A package ID utility is available, `icid`. When `icid` is executed, the package ID is written to standard output. You must run the compiler configuration scripts (iccvars.sh or eccvars.sh) before using icid. Run `icid -icc` or `icid -ecc` to determine the package ID for the icc or ecc compilers. Run `icid -help` to obtain more options if you need to determine the package ID for another component.
*   If you have an error installing the compiler package, create a Customer support issue on the Intel Premier Support website and select `install error` for the issue type. See [Technical Support and Feedback](#Technical_Support_and) for instructions on how to register for support. If you were not able to install the compiler or cannot run `icid` to determine the package ID, enter the filename you downloaded as the package ID if you downloaded the compiler, or enter 5.0.1 CD-ROM if you have the CD version of the compiler.

A technical support engineer will respond within one (1) Intel business day.

---

### Copyright and Legal Information

Intel, Pentium, MMX and Itanium are trademarks or registered trademarks of Intel Corporation or its subsidiaries in the United States and other countries  

\* _Other names and brands may be claimed as the property of others_

Copyright (C) 2000, 2001 Intel Corporation. All Rights Reserved.
