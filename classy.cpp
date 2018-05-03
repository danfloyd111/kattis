#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum t_class {
    lower,
    middle,
    upper
};

vector<string> tokenizer(string chain) {
    string delimiter = "-";
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while((pos=chain.find(delimiter)) != string::npos) {
        token = chain.substr(0, pos);
        tokens.push_back(token);
        chain.erase(0, pos + delimiter.length());
    }
    tokens.push_back(chain);
    return tokens;
}

int sort_class(t_class c1, t_class c2) {
    if (c1 > c2)
        return 1;
    if (c1 < c2)
        return -1;
    return 0;
}

t_class string_to_t_class(string s) {
    if (s=="upper")
        return upper;
    if (s=="middle")
        return middle;
    return lower;
}

bool sort_pairs(pair<string,string> p1, pair<string,string> p2) {
    vector<string> t1 = tokenizer(p1.second);
    vector<string> t2 = tokenizer(p2.second);
    reverse(t1.begin(),t1.end());
    reverse(t2.begin(),t2.end());
    int i=0;
    while (i<t1.size() && i<t2.size()) {
        int res = sort_class(string_to_t_class(t1[i]),string_to_t_class(t2[i]));
        if (res == 1) return true;
        if (res == -1) return false;
        ++i;
    }
    return p1.first.compare(p2.first) < 0;
}

int main() {
    int n_cases;
    cin >> n_cases;
    while (n_cases--) {
        vector<pair<string,string>> pairs;        
        int n_lines;
        cin >> n_lines;
        while (n_lines--) {
            string name;
            cin >> name;
            string chain;
            cin >> chain;
            string discard;
            cin >> discard;
            name = name.substr(0,name.size()-1); // eliminate trailing ':'
            pair<string,string> p (name,chain);
            pairs.push_back(p);
        }        
        sort(pairs.begin(), pairs.end(), sort_pairs);
        for (pair<string,string> p : pairs) {
            cout << p.first << "\n";
        }
        for (int i=0; i<30; ++i) {
            cout << "=";
        }
        cout << "\n";
    }
    return EXIT_SUCCESS;
}