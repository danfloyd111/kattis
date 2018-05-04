#include <vector>
#include <iostream>
#include <numeric>
#include <math.h>

using namespace std;

int main() {
    int n;
    vector<int> proper_divs;
    while (cin >> n) {
        proper_divs.clear();
        proper_divs.push_back(1);
        int s = (int) sqrt(n) + 1;
        for (int i = 2; i < s; ++i) {
            if (n % i == 0) {
                int num = n / i;
                if (i != num)
                    proper_divs.push_back(num);
                proper_divs.push_back(i);
            }
        }
        int sum = accumulate(proper_divs.begin(), proper_divs.end(), 0);
        if (sum == n) {
            cout << n << " perfect\n";
        } else if (sum >= n-2 && sum <= n+2) {
            cout << n << " almost perfect\n";
        } else {
            cout << n << " not perfect\n";
        }
    }
    return EXIT_SUCCESS;
}