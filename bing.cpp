#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    uint32_t n_cases;
    cin >> n_cases;
    
    map<string,uint32_t> vocabulary;

    while (n_cases--) {
        
        map<string,uint32_t>::iterator i;

        string str;
        cin >> str;

        if ((i = vocabulary.find(str)) == vocabulary.end()) cout << "0\n";
        else cout << i->second << "\n";

        string builder = "";            
        for (char c : str) {
            builder += c;
            if ((i = vocabulary.find(builder)) == vocabulary.end()) {
                vocabulary[builder] = 1;
            } else {
                vocabulary[builder]++;
            }
        }

    }

    return EXIT_SUCCESS;
}