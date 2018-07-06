//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;

   long total;
 
   x = 40;
   y = 2;
 
   total = add (x, y); 
 
   printf("the sum of %d and %d is %ld\n", x, y, total);
 
   char c = 'a';
   printf("%d\n",sizeof(c));
   char *address;
   address = &c;
   printf("address of char is %p\n",address);
   
   
   
   unsigned long ul       = 0;
   printf("%d\n",sizeof(ul));
   unsigned long *address1;
   address1 = &ul;
   printf("address of unsigned long is %p\n",address1);
   
   unsigned int ui        = 1;
   printf("%d\n",sizeof(ui));
   unsigned int *address2;
   address2 = &ui;
   printf("address of unsigned int is %p\n",address2);
   
   unsigned long long ull = 2;
   printf("%d\n",sizeof(ull));
   unsigned long long *address3;
   address3 = &ull;
   printf("address of unsigned longlong is %p\n",address3);
   
   unsigned short us      = 3;
   printf("%d\n",sizeof(us));
   unsigned short *address4;
   address4 = &us;
   printf("address of unsigned short is %p\n",address4);
 
   printf("\n");
   printf("\n");
   printf("\n");
   
   signed long sl       = 4;
   printf("%d\n",sizeof(sl));
   signed long *address5;
   address5 = &sl;
   printf("address of signed long is %p\n",address5);
   
   signed int si        = 5;
   printf("%d\n",sizeof(si));
   signed int *address6;
   address6 = &si;
   printf("address of signed int is %p\n",address6);
   
   signed long long sll = 6;
   printf("%d\n",sizeof(sll));
   signed long long *address7;
   address7 = &sll;
   printf("address of signed longlong is %p\n",address7);
   
   signed short ss      = 7;
   printf("%d\n",sizeof(ss));
   signed short *address8;
   address8 = &ss;
   printf("address of signed short is %p\n",address8);
   
   printf("\n");
   printf("\n");
   printf("\n");68
 
   long l       = 8;
   printf("%d\n",sizeof(l));
   long *address9;
   address9 = &l;
   printf("address of long is %p\n",address9);

   int i        = 9;
   printf("%d\n",sizeof(i));
   int *address10;
   address10 = &i;
   printf("address of int is %p\n",address10);
   
   long long ll = 10;
   printf("%d\n",sizeof(ll));
   long long *address11;
   address11 = &ll;
   printf("address of long long is %p\n",address11);
   
   short s      = 11;
   printf("%d\n",sizeof(s));
   short *address12;
   address12 = &s;
   printf("address of short is %p\n",address12);
   
   printf("\n");
   printf("\n");
   printf("\n");
 
   float f = 3.1;
   printf("%d\n",sizeof(f));
   float *address13;
   address13 = &f;
   printf("address of float is %p\n",address13);
   
   double d = 3.14;
   printf("%d\n",sizeof(d));
   double *address14;
   address14 = &d;
   printf("address of double is %p\n",address14);
 
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
