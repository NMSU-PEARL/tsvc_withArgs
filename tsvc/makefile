COMPILER=gcc
ARCH=$(shell  arch)
FLAGS = -O3 
	ifeq ($(ARCH),x86_64)
	CFLAGS= -march=skylake-avx512 -mprefer-vector-width=512 $(FLAGS)
	else
	CFLAGS= -mcpu=a64fx+sve -msve-vector-bits=512 $(FLAGS)
	endif	
	ifeq ($(COMPILER),gcc) 
	ALL_CFLAGS = -fopt-info-all $(CFLAGS)
	else
	ALL_CFLAGS = -Rpass=loop-vectorize -Rpass-missed=loop-vectorize $(CFLAGS)
	endif
all:	run

run:	$(COMPILER)_$(ARCH).o
	./$(COMPILER)_$(ARCH).o >  $(COMPILER)_$(ARCH)_timing.txt
	objdump -d $(COMPILER)_$(ARCH).o > $(COMPILER)_$(ARCH)_objdump.txt
	lscpu > $(COMPILER)_$(ARCH)_cpu_info.txt

$(COMPILER)_$(ARCH).o:	$(COMPILER)_$(ARCH)_dummy.o $(COMPILER)_$(ARCH)_common.o $(COMPILER)_$(ARCH)_tsvc.o $(COMPILER)_$(ARCH)_loops.o
	$(COMPILER)  $(COMPILER)_$(ARCH)_dummy.o $(COMPILER)_$(ARCH)_common.o $(COMPILER)_$(ARCH)_tsvc.o $(COMPILER)_$(ARCH)_loops.o -lm -o $(COMPILER)_$(ARCH).o
$(COMPILER)_$(ARCH)_dummy.o:	dummy.c
	$(COMPILER) $(CFLAGS)  -c -o $(COMPILER)_$(ARCH)_dummy.o dummy.c				
$(COMPILER)_$(ARCH)_common.o:	common.c
	$(COMPILER) $(CFLAGS) -c -o $(COMPILER)_$(ARCH)_common.o common.c 			
$(COMPILER)_$(ARCH)_tsvc.o:	tsvc.c
	$(COMPILER) $(CFLAGS) -c -o $(COMPILER)_$(ARCH)_tsvc.o tsvc.c			
$(COMPILER)_$(ARCH)_loops.o:	loops.c
	$(COMPILER) $(ALL_CFLAGS)  -c -o $(COMPILER)_$(ARCH)_loops.o loops.c 2>$(COMPILER)_$(ARCH)_report.txt

clean:	
	rm -f *.o *.txt
