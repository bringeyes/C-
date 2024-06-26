#include "Skill.h"

// ��ϣ
int skill_Aixi(Hero& target, int level) {
	/*
	* ����������
	������������뷢
	������ս����ʼʱӵ��15����ʸ��ÿ3�ι������(1/1/3)level����ʸ������ǰ��ʸ������
	�������Ե�ǰ����һ�μ�ʸ���䣬ÿ֧�Ѵ���ļ�ʸ���(40%/40%/100%)AD+(4%/6%/20%)AP �����˺���
		�ܼ����()�����˺�����Ŀ��;�������������3�����˾�̯��
	*/
	double add_AD, add_AP;				// ���ܵ�AD/AP�ӳ�
	int	arrows = 15;						// ��ʸ��
	int add_arrow;						// ÿ3�ι�����õļ�ʸ��
	int damage = 0;						// �����˺�

	// ����Ӣ���Ǽ��������ܼӳ�
	switch (level) {
	case 1:
		add_AD = 0.4; add_AP = 0.04; add_arrow = 1;
		break;
	case 2:
		add_AD = 0.4; add_AP = 0.06; add_arrow = 1;
		break;
	case 3:
		add_AD = 1.0; add_AP = 0.2; add_arrow = 3;
		break;
	default:
		cout << "Ӣ���Ǽ����������ȷ��Χ{1,2,3}��\n";
		break;
	}

	int current_AD = target.m_ratio_AD * target.m_AD;					// ���㵱ǰ�﹥
	arrows = 15 + (target.m_count_Attacks / 3) * add_arrow;				// ���㵱ǰ��ʸ��
	damage = arrows * (add_AD * current_AD + add_AP * target.m_AP);		// ���㼼���˺�

	// ������ܿ��Ա��������ݱ����ʼ��㼼���˺�
	if (target.if_Skill_Crit == true) {
		if ((static_cast<double>(rand()) / RAND_MAX) <= target.m_baoji) {
			damage *= target.m_baoshang;
			/*cout << "���ܱ�����";*/
		}
	}

	damage *= target.m_ratio_damage;					// �����˺�����
	/*cout << "��" << target.m_count_Skills << "�μ����˺���" << damage << endl;*/

	return damage;
}