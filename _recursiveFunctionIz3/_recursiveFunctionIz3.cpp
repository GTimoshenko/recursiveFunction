#include <iostream>
using namespace std;
/*������� recursiveFuncComp �������� �� ����:
* int y - �������� ������������� �������� Y
* int x - �������� ������������� �������� �
* ������������ ���������� �������� � � �, ������������ ����������� �������.
* ���������� 0 � ������, ���� �� ����� �� ������ ��������, � ������ �� ������ - nextStep(��������� ��������� ���).
*/
int recursiveFuncComp(int y, int x) {
	int currStep, nextStep;
	if (y == 0) {
		cout << endl;
		cout << "f(0," << x << ") = g(" << x << ") = 0" << endl;
		return 0;
	}
	currStep = recursiveFuncComp(y - 1, x);
	nextStep = (y*(y-1)/2) + y * x;
	cout << "f(" << y << "," << x << ") = h("
		 << y - 1 << ",f(" << y - 1 << "," << x
		 << ")," << x  << ") " << "= h(" << y - 1 << "," << currStep << ","
		 << x << ") = " << nextStep << endl; 
		return nextStep;
}
/*������� showProblemScheme ������ �� �������� �� ����, �� ����������.
* ������� ����� ��������.
*/
void showProblemScheme() {
	cout << "����� �������� �� �������� ��������:" << endl << endl
		 << "{ f(0,x) = g(x) = 0" << endl
		 << "{ h(y,f(y,x),x) = f(y+1,x) = y + f(y,x) + x" << endl << endl;
}
/*������� compStep ������ �� �������� �� ����, �� ����������.
* ��������� �� ������� � � �, �������� �� ������� recursiveFuncStep.
* ����� ��������� ���������� ������ ����� ������ ��� ����� �� ���������, ��������� ����� ������������.
*/
void compStep() {
	int stopFlag = 1, x, y;
	while (stopFlag == 1) {
		cout << endl;
		cout << "������� ����������� ��� �������� �������� X � Y:" << endl;
		cin >> x >> y;
		int recursiveFuncStep = recursiveFuncComp(x, y);
		cout << endl;
		cout << "�������" << endl
			 << "1 - ����� ��������� ����������� ������� ��� ����� ��������� ��������." << endl
			 << "2 - ����� ����� �� ���������." << endl;
		cin  >> stopFlag;
		if (stopFlag == 2) {
			cout << endl << "��������� ��������� ������." << endl;
			break;
		}
		if (stopFlag != 2 && stopFlag != 1) {
			cout << endl << "����� �������� �� ����������. ��������� ��������� ������." << endl;
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	showProblemScheme();
	compStep();
	return 0;
}