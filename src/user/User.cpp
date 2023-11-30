#pragma once
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

User::User() {
    this->id = 0;
    this->name = "";
    this->email = "";
    this->password = "";
}

User::User(int id, string name) {
    this->id = id;
    this->name = name;
}

User::User(int id, string email, string password) {
    this->id = id;
    this->email = email;
    this->password = password;
}

User::User(int id, string name, string email, string password) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

void User::operator=(User const& obj) {
    this->id = obj.id;
    this->name = obj.name;
    this->email = obj.email;
    this->password = obj.password;
}

int User::getID() {return this->id;}
void User::setID(int id) {this->id = id;}
string User::getName() {return this->name;}
void User::setName(string name) {this->name = name;}
string User::getEmail() {return this->email;}
void User::setEmail(string email) {this->email = email;}
string User::getPassword() {return this->password;}
void User::setPassword(string password) {this->password = password;}
