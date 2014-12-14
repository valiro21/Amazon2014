#include <string>
#include "colors_class.cpp"

#define bugs_type vector <Bug>

using namespace std;

class Bug : public Colors {
  private:
  string name;

  public:
  Bug(string _name) {
    name = _name;
  }

  int frame;
  const char* getName();
};

const char* Bug::getName() {
  return name.c_str();
}

