#include<iostream>
using namespace std;

/*
 * ��������ˤĤ���
 */

class Man;                // �������

class Human {
	public:
		Human(Man &);     // Man�Ȥ����Τ��Τ餻�뤿��ˤ���������ιԤ�����������Ƥ���
};

class Man {
	public:
		char *name;
		Man(char *name){
			Man::name = name;
		}
} manobj("azarashi");

Human::Human(Man &obj){
	cout << obj.name << endl;
}

int main(){
	Human obj(manobj); 
	return 0;
}
