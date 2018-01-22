#include <iostream>

using namespace std;

int main() {

    char names[] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7'};
    int dominant[] = {11, 4, 3, 20, 10, 14, 0, 0};
    int not_dominant[] = {11, 4, 3, 2, 10, 0, 0, 0};

    int times;
    cin >> times;

    char suit;
    cin >> suit;

    int points = 0;
    
    for (int i=0; i<4*times; ++i) {
	string line;
	cin >> line;
	char name = line[0];
	char s = line[1];
	int index = 0;
	for (char n : names) {
	    if (n == name)
		break;
	    index ++;
	}
	if (s == suit)
	    points += dominant[index];
	else
	    points += not_dominant[index];
    }

    cout << points << "\n";
    
    return EXIT_SUCCESS;

}
