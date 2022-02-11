#include <iostream>

using namespace std;

// szablon klasy liczący ciąg fibonacciego
template <typename T, int N>
class Fibonacci
{
public:
	// konstruktor wyliczający ciąg w podanym zakresie
	Fibonacci()
	{
		elementy[0] = 0;
		elementy[1] = 1;

		for (int i = 2; i < N; i++)
		{
			elementy[i] = elementy[i - 1] + elementy[i - 2];
		}
	}

	// zwraca n-ty wyraz ciągu lub -1 jeżeli podano n spoza zakresu
	T Element(int n)
	{
		if (!CzyNalezy(n))
		{
			return (T)-1;
		}

		return elementy[n];
	}

	// sprawdza czy n jest w zakresie
	bool CzyNalezy(int n)
	{
		return n >= 0 && n < N;
	}

private:
	// tablica elementów ciągu
	T elementy[N];
};

// start programu
int main(int argc, char** argv)
{
	// test dla typu int
	Fibonacci<int, 20> f1;

	cout << "f1.Element(5) = " << f1.Element(5) << endl;
	cout << "f1.Element(10) = " << f1.Element(10) << endl;
	cout << "f1.Element(19) = " << f1.Element(19) << endl;

	// test dla typu double
	Fibonacci<double, 30> f2;

	cout << "f2.Element(10) = " << f2.Element(10) << endl;
	cout << "f2.Element(20) = " << f2.Element(20) << endl;
	cout << "f2.Element(29) = " << f2.Element(29) << endl;

	return 0;
}
