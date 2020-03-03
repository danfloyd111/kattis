#include <iostream>

using namespace std;

int main() {

    int n, p;
    cin >> n >> p;

    string foo;
    while (n > 0) {
	cin >> foo;
	n--;
    }

    cout << p << "\n";

    return EXIT_SUCCESS;

}
