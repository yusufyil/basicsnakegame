#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
void gotoxy(int, int);
void setTable(void);
void drawTable(void);
void moveSnake(void);
void foodGenerator(void);
char table[168][50]={0};
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
	while(gameContinue){
	if(kbhit()){
		input=getch();
		if(input=='w'||'a'||'s'||'d')
		direction=input;
	}
	if (newfood==1)
	foodGenerator();
	setTable();
	drawTable();
	newfood=0;
	moveSnake();
	usleep(50000);
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
	if (direction=='d'){
		int n;
		for(n=length;n>0;n--){
			snakex[n]=snakex[n-1];
			snakey[n]=snakey[n-1];
		}
			if(table[snakex[0]+1][snakey[0]]=='O'){
				length++;
				newfood=1;
			}
			else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1]+1;
			snakey[0]=snakey[1];
			table[snakex[0]][snakey[0]]='*';
		
	}
	else if (direction=='a'){
		int n;
		for(n=length;n>0;n--){
			snakex[n]=snakex[n-1];
			snakey[n]=snakey[n-1];
		}
		if(table[snakex[0]-1][snakey[0]]=='O'){
			length++;
			newfood=1;
		}
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1]-1;
			snakey[0]=snakey[1];
			table[snakex[0]][snakey[0]]='*';
		
	}
	else if (direction=='s'){
		int n;
		for(n=length;n>0;n--){
			snakex[n]=snakex[n-1];
			snakey[n]=snakey[n-1];
		}
		if(table[snakex[0]][snakey[0]+1]=='O'){
			length++;
			newfood=1;
		}
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1];
			snakey[0]=snakey[1]+1;
			table[snakex[0]][snakey[0]]='*';
		
	}
	else if (direction=='w'){
		int n;
		for(n=length;n>0;n--){
			snakex[n]=snakex[n-1];
			snakey[n]=snakey[n-1];
		}
		if(table[snakex[0]][snakey[0]-1]=='O'){
			length++;
			newfood=1;
		}
		else
			table[snakex[length]][snakey[length]]=0;
			snakex[0]=snakex[1];
			snakey[0]=snakey[1]-1;
			table[snakex[0]][snakey[0]]='*';	
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
}

