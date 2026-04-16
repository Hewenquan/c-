#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Solution{
public:
	bool wordBreak(string s,vector<string>& wordDict){
		unordered_set<string> hash;
		for(auto& str:wordDict){
			hash.insert(str);;
		}
		int n=s.size();
		vector<bool> dp(n+1);
		s=" "+s;
		dp[0]=true;
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(dp[j-1]==true&&hash.count(s.substr(j,i-j+1))){
					dp[i]=true;
					break;
				}
			}
		}
		return dp[n];
	}
};
int main(){
	Solution sol;
	string s="leetcode";
	vector<string> dict={"leet","code"};
	bool result=sol.wordBreak(s,dict);
	if(result){
		cout <<"可以拆分"<<endl;
	}else{
		cout <<"不可拆分"<< endl;
	}
	return 0;
}
