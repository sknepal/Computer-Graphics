
#include <graphics.h>
#include <math.h>
#define tx 10
#define ty 20
#define theta (10*3.1416)/180
#define xr 100
#define yr 100
#define sx 2
#define sy 2
void matrixMultiply(float a[][3], float b[][5], float c[][5]);

int main(){
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
float c[3][5] = {};
float v[3][5] = {{100, 200, 200, 100, 100},
             {100, 100, 200, 200, 100},
             {1, 1, 1, 1, 1}};

for (int i=0; i<4; i++)
    line(v[0][i], v[1][i], v[0][i+1], v[1][i+1]);

//translation
float t[3][3]={ {1, 0, tx},
                {0, 1, ty},
                    {0, 0, 1}};
matrixMultiply(t, v, c);
setcolor(GREEN);
for (int i=0; i<4; i++)
    line(c[0][i], c[1][i], c[0][i+1], c[1][i+1]);

//rotation about origin
float r[3][3] = { {cos(theta), -sin(theta), 0}, {sin(theta), cos(theta), 0}, {0, 0, 1}};
setcolor(RED);
matrixMultiply(r, v, c);

for (int i=0; i<4; i++)
    line(c[0][i], c[1][i], c[0][i+1], c[1][i+1]);

//rotation about fixed point
float rf[3][3] = {{cos(theta), -sin(theta), xr*(1-cos(theta))+yr*sin(theta)}, {sin(theta), cos(theta), yr*(1-cos(theta)) - xr * sin(theta)}, {0, 0, 1}};
setcolor(YELLOW);
matrixMultiply(rf, v, c);
for (int i=0; i<4; i++)
    line(c[0][i], c[1][i], c[0][i+1], c[1][i+1]);

// general scaling

float s[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
setcolor(BLUE);
matrixMultiply(s, v, c);
for (int i=0; i<4; i++)
    line(c[0][i], c[1][i], c[0][i+1], c[1][i+1]);

// scaling about fixed point
float sf[3][3] = {{sx, 0, xr*(1-sx)}, {0, sy, yr*(1-sy)}, {0, 0, 1}};
setcolor(BROWN);
matrixMultiply(sf, v, c);
for (int i=0; i<4; i++)
    line(c[0][i], c[1][i], c[0][i+1], c[1][i+1]);

printf("White: Original\nGreen: Translation\nRed: Rotation\nYellow: Rotation about fixed point\nBlue: General Scaling\nBrown: Fixed Scaling");

   delay(5000);
   closegraph();
   return 0;
}

void matrixMultiply(float a[][3], float b[][5], float c[][5]){
    for (int i=0; i<3; i++){
            for (int j=0; j<5; j++){
                c[i][j] = 0;
                    for (int k=0; k<3; k++){
                        c[i][j] = c[i][j] + a[i][k] * b [k][j];
                    }
            }
    }
}
