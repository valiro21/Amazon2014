#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include "bug_class.cpp"

using namespace std;

int no_bugs = 0;
int starting_life, tower_range, tower_cost, rewards_per_bug, starting_money;
char harta[1000][1000];
int hartaN, hartaM;

ifstream fin("map.txt");

void read();
void read_first_values();
void read_chunk();
void read_bugs();
void read_harta();
void solve();

int main() {
  read();
  solve();
}

void read() {
  read_first_values();
  read_chunk();
  read_bugs();
  read_harta();
}

void read_first_values() {
  freopen("map.txt", "r", stdin);
  scanf("starting_life=%d\n", &starting_life);
  scanf("starting_money=%d\n", &starting_money);
  scanf("tower_range=%d\n", &tower_range);
  scanf("tower_cost=%d\n", &tower_cost);
  scanf("rewards_per_bug=%d\n", &rewards_per_bug);
}

void read_chunk() {
  char s[10000];

  fin.getline(s, 5000);
  fin.getline(s, 5000);
  fin.getline(s, 5000);
  fin.getline(s, 5000);
  fin.getline(s, 5000);

  fin.getline(s, 5000);
}

void read_bugs() {
  char bug[10000];

  while (true) {
    fin.getline(bug, 5000);

    if (bug[0] == '\0') { break; }
    ++no_bugs;
    char *p;
    p = strtok(bug, " ");

    Bug currentBug(p);

    for (p = strtok(NULL, " "); p != NULL; p = strtok(NULL, " ") )  {
      char *value_s = strchr(p, '=');
      ++value_s;
      int value = atoi(value_s);

      if (strstr(p, "frame=")) {
        currentBug.frame = value;
      } else {
        char color[1000], *aux2;
        strcpy(color, p);

        aux2 = strchr(color, '=');
        *aux2 = '\0';

        currentBug.setColor(color, value);
      }
    }
  }
}

void read_harta() {
  char line[10000];
  while (true) {
    fin.getline(line, 5000);

    if (line[0] == '\0') { break; }

    char *value;
    value = strtok(line, " ");
    ++hartaN;
    hartaM = 0;
    for (; value != NULL; value = strtok(NULL, " ")) {
      ++hartaM;
      harta[hartaN][hartaM] = (char)*value;
    }
  }
}

void solve() {
}
