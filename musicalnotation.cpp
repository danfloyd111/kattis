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
            if (c == entry.first) {
                chart[c] += "*";
            } else {
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
                        chart[entry.first] += " ";
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
                        chart[entry.first] += "-";
                    }
                }
            }
        }
    }


    // we have to display the chart in a particular order
    cout << "G: " << chart['G'] << "\n";
    cout << "F: " << chart['F'] << "\n";
    cout << "E: " << chart['E'] << "\n";
    cout << "D: " << chart['D'] << "\n";
    cout << "C: " << chart['C'] << "\n";
    cout << "B: " << chart['B'] << "\n";
    cout << "A: " << chart['A'] << "\n";
    cout << "g: " << chart['g'] << "\n";
    cout << "f: " << chart['f'] << "\n";
    cout << "e: " << chart['e'] << "\n";
    cout << "d: " << chart['d'] << "\n";
    cout << "c: " << chart['c'] << "\n";
    cout << "b: " << chart['b'] << "\n";
    cout << "a: " << chart['a'] << "\n";

    return EXIT_SUCCESS;

}
