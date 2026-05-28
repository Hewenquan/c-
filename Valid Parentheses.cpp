#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		unordered_map<char, char> pairs = {
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		
		for (char c : s) {
			// 如果是右括号，检查栈顶是否匹配
			if (pairs.count(c)) {
				if (st.empty() || st.top() != pairs[c]) {
					return false;
				}
				st.pop();
			} else {
				// 左括号直接入栈
				st.push(c);
			}
		}
		// 栈空表示所有括号都匹配成功
		return st.empty();
	}
};
