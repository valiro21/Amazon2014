#include "colors_class.cpp";
#include <vector>
#include <string>

#define towers_type vector <Tower>

using namespace std;

struct action { int frame; string bugName; };

class Tower : public Colors {
  public:
    int frame = 1;

    vector <action> actions;
};
