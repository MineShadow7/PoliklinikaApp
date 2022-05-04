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
	int pindex;

public:
	void createNewPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy) {};
	int findPatientFIO(string _FIO) { return pindex; };
	int findPatientID(int _id) { return pindex; };
	void editThisPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy, int index) {};
	void deletePatient(int index) {};
	string getPatientFIO(int index) { return allPatients[index].FIO; };
	string getPatientDate(int index) { return allPatients[index].date; };
	int getPatientPassport(int index) { return allPatients[index].passport; };
	int getPatientSnils(int index) { return allPatients[index].snils; };
	int getPatientId(int index) { return allPatients[index].id; };
	string getPatientDiagnosis(int index) { return allPatients[index].diagnisis; };
	string getPatientAllergy(int index) { return allPatients[index].allergy; };
private:
	void getPatients() {};
};