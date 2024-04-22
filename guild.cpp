#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include<map>
#include "guild.h"
#include "license.h"
#include "person.h"

Guild :: Guild(string name, unsigned fee, unsigned salary, const vector<shared_ptr<Person>>& members): name{name}, fee {fee}, salary{salary} {
    if(name.empty() || salary <= 0 || fee <= 0) throw runtime_error("err");
    
    
    for(const auto& x: members) {
        if (this->members.count((*x).get_name()) == 0)
          this->members.insert(pair<string, shared_ptr<Person>>((*x).get_name(),x));
          else throw runtime_error("err");
      }
}

bool Guild :: add_member(shared_ptr<Person> p){
    for(const auto& i: members){
        if (i.first== p->get_name()) return false;
    }
    
    members.insert(pair<string, shared_ptr<Person>>(p->get_name(),p));
    return true;
}

bool Guild :: remove_member(string n){
    for(const auto& i: members){
        if(i.first == n){
            members.erase(n);
            return true;
        }
    }
    return false;
}

void Guild :: grant_license(string n){
    if(members.count(n) == 0 ) throw runtime_error("NO");
    
    for(auto it = members.begin(); it != members.end(); ++it){
        if((it->first == n && it->second->pay_fee(fee))){
            it->second->receive_license(make_unique<License>(name, salary));
              return;
        }
    }throw runtime_error("err");
}

bool Guild:: offer_job(shared_ptr<Person>p) const{
    if(members.count(p->get_name())){
        p->work(salary*2);
        return true;
    }
    else if(p->eligible(this->name)){
        p->work(this->name);
        return true;
    }
    return false;
}

ostream& Guild :: print(ostream& o) const {
      bool first = true;
    o<< "["<< name<< ", License fee: " << fee << ", Job salary: " << salary << ", {";
    for(auto it = this->members.begin(); it != this->members.end(); ++it){
        if(first){
        o<< it->first;
           first = false;
        } else o << ", " << it->first;
    }
    o<<"}]";
    return o;
}

ostream& operator << (ostream& o, const Guild& g) {return g.print(o);}
