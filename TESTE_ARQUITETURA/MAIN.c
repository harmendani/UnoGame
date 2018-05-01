#include <stdio.h>
#include <stdlib.h>
void main (void)
{
int a;
short int b;
long int c;
unsigned int d;
unsigned short int e;
unsigned long int f;
float g;
double i;
long double j;
unsigned char k;
printf ("Tamanho do a : %d\n", sizeof(a));
printf ("Tamanho do b : %d\n", sizeof(b));
printf ("Tamanho do c : %d\n", sizeof(c));
printf ("Tamanho do d : %d\n", sizeof(d));
printf ("Tamanho do e : %d\n", sizeof(e));
printf ("Tamanho do f : %d\n", sizeof(f));
printf ("Tamanho do g : %d\n", sizeof(g));
printf ("Tamanho do i-  Double - Representação : %g  - Size : %d \n", i, sizeof(i));
printf ("Tamanho do j - Long Double - Representação : %g  - Size : %d \n", j, sizeof(j));
printf ("Tamanho do k : %d\n", sizeof(k));
system("pause");
}
