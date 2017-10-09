void reverse(int arr[], unsigned int len){
   int temp;
   int repeats=len/2;
   for (int i=0; i<repeats; i++){
      temp = arr[i];
      arr[i] = arr[len-1-i];
      arr[len-1-i] = temp;
   }
   return;
}

