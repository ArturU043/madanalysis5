# Welcome to MadAnalysis 5

[![PAD](https://img.shields.io/static/v1?style=plastic&label=Recasting&message=PublicAnalysisDatabase&color=blue)](http://madanalysis.irmp.ucl.ac.be/wiki/PublicAnalysisDatabase)
[![TUTO](https://img.shields.io/static/v1?style=plastic&label=Tutorials&message=@HomePage&color=red)](https://madanalysis.irmp.ucl.ac.be/wiki/tutorials)
[![Talks](https://img.shields.io/static/v1?style=plastic&label=Talks&message=@HomePage&color=red)](http://madanalysis.irmp.ucl.ac.be/wiki/Talks)
[![FAQ](https://img.shields.io/static/v1?style=plastic&label=FAQ&message=NormalMode&color=orange)](http://madanalysis.irmp.ucl.ac.be/wiki/FAQNormalMode)

![Python v3.8](https://img.shields.io/badge/python-3670A0?style=plastic&logo=python&logoColor=ffdd54&label=3.8&color=brightgreen)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=plastic&logo=c%2B%2B&logoColor=white&label=11)
## Outline
 - [What is MadAnalysis 5?](#what-is-madanalysis-5)
 - [Requirements](#requirements)
 - [Downloading and installing the MadAnalysis 5 package](#downloading-and-installing-the-madanalysis-5-package)
 - [Usage of MadAnalysis 5](#usage-of-madanalysis-5)
 - [Description of the package](#description-of-the-package)
 - [Very first steps with MadAnalysis 5](#very-first-steps-with-madanalysis-5)
 - [Troubleshootings and bug reports](#troubleshootings-and-bug-reports)
 - [Supported third party software](#supported-third-party-software)
 - [Authors](#authors)
 - [Developer's Guide: How to contribute to MadAnalysis 5](./doc/CONTRIBUTING.md)
 - [Our famous last words](#our-famous-last-words)
 - [Credits](#credits)



### What is MadAnalysis 5? 

MadAnalysis 5 is a framework for phenomenological investigations at particle
colliders. Based on a C++ kernel, this program allows to efficiently perform, in
a straightforward and user-friendly fashion, sophisticated physics analyses of
event files such as those generated by a large class of Monte Carlo event
generators.

The first running mode ([Normal Mode](https://madanalysis.irmp.ucl.ac.be/attachment/wiki/WikiStart/normal_mode_v1.8.pdf)) of the program, easier to handle, uses the strengths of a
powerful Python interface in order to implement physics analyses by means of a
set of intuitive commands.

The second running mode ([Expert Mode](http://madanalysis.irmp.ucl.ac.be/raw-attachment/wiki/WikiStart/MadAnalysis_5_v1_6___Expert_Mode.pdf)) requires to implement the analyses in the C++
programming language, directly within the core of the analysis framework. This
opens unlimited possibilities concerning the level of complexity that can be
reached, the latter being only limited by the programming skills and the
originality of the user.

More details can be found on the [MadAnalysis 5 website](https://madanalysis.irmp.ucl.ac.be).

### Requirements

MadAnalysis 5 requires several external libraries in order to properly run:

 - Python 3.8 or a more recent version that can be downloaded from [this website](http://www.python.org/)
   In order to check the installed version of Python on a system, it is
   sufficient to issue in a shell `$ python --version`.

 - Either the GNU GCC compiler, or the Apple clang compiler. MadAnalysis 5 has been validated:
     - with the version (minimum) `7.0` of the GCC compiler. The GCC compiler can be downloaded from [this website](http://gcc.gnu.org/).
     - with the version 13.1.6 (clang-1316.0.21.2) of the clang compiler.

To benefit from all options coming with the MadAnalysis 5 program, the following
(optional) libraries have to be installed on the system:
 - Zlib headers and libraries that can be downloaded from [this website](http://zlib.net/) which can 
also be downloaded by by typing `ma5> install zlib` through MadAnalysis interface.
 - The FastJet package version 3.3, or a more recent version, that can be
   downloaded from [this link](http://fastjet.fr/). This package can also be installed by 
  typing `ma5> install fastjet` in MadAnalysis.
 - LaTeX and `pdflatex` compilers for report rendering.
 - All Python libraries that MadAnalysis 5 requires can be installed by typing 
`$ python3 -m pip install -r requirements.txt`.

### Downloading and installing the MadAnalysis 5 package

We are moving from our previous location in [Launchpad](https://launchpad.net/madanalysis5) but the latest MadAnalysis 5
version can still be downloaded through [here](https://launchpad.net/madanalysis5) until the 
release of `v1.10`. Note that future versions will only be available through GitHub. 

If you satisfy the requirements mentioned [above](#requirements) the only thing that you need to do is
 download the latest release from [here](https://github.com/MadAnalysis/madanalysis5/releases) and 
start playing;
```bash
$ cd madanalysis5
$ ./bin/ma5
```
During your first execution MadAnalysis 5 will build the entire workspace automatically. 
Note that release versions are always the stable ones the main repository will be under constant 
development.

### Usage of MadAnalysis 5

Syntax: `./bin/ma5 [options] [scripts]`
```
[options]
This optional argument allows to select the running mode of MadAnalysis 5 appropriate 
to the type of event files to analyze. If absent, the parton-level mode is selected. 
Warning: the different modes are self-excluding each other and only one choice has to be made.

List of available options :
 -P or --partonlevel  : parton-level mode
 -H or --hadronlevel  : hadron-level mode
 -R or --recolevel    : detector-level mode
 -e or -E or --expert : entering expert mode
 -v or --version
    or --release      : display the version number of MadAnalysis
 -b or --build        : rebuild the SampleAnalyzer static library
 -f or --forced       : do not ask for confirmation when MA5 removes a directory or overwrites an object
 -s or --script       : quit automatically MA5 when the script is loaded
 -h or --help         : dump this help
 -i or --installcard  : produce the default installation card in installation_card.dat
 -d or --debug        : debug mode
 -q or --qmode        : developper mode only for MA5 developpers

[scripts]
This optional argument is a list of filenames containing a set of MadAnalysis 5 commands. 
The file name are handled as concatenated, and the commands are applied sequentially.
```
### Description of the package

The directory structure of the MadAnalysis 5 package can be summarized as
follows:
```
   +  bin                | This directory contains the executable file 'ma5'.
   +  madanalysis        | This directory contains all the source files of
                         |   MadAnalysis 5.
      +   configuration  | This directory contains functions related to the
                         |   configuration of the dependencie such as FastJet.
      +   core           | This directory contains the core of the Python
                         |   interface.
      +   dataset        | This directory contains the functions related to the
                         |   handling of Monte Carlo event files in MadAnalysis
                         |   5.
      +   enumeration    | This directory contains the definition of the
                         |   keywords used by within the Python source files. 
      +   input          | This directory contains the lists of (multi)particles
                         |   to be loaded at the start-up of MadAnalysis 5.
      +   IOinterface    | This directory contains routines related to
                         |   input/output flows.
      +   interpreter    | This directory contains all the commands available
                         |   within the Python interface of MadAnalysis 5.
      +   job            | This directory contains the routines necessary for
                         |   the creation and execution of C++ jobs.
      +   layout         | This directory contains all the functions necessary
                         |   for handling the layout of the figures and reports
                         |   produced by MadAnalysis 5. 
      +   multiparticle  | This directory contains the functions related to the
                         |   handling of multiparticle and particle collections.
      +   observable     | This directory contains the list of observables
                         |   supported within MadAnalysis 5.
      +   selection      | This directory contains the routines necessary for
                         |   producing histograms and applying event selection
                         |   cuts.
   +  tools              | This directory contains the packages that are used
                         |   by MadAnalysis 5.
      +   SampleAnalyzer | This directory contains the C++ kernel of
                         |   MadAnalysis, dubbed SampleAnalyzer (see below).
      +   Glue           | This directory contains the glues allowing to use
                         |   showering programs (not supported yet).
  (+) samples            | This optional directory is dedicated to event sample
                         |   storage. 
```
The main file of the package is also the only one which is supposed to be run on
a system: 
```bash
$ ./bin/ma5
```
In addition, several text files are dedicated to specific information:
  - `README`: this file,
  - `COPYING`: the description of the software license,
  - `version.txt`: general information about the installed release,
  - `madanalysis/UpdateNotes.txt`: the update notes.

The C++ kernel of MadAnalysis is stored in the directory
  `tools/SampleAnalyzer`
This directory has the following structure: 
```
   + tools
     + SampleAnalyzer
       + Analyzer         | This directory contains the skeleton for the
                          |   analysis class as well as for the merging plots.
       + Core             | This directory contains the main routines.
       + Counter          | This directory contains routines related to
                          |   histogram and cut referencing.
       + DataFormat       | This directory contains the implementation of the
                          |   employed data format for handling event samples
                          |   and the related information.
       + Filter           | This directory contains routines for applying event
                          |   filtering (to be developped in the future).
       + JetClustering    | This directory contains routines dedicated to jet
                          |   clustering algorithms.
       + Lib              | This directory store the SampleAnalyzer library,
                          |   once compiled.
       + Plot             | This directory contains all the methods related to
                          |   histogram generation.
       + Reader           | This directory contains the definition of classes
                          |   dedicated to the reading of the event files. 
       + Service          | This directory contains services (logger, physics
                          |   tools, ...)
       + Writer           | This directory contains the definition of classes
                          |   dedicated to the writing of event files and
                          | result files.
     + newAnalyzer.py     | This script allows to create a blank analysis.
     + newFilter.py       | This script allows to create a blank filter.
```
The Glue directory contains routines dedicated to future developments and are
thus neither supporter, nor documented.

The associated Doxygen documentation can be found on the [MadAnalysis 5 wiki](http://madanalysis.irmp.ucl.ac.be/wiki/doxygen).  

### Very first steps with MadAnalysis 5

To start MadAnalysis 5, it is enough to type in a shell `./bin/ma5`

In a first step, the program checks all the dependencies and provide warning
and/or error messages if necessary. Next, the `SampleAnalyzer` C++ kernel library
is generated. This is performed once and for all at the first run of MadAnalysis 
- Let us however note that if the system configuration changes, this is
detected by MadAnalysis 5 and the library is regenerated.

If everything is going as smoothly as it should, a Python command line interface
with a `ma5>` prompt appears. To learn how to use MadAnalysis 5 and to get an
overview of its functionalities, we refer in particular to Section 3 of the
manual that can be found [here](http://arxiv.org/abs/1206.1599).

### Troubleshootings and bug reports

Any public release of MadAnalysis 5 has been automatically and intensely
validated. However, especially due to the variety of possible system
configurations and the large number of functionalities included in the program,
it is not impossible that some bugs are found. In this case, is is strongly
suggested to create a report on [GitHub Issues](https://github.com/MadAnalysis/madanalysis5/issues).

In this way, you also participate to the improvement of MadAnalysis 5 and the
authors thank you for this.

### Supported third party software

In the following you can find supported third party software that can be used within MadAnalysis 5.
The [latest release](https://github.com/MadAnalysis/madanalysis5/releases) of MadAnalysis 5 has been tested with enlisted versions.

- [FastJet](http://fastjet.fr) v3.3.3
- [Delphes](https://github.com/delphes/delphes) v3.4.3
- [ROOT](https://root.cern) v6.04.08
- [pyhf](https://github.com/scikit-hep/pyhf) v0.7.0

### Authors

MadAnalysis 5 is openly developed by the core dev team consisting of:
- [Jack Y. Araz](mailto:jack.araz@durham.ac.uk)
- [Benjamin Fuks](mailto:fuks@lpthe.jussieu.fr)
- [Eric Conte](mailto:eric.conte@iphc.cnrs.fr)

### Our famous last words

The development team of MadAnalysis 5 hopes that the package will meet the
expectations of the users and help particle physicists in their phenomenological
investigations.

That's all folks!

### Credits

If you use MadAnalysis 5, please cite:

 - [E. Conte, B. Fuks and G. Serret; Comput. Phys. Commun. 184 (2013) 222](http://arxiv.org/abs/1206.1599)
 - [E. Conte, B. Dumont, B. Fuks and C. Wymant; Eur. Phys. J. C 74 (2014) 10, 3103](http://arxiv.org/abs/1405.3982)
 - [B. Dumont, B. Fuks, S. Kraml et al.; Eur. Phys. J. C 75 (2015) 2, 56](http://arxiv.org/abs/1407.3278)
 - [E. Conte, and B. Fuks; Int. J. Mod. Phys. A 33 (2018) 1830027](http://arxiv.org/abs/1808.00480)
 - [J. Y. Araz, M. Frank and B. Fuks; Eur. Phys. J. C 80 (2020) 6, 531](https://arxiv.org/abs/1910.11418)
 - [J. Y. Araz, B. Fuks and G. Polykratis; Eur. Phys. J. C 81 (2021) 329](https://arxiv.org/abs/2006.09387)
 - [J. Y. Araz, B. Fuks, M. D. Goodsell and M. Utsch; Eur. Phys. J. C 82 (2022) 597](https://arxiv.org/abs/2112.05163)
 - [G. Alguero, J. Y. Araz, B. Fuks, S. Kraml; arXiv:2206.14870](https://arxiv.org/abs/2206.14870)
