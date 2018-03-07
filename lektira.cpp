#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string word;
    cin >> word;

    string min = "";

    // using brute force

    for (int f_cut = 1; f_cut < word.length() - 1; ++f_cut) {
        for (int s_cut = f_cut + 1; s_cut < word.length(); ++s_cut) {
            string f_tok = word.substr(0, f_cut),
                   s_tok = word.substr(f_cut, s_cut - f_cut),
                   t_tok = word.substr(s_cut, word.length() - s_cut);
            reverse(f_tok.begin(), f_tok.end());
            reverse(s_tok.begin(), s_tok.end());
            reverse(t_tok.begin(), t_tok.end());
            string res = f_tok.append(s_tok.append(t_tok));
            if (min == "" || min.compare(res) > 0) min = res;         
        }
    }

    cout << min << endl;

    return EXIT_SUCCESS;
}