#pragma once
#include "../datastructure/LinkedList.cpp"
#include "../Drug/Drug.h"
#include "../Drug/Drug.cpp"

class Cart {
    private:
        LinkedList<int>* drugID;
        LinkedList<int>* drugQuantity;
        int totalPrice;

    public:
        Cart();
        ~Cart();
        void addDrugtoCart(int, int, int = 1);
        void emptyCart();
        LinkedList<int>* getDrugIDList();
        LinkedList<int>* getDrugQuantityList();
        int getTotalPrice();
};