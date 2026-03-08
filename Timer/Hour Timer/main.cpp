#include <bits/stdc++.h>
#include <windows.h>
#define WHITE "\033[47m"
#define RESET "\033[0m"
using namespace std;
bool is_valid_time (string s)
{
    if (s.length()!=8)
        return false;
    if (s[2]!=':' || s[5]!=':')
        return false;
    if (!isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[3]) || !isdigit(s[4]) || !isdigit(s[6]) || !isdigit(s[7]))
        return false;
    int sec=(s[6]-'0')*10+(s[7]-'0');
    int mnt=(s[3]-'0')*10+(s[4]-'0');
    if (sec>=60 || mnt>=60)
        return false;
    return true;
}
void digits (char ch, int i, int j)
{
    switch (ch)
    {
    case '1':
        if (j==3 && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '2':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 && i>=4 && i<=5) || (j==3 && i>=1 && i<=2))
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '3':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if (j==3 && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '4':
        if (i==3 && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 && i>=1 && i<=2) || (j==3 && i!=0 && i!=3 && i!=6))
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '5':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==3 && i>=4 && i<=5) || (j==0 && i>=1 && i<=2))
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '6':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 && i!=0 && i!=3 && i!=6) || (j==3 && i>=4 && i<=5))
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '7':
        if (i==0 && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if (j==3 && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '8':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 || j==3) && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '9':
        if ((i==0 || i==3 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 && i>=1 && i<=2) || (j==3 && i!=0 && i!=3 && i!=6))
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case '0':
        if ((i==0 || i==6) && j!=0 && j!=3)
            cout<<WHITE<<"  "<<RESET;
        else if ((j==0 || j==3) && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    case ':':
        if (j==1 && i!=0 && i!=3 && i!=6)
            cout<<WHITE<<"  "<<RESET;
        else
            cout<<"  ";
        break;
    default:
        cout<<"  ";
    }
}
void display (string s)
{
    for (int i=0; i<7; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (j==2 || j==5)
            {
                for (int k=0; k<3; k++)
                    digits(s[j],i,k);
            }
            else
            {
                for (int k=0; k<4; k++)
                    digits(s[j],i,k);
            }
            cout<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    string s;
    cout<<"Enter the timer (HH:MM:SS):"<<endl;
    cin>>s;
    if (!is_valid_time(s))
    {
        cout<<"Invalid input."<<endl;
        cout<<"Input timer in given format."<<endl;
        return 0;
    }
    Sleep(970);
    while (1)
    {
        system("cls");
        display(s);
        if (s[0]=='0' && s[1]=='0' && s[3]=='0' && s[4]=='0' && s[6]=='0' && s[7]=='0')
            break;
        else if (s[3]=='0' && s[4]=='0' && s[6]=='0' && s[7]=='0')
        {
            s[3]='5';
            s[4]='9';
            s[6]='5';
            s[7]='9';
            if (s[1]=='0' && s[0]!='0')
            {
                s[1]='9';
                s[0]--;
            }
            else
                s[1]--;
        }
        else if (s[6]=='0' && s[7]=='0')
        {
            s[6]='5';
            s[7]='9';
            if (s[4]=='0' && s[3]!='0')
            {
                s[4]='9';
                s[3]--;
            }
            else
                s[4]--;
        }
        else if (s[7]=='0' && s[6]!='0')
        {
            s[6]--;
            s[7]='9';
        }
        else
            s[7]--;
        Sleep(970);
    }
    system("cls");
    cout<<"Time is up"<<endl;
    for (int i=0; i<3; i++)
    {
        Beep(1000,500);
        Sleep(200);
    }
    return 0;
}
