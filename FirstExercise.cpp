class Solution {
//sorting the greed factors and cookie sizes	
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), g.end());
//keeps track how many cookies are assigned to a child with certain greed factor
		int contentChildren = 0;
		int i = 0;
		int j = 0;
/*
gives cookie to a child if the cookie and greed factor suit and then moves on to
the next child and in the end we can see how many children could be satisfied with
that amount of cookies
*/
		while (i < g.size() && j < s.size()) {
			if (s[j]) >= g[i]{
				contentChildren++,
				i++;
			}
			j++;
		}

		return contentChildren;

	}
};
