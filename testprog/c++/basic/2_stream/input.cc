#include<iostream>
using namespace std;

int main()
{

	/* ���� */
	char yourname[100];
	cout << "Input Your Name: " << flush;                      /* �����ǡ�Azarashi Taro�פ����Ϥ����������ǧ������ñ��Ȥ����ɤ߹��ߤޤ� */
	cin >> yourname;

	cout << "Input Your Age: " << flush;
	int age;
	cin >> age;

	/* ��̤ν��� */
	cout << "Results: " << endl;
	cout << "\tName: "    << yourname << endl;
	cout << "\tAge:  "    << age      << endl;
}
