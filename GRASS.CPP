#include<graphics.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#define true  1
#define false 0
void rsnake(void)
{int gdriver=DETECT,gmode,errorcode;
 void
 *body,*food,*tail1,*tail2,*tail3,*tail4,*head1,*head2,*head3,*head4;
 int x,y,X[5000],Y[5000],i=3,
 maxx,maxy,speed=100,bo=10,t[10],score=0,hscore=20;
 unsigned int size;
 char a='6',b,scor[4],hs[4];
 int k=2,l,r1,r2,f=0,z=100,first=0,second=1;;
 r1=300;
 r2=350;
 ifstream infile("c:\tc\bin\rattle.txt");
 infile.getline(hs,4);
 infile.close();
 hscore = atoi(hs);
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 maxx = getmaxx();
 maxy = getmaxy();
 y = 160;
 x = 80;
 for(int j=0; j<=3; j++)
 {X[i-j]=x-bo*(j+1);
  Y[i-j]=y;
 }
 setfillstyle(1,2);
 bar(10,10,20,20);
 setcolor(0);
 setlinestyle(0,1,3);
 line(9,9,21,21);
 line(9,21,21,9);
 size=imagesize(10,10,20,20);
 body=malloc(size);
 getimage(10,10,20,20,body);
 cleardevice();
 setcolor(0);
 t[0]=20;t[1]=10;
 t[2]=10;t[3]=10;
 t[4]=20;t[5]=15;
 t[6]=10;t[7]=20;
 t[8]=20;t[9]=21;
 fillpoly(5,t);
 size=imagesize(10,10,20,21);
 tail1= malloc(size);
 getimage(10,10,20,21,tail1);
 cleardevice();
 t[0]=10;t[1]=10;
 t[2]=20;t[3]=10;
 t[4]=10;t[5]=15;
 t[6]=20;t[7]=20;
 t[8]=10;t[9]=21;
 fillpoly(5,t);
   size=imagesize(10,10,20,21);
   tail2 = malloc(size);
   getimage(10,10,20,21,tail2);
   cleardevice();

   //tail3-up
   t[0]=10; t[1]=20;
   t[2]=10; t[3]=10;
   t[4]=15; t[5]=20;
   t[6]=20; t[7]=10;
   t[8]=20; t[9]=21;
   fillpoly(5, t);
   size = imagesize(10,10,20,21);
   tail3 = malloc(size);
   getimage(10,10,20,21,tail3);
   cleardevice();

   //tail4-down
   t[0]=10; t[1]=10;
   t[2]=10; t[3]=21;
   t[4]=15; t[5]=10;
   t[6]=20; t[7]=21;
   t[8]=20; t[9]=10;
   fillpoly(5, t);
   size = imagesize(10,10,20,21);
   tail4 = malloc(size);
   getimage(10,10,20,21,tail4);
   cleardevice();

   //head1-right
   setlinestyle(1,1,1);
   setcolor(2);
   fillellipse(10,10,10,5);
   setcolor(4);
   //eyes
   fillellipse(15,7,1,1);
   fillellipse(15,13,1,1);
   size = imagesize(10,5,20,15);
   head1 = malloc(size);
   getimage(10,5,20,15,head1);

   //head2-left
   //eyes
   fillellipse(5,7,1,1);
   fillellipse(5,13,1,1);
   size = imagesize(0,5,10,15);
   head2 = malloc(size);
   getimage(0,5,10,15,head2);
   cleardevice();

   //head3-up
   //eyes
   setcolor(2);
   fillellipse(12,12,5,10);
   setcolor(4);
   fillellipse(9,6,1,1);
   fillellipse(15,6,1,1);
   size = imagesize(7,2,18,12);
   head3 = malloc(size);
   getimage(7,2,18,12,head3);


   //head4-down
   //eyes
   fillellipse(9,17,1,1);
   fillellipse(15,17,1,1);
   size = imagesize(7,12,18,22);
   head4 = malloc(size);
   getimage(7,12,18,22,head4);
   cleardevice();


   //food
   setcolor(15);
   setfillstyle(1,15);
   fillellipse(10,10,3,5);
   size = imagesize(5,3,15,17);
   food = malloc(size);
   getimage(5,3,15,17,food);
   cleardevice();

    /* repeat until a key is pressed */

   maxx=getmaxx();
   maxy=getmaxy();
   setlinestyle(0,1,3);
   setcolor(9);
   rectangle(0,0,maxx,maxy);
   setlinestyle(0,1,2);
   line(maxx-150,0,maxx-150,maxy);
   setcolor(8);
   setfillstyle(1,8);
   bar(maxx-147,3,maxx-3,63);
   setcolor(12);
   int maze=1;
   if(maze==1)
   {
   setfillstyle(1,6);
   bar(4,4,maxx-154,14);
   bar(4,4,14,maxy-4);
   bar(4,maxy-4,maxx-154,maxy-14);
   bar(maxx-154-10,4,maxx-154,maxy-4);
   }


   settextstyle(0,0,1);
   delay(300);
   outtextxy(maxx-125,30,"RATTLE SNAKE");
   delay(300);
   setcolor(11);
   setlinestyle(0,1,2);
   rectangle(maxx-145,65,maxx-5,205);
   outtextxy(maxx-128,70,"INSTRUCTIONS");
   delay(200);
   setcolor(6);
   outtextxy(maxx-140,90,"Commands     Key");
   delay(300);
   setcolor(8);
   outtextxy(maxx-140,110," Move Up      w");
   delay(50);
   outtextxy(maxx-140,130," Move Down    s");
    delay(50);
   outtextxy(maxx-140,150," Move Right   d");
    delay(50);
   outtextxy(maxx-140,170," Move Left    a");
    delay(50);
   outtextxy(maxx-140,190," Exit         0");
   delay(200);
   setcolor(12);
   setlinestyle(0,1,2);
   rectangle(maxx-145,210,maxx-5,350);
   setcolor(1);
   outtextxy(maxx-130,220,"Player's Name");
   setcolor(15);
   outtextxy(maxx-100,230,"Yellow");
   setcolor(4);
   delay(200);
   itoa(score,scor,10);
   outtextxy(maxx-140,250,"Score");
   outtextxy(maxx-50,250,scor);
   delay(200);
   setcolor(10);
   outtextxy(maxx-140,280,"Level");
   delay(200);
   setcolor(13);
   outtextxy(maxx-140,310,"Maze        1");
   delay(200);
   setcolor(14);
   outtextxy(maxx-140,340,"High Score  ");
   outtextxy(maxx-50,340,hs);

   for(j=0; j<=1000; j++)
   {
	putpixel(random(maxx-150),random(maxy),6);
	delay(1);
   }

   while (a!='0')
   {

       // plot new image
      if(a=='d')
	    putimage(x, y, head1, XOR_PUT);
      if(a=='a')
	    putimage(x, y, head2, XOR_PUT);
      if(a=='w')
	    putimage(x, y, head3, XOR_PUT);
      if(a=='s')
	    putimage(x, y, head4, XOR_PUT);

      for(j=0; j<k; j++)
      {
	   putimage(X[i-j], Y[i-j], body, XOR_PUT);
      }

      if((X[i-j-1]-X[i-j])<0  && (Y[i-j-1]-Y[i-j])==0)
	    putimage(X[i-j], Y[i-j], tail1, XOR_PUT);

      if((X[i-j-1]-X[i-j])>0  && (Y[i-j-1]-Y[i-j])==0)
	    putimage(X[i-j], Y[i-j], tail2, XOR_PUT);

      if((X[i-j-1]-X[i-j])==0  && (Y[i-j-1]-Y[i-j])<0)
	    putimage(X[i-j], Y[i-j], tail3, XOR_PUT);

      if((X[i-j-1]-X[i-j])==0  && (Y[i-j-1]-Y[i-j])>0)
	    putimage(X[i-j], Y[i-j], tail4, XOR_PUT);

      delay(speed);

      if(second==1)
      {
	setcolor(15);
	outtextxy(maxx-140,360,"Press Any Key...");
	getch();
	setcolor(0);
	outtextxy(maxx-140,360,"Press Any Key...");
	a='d';

	second=2;
      }


      if(first==1)
      {
	setcolor(15);
	outtextxy(maxx-140,360,"Congratulations  ");
	sound(100);
	delay(300);
	nosound();
	getch();
	setcolor(0);
	outtextxy(maxx-140,360,"Congratulations  ");
	second++;
	first=2;

      }

	// erase old image
      if(a=='d')
	    putimage(x, y, head1, XOR_PUT);
      if(a=='a')
	    putimage(x, y, head2, XOR_PUT);
      if(a=='w')
	    putimage(x, y, head3, XOR_PUT);
      if(a=='s')
	    putimage(x, y, head4, XOR_PUT);


      for(j=0; j<k; j++)
      {
	   putimage(X[i-j], Y[i-j], body, XOR_PUT);

      }

      if((X[i-j-1]-X[i-j])<0  && (Y[i-j-1]-Y[i-j])==0)
	    putimage(X[i-j], Y[i-j], tail1, XOR_PUT);

      if((X[i-j-1]-X[i-j])>0  && (Y[i-j-1]-Y[i-j])==0)
	    putimage(X[i-j], Y[i-j], tail2, XOR_PUT);

      if((X[i-j-1]-X[i-j])==0  && (Y[i-j-1]-Y[i-j])<0)
	    putimage(X[i-j], Y[i-j], tail3, XOR_PUT);

      if((X[i-j-1]-X[i-j])==0  && (Y[i-j-1]-Y[i-j])>0)
	    putimage(X[i-j], Y[i-j], tail4, XOR_PUT);


      if(f==0)
      {
	putimage(r1,r2,food,XOR_PUT);
	f=1;
      }

      z--;
      if((x>=r1 && y>=r2 && x<=r1+10 && y<=r2+10) || (x<=r1 && y<=r2 &&
x>=r1-10 && y>=r2-10) || z==0)
      {
	if(z!=0)
	{
		sound(800);
		delay(20);
		setcolor(0);
		score += 10;
		outtextxy(maxx-50,250,scor);
		itoa(score,scor,10);
		if(score>hscore)
		{
			strcpy(hs,scor);
			setfillstyle(1,1);
			bar(maxx-140,337,maxx-20,348);
			setcolor(14);
			outtextxy(maxx-50,340,hs);
			outtextxy(maxx-140,340,"High Score  ");
			if(first==0)
			{
			first=1;
			}
		}
		setcolor(4);
		outtextxy(maxx-50,250,scor);
		k++;
	nosound();
	}
	z=100;
	putimage(r1,r2,food,XOR_PUT);
	repr1:
	r1=random(450);
	    if(r1<50)
	       goto repr1;
	repr2:
	r2=random(400);
	    if(r2<50)
		goto repr2;

	f=0;
      }


      i++;
      X[i]=x;
      Y[i]=y;

      b=a;
      if(kbhit())
      {
		rep:
		a=getche();

		if((b=='d' && a=='a') || (b=='a' && a=='d'))
			a=b;

		if((b=='w' && a=='s') || (b=='s' && a=='w'))
			a=b;

		if(a!='d' && a!='a' && a!='w' && a!='0' && a!='s')
			a=b;
      }

 /*     if(x>maxx-170)
	x=0;

      if(y>maxy)
	y=0;*/

      if(a=='w')
	y -= bo;

      if(a=='s')
	y += bo;

      if(a=='a')
	x -= bo;

      if(a=='d')
	x += bo;

      for(j=i+1; j<i-k; j--)
      {
	if((Y[i]>=Y[j] && Y[i]<=Y[j]+10) || (Y[i]<=Y[j] && Y[i]>=X[j]-10))
	{
		if((X[i]>=X[j] && X[i]<=X[j]+10) || (X[i]<=X[j] && X[i]>=X[j]-10))
		{
			a='0';
		}

		 outtextxy(maxx-140,360,"C ");


	}

	if((X[i]>=X[j] && X[i]<=X[j]+10) || (X[i]<=X[j] && X[i]>=X[j]-10))
	{
		if((Y[i]>=Y[j] && Y[i]<=Y[j]+10) || (Y[i]<=Y[j] && Y[i]>=X[j]-10))
		{
			a='0';
		}

			outtextxy(maxx-140,360,"C  ");
	}

       }

/*      for(j=i; j<i-k; j--)
      {
	if((y>=Y[j] && y<=Y[j]+10) || (y<=Y[j] && y>=Y[j]-10))
	{
		if((x>=X[j] && x<=X[j]+10) || (x<=X[j] && x>=X[j]-10))
		{
			a='5';
		}
	}

	if((x>=X[j] && x<=X[j]+10) || (x<=X[j] && x>=X[j]-10))
	{
		if((y>=Y[j] && y<=Y[j]+10) || (y<=Y[j] && y>=Y[j]-10))
		{
			a='5';
		}
	}
	if(j==0)
		break;
      }      */


  /*	if(x<=0)
	x=maxx-170;

	if(y<=0)
	y=maxy;*/

	if(maze==1)
	{
		if(x<=14 || x>=maxx-184 || y<=14 || y>=maxy-14)
		{
		   a='0';
		}
	}

   }

   if(score>hscore)
   {
	ofstream onfile("c:\turboc3\bin\rattle.txt");
	onfile<<scor;
	onfile.close();
   }

   setcolor(15);
   outtextxy(maxx-140,390,"    Gameover");
   sound(100);
   delay(400);
   nosound();
   getch();
   /* clean up */
   free(body);
   closegraph();
   getch();
}
void start()
{int gdriver=DETECT,choice,i,gmode,ch1;
 initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setcolor(14);
 outtextxy(190,180,"VENOM GAME CENTRE");
 outtextxy(170,190,"*------------------*");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(180,220,"a place for unique legends...");
 getch();
}
//for shuffle game
void disp();
void printmenu();void intro();
void levelmenu();void easy();
void initial(int x);
void draw(int x, int y, int i);
void userwin(int no);int check(int key);
int load,i,step,level,num[25],win;
char square[10]={'o','1','2','3','4','5','6','7','8','9'};
int checkwin()
{if(square[1]==square[2]&&square[2]==square[3])
    return 1;
 else if(square[4]==square[5]&&square[5]==square[6])
	 return 1;
 else if(square[7]==square[8]&&square[8]==square[9])
	 return 1;
 else if(square[1]==square[4]&&square[4]==square[7])
	 return 1;
 else if(square[2]==square[5]&&square[5]==square[8])
	 return 1;
 else if(square[3]==square[6]&&square[6]==square[9])
	 return 1;
 else if(square[1]==square[5]&&square[5]==square[9])
	 return 1;
 else if(square[3]==square[5]&&square[5]==square[7])
	 return 1;
 else if(square[1]!='1'&&square[2]!='2'&&square[3]!='3'&&square[4]!='4'&&square[5]!='5'&&square[6]!='6'&&square[7]!='7'&&square[8]!='8'&&square[9]!='9')
	 return 0;
 else
 return -1;
}
void board()
{clrscr();
 cout<<"\n\n\tTic Tac Toe\n\n";
 cout<<"Player 1 (X)  -  Player 2 (O)"<<endl<<endl;
 cout<<endl;
 cout<<"     |     |     "<<endl;
 cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<endl;
 cout<<"_____|_____|_____"<<endl;
 cout<<"     |     |     "<<endl;
 cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<endl;
 cout<<"_____|_____|_____"<<endl;
 cout<<"     |     |     "<<endl;
 cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<endl;
 cout<<"     |     |     "<<endl<<endl;
}
void main(void)
{
 clrscr();
 start();
 clrscr();
 int gdriver=DETECT,choice,i,gmode,ch1;
 char ch,l[100],p[100],ps[100],u[100],password[100];
a:{clrscr();
   initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
   setbkcolor(BLACK);
   cout<<"\n\n\t\t\t\t VENOM GAME CENTRE\n";
   cout<<"\t\t\t\t*------------------*\n";
   cout<<"\n\t\t1.Rattle snake.\n";
   cout<<"\n\t\t2.Tic Tac Toe.\n";
   cout<<"\n\t\t3.Shuffle game.\n";
   cout<<"\n\t\t4.Exit.\n";
   cout<<"\n\t\tEnter you choice: ";
   cin>>ch1;
   switch(ch1)
   {case 1:{clrscr();
	    rsnake();
	    goto a;
	   }
    case 2:{clrscr();
	    int player=1,i,choice;
	    char mark;
	    do
	    {board();
	     player=(player%2)?1:2;
	     cout<<"Player "<<player<<", enter a number:  ";
	     cin>>choice;
	     mark=(player==1)?'X':'O';
	     if(choice==1&&square[1]=='1')
	     square[1]=mark;
	     else if(choice==2&&square[2]=='2')
	     square[2]=mark;
	     else if(choice==3&&square[3]=='3')
	     square[3]=mark;
	     else if(choice==4&&square[4]=='4')
	     square[4]=mark;
	     else if(choice==5&&square[5]=='5')
	     square[5]=mark;
	     else if(choice==6&&square[6]=='6')
	     square[6]=mark;
	     else if(choice==7&&square[7]=='7')
	     square[7]=mark;
	     else if(choice== 8 && square[8] == '8')
	     square[8]=mark;
	     else if(choice==9&&square[9]=='9')
	     square[9]=mark;
	     else
	     {cout<<"Invalid move ";
	      player--;
	      cin.ignore();
	      cin.get();
	     }
	     i=checkwin();
	     player++;
	    }
	    while(i==-1);
	    board();
	    if(i==1)
	    cout<<"==>\aPlayer "<<--player<<" win ";
	    else
	    cout<<"==>\aGame draw";
	    cin.ignore();
	    cin.get();
	    goto a;
	   }
    case 3:{clrscr();
	    int gdriver = DETECT, gmode, errorcode;
	    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	    levelmenu();
	    clrscr();
	    cleardevice();
	    setbkcolor(WHITE);
	    easy();
	    getch();
	    goto a;
	   }
    case 4:{clrscr();
	    initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	    setbkcolor(BLACK);
	    settextstyle(1,0,3);
	    outtextxy(110,200,"Thank you for using our centre!!");
	    outtextxy(410,310,"Done By:-");
	    outtextxy(410,340,"  R.Aravindh.");
	    getch();
	    exit(0);
	   }
   }
   getch();
  }
}
//for  shuffle game
void levelmenu()
{level=0;
 clrscr();
 cleardevice();
 setbkcolor(BLACK);
 settextstyle(1,0,2);
 cout<<"\n\n\t\t\t\tShuffle game\n";
 cout<<"\t\t\t\t*---------------*\n";
 cout<<"\n\t\t1.Start.\n";
 cout<<"\n\t\t2.Rules.\n";
 cout<<"\n\t\tEnter you choice: ";
 cin>>level;
 if(level==2)
 {clrscr();
  setbkcolor(BLACK);
  outtextxy(20,40,"Read the rules :");
  outtextxy(20,80,"1: Arrange the nos in ascending order");
  outtextxy(20,120,"2: Press the no. key to move the nos.");
  outtextxy(20,160,"3: X-Exit");
  delay(3000);
  levelmenu();
 }
}
void printmenu()
{setbkcolor(BLACK);
 int i;
 gotoxy (33,1);
 cout<<"SHUFFLE GAME";
 gotoxy (1,2);
 for(i=0; i<80; i++)
 cout<<"\xcd";
 cout<<"\t\t\t\tX=exit game\n";
 for(i=0; i<80; i++)
 cout<<"\xcd";
 gotoxy (35,23);
 cout<<"Moves = "<<step;
}
void easy()
{int i,x,y,key,valid;
 char press[2];
 if(load==false)
 initial(9);
 else
 load=false;
 do
 {
  start:
  printmenu();
  i=0;
  for(y=8; y<17; y+=4)
  for(x=33; x<44; x+=5)
  {
   draw(x,y,i);
   i++;
  }
  userwin(8);
  if(win==true)
  {cleardevice();
   outtextxy(2,2,"You have won the game");
   delay(2000);
   disp();
   delay(2000);
   win=false;
   return;
  }
  gotoxy (55,17);
  cout<<"Tips:";
  gotoxy (61,18);
  cout<<"Number will move";
  gotoxy (61,19);
  cout<<"when you key in!";
  gotoxy (43,23);fflush(stdin);
  press[0]=toupper(getche());
  if(press[0]=='X')
  {
   disp();
   main();
  }
  key=atoi(press);
  if((valid=check(key))==false)
  goto start;
  step++;
  if(step==50)
  {
   cleardevice();
   outtextxy(20,200,"YOU HAVE SURPASSED MAXIMUM POSSIBLE MOVES");
   delay(1500);
   disp();
   delay(2500);
   main();
  }
  for(i=0; i<9; i++)
  {if(num[i]==key)
   num[i]=0;
   else
   if(num[i]==0)
   num[i]=key;
  }
 }
 while(true);
}
void initial(int x)
{int i,no;
 step=0;
 no=0%x;
 if(no==1)
 no+=5;
 for(i=0; i<x; i++)
 {
  num[i]=no;
  no+=2;
  if(no>=x)
  if(!(no%2))
  no=1;
  else
  no=0;
 }
}
void draw(int x, int y, int i)
{gotoxy (x,y);
 if(level==1)
 {
  printf("%c%c%c",201,205,187);
  gotoxy (x,y+1);
  printf("%c",186);
  if(num[i]==0)
  printf(" ");
  else
  printf("%d", num[i]);
  printf("%c",186);
  gotoxy (x,y+2);
  printf("%c%c%c",200,205,188);
 }
}
void disp()
{cleardevice();
 setbkcolor(BLACK);
 settextstyle(1,0,3);
 outtextxy(90,150,"Thank you for playing this game!!");
 delay(2500);
}
int check(int key)
{
   int i, valid=false;
   if(level==1)
   for(i=0; i<9; i++)
   {
 if(num[i]==key)
      {
      valid=true;
      switch(i)
      {
      case 0: if(num[1]!=0 && num[3]!=0)valid=false;break;
      case 1: if(num[0]!=0 && (num[2]!=0 && num[4]!=0))
       valid=false;break;
      case 2: if(num[1]!=0 && num[5]!=0)valid=false;break;
      case 3: if(num[0]!=0 && (num[4]!=0 && num[6]!=0))
       valid=false;break;
      case 4: if((num[1]!=0 && num[3]!=0) &&
       (num[5]!=0 && num[7]!=0))valid=false;break;
      case 5: if(num[2]!=0 && (num[4]!=0 && num[8]!=0))
       valid=false;break;
      case 6: if(num[3]!=0 && num[7]!=0)valid=false;break;
      case 7: if(num[4]!=0 && (num[6]!=0 && num[8]!=0))
       valid=false;break;
      case 8: if(num[5]!=0 && num[7]!=0)valid=false;break;
      default:valid=false;break;
       }
      }
   }
   return valid;
}
void userwin(int no)
{       int i;
 for(i=0; i<no; i++)
 if(num[i]!=i+1)
 {
 win=false;
 break;
 }

       else
 win=true;
}