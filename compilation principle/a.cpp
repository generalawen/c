#include<stdio.h>
int main(){
	double a,b,c,d,e;
	e=1.0;
    d=(-2*e)/3;
    c=-(+3*e);
    b=(c+3*d+2*e)/(2);
    a = -b+c-2*d+e;
	printf("%.2f  %.2f %.2f %.2f %.2f ",a,b,c,d,e);
	return 0;
} 