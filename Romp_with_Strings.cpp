#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
const int Maxn = 100005;
const int Maxm = 505;
const int mod1 = 1000000007;
const int arg1 = 1000003;
 
int pw1[Maxn];
int t;
char tmp[Maxn];
string T, S;
vector <ii> seq;
vector <int> lens;
int TH[Maxn], SH[Maxn];
int dp[Maxn][Maxm];
 
void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}
 
int getHash(int H[], int l, int r)
{
	int res = H[r];
	l--;
	if (l >= 0)
		res -= ll(pw1[r - l]) * H[l];
	return res;
}
 
int main()
{
	pw1[0]= 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(arg1) * pw1[i - 1];
	}
	scanf("%d", &t);
	while (t--) {
		Read(T); Read(S);
		seq.clear();
		int i = 0;
		while (i < T.length() && T[i] == '*') i++;
		if (i >= T.length()) {
			for (int i = 1; i <= S.length(); i++)
				printf("%d%c", i, i + 1 <= S.length()? ' ': '\n');
			continue;
		}
		for (; i < T.length(); i++)
			if (T[i] != '*')
				if (seq.empty() || seq.back().second + 1 < i) seq.push_back(ii(i, i));
				else seq.back().second++;
		lens.clear();
		for (int i = 0; i < seq.size(); i++)
			lens.push_back(seq[i].second - seq[i].first + 1);
		int h = 0;
		for (int i = 0; i < T.length(); i++) {
			int val = T[i] == '*'? 1005: ll(T[i] - 'a' + 1);
			h = ll(h) * arg1 + val;
			TH[i] = h;
		}
		h = 0;
		for (int i = 0; i < S.length(); i++) {
			int val = int(S[i] - 'a' + 1);
			h = ll(h) * arg1 + val;
			SH[i] = h;
		}
		for (int j = 0; j < seq.size(); j++)
			dp[S.length()][j] = -1;
		for (int i = int(S.length()) - 1; i >= 0; i--) {
			int len = seq.back().second - seq.back().first + 1;
			if (i + lens.back() <= S.length())
				if (getHash(SH, i, i + lens.back() - 1) == getHash(TH, seq.back().first, seq.back().second))
					dp[i][int(seq.size()) - 1] = i + lens.back() - 1;
				else dp[i][int(seq.size()) - 1] = dp[i + 1][int(seq.size()) - 1];
			else dp[i][int(seq.size()) - 1] = -1;
			for (int j = int(seq.size()) - 2; j >= 0; j--)
				if (i + lens[j] <= S.length())
					if (getHash(SH, i, i + lens[j] - 1) == getHash(TH, seq[j].first, seq[j].second))
						dp[i][j] = dp[i + lens[j]][j + 1];
					else dp[i][j] = dp[i + 1][j];
				else dp[i][j] = -1;
		}
		for (int i = 0; i < S.length(); i++)
			printf("%d%c", dp[i][0] < 0? -1: dp[i][0] + 1, i + 1 < S.length()? ' ': '\n\n');
	}
	return 0;
} 