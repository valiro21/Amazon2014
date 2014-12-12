#include <vector>

using namespace std;

class power2 {
private:
    vector<int> bits;
    int value;
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

    int operator[](int _index) {
        if (_index<bits.size ())
            return bits[_index];
        return 0;
    }

    void ponderate (vector<int> _back) {

    }
};
