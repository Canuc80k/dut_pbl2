#pragma once
#include <iostream>
#include <string>
using namespace std;

class Drug {
    private:
        int id;
        string name;
        string disease;
        int quantity;
        int price;
        int sale;
        string description;

public:
    Drug();
    Drug(int, string, string, int, int, int, string);
    Drug(const Drug&);

    Drug& operator = (const Drug&);

    int getID();
    void setID(int);
    string getName();
    void setName(string);
    string getDisease();
    void setDisease(string);
    int getQuantity();
    void setQuantity(int);
    int getPrice();
    void setPrice(int);
    int getSale();
    void setSale(int);
    string getDescription();
    void setDescription(string);
};