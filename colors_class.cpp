#include <string>
#include <vector>

using namespace std;


//pana la urma pot fi maxim 5 culori asa ca facem fara map



struct Color {
    string name;
    int value;

    Color(string name, int value) {
        this->name = name;
        this->value = value;
    }
};

//clasa Colors - Indicii culorilor incep de la 0
class Colors {
  private:
        vector<Color> colors;

  public:
    void setColor(string _color, int _value);
    int getColor(string _color);

    void setColor(int _color, int _value);
    int getColor(int _color);
};

void Colors::setColor(string _color, int _value) {
    for (int i = 0; i < colors.size (); i++)
        if (colors[i].name == _color) {
            colors[i].value = _value;
            return;
        }

   Color x(_color, _value);
   colors.push_back (x);
}

int Colors::getColor(string _color) {
    for (int i = 0; i < colors.size (); i++)
        if (colors[i].name == _color)
            return colors[i].value;
    return 0;
}


void Colors::setColor(int _color, int _value) {
    if (_color < colors.size ())
        colors[_color].value = _value;
}

int Colors::getColor(int _color) {
    if (_color < colors.size ())
        return colors[_color].value;
    return 0;
}
