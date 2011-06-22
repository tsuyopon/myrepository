#include <iostream>
using namespace std;

/*
 * �Ƽ��ѿ��Υ�������(1)��(4)��ͭ���ϰ�
 * �ؿ��Υ�������(A)��(B)��ͭ���ϰ�
 * ��::�ץ����Х륹�����ײ��黻��
 *
 */

char *str = "Azarashi";                    // (1)

void function(){                           // (A)
	cout << "function()" << endl;
}

/*
 * MyClass Start
 */
class MyClass {
	public:
		char *str;                         // (2)
		void print(char *);
		void function();
};

void MyClass::print(char *str){            // (3)
	cout << str << endl;                   // (3)��str����Ϥ�����
	cout << MyClass::str << endl;          // (2)��str����Ϥ�����
	cout << ::str << endl;                 // (1)��str����Ϥ�����(�����Х륹�����ײ��黻�ҡ�::��)
}

void MyClass::function(){                  // (B)
	cout << "MyClass::function()" << endl; // (B)���Ȥ����
	::function();                          // (A)�����
}

/*
 * main() Start
 */
int main()
{
	char *str = "Ashika";                  // (4)

	cout << "##### MyClass str output" << endl;
	MyClass obj;
	obj.str = "Dolphin";
	obj.print("WHALE");

	cout << "##### main str output" << endl;
	cout << "local str:"  << str << endl;  // (4)��str����Ϥ�����
	cout << "global str:" << ::str<< endl; // (1)��str����Ϥ�����

	cout << "##### function output" << endl;
	obj.function();


	return 0;
}

