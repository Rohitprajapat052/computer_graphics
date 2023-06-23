#include<stdio.h> 
#include<math.h> 
#include<conio.h> 
#include<graphics.h> 

void main() {
   int x1, x2, y1, y2;
   int gd = DETECT, gm;
   void linebres(int, int, int, int);
   printf("Enter the two end points:");
   scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
   initgraph(&gd, &gm, "");
   cleardevice();
   linebres(x1, y1, x2, y2);
   getch();
   line(x1, y1, x2, y2);
   getch();
   closegraph();
}

void linebres(int x1, int y1, int x2, int y2) {
   int dx = abs(x1 - x2), dy = abs(y1 - y2);
   int p, x, y, i, xend, yend;
   if (dx != 0) {
      p = 2 * dy - dx;
      if (x1 > x2) {
         x = x2;
         y = y2;
         xend = x1;
      }
      else {
         x = x1;
         y = y1;
         xend = x2;
      }
      putpixel(x, y, 2);
      for (i = x; i < xend; i++) {
         x += 1;
         if (p < 0)
            p += 2 * dy;
         else
            p += 2 * (dy - dx);
      }
      putpixel(x, y, 2);
   }
   else {
      p = 2 * dx - dy;
      if (y1 > y2) {
         x = x2;
         y = y2;
         yend = y2;
      }
      putpixel(x, y, 2);
      for (i = y; i < yend; i++) {
         y += 1;
         if (p < 0)
            p += 2 * dx;
         else {
            x += 1;
            p += 2 * (dx - dy);
         }
         putpixel(x, y, 2);
      }
   }
}