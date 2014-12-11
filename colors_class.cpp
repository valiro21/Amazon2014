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
    void setColor(string ColorName, int value);
    int getColor(string ColorName);

    void setColor(int ColorName, int value);
    int getColor(int ColorName);
};

void Colors::setColor(string ColorName, int value) {
    for (int i = 0; i < colors.size (); i++)
        if (colors[i].name == ColorName) {
            colors[i].value = value;
            return;
        }

   Color x(ColorName, value);
   colors.push_back (x);
}

int Colors::getColor(string ColorName) {
    for (int i = 0; i < colors.size (); i++)
        if (colors[i].name == ColorName)
            return colors[i].value;
    return 0;
}


void Colors::setColor(int Color, int value) {
    if (Color < colors.size ())
        colors[Color].value = value;
}

int Colors::getColor(int Color) {
    if (Color < colors.size ())
        return colors[Color].value;
    return 0;
}
