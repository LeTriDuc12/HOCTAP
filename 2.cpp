#include<iostream>
#include<cmath>
using namespace std;
class ps{
	private:
		double a,b,c,d;
	public:
		ps(double a1,double a2,double a3,double a4){
			this->a=a1;
			this->b=a2;
			this->c=a3;
			this->d=a4;
		}
		
		friend double tinh(ps&h){
			return (h.a+(h.b-abs(-h.c))*h.d);
		}
};
int main(){
	ps a(3,4,5,6);
	cout<<tinh(a);
}
