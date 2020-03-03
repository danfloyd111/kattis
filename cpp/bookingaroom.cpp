#include <iostream>
#include <random>
#include <bitset>

using namespace std;

int main() {

  int r, n;

  cin >> r >> n;

  if (n == 0) cout << "1" << endl;
  else if (n == r) cout << "too late" << endl;
  else {
    bitset<100> rooms;
    int tmp;
    for (int i=0; i<n; ++i) {
      cin >> tmp;
      tmp--;
      rooms[tmp] = true;
    }
    int room;
    if (n < r/2) {
      // using random approach
      random_device rd;
      mt19937 eng(rd());
      uniform_int_distribution<> distr(0,r-1);
      room = distr(eng);
      while (rooms[room]) room = distr(eng);
    } else {
      // using linear approach
      room=0;
      while (rooms[room] && room<r) room++;
    }
    cout << room+1 << endl;
  }

  return EXIT_SUCCESS;

}
