#include <iostream>
#include <string>

#define MAX_C 200

using namespace std;

// Returns the index of string `s` if is contained into `ls` which have a size of `size`
// Returns -1 if `s` is not contained into `ls`
int index_of(string s, string ls[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (s.compare(ls[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {

     int c;
     string currencies[MAX_C];
     double matrix[MAX_C][MAX_C];

     while (cin >> c && c) {

         for (int i=0; i<c; ++i) {
             cin >> currencies[i];
             for (int j=0; j<c; ++j) {
                 matrix[i][j] = (i==j) ? 1.0 : 0.0; // setting default values on the diagonal
             }
         }

         int r;
         string c1, c2, ratio;

         cin >> r;
         while (r--) {

             cin >> c1 >> c2 >> ratio;

             size_t pos = ratio.find(":");
             string token1, token2;
             token1 = ratio.substr(0, pos);
             token2 = ratio.substr(pos+1, ratio.length()-1);

             int i1 = index_of(c1,currencies,c);
             int i2 = index_of(c2,currencies,c);

             matrix[i1][i2] = max(matrix[i1][i2], stod(token2) / stod(token1));

         }

         for (int k=0; k<c; ++k) {
             for (int i=0; i<c; ++i) {
                 for (int j=0; j<c; ++j) {
                     matrix[i][j] = max(matrix[i][j], matrix[i][k] * matrix[k][j]);
                 }
             }
         }

         bool arbitrage = false;

         for (int i=0; i<c; ++i) {
             if (matrix[i][i] > 1.0) {
                 arbitrage = true;
                 cout << "Arbitrage\n";
                 break;
             }
         }

         if (!arbitrage) cout << "Ok\n";

     }

     return EXIT_SUCCESS;
}
