#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  while (n) {
    string msg;
    cin >> msg;
    const long msg_length = msg.length();
    long i = 1;
    while (i*i < msg_length) ++i;
    char** matrix = new char*[i];
    for (int j=0; j<i; ++j) matrix[j] = new char[i];
    int k=0,w=0;
    for (int j=0; j<msg_length; ++j) {
      matrix[k][w] = msg[j];
      w++;
      if (w==i) { w=0; k++; }
    }
    string result = "";
    for (int a=0; a<i; a++) {
      for (int b=i-1; b>=0; b--) {
	if(matrix[b][a]) result += matrix[b][a];
      }
    }
    cout << result << endl;
    for (int j=0; j<i; ++j) delete[] matrix[j];
    delete[] matrix;
    --n;
  }
  return EXIT_SUCCESS;
}
