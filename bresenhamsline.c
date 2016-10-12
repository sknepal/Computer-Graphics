#include <graphics.h>
#include <math.h>

int main(){
int p, x1, y1, x2, y2, delx, dely, i;
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
printf("Enter x1, y1, x2, y2 : ");
scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

putpixel(x1, y1, RED);
delx = fabs(x2-x1);
dely = fabs(y2-y1);
p = 2 * dely - delx;
for (i=0; i<=delx; i++){
   if (p<0){
    x1 = x1 + 1;
    putpixel(x1, y1, RED);
    p = p+ 2 * dely;
}
else{
    x1 = x1 + 1;
    y1 = y1+1;
    putpixel(x1, y1, RED);
    p = p + 2 * dely - 2 * delx;
}
}
    delay(5000);
   closegraph();
   return 0;
}
