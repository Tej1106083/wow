////////Designed and Doveloped By Tejendra Singh & Shubham Singh/////////////
//////////////////////////*/Computer Science & Engg./*///////////////////////
/////////////////////////////////*/NIT Patna/*/////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
void bullet(int);
void keyhit(int);
void target(int);
void blast(int,int);
void won(int);
void loose(int);
void score(int,int,int);
void rect(int);
void pass();
int x,y,l=0,shots=0;

void main()
{
	int ab=DETECT,bc,i=0;
	char ch;
	initgraph(&ab,&bc,"C:\\turboC3\\BGI");      //initiate graphics
	setbkcolor(9);
   settextstyle(4,0,7);
   setcolor(RED);
   outtextxy(90,50,"BATTLE FIELD");


   settextstyle(10,0,4);
   setcolor(YELLOW);
   outtextxy(230,200,"World");
   outtextxy(269,250,"Of");
   outtextxy(245,300,"Wars");

   settextstyle(11,0,4);
   setcolor(BLUE);
   outtextxy(100,450,"Designed & Developed by <<::>> Shubham Singh & Tejendra Singh");
   outtextxy(10,10,"Press Esc to Exit.");
   outtextxy(400,10,"Press any key to Continue.");

   ch=getch();
   if(ch==27){closegraph(); exit(0);}

 //  pass();

   keyhit(i);
}
void keyhit(int i)
{
	int j,k;
	setbkcolor(0);
	target(i);
	char ch;
	for(j=0;j<10000;j++)
	{
		while(!kbhit())
		{target(i);}
		ch=getch();
		if(ch=='q'||ch==27)
		 {
		closegraph();exit(0);}
		while(ch=='a'||ch==75)
		{target(i-=10);k=kbhit();while(k==0){target(i);k=kbhit();}ch=getch();sound(900);delay(2);nosound();}
		while(ch=='d'||ch==77)
		{target(i+=10);k=kbhit();while(k==0){target(i);k=kbhit();}ch=getch();sound(900);delay(2);nosound();}
		while(ch=='w'||ch==72)
		{if(shots<25)
		{bullet(i);
		 k=kbhit();
		 target(i);
		 while(k==0)
		 {target(i);k=kbhit();}shots++;ch=getch();}
		 else
		 score(i,::l,::shots);}
	}
}
void rect(int i)
{
	setbkcolor(0);

       if(300+i<=0)
       keyhit(i+=10);
	else if(350+i>=640)
	keyhit(i-=10);
	else
	{setlinestyle(DASHED_LINE,1,2);
	 rectangle(300+i,429,350+i,436);
	 setlinestyle(SOLID_LINE,1,2);
	 rectangle(310+i,419,340+i,429);
	 rectangle(322+i,409,328+i,419);
	 setcolor(GREEN);
	 line(10,438,630,438);
	 setfillstyle(SOLID_FILL,6);
	 bar(10,440,630,445);floodfill(12,441,6);
	 setcolor(1);
	 settextstyle(11,0,4);
	 outtextxy(80,460,"Designed and Developed by <<::>> Tejendra Singh & Shubham Singh");
	 setcolor(RED);
	 settextstyle(11,0,4);
	 outtextxy(15,20,"Score:");
	 setcolor(WHITE);
	 circle(303+i,432,3);
	 circle(312+i,432,3);
	 circle(324+i,432,3);
	 circle(336+i,432,3);
	 circle(347+i,432,3);
		 setcolor(i+1);
	 outtextxy(10,50,".");  setcolor(i+1);
	 outtextxy(20,100,"."); setcolor(i+2);
	 outtextxy(30,150,"."); setcolor(i+3);
	 outtextxy(50,50,".");  setcolor(i+4);
	 outtextxy(90,200,".");  setcolor(i+5);
	 outtextxy(420,277,"."); setcolor(i+6);
	 outtextxy(150,110,"."); setcolor(i+7);
	 outtextxy(350,300,"."); setcolor(i+8);
	 outtextxy(200,140,"."); setcolor(i+9);
	 outtextxy(550,280,"."); setcolor(i+10);
	 outtextxy(300,250,"."); setcolor(i+11);
	 outtextxy(560,260,"."); setcolor(i+12);
	 outtextxy(400,70,".");  setcolor(i+13);
	 outtextxy(15,239,".");  setcolor(i+14);
	 outtextxy(450,166,"."); setcolor(i+15);
	  outtextxy(300,59,"."); setcolor(i+16);
	 outtextxy(500,80,".");  setcolor(i+17);
	  outtextxy(290,95,"."); setcolor(i+18);
	 outtextxy(530,89,".");  setcolor(i+19);
	   outtextxy(150,305,".");
	 setcolor(RED);
	 }
}
void bullet(int i)
{
	setbkcolor(0);
	int j;
	for(j=425;j>=0;j-=25)
	{circle(325+i,j,3); floodfill(327+i,j+1,RED);
	if((322+i<=::x)&&(328+i>=::x)&&(j==::y))
	  {::l++;if(::l<20){blast(i,j);break;}
	   if(::l==20){getch();delay(1000);blast(i,j);score(i,::l,::shots);}}
	delay(15); sound(600);delay(1);nosound(); target(i);}
}
void blast(int i,int j)
{
	int k;
	for(k=0;k<16;k++)
	{
		setcolor(k);
		circle(325+i,j,k);
		delay(20);

	}
	sound(900);
	delay(200);
	nosound();
	for(k=15;k>=0;k--)
	{
		setcolor(0);
		circle(325+i,j,k);
		delay(20);
	}
}
void pass()
   {
     int i,k,a	;
     char masterlist[2][20]={ "Shubham Singh","Tejendra Singh"};
     char yourname[20];
     char password[20];
     char ch;

     textcolor(RED);
     cleardevice();
     setbkcolor(BLACK);
     settextstyle(11,0,5);
     setcolor(BLUE);
     setlinestyle(SOLID_LINE,1,2);
     rectangle(0,0,639,469);
     setcolor(3);
     rectangle(20,20,619,449);
     setcolor(RED);
     setlinestyle(DASHED_LINE,1,2);
     rectangle(10,10,629,459);
     setcolor(6);
     line(142,230,428,230);
     setcolor(YELLOW);
     rectangle(140,190,430,270);
     setcolor(2);
     line(300,190,300,270);

     setcolor(RED);
     outtextxy(150,205,"Enter the Username:");
     outtextxy(150,245,"Enter the Password:");
     gotoxy(40,14);
     gets(yourname);
     gotoxy(40,16);
     for(i=0;i<20;i++)
     {if((ch=getch())=='\r')
      {password[i]='\0';break;}
      else if(ch=='\b')
      {printf("\b");i--;}
      else
      {password[i]=ch;printf("*");}}


      for(i=0;i<2;i++)
     {
       if((strcmp(&masterlist[i][0],password)==0))
       {
	 cleardevice();
	 settextstyle(5,0,6);
	 setbkcolor(BLUE);
	 setcolor(YELLOW);
	 outtextxy(180,200,".....Welcome.....");
	 gotoxy(40,18);
	 puts(yourname);
	for(i=0;i<30;i++)
	      {
	      setlinestyle(DASHED_LINE,1,8);
	      setcolor(i);
	      rectangle(162,202,542,302);
	      setcolor(i+1);
	      rectangle(160,200,544,304);
	      setcolor(i+2);
	      rectangle(158,198,546,306);
	      setcolor(i+3);
	      rectangle(156,196,548,308);
		  sound(600);
	      delay(50);
	      nosound();
	      delay(50);
	      }
	  cleardevice();
	  setbkcolor(YELLOW);
	  settextstyle(11,0,4);
	  setcolor(BROWN);
	  outtextxy(10,10,"Use (left,right)arrow/(a,d) keys to move the tanker and uparrow/w key to fire Bullets");
	  setcolor(RED);
	  settextstyle(4,0,4);
	  outtextxy(220,200,"Please Wait");
	  outtextxy(250,300,"Loading.....");
	  rectangle(98,438,502,462);
	  setlinestyle(SOLID_FILL,1,2);
	  setcolor(BLUE);

	 for(i=100;i<=500;i+=2)
	   {
	     line(i,440,i,460);
	     delay(20);
	     }
	     setcolor(RED);

	 }
      else if(i==1)
	 {
	    cleardevice();
	    settextstyle(11,0,6);

	    setbkcolor(RED);
	    setcolor(YELLOW);
	    outtextxy(200,250,"...Incorrect UserName/Password...");
	    outtextxy(227,280,"Access Denied");
	    outtextxy(227,290,"Sorry");
	    gotoxy(38,19);
	    puts(yourname);

	    for(i=1;i<4;i++)
	       {
		  sound(600);
		  delay(1000);
		  nosound();
		  delay(200);
	       }
	       exit(0);
	    }
      }
}
 void target(int i)
 {
	cleardevice();
     rect(i);
 {
   setcolor(RED);
   settextstyle(11,0,4);
   outtextxy(15,20,"Score:");
   outtextxy(300,20,"Shotes:");
   gotoxy(47,2);
   printf("%d/25",::shots);
   outtextxy(550,20,"Level:");
   gotoxy(77,2);
   printf("1");
   gotoxy(9,2);
   printf("%d",::l*1000-::shots*150);
   }
   setbkcolor(0);
   randomize();
   x=random(598);
   y=random(150);
   x=x-x%10+32;
   y=y-y%25+75;
   setfillstyle(SOLID_FILL,YELLOW);
      circle(x,y,5);floodfill(x+2,y+1,RED);
      setfillstyle(SOLID_FILL,GREEN);
      rectangle(x-20,y-3,x-5,y+3);floodfill(x-18,y-2,RED);
      line(x-20,y,x-28,y-8);
      line(x-20,y,x-28,y+8);

       rect(i);
		   }

  void won(int i)
  {
    char ch;
    cleardevice();
    setbkcolor(9);
    settextstyle(4,0,7);
    setcolor(BLUE);
    outtextxy(200,150,"You Won");
    settextstyle(11,0,5);
    outtextxy(10,10,"press Esc key to exit");
    outtextxy(200,350,"Do You Want To Play Again (Y/N)");
    while(1)
    {ch=getch();
    if(ch=='y')
    {::l=0;::shots=0;keyhit(i=0);}
    if(ch=='n'||ch==27)
    {closegraph();exit(0);}}
   }
void loose(int i)
  {
    char ch;
    cleardevice();
    settextstyle(4,0,7);
    setbkcolor(BLACK);
    setcolor(RED);
    outtextxy(130,150,"YOU LOSE");
    settextstyle(11,0,5);
    outtextxy(10,10,"press Esc key to exit");
    outtextxy(200,350,"Do You Want To Play Again (Y/N)");
    setcolor(1);
    settextstyle(11,0,4);
    outtextxy(150,460,"Designed & Developed by <<::>> Shubham Singh & Tejendra Singh");
    while(1)
    {ch=getch();
    if(ch=='y')
    {::l=0;::shots=0;keyhit(i=0);}
    if(ch=='n'||ch==27)
    {closegraph();exit(0);}}
   }
   void score(int i,int l,int shots)
   {
	int n;
	for(n=0;n<3;n++)
	{sound(200);
	 cleardevice();
	 delay(250);
	 nosound();
	 settextstyle(4,0,8);
	 setcolor(6);
	 outtextxy(150,150,"Game Over");
	 setcolor(RED);
	 rect(i);
	 delay(350);}
	delay(100);
	getch();
	cleardevice();
	setbkcolor(RED);
	gotoxy(34,16);
	printf("Your Score:: %d",l*1000-::shots*150);
	gotoxy(33,17);
	printf("Highest Score:: 20000");
	delay(2500);
	getch();
	if(shots>=25)loose(i);
	else won(i);
   }


