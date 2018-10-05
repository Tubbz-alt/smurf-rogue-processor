# smurf stream processor

A repository containing pyrogue module for smurf stream processing.

## Sub Directories

### matlab

matlab filtering and codegen

### rogue-module

Rogue module for processing v0 smurf streaming frames.

## Building the project

````
$ cd matlab/codegen/lib/process_frame_v0
$ make
$
$ cd ../../../../rogue-module/
$ source setup.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
````

