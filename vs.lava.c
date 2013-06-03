#define UP_KEY 0x14
#define DOWN_KEY 0x15
#define LEFT_KEY 0x17
#define RIGHT_KEY 0x16
#define ESC_KEY 27


char Str[6][20]={"����","��սʷ","����Ⱥ","��Ա��","��ͼ��","�뿪"};
char Str2[6][25]={"LAVA����:CoolMore","����߻�:FireGhost","����:CoolMore"
 ,"��־&&��վ:FireGhost","�����:CoolMore"};
int P_ID;

char team[2][11]={"�ʼ������","��������"};
char p_name[32][11]={ "��������˹","�����Ӷ�","����˹","�����","��������","�Ͷ�",
                            "���ɶ���","�ޱ����","����˹","���յ�˹��","��¸���",
                            "���˺�ķ","����άɭ","�ŵ�","����","������"
                            ,"�Ͷ���˹","³��","������","���˹","��Լ��","����¡˹��"
                            ,"�����׶�ɭ","��ά","С��","����÷��","�¿�","����˹��",
                            "����ɭ","����","���а�","÷��"};
char position[7][5]={"","�Ž�","����","����","�г�","ǰ��","ǰ��"};
                        

int p_position[32]={1,2,2,5,3,6,6,6,1,4,2,4,3,4,2,4,1,1,2,2,2,2,2,4,5,4,5,4,6,6,6,6};
int p_number[32]={1,2,3,5,6,7,9,10,13,8,18,23,16,14,22,12,1,28,2,4,5,12,15,6,10,14,20,
                    24,7,8,9,30};
int attack[32]={70,78,85,90,80,90,95,93,70,82,70,88,76,83,70,84,
                70,70,76,70,84,75,84,88,92,84,86,80,86,88,94,87};
int mid[32]={   70,80,89,97,83,85,88,91,70,89,79,90,80,87,83,85,
                70,70,77,80,87,83,86,88,95,82,92,88,87,83,82,82};
int defen[32]= {80,88,92,82,93,79,82,76,77,84,91,76,94,87,88,81,
                79,70,89,84,93,84,85,71,80,83,74,79,77,83,74,80};
int save[32]={93,0,0,0,0,0,0,0,84,0,0,0,0,0,0,0,92,88,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

char pic[1600];
void Show_Pic(int x,int y,int no,int ty)
{
	
	int	fp;
	ClearScreen();
	SetScreen(1);
	Refresh();
	fp=fopen("/LavaData/FIFA.dat","r");
	fseek(fp,1600*no,SEEK_SET);
	fread(pic,1,1600,fp);
	fclose(fp);
	WriteBlock(x,y,160,80,ty,pic);
	
	XDraw(5);
	Refresh();
	
	
	
}
int Choose_Team_Menu()
{
char c;int i;
SetScreen(1);
ClearScreen();


Refresh();
TextOut(20,40,"ѡ���������������",1);
Refresh();
getchar();
i=1;

while (c!=13)
{

Show_Pic(-9,-3,i,1);

if (i==1) TextOut(1,1,team[0],1);
else {TextOut(1,1,team[1],1);}
Refresh(); 
c=getchar();
i++;
if (i==3) i=1;
}
P_ID=i;
}






void Show_Welcome(int String )
{



Block(0,60,160,80,0);
    Rectangle(1,60,159,79,1);
    Rectangle(3,62,157,77,1);
  TextOut(5,65,String,1);
  Refresh();
  getchar();


  
}


void Game_Start_Menu()
{
Show_Pic(-12,-5,0,2);
getchar();
}









int Show_Player_Messages()
{
int i;
char c;
int sa;
i=0;
SetScreen(1);
ClearScreen();
Refresh();
while (c!=ESC_KEY)
{
sa=i/16;
printf("%s\n",team[sa]);
printf("%s  ",p_name[i]);
printf("%s %d��  \n",position[p_position[i]],p_number[i]);
if (p_position[i]==1)
{printf("�˾�%d ����%d \n",save[i],defen[i]);}
else
{
printf("����%d  ��֯%d  ����%d \n",attack[i],mid[i],defen[i]);
}

sa=(p_position[i]*(attack[i]*6+mid[i]*7)+defen[i]*(100-p_position[i]*13)+save[i]*15)/100;
printf("�ۺ�����:%d",sa);
if (CheckKey(128)==0) 
{
c=getchar();

if (c==ESC_KEY) return 0;

}

SetScreen(1);
if (i==31&&c==DOWN_KEY) i=-1;
if (i==0&&c==UP_KEY) i=32;
if (c==DOWN_KEY) i++;
if (c==UP_KEY) i--;
Delay (200);


}
}
void Show_Names()
{
 ClearScreen();
 SetScreen(1);
 Refresh();
 
 TextOut(20,30,"CoolMore:ë����",1);
 TextOut(20,43,"FireGhost:����ɭ",1);
 Refresh();
 getchar();
}

 

int Maker_Information()
{
   
   int i;
   int j;
   int sa;
   i=40;
   ClearScreen();
 SetScreen(1);
 Refresh();
 
 
 
 
 Rectangle(1,1,3,79,1);
 Rectangle(157,1,159,79,1);
 Rectangle(5,1,7,79,1);
 Rectangle(153,1,155,79,1);
 Refresh();
 for (i=80;!Inkey();i--)
 {
 for (j=0;j<6;j++)
 {
 sa=i+j*15;
 
 
 if (sa<=80&&sa>=1)
 {
 TextOut(26,sa-1,"                    ",1);
 TextOut(26,sa,Str2[j],1);
 Refresh();
 
 }
 }
 
 if (i<0) 
 {
 
 Delay(2000);
 ClearScreen();
 Rectangle(1,1,3,79,1);
 Rectangle(157,1,159,79,1);
 Rectangle(5,1,7,79,1);
 Rectangle(153,1,155,79,1);
 Refresh();
 i=80;
 
 }
 }
 
 Show_Names();
 return 0;
 

}

                           


int Main_Menu()
{
char c;
int i;i=0;
Show_Pic(0,0,3,2);

while (c=13)
{

Block(1,1,43,22,0);
Rectangle(1,1,43,22,1);
Rectangle(3,3,41,20,1);
Refresh();
SetScreen(1);
TextOut(5,5,Str[i],1);
Refresh();
c=getchar();
if (c==13) return i;
if (c==DOWN_KEY) i++;
if (c==UP_KEY) i--;
if (i==6) i=5;
if (i==-1) i=0;

}


}

void Welcome()
{
Show_Welcome("��ӭʹ����CoolMore��д��");
Show_Welcome("FIFA2006--���������ҵ±�.");
Show_Welcome("     ���κ���ҵĿ��.");
Show_Welcome("     ��л:FireGhost.");
}

int History()
{
int	fp;int i;
	ClearScreen();
	SetScreen(1);
	Refresh();
	fp=fopen("/LavaData/History.txt","r");
	fseek(fp,1,EOF);
	fread(pic,1,40,fp);
	fclose(fp);
	for (i=0;i<20;i=i+2)
	{
	printf("%d.%s%d:%d%s\n",i/2+1,team[0],pic[i],pic[i+1],team[1]);
	getchar();
	}
	for (i=0;i<20;i=i+2)
	{
	printf("%d.%s%d:%d%s\n",i/2+1,team[1],pic[i+19],pic[i+20],team[0]);
	getchar();
	}
}

	
	
	


int Pictures()
{
int i;
for(i=0;i<27;i++)
{

Show_Pic(-18,-2,i+4,2);
if (getchar()==ESC_KEY) return 0;

}
ClearScreen();
Refresh();
TextOut(40,20,"лл�ۿ�!",1);
TextOut(40,40,"����:ë����",1);
Refresh();
getchar();
}

void Quit()
{
 SetScreen(1);
 ClearScreen();
 Refresh();
 Rectangle(1,1,159,79,1);
 Rectangle(3,3,157,77,1);
 
 TextOut(15,20,"maosuhan@yahoo.com.cn",1);
 TextOut(15,40,"zhaosusen@yahoo.com.cn",1);
 Refresh();
 getchar();
 exit(0);
 }
 
 
 
 
void main()
{
    
    int choose;
    
  Game_Start_Menu();
  Welcome();
  Choose_Team_Menu();

  while(1)
  {
  choose=Main_Menu();
  
  if (choose==3) Show_Player_Messages();
  if (choose==4) Pictures();
  if (choose==2) Maker_Information();
  if (choose==1) History();
  if (choose==5) Quit();
  }
  
  
}
