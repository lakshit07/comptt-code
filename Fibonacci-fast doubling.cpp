#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
const int MAX=1e5;
int fibo[100001];
int M=(int)1e9+7;
void pre_compute() {
	fibo[0] = 0, fibo[1] = 1;
	for(int i=2; i<=MAX; ++i) {
		fibo[i] = ((long long)fibo[i-1]+fibo[i-2])%M;
	}
}

inline int fib(int &x, int &y, int n) {
	if (n<1e5) {
		x = fibo[n], y = fibo[n+1];
	}
	else {
		int a, b;
		fib(a, b, n >> 1);
		int z = (((long long)b << 1) - a)%M;
		if (z < 0) z += M;
		x =((long long)a*z)%M;
        int t1=((long long)a*a)%M,t2=((long long)b*b)%M;
		y = ((long long)t1+t2)%M;
		if (n & 1) {
			x =((long long)x+y)%M;
			x ^= y ^= x ^= y;
		}
	}
	return x;
}
inline int fibi(int n) {
	int x = 0, y = 1;
	return fib(x, y, n);
}
int main()
{
    pre_compute();
    printf("%d %d\n",fibi(6),fibi(10000000));
    return 0;
}