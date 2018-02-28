#include <iostream>
#include <vector>

using namespace std;

int main() {
    long x, i=2, target, points=0;
    cin >> x;
    target = x;
    while (i*i<=target) {
        if (target%i == 0) {
            target /= i;
            ++points;
        } else {
            ++i;
        }
    }
    ++points;
    cout << points << endl;
    return EXIT_SUCCESS;
}