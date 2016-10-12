#include <graphics.h>

int main(){
float x,y, rx, ry, xc, yc, p1, p2;
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
printf("Enter rx, ry, xc, yc : ");
scanf("%f %f %f %f", &rx, &ry, &xc, &yc);
x = 0;
y = ry;
p1 = ry * ry - rx * rx * ry + 1/4 * rx * rx;
while (2 * ry * ry * x <= 2 * rx * rx * y)
{
    if (p1<0){
        x=x+1;
        p1 = p1 + 2 * ry * ry * x + ry * ry;
    }else{
        x = x+1;
        y = y -1;
        p1 = p1 + 2 * ry * ry * x + ry * ry - 2 * rx * rx * y;
    }

    putpixel(xc+x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc-x, yc+y, RED);
}

p2 = ry * ry * (x + 1/2) * (x + 1/2) + rx * rx * (y-1) * (y-1) - rx* rx * ry * ry;
while (y >= 0){
    if (p2>0){
        y = y-1;
        p2 = p2 - 2 * rx * rx * y + rx* rx;
    }else{
        x = x+1;
        y = y-1;
        p2 = p2 + 2 * ry* ry * x - 2 * rx * rx * y + rx * rx;
    }
    putpixel(xc+x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc-x, yc+y, RED);

}
   delay(5000);
   closegraph();
   return 0;
}
