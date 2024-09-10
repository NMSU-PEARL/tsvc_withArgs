COMPILER=icx
ARCH=$(shell  arch)
CFLAGS = -O3 -march=skylake-avx512 -qopt-zmm-usage=high
ALL_CFLAGS = -qopt-report -qopt-report-file=icc_report.txt $(CFLAGS)

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
	$(COMPILER) $(ALL_CFLAGS)  -c -o $(COMPILER)_$(ARCH)_loops.o loops.c

clean:	
	rm -f *.o *.txt
