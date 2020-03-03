#include <iostream>

using namespace std;

int main() {

    long n, k, q, gap;
    cin >> n >> k >> q;
    gap = k-2;

    long n1, n2;
    while (q) {
        long distance = 0;
        cin >> n1 >> n2;
        if (n1 == n2) cout << "0" << endl;
        else if (k == 1) cout << abs(n1-n2) << endl;
        else {
            while (n1 != n2) {
                if (n1 > n2) {
                    n1 = (n1+gap) / k;
                    ++distance;
                } else {
                    n2 = (n2+gap) / k;
                    ++distance;
                }
            }
            cout << distance << endl;
        }
        --q;
    }

    return EXIT_SUCCESS;
}