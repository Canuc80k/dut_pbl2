#include <vector>
#include <string>
using namespace std;

class Nation {
    private:
        int id = -1;
        string name, abbr;
        vector<int> leagues;
        vector<int> person;

    public:
        Nation() {};
        Nation(string name, string abbr): name(name), abbr(abbr) {};
        void setId(int id);
        int getId();
        ~Nation() {};
};