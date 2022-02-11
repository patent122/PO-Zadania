#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

class Bryla
{
public:
	virtual double Pole() const = 0;
	virtual double Objetosc() const = 0;
	
	virtual double Przekatna()
	{
		return 0.0;
	};
};

class Kula : public Bryla
{
public:
	Kula(double r)
	{
		this->r = r;
	}

	virtual double Pole() const
	{
		return 4.0 * M_PI * r * r;
	}

	virtual double Objetosc() const
	{
		return 4.0 / 3.0 * M_PI * r * r * r;
	}
protected:
	double r;
};

class Prostopadloscian : public Bryla
{
public:
	Prostopadloscian(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	virtual double Pole() const
	{
		return 2.0 * a * b + 2.0 * a * c + 2.0 * b * b;
	}

	virtual double Objetosc() const
	{
		return a * b * c;
	}

	virtual double Przekatna() const
	{
		return sqrt(a * a + b * b + c * c);
	}
protected:
	double a;
	double b;
	double c;
};

class Ostroslup : public Bryla
{
public:
	Ostroslup(double a, double b, double h)
	{
		this->a = a;
		this->b = b;
		this->h = h;
	}

	virtual double Pole() const
	{
		return a * b + 2.0 * h;
	}

	virtual double Objetosc() const
	{
		return 1.0 / 3.0 * a * b * h;
	}
protected:
	double a;
	double b;
	double h;
};


int main(int argc, char** argv)
{
	Kula kula(5);
	Prostopadloscian prostopadloscian(10, 5, 2);
	Ostroslup ostroslup(2, 3, 5);

	cout << "kula.Objetosc() = " << kula.Objetosc() << endl;
	cout << "kula.Pole() = " << kula.Pole() << endl;
	cout << "prostopadloscian.Objetosc() = " << prostopadloscian.Objetosc() << endl;
	cout << "prostopadloscian.Pole() = " << prostopadloscian.Pole() << endl;
	cout << "prostopadloscian.Przekatna() = " << prostopadloscian.Przekatna() << endl;
	cout << "ostroslup.Objetosc() = " << ostroslup.Objetosc() << endl;
	cout << "ostroslup.Pole() = " << ostroslup.Pole() << endl;

	return 0;
}
