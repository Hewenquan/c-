class Solution{
public:
	int trap (vector<int>& height){
		int res=0;
		int left=0,right=height.size()-1;
		int maxL=height[left],maxR=height[right];
		while(left<right){
			if(maxL<maxR){
				++left;
				maxL=max(maxL,height[left]);
				res +=(maxL-height[left]);
			}else{
				--right;
				maxR=max(maxR,height[right]);
				res +=(maxR-height[right]);
			}
		}
		return res;
	}
};
