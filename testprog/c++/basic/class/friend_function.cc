#include<iostream>
using namespace std;

/*
 * �ե��ɴؿ��λ���ˡ�ˤĤ���
 */

class MyClass {
		char *str;

		/* �ե��ɴؿ���������Ƥ��ޤ�
		 *   ���ե��ɴؿ��ϥ��С��ؿ��ǤϤʤ�
		 *   ��this�ݥ��󥿡���¸�ߤ��ʤ�
		 *   ���Ѿ��⤵��ޤ���
		 */
		friend char *getStr(MyClass &);
	public:
		MyClass(char *str){
			MyClass::str = str;
		}
} obj("hello");

char *getStr(MyClass &obj){
	return obj.str;                   // MyClass�������(private)���С��˥����������Ƥ��ޤ���
}

int main()
{
	cout << getStr(obj) << endl;      // obj.getStr()�Ȥ����ƤӽФ����ϤǤ��ʤ��Τ���դ�ɬ�פǤ�!
	return 0;
}
