#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include <windows.h>




//배경음악 관련 함수

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <Digitalv.h>

MCI_OPEN_PARMS menuBgm;
MCI_PLAY_PARMS menu2Bgm;
MCI_OPEN_PARMS main1Bgm;
MCI_PLAY_PARMS play1Bgm;
MCI_OPEN_PARMS miniBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS main2Bgm;
MCI_PLAY_PARMS play2Bgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;

//bgm 경로를 바꾸어 주어야지 bgm이 들림
#define bgm0 "C:\\Users\\osh\\Desktop\\프로젝트 bgm\\메뉴음악.mp3"
#define bgm1 "C:\\Users\\osh\\Desktop\\프로젝트 bgm\\메인게임1음악.mp3"
#define bgm2 "C:\\Users\\osh\\Desktop\\프로젝트 bgm\\미니게임음악.mp3"
#define bgm3 "C:\\Users\\osh\\Desktop\\프로젝트 bgm\\메인게임2음악.mp3"
#define shuffle "C:\\Users\\osh\\Desktop\\프로젝트 bgm\\주사위굴리는소리.mp3"
int dwID;
void mainmenuBgm();
void maingame1_Bgm();
void minigame_Bgm();
void maingame2_Bgm();
void playingShuffleSound();




//공통으로 필요한 것
char temp;        //문자 입력 변수
#define PLAYER 10         //플레이어 수를 나타내는 것
int tem_main_score[PLAYER];    //메인게임 예비 점수배열
double tem_mini_score[PLAYER];  //미니게임 예비 점수배열
int i_tmp;              //변수 바꾸기를 위한 임시 정수형변수
double d_tmp;           //변수 바꾸기를 위한 임시 double형변수
int most;               //선택정렬 후 가장 큰 값의 인덱스를 저장해주는 값
int totalscore[PLAYER];  //종합게임점수
int mg_rank[PLAYER];     //미니게임 후 순서 저장 배열
void Total_score_ranking();




//메인메뉴 관련 함수
#pragma comment(lib,"winmm.lib")
#define SWAP(d,e,t) ((t)=(d),(d)=(e),(e)=(t))
#define A 55//sleep
#define _CRT_SECURE_NO_WARNINGS

typedef struct obj
{
	int x;
	int y;
}obj;

obj startcursor = { 8,13 };//메뉴용 커서
void mainmenu();
void erasecursor(void);//메뉴에서 사용하는거
void cursorsupply(void);//==
void init(void);
void start(void);
int skip;
void rule_menu();
int howto_a1();// 1번 게임 설명
int howto_a2();// 1번 게임 설명
int howto_a3();// 1번 게임 설명
int howto_b1();// 2번 게임 설명
int howto_c1();// 3번 게임 설명
int howto_c2();// 3번 게임 설명




//메인게임1 관련 함수
void maingame1();
void maingame1_rule();
int dice_rolling(int K, int x, int y, int** p2, int M, int N, int j);



//미니게임 관련 함수
void minigame();
int player_score_sort(double data[], int start, int data2[], int one_or_two);
char sequence[PLAYER];



//메인게임2 관련 함수
#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(col,0x000c);          //첫번째 빨간색
#define VIOLET SetConsoleTextAttribute(col,0x000d);       //두번째 자주색
#define GREEN SetConsoleTextAttribute(col,0x000a);        //세번째 초록색
#define YELLOW SetConsoleTextAttribute(col,0x000e);       //네번째 노란색
#define BLUE SetConsoleTextAttribute(col,0x0009);         //다섯째 파란색
#define WHITE SetConsoleTextAttribute(col,0x000f);

//4개의 지도루트(안겹치게 할려고 10은 100,20은 200 넣음)
int base_route[21] = { 0,2,4,6,8,100,12,14,16,18,200,22,24,26,28,300,32,34,36,38,40 };
int route1[13] = { 0,2,4,6,8,10,13,16,19,25,30,35,40 };
int route2[17] = { 0,2,4,6,8,100,12,14,16,18,20,21,23,25,30,35,40 };
int route3[23] = { 0,2,4,6,8,100,12,14,16,18,200,22,24,26,28,30,28,27,26,25,30,35,40 };

int a[10] = { 0,0,0,0,0,0,0,0,0,0 };             //주사위의 합산 배열 and 마지막에 메인게임2 스코어 정렬
int player[10] = { 0,0,0,0,0,0,0,0,0,0 };        //메인게임 플레이어 점수를 나타내는 배열
int o[10] = { 3,3,3,3,3,3,3,3,3,3 };   //말이 움직이면 빈칸 채우기 용도
int p[10] = { 4,6,8,10,12,4,6,8,10,12 }; //말이 움직이면 빈칸 채우기 용도

int score = 60;                        //메인게임2 도착했을 때 초기 점수
void maingame2(int hello);
void maingame2_rule();
void catch_player(char mynumber, int b, int mylocation, char n1, char n2, char n3, char n4, char n5,
	int p1, int p2, int p3, int p4, int p5, int hello);
int player_location(int dice, char playernumber, int delivery, int mynumber, int p1, int p2, int p3, int p4, int p5, 
	int an, int hello);
int player1_dice(int dice, int hello);
int player2_dice(int dice, int hello);
int player3_dice(int dice, int hello);
int player4_dice(int dice, int hello);
int player5_dice(int dice, int hello);
void map_print(int hello);
char map[38][78] = {
		{"┌----------------------------------------------------------------------┐"},
		{"│ __________                                                           │"},
		{"│|0(시작)  |                                                           │"},
		{"│|1 2 3 4 5|                                                           │"},
		{"│|_________|                                                           │"},
		{"│ _____                          ________                              │"},
		{"│| 2  |                         |  도   |                              │"},
		{"│|    |                         |  착   |                              │"},
		{"│|____|                         |_______|                              │"},
		{"│ _____                           _____                                │"},
		{"│| 4  |                          | 40 |                                │"},
		{"│|    |                          |    |   _____                        │"},
		{"│|____|                          |____|  | 38 |                        │"},
		{"│ _____                           _____  |    |  _____                 │"},
		{"│| 6  |                          | 35 |  |____| | 36 |                 │"},
		{"│|    |                          |    |         |    |  _____          │"},
		{"│|____|                          |____|         |____| | 34 |          │"},
		{"│ _____                           _____                |    |  _____   │"},
		{"│| 8  |                          | 30 |                |____| | 32 |   │"},
		{"│|    |                          |    |                       |    |   │"},
		{"│|____|                          |____|                       |____|   │"},
		{"│ _____   _____   _____   _____   _____   _____   _____   _____   _____│"},
		{"│| 10 |  | 13 |  | 16 |  | 19 |  | 25 |  | 26 |  | 27 |  | 28 |  | 30 |│"},
		{"│|    |  |    |  |    |  |    |  |    |  |    |  |    |  |    |  |    |│"},
		{"│|_->_|  |____|  |____|  |____|  |_^__|  |____|  |____|  |____|  |_<-_|│"},
		{"│    _____                        _____                        _____   │"},
		{"│   | 12 |                       | 23 |                       | 28 |   │"},
		{"│   |    |  _____                |    |                 _____ |    |   │"},
		{"│   |____| | 14 |                |____|                | 26 | |____|   │"},
		{"│          |    |  _____          _____          _____ |    |          │"},
		{"│          |____| | 16 |         | 21 |         | 24 | |____|          │"},
		{"│                 |    |  _____  |    |   _____ |    |                 │"},
		{"│                 |____| | 18 |  |____|  | 22 | |____|                 │"},
		{"│                        |    |   _____  |    |                        │"},
		{"│                        |____|  | 20 |  |____|                        │"},
		{"│                                |    |                                │"},
		{"│                                |_^__|                                │"},
		{"└----------------------------------------------------------------------┘"}
};


int main(void) 
{
	mainmenuBgm();
	mainmenu();

	return 0;
}

void mainmenu()
{
	init();
	start();
}
//메뉴화면
void clear(void)//화면을 비워줌
{
	system("cls");
}

void gotoxy(int x, int y)//커서를 이동시켜줌
{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void erasecursor(void)
{
	gotoxy(startcursor.x, startcursor.y);
	printf("  ");
}

void cursorsupply(void)
{
	gotoxy(startcursor.x, startcursor.y);
	printf("☞");
}

void init(void) //초기화를 해주는 함수
{

	CONSOLE_CURSOR_INFO curinfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);
	curinfor.bVisible = FALSE;//커서를 안보이게 함
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfor);

}

void start(void)
{
	clear();
	cursorsupply();
	while (1)
	{
		gotoxy(15, 6);
		printf("▣=============================== 주 사 위 게 임 ===============================▣");
		gotoxy(10, 13);
		printf("◑ 게임 시작");
		gotoxy(10, 16);
		printf("◑ 게임 설명");
		gotoxy(10, 19);
		printf("◑ 종료");
		gotoxy(5, 36);
		printf("방향키 : 이동 / 스페이스바 : 선택\n");
		if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
			if (startcursor.y <= 16) {
				erasecursor();
				startcursor.y = startcursor.y + 3;
				cursorsupply();
				Sleep(A + 200);
			}
			else {
				erasecursor();
				startcursor.y = 13;
				cursorsupply();
				Sleep(A + 200);
			}
		}
		if (GetAsyncKeyState(VK_UP) & 0X8000) {
			if (startcursor.y >= 16) {
				erasecursor();
				startcursor.y = startcursor.y - 3;
				cursorsupply();
				Sleep(A + 200);
			}
			else {
				erasecursor();
				startcursor.y = 19;
				cursorsupply();
				Sleep(A + 200);
			}
		}
		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			if (startcursor.y == 13) {
				maingame1();
				exit(0);
			}
			else if (startcursor.y == 16) {
				cursorsupply();
				rule_menu();
			}
			else if (startcursor.y == 19) {
				exit(0);
			}
		}
	}
}

void rule_menu(void) {
	cursorsupply();
	clear();
	while (1)
	{
		gotoxy(50, 1);
		printf("설명을 보고 싶은 게임을 선택하세요");
		gotoxy(10, 13);
		printf("◑ 1번 주사위 굴리기 게임");
		gotoxy(10, 18);
		printf("◑ 2번 주사위 사칙연산 게임");
		gotoxy(10, 23);
		printf("◑ 3번 주사위 윷놀이 게임");
		gotoxy(10, 28);
		printf("◑ 메인 메뉴로 돌아가기");
		gotoxy(5, 36);
		printf("방향키 : 이동 / 스페이스바 : 선택\n");
		if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
			if (startcursor.y <= 23) {
				erasecursor();
				startcursor.y = startcursor.y + 5;
				cursorsupply();
				Sleep(A + 200);
			}
			else {
				erasecursor();
				startcursor.y = 13;
				cursorsupply();
				Sleep(A + 200);
			}
		}
		if (GetAsyncKeyState(VK_UP) & 0X8000) {
			if (startcursor.y >= 18) {
				erasecursor();
				startcursor.y = startcursor.y - 5;
				cursorsupply();
				Sleep(A + 200);
			}
			else {
				erasecursor();
				startcursor.y = 28;
				cursorsupply();
				Sleep(A + 200);
			}
		}
		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			if (startcursor.y == 13) {
				cursorsupply();
				howto_a1();
			}
			else if (startcursor.y == 18) {
				cursorsupply();
				howto_b1();
			}
			else if (startcursor.y == 23) {
				cursorsupply();
				howto_c1();
			}
			else if (startcursor.y == 28) {
				start();
				cursorsupply();
			}
		}
	}
}


int howto_a1(void)
{
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(50, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 6);
		printf("※ 1번 주사위 굴리기 게임의 설명입니다");
		gotoxy(2, 9);
		printf("※ 크기가 N x M인 지도 위에 주사위 하나가 놓여져 있다.");
		gotoxy(2, 12);
		printf("※ 지도의 오른쪽은 동쪽, 위쪽은 북쪽, 왼쪽은 서쪽, 아래쪽은 남쪽이다.");
		gotoxy(2, 15);
		printf("※ 지도의 좌표는 (r, c)로 나타내며, r은 북쪽, c는 서쪽으로부터 떨어진 칸의 개수이다.");
		gotoxy(2, 18);
		printf("※ 주사위는 윗면이 1, 오른쪽면이 3, 왼쪽면이 4, 앞쪽이 5, 뒤쪽이 2, 밑면이 6으로 구성된다.");
		gotoxy(2, 21);
		printf("※ 주사위의 모든 면은 초기에 전부 0으로 주어진다");
		gotoxy(2, 24);
		printf("※ 지도의 각 칸에는 정수가 하나씩 쓰여져 있다.");
		gotoxy(2, 27);
		printf("※ 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥 면에 있는 수가 칸에 복사된다.");
		gotoxy(2, 30);
		printf("※ 이동한 칸에 쓰여 있는 수가 0이 아닌 경우 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사, 칸에 쓰여 있는 수는 0이 된다.");
		gotoxy(2, 33);
		printf("※ 주사위는 지도의 바깥으로 이동시킬 수 없다.(바깥으로 이동시키려고 하면 해당 명령을 무시, 복사X)");

		gotoxy(5, 40);
		printf("○다음 페이지 = 스페이스바");
		gotoxy(5, 42);
		printf("○메인 메뉴로 돌아가기 = z");
		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_a2();
		}
		if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}
	}
}

int howto_a2(void)
{
	if (skip == 1) return 0;
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(45, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 9);
		printf("※ 첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N ≤ 5, 1 ≤ M ≤ 10)");
		gotoxy(2, 12);
		printf("※ 주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 20)가 주어진다.");
		gotoxy(2, 15);
		printf("※ 둘째 줄부터는 가장 처음에 오는 수가 좌표 (0, 0) 부터 시작하여 동쪽으로는 c좌표가 증가되고,");
		gotoxy(2, 18);
		printf("※ 북쪽으로는 r좌표가 증가(지도의 각 칸에 쓰여 있는 수는 0부터 9까지, (x, y)좌표는 무조건 지도의 숫자가 0 이어야 함)");
		gotoxy(2, 21);
		printf("※ 마지막 줄에는 이동하는 명령이 순서대로 주어진다.");
		gotoxy(2, 24);
		printf("※ 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 표현이 된다.(M, N, x, y, K , 지도의 값은 랜덤으로 주어짐)  ");

		gotoxy(5, 40);
		printf("○다음 페이지 = SpaceBar");
		gotoxy(5, 42);
		printf("○이전 페이지 = x");
		gotoxy(5, 44);
		printf("○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_a3();
		}
		else if (GetAsyncKeyState(0x58) & 0X8000) {
			return howto_a1();
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}
	}
}
int howto_a3(void)
{
	if (skip == 1) return 0;
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(45, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 6);
		printf("※ 게임의 예시를 보여드리겠습니다.");
		gotoxy(2, 9);
		printf("※ 4 2 0 0 8(처음부터 순서대로 N M x y K)");
		gotoxy(2, 12);
		printf("※ 0 2 3 4 5 6 7 8 -(x, y)좌표가 (0, 0)이므로 0이고 가로 2칸 세로 4칸으로 구성된다.");
		gotoxy(2, 15);
		printf("※ 4 4 4 1 3 3 3 2 -명령의 갯수가 8개이므로 명령수가 8개이고 각각 이동하는 방향이다.");
		gotoxy(2, 18);
		printf("※ 다음은 주사위의 전개도입니다.");
		gotoxy(8, 25);
		printf("주사위의 전개도");
		gotoxy(5, 26);
		printf("       -------");
		gotoxy(5, 27);
		printf("      ㅣ  2  ㅣ");
		gotoxy(5, 28);
		printf(" -------------------");
		gotoxy(5, 29);
		printf("ㅣ 4  ㅣ  1  ㅣ  3 ㅣ");
		gotoxy(5, 30);
		printf(" -------------------");
		gotoxy(5, 31);
		printf("      ㅣ  5  ㅣ");
		gotoxy(5, 32);
		printf("       -------");
		gotoxy(5, 33);
		printf("      ㅣ  6  ㅣ");
		gotoxy(5, 34);
		printf("       -------");


		gotoxy(5, 40);
		printf("○이전 페이지 = x");
		gotoxy(5, 42);
		printf("○메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			howto_a2();
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}
	}
}

int howto_b1(void)
{
	if (skip == 1) return 0;
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(50, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 6);
		printf("※ 2번 주사위 사칙연산 게임의 설명입니다.");
		gotoxy(2, 10);
		printf("※ 플레이어가 순서대로 3개의 주사위를 던집니다.");
		gotoxy(2, 14);
		printf("※ 각각의 주사위에는 1 ~ 6의 숫자, 사칙연산 기호, 1 ~ 6의 숫자가 적혀있습니다.");
		gotoxy(2, 18);
		printf("※ 주사위의 값이 나온 대로 컴퓨터가 사칙연산을 수행합니다.");
		gotoxy(2, 22);
		printf("※ 사칙연산의 결과값이 높은 순서대로 등수가 정해집니다.");
		gotoxy(2, 26);
		printf("※ 만약 사칙연산의 결과값이 같은 플레이어가 생긴다면 플레이 순서대로 등수가 정해집니다.");
		gotoxy(2, 30);
		printf("※ 여기서 정해진 등수대로 다음 게임의 플레이 순서가 정해집니다.");
		gotoxy(2, 34);
		printf("※ 6등 부터 10등 까지는 다음 게임에서 패널티가 생깁니다. 패널티는 메인게임 설명에서 알려드리겠습니다.");


		gotoxy(5, 40);
		printf("○이전 페이지 = x");
		gotoxy(5, 42);
		printf("○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			cursorsupply();
			rule_menu();
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}

	}
}

int howto_c1(void)
{
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(50, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 6);
		printf("※ 3번 주사위 윷놀이 게임의 설명입니다");
		gotoxy(2, 9);
		printf("※ 2번 게임의 등수대로 5명씩 나눠서 플레이 합니다.");
		gotoxy(2, 12);
		printf("※ 각 플레이어들은 맵의 0번에서 시작합니다.");
		gotoxy(2, 15);
		printf("※ 1 부터 5 까지 있는 주사위를 던져 나온 수 만큼 플레이어가 이동합니다.");
		gotoxy(2, 18);
		printf("※ 이동할 수 있는 루트는 4가지가 있는데 화살표가 그려진 부분이 루트입니다.");
		gotoxy(2, 21);
		printf("※ ex) 10지점에 도착하면 13, 16, 19, 25, 30, 35, 40, 도착 지점으로 갈 수 있다");
		gotoxy(2, 24);
		printf("※ 말이 이동을 마치는 칸에 다른 말이 있다면 그 말은 시작 지점으로 되돌아갑니다.");

		gotoxy(105, 1);
		printf("주사위 윷놀이의 게임판 입니다.");
		gotoxy(85, 3);
		printf("┌----------------------------------------------------------------------┐");
		gotoxy(85, 4);
		printf("│ _____                                                                │");
		gotoxy(85, 5);
		printf("│| 0  |                                                                │");
		gotoxy(85, 6);
		printf("│|    |                                                                │");
		gotoxy(85, 7);
		printf("│|____|                                                                │");
		gotoxy(85, 8);
		printf("│ _____                           _____                                │");
		gotoxy(85, 9);
		printf("│| 2  |                          | 도 |                                │");
		gotoxy(85, 10);
		printf("│|    |                          | 착 |                                │");
		gotoxy(85, 11);
		printf("│|____|                          |____|                                │");
		gotoxy(85, 12);
		printf("│ _____                           _____                                │");
		gotoxy(85, 13);
		printf("│| 4  |                          | 40 |                                │");
		gotoxy(85, 14);
		printf("│|    |                          |    |   _____                        │");
		gotoxy(85, 15);
		printf("│|____|                          |____|  | 38 |                        │");
		gotoxy(85, 16);
		printf("│ _____                           _____  |    |  _____                 │");
		gotoxy(85, 17);
		printf("│| 6  |                          | 35 |  |____| | 36 |                 │");
		gotoxy(85, 18);
		printf("│|    |                          |    |         |    |  _____          │");
		gotoxy(85, 19);
		printf("│|____|                          |____|         |____| | 34 |          │");
		gotoxy(85, 20);
		printf("│ _____                           _____                |    |  _____   │");
		gotoxy(85, 21);
		printf("│| 8  |                          | 30 |                |____| | 32 |   │");
		gotoxy(85, 22);
		printf("│|    |                          |    |                       |    |   │");
		gotoxy(85, 23);
		printf("│|____|                          |____|                       |____|   │");
		gotoxy(85, 24);
		printf("│ _____   _____   _____   _____   _____   _____   _____   _____   _____│");
		gotoxy(85, 25);
		printf("│| 10 |  | 13 |  | 16 |  | 19 |  | 25 |  | 26 |  | 27 |  | 28 |  | 30 |│");
		gotoxy(85, 26);
		printf("│|    |  |    |  |    |  |    |  |    |  |    |  |    |  |    |  |    |│");
		gotoxy(85, 27);
		printf("│|_->_|  |____|  |____|  |____|  |_^__|  |____|  |____|  |____|  |_<-_|│");
		gotoxy(85, 28);
		printf("│    _____                        _____                        _____   │");
		gotoxy(85, 29);
		printf("│   | 12 |                       | 23 |                       | 28 |   │");
		gotoxy(85, 30);
		printf("│   |    |  _____                |    |                 _____ |    |   │");
		gotoxy(85, 31);
		printf("│   |____| | 14 |                |____|                | 26 | |____|   │");
		gotoxy(85, 32);
		printf("│          |    |  _____          _____          _____ |    |          │");
		gotoxy(85, 33);
		printf("│          |____| | 16 |         | 21 |         | 24 | |____|          │");
		gotoxy(85, 34);
		printf("│                 |    |  _____  |    |   _____ |    |                 │");
		gotoxy(85, 35);
		printf("│                 |____| | 18 |  |____|  | 22 | |____|                 │");
		gotoxy(85, 36);
		printf("│                        |    |   _____  |    |                        │");
		gotoxy(85, 37);
		printf("│                        |____|  | 20 |  |____|                        │");
		gotoxy(85, 38);
		printf("│                                |    |                                │");
		gotoxy(85, 39);
		printf("│                                |_^__|                                │");
		gotoxy(85, 40);
		printf("└----------------------------------------------------------------------┘");


		gotoxy(5, 40);
		printf("○다음 페이지 = 스페이스바");
		gotoxy(5, 42);
		printf("○메인 메뉴로 돌아가기 = z");
		if (GetAsyncKeyState(VK_SPACE) & 0X8000) {
			howto_c2();
		}
		if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}
	}
}
int howto_c2(void)
{
	if (skip == 1) return 0;
	clear();
	Sleep(300);
	while (1)
	{
		gotoxy(50, 1);
		printf("HOW TO PLAY DICE GAME");
		gotoxy(2, 6);
		printf("※ 게임은 총 10개의 턴으로 이루어집니다.");
		gotoxy(2, 9);
		printf("※ 매 턴마다 주사위를 굴리고, 도착 칸에 있지 않은 말을 하나 골라 주사위에 나온 수만큼 이동시킵니다.");
		gotoxy(2, 12);
		printf("※ 플레이어 한 명이 도착을 하면 그 플레이어는 1등이 되고 점수 60점을 획득합니다.");
		gotoxy(2, 15);
		printf("※ 그 이후로 다른 플레이어들이 도착을 하면 58점, 56점, 2점씩 감소되어 점수를 받습니다.");
		gotoxy(2, 18);
		printf("※ 그리고 만일 두 명의 플레이어만 남았으면 한 명이 도착 지점에 도착하면 게임은 종료됩니다.");
		gotoxy(2, 21);
		printf("※ 만약 주사위 순서가 먼저인 플레이어가 도착을 했을 시 마지막 플레이어는 마지막 주사위를 굴릴 수 있다.");
		gotoxy(2, 24);
		printf("※ 만일 플레이어들이 10턴안에 도착을 못할 시 그 자리에 있는 점수가 자기 자신의 점수입니다.");
		gotoxy(2, 27);
		printf("※ 미니게임의 패널티는 두 번째로 플레이하는 6등에서 10등의 플레이어가 받을 수 있는 최대 점수가 깎이는 것입니다.");
		gotoxy(2, 30);
		printf("※ 첫 번째 플레이 하는 1등에서 5등 플레이어가 골인해서 받은 점수 보다 2점 낮게 최고 점수가 설정 됩니다.");
		gotoxy(2, 33);
		printf("※ 예시로 첫 번째 게임에서 3명의 플레이어가 골인하여 56점을 받았다면, 두 번째 게임할 때는 최고 점수가 54점으로 시작합니다.");

		gotoxy(5, 40);
		printf("○이전 페이지 = x");
		gotoxy(5, 42);
		printf("○메인 메뉴로 돌아가기 = z");

		if (GetAsyncKeyState(0x58) & 0X8000) {
			howto_c1();
		}
		else if (GetAsyncKeyState(0x5A) & 0X8000) {
			start();
		}
	}
}

//메인게임1
void maingame1_rule()
{
	mciSendCommand(menuBgm.wDeviceID, MCI_CLOSE, 0, NULL);
	system("cls");
	maingame1_Bgm();
	printf("1번째 메인게임(주사위 굴리기)을 설명하겠습니다 1번째 메인게임은 어려우니 잘 읽어보시고 숙지를 완벽히 한 다음 게임을 시작하시기 바랍니다.\n\n");
	printf("1. 크기가 NxM인 지도 위에 주사위 하나가 놓여져 있다.\n");
	printf("2. 지도의 오른쪽은 동쪽, 위쪽은 북쪽, 왼쪽은 서쪽, 아래쪽은 남쪽이다.\n");
	printf("3. 지도의 좌표는 (r, c)로 나타내며, r은 북쪽, c는 서쪽으로부터 떨어진 칸의 개수이다.(모든 예시는 이따 나옴)\n");
	printf("4. 주사위는 윗면이 1, 오른쪽면이 3, 왼쪽면이 4, 앞쪽이 5, 뒤쪽이 2, 밑면이 6으로 구성된다.(자리의 번호이다.)\n");
	printf("5. 주사위의 모든 면은 초기에 전부 0으로 주어진다\n");
	printf("6. 지도의 각 칸에는 정수가 하나씩 쓰여져 있다.\n");
	printf("- 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥 면에 있는 수가 칸에 복사된다.\n");
	printf("- 만일 이동한 칸에 쓰여 있는 수가 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, \n");
	printf("칸에 쓰여 있는 수는 0이 된다.\n");
	printf("7. 주사위는 지도의 바깥으로 이동시킬 수 없다.(만일 바깥으로 이동시키려고 하는 경우엔 해당 명령을 무시, 복사X)\n\n");

	printf("지금부터 게임의 본격적인 룰에 대해 설명드리겠습니다.\n\n");
	printf("8. 첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N ≤ 5, 1 ≤ M ≤ 10),\n");
	printf("주사위를 놓은 곳의 좌표 x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 20)가 주어진다.\n");
	printf("9. 둘째 줄부터는 가장 처음에 오는 수가 좌표 (0, 0) 부터 시작하여 동쪽으로는 c좌표가 증가되고, \n");
	printf("북쪽으로는 r좌표가 증가된다(지도의 각 칸에 쓰여 있는 수는 0부터 9까지이다, (x, y)좌표는 무조건 지도의 숫자가 0 이어야 한다)\n");
	printf("10. 마지막 줄에는 이동하는 명령이 순서대로 주어진다.\n");
	printf("- 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 표현이 된다.(M, N, x, y, K , 지도의 값은 랜덤으로 주어짐)\n");
	printf("(예시)\n");
	printf("4 2 0 0 8(처음부터 순서대로 N M x y K)\n");
	printf("0 2\n3 4\n5 6\n7 8                -(x, y)좌표가 (0, 0)이므로 0이고 가로 2칸 세로 4칸으로 구성된다.\n");
	printf("4 4 4 1 3 3 3 2    -명령의 갯수가 8개이므로 명령수가 8개이고 각각 이동하는 방향이다.\n\n");
	printf("다음은 주사위의 전개도입니다.\n");
	printf("       -------\n");
	printf("      ㅣ  2  ㅣ\n");
	printf(" -------------------\n");
	printf("ㅣ 4  ㅣ  1  ㅣ  3 ㅣ\n");
	printf(" -------------------\n");
	printf("      ㅣ  5  ㅣ\n");
	printf("       -------\n");
	printf("      ㅣ  6  ㅣ\n");
	printf("       -------\n\n");

	printf("지금부터 점수 측정 방법에 대해서 알려드리겠습니다\n\n");

	printf("11. 총 10명의 플레이어들이 게임을 합니다\n");
	printf("12. 플레이어들은 나온 정보들로 최종적으로 주사위의 각각의 면에 무슨 숫자가 써져있는지 맞추면 됩니다\n");
	printf("13. 1면씩 맞을 때마다 10점씩 추가되고, 6면이 다 맞으면 보너스로 10점을 더 받아 70점을 가져갑니다.\n");
	printf("14. 제일 먼저 값을 제출한 1등은 20점, 2등은 15점, 3등은 12점, 4등은 10점, 5등부터는 전부 5점을 줍니다.\n");
	printf("(참고로 10명의 플레이어들의 M, N, K 값만 똑같고 나머지 값은 전부 다릅니다.)\n\n");
	printf("게임을 시작하시겠습니까?(아무 문자나 입력하십시오) : ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");
}

void maingame1()
{
	maingame1_rule();
	srand((unsigned int)time(NULL));

	int i;
	int N, M, x, y, K;
	int score[10] = { 0,0,0,0,0,0,0,0,0,0 };
	double duration[10] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	N = rand() % 5 + 1;
	M = rand() % 10 + 1;
	K = rand() % 20 + 1;

	int** p2 = (int**)malloc(sizeof(int*) * M);
	for (int i = 0; i < N; i++) {
		p2[i] = (int*)malloc(sizeof(int) * N);
	}

	for (i = 0; i < 10; i++) {
		printf("player%d님 시작하십시오.(아무 문자나 입력하시오. 입력시에 바로 문제가 나오고 시간초가 지납니다) : ", i);
		temp = getchar();
		while (temp = getchar() != '\n' && temp != EOF);
		x = rand() % N;
		y = rand() % M;

		printf("\n%d %d %d %d %d\n", N, M, x, y, K);

		for (int b = 0; b < N; b++) {
			for (int d = 0; d < M; d++) {
				if (b == x && d == y) {
					p2[b][d] = 0;
				}
				else {
					p2[b][d] = rand() % 10;
				}
				printf("%d ", p2[b][d]);
			}
			printf("\n");
		}

		clock_t start = clock();
		int result = dice_rolling(K, x, y, p2, M, N, i);
		clock_t end = clock();

		duration[i] = (float)(end - start) / CLOCKS_PER_SEC;
		if (result == 6) {
			printf("player%d님은 모든 면을 맞추셨습니다. 점수는 %d점 입니다.\n", i, result * 10 + 10);
			score[i] = result * 10 + 10;
		}
		else {
			printf("player%d님은 총 %d면을 맞추셨습니다. 점수는 %d점 입니다.\n\n", i, result, result * 10);
			score[i] = result * 10;
		}
		printf("player%d님이 걸린 시간은 : %.3lf초 입니다.\n\n", i, duration[i]);
	}

	printf("메인게임 주사위 굴리기가 종료되었습니다. 게임 결과를 확인하려면 아무키나 입력하십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");

	for (i = 0; i < PLAYER; i++) {
		most = player_score_sort(duration, 0, tem_main_score, 1);

		duration[most] = -1.0;         //제일 큰수 두번째 큰수 순서대로 꺼내기 위해서 변수를 초기화 시켜줌

		if (i <= 5) {
			score[most] += 5;
		}
		else if (i == 6) {
			score[most] += 10;
		}
		else if (i == 7) {
			score[most] += 12;
		}
		else if (i == 8) {
			score[most] += 15;
		}
		else if (i == 9) {
			score[most] += 20;
		}
	}



	for (i = 0; i < PLAYER; i++) {
		tem_main_score[i] = score[i];
		totalscore[i] = score[i];
	}

	printf("============랭킹 1위부터 10위까지============\n");
	for (i = 0; i < PLAYER; i++) {
		most = player_score_sort(tem_mini_score, i, score, 2);
		i_tmp = score[i];
		score[i] = score[most];
		score[most] = i_tmp;

		for (int j = 0; j < PLAYER; j++) {
			if (tem_main_score[j] == score[i]) {
				printf("%d등 = player%d의 점수 : %d\n", i + 1, j, score[i]);
				mg_rank[i] = j;
				tem_main_score[j] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
				break;
			}
		}
	}

	printf("\n다음 게임을 진행하려면 아무키나 입력하십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");

	minigame();
}

int dice_rolling(int K, int x, int y, int** p2, int M, int N, int j)
{
	int dice_array[6] = { 0,0,0,0,0,0 };
	int n[6] = { 0,0,0,0,0,0 };
	int way;

	for (int i = 0; i < K; i++) {
		way = rand() % 4 + 1;
		printf("%d ", way);
		switch (way) {
		case 4:
			if (x + 1 == N) {
				x;
				break;
			}
			else {
				n[5] = dice_array[5];
				n[4] = dice_array[4];
				n[0] = dice_array[0];
				n[1] = dice_array[1];
				dice_array[4] = n[0];
				dice_array[5] = n[4];
				dice_array[1] = n[5];
				dice_array[0] = n[1];

				++x;

				if (p2[x][y] != 0) {
					dice_array[5] = p2[x][y];
					p2[x][y] = 0;
				}
				else if (p2[x][y] == 0) {
					p2[x][y] = dice_array[5];
				}
				break;
			}

		case 1:
			if (y + 1 == M) {
				y;
				break;
			}
			else {
				n[5] = dice_array[5];
				n[0] = dice_array[0];
				n[2] = dice_array[2];
				n[3] = dice_array[3];
				dice_array[3] = n[5];
				dice_array[0] = n[3];
				dice_array[2] = n[0];
				dice_array[5] = n[2];

				++y;

				if (p2[x][y] != 0) {
					dice_array[5] = p2[x][y];
					p2[x][y] = 0;
				}
				else if (p2[x][y] == 0) {
					p2[x][y] = dice_array[5];
				}
				break;
			}

		case 3:
			if (x - 1 == -1) {
				x;
				break;
			}
			else {
				n[5] = dice_array[5];
				n[4] = dice_array[4];
				n[0] = dice_array[0];
				n[1] = dice_array[1];
				dice_array[1] = n[0];
				dice_array[5] = n[1];
				dice_array[4] = n[5];
				dice_array[0] = n[4];

				--x;

				if (p2[x][y] != 0) {
					dice_array[5] = p2[x][y];
					p2[x][y] = 0;
				}
				else if (p2[x][y] == 0) {
					p2[x][y] = dice_array[5];
				}
				break;
			}

		case 2:
			if (y - 1 == -1) {
				y;
				break;
			}
			else {
				n[5] = dice_array[5];
				n[0] = dice_array[0];
				n[2] = dice_array[2];
				n[3] = dice_array[3];
				dice_array[0] = n[2];
				dice_array[3] = n[0];
				dice_array[5] = n[3];
				dice_array[2] = n[5];

				--y;

				if (p2[x][y] != 0) {
					dice_array[5] = p2[x][y];
					p2[x][y] = 0;
				}
				else if (p2[x][y] == 0) {
					p2[x][y] = dice_array[5];
				}
				break;
			}
		}
	}

	int result = 0;
	printf("\n\nplayer%d님 1번면부터 6번면까지 차례대로 입력하시오 \n", j);

	while (1) {
		printf("1번(윗면) 2번(뒷면) 3번(오른쪽면) 4번(왼쪽면) 5번(앞면) 6번(밑면) : ");
		int num = scanf_s("%d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5]);
		while (temp = getchar() != '\n' && temp != EOF);
		if (num == 6) {
			break;
		}
		printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
	}

	if (n[0] == dice_array[0]) {
		result++;
	}
	if (n[1] == dice_array[1]) {
		result++;
	}
	if (n[2] == dice_array[2]) {
		result++;
	}
	if (n[3] == dice_array[3]) {
		result++;
	}
	if (n[4] == dice_array[4]) {
		result++;
	}
	if (n[5] == dice_array[5]) {
		result++;
	}
	printf("\n");
	return result;
}

//미니게임
void minigame()
{
	mciSendCommand(main1Bgm.wDeviceID, MCI_CLOSE, 0, NULL);
	minigame_Bgm();
	srand((unsigned int)time(NULL));
	int dice1, dice3;
	char dice2[4] = { '+', '-', '*', '/' };
	int i;
	int c = rand() % 4;
	double score[PLAYER] = { 0.0, };

	printf("====================주사위 사칙연산 게임====================\n");

	for (i = 0; i < 10; i++) {
		printf("player %d\n", i);

		printf("숫자 주사위를 던지세요(press Enter)");
		temp = getchar();
		while (temp = getchar() != '\n' && c != EOF);
		WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
		playingShuffleSound();
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".\n");
		Sleep(500);
		dice1 = rand() % 6 + 1;
		printf("첫 번째 숫자 주사위값 : %d\n\n", dice1);


		printf("연산기호 주사위를 던지세요(press Enter)");
		temp = getchar();
		while (temp = getchar() != '\n' && c != EOF);
		WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
		playingShuffleSound();
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".\n");
		Sleep(500);
		c = rand() % 4;
		printf("두 번째 연산기호 주사위값 : %c\n\n", dice2[c]);


		printf("숫자 주사위를 던지세요(press Enter)");
		temp = getchar();
		while (temp = getchar() != '\n' && c != EOF);
		WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
		playingShuffleSound();
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".\n");
		Sleep(500);
		dice3 = rand() % 6 + 1;
		printf("세 번째 숫자 주사위값 : %d\n\n", dice3);

		if (c == 0)
		{
			d_tmp = (double)dice1 + dice3;
			score[i] = d_tmp;
			printf("결과값은 %lf 입니다.\n\n", d_tmp);
		}

		else if (c == 1) {
			d_tmp = (double)dice1 - dice3;
			score[i] = d_tmp;
			printf("결과값은 %lf 입니다.\n\n", d_tmp);
		}

		else if (c == 2) {
			d_tmp = (double)dice1 * dice3;
			score[i] = d_tmp;
			printf("결과값은 %lf 입니다.\n\n", d_tmp);
		}

		else if (c == 3) {
			d_tmp = (double)dice1 / dice3;
			score[i] = d_tmp;
			printf("결과값은 %lf 입니다.\n\n", d_tmp);
		}

		printf("계속 하려면 아무키나 누르십시오.");
		temp = getchar();
		while (temp = getchar() != '\n' && c != EOF);
		system("cls");
	}

	printf("게임이 끝났습니다!!!\n");
	printf("이번 게임의 랭킹을 토대로 다음 게임의 순서가 정해집니다\n");
	printf("미니게임 결과를 확인하려면 아무키나 입력하십시오");
	temp = getchar();
	while (temp = getchar() != '\n' && c != EOF);
	system("cls");


	for (i = 0; i < PLAYER; i++) {
		tem_mini_score[i] = score[i];
	}

	printf("========랭킹 1위부터 10위까지========\n");
	for (i = 0; i < PLAYER; i++) {
		most = player_score_sort(score, i, tem_main_score, 1);
		d_tmp = score[i];
		score[i] = score[most];
		score[most] = d_tmp;

		for (int j = 0; j < PLAYER; j++) {
			if (tem_mini_score[j] == score[i]) {
				printf("%d등 = player%d의 점수 : %lf\n", i + 1, j, score[i]);
				mg_rank[i] = j;
				tem_mini_score[j] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
				break;
			}
		}
	}
	for (i = 0; i < PLAYER; i++) {
		switch (mg_rank[i])
		{
		case 0:
			sequence[i] = '0';
			break;
		case 1:
			sequence[i] = '1';
			break;
		case 2:
			sequence[i] = '2';
			break;
		case 3:
			sequence[i] = '3';
			break;
		case 4:
			sequence[i] = '4';
			break;
		case 5:
			sequence[i] = '5';
			break;
		case 6:
			sequence[i] = '6';
			break;
		case 7:
			sequence[i] = '7';
			break;
		case 8:
			sequence[i] = '8';
			break;
		default:
			sequence[i] = '9';
			break;
		}
	}

	printf("다음 게임을 시작하려면 아무키나 입력하십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && c != EOF);
	system("cls");
	mciSendCommand(miniBgm.wDeviceID, MCI_CLOSE, 0, NULL);
	maingame2_Bgm();

	for (int y = 0; y < 2; y++) {
		maingame2(y);
	}
}

//메인게임2
void maingame2(int hello)  //배열을 증가시키는 변수 int hello
{
	maingame2_rule();

	srand((unsigned int)time(NULL));
	int dice = 0;
	int i;

	if (hello == 0) {
		map[3][4] = sequence[0];
		map[3][6] = sequence[1];
		map[3][8] = sequence[2];
		map[3][10] = sequence[3];
		map[3][12] = sequence[4];
	}
	else if (hello == 1) {
		map[3][4] = sequence[5];
		map[3][6] = sequence[6];
		map[3][8] = sequence[7];
		map[3][10] = sequence[8];
		map[3][12] = sequence[9];
	}

	map_print(hello);
	printf("1턴을 시작합니다.\n\n");

	for (i = 1; i <= 10; i++) {
		if (player[hello * 5] <= 40) {
			player[hello * 5] = player1_dice(dice, hello);
			system("cls");
		}
		if (player[hello * 5 + 1] <= 40) {
			system("cls");
			map_print(hello);
			player[hello * 5 + 1] = player2_dice(dice, hello);
			system("cls");
		}
		if (player[hello * 5 + 2] <= 40) {
			system("cls");
			map_print(hello);
			player[hello * 5 + 2] = player3_dice(dice, hello);
			system("cls");
		}
		if (player[hello * 5 + 3] <= 40) {
			system("cls");
			map_print(hello);
			player[hello * 5 + 3] = player4_dice(dice, hello);
			system("cls");
		}
		if (player[hello * 5 + 4] <= 40) {
			system("cls");
			map_print(hello);
			player[hello * 5 + 4] = player5_dice(dice, hello);
			system("cls");
		}

		int he1 = (player[hello * 5] > 40);
		int he2 = (player[hello * 5 + 1] > 40);
		int he3 = (player[hello * 5 + 2] > 40);
		int he4 = (player[hello * 5 + 3] > 40);
		int he5 = (player[hello * 5 + 4] > 40);
		int he_sum = he1 + he2 + he3 + he4 + he5;

		if ((he1 + he2 + he3 + he4 + he5) == 4 && i != 10) {
			printf("1명을 제외하고 4명의 player가 %d턴만에 도착지점에 도착하였습니다. 게임을 일찍 종료합니다\n\n", i);
			break;
		} // 플레이어 1명을 제외하고 4명의 플레이어가 10턴전에 도착할 시
		else if ((he1 + he2 + he3 + he4 + he5) == 5) {
			printf("모든 player가 %d턴만에 도착지점에 도착하였습니다. 게임을 일찍 종료합니다\n\n", i);
			break;
		} // 플레이어들 전부 10턴 전에 도착할시

		if (i < 9) {
			map_print(hello);
			printf("%d턴이 끝났습니다 %d턴을 시작합니다.\n\n", i, i + 1);
		}
		else if (i == 9) {
			map_print(hello);
			printf("%d턴이 끝났습니다 마지막 턴인 %d턴을 시작합니다.\n\n", i, i + 1);
		}
		else if (i == 10) {
			printf("마지막턴이 끝났습니다. 게임을 종료합니다.\n\n");
			if (he_sum > 0) {
				printf("%d명을 제외하고 %d명의 player가 도착지점에 도착하였습니다.\n\n", 5 - he_sum, he_sum);
			}
			else {
				printf("아무도 도착지점에 도착하지 못하였습니다.\n\\n");
			}
		}
	}

	printf("%d번째 메인게임2(주사위 윷놀이)의 게임 결과를 발표하겠습니다.\n", hello + 1);
	printf("player%c님 : %d점\n", sequence[hello * 5], player[hello * 5]);
	printf("player%c님 : %d점\n", sequence[hello * 5 + 1], player[hello * 5 + 1]);
	printf("player%c님 : %d점\n", sequence[hello * 5 + 2], player[hello * 5 + 2]);
	printf("player%c님 : %d점\n", sequence[hello * 5 + 3], player[hello * 5 + 3]);
	printf("player%c님 : %d점\n", sequence[hello * 5 + 4], player[hello * 5 + 4]);

	printf("\n다음 게임을 위해 아무키나 입력하십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");

	if (hello == 1) {                   //plaer배열의 플레이어 순서가 뒤죽박죽이므로 플레이어 0번부터 차례대로 넣어줌
		for (i = 0; i < PLAYER; i++) {
			a[mg_rank[i]] = player[i];
		}

		printf("==========메인게임2(주사위 윷놀이)의 전체 게임 랭킹==========\n");
		for (i = 0; i < PLAYER; i++) {
			tem_main_score[i] = a[i];
			totalscore[i] += a[i];
		}

		for (i = 0; i < PLAYER; i++) {
			most = player_score_sort(tem_mini_score, i, a, 2);
			i_tmp = a[i];
			a[i] = a[most];
			a[most] = i_tmp;

			for (int j = 0; j < PLAYER; j++) {
				if (tem_main_score[j] == a[i]) {
					printf("%d등 = player%d의 점수 : %d\n", i + 1, j, a[i]);
					mg_rank[i] = j;
					tem_main_score[j] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
					break;
				}
			}
		}
		printf("\n모든 게임이 종료되었습니다!! 최종 결과를 확인하려면 아무키나 입력하십시오.");
		temp = getchar();
		while (temp = getchar() != '\n' && temp != EOF);
		system("cls");
		mciSendCommand(main2Bgm.wDeviceID, MCI_CLOSE, 0, NULL);

		Total_score_ranking();
	}

	for (i = 0; i < 5; i++) {      //다음 게임을 위해 이전게임에서 도착하지 못한 말들을 공백으로 초기화 시켜준다
		map[o[i]][p[i]] = ' ';
	}
}

void maingame2_rule()
{
	printf("2번째 메인게임(주사위 윷놀이)을 설명하겠습니다\n\n");
	printf("1. 주사위 윳놀이는 총 2번의 게임이 진행됩니다.\n");
	printf("2. 미니게임(주사위 연산)에서 이긴 등수대로 게임을 진행합니다.\n");
	printf("3. 미니게임에서 1등부터 5등까지는 첫 번째 게임, 6등부터 10등까지는 두 번째 게임에 참여하게 됩니다.\n");
	printf("4. 말은 전부 0(시작)부터 시작합니다. 첫 번째 플레이어부터 1부터 5까지 있는 5면체의 주사위를 굴립니다.\n");
	printf("5. 만약 주사위가 5가 나오면 5칸을 이동하여 10에 도착을 합니다.\n");
	printf("(이 주사위 윳놀이에서는 총 4가지의 루트가 있습니다.\n");
	printf("1번째 루트는 10지점에 도착하면 13, 16, 19, 25, 30, 35, 40, 도착 지점으로 갈 수 있는 루트와\n");
	printf("2번째 루트는 20지점에 도착하면 22, 24, 25, 30, 35, 40, 도착 지점으로 갈 수 있는 루트와\n");
	printf("3번째 루트는 30지점에 도착하면 28, 27, 26, 25, 30, 35, 40, 도착 지점으로 갈 수 있는 루트와 기본루트가 있습니다)\n");
	printf("6. 말이 이동을 마치는 칸에 다른 말이 있을 시 그 칸에 원래 있었던 말은 다시 시작 지점으로 되돌아 갑니다.\n");
	printf("(자기가 있는 위치에 있는 숫자가 상대방이 있는 위치에 숫자랑 겹쳐도 있는 위치가 다르면 괜찮습니다.)\n");
	printf("7. 게임은 총 10개의 턴으로 이루어집니다. 매 턴마다 주사위를 굴리고, 도착 칸에 있지 않은 말을 하나 골라 주사위에\n");
	printf("나온 수만큼 이동시킵니다.\n");
	printf("8. 플레이어 한 명이 도착을 하면 그 플레이어는 1등이 되고 점수 60점을 획득합니다.\n");
	printf("그 이후로 다른 플레이어들이 도착을 하면 58점, 56점, 2점씩 감소되어 점수를 받습니다.\n");
	printf("그리고 만일 두 명의 플레이어만 남아있을 때 한 명이 도착 지점에 도착하면 게임은 종료됩니다.\n");
	printf("(만약 주사위 순서가 먼저인 플레이어가 도착을 했을 시 마지막 플레이어는 마지막 주사위를 굴릴 수 있다.)\n");
	printf("9. 만일 플레이어들이 10턴안에 도착을 못할 시 그 자리에 있는 점수가 자기 자신의 점수입니다.\n\n");

	printf("게임을 시작하시겠습니까?(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);
	system("cls");
}

int player_location(int dice, char playernumber, int delivery, int mynumber, int p1, int p2, int p3, int p4, int p5,
	int an, int hello)
{
	if (playernumber == sequence[hello * 5]) {
		map[o[an]][p[an]] = ' ';
	}
	else if (playernumber == sequence[hello * 5 + 1]) {
		map[o[an]][p[an]] = ' ';
	}
	else if (playernumber == sequence[hello * 5 + 2]) {
		map[o[an]][p[an]] = ' ';
	}
	else if (playernumber == sequence[hello * 5 + 3]) {
		map[o[an]][p[an]] = ' ';
	}
	else if (playernumber == sequence[hello * 5 + 4]) {
		map[o[an]][p[an]] = ' ';
	}


	if (delivery == 5 || (delivery == 5 + dice && mynumber == route1[5]) || (delivery == 6 + dice && mynumber == route1[6]) ||
		(delivery == 7 + dice && mynumber == route1[7]) || (delivery == 8 + dice && mynumber == route1[8]) ||
		(delivery == 9 + dice && mynumber == route1[9]) || (delivery == 10 + dice && mynumber == route1[10]) ||
		(delivery == 11 + dice && mynumber == route1[11]) || (delivery == 12 + dice && mynumber == route1[12])) {

		if (delivery > 12) {
			map_print(hello);
			printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
			printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", playernumber, playernumber);
			mynumber = score--;
			--score;

			return mynumber;
		}

		mynumber = route1[delivery];

		if (delivery == 5) {
			map[23][6] = playernumber;
			o[an] = 23;
			p[an] = 6;
		}
		else if (delivery == 6) {
			map[23][14] = playernumber;
			o[an] = 23;
			p[an] = 14;
		}
		else if (delivery == 7) {
			map[23][22] = playernumber;
			o[an] = 23;
			p[an] = 22;
		}
		else if (delivery == 8) {
			map[23][30] = playernumber;
			o[an] = 23;
			p[an] = 30;
		}
		else if (delivery == 9) {
			map[23][38] = playernumber;
			o[an] = 23;
			p[an] = 38;
		}
		else if (delivery == 10) {
			map[19][38] = playernumber;
			o[an] = 19;
			p[an] = 38;
		}
		else if (delivery == 11) {
			map[15][38] = playernumber;
			o[an] = 15;
			p[an] = 38;
		}
		else if (delivery == 12) {
			map[11][38] = playernumber;
			o[an] = 11;
			p[an] = 38;
		}

		catch_player(playernumber, delivery, mynumber, sequence[hello * 5], sequence[hello * 5 + 1], sequence[hello * 5 + 2]
			, sequence[hello * 5 + 3], sequence[hello * 5 + 4], p1, p2, p3, p4, p5, hello);

		if (delivery == 5) {
			printf("route1에 진입합니다.\n");
		}
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
		printf("player%c님의 위치는 route1의 %d 입니다.\n\n", playernumber, mynumber);
		return mynumber;
	}

	else if (delivery == 10 || (delivery == 10 + dice && mynumber == route2[10]) || (delivery == 11 + dice && mynumber == route2[11]) ||
		(delivery == 12 + dice && mynumber == route2[12]) || (delivery == 13 + dice && mynumber == route2[13]) ||
		(delivery == 14 + dice && mynumber == route2[14]) || (delivery == 15 + dice && mynumber == route2[15]) ||
		(delivery == 16 + dice && mynumber == route2[16])) {

		if (delivery > 16) {
			map_print(hello);
			printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
			printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", playernumber, playernumber);
			mynumber = score--;
			--score;

			return mynumber;
		}

		mynumber = route2[delivery];

		if (delivery == 10) {
			map[35][38] = playernumber;
			o[an] = 35;
			p[an] = 38;
		}
		else if (delivery > 10 && delivery < 17) {
			map[(o[an] - (dice * 4))][38] = playernumber;
			o[an] -= (dice * 4);
			p[an] = 38;
		}

		catch_player(playernumber, delivery, mynumber, sequence[hello * 5], sequence[hello * 5 + 1], sequence[hello * 5 + 2]
			, sequence[hello * 5 + 3], sequence[hello * 5 + 4], p1, p2, p3, p4, p5, hello);

		if (delivery == 10) {
			printf("route2에 진입합니다.\n");
		}
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
		printf("player%c님의 위치는 route2의 %d 입니다.\n\n", playernumber, mynumber);
		return mynumber;
	}

	else if (delivery == 15 || (delivery == 15 + dice && mynumber == route3[15]) || (delivery == 16 + dice && mynumber == route3[16]) ||
		(delivery == 17 + dice && mynumber == route3[17]) || (delivery == 18 + dice && mynumber == route3[18]) ||
		(delivery == 19 + dice && mynumber == route3[19]) || (delivery == 20 + dice && mynumber == route3[20]) ||
		(delivery == 21 + dice && mynumber == route3[21]) || (delivery == 22 + dice && mynumber == route3[22])) {

		if (delivery > 22) {
			map_print(hello);
			printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
			printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", playernumber, playernumber);
			mynumber = score--;
			--score;

			return mynumber;
		}

		mynumber = route3[delivery];

		if (delivery == 15) {
			map[23][70] = playernumber;
			o[an] = 23;
			p[an] = 70;
		}
		else if (delivery == 16) {
			map[23][62] = playernumber;
			o[an] = 23;
			p[an] = 62;
		}
		else if (delivery == 17) {
			map[23][54] = playernumber;
			o[an] = 23;
			p[an] = 54;
		}
		else if (delivery == 18) {
			map[23][46] = playernumber;
			o[an] = 23;
			p[an] = 46;
		}
		else if (delivery == 19) {
			map[23][38] = playernumber;
			o[an] = 23;
			p[an] = 38;
		}
		else if (delivery == 20) {
			map[19][38] = playernumber;
			o[an] = 19;
			p[an] = 38;
		}
		else if (delivery == 21) {
			map[15][38] = playernumber;
			o[an] = 15;
			p[an] = 38;
		}
		else if (delivery == 22) {
			map[11][38] = playernumber;
			o[an] = 11;
			p[an] = 38;
		}

		catch_player(playernumber, delivery, mynumber, sequence[hello * 5], sequence[hello * 5 + 1], sequence[hello * 5 + 2]
			, sequence[hello * 5 + 3], sequence[hello * 5 + 4], p1, p2, p3, p4, p5, hello);

		if (delivery == 15) {
			printf("route3에 진입합니다.\n");
		}
		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
		printf("player%c님의 위치는 route3의 %d 입니다.\n\n", playernumber, mynumber);
		return mynumber;
	}

	else {
		if (delivery > 20) {
			map_print(hello);
			printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
			printf("player%c님이 도착하셨습니다! player%c님은 게임에서 제외됩니다.\n\n", playernumber, playernumber);
			mynumber = score--;
			--score;
			return mynumber;
		}

		mynumber = base_route[delivery];

		if (delivery == 1) {
			map[7][6] = playernumber;
			o[an] = 7;
			p[an] = 6;
		}
		else if (delivery == 2) {
			map[11][6] = playernumber;
			o[an] = 11;
			p[an] = 6;
		}
		else if (delivery == 3) {
			map[15][6] = playernumber;
			o[an] = 15;
			p[an] = 6;
		}
		else if (delivery == 4) {
			map[19][6] = playernumber;
			o[an] = 19;
			p[an] = 6;
		}
		else if (delivery == 6) {
			map[27][9] = playernumber;
			o[an] = 27;
			p[an] = 9;
		}
		else if (delivery == 7) {
			map[29][16] = playernumber;
			o[an] = 29;
			p[an] = 16;
		}
		else if (delivery == 8) {
			map[31][23] = playernumber;
			o[an] = 31;
			p[an] = 23;
		}
		else if (delivery == 9) {
			map[33][30] = playernumber;
			o[an] = 33;
			p[an] = 30;
		}
		else if (delivery == 11) {
			map[33][46] = playernumber;
			o[an] = 33;
			p[an] = 46;
		}
		else if (delivery == 12) {
			map[31][53] = playernumber;
			o[an] = 31;
			p[an] = 53;
		}
		else if (delivery == 13) {
			map[29][60] = playernumber;
			o[an] = 29;
			p[an] = 60;
		}
		else if (delivery == 14) {
			map[27][67] = playernumber;
			o[an] = 27;
			p[an] = 67;
		}
		else if (delivery == 16) {
			map[19][67] = playernumber;
			o[an] = 19;
			p[an] = 67;
		}
		else if (delivery == 17) {
			map[17][60] = playernumber;
			o[an] = 17;
			p[an] = 60;
		}
		else if (delivery == 18) {
			map[15][53] = playernumber;
			o[an] = 15;
			p[an] = 53;
		}
		else if (delivery == 19) {
			map[13][46] = playernumber;
			o[an] = 13;
			p[an] = 46;
		}
		else if (delivery == 20) {
			map[11][38] = playernumber;
			o[an] = 11;
			p[an] = 38;
		}

		catch_player(playernumber, delivery, mynumber, sequence[hello * 5], sequence[hello * 5 + 1], sequence[hello * 5 + 2]
			, sequence[hello * 5 + 3], sequence[hello * 5 + 4], p1, p2, p3, p4, p5, hello);

		printf("나온 숫자는 %d 입니다 %d 만큼 이동합니다.\n", dice, dice);
		printf("player%c님의 위치는 base_route의 %d 입니다.\n\n", playernumber, mynumber);
		return mynumber;
	}
}

void catch_player(char mynumber, int b, int mylocation, char n1, char n2, char n3, char n4, char n5,
	int p1, int p2, int p3, int p4, int p5, int hello)
{
	if (((b == a[hello * 5] && mylocation == p1) || (25 == mylocation && 25 == p1) ||
		((b == 10 || b == 14 || b == 19) && (a[hello * 5] == 10 || a[hello * 5] == 14 || a[hello * 5] == 19) &&
			(30 == mylocation && 30 == p1)) || (35 == mylocation && 35 == p1) || (40 == mylocation && 40 == p1)) &&
		(mynumber != sequence[hello * 5])) {
		player[hello * 5] = 0;
		a[hello * 5] = 0;
		o[hello * 5] = 3;
		p[hello * 5] = 4;
		map[3][4] = sequence[hello * 5];
		map_print(hello);
		printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", mynumber, n1, n1);
	}
	else if (((b == a[hello * 5 + 1] && mylocation == p2) || (25 == mylocation && 25 == p2) ||
		((b == 10 || b == 14 || b == 19) && (a[hello * 5 + 1] == 10 || a[hello * 5 + 1] == 14 || a[hello * 5 + 1] == 19) &&
			(30 == mylocation && 30 == p2)) || (35 == mylocation && 35 == p2) || (40 == mylocation && 40 == p2)) &&
		(mynumber != sequence[hello * 5 + 1])) {
		player[hello * 5 + 1] = 0;
		a[hello * 5 + 1] = 0;
		o[hello * 5 + 1] = 3;
		p[hello * 5 + 1] = 6;
		map[3][6] = sequence[hello * 5 + 1];
		map_print(hello);
		printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", mynumber, n2, n2);
	}
	else if (((b == a[hello * 5 + 2] && mylocation == p3) || (25 == mylocation && 25 == p3) ||
		((b == 10 || b == 14 || b == 19) && (a[hello * 5 + 2] == 10 || a[hello * 5 + 2] == 14 || a[hello * 5 + 2] == 19) &&
			(30 == mylocation && 30 == p3)) || (35 == mylocation && 35 == p3) || (40 == mylocation && 40 == p3)) &&
		(mynumber != sequence[hello * 5 + 2])) {
		player[hello * 5 + 2] = 0;
		a[hello * 5 + 2] = 0;
		o[hello * 5 + 2] = 3;
		p[hello * 5 + 2] = 8;
		map[3][8] = sequence[hello * 5 + 2];
		map_print(hello);
		printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", mynumber, n3, n3);
	}
	else if (((b == a[hello * 5 + 3] && mylocation == p4) || (25 == mylocation && 25 == p4) ||
		((b == 10 || b == 14 || b == 19) && (a[hello * 5 + 3] == 10 || a[hello * 5 + 3] == 14 || a[hello * 5 + 3] == 19) &&
			(30 == mylocation && 30 == p4)) || (35 == mylocation && 35 == p4) || (40 == mylocation && 40 == p4)) &&
		(mynumber != sequence[hello * 5 + 3])) {
		player[hello * 5 + 3] = 0;
		a[hello * 5 + 3] = 0;
		o[hello * 5 + 3] = 3;
		p[hello * 5 + 3] = 10;
		map[3][10] = sequence[hello * 5 + 3];
		map_print(hello);
		printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", mynumber, n4, n4);
	}
	else if (((b == a[hello * 5 + 4] && mylocation == p5) || (25 == mylocation && 25 == p5) ||
		((b == 10 || b == 14 || b == 19) && (a[hello * 5 + 4] == 10 || a[hello * 5 + 4] == 14 || a[hello * 5 + 4] == 19) &&
			(30 == mylocation && 30 == p5)) || (35 == mylocation && 35 == p5) || (40 == mylocation && 40 == p5)) &&
		(mynumber != sequence[hello * 5 + 4])) {
		player[hello * 5 + 4] = 0;
		a[hello * 5 + 4] = 0;
		o[hello * 5 + 4] = 3;
		p[hello * 5 + 4] = 12;
		map[3][12] = sequence[hello * 5 + 4];
		map_print(hello);
		printf("player%c님이 player%c님의 말을 잡았습니다. player%c님은 시작지점으로 되돌아갑니다.\n", mynumber, n5, n5);
	}
	else {
		map_print(hello);
	}
}

int player1_dice(int dice, int hello)
{
	RED; printf("player%c님 ", sequence[hello * 5]);
	WHITE; printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드
	//whlie문을 실행했을 때 일단 버퍼에 있는 것을 c로 받고 버퍼에 \n(개행)이 들어있거나 또는 EOF로 끝인지를 체크하여
	//끝을 만날 때까지 반복문으로 버퍼를 비웁니다

	WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
	playingShuffleSound();
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("cls");
	dice = rand() % 5 + 1;
	a[hello * 5] += dice;

	int result = player_location(dice, sequence[hello * 5], a[hello * 5], player[hello * 5], player[hello * 5],
		player[hello * 5 + 1], player[hello * 5 + 2], player[hello * 5 + 3], player[hello * 5 + 4], hello * 5, hello);
	printf("다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드
	return result;
}

int player2_dice(int dice, int hello)
{
	VIOLET; printf("player%c님 ", sequence[hello * 5 + 1]);
	WHITE; printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
	playingShuffleSound();
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("cls");
	dice = rand() % 5 + 1;
	a[hello * 5 + 1] += dice;
	int result = player_location(dice, sequence[hello * 5 + 1], a[hello * 5 + 1], player[hello * 5 + 1],
		player[hello * 5], player[hello * 5 + 1], player[hello * 5 + 2], player[hello * 5 + 3], player[hello * 5 + 4], hello * 5 + 1, hello);
	printf("다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드
	return result;
}
int player3_dice(int dice, int hello)
{
	YELLOW; printf("player%c님 ", sequence[hello * 5 + 2]);
	WHITE; printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
	playingShuffleSound();
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("cls");
	dice = rand() % 5 + 1;
	a[hello * 5 + 2] += dice;
	int result = player_location(dice, sequence[hello * 5 + 2], a[hello * 5 + 2], player[hello * 5 + 2],
		player[hello * 5], player[hello * 5 + 1], player[hello * 5 + 2], player[hello * 5 + 3], player[hello * 5 + 4], hello * 5 + 2, hello);
	printf("다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	return result;
}
int player4_dice(int dice, int hello)
{
	GREEN; printf("player%c님 ", sequence[hello * 5 + 3]);
	WHITE; printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
	playingShuffleSound();
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("cls");
	dice = rand() % 5 + 1;
	a[hello * 5 + 3] += dice;
	int result = player_location(dice, sequence[hello * 5 + 3], a[hello * 5 + 3], player[hello * 5 + 3],
		player[hello * 5], player[hello * 5 + 1], player[hello * 5 + 2], player[hello * 5 + 3], player[hello * 5 + 4], hello * 5 + 3, hello);
	printf("다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	return result;
}
int player5_dice(int dice, int hello)
{
	BLUE; printf("player%c님 ", sequence[hello * 5 + 4]);
	WHITE; printf("주사위를 굴리십시오(아무 문자를 입력하세요): ");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	WHITE; printf("주사위가 몇이 나오는지 계산중입니다");
	playingShuffleSound();
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("cls");
	dice = rand() % 5 + 1;
	a[hello * 5 + 4] += dice;
	int result = player_location(dice, sequence[hello * 5 + 4], a[hello * 5 + 4], player[hello * 5 + 4],
		player[hello * 5], player[hello * 5 + 1], player[hello * 5 + 2], player[hello * 5 + 3], player[hello * 5 + 4], hello * 5 + 4, hello);
	printf("다음 플레이어의 시작을 위해 아무 문자를 입력 해주십시오.");
	temp = getchar();
	while (temp = getchar() != '\n' && temp != EOF);   //버퍼를 비우는 코드

	return result;
}

void map_print(int hello)
{
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 78; j++) {
			if ((map[i][j] == sequence[hello * 5] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[hello * 5] && map[i - 1][j + 1] == '(')) {
				RED; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[hello * 5 + 1] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[hello * 5 + 1] && map[i - 1][j - 1] == '(')) {
				VIOLET; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[hello * 5 + 2] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[hello * 5 + 2] && map[i - 1][j - 3] == '(')) {
				YELLOW; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[hello * 5 + 3] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[hello * 5 + 3] && map[i - 1][j - 5] == '(')) {
				GREEN; printf("%c", map[i][j]);
			}
			else if ((map[i][j] == sequence[hello * 5 + 4] && map[i - 1][j + 1] == ' ') ||
				(map[i][j] == sequence[hello * 5 + 4] && map[i - 1][j - 7] == '(')) {
				BLUE; printf("%c", map[i][j]);
			}
			else {
				WHITE; printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
}

//선택정렬
int player_score_sort(double data[], int start, int data2[], int one_or_two)
{
	int i, most;
	most = start;
	if (one_or_two == 1) {
		for (i = start + 1; i < PLAYER; i++) {
			if (data[i] > data[most]) {
				most = i;
			}
		}
	}
	else if (one_or_two == 2) {
		for (i = start + 1; i < PLAYER; i++) {
			if (data2[i] > data2[most]) {
				most = i;
			}
		}
	}

	return most;
}

//종합랭킹
void Total_score_ranking()
{
	printf("===============종합 게임 랭킹===============\n");
	for (int i = 0; i < PLAYER; i++) {
		tem_main_score[i] = totalscore[i];
	}

	for (int i = 0; i < PLAYER; i++) {
		most = player_score_sort(tem_mini_score, i, totalscore, 2);
		i_tmp = totalscore[i];
		totalscore[i] = totalscore[most];
		totalscore[most] = i_tmp;

		for (int j = 0; j < PLAYER; j++) {
			if (tem_main_score[j] == totalscore[i]) {
				printf("%d등 = player%d의 점수 : %d\n\n", i + 1, j, totalscore[i]);
				mg_rank[i] = j;
				tem_main_score[j] = -100;  //겹치는 부분이 있으면 안되므로 아무 변수나 넣어줌
				break;
			}
		}
	}
}

//배경음악
void mainmenuBgm() {
	menuBgm.lpstrElementName = bgm0; //파일 오픈
	menuBgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&menuBgm);
	dwID = menuBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&menuBgm); //음악 반복 재생
}
void maingame1_Bgm() {
	main1Bgm.lpstrElementName = bgm1; //파일 오픈
	main1Bgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&main1Bgm);
	dwID = main1Bgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&main1Bgm); //음악 반복 재생
}
void minigame_Bgm() {
	miniBgm.lpstrElementName = bgm2; //파일 오픈
	miniBgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&miniBgm);
	dwID = miniBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&miniBgm); //음악 반복 재생
}
void maingame2_Bgm() {
	main2Bgm.lpstrElementName = bgm3; //파일 오픈
	main2Bgm.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&main2Bgm);
	dwID = main2Bgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&main2Bgm); //음악 반복 재생
}
void playingShuffleSound() {
	openShuffleSound.lpstrElementName = shuffle; //파일 오픈
	openShuffleSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //음악을 한 번 재생
	Sleep(500);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}