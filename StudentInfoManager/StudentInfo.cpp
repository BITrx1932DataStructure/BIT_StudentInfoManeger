#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int num;                                   //��ѧ������

class student
{
    friend class studentMessage;
private:
    string ID;
    string name;
    double score[5];                       //1-4����math��English��OPP���ܳɼ�  ��0�ŵ�Ԫ�ճ�
    student* next;
public:
    student();
    string getName()
    {
        return name;
    }
    string getID()
    {
        return ID;
    }
    double getMath()
    {
        return score[1];
    }
    double getEnglesh()
    {
        return score[2];
    }
    double getOPP()
    {
        return score[3];
    }
    double gettotol()
    {
        return score[4];
    }
    student* getNext()
    {
        return next;
    }

    static void analyse(int, student*); //�����ɼ�
    void display();                          //��ӡ�ɼ�
    void swap();                          //��������Ͷ���->next����Ϣ
};

student::student()
{
    cout << "������ѧ��ѧ�� : ";cin >> ID;
    cout << "������ѧ������ : ";cin >> name;
    cout << "������ѧ������ѧ��Ӣ���OPP�ɼ� : " << endl;
    int a, b, c;
    cin >> a;
    while (a < 0 || a>100)
    {
        cout << "����ɼ���������������: " << endl;
        cin >> a;
    }
    cin >> b;
    while (b < 0 || b>100)
    {
        cout << "����ɼ���������������: " << endl;
        cin >> b;
    }
    cin >> c;
    while (c < 0 || c>100)
    {
        cout << "����ɼ���������������: " << endl;
        cin >> c;
    }
    score[1] = a;
    score[2] = b;
    score[3] = c;
    score[4] = a + b + c;
    next = NULL;
}

void student::analyse(int a, student* first)
{
    int you = 0, liang = 0, zhong = 0, jige = 0, bujige = 0;
    student* t = first;
    double average = 0;                   //ƽ����
    while (t)
    {
        int b = int(t->score[a] / 10);
        switch (b)
        {
        case 10:
        case 9:you++;break;
        case 8:liang++;break;
        case 7:zhong++;break;
        case 6:jige++;break;
        default:bujige++;
        }
        average += t->score[a];
        t = t->next;
    }
    average = average / num;
    cout << " ���������� : " << num << "        ƽ���� : " << average << endl;
    cout << "\n ��     ��      ��     ����    ������  " << endl;
    cout << " " << you << " \t" << liang << " \t" << zhong << "\t" << jige << "\t" << bujige << endl;
}

void student::display()
{
    cout << " " << setw(3) << ID << "     " << setw(3) << name << "      ";
    for (int i = 1;i <= 4;i++)
    {
        cout << setw(3) << score[i] << "      ";
    }
    cout << endl;
}

void student::swap()
{
    int j;
    string na, id;
    double sco[5];
    na = name;name = next->name;next->name = na;
    id = ID;ID = next->ID;next->ID = id;
    for (j = 1;j <= 4;j++)
    {
        sco[j] = score[j];
        score[j] = next->score[j];
        next->score[j] = sco[j];
    }
}

class studentMessage
{
private:
    student* first;
    student* last;
public:
    studentMessage();
    student* getFirst()
    {
        return first;
    }
    student* getLast()
    {
        return last;
    }
    int getNum()
    {
        return num;
    }
    void add();                             //���������ѧ���ɼ���¼
    void search();                          //�ڱ��в���ѧ���ɼ���¼
    void del();                             //�ڱ���ɾ��ѧ���ɼ���¼
    void showOne();                         //����һ�ſεĳɼ�
    void showAll();                         //�������ͬѧ���п�Ŀ�ĳɼ�
    void sort();                            //��һ�ſγɼ����ܳɼ�����
    void clear();                           //���������Ϣ���˳�ϵͳ

};

studentMessage::studentMessage()
{
    first = NULL;
    last = NULL;
    num = 0;
}

void studentMessage::add()
{
    student* t = new student;
    student* p = first;
    while (p)
    {
        if (p->ID == t->ID)
        {
            cout << "\nѧ�����������ѧ���ɼ��Ѿ����ڣ�(�����޸ģ�����ɾ��������¼��)" << endl;
            return;
        }
        p = p->next;
    }
    num++;
    if (first == NULL)
    {
        first = last = t;

    }
    else
    {
        last->next = t;
        last = last->next;
    }
}

void studentMessage::search()
{
    string a;
    cout << "\n������Ҫ���ҵ�ѧ����ѧ��:";cin >> a;
    student* t = first;
    while (t)
    {
        if (t->ID == a)
            break;
        t = t->next;
    }
    if (!t)
    {
        cout << "\nδ�ҵ�Ҫ����ѧ����" << endl;
        return;
    }
    cout << "\n���ҳɹ���" << endl;
    cout << " ѧ��    ����     ��ѧ     Ӣ��     OPP     �ܳɼ�" << endl;
    t->display();
}

void studentMessage::del()
{
    string a;
    cout << "\n������Ҫɾ����ѧ����ѧ��: ";cin >> a;
    student* t = first;
    student* p = NULL;
    while (t)
    {
        if (t->ID == a)
            break;
        p = t;
        t = t->next;
    }
    if (!t)
    {
        cout << "\nδ�ҵ�Ҫɾ��ѧ����" << endl;
        return;
    }
    if (!p)
    {
        first = first->next;
        cout << "\n�ɹ�ɾ��ѧ��" << a << endl;
        delete t;
    }
    else
    {
        p->next = t->next;
        cout << "�ɹ�ɾ��ѧ��" << a << endl;
        delete t;
    }

    num--;
}

void studentMessage::showOne()
{
    int a;
    while (1)
    {
        cout << "\n��Ҫ������һ�ųɼ�����������Ӧ���(1:math 2:English 3:OPP):  ";cin >> a;
        if (a != 1 && a != 2 && a != 3)
            cout << "\n��������������������룡" << endl;
        else
            break;
    }
    cout << "\n\t�ɼ���������: \n" << endl;
    student::analyse(a, first);
}

void studentMessage::showAll()
{
    cout << "---------------------�ɼ��б�----------------------" << endl;
    cout << " ѧ��    ����     ��ѧ     Ӣ��     OPP     �ܳɼ�" << endl;
    student* t = first;
    while (t)
    {
        t->display();
        t = t->next;
    }
}

void studentMessage::sort()
{
    int a, n = 0;                  //n--����
    cout << "��Ҫ����ʲô�ɼ�������������Ӧ���(1.��ѧ 2.Ӣ�� 3.OPP 4.�ܳɼ�): ";
    while (1)
    {
        cin >> a;
        if (a != 1 && a != 2 && a != 3 && a != 4)
            cout << "\n��������������������� : ";
        else
            break;
    }
    student* t = first;
    student* p = t;
    while (p->next)
    {
        t = first;
        while (t->next)
        {
            if (t->next->score[a] >= t->score[a])
            {
                t->swap();
            }
            t = t->next;
        }
        p = p->next;
    }
    t = first;
    cout << "\n\t �ɼ�������: " << endl;
    cout << "ѧ��    ����    �ɼ�    ����" << endl;
    while (t)
    {
        n++;
        cout << " " << t->getID() << "  \t" << t->getName() << "  \t";
        switch (a)
        {
        case 1:cout << t->getMath() << "  \t" << n << endl;break;
        case 2:cout << t->getEnglesh() << "  \t" << n << endl;break;
        case 3:cout << t->getOPP() << "  \t" << n << endl;break;
        case 4:cout << t->gettotol() << "  \t" << n << endl;break;
        }
        t = t->next;
    }
}

void studentMessage::clear()
{
    int x;
    cout << "ȷ��Ҫ���������Ϣ��������1��2 (1:ȷ�� 2:ȡ��) : ";cin >> x;
    if (x == 2)
    {
        cout << "\nȡ�����\n" << endl;
        return;
    }
    student* t = first;
    student* p;
    while (t)
    {
        p = t;
        t = t->next;
        delete p;
    }
    cout << "\n��ճɹ���\n";
    cout << "�˳��ɹ���\n";
}

void showMenu()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      ѧ���ɼ�����ϵͳ\n\n";
    cout << "      1.��ʾ����ѧ���ɼ�\n";
    cout << "      2.�����Ϣ\n";
    cout << "      3.��ѯ��Ϣ\n";
    cout << "      4.ɾ����Ϣ\n";
    cout << "      5.�ɼ�����\n";
    cout << "      6.���Ƴɼ�����\n";
    cout << "      7.���������Ϣ���˳�ϵͳ\n";
    cout << "      0.�˳�ϵͳ\n";
    cout << "===============================\n";
    cout << "                               \n";
}

int main()
{
    int h;
    studentMessage stuM = studentMessage();
    while (1)
    {
        showMenu();
        cout << "�����������Ӧ����� : ";
        cin >> h;
        cout << endl;
        switch (h)
        {
        case 1: stuM.showAll(); break;
        case 2: stuM.add(); break;
        case 3: stuM.search(); break;
        case 4: stuM.del(); break;
        case 5: stuM.sort(); break;
        case 6: stuM.showOne(); break;
        case 7: stuM.clear(); return 0;
        case 0: cout << "\n�˳��ɹ���";return 0;
        default:cout << "\n�������������������ȷ����š�" << endl;
        }
    }
}