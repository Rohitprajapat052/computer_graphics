#include<stdio.h> 
#include<conio.h> 
#include<process.h> 
#include<graphics.h> 

void main() {
   int gd = DETECT, gm, ch;
   initgraph(&gd, &gm, " ");
   do {

      clrscr();
      printf("\nmenu\n1.circle\n2.line\n3.rectangle\n4.exit\nEnter your choice: ");
      scanf("%d", &ch);
      cleardevice();
      outtextxy(10, 10, "FUNDAMENTALS");
      switch (ch) {

         case 1:
            circle(200, 200, 80);
            break;
         case 2:
            line(200, 200, 300, 300);
            break;
         case 3:
            rectangle(100, 100, 400, 400);
            break;

      }
      getch();
   } while (ch <= 3);
   getch();
}
 