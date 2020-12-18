#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include "item.h"

using namespace std;

void ItemData::setItem_n(string n) {
	item_n = n;
}
string ItemData::getItem_n() {
	return item_n;
}
void ItemData::setCategory_n(string n) {
	category_n = n;
}
string ItemData::getCategory_n() {
	return category_n;
}
void ItemData::setOption(string o) {
	option = o;
}
string ItemData::getOption() {
	return option;
}
void ItemData::setItem_p(int p) {
	item_p = p;
}
int ItemData::getItem_p() {
	return item_p;
}
void ItemData::setItem_a(int a) {
	item_a = a;
}
void ItemData::setTotalitem_a(int a) {
	item_a += a;
}
void ItemData::setSellitem_a(int a) {
	item_a -= a;
}
int ItemData::getItem_a() {
	return item_a;
}
void ItemData::setCash(int ch) {
	cash += ch;
}
void ItemData::setDedcash(int ch) {
	cash -= ch;
}
int ItemData::getCash() {
	return cash;
}
void ItemData::setCard(int cd) {
	card += cd;
}
int ItemData::getCard() {
	return card;
}
void ItemData::setSafe(int s) {
	safe += s;
}
int ItemData::getSafe() {
	return safe;
}
void ItemData::setMonth(int m) {
	month = m;
}
int ItemData::getMonth() {
	return month;
}
void ItemData::setDay(int d) {
	day = d;
}
int ItemData::getDay() {
	return day;
}

void Manager:: addItemType() {
    if (category == nullptr)
    {
        while (true)
        {
            cout << "ī�װ� �迭 ũ�� : ";
            cin >> size;
            if (size > 0)
            {
                category = new Manager[size];
                cout << "ī�װ� �迭�� �����Ǿ����ϴ�.\n";
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "0 �̻��� ���� �Է����ּ���.\n";
            }
        }
    }
    if ((category_c != 0) && (size - category_c == 0))
    {
        cout << "�� �̻� ī�װ��� �߰��� �� �����ϴ�.\n" << endl;
        return;
    }
    cout << "ī�װ� : ";
    string name;
    cin >> name;
    bool tf = true;
    for (int i = 0; i < category_c; i++)
    {
        if (category[i].category_n == name)
        {
            cout << "�ߺ��� ī�װ��Դϴ�.\n" << endl;
            tf = false;
            break;
        }
    }
    if (tf == true)
    {
        category[category_c].category_n = name;
        category[category_c].head = category[category_c].tail = nullptr;    // head, tail �ʱ�ȭ
        cout << category[category_c].category_n << " ī�װ� ��ϵǾ����ϴ�.\n" << endl;
        category_c++;   // ���� ī������ �� �ڸ����� �ϳ� ����
    }
}
void Manager::add() {
    cout << "��ǰ�� ����մϴ�.\n���� ī�װ��� �Է��Ͻʽÿ�. ";
    string c_name;
    cin >> c_name;
    for (int i = 0; i < category_c; i++)
    {
        if (category[i].category_n == c_name)
        {
            cout << c_name << " ī�װ��� � ��ǰ�� ����Ͻðڽ��ϱ�?\n";
            cout << "�̸� : ";
            string name;
            cin >> name;
            ItemNode* ptr = category[i].head;    // ī�װ� ������ ���� �̸��� ��ǰ�� ã�� ���� ������ ����
            while (ptr != nullptr)  // ��ǰ �̸��� ���� ���� �ִ��� Ȯ�����ִ� �۾�
            {
                if (ptr->data->getItem_n() == name)
                    break;
                ptr = ptr->next;
            }
            // �ٸ� ��� ���ݰ� �̺�Ʈ�� ����, ���� ��� ���� ����
            int amount;
            if (ptr == nullptr) // ��ǰ�̸��� �ٸ� ��
            {
                Manager* node = new Manager;
                node->data->setItem_n(name);
                int price;
                while (true)
                {
                    cout << "����(��) : ";
                    cin >> price;
                    if (price > 0)
                    {
                        node->data->setItem_p(price);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // ������ 0���� �Ǵ� ���ڿ��� ���� �� �����޽���
                    }
                }
                while (true)
                {
                    cout << "���(��) : ";
                    cin >> amount;
                    if (amount > 0)
                    {
                        node->data->setItem_a(amount);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // ��� 0���� �Ǵ� ���ڿ��� ���� �� �����޽���
                    }
                }
                if (c_name == "���ݸ�" && i_data.getMonth() == 2 && i_data.getDay() == 14)
                    node->data->setOption("�߷�Ÿ�ε���");
                else if (c_name == "����" && i_data.getMonth() == 3 && i_data.getDay() == 14)
                    node->data->setOption("ȭ��Ʈ����");
                else if (c_name == "������" && i_data.getMonth() == 11 && i_data.getDay() == 11)
                    node->data->setOption("�����ε���");
                else
                    node->data->setOption("����");
                node->next = nullptr;
                if (category[i].head == nullptr)    // ��ǰ ����Ʈ�� ���ٸ�
                    category[i].head = category[i].tail = node;
                else    // ������ ���� �߰�
                {
                    category[i].tail->next = node;  // ���� ������ ����� �ڿ� �ű� ��� �߰�
                    category[i].tail = node;   // tail �����͸� �ڷ� �̵�
                }
                cout << "���������� ��ϵǾ����ϴ�.\n" << endl;
                return;
            }
            else    // ��ǰ�̸��� ���� ��
            {
                ptr->data->setItem_n(name);
                while (true)
                {
                    cout << "���(��) : ";
                    cin >> amount;
                    cin.ignore(1000, '\n');
                    if (amount > 0)
                    {
                        ptr->data->setTotalitem_a(amount);
                        break;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // ��� 0���� �Ǵ� ���ڿ��� ���� �� �����޽���
                    }
                }
                cout << "���������� ��ϵǾ����ϴ�.\n" << endl;
                return;
            }
        }
    }
    cout << c_name << " ī�װ��� ��ϵǾ� ���� �ʽ��ϴ�.\n" << endl;
}
int Manager::printItemlist(ItemNode* ptr) {
    int no = 0;
    while (ptr != nullptr)
    {
        cout << no + 1 << ". " << ptr->data->getItem_n() << " / " << ptr->data->getItem_p() << "��"
            << " / " << ptr->data->getItem_a() << "��" << " / �̺�Ʈ���� : " << ptr->data->getOption() << endl;
        no++;
        ptr = ptr->next;
    }
    return no;
}
void Manager::showItems() {
    cout << "ī�װ� : ";
    cin >> type;
    if (type == "all")
    {
        for (int i = 0; i < category_c; i++)
        {
            cout << "[" << category[i].category_n << "]" << endl;
            if (category[i].head != nullptr)    // ��ϵ� ��ǰ�� �ִٸ�
            {
                int num = printItemlist(category[i].head);
                cout << "��ǰ ���� : " << num << endl << endl;
            }
            else
                cout << "��ǰ ���� : 0\n" << endl;
        }
    }
    else
    {
        bool found = false; // �Է��� ī������ ��ϵǾ��� �ƴ��� üũ�ϴ� ����
        for (int i = 0; i < category_c; i++)
        {
            if (category[i].category_n == type)
            {
                cout << "[" << category[i].category_n << "]" << endl;
                if (category[i].head != nullptr)    // ��ϵ� ��ǰ�� �ִٸ�
                {
                    int num = printItemlist(category[i].head);
                    cout << "��ǰ ���� : " << num << endl << endl;
                }
                else
                    cout << "��ǰ ���� : 0\n" << endl;
                found = true;  // ��ϵ� ī�����̹Ƿ� true�� ����
                break;
            }
        }
        if (!found)
            cout << type << " ī�װ��� ��ϵǾ� ���� �ʽ��ϴ�. \n" << endl;
    }
}
void Manager::sell() {
    cout << "ī�װ� : ";
    cin >> type;
    if (type == "charge")
    {
        while (true)
        {
            cout << "�󸶳� �����Ͻðڽ��ϱ�?(����: ��) ";
            int money;
            cin >> money;
            if (money > 0)
            {
                i_data.setCash(money);
                cout << "������ �Ϸ�Ǿ����ϴ�.\n" << endl;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // ������ 0���� �Ǵ� ���ڿ��� ���� �� �����޽���
            }
        }
    }
    else
    {
        fstream myreceipt;
        myreceipt.open("receipt.txt", ios::out | ios::app);
        bool found2 = false; // �Է��� ī������ ��ϵǾ��� �ƴ��� üũ�ϴ� ����
        for (int i = 0; i < category_c; i++)
        {
            if (category[i].category_n == type)
            {
                while (true)
                {
                    if (category[i].head != nullptr)    // ��ϵ� ��ǰ�� �ִٸ�
                    {
                        cout << "������ �Ľðڽ��ϱ�? ";
                        string name;
                        cin >> name;
                        ItemNode* ptr = category[i].head;    // ī�װ� ������ ���� �̸��� ��ǰ�� ã�� ���� ����
                        bool tf = true;
                        while (ptr != nullptr)  // ��ǰ �̸��� ���� ���� �ִ��� Ȯ�����ִ� �۾�
                        {
                            if (ptr->data->getItem_n() == name)
                            {
                                if (ptr->data->getItem_a() == 0)
                                {
                                    cout << "��� �����ϴ�. ��ǰ����� �̿��� ��� �߰����ּ���.\n";
                                    tf = !tf;
                                    break;
                                }
                                while (true)
                                {
                                    cout << "�󸶳� �Ľðڽ��ϱ�? ";
                                    int amount;
                                    cin >> amount;
                                    auto temp = ptr->data->getItem_a() - amount;
                                    if ((temp < 0) && (amount > 0))
                                        cout << "��� �����ϴ�.\n";
                                    else if ((temp >= 0) && (amount > 0))
                                    {
                                        ptr->data->setSellitem_a(amount);
                                        int price;
                                        price = ptr->data->getItem_p() * amount;
                                        while (true)
                                        {
                                            cout << "ī���ΰ���, �����ΰ���, ����Ƽ���ΰ���?(ī��� 1, ������ 2, ����Ƽ���� 3) ";
                                            int op;
                                            cin >> op;
                                            if (op == 1)
                                            {
                                                while (true)
                                                {
                                                    cout << "��Ż������� �Ͻðڽ��ϱ�?(y/Y or n/N) ";
                                                    char op2;
                                                    cin >> op2;
                                                    if (op2 == 'y' || op2 == 'Y')
                                                    {
                                                        if ((type == "���ݸ�" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "����" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "������" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.45;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.15;
                                                            break;
                                                        }
                                                    }
                                                    else if (op2 == 'n' || op2 == 'N')
                                                    {
                                                        if ((type == "���ݸ�" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "����" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "������" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.4;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.1;
                                                            break;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        cin.clear();
                                                        cin.ignore(1000, '\n');
                                                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // �����޽���
                                                    }
                                                }
                                                i_data.setCard(price);
                                                myreceipt << "��ǰ��: " + name << endl << "�Ǹŷ�: " + to_string(amount)
                                                    + "��\n�Ǹ��� �ݾ�: " + to_string(price) + "��\n��������: ī��\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else if (op == 2)
                                            {
                                                while (true)
                                                {
                                                    cout << "��Ż������� �Ͻðڽ��ϱ�?(y/Y or n/N) ";
                                                    char op2;
                                                    cin >> op2;
                                                    if (op2 == 'y' || op2 == 'Y')
                                                    {
                                                        if ((type == "���ݸ�" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "����" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "������" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.35;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            price = price - price * 0.05;
                                                            break;
                                                        }
                                                    }
                                                    else if (op2 == 'n' || op2 == 'N')
                                                    {
                                                        if ((type == "���ݸ�" && i_data.getMonth() == 2 && i_data.getDay() == 14) ||
                                                            (type == "����" && i_data.getMonth() == 3 && i_data.getDay() == 14) ||
                                                            (type == "������" && i_data.getMonth() == 11 && i_data.getDay() == 11))
                                                        {
                                                            price = price - price * 0.3;
                                                            break;
                                                        }
                                                        else
                                                            break;
                                                    }
                                                    else
                                                    {
                                                        cin.clear();
                                                        cin.ignore(1000, '\n');
                                                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // �����޽���
                                                    }
                                                }
                                                i_data.setCash(price);
                                                myreceipt << "��ǰ��: " + name << endl << "�Ǹŷ�: " + to_string(amount)
                                                    + "��\n�Ǹ��� �ݾ�: " + to_string(price) + "��\n��������: ����\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else if (op == 3)
                                            {
                                                i_data.setCard(price);
                                                myreceipt << "��ǰ��: " + name << endl << "�Ǹŷ�: " + to_string(amount)
                                                    + "��\n�Ǹ��� �ݾ�: " + to_string(price) + "��\n��������: ����Ƽ��\n"
                                                    + "2020." + to_string(i_data.getMonth()) + "." << i_data.getDay()
                                                    << endl << "\n-------------------------\n\n";
                                                break;
                                            }
                                            else
                                            {
                                                cin.clear();
                                                cin.ignore(1000, '\n');
                                                cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // �����޽���
                                            }
                                        }
                                        cout << "������ " + to_string(price) + "���Դϴ�.\n";
                                        break;
                                    }
                                    else
                                    {
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // �����޽���
                                    }
                                }
                                break;
                            }
                            ptr = ptr->next;
                        }
                        if (ptr == nullptr)
                            cout << "��ϵ��� ���� ��ǰ�Դϴ�.\n";
                        else if (tf == false)
                            break;
                        else
                        {
                            cout << "���������� �ǸŵǾ����ϴ�.\n";
                            cout << "�ٸ� ��ǰ�� �Ǹ��Ͻðڽ��ϱ�?(y/Y or n/N) ";
                            string op;
                            cin >> op;
                            if ((op == "y") || (op == "Y"))
                                cout << endl;
                            else if ((op == "n") || (op == "N"))
                            {
                                cout << endl;
                                break;
                            }
                            else
                            {
                                cout << "�ǸŸ� �����ϰڽ��ϴ�.\n" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "���� ��ǰ�� ����Ͻʽÿ�.\n" << endl;
                        break;
                    }
                }
                myreceipt.close();
                found2 = true;  // ��ϵ� ī�����̹Ƿ� true�� ����
                break;
            }
        }
        if (!found2)
            cout << type << " ī�װ��� ��ϵǾ� ���� �ʽ��ϴ�. \n" << endl;
    }
}
void Manager::deposit() {
    int money;
    while (true)
    {
        cout << "���� pos���� �ݾ� : " << i_data.getCash() << endl;
        cout << "�󸶸� �Ա��Ͻðڽ��ϱ�?(����: 10����) ";
        cin >> money;
        if (money > 0)
        {
            if ((i_data.getCash() - money * 100000) >= 0)
            {
                i_data.setDedcash(money * 100000);
                i_data.setSafe(money * 100000);
            }
            else
            {
                cout << "�ܾ��� �����մϴ�.\n";
                money = 0;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "����� �����ֽñ� �ٶ��ϴ�.\n";    // �����޽���
        }
    }
    cout << "�ݰ� " << money * 100000 << "�� �Ա��Ͽ�\n";
    cout << i_data.getSafe() << "�� �ֽ��ϴ�.\n" << endl;
}
bool Manager::receipt(bool tf) {
    cout << endl;
    fstream myreceipt;
    myreceipt.open("receipt.txt", ios::in);
    if (!myreceipt.is_open())
    {
        cout << "���� �ǸŸ� ���߽��ϴ�.\n" << endl;
        tf = !tf;
        return tf;
    }
    string s;
    while (myreceipt)
    {
        getline(myreceipt, s);
        cout << s << endl;
    }
    myreceipt.close();
}
void Manager::money_list() {
    cout << "ī���������: " << i_data.getCard() << "��" << endl;
    cout << "����: " << i_data.getCash() << "��" << endl;
    cout << "�Ѱ��: " << i_data.getCard() + i_data.getCash() + i_data.getSafe() - 100000 << "��\n" << endl;
}
void Manager::today() {
    int month, day;
    srand(time(nullptr));
    month = rand() % 12 + 1;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        day = rand() % 31 + 1;
    else if (month == 2)
        day = rand() % 29 + 1;
    else
        day = rand() % 30 + 1;
    i_data.setMonth(month);
    i_data.setDay(day);

    /*i_data.setMonth(2);
    i_data.setDay(14);

    i_data.setMonth(3);
    i_data.setDay(14);

    i_data.setMonth(11);
    i_data.setDay(11);*/
}
void Manager::today_event() {
    cout << "������ 2020�� " << i_data.getMonth() << "�� " << i_data.getDay() << "���̹Ƿ�\n";
    if (i_data.getMonth() == 2 && i_data.getDay() == 14)
        cout << "�߷�Ÿ�ε��̷� ���ݸ����� 30%�����Դϴ�!\n" << endl;
    else if (i_data.getMonth() == 3 && i_data.getDay() == 14)
        cout << "ȭ��Ʈ���̷� �������� 30%�����Դϴ�!\n" << endl;
    else if (i_data.getMonth() == 11 && i_data.getDay() == 11)
        cout << "�����ε��̷� �����η��� 30%�����Դϴ�!\n" << endl;
    else
        cout << "������ �̺�Ʈ�� �����ϴ�!\n" << endl;
}
