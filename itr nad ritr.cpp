#include <iostream>
#include <list>
using namespace std;
void test()
{
	list<int> mylist ={1,2,3,4,5};
	cout << "正序输出";
	list<int> :: iterator itr;
	for(itr=mylist.begin();itr !=mylist.end();++itr){
		cout <<*itr<<" ";
	}
	cout <<endl;
	cout << "逆序输出";
	list<int>::reverse_iterator ritr;  // 逆向迭代器
	for(ritr=mylist.rbegin();ritr !=mylist.rend();++ritr){
		cout <<*ritr<<" ";
	}
	cout <<endl;
}
int main()
{
	test();
	return 0;
}
