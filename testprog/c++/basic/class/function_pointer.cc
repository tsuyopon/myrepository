#include<iostream>
using namespace std;

/*
 *  �����С����ɤ��줿�ؿ��ǤΥݥ��󥿻�����ˡ�ˤĤ���
 */

void MyMethod(){
	cout << "hello" << endl;
}
void MyMethod(char *str){
	cout << str << endl;
}

int main()
{
	void (*po1)(), (*po2)(char *);   // �����С����ɤ��줿�ؿ��ݥ��󥿤������ˡ

	po1 = MyMethod;
	po2 = MyMethod;

	(*po1)();
	(*po2)("good evening");

	return 0;
}
