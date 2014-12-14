#include <string>
#include <map>

#define colors_type map <string, int>


using namespace std;

class Colors {
  public:
    colors_type colors;

    void setColor(string _color, int _value);
    int getColor(string _color);
    int substractColors(colors_type variabila);
};

void Colors::setColor(string _color, int _value) {
  colors[_color] = _value;
}

int Colors::getColor(string _color) {
    return colors[_color];
}

int Colors::substractColors(colors_type scazator) {
  int diff = 0;

  for(colors_type::iterator color=colors.begin(); color != colors.end(); ++color) {
    int v1 = color->second;
    int v2 = scazator[color->first];

    if (v1-v2 < 0) diff += v2-v1;
    color->second -= v2;
  }

  return diff;
}


