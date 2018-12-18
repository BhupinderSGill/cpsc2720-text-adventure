#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
using namespace std;

Event {
  private:
   string file;
   vector<Text> activity;
  public:
   Event ();

  private:
   void open(string);
   string getTag(istream&);
   string run();
}

#endif
