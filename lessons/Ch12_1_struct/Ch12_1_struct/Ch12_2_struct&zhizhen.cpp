#include <iostream>
using namespace std;

struct st_girl
{
    //  string name = "��ʩ";     // �ṹ���п�����string�������ᳫ
    char name[21];          // �ǵó�ʼ��

    int age = 25;
    double weight = 48.6;
    char sex = 'X';
    bool yz = true;

}girl1{ "��ʩ",26,50,'X',false };

void func(const st_girl* pst)   // �����ϣ��ʵ�α��޸ģ���constԼ��
{
    cout << "����func��" << endl;
    // pst->name = "����";    // C����ַ���������ֱ�����ַ�����ֵ

    //strcpy_s(pst->name, "����");      // strcpy�����ˣ�strcpy_s����ȫ
    //pst->age = 88; 

    cout << "������" << pst->name << "���䣺" << pst->age << "���أ�" << pst->weight
        << "�Ա�" << pst->sex << "��ֵ��" << pst->yz << endl;
}

int main()
{
    // ��ʼ����
    //st_girl girl1 = { 0 };      // �����ṹ
    // st_girl girl1 = {};
        // �ڶ��ֳ�ʼ��������struct �ṹ���� �ṹ������� = { ��Աһ��ֵ,��Ա����ֵ�� ��Աn��ֵ };
    cout << "������" << girl1.name << "���䣺" << girl1.age << "���أ�" << girl1.weight
        << "�Ա�" << girl1.sex << "��ֵ��" << girl1.yz << endl;

    // �ṹ��ָ��
    st_girl* pst = &girl1;
    cout << "������" << (*pst).name << "���䣺" << (*pst).age << "���أ�" << (*pst).weight
        << "�Ա�" << (*pst).sex << "��ֵ��" << (*pst).yz << endl;   // . �����ȼ����� * ���������� ()

    cout << "������" << pst->name << "���䣺" << pst->age << "���أ�" << pst->weight
        << "�Ա�" << pst->sex << "��ֵ��" << pst->yz << endl;
    // girl1.   (*pst).     pst->   Ч���ȼ�
   

    // ��;��
    // 1. ����������
    //      ���Ҫ�ѽṹ�崫�ݸ�������ʵ��ȡ�ṹ������ĵ�ַ���������β��ýṹ��ָ�롣
    //      �����ϣ���ں������޸Ľṹ�������ֵ�����Զ��βμ�const Լ����
    func(pst);

    // 2. ��̬�����ڴ�
    st_girl* girl3 = new st_girl;   // �����ṹ��ָ�룬newһ���ṹ�壬��ָ��ָ����
    // �����÷��� st_girl* girl3 = new st_girl({ });     // ���г�ʼ��
                 // �� st_girl* girl3 = new st_girl({ "��ʩ",26,50,'X',false });

    func(girl3);    // ����û�г�ʼ����������ʾ����
    memset(girl3, 0, sizeof(girl3));    // �����girl3��ָ�룬��Сֻ��8�ֽڣ�����ֻ�����8�ֽ�
    func(girl3);                                // ��̬�����ڴ�ʱû�нṹ����
    memset(girl3, 0, sizeof(st_girl));  // ֻ���ýṹ����
    func(girl3);

    delete girl3;       // ��̬������ڴ�Ҫ�ֶ��ͷ�
     

}   
