




#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define HUMAN_BOTTOM_Y 12
#define STOP_BOTTOM_Y 20
#define STOP_BOTTOM_X 45

//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title jump game. By Minseok.");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//ĳ���͸� �׸��� �Լ�
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

//��ֹ��� �׸��� �Լ�
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
		//aŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
		if (GetKeyDown() == 'a' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		//�������̶�� Y�� ����, ������ �������� Y�� ����.
		if (isJumping)
		{
			humanY -= gravity;
		}
		else
		{
			humanY += gravity;
		}

		//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
		if (humanY >= HUMAN_BOTTOM_Y)
		{
			humanY = HUMAN_BOTTOM_Y;
			isBottom = true;
		}

		//��ֹ��� �������� �������ϰ�
		//��ֹ��� ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
		stopX -= 2;
		if (stopX <= 0)
		{
			stopX = STOP_BOTTOM_X;
		}

		//������ ������ ������ ������ ���� ��Ȳ.
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
