#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

void read (char* in)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file(in);
	if (file.is_open())
	{
		string x;
		while (!file.eof())
		{
			getline(file, x);
			if (!file.eof())
			{
				cout<<x<<endl;
			}
		}
		file.close();
	}
	else cout<<"����������� ������� ����."<<endl;
};

void write (char* in, char* out)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file_in(in);
	if (file_in.is_open())
	{
		ofstream file_out(out);
		if (file_out.is_open())
		{
			int k = 1;
			string x;
			int id = 0;
			while (!file_in.eof())
			{
				getline(file_in, x);
				if (!file_in.eof())
				{
					if (id % 2 == 1)
					{
						int n = x.length();
						string k;
						
						for (int arc = n - 1 ; arc >= 0 ; arc --)
						{
							k = k + x[arc];
						}
						file_out<<k<<endl;
					}
					else
					{
						file_out<<x<<endl;
					}
					id ++;
				}
			}
		}
		else cout<<"����������� ������� ����."<<endl;
		file_out.close();
	}
	else cout<<"����������� ������� ����."<<endl;
	file_in.close();
};

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* name_in = "7.txt";
	char* name_out = "7-1.txt";
	cout<<"� ����� 7.txt ��������� �����:"<<endl;
	read(name_in);
	write(name_in, name_out);
	cout<<endl<<"� ����� 7-1.txt ������ ������ ������ ���������� � �������� �������:"<<endl;
	read(name_out);
	return 0;
}
