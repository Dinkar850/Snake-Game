#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void frontpage();
void gameplay();
void customize();
void gameover(int);
void updateScore(int);
void displayControls();
void showCredits();
void mainmenu();
int x = 650;
int high = 0;
int plain = GREEN;
int border = BROWN;
int m;
int i;
int j;
int fX;
int fY;
int sX[200];
int sY[200];
int key;
int body;int  f; int dt; int prev_dir;int l;int game;int selection;
char mess[100] = "P R E S S    E N T E R", str[100] = "SNAKE", pl[100] = "Play";
char pl1[100] = "Controls";
char pl2[100] = "Customize";
char pl3[100] = "Credits";
char pl4[100] = "Exit";
char str1[100] = "MAIN MENU";
char str2[100] = "P R E S S     E N T E R     T O     S E L E C T";
char keystate, str3[100] = "SCORE", str4[100] = "HIGH";
char str5[100] = "GAME OVER";
char str10[100];
char str6[100] = "NEW HIGHSCORE!!";
char str7[100];
char strf[100] = "MOVE RIGHT  :       D";
char strb[100] = "MOVE LEFT   :       A";
char stru[100] = "MOVE UP     :       W";
char strd[100] = "MOVE DOWN  :       S", str8[100], str9[100];
char pl5[100] = "DEFAULT(GRASS)";
char pl6[100] = "OCEAN";
char pl7[100] = "CONCRETE";
char mess1[100] = "DO NOT PRESS ENTER UNTIL \"PRESS ENTER\" IS DISPLAYED";
char pl8[100] = "BY- DINKAR GUPTA (SEC-B)";
char pl9[100] = "2022021124";


int main()
{
    int gm ,gd = DETECT;

    char data[] = "C:\\TURBOC3\\BGI"; //static file

    initgraph(&gd, &gm, data);
    frontpage();


    getch();
    closegraph();

    return 0;
}

void frontpage() {
    int a = 0;a++;
    m = -80;
    setbkcolor(BLUE);

    setcolor(YELLOW);
    settextstyle(7,0,8);
    outtextxy(x/2-150, 90, str);

    setfillstyle(1, RED);
    bar(0, 310 + m, 320, 350 + m);

    setfillstyle(1, MAGENTA);
    bar(320, 325 + m, 345, 335 + m);

    setfillstyle(1, DARKGRAY);
    setcolor(DARKGRAY);
    circle(310, 320 + m, 5);
    circle(310, 340 + m, 5);
    floodfill(310, 320 + m, DARKGRAY);
    floodfill(310, 340 + m, DARKGRAY);

    setfillstyle(1, GREEN);
    bar(500, 310 + m, 540, 350 + m);

    setfillstyle(1, BROWN);
    bar(515, 300 + m, 525, 310 + m);

    settextstyle(2, 0, 7);
    setcolor(YELLOW);
    outtextxy(x / 2 - 90, 430, mess);

    delay(10);
    getch();
    mainmenu();
}

void mainmenu(){
    setbkcolor(BLACK);

	selection=0;

	cleardevice();
    setcolor(15);

    // int x = getmaxx();


	while(1){
		cleardevice();
		// outtextxy(x/2-100,100,pl);
	    settextstyle(3, 0, 5);
	    outtextxy(x/2 - 100,70,str1);
	    settextstyle(3,0,3);
		outtextxy(x/2-40,160,pl);
		outtextxy(x/2-40,210,pl1);
		outtextxy(x/2-40,260,pl2);
		outtextxy(x/2-40,310,pl3);
		outtextxy(x/2-40,360,pl4);
		// circle(x/2-110,125,5);
		circle(x/2-50,175,5);
		circle(x/2-50,225,5);
		circle(x/2-50,275,5);
		circle(x/2-50,325,5);
		circle(x/2-50,375,5);


		setfillstyle(SOLID_FILL,15);
		floodfill(x/2-50,175+50*selection,15);
	    settextstyle(2, 0, 5);
	    outtextxy(x / 2 - 150, 430, str2);
	    setfillstyle(1, RED);
	    bar(5, 5, 25, 125);
	    setfillstyle(1, YELLOW);
	    bar(5, 205, 25, 225);
	    setfillstyle(1, BLUE);
	bar(615, 470, 635, 350);
	setfillstyle(1, MAGENTA);
	bar(615, 270, 635, 290);


	switch(getch()){
			case 'W':
			case 'w':
				if (selection == 0)
					selection = 4;
				else
					selection--;
				break;
			case 's':
			case 'S':
				if (selection == 4)
					selection = 0;
				else
					selection++;
				break;
			case 13://enterkey - CR
				if (selection == 0){
					gameplay();
				}
				else if(selection == 1){
					displayControls();
				}
				else if(selection == 2){
					customize();
				}
				else if (selection == 3){
					showCredits();
				}
				else {
		            high = 0;
					exit(0);
				}

				break;
			default:
				break;
		}

	}
}

void gameplay() {
    cleardevice();
    body = 500; f = 0; dt = 200; prev_dir = 1; l = 1; game = 1;
    sX[200], sY[200];
    fX = 200;
    fY = 200;

    for (i = 0; i < 200; i++) {
	sX[i] = 0;
	sY[i] = 0;
    }
    sX[0] = 200, sY[0] = 200;
    key = 1;

    //game panel

    while (game) {
	cleardevice();
	setfillstyle(1, plain);
	bar(0, 0, 550, 480);
	setfillstyle(1, border);
	bar(0, 0, 550, 10);
	bar(0, 0, 10, 480);
	bar(0, 480, 550, 470);
	bar(540, 10, 550, 480);
	setfillstyle(1, YELLOW);
	settextstyle(3, 0, 2);
	outtextxy(565, 90, str3);
	outtextxy(565, 270, str4);

	if (sX[0] == fX && sY[0] == fY) {
	    l += 1;
	    f += 1;
	    dt = dt - 2;
	    bar(fX, fY, fX + 10, fY + 10);

	    do{
		fX = (10 + rand() % 500);
		fY = (10 + rand() % 450);
	    }while (getpixel(fX, fY) != 0 && fX > 10 && fY > 10);

	    fX /= 10; //for in multiples of 10
	    fX *= 10;
	    fY /= 10;
	    fY *= 10;

	    if (fX == 10) { //for food is not stuck to an end
		fX = rand() % 10 + 5; //5 - 14 values
		fX *= 10;
	    }
	    else if (fY == 10) {
		fY = rand() % 10 + 5;
		fY *= 10;
	    }

	}
	updateScore(f);
	bar(fX, fY, fX + 10, fY + 10);

	setfillstyle(1, RED);

	if(kbhit()){
			switch(getch()){
				case 'D':
				case 'd':
					key = 1;
					break;
				case 'a':
				case 'A':
					key = 2;
					break;
				case 'W':
				case 'w':
					key = 3;
					break;
				case 'S':
				case 's':
					key = 4;
					break;
				default:
					break;
	    }
	}
	switch (key) {
	    case 0:
		if (prev_dir == 1) {
		    sX[0] = sX[0] + 10; //if was moving in right, then right
		}
		else if (prev_dir == 2) {
		    sX[0] = sX[0] - 10; //if was moving in right, then right
		}
		else if (prev_dir == 3) {
		    sY[0] = sY[0] - 10; //if was moving in right, then right
		}
		else if (prev_dir == 4) {
		    sY[0] = sY[0] + 10; //if was moving in right, then right
		}
		else key = 0;
		break;

	    case 1:
		sX[0] = sX[0] + 10;
		prev_dir = 1;
		break;

	    case 2:
		sX[0] = sX[0] - 10;
		prev_dir = 2;
		break;

	    case 3:
		sY[0] = sY[0] - 10;
		prev_dir = 3;
		break;

	    case 4:
		sY[0] = sY[0] + 10;
		prev_dir = 4;
		break;
	}
	//displaying snake

	for (i = 0; i < l; i++) {
	    bar(sX[i], sY[i], sX[i] + 10, sY[i] + 10);
	}
	//body
	for (j = 199; j > 0; j--) {
	    sX[j] = sX[j - 1];
	    sY[j] = sY[j - 1];
	}

	//touching body

	for (i = 2; i < l; i++) {
	    if(sX[0] == sX[i] && sY[0] == sY[i]) {
		body = i;
		break;
	    }
	}
	delay(dt);

	//touching boundary

	if (sX[0] >= 525 || sX[0] <= 5 || sY[0] <= 5 || sY[0] >= 455) {
	    game = 0;
	}

	if (sX[0] == sX[body] || sY[0] == sY[body]) {
	    game = 0;
	}

    }
    gameover(f);
}

void gameover(int f) {
    cleardevice();
    // setbkcolor(GREEN);
    settextstyle (3, 0, 5);
    setcolor(WHITE);
    outtextxy(x/2-125,165,str5);
    settextstyle (3, 0, 3);
    sprintf(str10, "TOTAL SCORE: %d", f);
    outtextxy(x/2-100,305,str10);
    if (f > high) {
	high = f;
	setcolor (YELLOW);
	sprintf(str7, "HIGHSCORE: %d", high);
	outtextxy(x / 2 - 100, 235, str6);
	setcolor(15);
	outtextxy(x/2-95, 335, str7);
    }
    else {
	sprintf(str7, "HIGHSCORE: %d", high);
	outtextxy(x/2-95, 335, str7);
    }
    delay(10);
    getch();
    mainmenu();
}
void displayControls() {
    cleardevice();
    settextstyle(3, 0, 2);
    outtextxy(x/2-120,150,strf);
    outtextxy(x/2-120,200,strb);
    outtextxy(x/2-120,250,stru);
    outtextxy(x/2-120,300,strd);
    settextstyle(2, 0, 5);
    outtextxy(x / 2 - 120, 430, mess);

    delay(10);
    getch();
    mainmenu();
}

void updateScore(int food) {
    settextstyle(3, 0, 1);
    sprintf(str8, "%d", food);
    sprintf(str9, "%d", high);
    outtextxy(585, 120, str8);
    outtextxy(585, 300, str9);

}


void customize() {
    selection = 0;
    cleardevice();

    while(1) {
	cleardevice();
	settextstyle(3,0,3);
	outtextxy(x/2-70,160,pl5);
	outtextxy(x/2-70,210,pl6);
	outtextxy(x/2-70,260,pl7);
	setfillstyle(1, GREEN);
	bar(500, 165, 520, 185);
	setfillstyle(1, BROWN);
	bar(530, 165, 550, 185);

	setfillstyle(1, BLUE);
	bar(500, 215, 520, 235);
	setfillstyle(1, LIGHTBLUE);
	bar(530, 215, 550, 235);

	setfillstyle(1, DARKGRAY);
	bar(500, 265, 520, 285);
	setfillstyle(1, LIGHTGRAY);
	bar(530, 265, 550, 285);


	circle(x/2-80,175,5);
	circle(x/2-80,225,5);
	circle(x/2-80,275,5);
	setfillstyle(SOLID_FILL,15);
	floodfill(x/2-80,175+50*selection,15);
	settextstyle(2, 0, 5);
	outtextxy(x / 2 - 150, 430, str2);
	switch(getch()){
			case 'W':
			case 'w':
				if (selection == 0)
					selection = 2;
				else
					selection--;
				break;
			case 's':
			case 'S':
				if (selection == 2)
					selection = 0;
				else
					selection++;
				break;
			case 13://enterkey - CR
				if (selection == 0){
					plain = GREEN;
		    border= BROWN;
		    mainmenu();
				}
				else if(selection == 1){
					plain = LIGHTBLUE;
		    border= BLUE;
		    mainmenu();

		}
				else if(selection == 2){
					plain = LIGHTGRAY;
		    border= DARKGRAY;
		    mainmenu();
				}
				else {
		    mainmenu();
				}

				break;
			default:
				break;
		}

    }

}
void showCredits() {
    cleardevice();
    for (i = 500; i  >= 250; i -= 5) {
	cleardevice();
	settextstyle(3,0,1);
	outtextxy(0, 10, mess1);
	settextstyle(3, 0, 2);
	outtextxy(x/2-100,i,pl8);
	outtextxy(x/2-50, i + 40,pl9);
	delay(100);
    }
    settextstyle(2, 0, 7);
    setcolor(15);
    outtextxy(x / 2 - 90, 430, mess);
    getch();
    mainmenu();

}




