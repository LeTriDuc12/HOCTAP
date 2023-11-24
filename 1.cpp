#include<iostream>
using namespace std;
class ps{
	private:
		int a,b;
	public:
		void nhap(){
			cin>>a;
			cin>>b;
		}
		int tinh(){
			return a+b;
		}
};
int main(){
	ps a;
	a.nhap();
	cout<<a.tinh();
}
