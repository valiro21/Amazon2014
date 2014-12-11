#include <map>
#include <string>

using namespace std;

class Colors {

  private:
    map <string, int> colors;

  public:
    void setColor(string color, int value);
    int getColor(string color);

};

void Colors::setColor(string color, int value) {
  colors[color] = value;
}

int Colors::getColor(string color) {
  return colors[color];
}
