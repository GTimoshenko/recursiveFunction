#include <iostream>
using namespace std;
/*
*/
int recursiveFuncComp(int y, int x) {
	if (y == 0) {
		cout << endl;
		cout << "f(0," << x << ") = g(" << x << ") = 0" << endl;
		return 0;
	}
	int currStep = recursiveFuncComp(y - 1, x);
	int nextStep = (y*(y-1)/2) + y * x;
	cout << "f(" << y << "," << x << ") = h("
		 << y - 1 << ",f(" << y - 1 << "," << x
		 << ")," << x  << ") " << "= h(" << y - 1 << "," << currStep << ","
		 << x << ") = " << nextStep << endl; 
		return nextStep;
}

void showProblemScheme() {
	setlocale(LC_ALL, "Russian");
	cout << "Схема рекурсии по заданным функциям:" << endl << endl
		 << "{ f(0,x) = g(x) = 0" << endl
		 << "{ h(y,f(y,x),x) = f(y+1,x) = y + f(y,x) + x" << endl << endl;
}

void compStep() {
	setlocale(LC_ALL, "Russian");
	int stopFlag = 1, x, y;
	while (stopFlag == 1) {
		cout << endl;
		cout << "Введите необходимые для обрабоки значения X и Y:" << endl;
		cin >> x >> y;
		int recursiveFuncStep = recursiveFuncComp(x, y);
		cout << endl;
		cout << "Введите" << endl
			 << "1 - Чтобы вычислить рекурсивную функцию для вновь введенных значений." << endl
			 << "2 - Чтобы выйти из программы." << endl;
		cin  >> stopFlag;
		if (stopFlag == 2) {
			cout << endl << "Программа завершила работу." << endl;
			break;
		}
		if (stopFlag != 2 && stopFlag != 1) {
			cout << endl << "Такой комманды не существует. Программа завершила работу." << endl;
			break;
		}
	}
}

int main() {
	showProblemScheme();
	compStep();
	return 0;
}