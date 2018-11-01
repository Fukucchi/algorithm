//
// ���̐��� n �̖񐔂�񋓂���, O(��n)
//
// verified
//   ABC 112 D - Partition
//     http://codeforces.com/contest/1034/problem/A
//


/*
	n �̖񐔂�Ԃ�
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long> calc_divisor(long long n) {
	vector<long long> res;
	for (long long i = 1LL; i*i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			long long j = n / i;
			if (j != i) res.push_back(j);
		}
	}
	sort(res.begin(), res.end());
	return res;
}


int main() {
	long long N, M;
	cin >> N >> M;
	vector<long long> div = calc_divisor(M);
	
	// M �̖� d �ł����āAd * N <= M �ƂȂ�ő�� d �����߂�
	long long res = 1;
	for (auto d : div) {
		if (d * N <= M) res = max(res, d);
	}

	cout << res << endl;
}