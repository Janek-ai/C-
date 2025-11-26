/*Treść
Aplikacja naśladująca listę kontaktów w telefonie. Program ma działać w nieskończonej pętli,
dopóki użytkownik nie wpisze z klawiatury, że chce wyjść z programu.
1. Należy stworzyć strukturę danych, która będzie przechowywać informacje
wprowadzone przez użytkownika: numer telefonu, nazwisko oraz liczbę połączeń
2. Należy stworzyć funkcję wypisz, która wypisze całą książkę telefoniczną wraz z
liczbą połączeń
3. Należy stworzyć funkcję szukaj, która sprawdzi czy dany numer telefonu jest już w
książce (i wypisze go)
4. Należy stworzyć funkcję dodaj, która dodaje numer telefonu do książki (wraz z
nazwiskiem) i ustawi liczbę połączeń z tym numerem na zero. Oczywiście najpierw
sprawdziwszy, czy taki numer już nie jest dodany
5. Należy stworzyć funkcję usuń, która usunie kontakt wg podanego numeru telefonu.
6. Należy stworzyć funkcję połącz, która zapyta o numer telefonu, a następnie zwiększy
liczbę połączeń z tym numerem o 1.
Przykład:
Co chcesz zrobić? 1 - szukaj numeru, 2 - dodaj numer, 3 - usuń numer, 4 - połącz z
numerem, 5 - wypisz numery, 0 - wyjdź
> 1
Podaj numer do wyszukania:
> 444
Znaleziono: 444, Jan Kowalski, polaczenia: 4
Co chcesz zrobić?...
// Kroki:
1. Tworzymy nieskończoną pętlę dopóki użytwkonik nie wpisze z menu wyboru cyfry 0.
2. Tworzymy strukturę danych
3. Tworzymy funckję wypisującą
4. Tworzymy funkcję która szuka
5. Tworzymy funkcję która dodaje
6. Tworzymy funkcję kasującą
7. Funkcja połącz 
*/

#include <iostream>

using namespace std;
string nazwa[100];
string numer[100];
int polaczenia[100];
int n = 0;
void wypisywanie()
{
	/*//void to funkcja bez zwracania
	//N - liczba kontaktów
	Po dodaniu kontaktu N+1
	Po usunięciu kontaktów liczba N-liczba usunięych kontaków
	*/
	for (int i = 0; i < n; i++)
	{
		cout << nazwa[i] /*Tu wpisujemy nasz iterator*/ << endl;
		cout << numer[i] /*Tu wpisujemy nasz iterator*/ << endl;
		cout << polaczenia[i] /*Tu wpisujemy nasz iterator*/ << endl;
	}
}

void dodawanie()
{
	/*Przed odaniem numeru telefonu tworzymy mechanizm sprawdzający czy już nasz numer jest w bazie*/
	cout << "Proszę podać numer telefonu \n";
	string telefon;
	cin >> telefon;
	for (int i = 0; i < n; i++)
	{
		if (telefon == numer[i])
		{
			cout << "Taki numer już istnieje \n";
			return;
		}
	}
	cout << "Wprowadź nazwę użytownika\n";
	cin >> nazwa[n];
	numer[n] = telefon;
	cout << "O to przez Ciebie wprowadzony numer telefonu " << numer[n] << endl;
	polaczenia[n] = 0;
	n = n + 1;
}

void kasowanie()
{
	/*
	Funkcja kasująca
	1. Najpierw trzeba wskazać kontakt
	Kontakt musi byc wskazany za pomoca numeru telefonu

	*/
	if (n <= 0)
	{
		std::cout << "Brak kontaktów.\n";
		return;
	}
	wypisywanie();
	cout << "Wprowadz numer telefonu ktory chcesz usunac\n";
	string tel;
	cin >> tel;
	bool znaleziono = false;
	for (int i = 0; i < n; ++i)
	{
		if (!znaleziono && numer[i]==tel)
		{
			std::cout << "Usunięto kontakt.\n";
			cout << nazwa[i]  << endl;
			cout << numer[i] << endl;
			cout << polaczenia[i] << endl;
			--n;
			znaleziono = true;
		}
		if (znaleziono)
		{
			nazwa[i] = nazwa[i + 1];
			numer[i] = numer[i + 1];
			polaczenia[i] = polaczenia[i + 1];
		}
	}
	if (!znaleziono)
		std::cout << "Nie ma takiego numeru.\n";


}
void polaczenie()
{
	string tel;
	cout << "Wprowadz numer telefonu\n";
	cin >> tel;
	for (int i = 0; i < n; i++)
	{
		if (tel == numer[i])
		{
			polaczenia[i]++;
			return;
		}
	}

}


void search()
{
	string tel;
	cout << "Wprowadz numer telefonu\n";
	cin >> tel;
	for (int i = 0; i < n; i++)
	{
		if (tel == numer[i])
		{
			cout << nazwa[i] << endl;
			cout << numer[i] << endl;
			cout <<polaczenia[i] << endl;
			return;
		}
	}
	cout << "Nie ma takiego kontaktu w bazie \n";
}

int main()
{
	int wybor = 1;
	while (wybor != 0)
	{
		cout << "Co chcesz zrobić?...\n";
		cout << "1 - szukaj numeru\n";
		cout << "2 - dodaj numer\n";
		cout << "3 - usuń numer\n";
		cout << "4 - połącz z numerem\n";
		cout << "5 - wypisz numery\n";
		cout << "0 - wyjdź\n";
		cin >> wybor;
		switch (wybor)
		{
		case 0:
			cout << "Do widzenia \n";
			break;
		case 1:
			search();
			break;
		case 2:
			//2 - dodaj numer
			dodawanie();
			break;
		case 3:
			kasowanie();
			break;
		case 4:
			//4 - połącz z numerem
			polaczenie();
			break;
		case 5:
			//5 - wypisz numery
			wypisywanie();
			break;
		default:
			cout << "Nie ma takiej opcji\n";
		}
	}
	system("pause");
}
