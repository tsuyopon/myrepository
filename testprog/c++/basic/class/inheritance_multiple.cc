#include<iostream>
using namespace std;

/*
 *  ¿�ŷѾ��ˤĤ���
 *    (A -> B -> C�Ȥʤ�ľ��Ū�Ѿ��ξ��)
 */

class GrandParent {
	public:
		GrandParent(){
			cout << "GrandParent" << endl;
		}
};

class Parent : public GrandParent {
	public:
		Parent(){
			cout << "Parent" << endl;
		}
};

class Child : public Parent {
	public:
		Child(){
			cout << "Child" << endl;
		}
};

int main(){
	Child obj;
	return 0;
}
