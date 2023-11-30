#pragma once
#include "../Drug/Drug.h"
#include "../Drug/Drug.cpp"
#include "../datastructure/LinkedList.cpp"
#include "FileManagement.cpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

bool isValidDrugId(int drugID) {
    ifstream inFile("./database/DrugDB/drugID.txt");
    string x;

    while (getline(inFile, x)) {
        if (stoi(x) == drugID)
            return true;
    }
    inFile.close();
    return false;
}

int getLastDrugId() {
    ifstream inFile("./database/DrugDB/lastID.txt");
    string x;
    int res;
    getline(inFile, x);
    return stoi(x);
    inFile.close();
    return res;
}

void addDrugToDatabase(Drug &drug) {
    string fileName = to_string(drug.getID()) + ".txt";
    string filePath = "./database/DrugDB/" + fileName;

    ofstream outFile(filePath);
    outFile << drug.getID() << endl;
    outFile << drug.getName() << endl;
    outFile << drug.getDisease() << endl;
    outFile << drug.getQuantity() << endl;
    outFile << drug.getPrice() << endl;
    outFile << drug.getSale() << endl;
    outFile << drug.getDescription() << endl;

    if (!isValidDrugId(drug.getID())) {
        ofstream outFileDrugId("./database/DrugDB/drugID.txt", ios::app);
        outFileDrugId << drug.getID() << endl;
        outFileDrugId.close();
    }
    outFile.close();
}

void addNewDrugToDataBase(Drug &drug) {
    int id = getLastDrugId() + 1;

    drug.setID(id);
    addDrugToDatabase(drug);
    updateLine("./database/DrugDB/lastID.txt", 1, to_string(id));

    ofstream outFilesale("./database/saleSummary.txt", ios::app);
    if (drug.getID() != 1) outFilesale << endl;
    outFilesale << drug.getID() << " " << drug.getSale();
    outFilesale.close();
}

Drug getDrugFromDatabase(int drugID) {
    string fileName = to_string(drugID) + ".txt";
    string filePath = "./database/DrugDB/" + fileName;

    ifstream inFile(filePath);
    string line;

    string name;
    string disease;
    int quantity;
    int price;
    int sale;
    string description;

    getline(inFile, line);
    drugID = stoi(line);

    getline(inFile, line);
    name = line;

    getline(inFile, line);
    disease = line;

    getline(inFile, line);
    quantity = stoi(line);

    getline(inFile, line);
    price = stoi(line);

    getline(inFile, line);
    sale = stoi(line);

    getline(inFile, line);
    description = line;

    return Drug(drugID, name, disease, quantity, price, sale, description);
}

void deleteDrugFromDatabase(int drugID) {
    string filePath = "./database/DrugDB/";
    string fileName = to_string(drugID) + ".txt";

    int status = remove((filePath + fileName).c_str());

    if (status == 0) {
        eraseFileLine(filePath + "drugID.txt", to_string(drugID));
        eraseFileLine("./database/saleSummary.txt", to_string(drugID));
    }
}

void updateDrugInDatabase(int drugID, Drug &newDrug) {
    Drug drug = getDrugFromDatabase(drugID);
    string filePath = "./database/DrugDB/";
    string fileName = to_string(drugID) + ".txt";

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    int status = remove(char_filePath);
    addDrugToDatabase(newDrug);
}

LinkedList<Drug>* getAllDrug() {
    LinkedList<Drug>* drugs = new LinkedList<Drug>;
    ifstream inFile("./database/DrugDB/drugID.txt");
    string x;
    while (getline(inFile, x)) {
        Drug drug = getDrugFromDatabase(stoi(x));
        (*drugs).addLast(drug);
    }
    inFile.close();
    return drugs;
}

Drug searchByDrugsID(int id) {
    if (!isValidDrugId(id)) return Drug();
    return getDrugFromDatabase(id);
}

void updateDrugQuantityInDatabase(int id, int quantity) {
    updateLine("./database/DrugDB/" + to_string(id) + ".txt", 4, to_string(quantity));
}

void updateSale(int drugID, int amount) {
    ifstream inFile("./database/saleSummary.txt");
    string sale, line;
    int firstIndex;
    while (getline(inFile, line)) {
        firstIndex = line.find_first_of(" ");
        if (stoi(line.substr(0, firstIndex)) == drugID)
            break;
    } 
    inFile.close();
    Drug drug = getDrugFromDatabase(drugID);
    int new_sale = drug.getSale() + amount;
    updateLine("./database/saleSummary.txt", line, line.substr(0, firstIndex + 1) + to_string(new_sale));
    updateLine("./database/DrugDB/" + to_string(drugID) + ".txt", 6, to_string(new_sale));
}

LinkedList<Drug>* getSaleManagement() {
    ifstream inFile("./database/saleSummary.txt");
    LinkedList<Drug>* drugs = new LinkedList<Drug>;

    string line;
    int firstIndex;
    while (getline(inFile, line)) {
        firstIndex = line.find_first_of(" ");
        int drugID = stoi(line.substr(0, firstIndex));
        int sale = stoi(line.substr(firstIndex + 1));
        Drug drug = getDrugFromDatabase(drugID);
        (*drugs).addLast(Drug(drug.getID(), drug.getName(), drug.getDisease(), drug.getQuantity(), drug.getPrice(), drug.getSale(), drug.getDescription()));
    }
    inFile.close();
    return drugs;
}