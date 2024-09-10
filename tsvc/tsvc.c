
/*
 * This is an executable test containing a number of loops to measure
 * the performance of a compiler. Arrays' length is LEN_1D by default
 * and if you want a different array length, you should replace every
 * LEN_1D by your desired number which must be a multiple of 40. If you
 * want to increase the number of loop calls to have a longer run time
 * you have to manipulate the constant value iterations. There is a dummy
 * function called in each loop to make all computations appear required.
 * The time to execute this function is included in the time measurement
 * for the output but it is neglectable.
 *
 *  The output includes three columns:
 *    Loop:        The name of the loop
 *    Time(Sec):     The time in seconds to run the loop
 *    Checksum:    The checksum calculated when the test has run
 *
 * In this version of the codelets arrays are static type.
 *
 * All functions/loops are taken from "TEST SUITE FOR VECTORIZING COMPILERS"
 * by David Callahan, Jack Dongarra and David Levine except those whose
 * functions' name have 4 digits.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#include "common.h"
#include "array_defs.h"

// array definitions
__attribute__((aligned(ARRAY_ALIGNMENT))) real_t flat_2d_array[LEN_2D*LEN_2D];

__attribute__((aligned(ARRAY_ALIGNMENT))) real_t x[LEN_1D];

__attribute__((aligned(ARRAY_ALIGNMENT))) real_t a[LEN_1D],b[LEN_1D],c[LEN_1D],d[LEN_1D],e[LEN_1D],
                                   aa[LEN_2D][LEN_2D],bb[LEN_2D][LEN_2D],cc[LEN_2D][LEN_2D],tt[LEN_2D][LEN_2D];

__attribute__((aligned(ARRAY_ALIGNMENT))) int indx[LEN_1D];

real_t* __restrict__ xx;
real_t* yy;




real_t s000(struct args_t * func_args,  struct data_struct *data_args );
real_t s111(struct args_t * func_args ,struct data_struct *data_args);
real_t s114(struct args_t * func_args,struct data_struct *data_args);
real_t s1111(struct args_t * func_args, struct data_struct *data_args);
real_t s112(struct args_t * func_args, struct data_struct *data_args);
real_t s1112(struct args_t * func_args, struct data_struct *data_args);
real_t s113(struct args_t * func_args, struct data_struct *data_args);
real_t s1113(struct args_t * func_args, struct data_struct *data_args);
real_t s115(struct args_t * func_args, struct data_struct *data_args);
real_t s1115(struct args_t * func_args, struct data_struct *data_args);
real_t s116(struct args_t * func_args, struct data_struct *data_args);
real_t s118(struct args_t * func_args, struct data_struct *data_args);
real_t s119(struct args_t * func_args, struct data_struct *data_args);
real_t s1119(struct args_t * func_args, struct data_struct *data_args);
real_t s121(struct args_t * func_args, struct data_struct *data_args);
real_t s122(struct args_t * func_args, struct data_struct *data_args);
real_t s123(struct args_t * func_args, struct data_struct *data_args);
real_t s124(struct args_t * func_args, struct data_struct *data_args);
real_t s125(struct args_t * func_args, struct data_struct *data_args);
real_t s126(struct args_t * func_args, struct data_struct *data_args);
real_t s127(struct args_t * func_args, struct data_struct *data_args);
real_t s128(struct args_t * func_args, struct data_struct *data_args);
real_t s131(struct args_t * func_args, struct data_struct *data_args);
real_t s132(struct args_t * func_args, struct data_struct *data_args);
real_t s141(struct args_t * func_args, struct data_struct *data_args);
real_t s151(struct args_t * func_args, struct data_struct *data_args);
real_t s152(struct args_t * func_args, struct data_struct *data_args);
real_t s161(struct args_t * func_args, struct data_struct *data_args);
real_t s1161(struct args_t * func_args, struct data_struct *data_args);
real_t s162(struct args_t * func_args, struct data_struct *data_args);
real_t s171(struct args_t * func_args, struct data_struct *data_args);
real_t s172(struct args_t * func_args, struct data_struct *data_args);
real_t s173(struct args_t * func_args, struct data_struct *data_args);
real_t s174(struct args_t * func_args, struct data_struct *data_args);
real_t s175(struct args_t * func_args, struct data_struct *data_args);
real_t s176(struct args_t * func_args, struct data_struct *data_args);
real_t s211(struct args_t * func_args, struct data_struct *data_args);
real_t s212(struct args_t * func_args, struct data_struct *data_args);
real_t s1213(struct args_t * func_args, struct data_struct *data_args);
real_t s221(struct args_t * func_args, struct data_struct *data_args);
real_t s1221(struct args_t * func_args, struct data_struct *data_args);
real_t s222(struct args_t * func_args, struct data_struct *data_args);
real_t s231(struct args_t * func_args, struct data_struct *data_args);
real_t s232(struct args_t * func_args, struct data_struct *data_args);
real_t s1232(struct args_t * func_args, struct data_struct *data_args);
real_t s233(struct args_t * func_args, struct data_struct *data_args);
real_t s2233(struct args_t * func_args, struct data_struct *data_args);
real_t s235(struct args_t * func_args, struct data_struct *data_args);
real_t s241(struct args_t * func_args, struct data_struct *data_args);
real_t s242(struct args_t * func_args, struct data_struct *data_args);
real_t s243(struct args_t * func_args, struct data_struct *data_args);
real_t s244(struct args_t * func_args, struct data_struct *data_args);
real_t s1244(struct args_t * func_args, struct data_struct *data_args);
real_t s2244(struct args_t * func_args, struct data_struct *data_args);
real_t s251(struct args_t * func_args, struct data_struct *data_args);
real_t s1251(struct args_t * func_args, struct data_struct *data_args);
real_t s2251(struct args_t * func_args, struct data_struct *data_args);
real_t s3251(struct args_t * func_args, struct data_struct *data_args);
real_t s252(struct args_t * func_args, struct data_struct *data_args);
real_t s253(struct args_t * func_args, struct data_struct *data_args);
real_t s254(struct args_t * func_args, struct data_struct *data_args);
real_t s255(struct args_t * func_args, struct data_struct *data_args);
real_t s256(struct args_t * func_args, struct data_struct *data_args);
real_t s257(struct args_t * func_args, struct data_struct *data_args);
real_t s258(struct args_t * func_args, struct data_struct *data_args);
real_t s261(struct args_t * func_args, struct data_struct *data_args);
real_t s271(struct args_t * func_args, struct data_struct *data_args);
real_t s272(struct args_t * func_args, struct data_struct *data_args);
real_t s273(struct args_t * func_args, struct data_struct *data_args);
real_t s274(struct args_t * func_args, struct data_struct *data_args);
real_t s275(struct args_t * func_args, struct data_struct *data_args);
real_t s2275(struct args_t * func_args, struct data_struct *data_args);
real_t s276(struct args_t * func_args, struct data_struct *data_args);
real_t s277(struct args_t * func_args, struct data_struct *data_args);
real_t s278(struct args_t * func_args, struct data_struct *data_args);
real_t s279(struct args_t * func_args, struct data_struct *data_args);
real_t s1279(struct args_t * func_args, struct data_struct *data_args);
real_t s2710(struct args_t * func_args, struct data_struct *data_args);
real_t s2711(struct args_t * func_args, struct data_struct *data_args);
real_t s2712(struct args_t * func_args, struct data_struct *data_args);
real_t s281(struct args_t * func_args, struct data_struct *data_args);
real_t s1281(struct args_t * func_args, struct data_struct *data_args);
real_t s291(struct args_t * func_args, struct data_struct *data_args);
real_t s292(struct args_t * func_args, struct data_struct *data_args);
real_t s293(struct args_t * func_args, struct data_struct *data_args);
real_t s2101(struct args_t * func_args, struct data_struct *data_args);
real_t s2102(struct args_t * func_args, struct data_struct *data_args);
real_t s2111(struct args_t * func_args, struct data_struct *data_args);
real_t s311(struct args_t * func_args, struct data_struct *data_args);
real_t s31111(struct args_t * func_args, struct data_struct *data_args);
real_t s312(struct args_t * func_args, struct data_struct *data_args);
real_t s313(struct args_t * func_args, struct data_struct *data_args);
real_t s314(struct args_t * func_args, struct data_struct *data_args);
real_t s315(struct args_t * func_args, struct data_struct *data_args);
real_t s316(struct args_t * func_args, struct data_struct *data_args);
real_t s317(struct args_t * func_args, struct data_struct *data_args);
real_t s318(struct args_t * func_args, struct data_struct *data_args);
real_t s319(struct args_t * func_args, struct data_struct *data_args);
real_t s3110(struct args_t * func_args, struct data_struct *data_args);
real_t s13110(struct args_t * func_args, struct data_struct *data_args);
real_t s3111(struct args_t * func_args, struct data_struct *data_args);
real_t s3112(struct args_t * func_args, struct data_struct *data_args);
real_t s3113(struct args_t * func_args, struct data_struct *data_args);
real_t s321(struct args_t * func_args, struct data_struct *data_args);
real_t s322(struct args_t * func_args, struct data_struct *data_args);
real_t s323(struct args_t * func_args, struct data_struct *data_args);
real_t s331(struct args_t * func_args, struct data_struct *data_args);
real_t s332(struct args_t * func_args, struct data_struct *data_args);
real_t s341(struct args_t * func_args, struct data_struct *data_args);
real_t s342(struct args_t * func_args, struct data_struct *data_args);
real_t s343(struct args_t * func_args, struct data_struct *data_args);
real_t s351(struct args_t * func_args, struct data_struct *data_args);
real_t s1351(struct args_t * func_args, struct data_struct *data_args);
real_t s352(struct args_t * func_args, struct data_struct *data_args);
real_t s353(struct args_t * func_args, struct data_struct *data_args);
real_t s421(struct args_t * func_args, struct data_struct *data_args);
real_t s1421(struct args_t * func_args, struct data_struct *data_args);
real_t s422(struct args_t * func_args, struct data_struct *data_args);
real_t s423(struct args_t * func_args, struct data_struct *data_args);
real_t s424(struct args_t * func_args, struct data_struct *data_args);
real_t s431(struct args_t * func_args, struct data_struct *data_args);
real_t s441(struct args_t * func_args, struct data_struct *data_args);
real_t s442(struct args_t * func_args, struct data_struct *data_args);
real_t s443(struct args_t * func_args, struct data_struct *data_args);
real_t s451(struct args_t * func_args, struct data_struct *data_args);
real_t s452(struct args_t * func_args, struct data_struct *data_args);
real_t s453(struct args_t * func_args, struct data_struct *data_args);
real_t s471(struct args_t * func_args, struct data_struct *data_args);
real_t s481(struct args_t * func_args, struct data_struct *data_args);
real_t s482(struct args_t * func_args, struct data_struct *data_args);
real_t s491(struct args_t * func_args, struct data_struct *data_args);
real_t s4112(struct args_t * func_args, struct data_struct *data_args);
real_t s4113(struct args_t * func_args, struct data_struct *data_args);
real_t s4114(struct args_t * func_args, struct data_struct *data_args);
real_t s4115(struct args_t * func_args, struct data_struct *data_args);
real_t s4116(struct args_t * func_args, struct data_struct *data_args);
real_t s4117(struct args_t * func_args, struct data_struct *data_args);
real_t s4121(struct args_t * func_args, struct data_struct *data_args);
real_t va(struct args_t * func_args, struct data_struct *data_args);
real_t vag(struct args_t * func_args, struct data_struct *data_args);
real_t vas(struct args_t * func_args, struct data_struct *data_args);
real_t vif(struct args_t * func_args, struct data_struct *data_args);
real_t vpv(struct args_t * func_args, struct data_struct *data_args);
real_t vtv(struct args_t * func_args, struct data_struct *data_args);
real_t vpvtv(struct args_t * func_args, struct data_struct *data_args);
real_t vpvts(struct args_t * func_args, struct data_struct *data_args);
real_t vpvpv(struct args_t * func_args, struct data_struct *data_args);
real_t vtvtv(struct args_t * func_args, struct data_struct *data_args);
real_t vsumr(struct args_t * func_args, struct data_struct *data_args);
real_t vdotr(struct args_t * func_args, struct data_struct *data_args);
real_t vbor(struct args_t * func_args, struct data_struct *data_args);




typedef real_t (*test_function_t) (struct args_t *,  struct data_struct *);


void time_function(test_function_t vector_func, void * arg_info, struct data_struct * data_info)

{
    struct args_t func_args = {.arg_info=arg_info};
    double result = vector_func(&func_args, data_info);

    double tic=func_args.t1.tv_sec+(func_args.t1.tv_usec/1000000.0);
    double toc=func_args.t2.tv_sec+(func_args.t2.tv_usec/1000000.0);

    double taken = toc-tic;

    printf("%10.3f\t%f\n", taken, result);
}

int main(int argc, char ** argv){
    int n1 = 1;
    int n3 = 1;
    int* ip;
    real_t s1,s2;
    init(&ip, &s1, &s2);

    printf("Loop \tTime(sec) \tChecksum\n");
    struct data_struct data; 

    data.flat_2d_array=flat_2d_array;
    data.x=x;
    data.a=a;
    data.b=b;
    data.c=c;
    data.d=d;
    data.e=e;
   data.aa= &aa[0][0];
    data.bb=&bb[0][0];
    data.cc=&cc[0][0];
    data.tt=&tt[0][0];
    data.indx=indx;
    data.Iterations=100000;
    data.lEN_1D= 32000; 
    data.lEN_2D= 256; 
 
time_function(&s000, NULL,&data);
    time_function(&s111, NULL,&data);
    time_function(&s1111, NULL,&data);
    time_function(&s112, NULL,&data);
    time_function(&s1112, NULL,&data);
    time_function(&s113, NULL,&data);
    time_function(&s1113, NULL,&data);
    time_function(&s114, NULL,&data);
    time_function(&s115, NULL,&data);
    time_function(&s1115, NULL,&data);
    time_function(&s116, NULL,&data);
    time_function(&s118, NULL,&data);
    time_function(&s119, NULL,&data);
    time_function(&s1119, NULL,&data);
    time_function(&s121, NULL,&data);
    time_function(&s122, &(struct{int a;int b;}){n1, n3},&data);
    time_function(&s123, NULL,&data);
    time_function(&s124, NULL,&data);
    time_function(&s125, NULL,&data);
    time_function(&s126, NULL,&data);
    time_function(&s127, NULL,&data);
    time_function(&s128, NULL,&data);
    time_function(&s131, NULL,&data);
    time_function(&s132, NULL,&data);
    time_function(&s141, NULL,&data);
    time_function(&s151, NULL,&data);
    time_function(&s152, NULL,&data);
    time_function(&s161, NULL,&data);
    time_function(&s1161, NULL,&data);
    time_function(&s162, &n1,&data);
    time_function(&s171, &n1,&data);
    time_function(&s172, &(struct{int a;int b;}){n1, n3},&data);
    time_function(&s173, NULL,&data);
    time_function(&s174, &(struct{int a;}){LEN_1D/2},&data);
    time_function(&s175, &n1,&data);
    time_function(&s176, NULL,&data);
    time_function(&s211, NULL,&data);
    time_function(&s212, NULL,&data);
    time_function(&s1213, NULL,&data);
    time_function(&s221, NULL,&data);
    time_function(&s1221, NULL,&data);
    time_function(&s222, NULL,&data);
    time_function(&s231, NULL,&data);
    time_function(&s232, NULL,&data);
    time_function(&s1232, NULL,&data);
    time_function(&s233, NULL,&data);
    time_function(&s2233, NULL,&data);
    time_function(&s235, NULL,&data);
    time_function(&s241, NULL,&data);
    time_function(&s242, &(struct{real_t a;real_t b;}){s1, s2},&data);
    time_function(&s243, NULL,&data);
    time_function(&s244, NULL,&data);
    time_function(&s1244, NULL,&data);
    time_function(&s2244, NULL,&data);
    time_function(&s251, NULL,&data);
    time_function(&s1251, NULL,&data);
    time_function(&s2251, NULL,&data);
    time_function(&s3251, NULL,&data);
    time_function(&s252, NULL,&data);
    time_function(&s253, NULL,&data);
    time_function(&s254, NULL,&data);
    time_function(&s255, NULL,&data);
    time_function(&s256, NULL,&data);
    time_function(&s257, NULL,&data);
    time_function(&s258, NULL,&data);
    time_function(&s261, NULL,&data);
    time_function(&s271, NULL,&data);
    time_function(&s272, &s1,&data);
    time_function(&s273, NULL,&data);
    time_function(&s274, NULL,&data);
    time_function(&s275, NULL,&data);
    time_function(&s2275, NULL,&data);
    time_function(&s276, NULL,&data);
    time_function(&s277, NULL,&data);
    time_function(&s278, NULL,&data);
    time_function(&s279, NULL,&data);
    time_function(&s1279, NULL,&data);
    time_function(&s2710, &s1,&data);
    time_function(&s2711, NULL,&data);
    time_function(&s2712, NULL,&data);
    time_function(&s281, NULL,&data);
    time_function(&s1281, NULL,&data);
    time_function(&s291, NULL,&data);
    time_function(&s292, NULL,&data);
    time_function(&s293, NULL,&data);
    time_function(&s2101, NULL,&data);
    time_function(&s2102, NULL,&data);
    time_function(&s2111, NULL,&data);
    time_function(&s311, NULL,&data);
    time_function(&s31111, NULL,&data);
    time_function(&s312, NULL,&data);
    time_function(&s313, NULL,&data);
    time_function(&s314, NULL,&data);
    time_function(&s315, NULL,&data);
    time_function(&s316, NULL,&data);
    time_function(&s317, NULL,&data);
    time_function(&s318, &n1,&data);
    time_function(&s319, NULL,&data);
    time_function(&s3110, NULL,&data);
    time_function(&s13110, NULL,&data);
    time_function(&s3111, NULL,&data);
    time_function(&s3112, NULL,&data);
    time_function(&s3113, NULL,&data);
    time_function(&s321, NULL,&data);
    time_function(&s322, NULL,&data);
    time_function(&s323, NULL,&data);
    time_function(&s331, NULL,&data);
    time_function(&s332, &s1,&data);
    time_function(&s341, NULL,&data);
    time_function(&s342, NULL,&data);
    time_function(&s343, NULL,&data);
    time_function(&s351, NULL,&data);
    time_function(&s1351, NULL,&data);
    time_function(&s352, NULL,&data);
    time_function(&s353, ip,&data);
    time_function(&s421, NULL,&data);
    time_function(&s1421, NULL,&data);
    time_function(&s422, NULL,&data);
    time_function(&s423, NULL,&data);
    time_function(&s424, NULL,&data);
    time_function(&s431, NULL,&data);
    time_function(&s441, NULL,&data);
    time_function(&s442, NULL,&data);
    time_function(&s443, NULL,&data);
    time_function(&s451, NULL,&data);
    time_function(&s452, NULL,&data);
    time_function(&s453, NULL,&data);
    time_function(&s471, NULL,&data);
    time_function(&s481, NULL,&data);
    time_function(&s482, NULL,&data);
    time_function(&s491, ip,&data);
    time_function(&s4112, &(struct{int*a;real_t b;}){ip, s1},&data);
    time_function(&s4113, ip,&data);
    time_function(&s4114, &(struct{int*a;int b;}){ip, n1},&data);
    time_function(&s4115, ip,&data);
    time_function(&s4116, &(struct{int * a; int b; int c;}){ip, LEN_2D/2, n1},&data);
    time_function(&s4117, NULL,&data);
    time_function(&s4121, NULL,&data);
    time_function(&va, NULL,&data);
    time_function(&vag, ip,&data);
    time_function(&vas, ip,&data);
    time_function(&vif, NULL,&data);
    time_function(&vpv, NULL,&data);
    time_function(&vtv, NULL,&data);
    time_function(&vpvtv, NULL,&data);
    time_function(&vpvts, &s1,&data);
    time_function(&vpvpv, NULL,&data);
    time_function(&vtvtv, NULL,&data);
    time_function(&vsumr, NULL,&data);
    time_function(&vdotr, NULL,&data);
    time_function(&vbor, NULL,&data);

    return EXIT_SUCCESS;
}
