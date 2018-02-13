#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n, m;
  vector<string> dictionary, plates;

  cin >> n >> m;

  for (int i=0; i<n; ++i) {
    string temp;
    cin >> temp;
    dictionary.push_back(temp);
  }

  for (int i=0; i<m; ++i) {
    string temp;
    cin >> temp;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    plates.push_back(temp);
  }

  for (string plate : plates) {
    auto p0 = plate.at(0);
    auto p1 = plate.at(1);
    auto p2 = plate.at(2);
    bool found = false;
    for (string word : dictionary) {
      auto pos0 = word.find(p0);
      if (pos0 == string::npos) continue;
      auto pos1 = word.find(p1, pos0+1);
      if (pos1 == string::npos) continue;
      auto pos2 = word.find(p2, pos1+1);
      if (pos2 == string::npos) continue;
      cout << word << endl;
      found = true;
      break;/*
      if (pos0 != string::npos && pos1 != string::npos && pos2 != string::npos) {
        cout << word << endl;
        found = true;
        break;
      }*/
    }
    if (!found) cout << "No valid word" << endl;
  }
  return EXIT_SUCCESS;

}
