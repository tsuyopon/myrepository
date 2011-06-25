#include<iostream>
using namespace std;

/*
 * 演算子のオーバーロードについて
 */ 

class Integer {
	private:
		int value;
	public:
		int operator + (Integer obj){
			return 777;
		}
		int operator - (Integer obj){
			return this->value - obj.value;
		}
		Integer(int value){
			this->value = value;
		}
};

int main(){
	Integer obj1(10), obj2(100);
	cout << obj1 + obj2 << endl;
	cout << obj1 - obj2 << endl;
	return 0;
}
