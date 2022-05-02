#pragma once
#include <string>

using namespace std;

class PersonalData {
protected:
	string FIO;
	string date;
	int passport;
	int snils;
};

class Patient : protected PersonalData {
protected:
	int id;
	string diagnisis;
	string allergy;


public:
	void createPatient(string _FIO, string _date, int _passport, int _snils, int _id, string diagnisis, string allergy) {};
	void editPatient(string _FIO, string _date, int _passport, int _snils, string diagnisis, string allergy) {};

	friend class Patients;
};

class Patients {
protected:
	Patient* allPatients;
	int patientCount;

public:
	void createNewPatient(string _FIO, string _date, int _passport, int _snils, int _id, string diagnisis, string allergy) {};
	void findPatientFIO(string _FIO) {};
	void findPatientID(int _id) {};
	void editThisPatient(string _FIO, string _date, int _passport, int _snils, int _id, string diagnisis, string allergy) {};
	void deletePatient() {};
private:
	void getPatients() {};
};