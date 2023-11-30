#pragma once
#include "../user/Patient.h"
#include "../user/Patient.cpp"
#include "../datastructure/LinkedList.cpp"
#include "FileManagement.cpp"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

bool isValidPatientID(int patientID) {
    ifstream inFile("./database/UserDB/PatientDB/patientID.txt");
    string x, line;
    while (getline(inFile, x)) {
        line = x;
        if (stoi(line) == patientID)
            return true;
    }
    inFile.close();
    return false;
}

int getLastPatientId() {
    ifstream inFile("./database/userdb/patientdb/lastID.txt");
    string x;
    int res;
    getline(inFile, x);
    return stoi(x);
    inFile.close();
    return res;
}

void addPatientToDatabase(Patient &patient) {
    string fileName = "patient" + to_string(patient.getID()) + ".txt";
    string filePath = "./database/userdb/patientdb/" + fileName;
    ofstream outFile(filePath);
    outFile << patient.getName() << '\n';
    outFile << patient.getEmail() << '\n';
    outFile << patient.getPassword() << '\n';
    if (patient.getRec()) {
        for (int i = 0; i < (*patient.getRec()).size(); i++)
            outFile << (*(*patient.getRec()).get(i)) << endl;
    }
    outFile.close();
    if (!isValidPatientID(patient.getID())) {
        ofstream outFilePatientId("./database/userdb/patientdb/patientID.txt", ios::app);
        outFilePatientId << patient.getID() << endl;
        outFilePatientId.close();
    }
}

void addNewPatient(Patient &patient) {
    int id = getLastPatientId() + 1;
    patient.setID(id);
    addPatientToDatabase(patient);
    ofstream outFile("./database/userdb/userData.txt", ios::app);
    outFile << patient.getID() << " ";
    outFile << patient.getEmail() << " ";
    outFile << patient.getPassword() << endl;
    outFile.close();
    updateLine("./database/userdb/patientdb/lastID.txt", 1, to_string(id));
}

Patient getPatientFromDatabase(int patientID) {
    string filePath = "./database/userdb/patientdb/";
    string fileName = "patient" + to_string(patientID) + ".txt";

    ifstream inFile(filePath + fileName);
    string line, name, email, password;

    getline(inFile, line);
    name = line;
    getline(inFile, line);
    email = line;
    getline(inFile, line);
    password = line;

    LinkedList<string>* recs;
    while (getline(inFile, line))
        (*recs).addLast(line);
    return Patient(patientID, name, email, password, recs);
}

void deletePatientFromDatabase(int patientID) {
    Patient patient = getPatientFromDatabase(patientID);

    string filePath = "./database/userdb/patientdb/";
    string fileName = "patient" + to_string(patientID) + ".txt";

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    int status = remove(char_filePath);
    if (status == 0) {
        eraseFileLine(filePath + "patientID.txt", to_string(patientID));
        eraseFileLine("./database/userdb/userData.txt", to_string(patientID) + " " + patient.getEmail() + " " + patient.getPassword());
    }
}

void updatePatientInDatabase(int patientID, Patient &patient) {
    Patient oldPatient = getPatientFromDatabase(patientID);
    patient.setID(patientID);
    patient.setRec(oldPatient.getRec());
    string filePath = "./database/userdb/patientdb/";
    string fileName = "patient" + to_string(patientID) + ".txt";
    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());
    int status = remove(char_filePath);
    cout << status << " " << filePath + fileName << endl;
    addPatientToDatabase(patient);
    updateLine("./database/userDB/userData.txt", to_string(oldPatient.getID()) + " " + oldPatient.getEmail() + " " + oldPatient.getPassword(), to_string(patient.getID()) + " " + patient.getEmail() + " " + patient.getPassword());
}

LinkedList<Patient>* getAllPatient() {
    LinkedList<Patient>* patients = new LinkedList<Patient>;
    ifstream inFile("./database/userdb/patientdb/patientID.txt");
    string x;
    while (getline(inFile, x)) {
        Patient patient = getPatientFromDatabase(stoi(x)); 
        (*patients).addLast(patient);
    }
    inFile.close();
    return patients;
}

int main() {
    Patient a(1, "Quang", "quang@gmail.com", "2106");
    Patient b(2, "Ly", "ly@gmail.com", "2201");
    Patient c(3, "Han", "han@gmail.com", "2709");
    // addNewPatient(a);
    // addNewPatient(b);
    // addNewPatient(c);

    LinkedList<Patient>* x = new LinkedList<Patient>;
    (*x).addLast(a);
    cout << "DONE ADD" << endl;
    (*x).addLast(b);
    (*x).addLast(c);
    // cout << (*(*x).get(0)).getID() << endl;
    for (int i = 0; i < (*x).size(); i ++) {
        // cout << "??endl" << " " << (*(*x).get(i)).getID() << endl;
        cout << (*(*x).get(i)).getID() << " ";
    }
}

// void printPatient(Patient &patient) {
//     TextTable table;

//     table.add("ID");
//     table.add("Name");
//     table.add("Email");
//     table.endOfRow();

//     table.add(to_string(patient.getID()));
//     table.add(patient.getName());
//     table.add(patient.getEmail());
//     table.endOfRow();

//     cout << table << endl;
// }

// void printAllPatient(LinkedList<Patient> patients = getAllPatient()) {
//     TextTable table;

//     table.add("ID");
//     table.add("Name");
//     table.add("Email");
//     table.endOfRow();

//     for (int i = 0; i < patients.length(); i++)
//     {
//         Patient patient = patients.get(i);
//         table.add(to_string(patient.getID()));
//         table.add(patient.getName());
//         table.add(patient.getEmail());
//         table.endOfRow();
//     }

//     cout << table << endl;
// }

// LinkedList<Patient> searchByPatientCase(string toSearch) {
//     LinkedList<Patient> res;
//     LinkedList<Patient> patients = getAllPatient();

//     for (int i = 0; i < patients.length(); i++)
//     {
//         Patient patient = patients.get(i);
//         if (findCaseInsensitive(patient.getName(), toSearch) != string::npos)
//         {
//             res.addLast(patient);
//         }
//     }
//     return res;
// }

// LinkedList<Patient> getPatientNameFromDatabase(string toSearch) {
//     LinkedList<Patient> res;
//     LinkedList<Patient> patients = getAllPatient();

//     for (int i = 0; i < patients.length(); i++)
//     {
//         Patient patient = patients.get(i);
//         if (findCaseInsensitive(patient.getName(), toSearch) != string::npos)
//         {
//             res.addLast(patient);
//         }
//     }
//     return res;
// }

// void searchPatientID() {
//     int id = getIntInput("Enter ID");
//     if (!isValidPatientID(id))
//     {
//         printError("Invalid ID!");
//     }
//     else
//     {
//         Patient patient = getPatientFromDatabase(id);
//         printPatient(patient);
//     }
// }

// void searchByPatientName() {
//     string name = getStringInput("Enter name");
//     LinkedList<Patient> patients = searchByPatientCase(name);
//     if (patients.length() > 0)
//     {
//         printAllPatient(patients);
//     }
//     else
//     {
//         printError("Invalid name!");
//     }
// }
