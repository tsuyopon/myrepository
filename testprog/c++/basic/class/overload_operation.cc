#include<iostream>
using namespace std;

/*
 * �黻�ҤΥ����С����ɤˤĤ���
 */ 

class Integer {
	private:
		int value;
	public:
		int operator + (Integer obj){         // +�黻�ҤΥ����С����ɤ˴ؤ������
			cout << "Plus Operator START" << endl;
			return 777;
		}
		int operator - (Integer obj){         // -�黻�ҤΥ����С����ɤ˴ؤ������
			cout << "Minus Operator START" << endl;
			return this->value - obj.value;
		}
		Integer(int value){
			cout << "Integer(" << value << ") START" << endl;
			this->value = value;
		}
};

int main(){
	Integer obj1(10), obj2(100);
	cout << obj1 + obj2 << endl;
	cout << obj1 - obj2 << endl;
	cout << obj1 - obj2 << endl;
	return 0;
}
