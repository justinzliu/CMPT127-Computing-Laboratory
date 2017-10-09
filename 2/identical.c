int identical (int a[], int b[], unsigned int len){
   int identical;
   for (int i=0; i<len; ++i){
      if (a[i]==b[i]){
         identical+=1;
      }
      else {
         return 0;
      }
   }
   return 1;
}
