#include<iostream>
using namespace std;

/*
 *  ��::�ץ������ױ黻�Ҥ����Ѥ������饹�᥽�å���Ͽ
 *  ���󥹥ȥ饯����Ͽ��ˡ
 *  �ǥ��ȥ饯����Ͽ��ˡ
 */

class MyClass {
	private:
		int point;
	public:
		MyClass();                         // ���󥹥ȥ饯�� ���С�
		~MyClass();                        // �ǥ��ȥ饯��   ���С�
		void setPoint(int i);
		int  getPoint(int i);
};

MyClass::MyClass(){                        // ���󥹥ȥ饯��
	cout << "START PROGRAM" << endl;
}

MyClass::~MyClass(){                       // �ǥ��ȥ饯��(�������Ϥ����ȤϤǤ��ޤ���)
	cout << "END PROGRAM" << endl;
}

void MyClass::setPoint(int i){             // ��::�ץ������ײ��黻��
	point = i;
}

int MyClass::getPoint(int i){
	point += 1;
	return point;
}

int main()
{
	MyClass obj;
	obj.setPoint(1);
	for(int i = 0; i < 10; i++){
		cout << obj.getPoint(i) << endl;
	}
	return 0;
}


