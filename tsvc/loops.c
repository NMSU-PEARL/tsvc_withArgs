#include "common.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

real_t s000(struct args_t * func_args, struct data_struct *data_args ) //yes
{

//    linear dependence testing
//    no dependence - vectorizable
real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           
   int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__); 
    gettimeofday(&func_args->t1, NULL);
    
    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i  < lEN_1D; i++) {
            a[i] = b[i] + 1;
        }
       dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}


real_t s111(struct args_t * func_args ,struct data_struct *data_args)
{

//    linear dependence testing
//    no dependence - vectorizable
real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 1; i <  lEN_1D; i += 2) {
            //printf("%f %f %d \n", a[i], b[i], i );
            a[i] = a[i - 1] + b[i];
            //printf("%f %f %d \n", a[i], b[i], i );
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}



real_t s114(struct args_t * func_args,struct data_struct *data_args)
{

//    linear dependence testing
//    transpose vectorization
//    Jump in data access - not vectorizable
real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 


   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);


    for (int nl = 0; nl < 200*(Iterations/(lEN_2D)); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < i; j++) {
              
              (*aa)[i][j] = (*aa)[j][i] + (*bb)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }



    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1111(struct args_t * func_args, struct data_struct *data_args)
{

//    no dependence - vectorizable
//    jump in data access

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D/2; i++) {
            a[2*i] = c[i] * b[i] + d[i] * b[i] + c[i] * c[i] + d[i] * b[i] + d[i] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

real_t s112(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    loop reversal

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 3*Iterations; nl++) {
        for (int i = lEN_1D - 2; i >= 0; i--) {
            a[i+1] = a[i] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1112(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    loop reversal

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*3; nl++) {
        for (int i = lEN_1D - 1; i >= 0; i--) {
            a[i] = b[i] + (real_t) 1.;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

real_t s113(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    a(i)=a(1) but no actual dependence cycle

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 1; i < lEN_1D; i++) {
            a[i] = a[0] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1113(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    one iteration dependency on a(lEN_1D/2) but still vectorizable

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = a[lEN_1D/2] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

// %1.1

real_t s115(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    triangular saxpy loop

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 1000*(Iterations/lEN_2D); nl++) {
        for (int j = 0; j < lEN_2D; j++) {
            for (int i = j+1; i < lEN_2D; i++) {
                a[i] -= (*aa)[j][i] * a[j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1115(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    triangular saxpy loop

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                (*aa)[i][j] = (*aa)[i][j]*(*cc)[j][i] + (*bb)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

real_t s116(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_1D - 5; i += 5) {
            a[i] = a[i + 1] * a[i];
            a[i + 1] = a[i + 2] * a[i + 1];
            a[i + 2] = a[i + 3] * a[i + 2];
            a[i + 3] = a[i + 4] * a[i + 3];
            a[i + 4] = a[i + 5] * a[i + 4];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

real_t s118(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    potential dot product recursion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 200*(Iterations/lEN_2D); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 0; j <= i - 1; j++) {
                a[i] += (*bb)[j][i] * a[i-j-1];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.1

real_t s119(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    no dependence - vectorizable

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 200*(Iterations/(lEN_2D)); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 1; j < lEN_2D; j++) {
                (*aa)[i][j] = (*aa)[i-1][j-1] + (*bb)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1119(struct args_t * func_args, struct data_struct *data_args)
{

//    linear dependence testing
//    no dependence - vectorizable

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 200*(Iterations/(lEN_2D)); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                (*aa)[i][j] = (*aa)[i-1][j] + (*bb)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s121(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    loop with possible ambiguity because of scalar store

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    for (int nl = 0; nl < 3*Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            j = i + 1;
            a[i] = a[j] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s122(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    variable lower and upper bound, and stride
//    reverse data access and jump in data access

    struct{int a;int b;} * x = func_args->arg_info;
    int n1 = x->a;
    int n3 = x->b;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j, k;
    for (int nl = 0; nl < Iterations; nl++) {
        j = 1;
        k = 0;
        for (int i = n1-1; i < lEN_1D; i += n3) {
            k += j;
            a[i] += b[lEN_1D - k];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s123(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    induction variable under an if
//    not vectorizable, the condition cannot be speculated

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    for (int nl = 0; nl < Iterations; nl++) {
        j = -1;
        for (int i = 0; i < (lEN_1D/2); i++) {
            j++;
            a[j] = b[i] + d[i] * e[i];
            if (c[i] > (real_t)0.) {
                j++;
                a[j] = c[i] + d[i] * e[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s124(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    induction variable under both sides of if (same value)

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    for (int nl = 0; nl < Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D; i++) {
            if (b[i] > (real_t)0.) {
                j++;
                a[j] = b[i] + d[i] * e[i];
            } else {
                j++;
                a[j] = c[i] + d[i] * e[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2
real_t s125(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    induction variable in two loops; collapsing possible

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k;
    for (int nl = 0; nl < 100*(Iterations/(lEN_2D)); nl++) {
        k = -1;
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                k++;
                flat_2d_array[k] = (*aa)[i][j] + (*bb)[i][j] * (*cc)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2
real_t s126(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    induction variable in two loops; recurrence in inner loop

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k;
    for (int nl = 0; nl < 10*(Iterations/lEN_2D); nl++) {
        k = 1;
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 1; j < lEN_2D; j++) {
                (*bb)[j][i] = (*bb)[j-1][i] + flat_2d_array[k-1] * (*cc)[j][i];
                ++k;
            }
            ++k;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s127(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variable recognition
//    induction variable with multiple increments

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    for (int nl = 0; nl < 2*Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D/2; i++) {
            j++;
            a[j] = b[i] + c[i] * d[i];
            j++;
            a[j] = b[i] + d[i] * e[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.2

real_t s128(struct args_t * func_args, struct data_struct *data_args)
{

//    induction variables
//    coupled induction variables
//    jump in data access

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j, k;
    for (int nl = 0; nl < 2*Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D/2; i++) {
            k = j + 1;
            a[i] = b[k] - d[i];
            j = k + 1;
            b[k] = a[i] + c[k];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.3

real_t s131(struct args_t * func_args, struct data_struct *data_args)
{
//    global data flow analysis
//    forward substitution

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int m  = 1;
    for (int nl = 0; nl < 5*Iterations; nl++) {
        for (int i = 0; i < lEN_1D - 1; i++) {
            a[i] = a[i + m] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.3

real_t s132(struct args_t * func_args, struct data_struct *data_args)
{
//    global data flow analysis
//    loop with multiple dimension ambiguous subscripts

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int m = 0;
    int j = m;
    int k = m+1;
    for (int nl = 0; nl < 400*Iterations; nl++) {
        for (int i= 1; i < lEN_2D; i++) {
            (*aa)[j][i] = (*aa)[k][i-1] + b[i] * c[1];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.4

real_t s141(struct args_t * func_args, struct data_struct *data_args)
{

//    nonlinear dependence testing
//    walk a row in a symmetric packed array
//    element a(i,j) for (int j>i) stored in location j*(j-1)/2+i

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k;
    for (int nl = 0; nl < 200*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            k = (i+1) * ((i+1) - 1) / 2 + (i+1)-1;
            for (int j = i; j < lEN_2D; j++) {
                flat_2d_array[k] += (*bb)[j][i];
                k += j+1;
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.5

void s151s(real_t *a, real_t* b,int lEN_1D,  int m)
{
    for (int i = 0; i < lEN_1D-1; i++) {
        a[i] = a[i + m] + b[i];
    }
}

real_t s151(struct args_t * func_args, struct data_struct *data_args)
{

//    interprocedural data flow analysis
//    passing parameter information into a subroutine

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 5*Iterations; nl++) {
        s151s(a, b,lEN_1D , 1);
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.5

void s152s(real_t *a, real_t *b, real_t *c, int i)
{
    a[i] += b[i] * c[i];
}

real_t s152(struct args_t * func_args, struct data_struct *data_args)
{

//    interprocedural data flow analysis
//    collecting information from a subroutine

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            b[i] = d[i] * e[i];
            s152s(a, b, c, i);
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.6

real_t s161(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    tests for recognition of loop independent dependences
//    between statements in mutually exclusive regions.

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 0; i < lEN_1D-1; ++i) {
            if (b[i] < (real_t)0.) {
                goto L20;
            }
            a[i] = c[i] + d[i] * e[i];
            goto L10;
L20:
            c[i+1] = a[i] + d[i] * d[i];
L10:
            ;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1161(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    tests for recognition of loop independent dependences
//    between statements in mutually exclusive regions.

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; ++i) {
            if (c[i] < (real_t)0.) {
                goto L20;
            }
            a[i] = c[i] + d[i] * e[i];
            goto L10;
L20:
            b[i] = a[i] + d[i] * d[i];
L10:
            ;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.6

//int s162(int k)
real_t s162(struct args_t * func_args, struct data_struct *data_args)
{
//    control flow
//    deriving assertions

    int k = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        if (k > 0) {
            for (int i = 0; i < lEN_1D-1; i++) {
                a[i] = a[i + k] + b[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

//int s171(int inc)
real_t s171(struct args_t * func_args, struct data_struct *data_args)
{

//    symbolics
//    symbolic dependence tests

    int inc = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i * inc] += b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

//int s172( int n1, int n3)
real_t s172(struct args_t * func_args, struct data_struct *data_args)
{
//    symbolics
//    vectorizable if n3 .ne. 0

    struct{int a;int b;} * x = func_args->arg_info;
    int n1 = x->a;
    int n3 = x->b;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = n1-1; i < lEN_1D; i += n3) {
            a[i] += b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

real_t s173(struct args_t * func_args, struct data_struct *data_args)
{
//    symbolics
//    expression in loop bounds and subscripts

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k = lEN_1D/2;
    for (int nl = 0; nl < 10*Iterations; nl++) {
        for (int i = 0; i < lEN_1D/2; i++) {
            a[i+k] = a[i] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

//int s174(int M)
real_t s174(struct args_t * func_args, struct data_struct *data_args)
{

//    symbolics
//    loop with subscript that may seem ambiguous

    int M = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 10*Iterations; nl++) {
        for (int i = 0; i < M; i++) {
            a[i+M] = a[i] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

//int s175(int inc)
real_t s175(struct args_t * func_args, struct data_struct *data_args)
{

//    symbolics
//    symbolic dependence tests

    int inc = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i += inc) {
            a[i] = a[i + inc] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %1.7

real_t s176(struct args_t * func_args, struct data_struct *data_args)
{

//    symbolics
//    convolution

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int m = lEN_1D/2;
    for (int nl = 0; nl < 4*(Iterations/lEN_1D); nl++) {
        for (int j = 0; j < (lEN_1D/2); j++) {
            for (int i = 0; i < m; i++) {
                a[i] += b[i+m-j-1] * c[j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// **********************************************************
// *                                *
// *            VECTORIZATION                *
// *                                *
// **********************************************************

// %2.1

real_t s211(struct args_t * func_args, struct data_struct *data_args)
{

//    statement reordering
//    statement reordering allows vectorization

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 1; i < lEN_1D-1; i++) {
            a[i] = b[i - 1] + c[i] * d[i];
            b[i] = b[i + 1] - e[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.1

real_t s212(struct args_t * func_args, struct data_struct *data_args)
{

//    statement reordering
//    dependency needing temporary

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            a[i] *= c[i];
            b[i] += a[i + 1] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1213(struct args_t * func_args, struct data_struct *data_args)
{

//    statement reordering
//    dependency needing temporary

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 1; i < lEN_1D-1; i++) {
            a[i] = b[i-1]+c[i];
            b[i] = a[i+1]*d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.2

real_t s221(struct args_t * func_args, struct data_struct *data_args)
{

//    loop distribution
//    loop that is partially recursive

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 1; i < lEN_1D; i++) {
            a[i] += c[i] * d[i];
            b[i] = b[i - 1] + a[i] + d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1221(struct args_t * func_args, struct data_struct *data_args)
{

//    run-time symbolic resolution

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 4; i < lEN_1D; i++) {
            b[i] = b[i - 4] + a[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.2

real_t s222(struct args_t * func_args, struct data_struct *data_args)
{

//    loop distribution
//    partial loop vectorizatio recurrence in middle

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 1; i < lEN_1D; i++) {
            a[i] += b[i] * c[i];
            e[i] = e[i - 1] * e[i - 1];
            a[i] -= b[i] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.3

real_t s231(struct args_t * func_args, struct data_struct *data_args)
{
//    loop interchange
//    loop with data dependency

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; ++i) {
            for (int j = 1; j < lEN_2D; j++) {
                (*aa)[j][i] = (*aa)[j - 1][i] + (*bb)[j][i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.3

real_t s232(struct args_t * func_args, struct data_struct *data_args)
{

//    loop interchange
//    interchanging of triangular loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/(lEN_2D)); nl++) {
        for (int j = 1; j < lEN_2D; j++) {
            for (int i = 1; i <= j; i++) {
                (*aa)[j][i] = (*aa)[j][i-1]*(*aa)[j][i-1]+(*bb)[j][i];
            }
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1232(struct args_t * func_args, struct data_struct *data_args)
{

//    loop interchange
//    interchanging of triangular loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int j = 0; j < lEN_2D; j++) {
            for (int i = j; i < lEN_2D; i++) {
                (*aa)[i][j] = (*bb)[i][j] + (*cc)[i][j];
            }
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.3

real_t s233(struct args_t * func_args, struct data_struct *data_args)
{

//    loop interchange
//    interchanging with one of two inner loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 1; j < lEN_2D; j++) {
                (*aa)[j][i] = (*aa)[j-1][i] + (*cc)[j][i];
            }
            for (int j = 1; j < lEN_2D; j++) {
                (*bb)[j][i] = (*bb)[j][i-1] + (*cc)[j][i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s2233(struct args_t * func_args, struct data_struct *data_args)
{

//    loop interchange
//    interchanging with one of two inner loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 1; j < lEN_2D; j++) {
                (*aa)[j][i] = (*aa)[j-1][i] + (*cc)[j][i];
            }
            for (int j = 1; j < lEN_2D; j++) {
                (*bb)[i][j] = (*bb)[i-1][j] + (*cc)[i][j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.3
real_t s235(struct args_t * func_args, struct data_struct *data_args)
{

//    loop interchanging
//    imperfectly nested loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 200*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            a[i] += b[i] * c[i];
            for (int j = 1; j < lEN_2D; j++) {
                (*aa)[j][i] = (*aa)[j-1][i] + (*bb)[j][i] * a[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.4

real_t s241(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting
//    preloading necessary to allow vectorization

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            a[i] = b[i] * c[i  ] * d[i];
            b[i] = a[i] * a[i+1] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.4

//int s242(real_t s1, real_t s2)
real_t s242(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting

    struct{real_t a;real_t b;} * x = func_args->arg_info;
    real_t s1 = x->a;
    real_t s2 = x->b;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/5; nl++) {
        for (int i = 1; i < lEN_1D; ++i) {
            a[i] = a[i - 1] + s1 + s2 + b[i] + c[i] + d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.4

real_t s243(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting
//    false dependence cycle breaking

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            a[i] = b[i] + c[i  ] * d[i];
            b[i] = a[i] + d[i  ] * e[i];
            a[i] = b[i] + a[i+1] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.4

real_t s244(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting
//    false dependence cycle breaking

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; ++i) {
            a[i] = b[i] + c[i] * d[i];
            b[i] = c[i] + b[i];
            a[i+1] = b[i] + a[i+1] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1244(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting
//    cycle with ture and anti dependency

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            a[i] = b[i] + c[i] * c[i] + b[i]*b[i] + c[i];
            d[i] = a[i] + a[i+1];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s2244(struct args_t * func_args, struct data_struct *data_args)
{

//    node splitting
//    cycle with ture and anti dependency

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
            a[i+1] = b[i] + e[i];
            a[i] = b[i] + c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s251(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    scalar expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t s;
    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            s = b[i] + c[i] * d[i];
            a[i] = s * s;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1251(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    scalar expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t s;
    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            s = b[i]+c[i];
            b[i] = a[i]+d[i];
            a[i] = s*e[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s2251(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    scalar expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        real_t s = (real_t)0.0;
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = s*e[i];
            s = b[i]+c[i];
            b[i] = a[i]+d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s3251(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    scalar expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++){
            a[i+1] = b[i]+c[i];
            b[i]   = c[i]*e[i];
            d[i]   = a[i]*e[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s252(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    loop with ambiguous scalar temporary

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t t, s;
    for (int nl = 0; nl < Iterations; nl++) {
        t = (real_t) 0.;
        for (int i = 0; i < lEN_1D; i++) {
            s = b[i] * c[i];
            a[i] = s + t;
            t = s;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s253(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    scalar expansio assigned under if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t s;
    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > b[i]) {
                s = a[i] - b[i] * d[i];
                c[i] += s;
                a[i] = s;
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s254(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    carry around variable

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x;
    for (int nl = 0; nl < 4*Iterations; nl++) {
        x = b[lEN_1D-1];
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = (b[i] + x) * (real_t).5;
            x = b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s255(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    carry around variables, 2 levels

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x, y;
    for (int nl = 0; nl < Iterations; nl++) {
        x = b[lEN_1D-1];
        y = b[lEN_1D-2];
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = (b[i] + x + y) * (real_t).333;
            y = x;
            x = b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s256(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    array expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 10*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 1; j < lEN_2D; j++) {
                a[j] = (real_t)1.0 - a[j - 1];
                (*aa)[j][i] = a[j] + (*bb)[j][i]*d[j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.5

real_t s257(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    array expansion

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 10*(Iterations/lEN_2D); nl++) {
        for (int i = 1; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                a[i] = (*aa)[j][i] - a[i-1];
                (*aa)[j][i] = a[i] + (*bb)[j][i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s258(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    wrap-around scalar under an if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t s;
    for (int nl = 0; nl < Iterations; nl++) {
        s = 0.;
        for (int i = 0; i < lEN_2D; ++i) {
            if (a[i] > 0.) {
                s = d[i] * d[i];
            }
            b[i] = s * c[i] + d[i];
            e[i] = (s + (real_t)1.) * (*aa)[0][i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s261(struct args_t * func_args, struct data_struct *data_args)
{

//    scalar and array expansion
//    wrap-around scalar under an if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t t;
    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 1; i < lEN_1D; ++i) {
            t = a[i] + b[i];
            a[i] = t + c[i-1];
            t = c[i] * d[i];
            c[i] = t;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s271(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    loop with singularity handling

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (b[i] > (real_t)0.) {
                a[i] += b[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

//int s272(real_t t)
real_t s272(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    loop with independent conditional

    int t = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (e[i] >= t) {
                a[i] += c[i] * d[i];
                b[i] += c[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s273(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    simple loop with dependent conditional

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += d[i] * e[i];
            if (a[i] < (real_t)0.)
                b[i] += d[i] * e[i];
            c[i] += a[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s274(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    complex loop with dependent conditional

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = c[i] + e[i] * d[i];
            if (a[i] > (real_t)0.) {
                b[i] = a[i] + b[i];
            } else {
                a[i] = d[i] * e[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s275(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    if around inner loop, interchanging needed

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 10*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            if ((*aa)[0][i] > (real_t)0.) {
                for (int j = 1; j < lEN_2D; j++) {
                    (*aa)[j][i] = (*aa)[j-1][i] + (*bb)[j][i] * (*cc)[j][i];
                }
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s2275(struct args_t * func_args, struct data_struct *data_args)
{

//    loop distribution is needed to be able to interchange

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                (*aa)[j][i] = (*aa)[j][i] + (*bb)[j][i] * (*cc)[j][i];
            }
            a[i] = b[i] + c[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s276(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    if test using loop index

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int mid = (lEN_1D/2);
    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (i+1 < mid) {
                a[i] += b[i] * c[i];
            } else {
                a[i] += b[i] * d[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7
real_t s277(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    test for dependences arising from guard variable computation.

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D-1; i++) {
                if (a[i] >= (real_t)0.) {
                    goto L20;
                }
                if (b[i] >= (real_t)0.) {
                    goto L30;
                }
                a[i] += c[i] * d[i];
L30:
                b[i+1] = c[i] + d[i] * e[i];
L20:
;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s278(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    if/goto to block if-then-else

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > (real_t)0.) {
                goto L20;
            }
            b[i] = -b[i] + d[i] * e[i];
            goto L30;
L20:
            c[i] = -c[i] + d[i] * e[i];
L30:
            a[i] = b[i] + c[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s279(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    vector if/gotos

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > (real_t)0.) {
                goto L20;
            }
            b[i] = -b[i] + d[i] * d[i];
            if (b[i] <= a[i]) {
                goto L30;
            }
            c[i] += d[i] * e[i];
            goto L30;
L20:
            c[i] = -c[i] + e[i] * e[i];
L30:
            a[i] = b[i] + c[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1279(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    vector if/gotos

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] < (real_t)0.) {
                if (b[i] > a[i]) {
                    c[i] += d[i] * e[i];
                }
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

//int s2710( real_t x)
real_t s2710(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    scalar and vector ifs

    int x = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > b[i]) {
                a[i] += b[i] * d[i];
                if (lEN_1D > 10) {
                    c[i] += d[i] * d[i];
                } else {
                    c[i] = d[i] * e[i] + (real_t)1.;
                }
            } else {
                b[i] = a[i] + e[i] * e[i];
                if (x > (real_t)0.) {
                    c[i] = a[i] + d[i] * d[i];
                } else {
                    c[i] += e[i] * e[i];
                }
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s2711(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    semantic if removal

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (b[i] != (real_t)0.0) {
                a[i] += b[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.7

real_t s2712(struct args_t * func_args, struct data_struct *data_args)
{

//    control flow
//    if to elemental min

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > b[i]) {
                a[i] += b[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.8

real_t s281(struct args_t * func_args, struct data_struct *data_args)
{

//    crossing thresholds
//    index set splitting
//    reverse data access

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x;
    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            x = a[lEN_1D-i-1] + b[i] * c[i];
            a[i] = x-(real_t)1.0;
            b[i] = x;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1281(struct args_t * func_args, struct data_struct *data_args)
{

//    crossing thresholds
//    index set splitting
//    reverse data access

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x;
    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            x = b[i]*c[i] + a[i]*d[i] + e[i];
            a[i] = x-(real_t)1.0;
            b[i] = x;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.9

real_t s291(struct args_t * func_args, struct data_struct *data_args)
{

//    loop peeling
//    wrap around variable, 1 level

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int im1;
    for (int nl = 0; nl < 2*Iterations; nl++) {
        im1 = lEN_1D-1;
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = (b[i] + b[im1]) * (real_t).5;
            im1 = i;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.9

real_t s292(struct args_t * func_args, struct data_struct *data_args)
{

//    loop peeling
//    wrap around variable, 2 levels
//    similar to S291

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int im1, im2;
    for (int nl = 0; nl < Iterations; nl++) {
        im1 = lEN_1D-1;
        im2 = lEN_1D-2;
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = (b[i] + b[im1] + b[im2]) * (real_t).333;
            im2 = im1;
            im1 = i;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.9

real_t s293(struct args_t * func_args, struct data_struct *data_args)
{

//    loop peeling
//    a(i)=a(0) with actual dependence cycle, loop is vectorizable

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = a[0];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.10

real_t s2101(struct args_t * func_args, struct data_struct *data_args)
{

//    diagonals
//    main diagonal calculation
//    jump in data access

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 10*Iterations; nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            (*aa)[i][i] += (*bb)[i][i] * (*cc)[i][i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.12

real_t s2102(struct args_t * func_args, struct data_struct *data_args)
{

//    diagonals
//    identity matrix, best results vectorize both inner and outer loops

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/lEN_2D); nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                (*aa)[j][i] = (real_t)0.;
            }
            (*aa)[i][i] = (real_t)1.;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %2.11

real_t s2111(struct args_t * func_args, struct data_struct *data_args)
{

//    wavefronts, it will make jump in data access

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 100*(Iterations/(lEN_2D)); nl++) {
        for (int j = 1; j < lEN_2D; j++) {
            for (int i = 1; i < lEN_2D; i++) {
                (*aa)[j][i] = ((*aa)[j][i-1] + (*aa)[j-1][i])/1.9;
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// **********************************************************
//                                *
//            IDIOM RECOGNITION            *
//                                *
// **********************************************************

// %3.1

real_t s311(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    sum reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < Iterations*10; nl++) {
        sum = (real_t)0.;
        for (int i = 0; i < lEN_1D; i++) {
            sum += a[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t test(real_t* A){
  real_t s = (real_t)0.0;
  for (int i = 0; i < 4; i++)
    s += A[i];
  return s;
}

real_t s31111(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    sum reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < 2000*Iterations; nl++) {
        sum = (real_t)0.;
        sum += test(a);
        sum += test(&a[4]);
        sum += test(&a[8]);
        sum += test(&a[12]);
        sum += test(&a[16]);
        sum += test(&a[20]);
        sum += test(&a[24]);
        sum += test(&a[28]);
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.1

real_t s312(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    product reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t prod;
    for (int nl = 0; nl < 10*Iterations; nl++) {
        prod = (real_t)1.;
        for (int i = 0; i < lEN_1D; i++) {
            prod *= a[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, prod);
    }

    gettimeofday(&func_args->t2, NULL);
    return prod;
}

// %3.1
real_t s313(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    dot product

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t dot;
    for (int nl = 0; nl < Iterations*5; nl++) {
        dot = (real_t)0.;
        for (int i = 0; i < lEN_1D; i++) {
            dot += a[i] * b[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, dot);
    }

    gettimeofday(&func_args->t2, NULL);
    return dot;
}

// %3.1

real_t s314(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    if to max reduction

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x;
    for (int nl = 0; nl < Iterations*5; nl++) {
        x = a[0];
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > x) {
                x = a[i];
            }
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, x);
    }

    gettimeofday(&func_args->t2, NULL);
    return x;
}

// %3.1

real_t s315(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    if to max with index reductio 1 dimension

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int i = 0; i < lEN_1D; i++)
        a[i] = (i * 7) % lEN_1D;

    real_t x, chksum;
    int index;
    for (int nl = 0; nl < Iterations; nl++) {
        x = a[0];
        index = 0;
        for (int i = 0; i < lEN_1D; ++i) {
            if (a[i] > x) {
                x = a[i];
                index = i;
            }
        }
        chksum = x + (real_t) index;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return index + x + 1;
}

// %3.1

real_t s316(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    if to min reduction

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t x;
    for (int nl = 0; nl < Iterations*5; nl++) {
        x = a[0];
        for (int i = 1; i < lEN_1D; ++i) {
            if (a[i] < x) {
                x = a[i];
            }
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, x);
    }

    gettimeofday(&func_args->t2, NULL);
    return x;
}
// %3.1

real_t s317(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    product reductio vectorize with
//    1. scalar expansion of factor, and product reduction
//    2. closed form solution: q = factor**n

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t q;
    for (int nl = 0; nl < 5*Iterations; nl++) {
        q = (real_t)1.;
        for (int i = 0; i < lEN_1D/2; i++) {
            q *= (real_t).99;
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, q);
    }

    gettimeofday(&func_args->t2, NULL);
    return q;
}

// %3.1

//int s318( int inc)
real_t s318(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    isamax, max absolute value, increments not equal to 1

    int inc = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k, index;
    real_t max, chksum;
    for (int nl = 0; nl < Iterations/2; nl++) {
        k = 0;
        index = 0;
        max = ABS(a[0]);
        k += inc;
        for (int i = 1; i < lEN_1D; i++) {
            if (ABS(a[k]) <= max) {
                goto L5;
            }
            index = i;
            max = ABS(a[k]);
L5:
            k += inc;
        }
        chksum = max + (real_t) index;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return max + index + 1;
}

// %3.1

real_t s319(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    coupled reductions

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < 2*Iterations; nl++) {
        sum = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = c[i] + d[i];
            sum += a[i];
            b[i] = c[i] + e[i];
            sum += b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %3.1

real_t s3110(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    if to max with index reductio 2 dimensions
//    similar to S315

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int xindex, yindex;
    real_t max, chksum;
    for (int nl = 0; nl < 100*(Iterations/(lEN_2D)); nl++) {
        max = (*aa)[(0)][0];
        xindex = 0;
        yindex = 0;
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                if ((*aa)[i][j] > max) {
                    max = (*aa)[i][j];
                    xindex = i;
                    yindex = j;
                }
            }
        }
        chksum = max + (real_t) xindex + (real_t) yindex;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return max + xindex+1 + yindex+1;
}

real_t s13110(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    if to max with index reductio 2 dimensions

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int xindex, yindex;
    real_t max, chksum;
    for (int nl = 0; nl < 100*(Iterations/(lEN_2D)); nl++) {
        max = (*aa)[(0)][0];
        xindex = 0;
        yindex = 0;
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                if ((*aa)[i][j] > max) {
                    max = (*aa)[i][j];
                    xindex = i;
                    yindex = j;
                }
            }
        }
        chksum = max + (real_t) xindex + (real_t) yindex;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return max + xindex+1 + yindex+1;
}

// %3.1

real_t s3111(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    conditional sum reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < Iterations/2; nl++) {
        sum = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > (real_t)0.) {
                sum += a[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %3.1

real_t s3112(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    sum reduction saving running sums

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < Iterations; nl++) {
        sum = (real_t)0.0;
        for (int i = 0; i < lEN_1D; i++) {
            sum += a[i];
            b[i] = sum;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %3.1

real_t s3113(struct args_t * func_args, struct data_struct *data_args)
{

//    reductions
//    maximum of absolute value

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t max;
    for (int nl = 0; nl < Iterations*4; nl++) {
        max = ABS(a[0]);
        for (int i = 0; i < lEN_1D; i++) {
            if ((ABS(a[i])) > max) {
                max = ABS(a[i]);
            }
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, max);
    }

    gettimeofday(&func_args->t2, NULL);
    return max;
}

// %3.2

real_t s321(struct args_t * func_args, struct data_struct *data_args)
{

//    recurrences
//    first order linear recurrence

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 1; i < lEN_1D; i++) {
            a[i] += a[i-1] * b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.2

real_t s322(struct args_t * func_args, struct data_struct *data_args)
{

//    recurrences
//    second order linear recurrence

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 2; i < lEN_1D; i++) {
            a[i] = a[i] + a[i - 1] * b[i] + a[i - 2] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.2

real_t s323(struct args_t * func_args, struct data_struct *data_args)
{

//    recurrences
//    coupled recurrence

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 1; i < lEN_1D; i++) {
            a[i] = b[i-1] + c[i] * d[i];
            b[i] = a[i] + c[i] * e[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.3

real_t s331(struct args_t * func_args, struct data_struct *data_args)
{

//    search loops
//    if to last-1

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    real_t chksum;
    for (int nl = 0; nl < Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] < (real_t)0.) {
                j = i;
            }
        }
        chksum = (real_t) j;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return j+1;
}

// %3.3
//int s332( real_t t)
real_t s332(struct args_t * func_args, struct data_struct *data_args)
{

//    search loops
//    first value greater than threshold

    int t = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int index;
    real_t value;
    real_t chksum;
    for (int nl = 0; nl < Iterations; nl++) {
        index = -2;
        value = -1.;
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > t) {
                index = i;
                value = a[i];
                goto L20;
            }
        }
L20:
        chksum = value + (real_t) index;
        dummy(a, b, c, d, e, *aa, *bb, *cc, chksum);
    }

    gettimeofday(&func_args->t2, NULL);
    return value;
}

// %3.4

real_t s341(struct args_t * func_args, struct data_struct *data_args)
{

//    packing
//    pack positive values
//    not vectorizable, value of j in unknown at each iteration

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j;
    for (int nl = 0; nl < Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D; i++) {
            if (b[i] > (real_t)0.) {
                j++;
                a[j] = b[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.4

real_t s342(struct args_t * func_args, struct data_struct *data_args)
{

//    packing
//    unpacking
//    not vectorizable, value of j in unknown at each iteration

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int j = 0;
    for (int nl = 0; nl < Iterations; nl++) {
        j = -1;
        for (int i = 0; i < lEN_1D; i++) {
            if (a[i] > (real_t)0.) {
                j++;
                a[i] = b[j];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.4

real_t s343(struct args_t * func_args, struct data_struct *data_args)
{

//    packing
//    pack 2-d array into one dimension
//    not vectorizable, value of k in unknown at each iteration

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k;
    for (int nl = 0; nl < 10*(Iterations/lEN_2D); nl++) {
        k = -1;
        for (int i = 0; i < lEN_2D; i++) {
            for (int j = 0; j < lEN_2D; j++) {
                if ((*bb)[j][i] > (real_t)0.) {
                    k++;
                    flat_2d_array[k] = (*aa)[j][i];
                }
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.5

real_t s351(struct args_t * func_args, struct data_struct *data_args)
{

//    loop rerolling
//    unrolled saxpy

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t alpha = c[0];
    for (int nl = 0; nl < 8*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i += 5) {
            a[i] += alpha * b[i];
            a[i + 1] += alpha * b[i + 1];
            a[i + 2] += alpha * b[i + 2];
            a[i + 3] += alpha * b[i + 3];
            a[i + 4] += alpha * b[i + 4];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1351(struct args_t * func_args, struct data_struct *data_args)
{

//    induction pointer recognition

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 8*Iterations; nl++) {
        real_t* __restrict__ A = a;
        real_t* __restrict__ B = b;
        real_t* __restrict__ C = c;
        for (int i = 0; i < lEN_1D; i++) {
            *A = *B+*C;
            A++;
            B++;
            C++;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %3.5

real_t s352(struct args_t * func_args, struct data_struct *data_args)
{

//    loop rerolling
//    unrolled dot product

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t dot;
    for (int nl = 0; nl < 8*Iterations; nl++) {
        dot = (real_t)0.;
        for (int i = 0; i < lEN_1D; i += 5) {
            dot = dot + a[i] * b[i] + a[i + 1] * b[i + 1] + a[i + 2]
                * b[i + 2] + a[i + 3] * b[i + 3] + a[i + 4] * b[i + 4];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, dot);
    }

    gettimeofday(&func_args->t2, NULL);
    return dot;
}

// %3.5

//int s353(int* __restrict__ ip)
real_t s353(struct args_t * func_args, struct data_struct *data_args)
{

//    loop rerolling
//    unrolled sparse saxpy
//    gather is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t alpha = c[0];
    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i += 5) {
            a[i] += alpha * b[ip[i]];
            a[i + 1] += alpha * b[ip[i + 1]];
            a[i + 2] += alpha * b[ip[i + 2]];
            a[i + 3] += alpha * b[ip[i + 3]];
            a[i + 4] += alpha * b[ip[i + 4]];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// **********************************************************
//                                *
//             LANGUAGE COMPLETENESS            *
//                                *
// **********************************************************

// %4.1
// %4.2

real_t s421(struct args_t * func_args, struct data_struct *data_args)
{

//    storage classes and equivalencing
//    equivalence- no overlap

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);
    real_t * xx;
    real_t * yy;
    xx = flat_2d_array;

    for (int nl = 0; nl < 4*Iterations; nl++) {
        yy = xx;
        for (int i = 0; i < lEN_1D - 1; i++) {
            xx[i] = yy[i+1] + a[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

real_t s1421(struct args_t * func_args, struct data_struct *data_args)
{

//    storage classes and equivalencing
//    equivalence- no overlap

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);
real_t * xx; real_t *yy;
    xx = &b[lEN_1D/2];

    for (int nl = 0; nl < 8*Iterations; nl++) {
        for (int i = 0; i < lEN_1D/2; i++) {
            b[i] = xx[i] + a[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.2

real_t s422(struct args_t * func_args, struct data_struct *data_args)
{

//    storage classes and equivalencing
//    common and equivalence statement
//    anti-dependence, threshold of 4

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);
real_t * xx; real_t *yy;
    xx = flat_2d_array + 4;

    for (int nl = 0; nl < 8*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            xx[i] = flat_2d_array[i + 8] + a[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.2

real_t s423(struct args_t * func_args, struct data_struct *data_args)
{

//    storage classes and equivalencing
//    common and equivalenced variables - with anti-dependence

    // do this again here
    int vl = 64;
    real_t * xx;  real_t * yy;
    

real_t * flat_2d_array=data_args->flat_2d_array;
xx = flat_2d_array + vl;

real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D - 1; i++) {
            flat_2d_array[i+1] = xx[i] + a[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.2

real_t s424(struct args_t * func_args, struct data_struct *data_args)
{

//    storage classes and equivalencing
//    common and equivalenced variables - overlap
//    vectorizeable in strips of 64 or less

    // do this again here
    int vl = 63;
    real_t * xx; real_t *yy;
    

real_t * flat_2d_array=data_args->flat_2d_array;
xx = flat_2d_array + vl;

real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D - 1; i++) {
            xx[i+1] = flat_2d_array[i] + a[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, 1.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.3

real_t s431(struct args_t * func_args, struct data_struct *data_args)
{

//    parameters
//    parameter statement

    int k1=1;
    int k2=2;
    int k=2*k1-k2;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = a[i+k] + b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.4

real_t s441(struct args_t * func_args, struct data_struct *data_args)
{

//    non-logical if's
//    arithmetic if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (d[i] < (real_t)0.) {
                a[i] += b[i] * c[i];
            } else if (d[i] == (real_t)0.) {
                a[i] += b[i] * b[i];
            } else {
                a[i] += c[i] * c[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.4

real_t s442(struct args_t * func_args, struct data_struct *data_args)
{

//    non-logical if's
//    computed goto

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            switch (indx[i]) {
                case 1:  goto L15;
                case 2:  goto L20;
                case 3:  goto L30;
                case 4:  goto L40;
            }
L15:
            a[i] += b[i] * b[i];
            goto L50;
L20:
            a[i] += c[i] * c[i];
            goto L50;
L30:
            a[i] += d[i] * d[i];
            goto L50;
L40:
            a[i] += e[i] * e[i];
L50:
            ;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.4

real_t s443(struct args_t * func_args, struct data_struct *data_args)
{

//    non-logical if's
//    arithmetic if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (d[i] <= (real_t)0.) {
                goto L20;
            } else {
                goto L30;
            }
L20:
            a[i] += b[i] * c[i];
            goto L50;
L30:
            a[i] += b[i] * b[i];
L50:
            ;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.5

real_t s451(struct args_t * func_args, struct data_struct *data_args)
{

//    intrinsic functions
//    intrinsics

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/5; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = sinf(b[i]) + cosf(c[i]);
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.5

real_t s452(struct args_t * func_args, struct data_struct *data_args)
{

//    intrinsic functions
//    seq function

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = b[i] + c[i] * (real_t) (i+1);
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.5

real_t s453(struct args_t * func_args, struct data_struct *data_args)
{

//    induction varibale recognition

    real_t s;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*2; nl++) {
        s = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            s += (real_t)2.;
            a[i] = s * b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.7

int s471s(void)
{
// --  dummy subroutine call made in s471
    return 0;
}

real_t s471(struct args_t * func_args, struct data_struct *data_args){

//    call statements
int lEN_1D= data_args->lEN_1D;
    int m = lEN_1D;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations/2; nl++) {
        for (int i = 0; i < m; i++) {
            x[i] = b[i] + d[i] * d[i];
            s471s();
            b[i] = c[i] + d[i] * e[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.8

real_t s481(struct args_t * func_args, struct data_struct *data_args)
{

//    non-local goto's
//    stop statement

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (d[i] < (real_t)0.) {
                exit (0);
            }
            a[i] += b[i] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.8

// %4.8
real_t s482(struct args_t * func_args, struct data_struct *data_args)
{

//    non-local goto's
//    other loop exit with code before exit

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[i] * c[i];
            if (c[i] > b[i]) break;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.9

//int s491(int* __restrict__ ip)
real_t s491(struct args_t * func_args, struct data_struct *data_args)
{

//    vector semantics
//    indirect addressing on lhs, store in sequence
//    scatter is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[ip[i]] = b[i] + c[i] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.11

//int s4112(int* __restrict__ ip, real_t s)
real_t s4112(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    sparse saxpy
//    gather is required

    struct{int * __restrict__ a;real_t b;} * x = func_args->arg_info;
    int * __restrict__ ip = x->a;
    real_t s = x->b;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[ip[i]] * s;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.11

//int s4113(int* __restrict__ ip)
real_t s4113(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    indirect addressing on rhs and lhs
//    gather and scatter is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[ip[i]] = b[ip[i]] + c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.11

//int s4114(int* ip, int n1)
real_t s4114(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    mix indirect addressing with variable lower and upper bounds
//    gather is required

    struct{int * __restrict__ a;int b;} * x = func_args->arg_info;
    int * __restrict__ ip = x->a;
    int n1 = x->b;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    int k;
    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = n1-1; i < lEN_1D; i++) {
            k = ip[i];
            a[i] = b[i] + c[lEN_1D-k+1-2] * d[i];
            k += 5;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.11

//int s4115(int* __restrict__ ip)
real_t s4115(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    sparse dot product
//    gather is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < Iterations; nl++) {
        sum = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            sum += a[i] * b[ip[i]];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %4.11

//int s4116(int* __restrict__ ip, int j, int inc)
real_t s4116(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    more complicated sparse sdot
//    gather is required

    struct{int * __restrict__ a;int b;int c;} * x = func_args->arg_info;
    int * __restrict__ ip = x->a;
    int j = x->b;
    int inc = x->c;

real_t * flat_2d_array=data_args->flat_2d_array;
//real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    int off;
    for (int nl = 0; nl < 100*Iterations; nl++) {
        sum = 0.;
        for (int i = 0; i < lEN_2D-1; i++) {
            off = inc + i;
            sum += a[off] * (*aa)[j-1][ip[i]];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %4.11

real_t s4117(struct args_t * func_args, struct data_struct *data_args)
{

//    indirect addressing
//    seq function

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = b[i] + c[i/2] * d[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %4.12

real_t f(real_t a, real_t b){
    return a*b;
}

real_t s4121(struct args_t * func_args, struct data_struct *data_args)
{

//    statement functions
//    elementwise multiplication

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += f(b[i],c[i]);
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t va(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector assignment

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

//int vag( int* __restrict__ ip)
real_t vag(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector assignment, gather
//    gather is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = b[ip[i]];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

//int vas( int* __restrict__ ip)
real_t vas(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector assignment, scatter
//    scatter is required

    int * __restrict__ ip = func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 2*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[ip[i]] = b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vif(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector if

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            if (b[i] > (real_t)0.) {
                a[i] = b[i];
            }
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vpv(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector plus vector

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vtv(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector times vector

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] *= b[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vpvtv(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector plus vector times vector

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[i] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

//real_t vpvts( real_t s)
real_t vpvts(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector plus vector times scalar

    real_t s = *(int*)func_args->arg_info;

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[i] * s;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vpvpv(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector plus vector plus vector

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] += b[i] + c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vtvtv(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector times vector times vector

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    for (int nl = 0; nl < 4*Iterations; nl++) {
        for (int i = 0; i < lEN_1D; i++) {
            a[i] = a[i] * b[i] * c[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}

// %5.1

real_t vsumr(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector sum reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t sum;
    for (int nl = 0; nl < Iterations*10; nl++) {
        sum = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            sum += a[i];
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, sum);
    }

    gettimeofday(&func_args->t2, NULL);
    return sum;
}

// %5.1

real_t vdotr(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    vector dot product reduction

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t dot;
    for (int nl = 0; nl < Iterations*10; nl++) {
        dot = 0.;
        for (int i = 0; i < lEN_1D; i++) {
            dot += a[i] * b[i];
        }
        dummy(a, b, c, d, e, *aa, *bb, *cc, dot);
    }

    gettimeofday(&func_args->t2, NULL);
    return dot;
}

// %5.1

real_t vbor(struct args_t * func_args, struct data_struct *data_args)
{

//    control loops
//    basic operations rates, isolate arithmetic from memory traffic
//    all combinations of three, 59 flops for 6 loads and 1 store.

real_t * flat_2d_array=data_args->flat_2d_array;
real_t * x=data_args->x;
           int Iterations=data_args->Iterations;
   int lEN_1D= data_args->lEN_1D;
   int lEN_2D= data_args->lEN_2D;


   real_t * a=data_args->a   ; 
   real_t * b=data_args->b   ;      
   real_t *c= data_args->c  ;
   real_t * d= data_args->d   ;
   real_t *e= data_args->e   ; 

   real_t (*aa)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->aa   ;
   real_t (*bb)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->bb   ;
   real_t (*cc)[lEN_2D][lEN_2D]=(real_t (*)[lEN_2D][lEN_2D]) data_args->cc   ;

    int * indx= data_args->indx;
initialise_arrays(__func__);
    gettimeofday(&func_args->t1, NULL);

    real_t a1, b1, c1, d1, e1, f1;
    for (int nl = 0; nl < Iterations*10; nl++) {
        for (int i = 0; i < lEN_2D; i++) {
            a1 = a[i];
            b1 = b[i];
            c1 = c[i];
            d1 = d[i];
            e1 = e[i];
            f1 = (*aa)[0][i];
            a1 = a1 * b1 * c1 + a1 * b1 * d1 + a1 * b1 * e1 + a1 * b1 * f1 +
                a1 * c1 * d1 + a1 * c1 * e1 + a1 * c1 * f1 + a1 * d1 * e1
                + a1 * d1 * f1 + a1 * e1 * f1;
            b1 = b1 * c1 * d1 + b1 * c1 * e1 + b1 * c1 * f1 + b1 * d1 * e1 +
                b1 * d1 * f1 + b1 * e1 * f1;
            c1 = c1 * d1 * e1 + c1 * d1 * f1 + c1 * e1 * f1;
            d1 = d1 * e1 * f1;
            x[i] = a1 * b1 * c1 * d1;
        }
        dummy(a, b, c, d, e,*aa, *bb, *cc, 0.);
    }

    gettimeofday(&func_args->t2, NULL);
    return calc_checksum(__func__);
}
