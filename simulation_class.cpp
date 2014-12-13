#include <vector>
#include <cstdio>
#include <string>
#include <utility>

#include "bug_class.cpp"
#include "tower_class.cpp"

#define bugs_type vector <Bug>
#define towers_type vector <Tower>

using namespace std;

class Simulation {

public:
  static pair < pair<int, int>, bugs_type > simulate(bugs_type bugs, towers_type towers, int life, int money, int towerCost, int rewardPerBug) {

    int noBugs = bugs.size();
    int currentFrame = 0;

    while (noBugs > 0 && life > 0 && money >= 0) {
      // adauga towers noi
      // TODO: muta bugs
      // TODO: adauga bugs noi
      // ataca towers

      for (towers_type::iterator it = towers.begin(); it != towers.end(); ++it) {
        if ((*it).frame == currentFrame) {
          money -= towerCost;
          if (money < 0) {
            printf("Prea putini bani %d", currentFrame);
            // break this
          }
        }
      }

      for (towers_type::iterator it = towers.begin(); it != towers.end(); ++it) {
        for (vector<action>::iterator jt = (*it).actions.begin(); jt != (*it).actions.end(); ++jt) {
          if ((*jt).frame == currentFrame) {
            //get the bug
            //check if is in tower's range
            //make damage
            //scade damage
          }
        }
      }


      ++currentFrame;

    }

    return make_pair(
        make_pair( life, money ),
        bugs
        );
  }

};
