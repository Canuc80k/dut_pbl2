#pragma once
#include "../Business/Patient.h"
#include "../Business/Patient.cpp"
#include "../Structure/LinkedList.cpp"
#include "../Library/Console.cpp"
#include "../Library/Table.cpp"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

bool isValidPatientID(int patientID)
{
    ifstream inFile("./Database/User/Patient/patientID.txt");
    string x;
    string line;
    while (getline(inFile, x))
    {
        line = x;
        if (stoi(line) == patientID)
        {
            return true;
        }
    }
    inFile.close();
    return false;
}

void addPatientToDatabase(Patient &patient)
{
    // generate file path
    // start from main.cpp
    string fileName = "patient" + to_string(patient.getID()) + ".txt";
    string filePath = "./Database/User/Patient/" + fileName;

    // write Patient to database
    ofstream outFile(filePath);
    outFile << patient.getName() << endl;
    outFile << patient.getEmail() << endl;
    outFile << patient.getPassword() << endl;
    for (int i = 0; i < patient.Rec().length(); i++)
    {
        outFile << patient.Rec().get(i) << endl;
    }

    // write Patientid to patientid.txt
    if (!isValidPatientID(patient.getID()))
    {
        ofstream outFilePatientId("./Database/User/Patient/patientID.txt", ios::app);
        outFilePatientId << patient.getID() << endl;
        outFilePatientId.close();
    }

    // close ofstream
    outFile.close();
}

Patient addNewPatient()
{
    cout << spaceLineChoice << "Bệnh nhân mới:\n";

    string name = getStringInput("Tên");
    string email = getEmailInput();
    while (!isUniqueEmail(email))
    {
        printError("Email đã tồn tại!");
        system("pause");
        PatientMenu::main();
    }
    string pwd = getPasswordInput("Mật khẩu");

    // create new patient object
    Patient patient = Patient(getLastPatientId(), name, email, pwd);

    // save to database
    addPatientToDatabase(patient);

    ofstream outFile("./Database/User/userAccount.txt", ios::app);
    outFile << patient.getID() << " ";
    outFile << patient.getEmail() << " ";
    outFile << patient.getPassword() << endl;
    outFile.close();

    // update new patient id range
    updateLine("./Database/ID.txt", 1, getLastPatientId());

    return patient;
}

Patient getPatientFromDatabase(int patientID)
{
    // take file path
    // start from main.cpp
    string filePath = "./Database/User/Patient/";
    string fileName = "patient" + to_string(patientID) + ".txt";

    ifstream inFile(filePath + fileName);
    string line;

    string name;
    string email;
    string password;

    getline(inFile, line);
    name = line;

    getline(inFile, line);
    email = line;

    getline(inFile, line);
    password = line;

    LinkedList<string> recs;
    while (getline(inFile, line))
    {
        recs.addLast(line);
    }

    return Patient(patientID, name, email, password, recs);
}

void deletePatientFromDatabase(int patientID)
{
    Patient patient = getPatientFromDatabase(patientID);

    string filePath = "./Database/User/Patient/";
    string fileName = "patient" + to_string(patientID) + ".txt";

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    int status = remove(char_filePath);

    if (status == 0)
    {
        printSuccess("Successfully delete this Patient!");
        eraseFileLine(filePath + "patientID.txt", to_string(patientID));
        eraseFileLine("./Database/User/userAccount.txt", to_string(patientID) + " " + patient.getEmail() + " " + patient.getPassword());
    }
    else
    {
        printError("Delete failed!");
    }
}

void updatePatientInDatabase(int patientID)
{
    Patient oldPatient = getPatientFromDatabase(patientID);
    Patient patient = getPatientFromDatabase(patientID);

    string filePath = "./Database/User/Patient/";
    string fileName = "patient" + to_string(patientID) + ".txt";

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    int status = remove(char_filePath);

    string name = updateComponent("Name", patient.getName());
    string email = updateComponent("Email", patient.getEmail());
    string password = updatePassword(patient.getPassword());

    patient.setID(patientID);
    patient.setName(name);
    patient.setEmail(email);
    patient.setPassword(password);
    patient.setRec(oldPatient.Rec());

    addPatientToDatabase(patient);
    updateLine("./Database/User/userAccount.txt", to_string(oldPatient.getID()) + " " + oldPatient.getEmail() + " " + oldPatient.getPassword(), to_string(patient.getID()) + " " + patient.getEmail() + " " + patient.getPassword());
}

LinkedList<Patient> getAllPatient()
{
    LinkedList<Patient> patients;

    ifstream inFile("./Database/User/Patient/patientID.txt");
    if (!inFile.is_open())
    {
        printError("Error open file patientID.txt!");
    }
    string x;
    while (getline(inFile, x))
    {
        patients.addLast(getPatientFromDatabase(stoi(x)));
    }

    inFile.close();
    return patients;
}

void printPatient(Patient &patient)
{
    TextTable table;

    table.add("ID");
    table.add("Name");
    table.add("Email");
    table.endOfRow();

    table.add(to_string(patient.getID()));
    table.add(patient.getName());
    table.add(patient.getEmail());
    table.endOfRow();

    cout << table << endl;
}

void printAllPatient(LinkedList<Patient> patients = getAllPatient())
{
    TextTable table;

    table.add("ID");
    table.add("Name");
    table.add("Email");
    table.endOfRow();

    for (int i = 0; i < patients.length(); i++)
    {
        Patient patient = patients.get(i);
        table.add(to_string(patient.getID()));
        table.add(patient.getName());
        table.add(patient.getEmail());
        table.endOfRow();
    }

    cout << table << endl;
}

LinkedList<Patient> searchByPatientCase(string toSearch)
{
    LinkedList<Patient> res;
    LinkedList<Patient> patients = getAllPatient();

    for (int i = 0; i < patients.length(); i++)
    {
        Patient patient = patients.get(i);
        if (findCaseInsensitive(patient.getName(), toSearch) != string::npos)
        {
            res.addLast(patient);
        }
    }
    return res;
}

LinkedList<Patient> getPatientNameFromDatabase(string toSearch)
{
    LinkedList<Patient> res;
    LinkedList<Patient> patients = getAllPatient();

    for (int i = 0; i < patients.length(); i++)
    {
        Patient patient = patients.get(i);
        if (findCaseInsensitive(patient.getName(), toSearch) != string::npos)
        {
            res.addLast(patient);
        }
    }
    return res;
}

void searchPatientID()
{
    int id = getIntInput("Enter ID");
    if (!isValidPatientID(id))
    {
        printError("Invalid ID!");
    }
    else
    {
        Patient patient = getPatientFromDatabase(id);
        printPatient(patient);
    }
}

void searchByPatientName()
{
    string name = getStringInput("Enter name");
    LinkedList<Patient> patients = searchByPatientCase(name);
    if (patients.length() > 0)
    {
        printAllPatient(patients);
    }
    else
    {
        printError("Invalid name!");
    }
}
