#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"

using namespace std;

License :: License(string name, unsigned int salary): name {name}, salary {salary},counter {0} {
    if(name.empty() || salary <= 0) throw runtime_error("Not allowed!");
}

string License :: get_guildname() const {return name;}

unsigned int License :: get_salary() const {return salary;}

bool License :: valid() const {
    return counter <= 3;
}

bool License :: use(){
    if(valid() == false) return false;
    else if (valid() == true){
        ++counter;
        }
    return true;
}

ostream& License :: print(ostream& o) const {
    o << "[License for " << name << ", Salary: " << salary << ", Used: " << counter << "]";
    return o;
}

ostream& operator<<(ostream& o, const License& l) {
    return l.print(o);
}
