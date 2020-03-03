#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

inline int t_eval(int left, char opr, int right) {
  switch (opr) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
    default : exit(EXIT_FAILURE);
  }
}

int main() {
  map<int, string> results_map;
  vector<char> ops {'+', '-', '*', '/'};
  char slot1, slot2, slot3;
  for (auto op : ops) {
    slot1 = op;
    for (auto op : ops) {
      slot2 = op;
      for (auto op : ops) {
        slot3 = op;
        vector<int> operands {4,4,4,4};
        vector<char> slots {slot1, slot2, slot3};
        for (int i=0; i<slots.size(); ++i) {
          if (slots[i] == '*' || slots[i] == '/') {
            operands[i] = t_eval(operands[i], slots[i], operands[i+1]);
            operands.erase(operands.begin()+i+1);
            slots.erase(slots.begin()+i);
            --i;
          }
        }
        for (int i=0; i<slots.size(); ++i) {
          operands[i] = t_eval(operands[i], slots[i], operands[i+1]);
            operands.erase(operands.begin()+i+1);
            slots.erase(slots.begin()+i);
            --i;
        }
        string expr = "4 " + string(1,slot1) + " 4 " + string(1,slot2) + " 4 " + string(1,slot3) + " 4 = " + to_string(operands[0]);
        results_map[operands[0]] = expr;
      }
    }
  }

  int n_cases;
  cin >> n_cases;
  while (n_cases) {
    int query;
    string result;
    cin >> query;
    cout << ((results_map.find(query) == results_map.end()) ? "no solution" : results_map[query]) << endl;
    --n_cases;
  }

  return EXIT_SUCCESS;
}  