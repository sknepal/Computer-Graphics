#include <graphics.h>
#include <stdio.h>
#include <math.h>
void main(){
 float x1,x2,y1,y2,dx,dy, steps, xinc, yinc, i=1;
 int gd=DETECT,gm;
 initgraph(&gd, &gm, NULL);
 printf("Enter the value of x1: ");
 scanf("%f", &x1);
 printf("Enter the value of y1: ");
 scanf("%f", &y1);
 printf("Enter the value of x2: ");
 scanf("%f", &x2);
 printf("Enter the value of y2: ");
 scanf("%f", &y2);

 dx=fabs(x2-x1);
 dy=fabs(y2-y1);
 if (dx>=dy) steps = dx;
 else steps = dy;
 xinc = dx/steps;
 yinc = dx/steps;

 for (i=0;i<=steps;i++){
    putpixel(x1,y1, GREEN);
    x1=x1+xinc;
    y1=y1+yinc;
    delay(100);
 }
 closegraph();
  getch();
}
