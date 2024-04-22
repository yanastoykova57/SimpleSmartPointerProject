#ifndef GUILD_H
#define GUILD_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include"license.h"
#include"person.h"
using namespace std;


class Guild{

private:
string name;
unsigned int fee;
unsigned int salary;
map<string, shared_ptr<Person>> members;

public:
Guild(string name, unsigned fee, unsigned salary, const vector<shared_ptr<Person>>& members = {});
bool add_member(shared_ptr<Person> p); //adds p to members if it's not already there
bool remove_member(string n);
void grant_license(string n);
bool offer_job(shared_ptr<Person>p) const;
ostream& print(ostream& o) const;
};

ostream& operator << (ostream& o, const Guild& g);



#endif
