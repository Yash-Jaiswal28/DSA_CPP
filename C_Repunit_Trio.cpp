#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<ll> repunits;
    
    // Generate repunits
    for (int len = 1; len <= 12; len++) {
        ll repunit = 0;
        for (int i = 0; i < len; i++) {
            repunit = repunit * 10 + 1;
        }
        repunits.push_back(repunit);
    }

    vector<ll> sums;

    // Find all possible sums of three repunits
    for (size_t i = 0; i < repunits.size(); i++) {
        for (size_t j = i; j < repunits.size(); j++) {
            for (size_t k = j; k < repunits.size(); k++) {
                ll sum = repunits[i] + repunits[j] + repunits[k];
                if (sum > 0) {
                    sums.push_back(sum);
                }
            }
        }
    }

    // Sort the sums in ascending order
    sort(sums.begin(), sums.end());

    // Output the N-th smallest sum
    cout << sums[N - 1] << endl;

    return 0;
}
