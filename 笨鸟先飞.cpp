#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<string>
#include<ctime>
using namespace std;
int speed = 0;
int speed1 = 0;
const int x = 100;
const int y = 20;
const int up = 0;
const int down = 18;
int count1 = 0;
class bird
{
public:
	bird(int x, int y)
	{
		birdx = x;
		birdy = y;
	}
	int birdx;
	int birdy;
};

class pillar
{
public:
	pillar(int x1, int y1)
	{
		if (y1 == 0)
		{
			y1 = rand() % (y / 2);
		}
		pillarx = x1;
		pillary = y1;
	}
	int pillarx;
	int pillary;
};

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);

}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void show(bird &birds,pillar &pillar1, pillar &pillar2, pillar &pillar3, pillar &pillar4, pillar& pillar5)
{
	gotoxy(0, 0);
	HideCursor();
	for (int i = 1; i < y; ++i)
	{
		for (int j = 1; j < x; ++j)
		{
			if(j == birds.birdx && i == birds.birdy)
			{
				cout <<"\b"<<"鸟";
			}
			else if (j == pillar1.pillarx && (i >= 1 && i <= pillar1.pillary) || j == pillar1.pillarx && (i >= pillar1.pillary + 5 && i <= y))
			{
				cout << "*";
			}
			else if (j == pillar2.pillarx && (i >= 1 && i <= pillar2.pillary) || j == pillar2.pillarx && (i >= pillar2.pillary + 5 && i <= y))
			{
				cout << "*";
			}
			else if (j == pillar3.pillarx && (i >= 1 && i <= pillar3.pillary) || j == pillar3.pillarx && (i >= pillar3.pillary + 5 && i <= y))
			{
				cout << "*";
			}
			else if (j == pillar4.pillarx && (i >= 1 && i <= pillar4.pillary) || j == pillar4.pillarx && (i >= pillar4.pillary + 5 && i <= y))
			{
				cout << "*";
			}
			else if (j == pillar5.pillarx && (i >= 1 && i <= pillar5.pillary) || j == pillar5.pillarx && (i >= pillar5.pillary + 5 && i <= y))
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
  }
	
}

void birdmove(bird &birds)
{
	if (kbhit())
	{
		string move;
		move = getch();
		if (move == " ")
		{
			if (birds.birdy >= 2)
			{
				birds.birdy -= 2;
			}
		}
	}
}

void move(bird& birds, pillar& pillar1, pillar& pillar2, pillar& pillar3, pillar& pillar4, pillar& pillar5)
{
	if (birds.birdx == pillar1.pillarx && (birds.birdy > pillar1.pillary && birds.birdy < pillar1.pillary + 5))
	{
		count1++;
	}
	else if (birds.birdx == pillar2.pillarx && (birds.birdy > pillar2.pillary && birds.birdy < pillar2.pillary + 5))
	{
		count1++;
	}
	else if (birds.birdx == pillar3.pillarx && (birds.birdy > pillar3.pillary && birds.birdy < pillar3.pillary + 5))
	{
		count1++;
	}
	else if (birds.birdx == pillar4.pillarx && (birds.birdy > pillar4.pillary && birds.birdy < pillar4.pillary + 5))
	{
		count1++;
	}
	if (birds.birdx == pillar5.pillarx && (birds.birdy > pillar5.pillary && birds.birdy < pillar5.pillary + 5))
	{
		count1++;
	}
	if (speed != 3)
	{
		speed++;
	}
	if (birds.birdy !=y && speed==3)
	{
		speed = 0;
		birds.birdy += 1;
	}
	if (speed1 != 5)
	{
		speed1++;
	}
	else if (speed1 == 5)
	{
		if (pillar1.pillarx > 0)
		{
			pillar1.pillarx--;
		}
		if (pillar2.pillarx > 0)
		{
			pillar2.pillarx--;
		}
		if (pillar3.pillarx > 0)
		{
			pillar3.pillarx--;
		}
		if (pillar4.pillarx > 0)
		{
			pillar4.pillarx--;
		}
		if (pillar5.pillarx > 0)
		{
			pillar5.pillarx--;
		}
		if (pillar1.pillarx == 0)
		{
			pillar1.pillarx = pillar5.pillarx + 10;
			pillar1.pillary = rand() % (y / 2);
			while (pillar1.pillary == 0)
			{
				pillar1.pillary = rand() % (y / 2);
			}
		}
		if (pillar2.pillarx == 0)
		{
			pillar2.pillarx = pillar1.pillarx + 10;
			pillar2.pillary = rand() % (y / 2);
			while (pillar2.pillary == 0)
			{
				pillar2.pillary = rand() % (y / 2);
			}
		}
		if (pillar3.pillarx == 0)
		{
			pillar3.pillarx = pillar2.pillarx + 10;
			pillar3.pillary = rand() % (y / 2);
			while (pillar3.pillary == 0)
			{
				pillar3.pillary = rand() % (y / 2);
			}
		}
		if (pillar4.pillarx == 0)
		{
			pillar4.pillarx = pillar3.pillarx + 10;
			pillar4.pillary = rand() % (y / 2);
			while (pillar4.pillary == 0)
			{
				pillar4.pillary = rand() % (y / 2);
			}
		}
		if (pillar5.pillarx == 0)
		{
			pillar5.pillarx = pillar4.pillarx + 10;
			pillar5.pillary = rand() % (y / 2);
			while (pillar5.pillary == 0)
			{
				pillar5.pillary = rand() % (y / 2);
			}
		}
		speed1 = 0;
	}
}
	
void startshow()
{
	cout << "********笨鸟先飞**********" << endl;
	cout << "1.开始游戏" << endl;
	cout << "2.退出" << endl;
}

void  program()
{
	srand(time(0));
	bird birds(x / 20, y / 2);
	pillar pillar1(x / 5, rand() % (y / 2));
	pillar pillar2(x / 5 + 10, rand() % (y / 2));
	pillar pillar3(x / 5 + 20, rand() % (y / 2));
	pillar pillar4(x / 5 + 30, rand() % (y / 2));
	pillar pillar5(x / 5 + 40, rand() % (y / 2));
	while (1)
	{
		show(birds, pillar1, pillar2, pillar3, pillar4, pillar5);
		move(birds, pillar1, pillar2, pillar3, pillar4, pillar5);
		birdmove(birds);
		if (birds.birdx == pillar1.pillarx && ((birds.birdy >= 1 && birds.birdy <= pillar1.pillary) || (birds.birdy >= pillar1.pillary + 5 && birds.birdy <= 20)))
		{
			cout << "得分：" << count1 << endl;
            cout << "game over！" << endl;
			break;
		}
		else if (birds.birdx == pillar2.pillarx && ((birds.birdy >= 1 && birds.birdy <= pillar2.pillary) || (birds.birdy >= pillar2.pillary + 5 && birds.birdy <= 20)))
		{
			cout << "得分：" << count1 << endl;
            cout << "game over!" << endl;
			break;
		}
		else if (birds.birdx == pillar3.pillarx && ((birds.birdy >= 1 && birds.birdy <= pillar3.pillary) || (birds.birdy >= pillar3.pillary + 5 && birds.birdy <= 20)))
		{
			cout << "得分：" << count1 << endl;
            cout << "game over!" << endl;
			break;
		}
		else if (birds.birdx == pillar4.pillarx && ((birds.birdy >= 1 && birds.birdy <= pillar4.pillary) || (birds.birdy >= pillar4.pillary + 5 && birds.birdy <= 20)))
		{
			cout << "得分：" << count1 << endl;
            cout << "game over!" << endl;
			break;
		}
		else if (birds.birdx == pillar5.pillarx && ((birds.birdy >= 1 && birds.birdy <= pillar5.pillary) || (birds.birdy >= pillar5.pillary + 5 && birds.birdy <= 20)))
		{
			cout << "得分：" << count1 << endl;
            cout << "game over!" << endl;
			break;
		}
        cout << "得分：" << count1 << endl;
	}
} 

int main()
{
	startshow();
	int choose; 
	cin >> choose;
	switch (choose)
	{
	case 1:
		program();
		break;
	case 2:
		return 0;
	}
    system("pause");
	return 0;
}