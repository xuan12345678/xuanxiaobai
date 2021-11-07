#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>

#define MAX 300
#define MAX_name 10
#define MAX_tele 13
#define MAX_sex 5
#define MAX_addr 30

struct PeoInfo
{
	char name[MAX_name];
	int age;
	char tele[MAX_tele];
	char sex[MAX_sex];
	char addr[MAX_addr];
};

struct Contact
{
	int size;//��¼���е���ϵ�˸���
	struct PeoInfo date[MAX];//��ŵ���ϵ�˵�������
};

void Initcontact(struct Contact* s);  //���ݳ�ʼ������
void AddContact(struct Contact* s);   //������ϵ��
void DelContact(struct Contact* s);   //ɾ����ϵ��
void SearchContact(const struct Contact* s);   //�鿴ָ����ϵ����Ϣ 
void ModifyContact(struct Contact* s);         //�޸�ָ����ϵ�˵���Ϣ
void ShowContact(const struct Contact* s);     //�鿴�����������ϵ����Ϣ

