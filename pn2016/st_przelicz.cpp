#include <cstdio>                               //( 1)
#include "xmmintrin.h"                          //( 2)
using namespace std;                            //( 3)
double przelicz(double, double);                //( 4)
int przelicz(int, int);                         //( 5)
double przelicz(const double*, const double*);  //( 6)
float* przelicz(float*, float*);                //( 7)
                                                //( 8)
int main(){                                     //( 9)
 double x=4.0, y=3.0;                           //(10)
 int a=24, b=15;                                //(11)
 printf("%lf\n",przelicz(x, y));                //(12)
 printf("%d\n",przelicz(a, b));               //(13)
 printf("%lf\n",przelicz(&x, &y));              //(14)
 printf("test %lf %lf\n", x, y);
 printf("%lf\n",przelicz(&x, &y));              //(15)
  printf("test %lf %lf\n", x, y);
 float w[4]={1.0, 6.0, 4.0, 8.0};               //(16)
 float z[4]={5.0, 3.0, 2.0, 1.0};               //(17)
 float *v=przelicz(w,z);                        //(18)
 printf("[%f %f %f %f]\n",v[0],v[1],v[2],v[3]); //(19)
 delete[] v;                                    //(20)
 return 0;                                      //(21)
}                                               //(22)
                                                //(23)
float* przelicz(float * x, float * y){          //(24)
	float * w = new float[4];                   //(25)
	__m128 a = _mm_loadu_ps(x);                 //(26)
	__m128 b = _mm_loadu_ps(y);                 //(27)
	__m128 c = _mm_div_ps(a, b);                //(28)
	_mm_storeu_ps(w, c);                        //(29)
	return w;                                   //(30)
}                                               //(31)