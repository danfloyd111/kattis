#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string line;
    cin >> line;
    
    double n_space = 0.0,
           n_lowercase = 0.0,
           n_uppercase = 0.0,
           n_symbols = 0.0;
    
    for (char c : line) {
        if (c == 95) {
            ++n_space;
        } else if ((c > 32 && c < 65) ||
                   (c > 90 && c < 97) ||
                   (c > 122)) {
            ++n_symbols;
        } else if (c > 64 && c < 91) {
            ++n_uppercase;
        } else if (c > 96 && c < 123) {
            ++n_lowercase;
        }
    }
    
    cout << (n_space / line.length()) << "\n";
    cout << (n_lowercase / line.length()) << "\n";
    cout << (n_uppercase / line.length()) << "\n";
    cout << (n_symbols / line.length()) << "\n";
    
    return EXIT_SUCCESS;
    
}