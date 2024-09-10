#ifndef TSVC_COMMON_HDR
#define TSVC_COMMON_HDR

#define iterations 100000
#define LEN_1D 32000
#define LEN_2D 256

#include <sys/time.h>

struct args_t {
    struct timeval t1;
    struct timeval t2;
    void * __restrict__ arg_info;
};



#if 0
typedef double real_t;
#define ABS fabs
#else
typedef float real_t;
#define ABS fabsf
#endif

struct data_struct  
{
 real_t * flat_2d_array;
real_t * x;
real_t * a;
real_t *b;
real_t *c ;
real_t * d;
real_t *e; 

real_t *aa ; 
real_t *bb;
real_t *cc;
real_t *tt;

int * indx;

int Iterations;
int lEN_1D; 
int lEN_2D; 

} ;


int dummy(real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_2D][LEN_2D], real_t[LEN_2D][LEN_2D], real_t[LEN_2D][LEN_2D], real_t);

void init(int** ip, real_t* s1, real_t* s2);

int initialise_arrays(const char* name);
real_t calc_checksum(const char * name);

#endif
