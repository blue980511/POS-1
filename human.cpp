#include <iostream>
#include <string>
#include "human.h"

using namespace std;

void HumanData :: Exchange() 
{
    string human_n[3] = { "�����˹�", "���ľ˹�", "�߰��˹�" };
    cout << "-----�˹ٸ��-----" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "-" << human_n[i] << endl;
    }
    while (true)
    {
        cout << "��ü�� ����ڸ� �Է��Ͻÿ�. : ";
        cin >> exchange_n;
        for (int i = 0; i < 3; i++)
        {
            if (human_n[i] == exchange_n)
            {
                present_n = exchange_n;
                cout << "����Ϸ�" << endl;
                break;
            }
        }
        if (present_n != exchange_n)
            cout << "��ϵ��� ���� �˹ٻ��Դϴ�." << endl;
        else
            break;
    }
    cout << "���� ����� : " << present_n << endl << endl;
}

void HumanData::Lock()
{
    string human_narray[3] = { "�����˹�", "���ľ˹�", "�߰��˹�" };
    string name;
    cout << "��ݵǾ����ϴ�. ����� �����Ϸ��� ����� �̸��� �����ּ���." << endl;

    while (true)
    {
        cin >> human_n;
        for (int i = 0; i < 3; i++)
        {
            if (human_narray[i] == human_n)
            {
                name = human_n;
                cout << "����� �����Ǿ����ϴ�.\n" << endl;
                break;
            }
        }
        if (name != human_n) {}
        else
            break;
    }
}