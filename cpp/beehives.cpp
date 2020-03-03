#include <vector>
#include <tuple>
#include <iostream>
#include <cmath>

using namespace std;

inline bool beefight(float distance, tuple<float, float, bool> a, tuple<float, float, bool> b) {
  float x_a = get<0>(a), x_b = get<0>(b);
  float y_a = get<1>(a), y_b = get<1>(b);
  float delta_x = abs(x_a - x_b), delta_y = abs(y_a - y_b);
  float delta = sqrt((delta_x * delta_x) + (delta_y * delta_y));
  return (delta <= distance) ? true : false;
}

int main() {
  bool go_on = true;
  while (go_on) {
    float d;
    int n;
    cin >> d >> n;
    if (d == 0.0 && n == 0) go_on = false;
    else {
      vector<tuple<float, float, bool>> beehives;
      beehives.reserve(n);
      for (int i=0; i<n; ++i) {
	float x, y;
	cin >> x >> y;
	beehives.push_back({x, y, false});
      }
      for (int i=0; i<n; ++i) {
	for (int j=i; j<n; ++j) {
	  if (i!=j && beefight(d, beehives[i], beehives[j])) {
	    get<2>(beehives[i]) = true;
	    get<2>(beehives[j]) = true;
	  }
	}
      }
      int sour_count = 0, sweet_count = 0;
      for (int i=0; i<beehives.size(); ++i) {
	if (get<2>(beehives[i]))
	  ++sour_count;
	else
	  ++sweet_count;
      }
      cout << sour_count << " sour, " << sweet_count << " sweet" << endl;
    }
  }
  return EXIT_SUCCESS;
}
