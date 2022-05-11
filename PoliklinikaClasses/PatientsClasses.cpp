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
			allPatients[i] = allPatients[i];
		}
	}
	delete[] allPatients;
	for (int i = 0; i < patientCount; i++)
	{
		allPatients[i] = _allPatients[i];
	}
};

void Patients::getPatients() {

}

