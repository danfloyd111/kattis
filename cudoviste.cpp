#include <iostream>
#include <vector>

using namespace std;

/*
 * Returns number of car smashed while parking on pos gived front line
 * fline and back line bline. Returns values from -1 (if parking is
 * impossible) to 4.
*/
int canPark(int pos, const string fline, const string bline);

int main() {

    int r, c;
    cin >> r >> c;

    vector<string> rows;
    for (int i=0; i<r; ++i) {
        string line;
        cin >> line;
        rows.push_back(line);
    }

    int results[5] = {};

    for (int i=0; i<r-1; i++) {
        for (int j=0; j<c-1; j++) {
            int n_smashed = canPark(j, rows[i], rows[i+1]);
            if (n_smashed>-1)
                results[n_smashed] ++;
        }
    } 
    
    for (int r : results) cout << r << "\n";

    return EXIT_SUCCESS;

}

int canPark(int pos, const string fline, const string bline) {
    
    char loc;
    int smashed_cars = 0;
    
    for (int i=0; i<2; ++i) {
        loc = fline[pos+i];
        if (loc == '#')
            return -1;
        if (loc == 'X')
            smashed_cars ++;
    }

    for (int i=0; i<2; ++i) {
        loc = bline[pos+i];
        if (loc == '#')
            return -1;
        if (loc == 'X')
            smashed_cars ++;
    }

    return smashed_cars;
}