#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
    private:
        int id;
        string name;
        string email;
        string password;

    public:
        User();
        User(int, string);
        User(int, string, string);
        User(int, string, string, string);
        void operator=(User const &user);

        int getID();
        void setID(int);
        string getName();
        void setName(string);
        string getEmail();
        void setEmail(string);
        string getPassword();
        void setPassword(string);
};