#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n, sum;
    scanf("%d", &t);
    while(t-- > 0){
        scanf("%d", &n);
        sum = 0;
        int house[55];
        for(int i = 0; i < n; i++) scanf("%d", &house[i]);
        sort(house, house + n);
        for(int i = 0; i < n - 1; i++) sum += abs(house[i] - house[i + 1]);
        printf("%d\n", sum);
    }
    return 0;
}