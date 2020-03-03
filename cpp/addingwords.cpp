#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string command;
    // these two vectors make the environment
    vector<int> values;
    vector<string> aliases;
    while (cin >> command) {
        if (command == "def") {
            string alias;
            int value;
            cin >> alias;
            cin >> value;
            ptrdiff_t pos = distance(aliases.begin(), find(aliases.begin(),aliases.end(),alias));
            if (pos < aliases.size()) {
                // re-defining
                aliases[pos] = alias;
                values[pos] = value;
            } else {
                aliases.push_back(alias);            
                values.push_back(value);
            }
        } else if(command == "calc") {
            vector<string> ops;
            vector<int> nums;
            string token, prompt = "";
            cin >> token;
            bool failure = false;
            while (token != "=") {
                prompt += (token + " ");
                if (token == "+" || token == "-") {
                    ops.push_back(token);
                } else {
                    ptrdiff_t pos = distance(aliases.begin(), find(aliases.begin(),aliases.end(),token));
                    if (pos >= aliases.size()) {
                        // not breaking here because we want the entire prompt
                        failure = true;
                    } else {
                        nums.push_back(values[pos]);
                    }
                }
                cin >> token;
            }
            if (!failure) {
                int result = nums[0];
                for (int i=0; i<ops.size(); ++i) {
                    if (ops[i] == "+") {
                        result += nums[i+1];
                    } else {
                        result -= nums[i+1];
                    }
                }
                ptrdiff_t pos = distance(values.begin(), find(values.begin(),values.end(),result));
                if (pos >= values.size()) {
                    cout << prompt + " = unknown" << endl;
                } else {
                    cout << prompt + " = " + aliases[pos] << endl;
                }
            } else {
                cout << prompt + " = unknown" << endl;                
            }
        } else if(command == "clear") {
            values.clear();
            aliases.clear();
        }
        // continue silently if the command is invalid
    }
    return EXIT_SUCCESS;
}