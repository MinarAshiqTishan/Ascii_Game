#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include <conio.h>
#include <windows.h>

char scr[23][77];
char dir;
char A[23][77];
int a[10],b[10];
int t=0,n=0,w=1;
int y3=0,y2=0;
int Z=1,Y=5;

void clear_screen()
{
	HANDLE hConsole;
	hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;   
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	DWORD dwConSize; 
	GetConsoleScreenBufferInfo(hConsole, &csbi);   
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}


void screen(int r,int c,int g,int z,int y){ 
  int row,col,k,i,j;
  int q;
  
  //if(w<2)w++;
  //else w=1;
  
  printf("STEPS LEFT : %d        ",g);
  printf("SCORE:%d  [up= w ,down= s ,right= d ,left= a]\n",n);
  
  for(row=0;row<23;row++){
    for(col=0;col<77;col++){
       scr[row][col]=' ';                    
     }  
  }
 
 for(row=0;row<23;row++){
    for(col=0;col<77;col++){
      if(col==0 || col==76){
	     scr[row][col]='|';
	  }
      else if(row==0 || row==22){
	 	 scr[row][col]='-';
	  }
    
    if(z==1) {
     scr[r][c]='O';      
     scr[r+1][c]='-';
     scr[r+1][c+1]='\\';
     scr[r+1][c-1]='/';
     scr[r-1][c]='-';
     scr[r-1][c-1]='\\';
     scr[r-1][c+1]='/';
     scr[r][c+1]='-';
     scr[r][c-1]='-';
    }
    
    /*else if(w==2){scr[r][c]='O';      
     scr[r+1][c]='|';
     scr[r+1][c+1]='\\';
     scr[r+1][c-1]='\\';
     scr[r-1][c]='|';
     scr[r-1][c-1]='\\';
     scr[r-1][c+1]='\\';
     scr[r][c+1]='-';
     scr[r][c-1]='-';}*/
    
   else if(y==5){
     scr[r][c]='O';      
     scr[r+1][c]='|';
     scr[r+1][c+1]='\\';
     scr[r+1][c-1]='/';
     scr[r-1][c]='|';
     scr[r-1][c-1]='\\';
     scr[r-1][c+1]='/';
     scr[r][c+1]='|';
     scr[r][c-1]='|';
	 }
    
    else if(z==2 || y==6){
     scr[r][c]='O';      
     scr[r+1][c]='|';
     scr[r-1][c]='|';
     scr[r][c+1]='-';
     scr[r][c-1]='-';
    }
    
    
    }
    
    
  }
   
   
   for(q=0;q<10;q++){
     if(r==a[q] && c==b[q] ||r+1==a[q] && c==b[q]||r+1==a[q] && c+1==b[q]||r+1==a[q] && c-1==b[q]||r-1==a[q] && c==b[q]||r-1==a[q] && c-1==b[q]||r-1==a[q] && c+1==b[q]||r==a[q] && c+1==b[q]||r==a[q] && c-1==b[q])
     {t=t-1; a[q]=0;b[q]=0;n+=10;y2+=10;}
   }  
   if(t==0){
      t=10;food();
   }
   else food2();

   

for(row=0;row<23;row++){
    for(col=0;col<77;col++){
     printf("%c",scr[row][col]);
    }
    printf("\n");
  }
}

int food()
{
 int i,j,k;
 for(i=0;i<10;i++){
       k=rand()%20;
       j=rand()%72;
       a[i]=k;b[i]=j;
      
      if( k>0) scr[k][j]='\4';
      //else if(k>0) scr[k][j]='O';
     }

}

int food2()
{
 int i,j,k;
 
 for(i=0;i<10;i++)
     {
      
      if(k<5) scr[a[i]][b[i]]='\4';
      else if(a[i]==0 && b[i]==0)scr[a[i]][b[i]]=' ';
      else  scr[a[i]][b[i]]='\4';

     }

}


int main(void)
{
   int i=20,j=36,k=20,l=36;
    int m=70;
   char p;
  system("cls");
  system("color 0c");
   
   printf("\n\n\n\n\n\n                                THE GAME ");
   printf("\n\n                                  -BY TISHAN");
   getch();
   system("color 0f");
   do{

       clear_screen();
       
       screen(i,j,m,Z,Y);
      
      while(1)
       {
	 if(kbhit())
	 {
		   p=getch();
	       if(p=='a' ){
			   l=l-1;
			   m-=1;
			   Y=0;
			   if(Z<2)Z++;
			   else if(Z==0) Z=1;

			   else Z=1;

			   break;
			  }

	       else if(p=='d' ){
				l=l+1;
				Y=0;
				if(Z<2)Z++;
				else if(Z==0) Z=1;

				else Z=1;
				m-=1;
				break;
				}

	       else if(p=='s' ){
			       k=k+1;
			       m-=1;
			       Z=0;
			       if(Y<5)Y=5;
			       if(Y==5) Y++;
			       else Y=5;
			       break;
			       }

	       else if(p=='w' ){k=k-1;m-=1;
			       Z=0;
			       if(Y<5)Y=5;
				if(Y==5) Y++;
			       else Y=5;
			       break;}

	       else if(p=='x' ){dir=p;m-=1;break;}
	   }
       }

       if(k>0 && k<22)i=k;
       else if(k==0 ){k=1;}
       else if(k==22 ){k=21;}

       if(l>0 && l<75)j=l;
       else if(l==0 ){l=1;}
       else if(l==75 ){l=74;}
	if((y2-y3)==20){y3=y2;m+=23;}
       if(m==0) dir='x';
     }while(dir!='x');

   system("cls");
   system("color 0c");
   
   printf("\n\n\n\n\n\n                                GAME OVER");
   printf("\n\n                               YOUR SCORE:%d ",n);

 mo:
   p=getch();


    if(p=='x') return 0;
   else goto mo;
}
















