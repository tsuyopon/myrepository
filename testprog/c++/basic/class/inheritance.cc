#include<iostream>
using namespace std;

/*
 *  �Ѿ��λ��ȤߤˤĤ���
 */

class Azarashi {
	public:
		void cry(){
			cout << "Kyu-" << endl;
		}
		void gorogoro(){
			cout << "Gorogoro" << endl;
		}
};

class Goma : public Azarashi {
	public:
		void cry(){
			cout << "Kyu-Kyu-" << endl;
		}
		void hungry(){
			cout << "I want to eat fish" << endl;
		}
} obj;

int main()
{
	obj.gorogoro();          // Azarashi���饹��gorogor()���ƤӽФ���ޤ�
	obj.hungry();            // Goma���饹��hugry()���ƤӽФ���ޤ�
	obj.Azarashi::cry();     // cry()��Azarashi��Goma�����Υ��饹�ˤ���Τǡ��ƥ��饹�Ǥϥ������פ����Ѥ��ƸƤӽФ��ޤ���
	obj.cry();               // Goma���饹��cry()���ƤӽФ���ޤ�

	return 0;
}

