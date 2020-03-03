#include <iostream>
#include <vector>

using namespace std;

int main() {

  int lines = 1;
  bool firstrun = true;

  while (lines) {
    string inl;
    getline(cin, inl);
    lines = stoi(inl);
    if (lines) {
      if (!firstrun) cout << endl;
      firstrun = false;
      vector<int> numpixels;
      for (int i=0; i<lines; ++i) {
        string line;
        getline(cin, line);
        vector<string> tokens;
        size_t pos=0, found;
        while ((found=line.find_first_of(' ',pos)) != string::npos) {
          tokens.push_back(line.substr(pos, found - pos));
          pos = found+1;
        }
        tokens.push_back(line.substr(pos));
        string imageline = "";
        int sum = 0;
        if (tokens[0]=="#") {
          for (int j=1; j<tokens.size(); ++j) {
            int num = stoi(tokens[j]);
            sum += num;
            if (j%2 == 1) {
              string chunk(num, '#');
              imageline += chunk;
            } else {
              string chunk(num, '.');
              imageline += chunk;
            }
          }
        } else {
          for (int j=1; j<tokens.size(); ++j) {
            int num = stoi(tokens[j]);
            sum += num;
            if (j%2 == 1) {
              string chunk(num, '.');
              imageline += chunk;
            } else {
              string chunk(num, '#');
              imageline += chunk;
            }
          }
        }
        cout << imageline << endl;
        numpixels.push_back(sum);
      }
      int val = numpixels[0];
      for (int v : numpixels) {
        if (v!=val) {
          cout << "Error decoding image" << endl;
          break;
        }
      }
      numpixels.clear();
    }
  }

  return EXIT_SUCCESS;

}
