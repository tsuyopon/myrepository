#include<iostream>
using namespace std;

/*
 *  �ؿ��Υ����С����ɤˤĤ���(�ݥ�⡼�ե�����)
 */

class MyClass {
	public:
		// ���󥹥ȥ饯���Υ����С�����
		MyClass(){
			cout << "no args" << endl;
		}
		MyClass(char *str){
			cout << str << endl;
		}
		
		// ���̴ؿ��Υ����С�����
		void Azarashi(){
			cout << "Azarashi: kyu-" << endl;
		}
		void Azarashi(char *str){
			cout << "Azarashi: " << str << endl;
		}

		// (���) �ǥ��ȥ饯���ˤĤ��Ƥϥ����С����ɤ����Ѥ��뤳�ȤϽ���ޤ���
} obj;

int main()
{
	obj = MyClass("testtest");
	obj.Azarashi();
	obj.Azarashi("kyu-kyu-");
	return 0;
}
