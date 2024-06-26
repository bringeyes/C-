#include "linkList.h"

LNode* InitList() {
    LNode* head = new (std::nothrow) LNode;     // ����ͷ���

    if (head == nullptr)return nullptr;         // �ڴ治�㣬����ʧ��

    // �ṹ���� . ���ʳ�Ա���ṹ��ָ���� -> ���ʳ�Ա
    head->next = nullptr;       // ͷ������һ�����ʱ�����ڣ��ÿ�

    return head;        // ����ͷ���
}

void DestroyList(LNode*& head) {
    // ����������ָ�ͷ�����ȫ���Ľ�㣬����ͷ��㡣
    LNode* tmp;

    while (head) {
        tmp = head->next;         // tmp ������һ���ĵ�ַ
        delete head;                    // �ͷŵ�ǰ���
        head = tmp;                    // ָ���ƶ�����һ���
    }
}

bool PushFront(LNode* head, const ElemType& ee) {   // ����Ԫ�ش����� + constԼ��
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return false; }

    // ����һ���µ�ַ
    LNode* tmp = new (std::nothrow) LNode;

    // �������ָ��
    tmp->next = head->next;
    head->next = tmp;

    // ��ֵ
    tmp->data = ee;

    return true;
}

void PrintList(const LNode* head) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return; }

    LNode* pp = head->next;      // �ӵ� 1 ����㿪ʼ

    while (pp) {
        cout << pp->data << " ";      // ���Ԫ��Ϊ�ṹ�壬���д���Ҫ�޸�
        pp = pp->next;
    }

    cout << endl;
}

size_t ListLength(LNode* head) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return 0; }

    LNode* pp = head->next;     // ͷ��㲻��
    size_t length = 0;

    while (pp) {
        length++;
        pp = pp->next;
    }
    return length;

    //if (head == nullptr) return 0;
    //return ListLength(head->next) + 1;      // ����ͷ���
}

bool PopFront(LNode* head) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return false; }
    if (head->next == nullptr) { cout << "����Ϊ�գ�û�н�㡣\n"; return false; }

    LNode* pp = head->next;     // ָ���һ�����
    head->next = pp->next;

    delete pp;      // ɾ����һ�����
    return true;
}

bool PopBack(LNode* head) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return false; }
    if (head->next == nullptr) { cout << "����Ϊ�գ�û�н�㡣\n"; return false; }

    LNode* pp = head->next;     // ָ���һ�����
    while (pp->next->next) {
        pp = pp->next;
    }
    delete pp->next;             // ɾ�����һ�����
    pp->next = nullptr;         // �����ڶ������ָ���
    return true;
}

void ClearList(LNode* head) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return; }
    if (head->next == nullptr) { cout << "�����Ѿ�Ϊ�գ�û�н�㡣\n"; return; }

    LNode* tmp = head->next, * tmp_next;

    while (tmp) {
        tmp_next = tmp->next;         // tmp_next ������һ���ĵ�ַ
        delete tmp;                            // �ͷŵ�ǰ���
        tmp = tmp_next;                    // ָ���ƶ�����һ���
    }

    head->next = nullptr;
}

LNode* LocateElem(const LNode* head, const ElemType& ee) {  // ���������ã������ƣ����Ч��
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return nullptr; }
    if (head->next == nullptr) { cout << "����Ϊ�գ�û�н�㡣\n"; return nullptr; }

    LNode* pp = head->next;     // �ӵ�һ����㿪ʼ
    while (pp) {
        // ���Ԫ���ǽṹ�壬���´���Ҫ�޸ĳɱȽϹؼ���
        if (pp->data == ee) return pp;
        pp = pp->next;
    }
    return pp;      // û�ҵ�����nulltpr
}

LNode* LocateNode(LNode* head, unsigned int n) {
    // �������Ϸ���
    if (head == nullptr) { cout << "�������ڡ�\n"; return nullptr; }

    LNode* pp = head;
    unsigned int ii = 0;
    while (pp && ii < n) {
        pp = pp->next;
        ii++;
    }
    if (pp == nullptr)
        cout << "λ��" << n << "���Ϸ��������˱���\n";

    return pp;
}

bool InsertNextNode(LNode* pp, const ElemType& ee) {
    // �������Ϸ���
    if (pp == nullptr) { cout << "��㲻���ڣ��޷����롣\n"; return false; }

    LNode* tmp = new LNode;
    tmp->data = ee;
    tmp->next = pp->next;
    pp->next = tmp;

    return true;
}

bool InsertPriorNode(LNode* pp, const ElemType& ee) {
    // �������Ϸ���
    if (pp == nullptr) { cout << "��㲻���ڣ��޷����롣\n"; return false; }

    // ͵������
    LNode* tmp = new LNode;
    tmp->data = pp->data;
    tmp->next = pp->next;
    pp->data = ee;
    pp->next = tmp;

    return true;
}

bool DeleteNode(LNode* pp) {
    // �������Ϸ���
    if (pp == nullptr) { cout << "��㲻���ڣ��޷�ɾ����\n"; return false; }

    // ͵����������ǰ����pp��һ������
    if (pp->next) {
        LNode* tmp = pp->next;
        pp->data = tmp->data;
        pp->next = tmp->next;
        delete tmp;
        return true;
    }
    return false;   // ���pp�����һ����㣬�ں��������PopBack()����
}

bool PushOrder(LNode* head, const ElemType& ee) {
    if (head == nullptr) { cout << "�������ڡ�\n"; return false; }
    if (head->next == nullptr) return PushFront(head, ee);      // �����һ�����Ϊ�գ�ֱ�Ӳ���; 

    // ��Ϊ�ǵ��������ҵ�>=ee�Ľ��ʱֹͣ����Ҫ����ǰ������ַ
    LNode* pp_pre = head;            // ���ȽϽ���ǰ�����
    LNode* pp = pp_pre->next;     // ���ȽϽ��
    LNode* tmp = new LNode;      // Ҫ����Ľ��

    while (pp) {
        if (pp->data >= ee) {        // �����Ϊ�գ��ӵ�һ�������ʼ�Ƚϴ�С
            tmp->data = ee;
            tmp->next = pp;
            pp_pre->next = tmp;
            return true;                    // �ҵ�����λ�ò���󷵻�
        }
        else {
            pp_pre = pp_pre->next;
            pp = pp->next;
        }
    }

    // �������������ppָ����nullptr�����tmp���뵽����ĩβ
    if (pp == nullptr) {
        tmp->data = ee;
        tmp->next = nullptr;
        pp_pre->next = tmp;
        return true;
    }
    return false;
}

void MergeList(LNode* La, LNode* Lb, LNode* Lc) {
    LNode* pa = La->next;
    LNode* pb = Lb->next;

    LNode* pp;

    while (pa && pb) {
        // ȡpa��pb�Ľ�С��
        if (pa->data <= pb->data) {
            pp = pa;
            pa = pa->next;
        }
        else {
            pp = pb;
            pb = pb->next;
        }

        // �ѽ�С�Ľ��pp׷�ӵ�Lc��
        Lc->next = pp;
        Lc = Lc->next;
    }

    // ������pa��pb������Ԫ��׷�ӵ�Lc��
    if (pa) Lc->next = pa;
    if (pb) Lc->next = pb;

    // ����La��Lb�Ľ����ȫ��ת�Ƹ���Lc�����ÿգ�����DestroyList()�������ظ��ͷŽ��
    La->next = Lb->next = nullptr;
}