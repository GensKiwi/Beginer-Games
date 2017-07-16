#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;


char playground[50][10];
int PlayerPosX, PlayerPosY;
bool LoseCause = true;
class Limits {
public:
	void LeftDesign(){
		for (int i = 0; i < 10; i++) {
			playground[49][i] = '|';
		}
	}
	void RightDesign(){
		for (int i = 0; i < 10; i++) {
			playground[0][i] = '|';
		}
	}
	void TopDesign(){
		for (int i = 0; i < 50; i++) {
			playground[i][0] = '-';
		}
	}
	void BottomDesign(){
		for (int i = 0; i < 50; i++) {
			playground[i][9] = '-';
		}
	}
};

void lostGame() { system("cls"); cout << "You have lost the game!" << endl; LoseCause = false; }

class Movements {
public:

	void up() {
		if (PlayerPosY -1 == 0)
			lostGame();
		else
		{
			playground[PlayerPosX][PlayerPosY] = 'o';
			PlayerPosY--;
			playground[PlayerPosX][PlayerPosY] = 'O';
		}
	}

	void down() {
		if (PlayerPosY +1 == 9)
			lostGame();
		else
		{
			playground[PlayerPosX][PlayerPosY] = 'o';
			PlayerPosY++;
			playground[PlayerPosX][PlayerPosY] = 'O';
		}
	}

	void left() {
		if (PlayerPosX -1 == 0)
			lostGame();
		else
		{
			playground[PlayerPosX][PlayerPosY] = 'o';
			PlayerPosX--;
			playground[PlayerPosX][PlayerPosY] = 'O';
		}
	}

	void right() {
		if (PlayerPosX + 1 == 0)
			lostGame();
		else
		{
			playground[PlayerPosX][PlayerPosY] = 'o';
			PlayerPosX++;
			playground[PlayerPosX][PlayerPosY] = 'O';
		}
	}
};


void StartGame();
void AssignLimitDesign();
void SetStartupSpace();
void Move();
void BoardManager();

void main(){
	srand(time(0));
	StartGame();
	system("pause");
}

void StartGame() {
	AssignLimitDesign();
	SetStartupSpace();
	do {
		Move();
		BoardManager();
	} while (LoseCause != false);
	
}

void AssignLimitDesign() {
	Limits Lim;
	Lim.LeftDesign();
	Lim.RightDesign();
	Lim.TopDesign();
	Lim.BottomDesign();
}

void SetStartupSpace() {
	playground[1][1] = 'O'; // playground[PlayerPosX][PlayerPosY] = 'O';
	PlayerPosX = 1;
	PlayerPosY = 1;
}

void Move() {
	Movements Move;
	char c = getch();
	switch (c) {
	case 'w': { Move.up(); break; }
	case 's': { Move.down(); break; }
	case 'a': { Move.left(); break; }
	case 'd': { Move.right(); break; }
	}
}

void BoardManager() {
	if(LoseCause != false)
		system("cls");
	for (int i = 0 ; i < 10; i++){
		for (int j = 0; j < 50; j++) {
			cout << playground[j][i];
		}
		cout << endl;
	}
}
