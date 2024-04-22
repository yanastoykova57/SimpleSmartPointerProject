#ifndef LICENSE_H
#define LICENSE_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include"person.h"
using namespace std;
//class Person;

class License{
private:
string name;
unsigned int salary;
unsigned int counter;
public:
License(string name, unsigned int salary); // instance variables; name can't be empty, salary > 0 (throw runtime_error)
string get_guildname() const; // return name der Gilde
unsigned int get_salary() const; // return salary per task
bool valid() const; // true if max 3 Aufgaben are done, if not it's false
bool use();
ostream& print(ostream& o) const; // [License for name, Salary: ...., Used: ....]
};

ostream& operator<<(ostream& o, const License& l);
#endif
