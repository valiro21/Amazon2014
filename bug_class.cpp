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
  string getName();
  bool isDead();
};

string Bug::getName() {
  return name;
}

bool Bug::isDead() {
  for (colors_type::iterator color = colors.begin(); color != colors.end(); ++color) {
    if (color->second > 0) {
      return false;
    }
  }
}
