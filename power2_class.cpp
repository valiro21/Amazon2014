#include <vector>

using namespace std;

class power2 {
private:
    vector<int> bits;
public:
    power2 () {
        bits.push_back (0);
    }

    power2 (int x) {
        while (x) {
            bits.push_back (x % 2);
            x /= 2;
        }
    }

    int operator[](int index) {
        if (index<bits.size ())
            return bits[index];
        return 0;
    }

    void ponderate () {

    }
};
