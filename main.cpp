#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
#include <vector>
#include <conio.h>
using namespace std;
void Display();//����display��ʾswitch()����
void Register();//ע��
void Enter();//��¼
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

void user:: Register()//ע��
{
	string pw1;
	string pw2;
	user person;
	cout<<"����������ID��";
flag:
	cin>>person.ID;
	for(int i=0;i<people.size();i++)
        {
		if(people.at(i).ID==person.ID)
		{
			cout<<"��ID�Ѵ��ڣ�����������:";
			goto flag;
		}
	}
	cout<<"�����������û�����";
	cin>>person.Name;
	cout<<"����������䣺";
	cin>>person.Email;
	cout<<"�������������룺";
flag0:
	cin>>pw1;
	cout<<"���ٴ�ȷ���������룺";
	cin>>pw2;
		if(pw1!=pw2)
		{
			cout<<"ǰ�������������벻һ�£���������������:";
			goto flag0;
		}
	cout<<"ע��ɹ���"<<endl;
	person.Password=pw1;
	people.push_back(person);
	Display();
}
void user::Enter()//��¼
{

	cout<<"����������ID��";
flag1:
	string id;
	string pwd;
	cin>>id;
	for(int i=0;i<people.size();i++)
        {//��֤ID�Ƿ����
		int tk=1;tk++;
		if(people.at(i).ID==id)

		{
			tk=2;
			cout<<"�������������룺";
flag2:
			cin>>pwd;
			if(people.at(i).Password!=pwd)
                {
				cout<<"�����������������:";
				goto flag2;
			}
			cout<<"��¼�ɹ���"<<endl;
			cout<<"     (1)Information�鿴��Ϣ\n     (2)Exit��ת��Ʒ��ϵͳ\n\nChoice:";
int choice;//ѡ�����
cin>>choice; switch(choice)
{
case 1://�鿴��Ϣ
	cout<<"����IDΪ��"<<people.at(i).ID<<endl;
	cout<<"��������Ϊ��"<<people.at(i).Password<<endl;
	cout<<"�����û���Ϊ��"<<people.at(i).Name<<endl;
	cout<<"��������Ϊ��"<<people.at(i).Email<<endl;
	Display();
case 2://�˳�
    return;
		}
	}
}
cout<<"��ID�����ڣ�����������:";
		goto flag1;

}

void Display()//����
{
cout<<"     (1)Registerע��\n     (2)Enter��¼\n     (3)Exit�˳�ת��Ʒ��\n\nChoice:";
int choice;//ѡ�����
user u;
cin>>choice; switch(choice)
{
case 1://ע��
   u.Register();//���ú���
    break;
case 2://��¼
    u.Enter();//���ú���
    break;
case 3://�˳�
return;
}
}
int Building::num=0;
 Building a[100];
void Building::tianjia1()
{

    cout<<"          �����뻧��:";
    cin>>huxing;
    cout<<endl<<"    ������¥��:";
    cin>>louhao;
    cout<<endl<<"    ������¥��:";
    cin>>louceng;
    cout<<endl<<"    ���������:";
    cin>>mianji;
    cout<<endl<<"    ������۸�:";
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
                cout<<"         �����Ѵ���,���ʧ�ܡ�"<<endl;
                j=1;
                num--;
            }



     }
if(!j)
     cout<<endl<<"       ��ӳɹ���"<<endl;
     system("pause");
     num++;
}

void Building::liulan2()
{
    int i;


   cout<<"  ����   ¥��   ¥��               ���                 �۸�"<<endl;
    for(i=0; i<num; i++)
        a[i].liulan1();

    system("pause");
}
void Building::xiugai()
{
    int m,i,n=0;
    string linshi;
e:
    cout<<"      1.�������޸�"<<endl;
    cout<<"      2.������޸�"<<endl;
    cout<<"      3.���۸��޸�"<<endl;
    cout<<"      4.��¥���޸�"<<endl;
    cout<<"      5.��¥���޸�"<<endl;
    cout<<"      ��ѡ��:"<<endl;
    cin>>m;
    if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
    {
        cout<<"   �������"<<endl;
        system("pause");
        system("cls");
       goto e;
    }
    switch(m)
    {
    case 1:
        cout<<"   �����뻧��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].gethuxing()==linshi)
            {
                n=1;
                cout<<"    �������µ���Ϣ:"<<endl;
                a[i].tianjia1();
                break;
            }
        }
        if(n==0)
            cout<<"        �������"<<endl;
        break;
    case 2:
        cout<<"            ���������:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getmianji()==linshi)
            {
                n=1;
               cout<<"     �������µ���Ϣ:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        �������"<<endl;
        break;
    case 3:
        cout<<"            ������۸�:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getjiage()==linshi)
            {
                n=1;
               cout<<"     �������µ���Ϣ:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        �������"<<endl;
        break;
        case 4:
        cout<<"   ������¥��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouceng()==linshi)
            {
                n=1;
                cout<<"    �������µ���Ϣ:"<<endl;
                a[i].tianjia1();
                break;
            }
        }
        if(n==0)
            cout<<"        �������"<<endl;
        break;
    case 5:
        cout<<"            ������¥��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouhao()==linshi)
            {
                n=1;
               cout<<"     �������µ���Ϣ:"<<endl;
               a[i].tianjia1();
               break;
            }
        }
        if(n==0)
            cout<<"        �������"<<endl;
        break;
    }
     system("pause");
}
void Building::chaxun()
{
    int m,i,n=0;
    string linshi;
e:
    cout<<"        1.�����Ͳ���"<<endl;
    cout<<"        2.���������"<<endl;
    cout<<"        3.���۸����"<<endl;
    cout<<"        4.��¥�����"<<endl;
    cout<<"        5.��¥�Ų���"<<endl;
    cout<<"        ��ѡ��:"<<endl;
    cin>>m;
    if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
    {
        cout<<"    �������"<<endl;
        system("pause");
        system("cls");
        goto e;
    }
    switch(m)
    {
    case 1:
        cout<<"    �����뻧��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].gethuxing()==linshi)
            {

                n++;
                if(n==1)
                cout<<"  ����   ¥��   ¥��                   ���                 �۸�"<<endl;
                a[i].liulan1();
            }
        }
        if(n==0)
            cout<<"   �������"<<endl;
        break;
    case 2:
        cout<<"       ���������:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getmianji()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  ����   ¥��   ¥��                   ���                 �۸�"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         �������"<<endl;
        break;
        case 3:
        cout<<"       ������۸�:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getjiage()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  ����   ¥��   ¥��                   ���                 �۸�"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         �������"<<endl;
        break;
        case 4:
        cout<<"       ������¥��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouceng()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  ����   ¥��   ¥��                   ���                 �۸�"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         �������"<<endl;
        break;
        case 5:
        cout<<"       ������¥��:";
        cin>>linshi;
        for(i=0; i<num; i++)
        {
            if(a[i].getlouhao()==linshi)
            {
                n++;
                if(n==1)
                cout<<"  ����   ¥��   ¥��                   ���                 �۸�"<<endl;
                a[i].liulan1();
            }
        }
         if(n==0)
            cout<<"         �������"<<endl;
        break;
    }
    system("pause");
}
void Building::shanchu()
{
    string huxing0000;
    cout<<"     ��������Ҫɾ������Ʒ������:";
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
            cout<<"     ɾ���ɹ�"<<endl;

        }
        if(i==num-1)
        {
            cout<<"     ���ѯ����Ʒ��������"<<endl;
        }
    }
    system("pause");
    system("cls");
}


int main()
{
    Display();//��ʾ���桡����ע�᣻����¼��3�˳�
    cin.get();
    int m,t=1;
    Building n;
    while(t)
    {
        system("cls");
        cout<<endl;
        cout<<endl<<endl;
        cout<<"            ***********************************************"<<endl<<endl;
        cout<<"                         **��Ʒ����Ϣ����ϵͳ **        "<<endl;
        cout<<endl;
        cout<<"                           * 1.�����Ʒ����Ϣ           "<<endl<<endl;
        cout<<"                           * 2.�����Ʒ����Ϣ           "<<endl<<endl;
        cout<<"                           * 3.�޸���Ʒ����Ϣ           "<<endl<<endl;
        cout<<"                           * 4.��ѯ��Ʒ����Ϣ           "<<endl<<endl;
        cout<<"                           * 5.ɾ����Ʒ����Ϣ           "<<endl<<endl;
        cout<<"                           * 6.�˳�                 "<<endl<<endl;
        cout<<"                                  "<<endl<<endl;
        cout<<"           ��ѡ��:"<<endl;
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
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                        **ллʹ�ã�**";
            break;



        }
    }

}

