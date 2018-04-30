#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n_cases;
    cin >> n_cases;
    while (n_cases) {
        int n, m, max_weight = -1;
        vector<int> sequence;
        cin >> n >> m;
        for (int i=0; i<n; ++i) {
            int tmp;
            cin >> tmp;
            sequence.push_back(tmp);
        }
        
        for (int i=0; i<n; ++i) {
            if (sequence[i] == m) {
                int tmp_weight = m;
                for (int j=i-1; (j>=0) && (sequence[j]>m); --j)
                    tmp_weight += sequence[j];
                for (int j=i+1; (j<sequence.size()) && (sequence[j]>m); ++j)
                    tmp_weight += sequence[j];     
                if (tmp_weight > max_weight) max_weight = tmp_weight;
            }
        }

        cout << max_weight << endl;

        --n_cases;
    }
    return EXIT_SUCCESS;
}