#include<iostream>
using namespace std;

/*
 * ���ԡ����󥹥ȥ饯���λ�����ˡ�ˤĤ���
 */

class MyClass {
	public:
		char *str;

		// �̾�Υ��󥹥ȥ饯������
		MyClass(){
			str = "first";
		}

		// ���ԡ����󥹥ȥ饯�������(���֥������ȤΥ��ԡ����Ȥ�줿�ݤ˼¹Ԥ�������)
		MyClass(const MyClass &myobj){
			str = "second";
		}
} myobj;

int main()
{
	MyClass obj = myobj;         // ���֥������ȤΥ��ԡ�(���ԡ����󥹥ȥ饯�����ƤӽФ���ޤ�)
	cout << myobj.str << endl;
	cout << obj.str << endl;
	return 0;
}
