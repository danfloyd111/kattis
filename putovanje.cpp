#include <cstdio>

#define W_LIMIT 1000

using namespace std;

int main() {

    int weights[W_LIMIT];
    int n, c, max_count = -1;

    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: can't read from stdin.\n");
        return 1;
    }

    if (scanf("%d", &c) != 1) {
        fprintf(stderr, "Error: can't read from stdin.\n");
        return 1;
    }

    for (int i = 0; i < n; ++ i) {
        if (scanf("%d", &weights[i]) != 1) {
            fprintf(stderr, "Error: can't read from stdin.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; ++ i) {
        int local_count = 0, current_weight = 0;
        for (int j = i; j < n; ++ j) {
            if (current_weight + weights[j] <= c) {
                current_weight += weights[j];
                local_count ++;
            }
        }
        if (local_count > max_count) {
            max_count = local_count;
        }
    }

    printf("%d\n", max_count);

    return 0;
}
