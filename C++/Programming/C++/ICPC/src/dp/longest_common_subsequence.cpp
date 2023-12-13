#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

template<typename T>
int lcs(T& seq1, T& seq2)
{
	int n = seq1.size();
	int m = seq2.size();

	vi prev(m + 1, 0), cur(m + 1, 0);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (seq1[i - 1] == seq2[j - 1])
				cur[j] = 1 + prev[j - 1];
			else
				cur[j] = max(cur[j - 1], prev[j]);
		}
		prev = cur;
	}

	return cur[m];
}
