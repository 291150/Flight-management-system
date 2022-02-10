//17:41 2022年1月24日
//航班信息管理系统
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char username[10][10]={"root","user"};
char flight_number[7];
int num=0;//航班数量；
int order_record=0;//订单数量

int get_order[20];
int root_page() ;
int users_page();

struct flights
{
	char number[7];
	char from[20];
	char terminal[20];
	char time[18];
	char duration[7];
	int price;
	char type[10];
	int ticket;
	struct flights *next;
	struct flights *prev;
};




int Login()                 //用户登录判断检查用户名和密码；
{
	char check_username[10];
	int password ;
	printf("                  欢迎使用航班信息管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("===================用户登录 =======================\n");
	printf("\n");
	printf("                  用户名：");
	scanf("%s",check_username);
	printf("                    密码：");
	scanf("%d",&password);
	if(strcmp(check_username,username[0]) == 0 && password ==123)
	{
		
		
		while(root_page())
		{
			
			;
		}
		
	}
	if(strcmp(check_username,username[1]) == 0 && password ==123)
	{
		
		 while(users_page())
		{
			;
		} 
		// users_page();
	}
	return 1;
}

struct flights flight[20];


int check_flights()//查询所有航班
{
	if(flight[0].price)
	{
		for(int i=0;i<num; i++)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
		}
	}
	else
	{
		printf("暂无航班请添加后查询！\n");
	}
	
	return 0;
}

int add_flights()//添加航班
{
	
	printf("请输入你想添加的航班数量\n");
	scanf("%d",&num);
	
	for(int i=0;i<num; i++)
	{
		printf("请输入本次航班的相关信息：\n");
		printf("<航班号>：");
		scanf("%s",flight[i].number);
		printf("<出发地>：");
		scanf("%s",flight[i].from);
		printf("<目的地>：");
		scanf("%s",flight[i].terminal);
		printf("<出发时间>：");
		scanf("%s",flight[i].time);
		printf("<飞行时长>：");
		scanf("%s",flight[i].duration);
		printf("<价格>：");
		scanf("%d",&flight[i].price);
		printf("<类型>：");
		scanf("%s",flight[i].type);
		printf("<余票>：");
		scanf("%d",&flight[i].ticket);
	}
	printf("添加成功！\n");
	return 0;
}

int modify_flights()//修改航班
{
	
	printf("请输入航班号查询相关信息：\n");
	scanf("%s",flight_number);
	

	
	for(int i=0;i<num; i++)
	{
		// printf("%d\n", flight[num].number, flight_number)
		if(strcmp(flight[i].number,flight_number) == 0)
		{
			printf("<出发地>：");
			scanf("%s",flight[i].from);
			printf("<目的地>：");
			scanf("%s",flight[i].terminal);
			printf("<出发时间>：");
			scanf("%s",flight[i].time);
			printf("<飞行时长>：");
			scanf("%s",flight[i].duration);
			printf("<价格>：");
			scanf("%d",&flight[i].price);
			printf("<类型>：");
			scanf("%s",flight[i].type);
			printf("<余票>：");
			scanf("%d",&flight[i].ticket);
			
			printf("更改成功！");
			return 0;
		}
		
	}
	printf("修改失败请核对航班号是否正确\n");
	
	
	return 0;
}

int delete_flights()//删除航班
{
	printf("请输入航班号进行删除：\n");
	scanf("%s",flight_number);
	
	int delete_logo=1;//删除标志，删除成功为0失败为1；
	
	for(int i=0; i<num ; i++)
	{
		if(strcmp(flight[i].number,flight_number) == 0)
		{
			for(int j=i; j<19 ;j++)
			{
				strcpy(flight[j].number,flight[j+1].number);
				strcpy(flight[j].from,flight[j+1].from);
				strcpy(flight[j].terminal,flight[j+1].terminal);
				strcpy(flight[j].time,flight[j+1].time);
				strcpy(flight[j].duration,flight[j+1].duration);
				flight[j].price = flight[j+1].price;
				strcpy(flight[j].type,flight[j+1].type);
				flight[j].ticket = flight[j+1].ticket;
				
			}
			delete_logo=0;
			printf("删除成功！");
		}
	}
	if(delete_logo)
	{
		printf("无该航班请添加后删除！");
	}
	
	return 0;
}


int root_page()    //管理员主界面
{
	int flag; 
	
	printf("                  欢迎使用航班信息管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\033[1;32;40m                   (1)查看所有航班           (2)添加航班\n");
	printf("                   (3)修改航班               (4)删除航班\n");
	printf("                   (5)返回登录页面 \033[0m\033[1;31;40m          (0)退出\n \033[0m");
	printf("===================请输入0-5进行操作 =========\n");
	
	scanf("%d",&flag);
	
	// while(flag)
	// {
		switch(flag)
		{
			case 1:
			check_flights();
			
			break;
			case 2:
			add_flights();
			
			break;
			case 3:
			modify_flights();
			
			break;
			case 4:
			delete_flights();
			break;
			
			case 5:
			Login();
			return 0;
			break;
			
			case 0:
			exit(0);
			break;
			default :
			printf("请输入有效的操作数0,1,2,3,4,5\n");
		}
	// }
	return 1;
}

int company_profile();//公司简介
int order_query();//查询航班
int ticket();//购票
int personnel_order();//个人订单

int users_page()//用户主页面
{
	int user_flag; 
	
	printf("                  欢迎使用xxx航班信息管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\033[1;32;40m            (1)公司简介          (2)查询航班\n");
	printf("            (3)购票              (4)个人订单\n");
	printf("            (5)返回登录页面 \033[0m\033[1;31;40m     (0)退出\n\033[0m");
	printf("===================请输入0-5进行操作 ============\n");
	
	scanf("%d",&user_flag);
	
	// while(flag)
	// {
		switch(user_flag)
		{
			case 1:
			company_profile();
			
			break;
			case 2:
			order_query();
			
			break;
			case 3:
			ticket();
			
			break;
			case 4:
			personnel_order();
			break;
			
			case 5:
			Login();
			break;
			
			case 0:
			exit(0);
			break;
			default :
			printf("请输入有效的操作数0,1,2,3,4,5\n");
		}
	return 1;
}

int destination_query()//目的地查询
{
	char destination[10];
	printf("请输入目的地：");
	scanf("%s",destination);
	int destination_flag=1;
	for(int i=0; i<20 ;i++)
	{
		if(strcmp(flight[i].terminal,destination) == 0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
			destination_flag=0;
		}
	}
	if(destination_flag)
	{
		printf("暂无到该地的航班\n");
	}
	return 0;
}

int starting_point_the_query()//出发地查询
{
	char start[10];
	printf("请输入出发地：");
	scanf("%s",start);
	
	int start_flag=1;
	
	for(int i=0; i<20 ;i++)
	{
		if(strcmp(flight[i].from,start) == 0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
			start_flag=0;
		}
	}
	if(start_flag)
	{
		printf("暂无从该地出发的航班\n");
	}
	return 0;
}

int flight_number_query()//航班号查询
{
	char user_number_query[10];
	printf("请输入航班号：");
	scanf("%s",user_number_query);
	
	int flight_number_flag=1;
	
	for(int i=0; i<20 ;i++)
	{
		if(strcmp(flight[i].number,user_number_query) == 0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
			flight_number_flag=0;
		}
	}
	if(flight_number_flag)
	{
		printf("无该航班请核对后重新输入！\n");
		
	}
	return 0;
}

int types_queries()//类型查询
{
	char flight_type[10];
	printf("请输入航班类型：");
	scanf("%s",flight_type);
	for(int i=0; i<20 ;i++)
	{
		if(strcmp(flight[i].type,flight_type) == 0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
		}
	}
	return 0;
}

int more_ticket_query()//余票查询
{
	
	for(int i=0; i<20 ;i++)
	{
		if(flight[i].ticket>0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
		}
	}
	return 0;
}

int price_inquiry()//价格查询
{
	int flight_price;
	printf("请输入价格：");
	scanf("%d",&flight_price);
	for(int i=0; i<20 ;i++)
	{
		if(flight[i].price <= flight_price && flight[i].ticket !=0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
		}
	}
	return 0;
}

int departure_time_query()//出发时间查询
{
	char flight_type[10];
	printf("请输入出发时间：");
	scanf("%s",flight_type);
	for(int i=0; i<20 ;i++)
	{
		if(strcmp(flight[i].time,flight_type) <= 0 && flight[i].ticket !=0)
		{
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
		}
	}
	return 0;
}

int company_profile()//公司简介
{
	printf("xxx航空公司成立于x年x月x日\n");
	printf("xxx航空公司联系热线138xxxxxxxx\n");
	printf("xxx航空公司现在拥有20辆航班\n");
	printf("每辆航班限载300人\n");
	
	return 0;
}

int order_query()//查询航班
{
	int order_flag; 
	
	printf("******************航班查询*************************\n");

	printf("    *(1)目的地查询   (2)出发地查询   (3)航班号查询*\n");
	printf("    *(4)类型查询     (5)余票查询     (6)价格查询  *\n");
	printf("    *(7)出发时间查询 (8)返回主界面                *\n");
	printf("***************************************************\n");
	printf("===================请输入0-8进行操作 ==============\n");
	
	scanf("%d",&order_flag);
	
	
		switch(order_flag)
		{
			case 1:
			destination_query();
			
			break;
			case 2:
			starting_point_the_query();
			
			break;
			case 3:
			flight_number_query();
			
			break;
			case 4:
			types_queries();
			break;
			case 5:
			more_ticket_query();
			
			break;
			case 6:
			price_inquiry();
			
			break;
			case 7:
			departure_time_query();
			
			break;
			case 8:
			users_page();
			
			break;
			default :
			printf("请输入有效的操作数0-8\n");
		}
		return 0;
}

int ticket()//购票
{
	int j;
	printf("请输入航班号进行购票：\n");
	scanf("%s",flight_number);
	
	int ticket_logo=1;//购票标志，购票成功为0失败为1；
	
	for(int i=0;i<=num; i++)
	{
		if(strcmp(flight[i].number,flight_number) == 0)
		{		
			flight[i].ticket=flight[i].ticket-1;
				order_record++;
			printf("<航班号>：%s\n",flight[i].number);
			printf("<出发地>：%s\n",flight[i].from);
			printf("<目的地>：%s\n",flight[i].terminal);
			printf("<出发时间>%s\n",flight[i].time);
			printf("<飞行时长>：%s\n",flight[i].duration);
			printf("<价格>：%d\n",flight[i].price);
			printf("<类型>：%s\n",flight[i].type);
			printf("<余票>：%d\n",flight[i].ticket);
			printf("\n");
				
			ticket_logo=0;
			printf("购票成功！\n");
			get_order[j++]=i;
		}
		
	}
	if(ticket_logo)
	{
		printf("无该航班请重新输入！\n");
	}
	return 0;
}

int personnel_order()//个人订单
{
	int order_subscript=0;//订单下标;
	int order_number=0;//订单号
	int order_marks=1;
	order_subscript=get_order[0];
	for(int i=0; i<order_record ;i++)
	{
		printf("==================订单%d=====================\n",++order_number);
		printf("\n");
		
		printf("<航班号>：%s\n",flight[order_subscript].number);
		printf("<出发地>：%s\n",flight[order_subscript].from);
		printf("<目的地>：%s\n",flight[order_subscript].terminal);
		printf("<出发时间>%s\n",flight[order_subscript].time);
		printf("<飞行时长>：%s\n",flight[order_subscript].duration);
		printf("<价格>：%d\n",flight[order_subscript].price);
		printf("<类型>：%s\n",flight[order_subscript].type);
		printf("<订单号>：%d\n",order_number);
		
		printf("\n");
		printf("============================================\n");
		order_marks=0;
		order_subscript=get_order[order_number];
	}
	if(order_marks)
	{
		printf("暂无订单请购买后查询\n");
	}
	return 0;
}

int main()
{
	// int r;
	// r=Login();
	// printf("%d\n",r);
	
	while(Login())//登录
	{
		system("reset");
		printf("请重新输入用户名和密码：\n");
		// Login();
	}
	
	
	  
	
	return 0;

}
