#include<iostream>
using namespace std;

/*
 * using�ˤĤ���(̾�����֤βĻ벽��Ԥ�)
 */

// using��������namespace�����ɬ��
namespace Azarashi {
	namespace Goma {
		void print(){
			cout << "Azarashi::Goma::print() START" << endl;
		}
	}
}

int main(){
	using namespace Azarashi::Goma;   // ̾�����֤��ɲä�ԤäƤ��ޤ�
	print();                          // Azarashi::Goma::print()�Ȥ��ƸƤӽФ����פǤ��뤳�Ȥ�����
	return 0;
}
