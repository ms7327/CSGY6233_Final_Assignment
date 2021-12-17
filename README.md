# CS-GY 6233 Final Project
Professor Kamen Yotov Phd

By Xiao Lin Zhong xz3343 and Mohammed Sujon ms7327

## Description
This is the repo for the final project for CS-GY 6233. Information regarding the contents of the repo, and how to run are contained herein. 

## Included Files
```
1. README.md
2. build.sh - Used to compile all of the C code   
3. run.c    
4. run_lseek.c                       
5. fast.c                          
6. run2.sh
7. run3.sh
8. run5.sh
9. run5_lseek.sh        
```                     

## Building the C files
The build shell script can be used to compile all of the C code, usage is shown below:
```
./build.sh
```

##  Commands and Usages
Please run the command below only after the C files are built. 

### run.c 
```
./run <filename> [-r|-w] <block_size> <block_count>
```
### run_lseek.c
```
./run_lseek <filename> [-r|-w] <block_size> <block_count>
``` 

### fast.c
```
./fast <filename>
```

### run2.sh
```
./run2.sh <filename> <block_size>
```

### run3.sh
```
./run3.sh <filename> <block_count>
```

### run5.sh
```
./run5.sh <filename>
```

### run5_lseek.sh
```
./run5_lseek.sh <filename>
```