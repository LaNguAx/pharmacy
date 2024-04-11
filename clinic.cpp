#pragma once
#include "Clinic.h"

Clinic::Clinic(const char* clinicName, const char* clinicAddress) {
	this->init(clinicName, clinicAddress);
}

Clinic::Clinic(const Clinic& c) { *this = c; }

 Clinic& Clinic::operator=(const Clinic& c) {
	
	if (this == &c) return *this;

	//strcpy_s(m_clinicName, c.getName());
	//strcpy_s(m_clinicAddress, c.getAddress());

	this->setName(c.getName());
	this->setAddress(c.getAddress());

	if (c.getNumOfPatients() == 0) return *this;
	
	// delete patients array
	// copy patients array

	return *this;
}


void Clinic::init(const char* clinicName, const char* clinicAddress) {

	//strcpy_s(m_clinicName, clinicName);
	//strcpy_s(m_clinicAddress, clinicAddress);

	this->setName(clinicName);
	this->setAddress(clinicAddress);
	
	m_numOfPatients = 0;
	m_patients = nullptr;
}

// setters
void Clinic::setName(const char* name) { strcpy_s(m_clinicName, name); }
void Clinic::setAddress(const char* address) { strcpy_s(m_clinicAddress, address); }

// getters
const char* Clinic::getName() const { return m_clinicName; }
const char* Clinic::getAddress() const { return m_clinicAddress; }
int Clinic::getNumOfPatients() const { return m_numOfPatients; }

// helpers
void Clinic::deletePatients() {

	for (int i = 0; i < m_numOfPatients; i++) {
		//int patientDiagnoses = this->m_patients[i]->getDiagnosesCount();
		delete this->m_patients[i];
	}
	delete[] this->m_patients;

	this->m_patients = nullptr;
}

Patient** Clinic::copyPatients() const {

	Patient** newPatients = new Patient * [m_numOfPatients + 1];

	for (int i = 0; i < m_numOfPatients; i++) {

		newPatients[i] = new Patient;
		newPatients[i]->setName(this->m_patients[i]->getFirstName(), this->m_patients[i]->getLastName());
		newPatients[i]->setId(this->m_patients[i]->getId());

		int patientDiagnoses = this->m_patients[i]->getDiagnosesCount();

		for (int j = 0; j < patientDiagnoses; j++) {
			newPatients[i]->addDiagnose(this->m_patients[i]->getDiagnose(j));
		}
	}

	return newPatients;
}


bool Clinic::addPatient(const Patient& p) {


	Patient** newPatients = this->copyPatients();
	
	this->deletePatients();

	newPatients[this->getNumOfPatients()] = new Patient;
	*newPatients[this->getNumOfPatients()] = p;



	this->m_patients = newPatients;
	++m_numOfPatients;

	return true;
}

void Clinic::printClinic() const {

	std::cout << "*********CLINIC DETAILS START*********" << std::endl;
	std::cout << m_clinicName << std::endl;
	std::cout << m_clinicAddress << std::endl;
	std::cout << m_numOfPatients << std::endl;


	for (int i = 0; i < m_numOfPatients; i++) {
		std::cout << "*********PATIENT NUM: " << i << " START*********" << std::endl;

		this->m_patients[i]->printPatient();
		std::cout << "*********PATIENT NUM: " << i << " END*********" << std::endl;

	}
	std::cout << "*********CLINIC DETAILS END*********" << std::endl;

}