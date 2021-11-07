#include "contact.h"


void Initcontact(struct Contact* s)      //数据初始化
{
	s->size = 0;
	memset(s->date, 0, sizeof(s->date));
}

static int FindByName(const struct Contact* ps)   //查找指定联系人
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

void AddContact(struct Contact* s)       //添加联系人
{
	if (s->size == 1000)
	{
		printf("联系人储存空间已满\n");
	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", s->date[s->size].name);
		printf("请输入电话号码:");
		scanf("%s", s->date[s->size].tele);
		printf("请输入性别:");
		scanf("%s", s->date[s->size].sex);
		printf("请输入年龄:");
		scanf("%d", &(s->date[s->size].age));
		printf("请输入家庭住址:");
		scanf("%s", s->date[s->size].addr);
		printf("添加成功\n");
		s->size++;
	}
}

void DelContact(struct Contact* s)          //删除指定联系人
{
	printf("请输入要删除联系人的名字:");
	int ret = FindByName(s);
	if (ret == s->size)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < s->size-1 ; j++)
		{
			s->date[j] = s->date[j + 1];
		}
		printf("删除成功\n");
		s->size--;
	}
}

void SearchContact(const struct Contact* s)           //查看指定联系人信息
{
	printf("请输入要查找人的名字:");
	int ret = FindByName(s);
	if (ret == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("%-10s\t%-12s\t%-5s\t%-3s\t%-30s\n", "姓名", "电话号码", "性别", "年龄", "住址");
		printf(" %-10s\t%-12s\t%-5s\t%-3d\t%-30s\n",
			s->date[ret].name,
			s->date[ret].tele,
			s->date[ret].sex,
			s->date[ret].age,
			s->date[ret].addr);
	}
}

void ModifyContact(struct Contact* s)           //修改指定联系人信息
{
	printf("请输入要修改联系人的名字");
	int ret = FindByName(s);
	if (ret == -1)
	{
		printf("找不到该联系人\n");
	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", s->date[ret].name);
		printf("请输入电话号码:");
		scanf("%s", s->date[ret].tele);
		printf("请输入性别:");
		scanf("%s", s->date[ret].sex);
		printf("请输入年龄:");
		scanf("%d", &(s->date[ret].age));
		printf("请输入家庭住址:");
		scanf("%s", s->date[ret].addr);
		printf("修改成功\n");
	}

}

void ShowContact(const struct Contact* s)           //查看所有已添加联系人信息
{
	if (s->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-12s\t%-5s\t%-3s\t%-30s\n","姓名","电话号码","性别","年龄","住址");
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