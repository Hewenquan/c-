class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		unordered_map<char,int> need_match,window;
		vector<int> result;
		int left=0,right=0;
		int match=0;
		for(char c:p){
			need_match[c]++;
			
		}
		while(right<s.size()){
			char c=s[right];
			right++;
			if(need_match.count(c)){
				window[c]++;
				if(window[c]==need_match[c]){
					match++;
				}
			}
			while(right-left==p.size()){
				if(match==need_match.size()){
					result.push_back(left);
				}
				char l=s[left];
				left++;
				if(need_match.count(l)){
					if(window[l]==need_match[l]){
						match--;
					}
					window[l]--;
				}
			}
		}
		return result;
	}
};
