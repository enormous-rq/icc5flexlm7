### The Goal
Get an ancient Intel cpp compiler for linux compiling again. I suppose the best way to do this would be to build a license generator (if only I was smart). Said compiler is protected by FlexLM licensing (now defunct & it's modern ancestor revenera that owns the portfolio of the company that owned the portfolio of the original Globetrotters flexlm offers zero support for things this old. Intel also offers zero support)

This is the compiler that we can't get going. Against all odds we were able to source this file:

[cc010911rh71.tar](intel-cpp-compiler-5,0,1) [See Release Notes]("intel-cpp-compiler-5,0,1/Intel\(R\) C++ Compiler 5.0.1 Release Notes.md")

We were able to successfully install it on a redhat 7.1 UTM/QEMU emulation using the bundled install script. Not entirely sure using that old of an environment is even necessary, but I would imagine something 32bit would probably be key. After install, there's a variable setting script that can be run. All of the good setup-related stuff is outlined in [this document](intel-cpp-compiler-5,0,1/iccinstructions.md) I translated from a Japanese page. It includes

- Install instructions
- Sample license (very useful here to see what the license is supposed to look like)
- Two commands for setting path vars (one is an intel provided script)
- A custom script to start/stop/restart the license engine. The engine has to be "running" when you attempt to use the app and the license validation is technically done locally. Back in the day I'm sure this allowed companies to govern their own licensing servers on their LANs, I'm not sure. 

_Note - I was having weird issues until I renamed the license file license.lic but it's very possible I screwed other things up along the way._

--- 

##### The Problem

As for demonstrating being walled off by FlexLM, after placing a sample license file in `/opt/intel/licenses/license.lic` & sourcing the `icc` command into your shell using:

```
setenv PATH ${PATH}:${HOME}:/usr/local/bin:/opt/intel/compiler50/ia32/bin  
source /opt/intel/compiler50/ia32/bin/iccvars.csh
```

You can start the license daemon (either using script in above guide or simply `daemon /opt/intel/compiler50/flexlm/lmgrd -c /opt/intel/licenses/license.dat -l /opt/intel/licenses/license.log`)

You can simply run `icc` and run into the following error:

```
% icc
icc: error: could not checkout FLEXlm license
```

and then if you go check out the `lmgrd` log with `cat /opt/intel/licenses/license.log` you might see something like this:

```
18:05:20 (lmgrd) -----------------------------------------------
18:05:20 (lmgrd)   Please Note:
18:05:20 (lmgrd) 
18:05:20 (lmgrd)   This log is intended for debug purposes only.
18:05:20 (lmgrd)   There are many details in licensing policies
18:05:20 (lmgrd)   that are not reported in the information logged
18:05:20 (lmgrd)   here, so if you use this log file for any kind
18:05:20 (lmgrd)   of usage reporting you will generally produce
18:05:20 (lmgrd)   incorrect results.
18:05:20 (lmgrd) 
18:05:20 (lmgrd) -----------------------------------------------
18:05:20 (lmgrd) 
18:05:20 (lmgrd) 
18:05:20 (lmgrd) lmgrd running as root:
18:05:20 (lmgrd) 	This is a potential security problem
18:05:20 (lmgrd) 	And is not recommended
18:05:20 (lmgrd) FLEXlm (v7.0f) started on localhost.localdomain (linux) (10/4/2024)
18:05:20 (lmgrd) FLEXlm Copyright 1988-1999, Globetrotter Software, Inc.
18:05:20 (lmgrd) US Patents 5,390,297 and 5,671,412.
18:05:20 (lmgrd) World Wide Web:  http://www.globetrotter.com
18:05:20 (lmgrd) License file(s): /opt/intel/licenses/license.dat
18:05:20 (lmgrd) lmgrd tcp-port 27000
18:05:20 (lmgrd) Starting vendor daemons ... 
18:05:20 (intelpto) FLEXlm version 7.0f
18:05:20 (intelpto) Invalid license key (inconsistent authentication code)
18:05:20 (intelpto) 	==>FEATURE l_cpp intelpto 5.01 permanent uncounted 4AE8033BCA13 [...]
18:05:20 (intelpto) Server started on localhost.localdomain
18:05:20 (lmgrd) Started intelpto (internet tcp_port 32783 pid 1076)
```

...which, yeah, that checks out. Since you know.. I don't actually have a valid license key. It is my incredibly elementary understanding here that Intel, leveraging the FlexLM SDK at the time built a vendor daemon `intelpto` to interface with `lmgrd`. This seemed to be the way companies providing license issuance/evaluation were leveraging the FlexLM platform. Many of the guides from the early 2000's mention using the SDK in conjunction with their reverse-engineering, and I unfortunately wasn't able to source a linux-sdk. I did, however find a [Windows FlexLM 7.0 SDK install exe](maybe_useful_guides_tools/FLEXlm_SDK_Windows_7.0d.zip) that seems to provide all the things mentioned in these essays/guides, but it's unclear to me if this is useful. I did quickly run it through a windows xp emulation and confirmed the install seems to be clean, all the goods are installed to c:\program files\flexlm. Pretty weird looking kit but I was just a kid at the time these things were being released, I have no idea what software dev was like back then. I've uploaded the unpacked contents (from c:\program files\flexlm\v7.0\) [here](unpacked_flexlm_sdk_windows_v7.0), I believe the relevant source files are in /machined. SDK docs are in /htmlman.

I used this as a license file to generate the above log, and it differs slightly from the sample license generated in the guide above. Not sure if ditching the SIGN= did something here, but I'm way over my head. (the key is bogus). Note: `localhost.localdomain` isn't anything special, thats for whatever reason the hostname that came with this weird old Redhat instance I have running in an emulated environment.

```
SERVER localhost.localdomain ANY
DAEMON intelpto /opt/intel/compiler50/flexlm/intelpto
FEATURE l_cpp intelpto 5.01 permanent uncounted 4AE8033BCA13B HOSTID=ANY
```

---

### Addtl resources

---

https://gbppr.net/greythorne/crackz/Flexlm.htm

The above website seems to be the single-biggest repository of still-alive links to essays and tools around the subject. Most of the tools are Windows tools, and I am unable to source a Windows version of ICC 5.0.1's installation media so I've been unable to pursue most of this. But I have tried some and I'm just not sure I'm hunting for the right things, I've been at this mercilously for a week now and it's robbed me of my sanity. 

There is a tool in here that looks like it does it all (Flexgen) but I read quite a few posts on it not being able to reliable generate licenses (plus it sticks weird piracy-group name attribution to the license file). I had no luck with hit myself. 

Note: Essays/tools by Nolan Blender appear to be really solid. Siulflex's essay, from what I've gathered, was like the original infamous first-pass at defeating FlexLM. I don't recall what version that was for, but it sounds like he/she got the ball rolling. In that essay there is a perl script he provides to do the disassembly/memory stuff (things people probably use Ollydbg, IDA for now). The archiving/restoring of this site however has seemingly nerfed the code, but I think I successfully restored it [here](maybe_useful_guides_tools/dasm.pl). 

From what I've gathered most version numbers for FlexLM are important, especially 7.2 and on things get a little more sophisticated but still doable. Luckily for me, the flexlm instance blocking ICC 5.0 here is v7.0 (or at least that's what it says), and Nolan Blender had this comment in a [set of 7.2 tools](maybe_useful_guides_tools/Nolflex3.zip) (notably calcseed.exe) he provided for 7.2 extraction (see bolded emphasis for reference to "earlier" versions):

_calcseed.txt_:

> calcseed 1.0 
>
>This program is used to derive encryption seeds 1 and 2 from programs protected with version 7.2 FLEXlm.
>
>FLEXlm hides the seeds by creating special segments of code that generate encrypted versions of the vendorcode structure, which holds the encryption seeds.  A special decrypting subroutine is called from l_sg to reveal these seeds, but the standard implementation does not actually store the correct seeds in the vendorcode structure after the call - instead the data is xored with specific values stored in the job structure.  The specific bytes that are selected are based on the first character of the vendor name.
>
>**Earlier versions of FLEXlm could be forced to reveal the seeds by passing in a NULL pointer as the first argument to the lm_new routine.** This deficiency has been addressed in the latest version of FLEXlm, however the actual algorithm used by Globetrotter to select the bytes to XOR against has not been changed.

Ultimately, however, I have no idea what he's talking about. In that set of tools, however, there is something called lmkg.exe which seems to generate vendor keys. I'm still trying to wrap my brain around it all but it sounds like there are 5 vendor keys & two seeds of interest. I believe first couple maybe first four are derived from the vendor name, in this case 'intelpto', and the 5th isnt realibly generated in that tool. No idea if it's reliant on the seeds. The seeds are most obviously the thing of interest, and the talented folks seem to have no issue extracting these using whatever methods out of the daemon or lmgrd (not sure which one). From there I believe the construction of a license generator becomes possible. 

---

https://www.sporaw.com/work/license_managers/flexlm/licenses/cracked_i.htm

This list seems to provide 2 vendor keys that match with the vendor name from the intelpto daemon

```
VENDOR_KEY2: 0x7B624ECD	
VENDOR_KEY3: 0xD5CDAE59	
VENDOR_NAME: intelpto	
DESC: Intel C Compiler v5.0
```

I have no idea if this is useful, or even correct given its for v5.0 and not v5.0.1, and I wouldn't be able to tell you if it's relevant to Windows, Linux or both, and I have no idea what it was sourced from. Nevertheless, it could be useful. 
