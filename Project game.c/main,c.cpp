




#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define HUMAN_BOTTOM_Y 12
#define STOP_BOTTOM_Y 20
#define STOP_BOTTOM_X 45

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google jump game. By Minseok.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//캐릭터를 그리는 함수
void DrawHuman(int humanY)
{
	GotoXY(0, humanY);
	static bool legFlag = true;
	printf("   $$$$$$$$$$$$$      \n");
	printf("   $   #   #   $      \n");
	printf("   $     @     $     \n");
	printf("   $$$$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$$$$$$          \n");
	printf("  $  $$$$$$$$$  $      \n");
	printf("  $  $$$$$$$$$  $       \n");
	printf("  $  $$$$$$$$$  $      \n");
	printf("     $$$$$$$$$        \n");
	printf("     $$$$$$$$$        \n");
	printf("     $$$$$$$$$       \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

//장애물을 그리는 함수
void DrawStop(int stopX)
{
	GotoXY(stopX, STOP_BOTTOM_Y);
	printf(" $$ ");
	GotoXY(stopX, STOP_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(stopX, STOP_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(stopX, STOP_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(stopX, STOP_BOTTOM_Y + 4);
	printf(" $$ ");
}

int main()
{
	SetConsoleView();

	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int humanY = HUMAN_BOTTOM_Y;
	int stopX = STOP_BOTTOM_X;

	while (true)
	{
		//a키가 눌렸고, 바닥이 아닐때 점프
		if (GetKeyDown() == 'a' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
		if (isJumping)
		{
			humanY -= gravity;
		}
		else
		{
			humanY += gravity;
		}

		//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
		if (humanY >= HUMAN_BOTTOM_Y)
		{
			humanY = HUMAN_BOTTOM_Y;
			isBottom = true;
		}

		//장애물이 왼쪽으로 가도록하고
		//장애물의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
		stopX -= 2;
		if (stopX <= 0)
		{
			stopX = STOP_BOTTOM_X;
		}

		//점프의 맨위를 찍으면 점프가 끝난 상황.
		if (humanY <= 3)
		{
			isJumping = false;
		}

		DrawHuman(humanY);		//draw human
		DrawStop(stopX);		//draw stop
		Sleep(60);
		system("cls");	//clear
	}
	return 0;
}
