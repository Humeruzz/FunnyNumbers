#include <iostream>
#include <Windows.h>

void Matrix();
void Labrinth();

using namespace std;
CONSOLE_FONT_INFOEX font;
int main()
{
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 0;
	font.dwFontSize.Y = 16;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	wcscpy_s(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);
	system("color A");
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD NewSBSize;
	int Status;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	NewSBSize.X = SBInfo.dwSize.X;
	NewSBSize.Y = SBInfo.dwSize.Y;// -8971;
	Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
	if (Status == 0)
	{
		Status = GetLastError();
		cout << "SetConsoleScreenBufferSize() failed! Reason : " << Status << endl;
		exit(Status);
	}
	//GetConsoleScreenBufferInfo(hOut, &SBInfo);
	//cout << "Screen Buffer Size : ";
	//cout << SBInfo.dwSize.X << " x ";
	//cout << SBInfo.dwSize.Y << endl;
	//return 0;
	//Matrix();
	Labrinth();
}

void Labrinth() {
	static int ran = 5, ran1 = 5;
	static int cup = 200;
	int mass[200];
	int mass1[200];
	bool start = true;
	bool line = false;
	if (start) {
		for (int i = 0; i < cup; i++) {
			if ((i >= 1) && (i < cup)) {
				mass[i] = (rand() % 2);
			}
			else
			{
				mass[i] = 1;
			}
			if (mass[i] == 1) {
				cout << mass[i];
			}
			else
			{
				cout << " ";
			}
			if (i == cup - 1) {
				cout << endl;
			}
		}
		start = false;
		//Sleep(5000);
	}
	for (int j = 0; j < 1000; j++) {
		if (line) {
			for (int i = 0; i < cup; i++) {
				if ((i >= 1) && (i < cup - 1)) {
					if ((mass[i - 1] == 1) || (mass1[i] == 1) || ((i + 1) == cup - 1) || ((i - 1) == 0))
					{
						if ((rand() % ran == 1) || (rand() % ran == 1)||(rand() % ran1 == 1) || (rand() % ran1 == 1)) {
							mass[i] = 1;
						}
						else {
							mass[i] = 0;
						}
					}
					else {
						mass[i] = 0;
					}
				}
				else {
					mass[i] = 1;
				}				
			}
			for (int i = cup - 1; i >= 0; i--) {
				if ((i >= 1) && (i < cup - 1)) {
					if (mass[i + 1] == 1)
					{
						if (mass[i] == 1) {
							mass[i] = 1;
						}
						else if ((rand() % ran == 1) || (rand() % ran == 1) || (rand() % ran1 == 1) || (rand() % ran1 == 1))
						{
							mass[i] = 1;
						}
						else {
							mass[i] = 0;
						}
					}
					else if (mass[i] == 1) {
						mass[i] = 1;
					}
					else {
						mass[i] = 0;
					}
				}
				else {
					mass[i] = 1;
				}
			}
			for (int i = 0; i < cup; i++) {
				if (mass[i] == 1) {
					cout << mass[i];
				}
				else
				{
					cout << " ";
				}
				if (i == cup - 1) {
					cout << endl;
				}
				
			}
			Sleep(150);
			line = false;
		}
		else {
			for (int i = 0; i < cup; i++) {
				if ((i >= 1) && (i < cup - 1)) {
					if ((mass1[i - 1] == 1) || (mass[i] == 1) || ((i + 1) == cup - 1) || ((i - 1) == 0))
					{
						if ((rand() % ran == 1) || (rand() % ran == 1) || (rand() % ran1 == 1) || (rand() % ran1 == 1)) {
							mass1[i] = 1;
						}
						else {
							mass1[i] = 0;
						}
					}
					else
					{
						mass1[i] = 0;
					}
				}
				else {
					mass1[i] = 1;
				}
			}
			for (int i = cup - 1; i >= 0; i--) {
				if ((i > 0) && (i < cup - 1)) {
					if (mass1[i + 1] == 1)
					{
						if (mass1[i] == 1) {
							mass1[i] = 1;
						}
						else if ((rand() % ran == 1) || (rand() % ran == 1) || (rand() % ran1 == 1) || (rand() % ran1 == 1)) {
							mass1[i] = 1;
						}
						else {
							mass1[i] = 0;
						}
					}
					else if (mass1[i] == 1) {
						mass1[i] = 1;
					}
					else {
						mass1[i] = 0;
					}
				}
				else {
					mass1[i] = 1;
				}
			}
			for (int i = 0; i < cup; i++) {
				if (mass1[i] == 1) {
					cout << mass1[i];
				}
				else
				{
					cout << " ";
				}
				if (i == cup - 1) {
					cout << endl;
				}
				
			}
			Sleep(150);
			line = true;
		}
	}
}
	



	void Matrix(){
	for (int j = 0; j < 10000; j++) {
		int mass[211];
		for (int i = 0; i < 211; i++) {
			if (((rand() % 3) != 0) && ((rand() % 2) != 0) && ((rand() % 2) != 0)) {
				mass[i] = (rand() % 2);
				//Sleep(0.5);
				cout << mass[i];
			}
			else
			{
				//Sleep(0.5);
				cout << " ";
			}

		}
		Sleep(5);
	}
}
