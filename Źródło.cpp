#include<iostream>
using namespace std;



float dod(float a, float b)
{
    float wynik = 0;
    wynik = a + b;
    return wynik;
}



float odej(float a, float b)
{
    float wynik = 0;
    wynik = a - b;
    return wynik;
}



float mno(float a, float b)
{
    float wynik = 0;
    wynik = a * b;
    return wynik;
}



float dziel(float a, float b)
{
    float wynik = 0;
    wynik = a / b;
    return wynik;



}




int main()
{
    int wybor = 1;
    while (wybor >= 1)
    {
        cout << "Jakie dzia³anie chcesz wykonac? \n 1. Dodawanie \n 2. Odejmowanie \n 3. Mno¿enie \n 4. Dzielenie \n 0. Koniec pracy\n";
        cin >> wybor;
        float a = 0, b = 0;
        switch (wybor)
        {
        case 1:
            cout << "Podaj a: ";
            cin >> a;
            cout << "Podaj b: ";
            cin >> b;
            cout << "Wynikiem dzia³ania jest: " << dod(a, b) << endl;
            break;
        case 2:
            cout << "Podaj a: ";
            cin >> a;
            cout << "Podaj b: ";
            cin >> b;
            cout << "Wynikiem dzia³ania jest: " << odej(a, b) << endl;
            break;
        case 3:
            cout << "Podaj a: ";
            cin >> a;
            cout << "Podaj b: ";
            cin >> b;
            cout << "Wynikiem dzia³ania jest: " << mno(a, b) << endl;
            break;
        case 4:
            cout << "Podaj a: ";
            cin >> a;
            cout << "Podaj b: ";
            cin >> b;
            if (b == 0)
            {
                cout << "nie mo¿na dzieliæ przez 0 baranie";
            }
            else
            {
                cout << "Wynikiem dzia³ania jest: " << dziel(a, b) << endl;
            }
            break;
        default: cout << "Podaj poprawna opcja" << endl;
            break;
        }
    }



}