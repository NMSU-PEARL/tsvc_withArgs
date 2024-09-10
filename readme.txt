This work is based on "https://github.com/UoB-HPC/TSVC_2". 
Please read their README. 

Changes Made
In common.h, we introduced struct data_struct. In the main() function in
tsvc.c file, we used this struct to pass the function arguments which were
previously global. 


#make and run

The "makefile" is for gcc and clang, for both x86 (intel) and ARM.
It uses "shell  arch" command to detect the architecture. 
make COMPILER=clang [for build and run ]
make COMPILER=gcc [for build and run ]

The file "mk_icx.make" is for ICC.

