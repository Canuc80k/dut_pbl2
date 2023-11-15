#include <vector>
#include <string>
using namespace std;

class Person {
    private:
        int id, age;
        string name;
        string nationID;
    
    public:
        Person() {};
        Person(string name, string nationID): name(name), nationID(nationID) {};
        ~Person() {};
};