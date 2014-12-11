#include <string>
#include "colors_class.cpp"

using namespace std;

class Bug : public Colors {
  private:
  string name;

  public:
  Bug(string name) {
    this -> name = name;
  }

  int frame;
  const char* getName();
};

const char* Bug::getName() {
  return this -> name.c_str();
}
