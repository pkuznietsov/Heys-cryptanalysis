#include <iostream>
#include "immintrin.h"


const int n=1024;
float a[n], b[n];
float c=3.0;

long foo(void) {
	bool use_AVX=true;
	if (use_AVX) 
	{ // fancy AVX loop:
		__m256 C=_mm256_broadcast_ss(&c); // splat c across all SIMD lanes
		for (int i=0;i<n;i+=8) {
			// b[i]=a[i]*c;
			__m256 A=_mm256_load_ps(&a[i]);
			__m256 B=_mm256_mul_ps(A,C);
			_mm256_store_ps(&b[i],B);
		}
	}
	else
	{ // simple float loop: 
		for (int i=0;i<n;i++) {
			b[i]=a[i]*c;
		}
	} 
	
	return b[0];
}

int main(){
    foo();
    std::cout<<"hello"<<std::endl;
}