#include <iostream>
#include <vector>
#include <sstream>

#define STAFF_LIMIT 14
#define NOTES_LIMIT 100

using namespace std;

int main() {

    int n;
    vector<char> notes;

    vector<vector<char>> chart;

    cin >> n;

    for (int i = 0; i < n; ++ i) {

        string code;
        cin >> code;

        char note = code[0];

        int rep = 1;
        if (code.size() > 1) {
            code.erase(0, 1);
            stringstream ss(code);
            ss >> rep;
        }

        while (rep --) {
            notes.push_back(note);
        }

    }

    return 0;

}
