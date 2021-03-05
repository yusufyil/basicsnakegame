#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define xcoord 168
#define	 ycoord 50
void setTable(void);
void drawTable(void);
void moveSnake(void);
void foodGenerator(void);
void gotoxy(int , int);
void gameStart(void);
char table[xcoord][ycoord]={0};
//those two array storing snakes position.
int snakex[xcoord*ycoord];
int snakey[xcoord*ycoord];
//direction veriable holds direction of snake (w for up, d for right, a for left, s for down)
char direction='d';
int length=1;
int gameContinue=1;
//i assigned 1 for first food 
int newfood=1;
int main (void){
	gameStart();
	srand(time(NULL));
	char input;
	snakex[0]=xcoord/2;
	snakey[0]=ycoord/2;
	table[xcoord/2][ycoord/2]='*';
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
	sleep(10);
}
void setTable(void){
	int k;
	for(k=0;k<xcoord;k++){
		table[k][0]='-';
		table[k][ycoord-1]='_';
	}
	for(k=0;k<ycoord;k++){
		table[0][k]='|';
		table[xcoord-1][k]='|';
	}
}
void drawTable(void){
	int k;
	for(k=0;k<ycoord;k++){
		int n;
		for(n=0;n<xcoord;n++){
			if(table[n][k]=='|')
			printf("|");
			else if(table[n][k]=='-')
			printf("-");
			else if(table[n][k]=='_')
			printf("_");
			else if(table[n][k]=='*')
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
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
			else if(table[snakex[0]+1][snakey[0]]=='|'||table[snakex[0]+1][snakey[0]]=='-'||table[snakex[0]+1][snakey[0]]=='_'||table[snakex[0]+1][snakey[0]]=='*')
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
		else if (table[snakex[0]-1][snakey[0]]=='|'||table[snakex[0]-1][snakey[0]]=='-'||table[snakex[0]-1][snakey[0]]=='_'||table[snakex[0]-1][snakey[0]]=='*')
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
		else if(table[snakex[0]][snakey[0]+1]=='|'||table[snakex[0]][snakey[0]+1]=='-'||table[snakex[0]][snakey[0]+1]=='_'||table[snakex[0]][snakey[0]+1]=='*')
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
		else if(table[snakex[0]][snakey[0]-1]=='|'||table[snakex[0]][snakey[0]-1]=='-'||table[snakex[0]][snakey[0]-1]=='_'||table[snakex[0]][snakey[0]-1]=='*')
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
	randx=rand()%(xcoord-1)+1;
	randy=rand()%(ycoord-1)+1;
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
void gameStart(void){
	int seconds=10;
	printf("you can steer the snake \n");
	printf("you can adjust game area by changing value of xcoord and ycoord.(both of them placed on top of the source code..)\n");
	for(;seconds>=0;seconds--){
		printf("game will start in %d seconds please make your game full screen..\n",seconds);
		sleep(1);
	}
	system("cls");
}
