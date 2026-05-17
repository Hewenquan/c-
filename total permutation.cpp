class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp;
		dfs(res,nums,tmp);
		return res;
	}
	void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int>& tmp){
		if(tmp.size()==nums.size()){
			res.push_back(tmp);
			return;
		}
		for(int i=0;i<nums.size();++i){
			int j;
			for(j=0;j<tmp.size();++j){
				if(nums[i]==tmp[j])
					break;
			}
			if(j==tmp.size()){
				tmp.push_back(nums[i]);
				dfs(res,nums,tmp);
				tmp.pop_back();
			}
		}
	}
};
