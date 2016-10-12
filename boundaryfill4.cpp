#include<stdio.h>
#include<graphics.h>
void boundfill(int xc,int yc,int r,int b)
{
        int cur;
        cur=getpixel(xc,yc);
        if(cur!=b && cur!=r)
        {
        putpixel(xc,yc,r);
        

        boundfill(xc+1,yc,r,b);
        boundfill(xc-1,yc,r,b);
        boundfill(xc,yc+1,r,b);
        boundfill(xc,yc-1,r,b);
         }

}
int main()
{
     int gd=DETECT,gm;
     initgraph(&gd, &gm, NULL);

    rectangle(100,100,300,300);
    boundfill(105,105,4,WHITE);

    getch();
    closegraph();
}