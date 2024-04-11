#include "Patient.h"

Patient::Patient(const Patient& p) {
	*this = p;
}

void Patient::init(const char* firstName, const char* lastName, long id) {

	char fullName[(NAME_LENGTH * 2) - 1] = { '\0' };
	strcat_s(fullName, firstName);
	strcat_s(fullName, lastName);

	if (!isValidName(fullName)) return;

	this->setName(firstName, lastName);
	this->setId(id);
}

Patient::~Patient() {

	int diagnosis = this->getDiagnosesCount();
	if (!diagnosis) return;

	for (int i = 0; i < diagnosis; i++) {
		this->deleteDiagnose(i);
	}
	delete[] this->m_diagnoses;
}


Patient& Patient::operator=(const Patient& p) {
	// must check addresses because *this might be equal to p.
	if (this == &p) return *this;

	this->init(p.getFirstName(), p.getLastName(), p.getId());

	this->deleteDiagnosis();
	this->m_diagnoses = nullptr;

	for (int i = 0; i < p.getDiagnosesCount(); i++) {
		this->addDiagnose(p.getDiagnose(i));
	}

	return *this;
}

void Patient::deleteDiagnosis() {

	int currentDiagnosesCount = this->getDiagnosesCount();
	// delete old array
	for (int i = 0; i < currentDiagnosesCount; i++) {

		//if (this->getDiagnose(i) == nullptr) continue;

		this->deleteDiagnose(i);
	}
	delete[] this->m_diagnoses;

	this->m_diagnoses = nullptr;

}



bool Patient::isValidName(const char* name) const {
	for (int i = 0; i < strlen(name); i++)
		if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' ' || name[i] == '-'))
			return false;

	return true;
}


void Patient::setName(const char* name, const char* lastName) {
	strcpy_s(this->m_firstName, strlen(name)+1, name);
	strcpy_s(this->m_lastName, strlen(lastName) + 1, lastName);
}

void Patient::printPatient() const {
	std::cout << this->getFirstName() << std::endl;
	std::cout << this->getLastName() << std::endl;
	std::cout << this->getId() << std::endl;

	std::cout << "Diagnoses: ";
	if (!this->m_diagnoses_count) std::cout << "0." << std::endl;
	else {
		std::cout << std::endl;
		this->printDiagnoses();
	}
}

void Patient::printDiagnoses() const {


	if (!this->getDiagnosesCount()) {
		std::cout << "no diagnosis to print" << std::endl;
	};

	for (int i = 0; i < this->getDiagnosesCount(); i++) {
		std::cout << i +1 << ". " << this->getDiagnose(i) << std::endl;
	}
}


void Patient:: addDiagnose(const char* diagnose) { 

	int currentDiagnosesCount = this->getDiagnosesCount();
	char** newDiagnoses = new char* [currentDiagnosesCount+ 1];
	
	// copy all diagnoses first
	for (int i = 0; i < currentDiagnosesCount; i++) {
		newDiagnoses[i] = new char[strlen(this->getDiagnose(i)) + 1];
		strcpy_s(newDiagnoses[i], strlen(this->getDiagnose(i)) + 1, this->getDiagnose(i));
	}
	// add new diagnosis
	newDiagnoses[currentDiagnosesCount] = new char[strlen(diagnose) + 1];
	strcpy_s(newDiagnoses[currentDiagnosesCount], strlen(diagnose) + 1, diagnose);


	// delete old array
	for (int i = 0; i < currentDiagnosesCount; i++) {
		delete[] this->m_diagnoses[i];
	}
	delete[] this->m_diagnoses;

	this->m_diagnoses = newDiagnoses;
	this->m_diagnoses_count = ++currentDiagnosesCount;

}


int Patient::searchDiagnose(const char* diagnose) const {

	for (int i = 0; i < this->getDiagnosesCount(); i++) {

		if (strcmp(this->getDiagnose(i), diagnose) != 0) continue;
		else return i;
	}
	return -1;
}

void Patient::deleteDiagnose(const char* diagnose) {

	int foundDiagnose = this->searchDiagnose(diagnose);

	if (this->getDiagnosesCount() == 0) {
		std::cout << "This patient is completely healthy!" << std::endl;
		return;

	}

	if (foundDiagnose < 0 ) {
		std::cout << "No diagnose found to delete.." << std::endl;
			return;
	}

	delete[] this->m_diagnoses[foundDiagnose];
	this->m_diagnoses[foundDiagnose] = nullptr;

	int currentDiagnosesCount = this->getDiagnosesCount();
	char** newDiagnoses = new char* [currentDiagnosesCount - 1];

	// copy all diagnoses first
	int k = 0;
	for (int i = 0; i < currentDiagnosesCount; i++) {
		
		// if we fall on the deleted index.
		if (this->getDiagnose(i) == nullptr) continue;

		newDiagnoses[k] = new char[strlen(this->getDiagnose(i)) + 1];
		strcpy_s(newDiagnoses[k], strlen(this->getDiagnose(i)) + 1, this->getDiagnose(i));

		k++;
	}

	// delete old array
	for (int i = 0; i < currentDiagnosesCount; i++) {

		if (this->getDiagnose(i) == nullptr) continue;

		delete[] this->m_diagnoses[i];
	}
	delete[] this->m_diagnoses;

	this->m_diagnoses = newDiagnoses;
	this->m_diagnoses_count = --currentDiagnosesCount;

	std::cout << "Successfully deleted " << diagnose << std::endl;
}
