// While playing an RPG game, you were assigned to complete one of the hardest quests in this game.
// There are n monsters you'll need to defeat in this quest. Each monster i is described with two integer
// numbers - poweri and bonusi. To defeat this monster, you'll need at least poweri experience points. If
// you try fighting this monster without having enough experience points, you lose immediately. You will
// also gain bonusi experience points if you defeat this monster. You can defeat monsters in any order.
// The quest turned out to be very hard - you try to defeat the monsters but keep losing repeatedly. Your
// friend told you that this quest is impossible to complete. Knowing that, you're interested, what is the
// maximum possible number of monsters you can defeat? (Question difficulty level: Hardest)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareRows(const vector<int>& a, const vector<int>& b) {
  return a[0] < b[0];
}

int main (int argc, char *argv[]) {
  int n = 0;
  cout << "Enter number of monsters : ";
  cin >> n; // get the number of monsters

  cout << "Enter initial experience : ";
  int xp;
  cin >> xp; // get initial experience

  vector<vector<int> > monsters(n, vector<int>(2, 0));

  for (int i = 0; i < n; i++) {
    cout << "Enter power of monster " << i+1 << " : ";
    int power = 0;
    cin >> power;
    monsters[i][0] = power;
  }

  for (int i = 0; i < n; i++) {
    cout << "Enter bonus of monster " << i+1 << " : ";
    int bonus = 0;
    cin >> bonus;
    monsters[i][1] = bonus;
  }

  sort(monsters.begin(), monsters.end(), compareRows);

  int res = 0;

  for (int i = 0; i < n; i++) {
    if (monsters[i][0] > xp) {
      break;
    }

    res++;
    xp += monsters[i][1];
  }

  cout << "The number of monsters defeated : " << res << endl;

  return 0;
}
