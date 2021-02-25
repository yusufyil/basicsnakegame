#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#define xcoord 168
#define	 ycoord 50
void setTable(void);
void drawTable(void);
void moveSnake(void);
void foodGenerator(void);
void gotoxy(int , int);
char table[xcoord][ycoord]={0};
//those two array storing snakes position.
int snakex[8400];
int snakey[8400];
//direction veriable holds direction of snake (w for up, d for right, a for left, s for down)
char direction='d';
int length=1;
int gameContinue=1;
//i assigned 1 for first food 
int newfood=1;
int main (void){
	srand(time(NULL));
	char input;
	snakex[0]=84;
	snakey[0]=25;
	table[84][25]='*';
//	table[80][20]='O';
	setTable();
	drawTable();
	while(gameContinue){
	if(kbhit()){
		input=getch();
		if(input=='w'||'a'||'s'||'d'){
			if(direction=='w'&&input!='s'||direction=='a'&&input!='d'||direction=='s'&&input!='w'||direction=='d'&&input!='a')
			direction=input;
		}
	}
	if (newfood==1)
	foodGenerator();
	newfood=0;
	moveSnake();
	usleep(50000);
	}
	gotoxy(0,100);
	printf("Your Score is %d well done....",length);
}
void setTable(void){
	int k;
	for(k=0;k<168;k++){
		table[k][0]='-';
		table[k][49]='_';
	}
	for(k=0;k<50;k++){
		table[0][k]='|';
		table[167][k]='|';
	}
}
void drawTable(void){
	int k;
	for(k=0;k<50;k++){
		int n;
		for(n=0;n<168;n++){
			printf("%c",table[n][k]);
		}
	}
}
void moveSnake (void){
		int n;
		for(n=length;n>0;n--){
		snakex[n]=snakex[n-1];
		snakey[n]=snakey[n-1];
		}
	if (direction=='d'){
			if(table[snakex[0]+1][snakey[0]]=='O'){
				length++;
				newfood=1;
			}
			else if(table[snakex[0]+1][snakey[0]]=='|'||table[snakex[0]+1][snakey[0]]=='-'||table[snakex[0]+1][snakey[0]]=='_')
			gameContinue=0;
			else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1]+1;
			snakey[0]=snakey[1];
			table[snakex[0]][snakey[0]]='*';
			
			gotoxy(snakex[0],snakey[0]);
			printf("*");
			gotoxy(snakex[length],snakey[length]);
			printf(" ");
			
		
	}
	else if (direction=='a'){
		if(table[snakex[0]-1][snakey[0]]=='O'){
			length++;
			newfood=1;
		}
		else if (table[snakex[0]-1][snakey[0]]=='|'||table[snakex[0]-1][snakey[0]]=='-'||table[snakex[0]-1][snakey[0]]=='_')
		gameContinue=0;
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1]-1;
			snakey[0]=snakey[1];
			table[snakex[0]][snakey[0]]='*';
			
			gotoxy(snakex[0],snakey[0]);
			printf("*");
			gotoxy(snakex[length],snakey[length]);
			printf(" ");
		
	}
	else if (direction=='s'){
		if(table[snakex[0]][snakey[0]+1]=='O'){
			length++;
			newfood=1;
		}
		else if(table[snakex[0]][snakey[0]+1]=='|'||table[snakex[0]][snakey[0]+1]=='-'||table[snakex[0]][snakey[0]+1]=='_')
		gameContinue=0;
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1];
			snakey[0]=snakey[1]+1;
			table[snakex[0]][snakey[0]]='*';
			
			gotoxy(snakex[0],snakey[0]);
			printf("*");
			gotoxy(snakex[length],snakey[length]);
			printf(" ");
		
	}
	else if (direction=='w'){
		if(table[snakex[0]][snakey[0]-1]=='O'){
			length++;
			newfood=1;
		}
		else if(table[snakex[0]][snakey[0]-1]=='|'||table[snakex[0]][snakey[0]-1]=='-'||table[snakex[0]][snakey[0]-1]=='_')
		gameContinue=0;
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1];
			snakey[0]=snakey[1]-1;
			table[snakex[0]][snakey[0]]='*';
			
			gotoxy(snakex[0],snakey[0]);
			printf("*");
			gotoxy(snakex[length],snakey[length]);
			printf(" ");
	}
}
void foodGenerator(void){
	int randx;
	int randy;
	do{
	randx=rand()%165+1;
	randy=rand()%48+1;
	}
	while(table[randx][randy]=='*');
	table[randx][randy]='O';
	gotoxy(randx,randy);
	printf("O");
}
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
