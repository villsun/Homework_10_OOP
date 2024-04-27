#include <iostream>

using namespace std;

class Student
{
private:
	int* ptr;
	int m_size;
public:
	Student()
	{
		ptr = nullptr;
		m_size = -1;
	}
	void Fill()
	{
		int size;
		cout << "Enter how many grades the student has:\n";
		cin >> size;
		if (size <= 0)
		{
			throw("Size must be greater than 0!");
		}
		m_size = size;
		ptr = new int[m_size];

		int marks;
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter marks:\n";
			cin >> marks;
			if (marks < 0 || marks>12)
			{
				throw("Marks must be greater than 0 but less than 12!");
			}
			ptr[i] = marks;
		}
	}

	void Show()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			cout << "Marks " << i + 1 << ": " << ptr[i] << endl;
		}
	}

	double GPA()
	{
		double GPA = 0;
		for (size_t i = 0; i < m_size; i++)
		{
			if (ptr[i] < 0 || ptr[i] > 12)
			{
				throw("ERROR!");
			}
			GPA += ptr[i];
		}

		return GPA / 1.0 / m_size;
	}
	~Student()
	{
		m_size = -1;
		delete[] ptr;
	}
};

int main()
{
	Student student_1;
	try
	{
		student_1.Fill();
		student_1.Show();
		cout << student_1.GPA() << endl;
	}
	catch(const char* exception)
	{
		cout << exception << endl;
		exit(-1);
	}

	return 0;
}