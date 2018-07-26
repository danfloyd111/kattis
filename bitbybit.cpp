#include <iostream>
#include <string>

#define CAPACITY 32

using namespace std;

int main() {

    int lines;

    while (cin >> lines && lines) {
        
        char reg[CAPACITY];

        for (int i = 0; i < CAPACITY; ++ i) {
            reg[i] = '?';
        }

        while (lines --) {

            string instruction;
            int i, j;

            cin >> instruction;

            if (instruction == "SET") {
                cin >> i;
                i = CAPACITY - 1 - i;
                reg[i] = '1';
            } else if (instruction == "CLEAR") {
                cin >> i;
                i = CAPACITY - 1 - i;
                reg[i] = '0';
            } else if (instruction == "AND") {
                cin >> i >> j;
                i = CAPACITY - 1 - i;
                j = CAPACITY - 1 - j;
                if (reg[i] == '0' || reg[j] == '0') {
                    reg[i] = '0';
                } else if (reg[i] == '1' && reg[j] == '1') {
                    reg[i] = '1';
                } else {
                    reg[i] = '?';
                }
            } else {
                // instruction == "OR"
                cin >> i >> j;
                i = CAPACITY - 1 - i;
                j = CAPACITY - 1 - j;
                if (reg[i] == '1' || reg[j] == '1') {
                    reg[i] = '1';
                } else if (reg[i] == '0' && reg[j] == '0') {
                    reg[i] = '0';
                } else {
                    reg[i] = '?';
                }
            }
        }

        for (int i = 0; i < CAPACITY; ++ i) {
            cout << reg[i];
        }

        cout << "\n";

    }

    return EXIT_SUCCESS;

}
