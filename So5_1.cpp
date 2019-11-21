#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
using namespace std;  
double *s_ltab;
long ltab_n;
void Sommation(double b) 
{
    double l1b = 1.0 / log(b);
    double s = 1.0;
    for (long k=0; k<ltab_n; ++k)
    {
        s_ltab[k] = log(1.0+s) * l1b;
    // == log_b(1+1/2^k)s *= 0.5;
    }
    }
