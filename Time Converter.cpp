#include <iostream>
#include <string>
using namespace std;
class timeConverter
{
  public:
  void convertToHHMMSS(int totalsecond)
  {
      int hours=totalsecond/3600;
      int remainingseconds=totalsecond%3600;
      int Minutes=remainingseconds/60;
      int Seconds=remainingseconds%60;
      
      cout<<"HH:MM:SS"<<hours<<":"<<Minutes<<":"<<Seconds<<endl;
  }
    
    int convertTosecond(int hours,int Minutes,int seconds)
    {
        return(hours*3600)+(Minutes*60)+seconds;
    }
};

int main()
{
    timeConverter timeconverter;
    int choice;
    cout<<"choose conversation type"<<endl;
    cout<<"1.convert second to HH.MM.SS"<<endl;
    cout<<"2.convert HH.MM.SS to seconds"<<endl;
    cin>>choice;
    
    if(choice==1)
    {
        int totalseconds;
        cout<<"enter seconds";
        cin>>totalseconds;
        timeconverter.convertToHHMMSS(totalseconds);
    }
    else if(choice==2)
    {
        float hours,minutes,seconds;
        cout<<"Enter Hour";
        cin>>hours;
        cout<<"Enter minutes";
        cin>>minutes;
        cout<<"Enter second";
        cin>>seconds;
        
        float totalseconds=timeconverter.convertTosecond(hours,minutes,seconds);
        cout<<"total seconds"<<totalseconds<<endl;
    }
    else
    {
        cout<<"wrong choice"<<endl;
    }
    return 0;
}
