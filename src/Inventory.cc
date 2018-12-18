/**
* @file Inventory.cc
* @brief Implementation file for game inventory functions
*
* @author Legendary Council
*
* @date 3/11/2017
*/
#include "../include/Inventory.h"
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
Inventory::Inventory()
: sto{}
{
}

//-----------------------------------------------------------------------------
bool Inventory::check(string item){
    if (item.empty() || item[0] != '!')
        return sto[item];
    else {
        return !sto[item.substr(1, item.size() - 1)];
    }
}
//-----------------------------------------------------------------------------
void Inventory::add(string item){
    sto[item] = true;
}
//-----------------------------------------------------------------------------
void Inventory::forget(string item) {
    sto[item] = false;
}
//-----------------------------------------------------------------------------
void Inventory::print() {
    for (auto i = sto.begin(); i != sto.end(); ++i) {
        if (i->second)
            cout << i->first << endl;
    }
}
//-----------------------------------------------------------------------------
void Inventory::save(ostream& out) {
    for(auto i = sto.begin(); i != sto.end(); ++i){
        if (i->second)
            out << i->first << endl;
    }
}
//-----------------------------------------------------------------------------
void Inventory::load(istream& in) {
    string item;
    while (in >> item && !in.eof()) {
        add(item);
    }
}
//-----------------------------------------------------------------------------
void Inventory::clear() {
    sto = map<string, bool>{};
}

bool Inventory::checkSuccessfulGame()
{
    int winner=0;
    int cutoff;
    if(this->check("Petition") == false) return false;
    if(this->check("Documents")) cutoff = 2;
    else cutoff = 4;
    if(this->check("BhupinderSignature")) winner++;
    if(this->check("JuliusSignature")) winner++;
    if(this->check("ParanoiaSignature")) winner++;
    if(this->check("KolodySignature")) winner++;
    if(this->check("CramerSignature")) winner++;
    if(this->check("HippySignature")) winner++;
    if(this->check("ParanoiaMotherSignature")) winner++;
    if(this->check("ConvinceConstructionWorker")) winner++;

    if(winner>=cutoff) return 1;
    else return 0;
}
