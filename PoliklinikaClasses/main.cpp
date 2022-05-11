#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char buff[50];
	ifstream file("Patients.txt");
	if (!file.is_open()) 
	{
		cout << "Ошибка открытия файла";
	}
	else
	{
		cout << "файл открыт";
	}
	
	file.close();

	return 0;
}