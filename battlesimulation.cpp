#include <iostream>
#include <vector>

using namespace std;

#define MAX_ATTACKS 1000000

int main() {

    string attack;
    cin >> attack;

    vector<char> response;
    response.reserve(MAX_ATTACKS);

    bool rFlag = false, bFlag = false, lFlag = false, go = false;
    char lastAttack = '#';

    for (char c : attack) {

        if (c == 'R') {
            go = !rFlag;
            rFlag = true;
            if (go && bFlag && lFlag) {
                response.pop_back();
                response.pop_back();
                response.push_back('C');
                rFlag = false;
                bFlag = false;
                lFlag = false;
                go = false;
            } else {
                if (c == lastAttack) {
                    lFlag = false;
                    bFlag = false;
                }
                response.push_back('S');
            }
        } else if (c == 'B') {
            go = !bFlag;
            bFlag = true;
            if (go && rFlag && lFlag) {
                response.pop_back();
                response.pop_back();
                response.push_back('C');
                rFlag = false;
                bFlag = false;
                lFlag = false;
                go = false;
            } else {
                if (c == lastAttack) {
                    lFlag = false;
                    rFlag = false;
                }
                response.push_back('K');
            }
        } else if (c == 'L') {
            go = !lFlag;
            lFlag = true;
            if (go && rFlag && bFlag) {
                response.pop_back();
                response.pop_back();
                response.push_back('C');
                rFlag = false;
                bFlag = false;
                lFlag = false;
                go = false;
            } else {
                if (c == lastAttack) {
                    rFlag = false;
                    bFlag = false;
                }
                response.push_back('H');
            }
        }

        lastAttack = c;

    }

    for (char c : response) {
        cout << c;
    }
    cout << "\n";

    return EXIT_SUCCESS;

}