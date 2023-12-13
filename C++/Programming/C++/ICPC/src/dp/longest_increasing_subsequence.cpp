#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define int long long
typedef size_t sz;
typedef uint_fast64_t Int;
typedef vector<Int> vi;
typedef pair<Int, Int> ii;
typedef vector<pair<Int, Int>> vii;
typedef vector<vector<Int>> vvi;

template<typename T>
int lis(vi arr)
{
	sz n = arr.size();
	vi lis(n, 1);

	for (sz i = 1; i < n; i++)
		for (sz j = 0; j < i; j++)
			if (arr[i] < arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	return *max_element(lis.cbegin(), lis.cbegin() + n);
}
