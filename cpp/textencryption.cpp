#include <iostream>

using namespace std;

inline string shrink(const string& s) {
    string res = "";
    for (char c : s) if (c != ' ') res += toupper(c);
    return res;
}

int main() {
    string in;
    getline(cin,in);
    int n = stoi(in);
    while (n) {
        string message, shrinked, secret = "";
        int i = 0, c = 0;
        getline(cin, message);
        shrinked = shrink(message);
        if (n > shrinked.length()) secret = shrinked;
        else {
            secret = string(shrinked);
            while (c < n && i < shrinked.length()) {
                int j = c;
                while (j < shrinked.length()) {
                    secret[j] = shrinked[i];
                    j += n;
                    ++ i;
                }
                ++ c;
            }
        }
        cout << secret << endl;
        getline(cin,in);
        n = stoi(in);
    }
    return EXIT_SUCCESS;
}