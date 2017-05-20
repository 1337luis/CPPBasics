#include <iostream>
#include <Windows.h>
#include <cstdlib>

using	namespace std;

void	refresh();
void	display();
void	clear();
void	setup();

int		pad[16][16] = { 0 };

int main() {
	setup();

	while (true) {
		refresh();
		display();
		Sleep(500);
		clear();
	}
	
}
void refresh() {

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			int neighbors = pad[x-1][y-1] + pad[x][y-1] + pad[x+1][y-1] + pad[x-1][y] + pad[x+1][y] + pad[x-1][y+1] + pad[x][y+1] + pad[x+1][y+1];

			if (pad[x][y] == 1) {
				if (neighbors <= 1) {
					//MUERE DE SOLEDAD
					pad[x][y] = 0;
				}
				else if (neighbors >= 4) {
					//MUERE DE SOBREPOBLACIÓN
					pad[x][y] = 0;
				}
				else if (neighbors == 2 || neighbors == 3) {
					//SOBREVIVE
					pad[x][y] = 1;
				}
			}
			else {
				if (neighbors == 3) {
					//VUELVE A LA VIDA
					pad[x][y] = 1;
				}
			}

		}
	}

}
void display() {

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			if (pad[x][y] == 1) {
				cout << (char)254u << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}

}

//STACKOVERFLOW METHOD TO CLEAR SCREEN WITHOUT CLS
void clear() {
	system("cls");
}
void setup() {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			int r = rand() % 100;
			if (r < 49) {
				pad[x][y] = 1;
			}
			else {
				pad[x][y] = 0;
			}
		}
	}
}
