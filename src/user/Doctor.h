#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include "../drug/Drug.h"
#include "../datastructure/LinkedList.cpp"

using namespace std;

class Doctor : public User {
    public:
        Doctor();
        Doctor(int, string, string, string);

        void searchByPatientID();
        void searchByPatientName();
        void printAllPatient();
        void updatePatientById(int);
        void deletePatientById(int);
        void addNewDrug();
        void updateDrugById(int);
        void deleteDrugById(int);
        void printAllAppointment();
        void printByMonthAppointment();
};
