#pragma once
#include "User.cpp"
#include "Cart.cpp"
#include "../datastructure/LinkedList.cpp"

class Patient : public User {
    private:
        Cart cart;
        LinkedList<string>* rec;

    public:
        Patient();
        Patient(int id, string name, string email, string password, LinkedList<string>* recs);

        Cart &getCart();
        LinkedList<string>* getRec();
        void setRec(LinkedList<string>*);
        void purchase();
        void searchByReceiptID(int);
        void printALLPatientReceipts();
        void addNewReceipt();
        void deleteReceiptById(string);
        void bookAnAppointment();
        void printMedicalHistory();
};
