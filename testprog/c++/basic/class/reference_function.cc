#include<iostream>
using namespace std;

/*
 *  �ؿ��˥��ɥ쥹���Ϥ���Ȥ�֥�å��ܥå���������
 *  �ؿ��λ��Ȥ��ֵѤ���
 */
class MyClass {
	private:
		int Num;
	public:
		char *str;
		int & getNum();                      // ����ǻ��Ȥ��ֵѤ��ޤ�
};

int & MyClass::getNum(){                     // ���Ȥ��֤��ؿ��Ǥ���
	return Num;
}

void setString(MyClass &obj, char *str){     // &�λ���
	obj.str = str;
}

int main()
{
	/*
	 * C����Ǥϡ��ؿ���ľ�ܥ��ɥ쥹���Ϥ��ޤ�����
	 * C++�Ǥϴؿ��˥��ɥ쥹���Ϥ��Ȥ�����Ȥ�֥�å��ܥå������Ǥ��ޤ���
	*/
	MyClass obj;
	setString(obj, "helloworld");    // ���ɥ쥹������Ϥ��Ƥ���櫓�Ǥʤ����Ȥ����
	cout << obj.str << endl;

	/*
	 * setter��getter���������򤹤�ؿ���������뤳�Ȥ�����ޤ���
	 */
	obj.getNum() = 100;
	cout << obj.getNum() << endl;

	return 0;
}
