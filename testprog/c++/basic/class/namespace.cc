#include<iostream>
using namespace std;

/*
 * ̾�����֤�����ˤĤ���
 */


// ̾�����֤�ɬ�������Х�ʰ��֤������Ԥ�����

// ̾�����ְ��֤�ʣ��ʬ�����(ʬ�䤷�Ƥ��ޤ���������MySpace̾�����֤Ȥ��ư����ޤ�)
namespace MySpace {
	void MySpace();
}

namespace MySpace {
	void MySpace(){
		cout << "MySpace::MySpace() START" << endl;
	}
}


// ̾�����֤Υͥ��Ȥ���
namespace Azarashi {
	namespace Goma {
		void print(){
			cout << "Azarashi::Goma::print() START" << endl;
		}
	}
}

// ̵̾̾�����֤���
namespace {
	char *str = "MUMEI NAMESPACE START";  // ̵̾̾�����֤����������ѿ���¾�Υե����뤫�饢���������뤳�ȤϤǤ��ޤ���(extern char *str�ˤ�륢���������ԲĤǤ�)
}

// ̾�����֤��Ф��륨���ꥢ������
namespace que = Azarashi::Goma;

int main(){
	MySpace::MySpace();
	Azarashi::Goma::print();   // ̾�����֤Υͥ��ȸƤӽФ�
	cout << ::str << endl;     // ̵̾̾�����ָƤӽФ�
	que::print();              // ̾�����֥����ꥢ�������Ѥ����ƤӽФ�
	return 0;
}
