#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"
#include "person.h"
using namespace std;


Person :: Person(string name, unsigned int wealth) : name{name}, wealth{wealth}{
    
    if(name.empty()) throw runtime_error("Name is empty");
}

void Person :: work(string guild) {
    if(eligible(guild)){
        licenses[guild]->use();
        this->work(licenses[guild]->get_salary());
        }
         else throw runtime_error ("Doesn't work");
         
}

void Person :: increase_wealth(unsigned int i) {wealth = wealth+i;}

string Person :: get_name() const {return name;}

bool Person :: pay_fee(unsigned int i) {
    if (wealth < i || i == 0) {return false;}
    else {
        wealth = wealth - i;
    }
    return true;
}

void Person :: receive_license(unique_ptr<License> l){
  
    if(this->licenses.count(l->get_guildname())){
        licenses.erase(l->get_guildname());
    }
    licenses.insert(make_pair(l->get_guildname(), move(l)));
}

void Person :: transfer_license(string l,shared_ptr<Person> p) {
    if(this->licenses.count(l) == 0) throw runtime_error ("Person doesn't have a license with name l.");
    if(licenses.count(l)){
        p->receive_license(move(this->licenses[l]));
        licenses.erase(l);
    }
}


bool Person :: eligible(string l) const{
    return (licenses.count(l)) && (licenses.at(l)->valid());
}

ostream& Person::print(ostream& o) const{
  bool first = true;
    o << name << ", " << wealth << " Coins, {";
    for(const auto& l : licenses) {
        if(first){
            o << *(l.second);
            first = false;
        }
        else
            o << ", " << *(l.second);
    }
    return o << "}]";
}



ostream& operator<< (ostream& o, const Person& p) {
    return p.print(o);
}

ostream& operator<< ( ostream& o, const Worker& w){
    return w.print(o);
}

ostream& operator<< (ostream& o, const Superworker& s){
    return s.print(o);
}
