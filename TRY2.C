#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
struct ball
{                      //structure storing dimensions and velocities of ball.
int x,y,nx,ny,vx,vy,r;
}b;

void main()
{
int score=0;
char tempstring[100];
int gd=DETECT,gm,m=200,n=400,ch;
char e;
char f;
initgraph(&gd,&gm,"NULL");

setbkcolor(11);                  //to set background colour.

b.x=100;
b.y=150;
b.vx=1;
b.vy=2;
b.r=10;
setcolor(RED);
settextstyle(0,HORIZ_DIR,6);
outtextxy(140,80,"BLAHBALL!");
settextstyle(0,HORIZ_DIR,1);
setcolor(MAGENTA);
outtextxy(200,140,"PRESS ANY KEY TO CONTINUE....");
e=getch();
cleardevice();

START :                               //label used for goto.
score=0;
setcolor(RED);
settextstyle(0,HORIZ_DIR,6);
outtextxy(140,80,"BLAHBALL!");
setcolor(BLUE);
settextstyle(0,HORIZ_DIR,2);
outtextxy(220,170,"a.PLAY");
outtextxy(220,200,"b.HELP");
outtextxy(220,230,"c.EXIT");

f=getch();

if(f=='a' || f=='A')
{
cleardevice();
while(1)
{
JUMP:                              //label used for goto.

b.nx=b.x+b.vx;                     //changes the position of the ball.
b.ny=b.y+b.vy;

if((b.nx-b.r)<0)
	b.vx=-b.vx;
if((b.ny-b.r)<0)
	b.vy=-b.vy;


b.nx=b.x+b.vx;
b.ny=b.y+b.vy;
	setcolor(2);
	circle(b.x,b.y,b.r);

	setcolor(2);
	setfillstyle(SOLID_FILL,BROWN);
	circle(b.nx,b.ny,b.r);
	floodfill(b.nx,b.ny,2);

delay(3);
cleardevice();

if((b.ny-b.r)<0)             //to make the ball bounce from the side walls.
	b.vy=-b.vy;
else if((b.ny+b.r)>400)
	b.vy=-b.vy;
else if((b.nx-b.r)<0)
	b.vx=-b.vx;
else if((b.nx+b.r)>600)
	b.vx=-b.vx;


b.x=b.nx;
b.y=b.ny;


setcolor(GREEN);
bar(m,n,m+120,n+10);

outtextxy(350,420,"Press Esc once to PAUSE...");
outtextxy(350,440,"and twice to exit....");

if(kbhit())
{
 ch=getch();
	if(ch==77)
	    {
		 m=m+10;
	    }
	if(ch==75)
	    {
		m=m-10;
	    }
	if(ch==27)
	    {
		goto START;
	    }
 delay(10);
 cleardevice();
 }

if((b.ny+b.r)>400)
{

 if((b.nx+b.r)<m || (b.nx-b.r)>(m+120))
  {
  cleardevice();
  setcolor(RED);
 settextstyle(0,HORIZ_DIR,5);
 outtextxy(100,100,"!!GAME OVER!!");
 settextstyle(0,HORIZ_DIR,2);
 setcolor(BLUE);
 sprintf(tempstring,"YOUR SCORE : %d",score);
 outtextxy(190,170,tempstring);
 delay(2500);
cleardevice();
goto START;
 }
 else
 score+=10;
 }}
}
else if(f=='B' || f=='b')

{
char h;
cleardevice();
setcolor(9);
settextstyle(3,0,3);
outtextxy(100,100,"INSTRUCTIONS");
settextstyle(3,0,1);
outtextxy(100,160,"PRESS -> FOR RIGHT MOVE");
outtextxy(100,180,"PRESS <- FOR LEFT MOVE");
outtextxy(100,200,"PRESS ESC ONCE TO PAUSE AND TWICE TO ESCAPE");
outtextxy(100,240,"RETURN TO THE MENU (PRESS r)");
h=getch();
if(h=='r'|| h=='R')
{
cleardevice();
goto START;
}
delay(5000);
}

else if(f=='c' || f=='C')
{
char g;
cleardevice();
outtextxy(50,200,"ARE YOU SURE YOU WANT TO EXIT (YS/N)");
g=getch();
if(ch=='y'|| ch=='Y')
{
exit(0);
}

else
{
cleardevice();
goto START;
}
}

closegraph();
}








