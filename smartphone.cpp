#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int calculateCost(string target, string suggestion) {
    int len = target.length() > suggestion.length() ? target.length() : suggestion.length();
    int i = 0;
    bool stop = false;
    while (i < len && !stop) {
        if (target[i] == suggestion[i]) {
            ++ i;
        } else {
            stop = true;
        }
    }
    int invalid = suggestion.length() - i;
    int valid = suggestion.length() - invalid;
    int toAdd = target.length() - valid;
    return invalid + toAdd;
}

int main() {

    int testCases, c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    string target, s0, s1, s2, s3;

    cin >> testCases;

    while (testCases --) {

        cin >> target >> s0 >> s1 >> s2 >> s3;

        c0 = calculateCost(target, s0); 
        c1 = calculateCost(target, s1) + 1;
        c2 = calculateCost(target, s2) + 1;
        c3 = calculateCost(target, s3) + 1;

        cout << min(min(c0, c1), min(c2, c3)) << "\n";
    }

    return EXIT_SUCCESS;

}