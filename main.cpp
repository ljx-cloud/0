#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;
void Display();//调用display显示switch()界面
void Register();//注册
void Enter();//登录
class Building
{
public:


    void xiugai();
    void chaxun();
    void shanchu();
    void tianjia1();
    void liulan1();
    void tianjia2();
    void liulan2();
    string gethuxing();
    string getmianji();
    string getjiage();
    string getlouceng();
    string getlouhao();
protected:
    string huxing;
    string louhao;
    string louceng;
    string mianji;
    string jiage;
    private:
    static int num;
};
class user{
private:
	 string ID;
	 string Name;
	 string Email;
	 string Password;
public:
	user(){};
	void Register();
	void Enter();
} ;
vector<user> people;

void user:: Register()//注册
{
	string pw1;
	string pw2;
	user person;
	cout<<"请设置您的ID：";
flag:
	cin>>person.ID;
	for(int i=0;i<people.size();i++)
        {
		if(people.at(i).ID==person.ID)
		{
			cout<<"该ID已存在，请重新设置:";
			goto flag;
		}
	}
	cout<<"请设置您的用户名：";
	cin>>person.Name;
	cout<<"请绑定您的邮箱：";
	cin>>person.Email;
	cout<<"请设置您的密码：";
flag0:
	cin>>pw1;
	cout<<"请再次确认您的密码：";
	cin>>pw2;
		if(pw1!=pw2)
		{
			cout<<"前后两次输入密码不一致，请重新设置密码:";
			goto flag0;
		}
	cout<<"注册成功！"<<endl;
	person.Password=pw1;
	people.push_back(person);
	Display();
}
void user::Enter()//登录
{

	cout<<"请输入您的ID：";
flag1:
	string id;
	string pwd;
	cin>>id;
	for(int i=0;i<people.size();i++)
        {//验证ID是否存在
		int tk=1;tk++;
		if(people.at(i).ID==id)

		{
			tk=2;
			cout<<"请输入您的密码：";
flag2:
			cin>>pwd;
			if(people.at(i).Password!=pwd)
                {
				cout<<"密码错误，请重新输入:";
				goto flag2;
			}
			cout<<"登录成功！"<<endl;
			cout<<"     (1)Information查看信息\n     (2)Exit跳转商品房系统\n\nChoice:";
int choice;//选择界面
cin>>choice; switch(choice)
{
case 1://查看信息
	cout<<"您的ID为："<<people.at(i).ID<<endl;
	cout<<"您的密码为："<<people.at(i).Password<<endl;
	cout<<"您的用户名为："<<people.at(i).Name<<endl;
	cout<<"您的邮箱为："<<people.at(i).Email<<endl;
	Display();
case 2://退出
    return;
		}
	}
}
cout<<"该ID不存在，请重新输入:";
		goto flag1;

}

void Display()//界面
{
cout<<"     (1)Register注册\n     (2)Enter登录\n     (3)Exit退出转商品房\n\nChoice:";
int choice;//选择界面
user u;
cin>>choice; switch(choice)
{
case 1://注册
   u.Register();//调用函数
    break;
case 2://登录
    u.Enter();//调用函数
    break;
case 3://退出
return;
}
}
int Building::num=0;
 Building a[100];
void Building::tianjia1()
{

    cout<<"          请输入户型:";
    cin>>huxing;
    cout<<endl<<"    请输入楼号:";
    cin>>louhao;
    cout<<endl<<"    请输入楼层:";
    cin>>louceng;
    cout<<endl<<"    请输入面积:";
    cin>>mianji;
    cout<<endl<<"    请输入价格:";
    cin>>jiage;


}
void Building::liulan1()
{
    cout<<setw(6)<<huxing<<setw(6)<<louhao<<setw(6)<<louceng<<setw(20)<<mianji<<setw(20)<<jiage<<endl;
}

string Building::gethuxing()
{
    return huxing;
}

string Building::getmianji()
{
    return mianji;
}
string Building::getjiage()
{
    return jiage;
}
string Building::getlouceng()
{
    return louceng;
}
string Building::getlouhao()
{
    return louhao;
}

void Building::tianjia2()
{
     int i;
     int j=0;
     a[num].tianjia1();
     for(i=0;i<num;i++)
     {
         if(a[i].huxing==a[num].huxing&&
            a[i].louhao==a[num].louhao&&
            a[i].louceng==a[num].louceng&&
            a[i].mianji==a[num].mianji&&
            a[i].jiage==a[num].jiage)
            {
                cout<<"         数据已存在,添加失败。"<<endl;
                j=1;
                num--;
            }



     }
if(!j)
     cout<<endl<<"       添加成功！"<<endl;
     system("pause");
     num++;
}

void Building::liulan2()
{
    int i;


   cout<<"  户型   楼号   楼层               面积                 价格"<<endl;
    for(i=0; i<num; i++)
        a[i].liulan1();

    system("pause");
}
void Building::xiugai()
{
    int m,i,n=0;
    string linshi;
e:
    cout<<"      1.按户型修改"<<endl;
    cout<<"      2.按面积修改"<<endl;
    cout<<"      3.按价格修改"<<endl;
    cout<<"      4.按楼层修改"<<endl;
    cout<<"      5.按楼号修改"<<endl;
    cout<<"      请选择:"<<endl;
    cin>>m;
    if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
    {
        cout<<"   输入错误！"<<endl;
        system("pause");
        system("cls");
       goto e;
    }
    switch(m)
    {
    case 1:
        cout<<"   请输入户型:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].gethuxing()==linshi)
            {
                n=1;
                cout<<"    请输入新的信息:"<<endl;
                a[i].tianjia1();
                break;
            }
        }
        if(n==0)
            cout<<"        输入错误！"<<endl;
        break;
    case 2:
        cout<<"            请输入面积:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getmianji()==linshi)
            {
                n=1;
               cout<<"     请输入新的信息:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        输入错误！"<<endl;
        break;
    case 3:
        cout<<"            请输入价格:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getjiage()==linshi)
            {
                n=1;
               cout<<"     请输入新的信息:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        输入错误！"<<endl;
        break;
        case 4:
        cout<<"   请输入楼层:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouceng()==linshi)
            {
                n=1;
                cout<<"    请输入新的信息:"<<endl;
                a[i].tianjia1();
                break;
            }
        }
        if(n==0)
            cout<<"        输入错误！"<<endl;
        break;
    case 5:
        cout<<"            请输入楼号:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouhao()==linshi)
            {
                n=1;
               cout<<"     请输入新的信息:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        输入错误！"<<endl;
        break;
    }
     system("pause");
}
void Building::chaxun()
{
    int m,i,n=0;
    string linshi;
e:
    cout<<"        1.按户型查找"<<endl;
    cout<<"        2.按面积查找"<<endl;
    cout<<"        3.按价格查找"<<endl;
    cout<<"        4.按楼层查找"<<endl;
    cout<<"        5.按楼号查找"<<endl;
    cout<<"        请选择:"<<endl;
    cin>>m;
    if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
    {
        cout<<"    输入错误！"<<endl;
        system("pause");
        system("cls");
        goto e;
    }
    switch(m)
    {
    case 1:
        cout<<"    请输入户型:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].gethuxing()==linshi)
            {

                n++;
                if(n==1)
                cout<<"  户型   楼号   楼层                   面积                 价格"<<endl;
                a[i].liulan1();
            }
        }
        if(n==0)
            cout<<"   输入错误！"<<endl;
        break;
    case 2:
        cout<<"       请输入面积:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getmianji()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  户型   楼号   楼层                   面积                 价格"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         输入错误！"<<endl;
        break;
        case 3:
        cout<<"       请输入价格:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getjiage()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  户型   楼号   楼层                   面积                 价格"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         输入错误！"<<endl;
        break;
        case 4:
        cout<<"       请输入楼层:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouceng()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  户型   楼号   楼层                   面积                 价格"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         输入错误！"<<endl;
        break;
        case 5:
        cout<<"       请输入楼号:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouhao()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  户型   楼号   楼层                   面积                 价格"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         输入错误！"<<endl;
        break;
    }
    system("pause");
}
void Building::shanchu()
{
    string huxing0000;
    cout<<"     请输入你要删除的商品房户型:";
    cin>>huxing0000;
    for(int i=0;i<num;i++)
    {
        if(huxing0000==a[i].gethuxing())
        {
            for(int j=i;j<num;j++)
            {
                a[j]=a[j+1];

            }
            num--;
            cout<<"     删除成功"<<endl;

        }
        if(i==num-1)
        {
            cout<<"     你查询的商品房不存在"<<endl;
        }
    }
    system("pause");
    system("cls");
}


int main()
{
    Display();//显示界面　　１注册；２登录；3退出
    cin.get();
    int m,t=1;
    Building n;
    while(t)
    {
        system("cls");
        cout<<endl;
        cout<<endl<<endl;
        cout<<"            ***********************************************"<<endl<<endl;
        cout<<"                         **商品房信息管理系统 **        "<<endl;
        cout<<endl;
        cout<<"                           * 1.添加商品房信息           "<<endl<<endl;
        cout<<"                           * 2.浏览商品房信息           "<<endl<<endl;
        cout<<"                           * 3.修改商品房信息           "<<endl<<endl;
        cout<<"                           * 4.查询商品房信息           "<<endl<<endl;
        cout<<"                           * 5.删除商品房信息           "<<endl<<endl;
        cout<<"                           * 6.退出                 "<<endl<<endl;
        cout<<"                                  "<<endl<<endl;
        cout<<"           请选择:"<<endl;
        cin>>m;
        system("cls");
        switch(m)
        {
        case 1:
            n.tianjia2();
            break;
        case 2:
            n.liulan2();
            break;
        case 3:
            n.xiugai();
            break;
        case 4:
            n.chaxun();
            break;
        case 5:
            n.shanchu();
            break;
        case 6:
            t=0;
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                        **谢谢使用！**";
            break;



        }
    }

}

