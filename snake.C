/*    Snake - Game */
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
int x[100],y[100],x2[500],y2[500],row=0,col=0,i=5,j,set=0,dupli,p,bb=5,aaa=1,access=0;
union REGS in,o;
int button,n,m;
struct time t;
int ro,co,xc1=0,yc1=0,bon=0,xc=0,yc=0,v,are,level=1,score=0,zzz=50,ddd=0;
char *buff,*f1,*f2,*st1,name[30]="player";

ra()
{
	setcolor(14);
	settextstyle(0,0,1);
	outtextxy(250,5,"Welcome To SNAKE Game ");
	setfillstyle(1,15);
	bar(32,32,43,43);
	are=imagesize(30,30,45,45);
	f1=malloc(are);
	getimage(30,30,45,45,f1);
	putimage(30,30,f1,XOR_PUT);
	setfillstyle(1,4);
	bar(32,32,43,43);
	are=imagesize(30,30,45,45);
	f2=malloc(are);
	getimage(30,30,45,45,f2);
	putimage(30,30,f2,XOR_PUT);
 return 0;
}
void initmouse();
//void viewport();
void show();
int m2();
void pos();
int menu();
void main()
{
	int sss,q,ll,gd=DETECT,p,gm,area,a=(450-(50*5)),d,cat=77,ch,dh,eh,t1,t2,t12,t22,len,cc,hh;
	char *str,*str1,*tim;
	initgraph(&gd,&gm,"");
	p=1;
	front();
	dr:
	viewport();
	q=menu();
	if(q==3)
	{
	     arun:	hh=help();
		if(hh==1)
		{
			how();
			goto arun;
		}
		if(hh==2)
		{
			select();
			goto arun;
		}
		if(hh==3)
		{
			credit();
			goto arun;
		}
		if(hh==4)
		{
			design();
			goto arun;
		}
		if(hh==5)
			goto dr;
	}
	if(q==2)
	{
	 rr:
		ll=sivakumar();
	       if(ll==1)
	       {
			p=m2();

			goto rr;
	       }
	       if(ll==2)
	       {
			a=speed();
			viewport();
			goto rr;
	       }
	       if(ll==3)
	       {
			topscore();
			goto rr;
		}
	       if(ll==4)
		    goto dr;
	}
	if(q==4)
		exit(0);
      if(q==1)
      {
	names();
	hide();
	viewport();
	x[0]=85;
	x[1]=70;
	x[2]=55;
	x[3]=40;
	y[0]=y[1]=y[2]=y[3]=35;
	setcolor(4);
	rectangle(24,19,626,396);
	ra();
	setcolor(15);
	setfillstyle(1,10);
	bar(32,32,43,43);
	area=imagesize(30,30,45,45);
	buff=malloc(area);
	getimage(30,30,45,45,buff);
	putimage(30,30,buff,XOR_PUT);
	setpos(0,0);
	setfillstyle(1,0);
	bar(100,100,500,350);
	prakash(p);
	level=p;
	putimage(40,35,buff,XOR_PUT);
	putimage(55,35,buff,XOR_PUT);
	putimage(70,35,buff,XOR_PUT);
	putimage(85,35,buff,XOR_PUT);
	textcolor(GREEN+BLINK);
	len=0;
	status("Game Play: Arrow keys       Menu: Esc         Pause (or) Play: Others key");
	while(1)
	{

	sss=getpixel(5,5);
	if(sss!=0);
	{
		setfillstyle(SOLID_FILL,0);
		bar(0,0,15,15);
	}
		if(((i-4)%11==0)&&(bon==0)&&(len!=(i-4)))
		{
			len=(i-4);
			gettime(&t);
			bonous();
				bon=1;
			t1=t.ti_sec;
			cc=10;
		}
		gettime(&t);
		if((t1!=t.ti_sec)&&(bon==1))
		{
			cc--;
			t1=t.ti_sec;
			itoa(cc,tim,10);
			setfillstyle(SOLID_FILL,0);
			bar(470,0,530,18);
			outtextxy(500,0,tim);

		}
		if((cc==0)&&(bon==1))
		{
			putimage(xc1,yc1,f2,XOR_PUT);
			bar(470,0,530,18);
			bon=0;
		}
		gotoxy(68,1);
		setcolor(6);
	       itoa(score,str,10);
	       setfillstyle(1,0);
	       settextstyle(3,0,1);
	       if(strcmp(str,str1)!=0)
	       {    bar(80,400,350,450);
		    outtextxy(100,420,"Score : ");
		    outtextxy(180,420,str);
		    strcpy(str1,str);
	       }
		if(kbhit())
		{
		       //	ch=getch();
			dh=getch();
			cat=dh;
		}
		else
		{
			arrange(x,y,i);
			if(set==0)
				food();
			if(cat!=dupli)
				cat=lock(cat,dupli);
			switch(cat)
			{
				case 72:
					     if(y[1]==20)
						  y[0]=380;
					     else
						  y[0]=y[1]-15;
					     x[0]=x[1];
					     d=getpixel(x[0]+8,y[0]+8);
					     if((d==10)||(d==14))
						doctor();
					     if((d==4)&&(bon==1))
					     {
						i++;
						sound(1000);
						delay(90);
						nosound();
						bon=0;
						score+=(cc*10);
					       putimage(xc1,yc1,f2,XOR_PUT);
					       putimage(x[0],y[0],buff,XOR_PUT);
					       putimage(x[i],y[i],buff,XOR_PUT);
					       setfillstyle(SOLID_FILL,0);
						bar(470,0,530,18);
					     }
					     else if(d==15)
					     {
						i++;
						set=0;
						sound(800);
						delay(40);
						score+=bb;
						nosound();
						putimage(x[0],y[0],buff,XOR_PUT);
					     }
					     else
					     {
						 putimage(x[0],y[0],buff,XOR_PUT);
						 putimage(x[i-1],y[i-1],buff,XOR_PUT);
					     }
						delay(a);
				     break;
				case 80:
				     if(y[1]==380)
					  y[0]=20;
				     else
					  y[0]=y[1]+15;
				     x[0]=x[1];
				      d=getpixel(x[0]+8,y[0]+8);
				      if((d==10)||(d==14))
					doctor();
					     if((d==4)&&(bon==1))
					     {
						i++;
						sound(1000);
						delay(90);
						nosound();
						bon=0;
						score+=(cc*10);
					       putimage(xc1,yc1,f2,XOR_PUT);
					       putimage(x[0],y[0],buff,XOR_PUT);
					       putimage(x[i],y[i],buff,XOR_PUT);
					       setfillstyle(SOLID_FILL,0);
						bar(470,0,530,18);
					     }
				      else if(d==15)
					     {
						i++;
						score+=bb;
						sound(800);
						delay(40);
						set=0;
						nosound();
						putimage(x[0],y[0],buff,XOR_PUT);
					     }
				       else
				      {
					     putimage(x[0],y[0],buff,XOR_PUT);
					     putimage(x[i-1],y[i-1],buff,XOR_PUT);
				      }
				     delay(a);
				     break;
				case 75:
				     if(x[1]==25)
					  x[0]=610;
				     else
					  x[0]=x[1]-15;
				     y[0]=y[1];
				     d=getpixel(x[0]+8,y[0]+8);
					if((d==10)||(d==14))
						doctor();
					     if((d==4)&&(bon==1))
					     {
						i++;
						sound(1000);
						delay(90);
						nosound();
						bon=0;
						score+=(cc*10);
					       putimage(xc1,yc1,f2,XOR_PUT);
					       putimage(x[0],y[0],buff,XOR_PUT);
					       putimage(x[i],y[i],buff,XOR_PUT);
					       setfillstyle(SOLID_FILL,0);
						bar(470,0,530,18);
					     }
					else if(d==15)
					  {
						i++;
						sound(800);
						delay(40);
						set=0;
						nosound();
						score+=bb;
						putimage(x[0],y[0],buff,XOR_PUT);
					  }
					  else
					  {
					     putimage(x[0],y[0],buff,XOR_PUT);
					     putimage(x[i-1],y[i-1],buff,XOR_PUT);
					  }
				      delay(a);
				 break;
				case 77:
				     if(x[1]==610)
					  x[0]=25;
				     else
					  x[0]=x[1]+15;
				     y[0]=y[1];
				     d=getpixel(x[0]+8,y[0]+8);
				      if((d==10)||(d==14))
					doctor();
					    if((d==4)&&(bon==1))
					     {
						i++;
						sound(1000);
						delay(90);
						nosound();
						bon=0;
						score+=(cc*10);
					       putimage(xc1,yc1,f2,XOR_PUT);
					       putimage(x[0],y[0],buff,XOR_PUT);
					       putimage(x[i],y[i],buff,XOR_PUT);
					       setfillstyle(SOLID_FILL,0);
						bar(470,0,530,18);
					     }
					else if(d==15)
					    {
						i++;
						set=0;
						sound(800);
						delay(40);
						score+=bb;
						nosound();
						putimage(x[0],y[0],buff,XOR_PUT);
					     }
					     else
					     {
						     putimage(x[0],y[0],buff,XOR_PUT);
						     putimage(x[i-1],y[i-1],buff,XOR_PUT);
					     }
				       delay(a);
					break;
				case 27:
					goto dx;
				//	break;
			}
			dupli=cat;
		}
    }
     }
     dx:
     call();
}
arrange(int x[],int y[],int i)
{
	int j;
	for(j=i;j>=0;j--)
	{
		x[j]=x[j-1];
		y[j]=y[j-1];
	}
	return 0;
}
int lock(int c,int du)
{
	if((c==80)&&(du==72))
		return 72;
	 if((c==72)&&(du==80))
		return 80;
	 if((c==75)&&(du==77))
		return 77;
	 if((c==77)&&(du==75))
		return 75;
	 if((c!=80)&&(c!=72)&&(c!=75)&&(c!=77)&&(c!=27))
		return dupli;
	 return c;
}
food()
{        row=col=0;
	setfillstyle(1,15);
	if(xc!=0 && yc!=0)
		putimage(xc,yc,f1,XOR_PUT);
     ram: col=random(1001);
	while(col>=40)
	{
		row=row+1;
		col-=40;
	}
	xc=(col*15)+25;
	yc=(row*15)+20;
	for(v=0;v<=i;v++)
	{
		if((x[v]==xc)&&(y[v]==yc))
			goto ram;
	}
	for(v=0;v<=j;v++)
	{
		if((x2[v]==xc)&&(y2[v]==yc))
			goto ram;
	}
	setfillstyle(1,15);
	if((xc<=610)&&(xc>=25)&&(yc<=380)&&(yc>=20))
	{
		putimage(xc,yc,f1,XOR_PUT);
		set=1;
	}
	else
		goto ram;
return 0;
}
doctor()
{       int j,k;
	char dc[]="Game Over !!!!";
	for(k=0;k<2;k++)
	{
	for(j=0;j<i;j++)
		putimage(x[j],y[j],buff,XOR_PUT);
	delay(500);
	for(j=0;j<i;j++)
		putimage(x[j],y[j],buff,XOR_PUT);
	delay(500);
	}
	setcolor(15);
	settextstyle(TRIPLEX_FONT,0,4);
	outtextxy(getmaxx()/2-100,getmaxy()/2,dc);
	sleep(1);
	call();
	viewport();
	exit(0);
	return 0;
}
int menu()
{
	char *menu[]={"New Game","Option","Instruction","Exit"};
	int w=0,k,g=130,h=200;
	setbkcolor(0);
	initmouse();
	show();
	setcolor(8);
	settextstyle(1,0,2);
	for(k=0;k<4;k++)
	{
		outtextxy(g,h,menu[k]);
		h+=textheight(menu[k])+10;
	}
	settextstyle(4,0,5);
	setcolor(14);
	setpos(0,0);
	outtextxy(190,90,"SNAKE GAME");
	status("Select Any one using mouse pointer");
	while(1)
	{
		pos(&button,&n,&m);
		w=opt(n,m);
		settextstyle(1,0,2);
		g=130;
		h=200;
		for(k=0;k<4;k++)
		{
			if(w==k+1)
			{
				setcolor(11);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;

				if(button==1)
					return w;
			}
			else
			{
				setcolor(8);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;
			}
		}
	}
}
void initmouse()
{
	in.x.ax=0;
	int86(0x33,&in,&o);
}
void show()
{
	in.x.ax=1;
	int86(0x33,&in,&o);
}
void pos(int *button,int *x,int *y)
{
	in.x.ax=3;
	int86(0x33,&in,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}
int opt(int m,int n)
{
	if((m>130 && n>202)&&(m<234 && n<221))
	{       status("Start the New game... ");
		return 1;
	}
	else if((m>130 && n>232)&&(m<193 && n<246))
	{       status("To Change Control settings..");
		return 2;
	}
	else if((m>130 && n>259)&&(m<240 && n<275))
	{       status("To view the Instruction ..");
		return 3;
	}
	else if((m>130 && n>286)&&(m<170 && n<302))
	{       status("To exit from the Game ..");
		return 4;
	}
	else
	 {
			status("Select any one using mouse pointer");
			return 0;
	 }
}
/*int siva()
{
	int a;
	while(1)
	{
	if(kbhit())
	{
		a=getch();
		return;
	}
	}
} */
int m2()
{
	int a=6,k,g=150,w=0,h=200;
	char *menu[]={"No Maze","Maze 1","Maze 2","Maze 3","Maze 4"};
	hide();
	viewport();
	status("Please Wait   Loading...");
	setpos(0,0);
	settextstyle(7,0,5);
	setcolor(14);
	outtextxy(250,50,"Mazes");
	setfillstyle(0,0);
	bar(100,100,280,440);
	settextstyle(3,0,3);
	setcolor(8);
	for(k=0;k<5;k++)
	{
		outtextxy(g,h,menu[k]);
		h+=textheight(menu[k])+10;
	}
		pos(&button,&n,&m);
		w=option(n,m);
		settextstyle(0,0,0);
		setcolor(13);
		outtextxy(300,138,"Preview");
		setcolor(4);
		rectangle(300,150,500,350);
		g=150;
		h=200;
	    while(1)
	    {
		g=150;
		h=200;
		pos(&button,&n,&m);
		w=option(n,m);
		for(k=0;k<5;k++)
		{
			settextstyle(3,0,3);
			if(w==k+1)
			{
				setcolor(11);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;
				if(a!=w)
					a=disp(w);
				if(button==1)
					return w;
			}
			else
			{
				setcolor(8);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;
			}
			 if(w>5)
				disp(8);
			 setfillstyle(SOLID_FILL,0);
			    status("Select any One using mouse pointer");
			    show();
		}

	     }
}
int option(int m,int n)
{
	if((m>148 && n>203)&&(m<239 && n<221))
	return 1;
	else if((m>148 && n>235)&&(m<218 && n<252))
	return 2;
	else if((m>148 && n>266)&&(m<226 && n<283))
	return 3;
	else if((m>148 && n>297)&&(m<226 && n<316))
	return 4;
	else if((m>148 && n>327)&&(m<226 && n<347))
	return 5;
	else
	return 8;
}

setpos(int x,int y)
{
	in.x.ax=4;
	in.x.cx=x;
	in.x.cx=y;
	int86(0x33,&in,&o);
	return 0;
}
int disp(int a)
{
	if(a==1)
	{
		setfillstyle(1,0);
		bar(301,151,499,349);
		box();
		aaa=1;
		return 1;
	}
	else if(a==3)
	{
		setfillstyle(1,15);
		bar(301,151,499,349);
		setfillstyle(1,0);
		bar(310,160,490,340);
		box();
		aaa=1;
		return 3;
       }
       else if(a==2)
       {
		setfillstyle(1,0);
		bar(301,151,499,349);
		setfillstyle(1,15);
		bar(390,151,395,349);
		box();
		aaa=1;
		return 2;
       }
       else if(a==5)
       {
		setfillstyle(1,15);
		bar(301,151,499,349);
		setfillstyle(1,0);
		bar(310,160,490,340);
		setfillstyle(1,15);

		bar(390,151,395,349);
		setfillstyle(1,0);
		bar(301,240,315,260);
		bar(490,240,499,260);
		box();
		aaa=1;
		return 5;
       }
       else if(a==4)
       {
		setfillstyle(1,15);
		bar(301,151,499,349);
		setfillstyle(1,0);
		bar(310,160,490,340);
		setfillstyle(1,15);
		bar(440,151,445,250);
		bar(370,251,375,349);
		setfillstyle(1,0);
		bar(301,240,315,260);
		bar(490,240,499,260);
		box();
		aaa=1;
		return 4;
       }
       return 0;
}
box()
{
		setfillstyle(1,2);
		bar(350,200,355,205);
		bar(360,200,365,205);
		bar(370,200,375,205);
		bar(380,200,385,205);
		return 0;
}
prakash(int g)
{
	int k;
	j=0;
       if(g==3)
       {        setfillstyle(1,14);
		for(k=20;k<395;k+=15)
		{
			bar(25,k,40,k+15);
			x2[j]=25;
			y2[j]=k;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,20,k+15,35);
			x2[j]=k;
			y2[j]=20;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,380,k+15,395);
			x2[j]=k;
			y2[j]=380;
			j++;
		}
		for(k=20;k<395;k+=15)
		{
			bar(610,k,625,k+15);
			x2[j]=610;
			y2[j]=k;
			j++;
		}

       }
       else if(g==2)
       {
		for(k=20;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(310,k,325,k+15);
			x2[j]=310;
			y2[j]=k;
			j++;
		}
       }
       else if(g==4)
	{
		for(k=20;k<185;k+=15)
		{
			setfillstyle(1,14);
			bar(25,k,40,k+15);
			x2[j]=25;
			y2[j]=j;
			j++;
		}
		for(k=200;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(25,k,40,k+15);
			x2[j]=25;
			y2[j]=j;
			j++;
		}
		for(k=20;k<185;k+=15)
		{
			setfillstyle(1,14);
			bar(610,k,625,k+15);
			x2[j]=610;
			y2[j]=j;
			j++;
		}
		for(k=200;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(610,k,625,k+15);
			x2[j]=610;
			y2[j]=j;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,20,k+15,35);
			x2[j]=k;
			y2[j]=20;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,380,k+15,395);
			x2[j]=k;
			y2[j]=380;
			j++;
		}
		for(k=20;k<230;k+=15)
		{
			bar(415,k,430,k+15);
			x2[j]=370;
			y2[j]=k;
			j++;
		}
		for(k=155;k<395;k+=15)
		{
			bar(175,k,190,k+15);
			x2[j]=145;
			y2[j]=k;
			j++;
		}
       }
       if(g==5)
       {
		for(k=20;k<185;k+=15)
		{
			setfillstyle(1,14);
			bar(25,k,40,k+15);
			x2[j]=25;
			y2[j]=j;
			j++;
		}
		for(k=200;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(25,k,40,k+15);
			x2[j]=25;
			y2[j]=j;
			j++;
		}
		for(k=20;k<185;k+=15)
		{
			setfillstyle(1,14);
			bar(610,k,625,k+15);
			x2[j]=610;
			y2[j]=j;
			j++;
		}
		for(k=200;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(610,k,625,k+15);
			x2[j]=610;
			y2[j]=j;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,20,k+15,35);
			x2[j]=k;
			y2[j]=20;
			j++;
		}
		for(k=25;k<625;k+=15)
		{
			bar(k,380,k+15,395);
			x2[j]=k;
			y2[j]=380;
			j++;
		}
		for(k=20;k<395;k+=15)
		{
			setfillstyle(1,14);
			bar(310,k,325,k+15);
			x2[j]=310;
			y2[j]=k;
			j++;
		}
       }
       return 0;
}

status(char *st)
{
	if(strcmp(st,st1)!=0)
	{
	setfillstyle(SOLID_FILL,1);
	bar(0,getmaxy()-15,getmaxx(),getmaxy());
	setcolor(14);
	settextstyle(0,0,1);
	outtextxy(20,getmaxy()-12,st);
	strcpy(st1,st);
	}
	return 0;
}
int speed()
{
int a,dd,xxx=99+(50*4),ii,count;
char *stt;
	setpos(0,0);
	viewport();
	count=zzz;
	xxx=99+(count*4);
	settextstyle(3,0,3);
	setcolor(14);
	outtextxy(100,100,"Speed Level");
	status("  Increment : [->]           Decrement : [<-]         Accept : [Enter key]");
	rectangle(99,249,500,276);
	setfillstyle(SOLID_FILL,4);
	bar(100,250,xxx,275);
	goto df;
   cd: while(1)
	{
		if(kbhit())
		{
		      dd=getch();
		      switch(dd)
		      {
			case 77:
				if(count==100)
				     continue;
				count++;
				for(ii=0;ii<=3;ii++)
				{
					setcolor(4);
					xxx++;
					line(xxx,250,xxx,275);
				}
				break;
			case 75:
				if(count==0)
					continue;
					count--;
				for(ii=0;ii<=3;ii++)
				{
					setcolor(0);
					line(xxx,250,xxx,275);
					xxx--;
				}
				break;
			case 13:
				zzz=count;
				bb=(count/10)+1;
				a=450-(count*4);
				return a;
			}
		    df:	settextstyle(3,0,3);
			 itoa(count,stt,10);

			setfillstyle(SOLID_FILL,0);
			bar(200,180,300,240);
			setcolor(2);
			outtextxy(240,200,stt);
			goto cd;
		}

	}
       //	getch();
}
hide()
{
	in.x.ax=2;
	int86(0x33,&in,&o);
	return 0;
}
int sivakumar()
{
	char men[][20]={"Mazes","Speed Level","Top Scorer List","Back"};
	int w=0,k,g=130,h=200;
	setpos(0,0);
	viewport();
	setcolor(8);
	settextstyle(1,0,2);
	for(k=0;k<4;k++)
	{
		outtextxy(g,h,men[k]);
		h+=textheight(men[k])+10;
	}
	settextstyle(7,0,5);
	setcolor(14);
	outtextxy(210,90,"OPTIONS");
	while(1)
	{
		pos(&button,&n,&m);
		w=opt1(n,m);
		settextstyle(1,0,2);
		g=130;
		h=200;
		for(k=0;k<4;k++)
		{
			if(w==k+1)
			{
				setcolor(11);
				outtextxy(g,h,men[k]);
				h+=textheight(men[k])+10;

				if(button==1)
					return w;
			}
			else
			{
				setcolor(8);
				outtextxy(g,h,men[k]);
				h+=textheight(men[k])+10;
			}
		}
	}
     //	getch();
}

int opt1(int m,int n)
{
	if((m>129 && n>200)&&(m<185 && n<220))
	{       status("To change the mazes... ");
		return 1;
	}
	else if((m>129 && n>229)&&(m<242 && n<249))
	{       status("To Change speed settings..");
		return 2;
	}
	else if((m>129 && n>257)&&(m<282 && n<273))
	{       status("To view the Top scorer list ...");
		return 3;
	}
	else if((m>129 && n>286)&&(m<179 && n<302))
	{       status("To return main menu.....");
		return 4;
	}
	else
	 {
			status("Select any one using mouse pointer");
			return 0;
	 }
}

names()
{
char na[30];

	setpos(0,0);
	viewport();
	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(80,200,"Enter UR Name : ");
	gotoxy(40,14);
	gets(na);
	strcpy(name,na);
	return 0;
}
topscore()
{
	int k,sco;
	char nam[20],sc[10];
	FILE *file;
	setpos(0,0);
	viewport();
	file=fopen("snake.dat","r");
	//if(file==-1)
	  //	printf("error");
	k=0;

	status("                         Exit : [Any key]   ");
	settextstyle(3,0,4);
	setcolor(14);
	outtextxy(250,50,"Top Score");
	settextstyle(1,0,1);
	setcolor(2);
	outtextxy(100,200,"NO MAZE");
	outtextxy(100,240,"MAZE  1");
	outtextxy(100,280,"MAZE  2");
	outtextxy(100,320,"MAZE  3");
	outtextxy(100,360,"MAZE  4");
	setcolor(13);
	while(fscanf(file,"%s %d\n",nam,&sco)!=EOF)
	{       itoa(sco,sc,10);
	if(k==0)
	{
	outtextxy(300,200,sc);
	outtextxy(400,200,nam);
	}
	else if(k==1)
	{
	outtextxy(300,240,sc);
	outtextxy(400,240,nam);
	}
	else if(k==2)
	{
	outtextxy(300,280,sc);
	outtextxy(400,280,nam);
	}
	else if(k==3)
	{
	outtextxy(300,320,sc);
	outtextxy(400,320,nam);
	}
	else if(k==4)
	{
	outtextxy(300,360,sc);
	outtextxy(400,360,nam);
	}
	k++;
	}

	fclose(file);
	getch();
	return 0;
}

bonous()
{        ro=co=0;
	setfillstyle(1,4);
     ram1: co=random(1001);
	while(co>=40)
	{
		ro=ro+1;
		co-=40;
	}
	xc1=(co*15)+25;
	yc1=(ro*15)+20;
	for(v=0;v<=i;v++)
	{
		if((x[v]==xc1)&&(y[v]==yc1))
			goto ram1;
	}
	if((xc==xc1)&&(yc==yc1))
		goto ram1;
	for(v=0;v<=j;v++)
	{
		if((x2[v]==xc1)&&(y2[v]==yc1))
			goto ram1;
	}
	setfillstyle(1,4);
	if((xc1<=610)&&(xc1>=25)&&(yc1<=380)&&(yc1>=20))
	{
		putimage(xc1,yc1,f2,XOR_PUT);
		bon=1;
	}
	else
		goto ram1;
	return 0;
}

help()
{
	char *menu[]={"How To Play","Selecting Option","Credits","About Me","Back"};
	int w=0,k,g=130,h=200;
	setbkcolor(0);
	settextstyle(3,0,3);
	setpos(0,0);
	viewport();
	settextstyle(7,0,5);
	setcolor(14);
	outtextxy(245,100,"HELP");
	settextstyle(1,0,2);
	setcolor(8);
	for(k=0;k<5;k++)
	{
		outtextxy(g,h,menu[k]);
		h+=textheight(menu[k])+10;
	}
	setpos(0,0);
	status("Select Any one using mouse pointer");

	while(1)
	{
		pos(&button,&n,&m);
		w=opt2(n,m);
		settextstyle(1,0,2);
		g=130;
		h=200;
		for(k=0;k<5;k++)
		{
			if(w==k+1)
			{
				setcolor(11);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;

				if(button==1)
					return w;
			}
			else
			{
				setcolor(8);
				outtextxy(g,h,menu[k]);
				h+=textheight(menu[k])+10;
			}
		}
		if(kbhit())
			goto pr;
	}
      //	getch();
	pr:
	return 0;
}

int opt2(int m,int n)
{
	if((m>128 && n>202)&&(m<255 && n<222))
	{       status("To Explain the \"How To Play\"... ");
		return 1;
	}
	else if((m>128 && n>230)&&(m<290 && n<248))
	{       status("To Explain the \"Selecting Option\"...");
		return 2;
	}
	else if((m>128 && n>258)&&(m<197 && n<276))
	{       status("To Explain the \"Credits\"...");
		return 3;
	}
	else if((m>128 && n>287)&&(m<220 && n<303))
	{       status("To about the Designer...");
		return 4;
	}
	else if((m>128 && n>313)&&(m<178 && n<331))
	{
		status("To Return the Main menu...");
		return 5;
	}
	else
	 {
			status("Select any one using mouse pointer");
			return 0;
	 }
}
how()
{
setpos(0,0);
viewport();
status("                             Return : [Any Key]");
settextstyle(1,0,3);
setcolor(14);
outtextxy(200,50,"How To Play");
settextstyle(1,0,1);
setcolor(2);
outtextxy(100,150,"Direct the SNAKE towards the prey without colliding with");
outtextxy(60,180," its own body and on any maze.");
outtextxy(60,230,"To move Upwards press [Up arrow] ");
outtextxy(60,270,"To move Down    press [Down arrow] ");
outtextxy(60,310,"To move Left    press [Left arrow] ");
outtextxy(60,350,"To move Right   press [Right arrow] ");
getch();
return 0;
}

select()
{
	setpos(0,0);
	viewport();
	status("                         Return : [Any key]");
	settextstyle(1,0,3);
	setcolor(14);
	outtextxy(180,50,"Selecting Option");
	settextstyle(1,0,2);
	setcolor(4);
	outtextxy(100,100,"SPEED LEVEL:");
	settextstyle(1,0,1);
	setcolor(2);
	outtextxy(130,130,"To Increase the speed press [->] ");
	outtextxy(130,160,"To Decrease the speed press [<-] ");
	settextstyle(1,0,2);
	setcolor(4);
	outtextxy(100,200,"MAZE LEVEL:");
	settextstyle(1,0,1);
	setcolor(2);
	outtextxy(130,240,"To select the difficulty level \( Maze \)");
	outtextxy(130,280," Use Mouse pointer");
	getch();
	return 0;
}
credit()
{
	setpos(0,0);
	viewport();
	status("                        Return : [Any key]");
	settextstyle(1,0,3);
	setcolor(14);
	outtextxy(240,50,"Credits");
	settextstyle(1,0,1);
	setcolor(2);
		outtextxy(100,100,"SPEED LEVEL [ 00 - 09 ] : 1 Point");
		outtextxy(100,125,"SPEED LEVEL [ 10 - 19 ] : 2 Points");
		outtextxy(100,150,"SPEED LEVEL [ 20 - 29 ] : 3 Points");
		outtextxy(100,175,"SPEED LEVEL [ 30 - 39 ] : 4 Points");
		outtextxy(100,200,"SPEED LEVEL [ 40 - 49 ] : 5 Points");
		outtextxy(100,225,"SPEED LEVEL [ 50 - 59 ] : 6 Points");
		outtextxy(100,250,"SPEED LEVEL [ 60 - 69 ] : 7 Points");
		outtextxy(100,275,"SPEED LEVEL [ 70 - 79 ] : 8 Points");
		outtextxy(100,300,"SPEED LEVEL [ 80 - 89 ] : 9 Points");
		outtextxy(100,325,"SPEED LEVEL [ 90 - 99 ] : 10 Points");
		outtextxy(100,350,"SPEED LEVEL [ - 100 - ] : 11 Points");
     setcolor(4);
     rectangle(0,400,getmaxx(),getmaxy()-27);
     setcolor(15);
     outtextxy(200,403,"BONUS POINT [ 100 POINTS ]");
     outtextxy(200,430,"\( Valid for 10 Seconds \)");
     getch();
     return 0;
}
call()
{
	int ttt=0,le=0,scor;
	char name1[20];
	FILE *file1,*file2;
	viewport();
//	crypt();
	file1=fopen("snake.dat","r");
	file2=fopen("snake1.dat","w");
	status("                                   Thank You ");
	while(fscanf(file1,"%s %d\n",name1,&scor)!=EOF)
	{
		le++;
		if(le==level)
		{
			if(scor<=score)
			 {
				 fprintf(file2,"\n%s %d",name,score);
				 ttt=1;
			 }
			 else
				fprintf(file2,"\n%s %d",name1,scor);
		}
		else
			fprintf(file2,"\n%s %d",name1,scor);
	}

	if(ttt==1)
	{
		settextstyle(1,0,1);
		setcolor(15);
		outtextxy(120,175,"Congratz!!   You get High Score for this Level");
	}
	else
	{
		settextstyle(1,0,1);
		setcolor(15);
		outtextxy(120,175,"Sorry !!!   You not get High Score for this Level");
	}
	fclose(file1);
	fclose(file2);
	crypt();
	remove("snake.dat");
	rename("snake1.dat","snake.dat");
	getch();
	exit(0);
	return 0;
}
design()
{

	hide();
	viewport();
	setfillstyle(3,3);
	status("                         Return :[Any key]");
	settextstyle(4,0,3);
	setcolor(10);
	setusercharsize(2,1, 2, 1);
	outtextxy(50,70,"Created By :  ");
	setcolor(14);
	settextstyle(1,0,2);
	setusercharsize(1,1, 1, 1);
	outtextxy(160,240,"E.P.Rama krishnan \(02CS24\),");
	
	getch();
	show();
	return 0;
}
front()
{
     setfillstyle(10,4);
     bar(0,0,getmaxx(),getmaxy());
     settextstyle(1,0,18);
     setusercharsize(5, 1, 5, 1);
     setcolor(10);
     outtextxy(100,150,"SNAKE");
     setusercharsize(2, 1, 1, 1);
     setcolor(10);
     outtextxy(400,325,"Game");
     settextstyle(1,0,1);
     setcolor(14);
     outtextxy(100,380,"  Done By :");
     setcolor(9);
     outtextxy(200,400,"  E.P.Ramakrishnan,");
    
    delay(2500);
    //getch();
    return 0;
}
viewport()
{
setfillstyle(SOLID_FILL,0);
bar(0,0,getmaxx(),getmaxy());
return 0;
}
crypt()
{
	char ccc;
	FILE *fi1,*fi2;
	fi1=fopen("snake.dat","r");
	fi2=fopen("temp.dat","w");
	while((ccc=fgetc(fi1))!=EOF)
	{
		if(ddd==1)
			fputc(ccc+12,fi2);
		else
			fputc(ccc-12,fi2);
	}
	if(ddd==1)
		ddd=0;
	else
		ddd=1;
	fclose(fi1);
	fclose(fi2);
	remove("snake.dat");
	change("snake.dat","temp.dat");
	remove("temp.dat");
	return 0;

}
  change(char ne[30],char old[30])
  {
	FILE *in,*out;
	char c;
	in=fopen(old,"r");
	rewind(in);
	out=fopen(ne,"w");
	while(1)
	{
			c=fgetc(in);
		if(c==EOF)
			break;
		else
			fputc(c,out);
	}

	return 0;
  }

