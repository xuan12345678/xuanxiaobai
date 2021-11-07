#include "contact.h"


void Initcontact(struct Contact* s)      //���ݳ�ʼ��
{
	s->size = 0;
	memset(s->date, 0, sizeof(s->date));
}

static int FindByName(const struct Contact* ps)   //����ָ����ϵ��
{
	int i = 0;
	char name[MAX_name];
	scanf("%s", name);
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	} 
		return -1;
}

void AddContact(struct Contact* s)       //�����ϵ��
{
	if (s->size == 1000)
	{
		printf("��ϵ�˴���ռ�����\n");
	}
	else
	{
		printf("����������:");
		scanf("%s", s->date[s->size].name);
		printf("������绰����:");
		scanf("%s", s->date[s->size].tele);
		printf("�������Ա�:");
		scanf("%s", s->date[s->size].sex);
		printf("����������:");
		scanf("%d", &(s->date[s->size].age));
		printf("�������ͥסַ:");
		scanf("%s", s->date[s->size].addr);
		printf("��ӳɹ�\n");
		s->size++;
	}
}

void DelContact(struct Contact* s)          //ɾ��ָ����ϵ��
{
	printf("������Ҫɾ����ϵ�˵�����:");
	int ret = FindByName(s);
	if (ret == s->size)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < s->size-1 ; j++)
		{
			s->date[j] = s->date[j + 1];
		}
		printf("ɾ���ɹ�\n");
		s->size--;
	}
}

void SearchContact(const struct Contact* s)           //�鿴ָ����ϵ����Ϣ
{
	printf("������Ҫ�����˵�����:");
	int ret = FindByName(s);
	if (ret == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("%-10s\t%-12s\t%-5s\t%-3s\t%-30s\n", "����", "�绰����", "�Ա�", "����", "סַ");
		printf(" %-10s\t%-12s\t%-5s\t%-3d\t%-30s\n",
			s->date[ret].name,
			s->date[ret].tele,
			s->date[ret].sex,
			s->date[ret].age,
			s->date[ret].addr);
	}
}

void ModifyContact(struct Contact* s)           //�޸�ָ����ϵ����Ϣ
{
	printf("������Ҫ�޸���ϵ�˵�����");
	int ret = FindByName(s);
	if (ret == -1)
	{
		printf("�Ҳ�������ϵ��\n");
	}
	else
	{
		printf("����������:");
		scanf("%s", s->date[ret].name);
		printf("������绰����:");
		scanf("%s", s->date[ret].tele);
		printf("�������Ա�:");
		scanf("%s", s->date[ret].sex);
		printf("����������:");
		scanf("%d", &(s->date[ret].age));
		printf("�������ͥסַ:");
		scanf("%s", s->date[ret].addr);
		printf("�޸ĳɹ�\n");
	}

}

void ShowContact(const struct Contact* s)           //�鿴�����������ϵ����Ϣ
{
	if (s->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-12s\t%-5s\t%-3s\t%-30s\n","����","�绰����","�Ա�","����","סַ");
		for (i = 0; i < s->size; i++)
		{
			printf(" %-10s\t%-12s\t%-5s\t%-3d\t%-30s\n",
				s->date[i].name,
				s->date[i].tele,
				s->date[i].sex,
				s->date[i].age,
				s->date[i].addr);
		}
		printf("\n");
	}
}