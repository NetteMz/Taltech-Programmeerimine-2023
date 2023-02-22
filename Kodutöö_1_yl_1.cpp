class Solution {
	//sorteerib isufaktorid ja lapsed	
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), g.end());
		// peab meeles kui palju igale lapsele antakse vastavalt selle kui suur tema isu on
		int contentChildren = 0;
		int i = 0;
		int j = 0;
		/*
		annab lapsele k�psise/k�psised vastavalt isule ja liigub siis j�rgmise lapse juurde 
		kuni k�psised on otsas ja saame teada paljd lapsed saavad nendest k�psistest isu t�is
		*/
		while (i < g.size() && j < s.size()) {
			if (s[j]) >= g[i]{
				contentChildren++,
				i++;
			}
			j++;
		}

		return contentChildren; //annab tulemuseks paljud lapsed isu t�is said

	}
};

