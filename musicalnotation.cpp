#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {

    int n;
    vector<char> notes;

    map<char,string> chart = {
        { 'G', "" },
        { 'F', "" },
        { 'E', "" },
        { 'D', "" },
        { 'C', "" },
        { 'B', "" },
        { 'A', "" },
        { 'g', "" },
        { 'e', "" },
        { 'f', "" },
        { 'd', "" },
        { 'c', "" },
        { 'b', "" },
        { 'a', "" },
    };

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

        notes.push_back('.');

    }

    notes.pop_back();

    for (char c : notes) {
        for (pair<char,string> entry : chart) {
            switch (entry.first) {
                // whitespace
                case 'G':
                case 'E':
                case 'C':
                case 'A':
                case 'f':
                case 'd':
                case 'c':
                case 'b': {
                    string s = entry.second + " ";
                    entry.second = s;
                    break;
                }
                // dash
                case 'e':
                case 'g':
                case 'B':
                case 'D':
                case 'F':
                // valid for 'a'
                default: {
                    string s = entry.second + "-";
                    entry.second = s;
                }
            }
        }
        if (c != '.') {
            string s = chart[c];
            s[s.size()-1] = '*';
            chart[c] = s;
        }
    }

    for (pair<char,string> entry : chart) {
        cout << entry.first << ":" << entry.second << "\n";
    }

//    for (char c : notes) { cout << c << endl; } // DEBUG

    return 0;

}
