#include<iostream>
using namespace std;

/*
 *  �ƥ�ץ졼�ȴؿ��ˤĤ���
 *   �� ���Υƥ�ץ졼�ȴؿ��ϡ�ʣ���η����������Ԥ�����ʤɤ�ʣ���ĤΥ����С��饤�ɴؿ��򵭽Ҥ��ʤ��Ƥ��ɤ��Ȥ������åȤ�����ޤ���
 */

template <class X> void println(X out){                        // float, double���ʤ�Ǥ�����դ��ޤ���â����int�������ϲ����᥽�åɤ�int���������С����ɤ���Ƥ���ΤǤ����餬ͥ�褵��ޤ�
	cout << "Template Class: " << out << endl;
}

void println(int out){                                       // println()�ؿ��ΰ�����int���Ǥ��ä����ˤ��Υ᥽�åɤ��ƤӽФ���ޤ�(�ƥ�ץ졼�ȤΥ����С��饤��)
	cout << "Int: " << out << endl;
}

template <class X> X addData(X arg1, X arg2){                  // �����η��϶���X�Ȱ��פ��Ƥ���Τǡ�Ʊ������̵����Фʤ�ʤ�
	return arg1 + arg2;
}

template <class X, class Y> void  printData(X arg1, Y arg2){   // �����η���X��Y�Ȱۤʤ�Τǡ��ۤʤ뷿���������Ƥ����ꤢ��ޤ���
	cout << "arg1=" << arg1 << "\targ2=" << arg2 << endl;
}

int main()
{
	// println()
	println(10);
	println("helloworld");
	println(1.234);

	// addData()
	cout << addData(100, 200) << endl;
//	cout << addData(1.23, 200) << endl;                        // ���Ĥ�ΰ����ȣ��Ĥ�ΰ������ۤʤ�Τǡ����ιԤ�����ȥ���ѥ���Ǥ��ʤ���

	// printData()
	printData("hello", "world");
	printData(1.234, 100);

	return 0;
}
