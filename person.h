#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

class License;
class Person {
string name; // eindeutig
unsigned int wealth;
map<string, unique_ptr<License>> licenses; // map of licenses

public:
Person(string name, unsigned int wealth=0); // name isn't empty (runtime_error)
virtual ~Person() = default;
void work(string guild); // if lincense for guild and is valid, then the license is used and the person works for the salary of the license; no license or not valid (runtime_error)
virtual void work(unsigned int) = 0; // ++wealth;
void increase_wealth(unsigned int i); // wealth + i;
string get_name() const; // return name;
bool pay_fee(unsigned int i); // if wealth < i || i == 0 -> false; else wealth - i and return true
void receive_license(unique_ptr<License> l); // l is saved in the map of licenses of the person; if there's a license with this name already, the old license is deleted
void transfer_license(string l,shared_ptr<Person> p ); // look at sheet, too long
bool eligible(string l) const; // true if there's a license with name l && license is valid; else false
virtual ostream& print(ostream& o) const;

friend ostream& operator<<(ostream& o, const Person& p);
};


class Worker: public Person {
public:
    Worker(string name , unsigned int wealth=0) : Person (name, wealth) {}
    void work(string nnn){
        Person :: work(nnn);
    }
    void work(unsigned int i) {
    Person :: increase_wealth(i);
}
    ostream& print(ostream& o) const{
        o << "[Worker ";
        return Person ::print(o);
    }
};

class Superworker: public Person {
    unsigned int fee;
public:
    Superworker(unsigned int fee,string name,unsigned int wealth =0) : Person(name, wealth), fee{fee} {}
    void work(unsigned int i) {
        int newn = i+fee;
        Person::increase_wealth(newn);
    }
    ostream& print(ostream& o) const{
        o << "[Superworker ";
        return Person ::print(o);
    }
};

ostream& operator<< (ostream& o, const Worker& w);
ostream& operator<< (ostream& o, const Superworker& s);
ostream& operator<< (ostream& o, const Person& p);
#endif
