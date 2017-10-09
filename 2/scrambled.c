int scrambled(unsigned int a[], unsigned int b[], unsigned int len){
   int testsuma = 0;
   int testsumb = 0;
   int testmula = 1;
   int testmulb = 1;
   for (int i=0; i<len; i++){
      if (len == 0){
      i = -2;
      }
      else {
         testsuma += a[i];
         testsumb += b[i];
         testmula = a[i] * testmula;
         testmulb = b[i] * testmulb;
      }
   }
   if (testsuma == testsumb && testmula == testmulb){
      return 1;
   }
   else {
      return 0;
   }
}
