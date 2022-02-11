#include <iostream>

using namespace std;

// klasa kondensatora
class Kondensator
{
public:
	// konstruktor bez parametrów
	Kondensator()
	{
		pojemnosc(0.0);
	}

	// konstruktor z parametrem
	Kondensator(double pojemnosc)
	{
		this->pojemnosc(pojemnosc);
	}

	// zwraca pojemność
	double pojemnosc() const
	{
		return _pojemnosc;
	}

	// pozwala ustawić pojemność
	void pojemnosc(double pojemnosc)
	{
		_pojemnosc = pojemnosc;
	}

	// zaprzyjaźnione operatory
	friend Kondensator operator+(const Kondensator& k1, const Kondensator& k2);
	friend Kondensator operator*(const Kondensator& k1, const Kondensator& k2);
	friend ostream& operator<<(ostream& out, const Kondensator& k);
private:
	// pojemność kondensatora
	double _pojemnosc;
};

// operator zwracający kondensator w wyniku połączenia k1 z k2 szeregowo
Kondensator operator+(const Kondensator& k1, const Kondensator& k2)
{
	return Kondensator((k1._pojemnosc * k2._pojemnosc) / (k1._pojemnosc + k2._pojemnosc));
}

// operator zwracający kondensator w wyniku połączenia k1 z k2 równolegle
Kondensator operator*(const Kondensator& k1, const Kondensator& k2)
{
	return Kondensator(k1._pojemnosc + k2._pojemnosc);
}

// operator wypisania
ostream& operator<<(ostream& out, const Kondensator& k)
{
	return out << k._pojemnosc << "F";
}

// start programu
int main(int argc, char** argv)
{
	// utworzenie 4 przykładowych kondesatorów
	Kondensator k1(10);
	Kondensator k2(10);
	Kondensator k3 = k1 + k2;
	Kondensator k4 = k1 * k2;

	// wypisanie wyników
	cout << "k1 = " << k1 << endl;
	cout << "k2 = " << k2 << endl;
	cout << "k3 = " << k3 << endl;
	cout << "k4 = " << k4 << endl;

	return 0;
}
