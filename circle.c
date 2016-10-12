
#include <graphics.h>
#include <math.h>

int main(){
int x,y,r,p,xc,yc;
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
printf("Enter the center of the circle (xc and yc): ");
scanf("%d %d", &xc, &yc);
printf("Enter the radius of the circle:");
scanf("%d", &r);
x=0;
y = r;
putpixel(xc+r,yc, RED);
putpixel(xc-r,yc, RED);
putpixel(xc,r+yc, RED);
putpixel(xc,yc-r, RED);
p = 1-r;
while (x<=y){
    if (p<0){
        x=x+1;
        p=p+2*x+1;
    }else{
        x=x+1;
        y=y-1;
        p=p+2+(x-y)+1;
    }
putpixel(xc+x, yc+y, RED);
putpixel(xc+y, yc+x, RED);
putpixel(xc-x, yc+y, RED);
putpixel(xc-y, yc+x, RED);
putpixel(xc+x, yc-y, RED);
putpixel(xc+y, yc-x, RED);
putpixel(xc-x, yc-y, RED);
putpixel(xc-y, yc-x, RED);

}


   delay(5000);
   closegraph();
   return 0;
}
