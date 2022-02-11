#include <iostream>
#include <string>

using namespace std;

// funkcja konwertująca linię tekstu na liczbę
int Konwertuj(const string& linia)
{
	// sprawdzenie czy są same cyfry
	for (char c : linia)
	{
		if (!isdigit(c))
		{
			throw exception("Wprowadzony ciag zawiera nieprawidlowe znaki");
		}
	}

	// próba konwersji
	try
	{
		return stoi(linia);
	}
	// ten wyjątek się pojawi jeżeli liczba nie mieści się w zakresie int
	catch (out_of_range&)
	{
		// wyrzucenie własnego wyjątku
		throw exception("Wprowadzona liczba jest za duża lub za mala");
	}
}

// start programu
int main(int argc, char** argv)
{
	string linia;

	// wczytanie linii z konsoli
	cout << "Podaj ciag znakow: ";
	getline(cin, linia);

	// próba konwersji
	try
	{
		cout << "Ciag znakow jako liczba = " << Konwertuj(linia) << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
