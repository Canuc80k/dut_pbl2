#pragma once
#include "Drug.h"
#include <fstream>
#include <iostream>
using namespace std;

Drug::Drug() {
    this->id = 0;
    this->name = "";
    this->disease = "";
    this->quantity = 0;
    this->price = 0;
    this->sale = 0;
    this->description = "";
}

Drug::Drug(int id, string name, string disease, int quantity, int price , int sale, string description) {
    this->id = id;
    this->name = name;
    this->disease = disease;
    this->quantity = quantity;
    this->price = price;
    this->sale = sale;
    this->description = description;
}

Drug::Drug(const Drug& drug) {
    this->id = drug.id;
    this->name = drug.name;
    this->disease = drug.disease;
    this->quantity = drug.quantity;
    this->price = drug.price;
    this->sale = drug.sale;
    this->description = drug.description;
}

Drug& Drug::operator = (const Drug& drug) {
    this->id = drug.id;
    this->name = drug.name;
    this->disease = drug.disease;
    this->quantity = drug.quantity;
    this->price = drug.price;
    this->sale = drug.sale;
    this->description = drug.description;
    return *this;
}

int Drug::getID() {return this->id;}
void Drug::setID(int id) {this->id = id;}
string Drug::getName() {return this->name;}
void Drug::setName(string name) {this->name = name;}
string Drug::getDisease() {return this->disease;}
void Drug::setDisease(string disease) {this->disease = disease;}
int Drug::getQuantity() {return this->quantity;}
void Drug::setQuantity(int quantity) {this->quantity = quantity;}
int Drug::getPrice() {return this->price;}
void Drug::setPrice(int price) {this->price = price;}
int Drug::getSale() {return this->sale;}
void Drug::setSale(int sale) {this->sale = sale;}
string Drug::getDescription() {return this->description;}
void Drug::setDescription(string description) {this->description = description;}