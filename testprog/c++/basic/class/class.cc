#include<iostream>
using namespace std;

/*
 *  ���饹��������֥������������ˡ
 *  ���С��ؿ������ˡ
 *  private������ˡ
 */

class MyClass{
	// ��������������ǡ����Τ��Ȥ���С��ȸƤӤޤ���
	private:
		char *test;
	public:
		char *str;
		void print(){
			cout << str << endl;
		}
		void setPrivate(char *set){       // test��private��ľ�����Ǥ��ʤ��Τ�public�ؿ��������ޤ�
			test = set;
		}
		void getPrivate(){            
			cout << test << endl;
		}
} obj;

int main()
{
	obj.str = "helloworld";
	obj.print();
	obj.setPrivate("konnitiha");
	obj.getPrivate();
}
