#include<iostream>
using namespace std;

/*
 * �ؿ��Υ����С�����(�ݥ�⡼�ե�����)
 * ���֥������Ȥν����
 */

class MyClass{
	public:
		char *data;
		MyClass(char *);           // ���󥹥ȥ饯��(����1��)   ���ؿ��Υ����С�����
		MyClass(bool, char *);     // ���󥹥ȥ饯��(����2��)
};


// �ʲ����ĤΥ��󥹥ȥ饯���ϴؿ��Υ����С����ɤǤ������줬��Ω����ˤϡ��ؿ��η����ޤ��ϰ����ο����ۤʤ뤳�Ȥ����Ǥ���
MyClass::MyClass(bool b, char *str){
	if(b){
		cout << str << endl;
	}
}

MyClass::MyClass(char *str){
	MyClass::data = str;
	cout << str << endl;
}

int main()
{

	// ������2�İʾ�ξ��ˤϡ����饹̾���ά���뤳�Ȥ��Ǥ��ޤ���
	cout << "######### PART1" << endl;
	MyClass o[3] = {
		MyClass(true,  "azarashi"),
		MyClass(false, "ashika"),
		MyClass(true,  "goma"),
	};

	// ������1�Ĥ����ξ��ˤϡ����饹̾���ά���뤳�Ȥ��Ǥ��ޤ���
	cout << "######### PART2" << endl;
	MyClass o2[3] = {
		"test1",
		"test2",
		"test3",
	};

	// ���֥������ȤΥݥ��󥿤ˤ�����ޤ�
	cout << "######### PART3" << endl;
	MyClass *o3;
	o3 = &o2[0];                               // o2����Ƭ���ɥ쥹��o3�˳�Ǽ���Ƥ��ޤ���
	cout <<     o3->data << endl;              // o3����Ϥ��Ƥ��ޤ���
	cout << (o3+1)->data << endl;              // (o3+1)�Ȥ������ɥ쥹�黻�ˤ��o2[1]��������椷�Ƥ��뤳�Ȥ���ա�"*"���ղä���Ƥ��ޤ���
	cout << (o3+2)->data << endl;              // (o3+2)�Ȥ������ɥ쥹�黻�ˤ��o2[2]�����椷�Ƥ��뤳�Ȥ���ա�"*"���ղä���Ƥ��ޤ���

	return 0;
}
