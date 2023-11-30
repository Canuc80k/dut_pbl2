#include "Patient.h"
#include "../calendar/Calendar.cpp"
#include "../drug/Drug.h"
// #include "../management/DrugManagement.cpp"
// #include "../management/ReceiptManagement.cpp"
// #include "../management/AppointmentManagement.cpp"
#include <iostream>
using namespace std;

Patient::Patient() : User(0, "", "", "") {
    this->rec = new LinkedList<string>;
    this->cart = Cart();
}

Patient::Patient(int id, string name, string email, string password) : User(id, name, email, password) {
    this->rec = new LinkedList<string>;
    this->cart = Cart();
}

Patient::Patient(int id, string name, string email, string password, LinkedList<string>* rec) : User(id, name, email, password) {
    this->rec = rec;
    this->cart = Cart();
}

void Patient::operator=(Patient const& obj) {
    cout << "AAAAA" << endl;
    *this = obj;
    this->rec = obj.rec;
    this->cart = obj.cart;
}

Patient::~Patient() {
    delete rec;
}

Cart &Patient::getCart() {return this->cart;}
LinkedList<string>* Patient::getRec() {return this->rec;}
void Patient::setRec(LinkedList<string>* rec) {this->rec = rec;}

void Patient::purchase() {
    // string recID = "REC#" + to_string(this->rec.size() + 1);
    // this->rec.addLast(recID);

    // string fileName = to_string(this->getID()) + "_" + recID + ".txt";
    // string filePath = "../../Database/ReceiptDB/" + fileName;
    // ofstream outFilePatient("../../Database/UserDB/PatientDB/PATIENT_" + to_string(this->getID()) + ".txt", ios::app);
    // outFilePatient << recID << '\n';
    // outFilePatient.close();

    // ofstream outFile(filePath);
    // string date = currentDateTime();
    // outFile << date << '\n';
    // outFile << cart.getTotalPrice() << '\n';

    // for (int i = 0; i < (*cart.getDrugIDList()).length(); i++) {
    //     outFile << (*cart.getDrugQuantityList()).get(i) << " ";
    //     outFile << (*cart.getDrugIDList()).get(i) << '\n';
    // }

    // outFile.close();
    // printReceipt(this->getID(), recID);

    // _Cart.emptyCart();
}

void Patient::searchByReceiptID(int id) {
    // getReceiptFromDatabase(this->getID(), id);
}

void Patient::printALLPatientReceipts() {
    // getAllPatientReceipts(*this);
}

void Patient::addNewReceipt() {
    // addReceiptToDatabase(this->getID(), this->cart, *this->rec);
}

void Patient::deleteReceiptById(string id) {
    // deleteReceiptFromDatabase(this->getID(), id);
}

void Patient::bookAnAppointment() {
}

void Patient::printMedicalHistory() {
}