#include<iostream>
using namespace std;

/*
 *  �ե��ɥ��饹�λ�����ˡ�ˤĤ���
 */

class Parent {
	private:
		int years;
		int month;

	public:
		void set(int y, int m){
			years = y;
			month = m;
		}

	friend class Child;               // �ե��ɥ��饹�����

};

class Child {
	public:
		void display(Parent obj){
			cout << "years:" << obj.years << endl;   // �ե��ɴؿ������Ѥ���Parent���饹��private�˥�������
			cout << "month:" << obj.month << endl;   // �ե��ɴؿ������Ѥ���Parent���饹��private�˥�������
		}
};

int main(){

	class Parent pobj;
	pobj.set(2011, 6);

	class Child cobj;
	cobj.display(pobj);

	return 0;
}
