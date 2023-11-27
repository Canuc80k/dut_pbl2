#pragma once
#include "Cart.h"
using namespace std;

Cart::Cart() {
    drugID = new LinkedList<int>();
    drugQuantity = new LinkedList<int>();
    this->totalPrice = 0;
}

Cart::~Cart() {
    delete drugID;
    delete drugQuantity;
}

LinkedList<int>* Cart::getDrugIDList() {return drugID;}
LinkedList<int>* Cart::getDrugQuantityList() {return drugQuantity;}

int Cart::getTotalPrice() {return this->totalPrice;}

void Cart::addDrugtoCart(int id, int drugPrice, int quantity) {
    (*this->drugID).addLast(id);
    (*this->drugQuantity).addLast(quantity);
    totalPrice += drugPrice * quantity;
}

void Cart::emptyCart() {
    this->drugID = new LinkedList<int>();
    this->drugQuantity = new LinkedList<int>();
    this->totalPrice = 0;
}
