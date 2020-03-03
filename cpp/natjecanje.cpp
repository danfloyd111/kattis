#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> reserves, broken, kayaks;
  
  int n, s, r, count = 0;
  cin >> n >> s >> r;
  
  for (int i = 0; i < s; ++ i) {
    int tmp;
    cin >> tmp;
    broken.push_back(tmp);
  }

  for (int i = 0; i < r; ++ i) {
    int tmp;
    cin >> tmp;
    reserves.push_back(tmp);
  }

  for (int b : broken) {
    vector<int>::iterator it = reserves.begin();
    bool found = false;
    while (it != reserves.end() && !found) {
      if (*it - 1 == b || *it + 1 == b) {
	it = reserves.erase(it);
	found = true;
      } else {
	++ it;
      }
    }
    if (!found) {
      ++ count;
    }
  }

  cout << count << "\n";
  
  return EXIT_SUCCESS;

}
