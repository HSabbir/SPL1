#include<iostream>

#include<graphics.h>

using namespace std ;


int  main(){
int gd = DETECT, gm;
    initgraph(&gd,&gm, " ");
int x[3],y[3],px,py,i;
cout<< "Enter four control points of bezier curve: " ;
for(i=0;i<3;i++) cin>>x[i]>>y[i];
double t;
for(t=0.0;t<=1.0;t+=0.001){
px=(1-t)*(1-t)*x[0]+2*t*(1-t)*x[1]+t*t*x[2];
py=(1-t)*(1-t)*y[0]+2*t*(1-t)*y[1]+t*t*y[2];
putpixel(px,py,RED);
delay(2);
line(x[0],y[0],x[2],y[2]);
}
getch();
closegraph();
}

/*
px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
*/
