#pragma once
#include "Doctor.h"
#include "../Management/PatientManagement.cpp"
#include "../Management/DrugManagement.cpp"
#include "../Management/AppointmentManagement.cpp"

Doctor::Doctor() : User() {}

Doctor::Doctor(int id, string name, string email, string password) : User(id, name, email, password) {}

void Doctor::searchByPatientID() {}

void Doctor::searchByPatientName() {}

void Doctor::printAllPatient() {}

void Doctor::updatePatientById(int id) {}

void Doctor::deletePatientById(int id) {}

void Doctor::addNewDrug() {}

void Doctor::updateDrugById(int id) {}

void Doctor::deleteDrugById(int id) {}

void Doctor::printAllAppointment() {}

void Doctor::printByMonthAppointment() {}