#include<iostream>
using namespace std;

class MyClass
{
	public:
		MyClass(char *str){
			cout << str << endl;
		}
};

class ArrayMyClass
{
	public:
		~ArrayMyClass(){
			cout << "ArrayMyClass desctructor START" << endl;
		}
};

int main()
{
	// ưŪ����μ���
	int *po;
	po = new int;                         // ������ꤷ��new�ˤ��ưŪ����������
	*po = 100;
	cout << *po << endl;
	delete po;

	// ���֥������Ȥγ������
	MyClass *obj;
	obj = new MyClass("Start MyClass");   // new�ˤ�륪�֥������Ȥ�ưŪ����������
	delete obj;

	// ����������
	ArrayMyClass *aryobj;
	aryobj = new ArrayMyClass[5];         // ������Ф���ưŪ����������
	delete [] aryobj;                     // ����ǳ�����Ƥ�������������������ˡ

	return 0;
}
