#include<iostream>
using namespace std;

/*
 *  �ǥե���Ȱ����˴ؤ��������ˡ�ˤĤ���
 */

void MyClass( char *str = "hello"){    // �ǥե�����ѿ������Ѥ��Ƥ���
	cout << str << endl;
}

void MyClass2(char *name="Azarashi", int age = 3){
	cout << "Name:" << name << "\tAge:" << age << endl;
}

int main(){
	MyClass();               // ��������ꤷ�Ƥʤ��Τǡ��ǥե���Ȱ��������Ѥ����
	MyClass("good evening"); // ��������ꤷ�Ƥ���Τǡ����������Ѥ����

	/* ���
	 *   �ʲ����㤫��狼��褦�ˡ��ǥե���Ȱ����ϴؿ��Υ����С����ɤ�ɽ����ۣ��ˤʤäƤ��ޤ����Ȥ�����ޤ���
	 */
	MyClass2();              // �����ϻ��ꤻ�����ǥե���Ȱ��������Ѥ���
	MyClass2("Goma");        // ��1�����Τ߻��ꤹ��(â�����裲�����Τ߻��ꤹ�뤳�ȤϤǤ��ʤ�)
	MyClass2("Goma", 5);     // ��������ꤷ���ǥե���Ȱ��������Ѥ��ʤ�

	return 0;
}
