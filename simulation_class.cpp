#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <map>

#include "bug_class.cpp"
#include "tower_class.cpp"

#define result_type pair < pair<int, int>, bugs_type >

using namespace std;

class Simulation {
private:
  bugs_type bugs;
  towers_type towers;

  map <string, Bug*> bugsCache;

  int life;
  int money;
  int towerCost;
  int towerRange;
  int rewardPerBug;

  int currentFrame;
  int noBugsAlive;
  void tick();

public:
  Simulation(bugs_type _bugs, towers_type _towers, int _life, int _money, int _towerCost, int _towerRange, int _rewardPerBug) {
    bugs = _bugs;
    towers = _towers;
    life = _life;
    money = _money;
    towerCost = _towerCost;
    towerRange = _towerRange;
    rewardPerBug = _rewardPerBug;

    currentFrame = 0;
    noBugsAlive = bugs.size();

    // caching bugs
    for (bugs_type::iterator bug = bugs.begin(); bug != bugs.end(); ++bug) {
      bugsCache[(*bug).getName()] = &(*bug);
    }
  }

  result_type next(int noFrames);
  result_type finish();
  bool isFinished();
};

result_type Simulation::next(int noFrames) {
  for (; noFrames && !isFinished(); --noFrames) {
    tick();
  }

  return make_pair(
      make_pair(life, money),
      bugs
      );
}

result_type Simulation::finish() {
  return next(1000000);
}

bool Simulation::isFinished() {
  if (life < 1) {
    printf("Ai ramas fara viata");
    return true;
  }

  if (noBugsAlive == 0) {
    return true;
  }

  if (money < 0) {
    printf("Prea putini bani");
    return true;
  }

  return false;
}

void Simulation::tick() {
  // adauga towers noi
  // TODO: muta bugs
  //   daca ajung pe X trebuie sa faca damage
  // ataca towers

  for (towers_type::iterator tower = towers.begin(); tower != towers.end(); ++tower) {
    if ((*tower).frame == currentFrame) {
      money -= towerCost;
      if (money < 0) {
        printf("Prea putini bani %d", currentFrame);
        return;
      }
    }
  }

  for (towers_type::iterator tower = towers.begin(); tower != towers.end(); ++tower) {
    for (vector<action>::iterator jt = (*tower).actions.begin(); jt != (*tower).actions.end(); ++jt) {
      if ((*jt).frame == currentFrame) {
        Bug *bug = bugsCache[(*jt).bugName];

        if (bug->isDead()) break;

        //check if is in tower's range

        life -= bug->substractColors( (*tower).colors );
        noBugsAlive -= bug->isDead();
        if (life < 1) {
          printf("Ai ramas fara viata %s", *bug->getName().c_str());
        }
        break;
      }
    }
  }

  ++currentFrame;
}


