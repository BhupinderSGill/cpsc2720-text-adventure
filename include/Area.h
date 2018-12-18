#ifndef AREA_H
#define AREA_H

#include "Inventory.h"
using namespace std;

class Area {
private:
   Inventory inventory;
public:
   Area();
   virtual Area* run() = 0;
   virtual void init();
};

#endif
