#include<iostream>
using namespace std;

/*
 * �ե��ɴؿ��λ���ˡ�ˤĤ���(ʣ�����饹�Ǥμ�갷��)
 */

class Age;

class Name {
		char *name;
	public:
		friend void print(Name &, Age &);    // (1): (2)������Ʊ����ʸ�ǡ�friend�ؿ�����Ǥ��뤳�Ȥ����

		// ���󥹥ȥ饯��
		Name(char *name){
			Name::name = name;
		}

} n_obj("Azarashi");

class Age {
		int age;
	public:
		friend void print(Name &, Age &);    // (2): (1)������Ʊ����ʸ�ǡ�friend�ؿ�����Ǥ��뤳�Ȥ����

		// ���󥹥ȥ饯��
		Age(int age){
			Age::age = age;
		}

} a_obj(3);

// ���С��ؿ��μ���
void print(Name &n, Age &a){
	cout << "Name:" << n.name << "\tAge:" << a.age << endl;
}

int main(){
	print(n_obj, a_obj);                    // �ե��ɴؿ���ƤӽФ��Ƥ��ޤ�
	return 0;
}
