#include <iostream>
#include <string>

using namespace std;

int main() {
  string input_a, input_b;
  for ( ; cin >> input_a >> input_b; ) cout << abs(stol(input_a) - stol(input_b)) << endl;
  return EXIT_SUCCESS;
}
