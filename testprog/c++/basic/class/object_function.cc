#include<iostream>
using namespace std;

/*
 * ���֥������Ȥ��Ϥ��ؿ��κ�����ˡ
 * ���֥������Ȥ��֤��ؿ��κ�����ˡ
 */

class MyClass {
	public:
		char *str;
		~MyClass();
}obj;

MyClass::~MyClass(){
	cout << str << endl;
}

MyClass getMyClassObject(char *str){                     // MyClass���֥������Ȥ��ֵѤ���᥽�å�
	MyClass obj;
	obj.str = str;
	return obj;
}

void func(MyClass *obj){                                 // MyClass���֥������Ȥ�����Ȥ��Ƽ�������᥽�å�
	obj->str = "My Name Is Second";
}

int main()
{

	// ���饹�᥽�åɤ��饪�֥������Ȥ��������
	MyClass obj2 = getMyClassObject("My Name Is Third");
	cout << obj2.str << endl;

	// ���饹�᥽�åɤ˥��֥������Ȥ�����Ϥ�
	obj.str = "My Name Is First";
	func(&obj);

	return 0;
}
