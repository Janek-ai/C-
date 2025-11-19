#include <iostream>
using namespace std;
int main()
{
	int ingredient = 0;

	cout << "Podaj numer skladnika (0: 3 zl / iiny: 5 zl)";
	cin >> ingredient;

	int price = ingredient == 0 ? 3 : 5;
	cout << "Koszt skladnika: " << price <<" zl"<< endl;
}