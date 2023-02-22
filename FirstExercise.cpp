class Solution {
//sorting the greed factors and cookie sizes	
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), g.end());

		int contentChildren = 0;
		int i = 0;
		int j = 0;

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
