#include <iostream>
#include <string>

using namespace std;

class HumanData	// ��������� Ŭ����
{
private:
    string human_n;	// human_n: ����̸�
    string exchange_n;    // exc_name; ��ü�� ���
    string present_n;    // pre_name; ��ü�� ���
    int size = 3;
public:
    HumanData() {}
    void Exchange();
    void Lock();
};