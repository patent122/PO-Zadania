#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class TestTime
{
public:
	double ReadFileNonVirtual(const char* path)
	{
		clock_t start = clock();
		for (int i = 0; i < 10; i++)
		{
			ReadFile(path);
		}
		clock_t finish = clock();
		return ((double)(finish - start)) / CLOCKS_PER_SEC;
	}

	virtual double ReadFileVirtual(const char* path)
	{
		clock_t start = clock();
		for (int i = 0; i < 10; i++)
		{
			ReadFile(path);
		}
		clock_t finish = clock();
		return ((double)(finish - start)) / CLOCKS_PER_SEC;
	}

private:
	void ReadFile(const char* path)
	{
		FILE* file;
		string text;
		int c;

		if (fopen_s(&file, path, "rb") == 0)
		{
			while ((c = fgetc(file)) != -1)
			{
				text += (char)c;
			}

			fclose(file);
		}
	}
};

class TestTimeDerived : public TestTime
{
};

int main(int argc, char** argv)
{
	TestTime t1;
	TestTimeDerived t2;

	cout << "t1 time = " << t1.ReadFileNonVirtual("PanTadeusz.txt") << "sek." << endl;
	cout << "t2 time = " << t2.ReadFileVirtual("PanTadeusz.txt") << "sek." << endl;

	return 0;
}
