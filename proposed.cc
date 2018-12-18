//Rejected by the author

#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

/* Pseudocode
bool testReorder() {
   string s = //some input;
      last label
      while (getlinefroms) {
	 scan line for [ symbol. get text betwen it and ] symbol.
	 compare that text to last label. If it is small return false
	 If it was larger return true (working)
      }
      }
*/
struct Interest {
   int start;
   int crit;
   int end;
   string text;
   string option;
   Interest (int a=0, int b=-1, int c=0, string z="", string y="")
      : start{a}, crit{b}, end{c}, text{z}, option{y}
   {}
   bool operator< (const Interest& a) const {
      return option < a.option;
   }
};

bool processLine(string& s, int& i, vector<Interest>& interest) {
   Interest build{i};
   for (; i < s.size() && s[i] != '\n'; ++i) {
      if (s[i] == '[') {
	 build.crit = i;
	 build.text += s[i];
	 ++i;
	 for (; s[i] != ']'; ++i) {
	    build.option += s[i];
	    build.text += s[i];
	 }
      }
      build.text += s[i];
   }
   build.end = i;
   if (build.crit != -1)
      interest.push_back(build);
   return build.end != s.size();
}

void reorder(string& s) {
   int i = 0;
   vector<Interest> line;
   while (processLine(s, i, line));
   vector<Interest> unsorted{line.size()};
   copy(line.begin(), line.end(), unsorted.begin());
   sort(line.begin(), line.end());
   for (int i = 0; i < line.size(); ++i) {
      int spot = unsorted[i].start;
      s.erase(spot, unsorted[i].end);
      s.insert(spot, line[i].text);
   }
}

int main() {
   return 0;
}
