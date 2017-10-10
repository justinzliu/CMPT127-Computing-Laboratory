int InRectangle( float pt[2], float rect[4] ) {
   float xmin;
   float xmax;
   float ymin;
   float ymax;
   if (rect[0] > rect[2]) {
      xmax = rect[0];
      xmin = rect[2];
   }
   else if (rect[2] > rect[0]) {
      xmax = rect[2];
      xmin = rect[0];
   }
   else if (rect[0] == rect[2]) {
      xmax = rect[0];
      xmin = rect[0];
   }
   if (rect[1] > rect[3]) {
      ymax = rect[1];
      ymin = rect[3];
   }
   else if (rect[3] > rect[1]) {
      ymax = rect[3];
      ymin = rect[1];
   }
   else if (rect[3] == rect[1]) {
      ymax = rect[1];
      ymin = rect[1];
   }
   if (pt[0] > xmax || pt[0] < xmin) {
      return 0;
   }
   else if (pt[1] > ymax || pt[1] < ymin) {
      return 0;
   }
   else {
      return 1;
   }
}
