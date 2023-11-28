#include <iostream>
#include <fstream>
using namespace std;

string trim(string &s) {
    s.erase(0, s.find_first_not_of(" \n\r\t"));                                                                                               
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    return s;   
}

void updateLine(string path, string line, string data) {
    ifstream inFile(path);
    string x, newFileData;
    while (getline(inFile, x)) {
        if (x != line) {
            newFileData += x + '\n';
            continue;
        } else newFileData += data + '\n';
    }
    inFile.close();
    ofstream outFile(path);
    outFile << trim(newFileData);
    outFile.close();
}

void updateLine(string path, int line, string data) {
    ifstream inFile(path);
    string x, newFileData;
    int cnt = 1;
    while (getline(inFile, x)) {
        if (cnt != line) newFileData += x + '\n';
        else newFileData += data + '\n';
        cnt ++;
    }
    inFile.close();
    ofstream outFile(path);
    outFile << trim(newFileData);
    outFile.close();
}

void eraseFileLine(string path, string data) {
    ifstream inFile(path);
    string x, newFileData;

    int cnt = 1;
    while (getline(inFile, x)) {
        if (x != data) {
            newFileData += x + '\n';
            continue;
        }
    }
    inFile.close();
    ofstream outFile(path);   
    outFile << trim(newFileData);
    outFile.close();
}

