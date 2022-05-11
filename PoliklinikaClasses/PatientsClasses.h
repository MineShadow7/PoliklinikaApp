#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class PersonalData {
protected:
	string FIO;
	string date;
	int passport;
	int snils;
	PersonalData& operator=(const PersonalData& right) {
		if (this == &right)
		{
			return *this;
		}
		else
		{
			this->FIO = right.FIO;
			this->date = right.date;
			this->passport = right.passport;
			this->snils = right.snils;
			return *this;
		}
	};
};

class Patient : protected PersonalData {
protected:
	int id;
	string diagnisis;
	string allergy;
	Patient()
	{
		id = NULL;
		FIO = "";
		date = "";
		passport = NULL;
		snils = NULL;
		diagnisis = "";
		allergy = "";
	}

	Patient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy)
	{
		id = _id;
		FIO = _FIO;
		date = _date;
		passport = _passport;
		snils = _snils;
		diagnisis = _diagnisis;
		allergy = _allergy;
	}

	Patient& operator=(const Patient& right)
	{
		if (this == &right)
		{
			return *this;
		}
		else
		{
			this->id = right.id;
			this->FIO = right.FIO;
			this->date = right.date;
			this->passport = right.passport;
			this->snils = right.snils;
			this->diagnisis = right.diagnisis;
			this->allergy = right.allergy;
			return *this;
		}
	}

public:
	void createPatient(string _FIO, string _date, int _passport, int _snils, int _id, string diagnisis, string allergy) {};
	void editPatient(string _FIO, string _date, int _passport, int _snils, string _diagnisis, string _allergy, int _id) {};
	
	friend class Patients;
};

class Patients {
protected:
	Patient* allPatients;
	int patientCount;
	int pindex;

	Patients()
	{
		patientCount = 0;	
		allPatients = new Patient[1]();
	}

public:
	void createNewPatient(string _FIO, string _date, int _passport, int _snils, int _id, string _diagnisis, string _allergy) {};
	int findPatientFIO(string _FIO) {};
	int findPatientID(int _id) {};
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
	void getPatients() {

	}; 
};