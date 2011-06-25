#include<iostream>
using namespace std;

/*
 *  ¿�ŷѾ��ˤĤ���
 *    (����Ū�Ѿ������������褹�벾�۴��ܥ��饹�ˤĤ���)
 *    inheritance_multiple3.cc�Ǥϡ�GrandParent��ʣ����ƤФ�ޤ��������۴��ܥ��饹��Ƥ֤Ȥ��Τ褦�ʤ��Ȥ����Ǥ��ޤ���
 */

class GrandParent {
	public:
		GrandParent(){
			cout << "GrandParent" << endl;
		}
};

class Parent : virtual public GrandParent {      // ���۴��ܥ��饹virtual�����ꤵ��Ƥ��ޤ���public����Ǥ���
	public:
		Parent(){
			cout << "Parent" << endl;
		}
};

class Parent2 : virtual private GrandParent {     // ���۴��ܥ��饹virtual�����ꤵ��Ƥ��ޤ���private����Ǥ���
	public:
		Parent2(){
			cout << "Parent2" << endl;
		}
};

/*
 *  �����ξ��ˤϡ�
 *      Parent���饹�ϡ�public��GrandParent��Ѿ����Ƥ��ޤ���
 *      Parent2���饹�ϡ�private��GrandParent��Ѿ����Ƥ��ޤ���
 *      Child����GrandParent���饹�˥�������������ˤϺǤ⥪���ץ������(�Ĥޤꡢ���ξ���public)��Ȥ�ޤ���
 */
class Child : public Parent, public Parent2 {    // 2�Ĥ�Ѿ����Ƥ��뤳�Ȥ�����
	public:
		Child(){
			cout << "Child" << endl;
		}
};

int main(){
	Child obj;
	return 0;
}
