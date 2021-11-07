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
	int size;//记录已有的联系人个数
	struct PeoInfo date[MAX];//存放的联系人的总容量
};

void Initcontact(struct Contact* s);  //数据初始化函数
void AddContact(struct Contact* s);   //增加联系人
void DelContact(struct Contact* s);   //删除联系人
void SearchContact(const struct Contact* s);   //查看指定联系人信息 
void ModifyContact(struct Contact* s);         //修改指定联系人的信息
void ShowContact(const struct Contact* s);     //查看所有已添加联系人信息

