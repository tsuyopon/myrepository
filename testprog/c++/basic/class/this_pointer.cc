#include<iostream>
using namespace std;

/*
 *  this�ݥ��󥿤λ�����ˡ�ˤĤ���
 */
class MyClass {
	public:
		char *str;
		MyClass(char *str){
			this->str = str;     // this�ݥ��󥿤Ȥϡ����С��ؿ����¹Ԥ��줿�Ȥ��Υݥ���(�� obj[0], obj[1], obj[2]���Υݥ��󥿤�ؤ��Ƥ��ޤ�)�����С��ؿ����¹Ԥ��줿��������this�ݥ��󥿤�¸�ߤ��ޤ���
		}
		void func(){
			cout << this->str << endl;
		}
};

int main()
{
	MyClass obj[3] = {
		"test1",
		"test2",
		"test3",
	};

	for(int i=0; i < 3; i++){
		obj[i].func();           // this�ݥ��󥿤��ɤΤ褦�˰����Ƥ��뤫��ǧ���Ƥ�������
	}
	return 0;
}
