#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>


struct position
{
  int h,v;
}p[3][3];

void box();
void print();

int i,j,d,sum,choose,score=1000,movement,temp;
int row = 3,col = 3;
char button,ch;
int ara1[3][3];
int ara2[3][3]={{1,2,3},{4,5,6},{7,8,0}};
int ara3[3][3]={{1,2,3},{4,5,6},{7,8,0}};

void load();
void instructions();
void rnd();
int move();
void yes();
void swap(int *a,int *b);
void init2();

int main()
{
   // load();
    instructions();
    int gm=DETECT,gd=DETECT;
    initgraph(&gm,&gd,"c:\\tc\\bgi");

    init2();print();
    outtextxy(50,280,"Press any key to show the random sort ");
    getch();

    cleardevice();
    rnd();init2();print();

    outtextxy(50,280,"Press a,s,d,w keys to solve puzzle  ");

    cleardevice();print();

    move();
    cleardevice();
    printf("Successful....!!!!\n");
    printf("You have used %d moves\n",movement);
    printf("Your score is %d\n",score);
    printf("Press r for reset OR any button for exit  ");
    ch=getch();
    if(ch=='r'){
	yes();

	}

    return 0;
}

//void load(){
//    int r,q;
//    gotoxy(45,14);
//    printf("loading...");
//    gotoxy(36,15);
//    for(r=1;r<=22;r++)
//    {
//        for(q=0;q<=100000000;q++);
//        printf("%c",177);
//    }
//    system("CLS");
//}


void instructions()
{
    printf("INSTRUCTIONS:-\n");
    printf("Click the button a in left movement\n");
    printf("Click the button d in right movement\n");
    printf("Click the button w in upper movement\n");
    printf("Click the button s in lower movement\n");
    printf("Press r for reset\n\n");
    printf("Press p for exit\n\n");
    printf("Press any key to play..");
    getch();
    clrscr();
    printf("Press any key to show the original sort. . .");
    getch();
}

 void box()
  {
      setcolor(2);

     for(int i=0;i<150;i+=50)
    {
      for(int j=0;j<180;j+=60)
      rectangle(j+100,i+100,j+50,i+60);
    }

  }

   void print()
  {
  box();
   for(int x=0;x<3;x++)
   {
     for(int y=0;y<3;y++)
     {
       gotoxy(p[x][y].h,p[x][y].v);
       if(ara1[x][y] == 0)
	 cout << "  ";
       else
	 cout<<ara1[x][y];
     }
   }

  }
   void init2()
  {

    for(int x=0,i=6;x<3;x++,i+=3)
   {
     for(int y=0,j=10;y<3;y++,j+=7)
     {
       p[x][y].h=j;
       p[x][y].v=i;
       ara1[x][y]=ara3[x][y];
     }
   }

  }


void rnd()
{
    int ara[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1},n,flag=0,i,j,k,m;
    srand( time(NULL) );
    for(i=0;i<9;i++)
    {
	level:
	    flag=0;
	    n=rand()%9;
	    if(i!=0)
	    {
		for(j=0;j<9;j++)
		{
		    if(ara[j]==n){
			flag=1;
			break;
		    }
		}
	    }
	ara[i]=n;
	if(flag==1)
	    goto level;
    }
	i=0;
	for(j=0;j<3;j++)
	{
	    for(k=0;k<3;k++)
	    {
		ara3[j][k]=ara[i];
		i++;
		//printf("%d ",ara1[j][k]);
	    }
	    //printf("\n");
	}
}

int  move()
{
    if(ara1[2][2]==0)
    {
	button = getch();
	if(button== 's'){
	    swap(&ara1[2][2],&ara1[1][2]);
	    }
	else if(button=='d'){
	    swap(&ara1[2][2],&ara1[2][1]);
	    }
    }
    else if(ara1[2][1]==0)
    {
	button = getch();
	if(button=='a')
	   {
	    swap(&ara1[2][1],&ara1[2][2]);
	   }
	else if(button=='d'){
	    swap(&ara1[2][1],&ara1[2][0]);
	}
	else if(button=='s'){
	    swap(&ara1[2][1],&ara1[1][1]);
	}
    }
    else if(ara1[2][0]==0)
    {
	button = getch();
	if(button=='s'){
	    swap(&ara1[2][0],&ara1[1][0]);
	    }
	else if(button=='a'){
	    swap(&ara1[2][0],&ara1[2][1]);
	}
    }
    else if(ara1[1][0]==0)
    {
	button = getch();
	if(button=='w'){
	   swap(&ara1[1][0],&ara1[2][0]);
	}
	else if(button=='s')
	{
	    swap(&ara1[1][0],&ara1[0][0]);
	}
	else if(button=='a'){
	    swap(&ara1[1][0],&ara1[1][1]);
	}
    }
    else if(ara1[1][1]==0)
    {
	button = getch();
	if(button=='s'){
	    swap(&ara1[1][1],&ara1[0][1]);
	}
	else if(button=='w'){
	    swap(&ara1[1][1],&ara1[2][1]);
	}
	else if(button=='d'){
	    swap(&ara1[1][1],&ara1[1][0]);
	}
	else if(button=='a')
	{
	    swap(&ara1[1][1],&ara1[1][2]);
	}
    }
    else if(ara1[1][2]==0)
    {
	button = getch();
	if(button=='d'){
	    swap(&ara1[1][2],&ara1[1][1]);
	}
	else if(button=='s'){
	    swap(&ara1[1][2],&ara1[0][2]);
	    }
	else if(button=='w')
	{
	    swap(&ara1[1][2],&ara1[2][2]);
	}
    }
    else if(ara1[0][2]==0)
    {
	button = getch();
	if(button=='w'){
	    swap(&ara1[0][2],&ara1[1][2]);
	}
	else if(button=='d'){
	    swap(&ara1[0][2],&ara1[0][1]);
	    }
    }
    else if(ara1[0][1]==0)
    {
	button = getch();
	if(button=='w'){
	    swap(&ara1[0][1],&ara1[1][1]);
	}
	else if(button=='a'){
	    swap(&ara1[0][1],&ara1[0][2]);
	}
	else if(button=='d')
	{
	    swap(&ara1[0][1],&ara1[0][0]);
	}
    }
    else if(ara1[0][0]==0)
    {
	button = getch();
	if(button=='a'){
	    swap(&ara1[0][0],&ara1[0][1]);
	}
	else if(button=='w'){
	    swap(&ara1[0][0],&ara1[1][0]);
	}
    }
    print();
    movement++;
    score--;
		if(ara1[0][0]+ara1[0][1]+ara1[0][2]==ara2[0][0]+ara1[0][1]+ara2[0][2] &&
		   ara1[1][0]+ara1[1][1]+ara1[1][2]==ara2[1][0]+ara2[1][1]+ara2[1][2] &&
		   ara1[2][0]+ara1[2][1]+ara1[2][2]==ara2[2][0]+ara2[2][1]+ara2[2][2] &&
		   ara1[0][0]+ara1[1][0]+ara1[2][0]==ara2[0][0]+ara2[1][0]+ara2[2][0] &&
		   ara1[0][1]+ara1[1][1]+ara1[2][1]==ara2[0][1]+ara2[1][1]+ara2[2][1] &&
		   ara1[0][2]+ara1[1][2]+ara1[2][2]==ara2[0][2]+ara2[1][2]+ara2[2][2])
		   return 0;
    outtextxy(94,220,"Keep moving...");
    if(button=='r')
	yes();
    else if(button=='p')
	exit(1);

    move();
}

void swap(int *a,int *b)
{
    temp=*a;
      *a=*b;
    *b=temp;
}

void yes()
{
    score=1000;
    movement=0;
    cleardevice();

    rnd();init2();print();


    outtextxy(400,420,"Game started with new puzzle ");
    outtextxy(400,430,"Press any key to continue .. ");
    getch ();

    cleardevice();print();
    move();
    cleardevice();
    printf("Successful....!!!!\n");
    printf("You have used %d moves\n",movement);
    printf("Your score is %d\n",score);
    printf("Press r for reset OR any button for exit  ");
    ch=getch();
    if(ch=='r'){
	yes();

	}

}