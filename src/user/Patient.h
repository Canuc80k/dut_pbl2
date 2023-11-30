#pragma once
#include "User.cpp"
#include "../cart/Cart.cpp"
#include "../datastructure/LinkedList.cpp"

class Patient : public User {
    private:
        Cart cart;
        LinkedList<string>* rec;

    public:
        Patient();
        Patient(int id, string name, string email, string password);
        Patient(int id, string name, string email, string password, LinkedList<string>* recs);
        ~Patient();
        void operator=(Patient const& patient);

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
