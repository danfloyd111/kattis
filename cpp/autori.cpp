#include <iostream>

using namespace std;

int main() {

    string autori;
    cin >> autori;

    cout << autori[0];
    int index = 0;

    for (char c : autori) {
	if (c == '-')
	    cout << autori[index+1];
	index ++;
    }

    cout << "\n";

    return EXIT_SUCCESS;

}
