#include <stdio.h>

int main(void)
{
   unsigned long schar=sizeof(char)*8;
   unsigned long suchar=sizeof(unsigned char)*8;
   unsigned long sint=sizeof(int)*8;
   unsigned long suint=sizeof(unsigned int)*8;
   unsigned long slong=sizeof(long)*8;
   unsigned long sulong=sizeof(unsigned long)*8;
   unsigned long sfloat=sizeof(float)*8;
   unsigned long sdouble=sizeof(double)*8;
   unsigned long sldouble=sizeof(long double)*8;
   printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", schar, suchar, sint, suint, slong, sulong, sfloat, sdouble, sldouble);
   return 0;
}
