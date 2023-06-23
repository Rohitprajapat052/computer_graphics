#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define Round(val)((int)(val+.5))

int maxx, maxy, miny, minx;

void main() {
   int gd = DETECT, gm;
   void clipping(int xa, int ya, int xb, int y);
   int xa, xb, ya, yb;
   printf("Enter the window coordination");
   scanf("%d%d%d%d", &minx, &maxy, &maxx, &miny);
   printf("Enter the two and points for the line");
   scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

   initgraph(&gd, &gm, "");

   rectangle(minx, miny, maxx, maxy);
   line(xa, ya, xb, yb);
   getch();
   closegraph();
}

void clipping(int xa, int ya, int xb, int yb) {

   int Dx = xb - xa, Dy = yb - ya, steps, k;
   int visible1 = 0, visible2 = 0;
   float xin, yin, x = xa, y = ya;

   if (abs(Dx) > abs(Dy))
      steps = abs(Dx);
   else
      steps = abs(Dy);

   xin = Dx / (float) steps;
   yin = Dy / (float) steps;
   putpixel(Round(x), Round(y), 2);

   for (k = 0; k < steps; k++) {
      x += xin;

      y += yin;

      if ((y > miny && y < maxx)) {
         visible1 = 1;
         putpixel(Round(x), Round(y), 2);
      } else
         visible2 = 1;
   }

   if (visible1 == 0)
      outtextxy(20, 200, "complextely visible");

   if (visible1 == 1 && visible2 == 1)
      outtextxy(20, 20, "partialy visible");

   if (visible1 == 1 && visible2 == 0)
      outtextxy(20, 20, "completly visible");
}