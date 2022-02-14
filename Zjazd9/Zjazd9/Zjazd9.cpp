// Zjazd9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iterator>
#include <list>


using namespace std;

int main(int argc, char** argv)
{
    list<int> lista;
    int n;

    cout << "Podaj n:";
    cin >> n;

    if (n <= 0)
    {
        cout << "Niepoprawne n";
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        int liczba;

        cout << "Podaj liczbe: ";
        cin >> liczba;

        if (liczba >= 0)
        {
            lista.push_back(liczba);
        }
        else
        {
            lista.push_front(liczba);
        }
    }

    list<int>::iterator it = lista.begin();
    for (int i = 0; i < n; i++)
    {
        cout << "lista[" << i << "] = " << *it << endl;
        it++;
    }

       

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
