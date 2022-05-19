#include "PatientsClasses.h"

void Patient::createPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy) {
	id = _id;
	FIO = _FIO;
	date = _date;
	passport = _passport;
	snils = _snils;
	diagnisis = _diagnisis;
	allergy = _allergy;
}

void Patient::editPatient(string _FIO, string _date, int _passport, int _snils, string _diagnisis, string _allergy, int _id) {
	id = _id;
	FIO = _FIO;
	date = _date;
	passport = _passport;
	snils = _snils;
	diagnisis = _diagnisis;
	allergy = _allergy;
};

void Patients::createNewPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy) {
	patientCount += 1;
	Patient* _allPatients = new Patient[patientCount];
	for (int i = 0; i < patientCount - 1; i++)
	{
		_allPatients[i] = allPatients[i];
	}
	_allPatients[patientCount - 1].createPatient(_FIO, _date, _passport, _snils, _id, _diagnisis, _allergy);
	delete[] allPatients;
	allPatients = new Patient[patientCount];
	for (int i = 0; i < patientCount; i++)
	{
		allPatients[i] = _allPatients[i];
	}
};

int Patients::findPatientFIO(string _FIO)
{
	for (int i = 0; i < patientCount; i++)
	{
		if (_FIO == allPatients[i].FIO) { return i; }
	}
}

int Patients::findPatientID(int _id) {
	for (int i = 0; i < patientCount; i++)
	{
		if (_id == allPatients[i].id) { return i; }
	}
};

void Patients::editThisPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy, int index) {
	allPatients[index].editPatient(_FIO, _date, _passport, _snils, _diagnisis, _allergy, _id);
};

void Patients::deletePatient(int index) {
	Patient* _allPatients;
	patientCount -= 1;
	for (int i = 0; i < patientCount; i++)
	{
		if (i >= index) {
			_allPatients[i] = allPatients[i + 1];
		}
		else {
			_allPatients[i] = allPatients[i];
		}
	}
	delete[] allPatients;
	for (int i = 0; i < patientCount; i++)
	{
		allPatients[i] = _allPatients[i];
	}
};

void Patients::getPatients() {
	{
		setlocale(LC_ALL, "RUSSIAN");
		string str, _FIO, _date, _diagnosis, _allergy;
		string* data_patients = new string[7];
		int flag1 = 1;
		for (int j = 0; j < 7; j++)
		{
			data_patients[j] = " ";
		}
		int _id, _passport, _snils, count = 0, index = 0, flag = 0;
		ifstream file("C:\\Users\\shad-\\Documents\\Programming\\PoliklinikaApp\\Patients\\Patients.txt");
		if (!file.is_open())
		{
			cout << "Ошибка открытия файла";
		}
		else
		{
			cout << "файл открыт";

			while (!file.eof())
			{
				str = "";
				getline(file, str);
				if (flag1 == 1)
				{
					patientCount = stoi(str);
					allPatients = new Patient[patientCount];
					flag1 = 0;
				}

				if (str == "]")
				{
					flag = 0;
					_id = stoi(data_patients[0]);
					_FIO = data_patients[1];
					_date = data_patients[2];
					_passport = stoi(data_patients[3]);
					_snils = stoi(data_patients[4]);
					_diagnosis = data_patients[5];
					_allergy = data_patients[6];
					allPatients[patientCount].editPatient(_FIO, _date, _passport, _snils, _diagnosis, _allergy, _id);
					cout << "\n" << _id << "\t" << _FIO << "\t" << _date << "\t" << _passport << "\t" << _snils << "\t" << _diagnosis << "\t" << _allergy;
				}

				if (flag == 1)
				{
					data_patients[index] = str;
					index++;
				}

				if (str == "[")
				{
					flag = 1;
					index = 0;
				}
			}
		}
		file.close();
	}
}

