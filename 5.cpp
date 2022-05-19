#include<iostream>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
public:
    Time(int temp_hour,int temp_minute);
    Time(int tmp_hour);
    void chagner(int t_hour,int t_minute);
    int get_hour();
    int get_minute();
    int compare(Time time);
    string time_word();
    void print();
    bool check(int tmp_minute,int tmp_hour);
};
void Time::print()
{
    cout<<"hour : "<<hour;
    cout<<"\nminute : "<<minute;
}
string Time::time_word()
{
    if(hour>=0&&hour<12)
    {
        return "morning";
    }
    if(hour==12&&minute==0)
    {
        return "noon";
    }
    if(hour>12&&hour<17)
    {
        return "after noon";
    }
    if(hour>=17&&hour<20)
    {
        return "asr!";
    }
    return "night";
}
Time::Time(int temp_hour,int temp_minute)
{
    if(check(temp_minute,temp_hour))
    {
        hour=temp_hour;
        minute=temp_minute;
    }
    else
    {
        abort();
    }
}
Time::Time(int tmp_hour)
{
    if(check(0,tmp_hour))
    {
        hour=tmp_hour;
        minute=0;
    }
    else
    {
        abort();
    }
}
bool Time::check(int tmp_minute,int tmp_hour)
{
    if(tmp_minute>=0&&tmp_minute<60&&tmp_hour>=0&&tmp_hour<24)
    {
        return true;
    }
    return false;
}
void Time::chagner(int t_hour,int t_minute)
{
    if(check(t_minute,t_hour))
    {
        hour=t_hour;
        minute=t_minute;
    }
}
int Time::get_hour()
{
    return hour;
}
int Time::get_minute()
{
    return minute;
}
int Time::compare(Time time)
{
    if(hour==time.hour)
    {
        if(minute>time.minute)
        {
            return 1;
        }
        if(minute==time.minute)
        {
            return 0;
        }
        return -1;
    }
    if(hour>time.hour)
    {
        return 1;
    }
    return -1;
}
int main()
{
    int h,m;
    cout<<"enter the time with this format : ";
    cout<<"\nhour : ";
    cin>>h;
    cout<<"\nminute : ";
    cin>>m;
    Time sample(h,m);
    sample.print();
    cout<<"\n**************************************\n";
    Time sample1(h);
    sample1.print();
    cout<<"\n**************************************\n";
    cout<<"now the time is : \n";
    sample.print();
    cout<<"\nto change it : \nhour: ";
    cin>>h;
    cout<<"minute : ";
    cin>>m;
    sample.chagner(h,m);
    sample.print();
    cout<<"\n**************************************\n";
    cout<<"time is : \n";
    cout<<"hour: "<<sample.get_hour();
    cout<<"\nminute: "<<sample.get_minute();
    cout<<"\n**************************************\n";
    cout<<"to compare ,enter time : ";
    cout<<"\nhour: ";
    cin>>h;
    cout<<"minute: ";
    cin>>m;
    Time sample2(h,m);
    int temp=sample2.compare(sample);
    if(temp==0)
    {
        cout<<"times are equal";
    }
    if(temp==-1)
    {
        cout<<"this entered time is smaller";
    }
    if(temp==1)
    {
        cout<<"this entered time is bigger";
    }
    cout<<"\n**************************************\n";
    cout<<sample.time_word();
    cout<<'\n';
}
