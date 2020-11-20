#include<iostream>
#include<cctype>
using namespace std;

class park
{
public:
    string RgNumber;
    string Color;
    void Parking(park [],int );
    void Status(park [],int);
    void unpark(park [],int);
    void Parkon_specific_position(park [],int);
    void SearchCar_Details(park [],int);
    void Find_reginumber_color(park [],int);
    void Find_slotnumber_color(park[], int);
    void SlotNumber_for_Rgnumber(park [],int );

};
void park::Parking(park p[],int slot_size)
{
    string Registration_Number,Car_color;
    park p2;
    for(int i=0;i<slot_size;i++)
    {
        cout<<"Enter Car "<<i+1<<" Details "<<endl;
        cout<<"Enter car Registration Number = ";
        cin>>Registration_Number;
        cout<<"Enter car Color = ";
        cin>>Car_color;
        p[i].RgNumber = Registration_Number;
        p[i].Color = Car_color;
    }
    cout<<"\nAll details add successfully !!"<<endl;
}
void park::Status(park p[],int slot_size)
{
    cout<<"\nPositions "<<"\t Registration Number"<<"\t Car color"<<endl;
    for(int i=0;i<slot_size;i++)
    {
        cout<<i+1<<"\t\t|"<<p[i].RgNumber<<"\t\t |"<<p[i].Color<<endl;
    }
}
void park::unpark(park p[],int slot_size)
{

    string RgNum;
    int check=0;
        cout<<"Enter Registration Number of car for leaving == ";
        cin>>RgNum;
        for(int i=0;i<slot_size;i++)
        {
            if(p[i].RgNumber==RgNum)
            {
                p[i].RgNumber = " ";
                p[i].Color = " ";
                cout<<"\nSlot Number "<<i+1<<" is free !!"<<endl;
                check++;
            }
        }
        if(check == 1)
        {
            cout<<"Car Details delete successfully !!"<<endl;
        }
        else
        {
            cout<<"\nPlease enter correct car Registration Number !!"<<endl;
        }
}
void park::Parkon_specific_position(park p[],int slot_size)
{
    int position;
    string RegiNumber,CarColor;
    cout<<"\nEnter position to park your car(between 1 to )"<<slot_size<<" = ";
    cin>>position;
    int check=0;
    if(position <= slot_size)
    {
        for(int i=0;i<slot_size;i++)
        {
            if(p[i].RgNumber== " " && p[i].Color == " ")
            {
                cout<<"Enter Car Details for slot number "<<i+1<<endl;
                cout<<"Enter car Registration Number = ";
                cin>>RegiNumber;
                cout<<"Enter car Color = ";
                cin>>CarColor;
                i==position;
                p[i].RgNumber=RegiNumber;
                p[i].Color=CarColor;
                check++;
                break;
            }
        }
        if(check==1)
        {
            cout<<"\nCar details add successfully !!"<<endl;
        }
        else
        {
            cout<<"\nParking lot already full !!";
        }
    }
    else
    {
        cout<<"enter position from 1 to "<<slot_size<<" !!"<<endl;
    }
}
void park::SearchCar_Details(park p[],int slot_size)
{
    string Registration_num;
    int check=0;
    cout<<"\nEnter car Registration Number == ";
    cin>>Registration_num;
    cout<<"\nCar Position "<<"\tRegistration Number "<<"\tCar Color"<<endl;
    for(int i=0;i<slot_size;i++)
    {
        if(p[i].RgNumber==Registration_num)
        {
            cout<<i+1<<"\t\t"<<p[i].RgNumber<<"\t\t"<<p[i].Color<<endl;
            check++;
            break;
        }
    }
    if(check==1)
    {
        cout<<"\nCar details found successfully !!"<<endl;
    }
    else
    {
        cout<<"\nCar details Not found!!"<<endl;
    }
}
void park::Find_reginumber_color(park p[],int slot_size)
{
    string color;
    cout<<"\nEnter Car color == ";
    cin>>color;
    int check=0;
    for(int i=0;i<slot_size;i++)
    {
        if(p[i].Color == color)
        {
            cout<<p[i].RgNumber<<", ";
            check++;
        }
    }
    if(check==0)
    {
        cout<<"\nFor "<<color<<" color Registration Number Not found !!";
    }
}
void park::Find_slotnumber_color(park p[],int slot_size)
{
    string color;
    cout<<"\nEnter Car color == ";
    cin>>color;
    int check=0;
    for(int i=0;i<slot_size;i++)
    {
        if(p[i].Color == color)
        {
            cout<<i+1<<", ";
            check++;
        }
    }
    if(check==0)
    {
        cout<<"\nFor "<<color<<" color Slot Number Not found !!";
    }
}
void park::SlotNumber_for_Rgnumber(park p[], int slot_size)
{
    string Rg;
    cout<<"\nEnter Registration number of car == ";
    cin>>Rg;
    int check=0;
    for(int i=0;i<slot_size;i++)
    {
        if(p[i].RgNumber==Rg)
        {
            cout<<i+1<<endl;
            check++;
        }
    }
    if(check==0)
    {
        cout<<"\nThis Registration number is not available on the system !!"<<endl;
    }
}
int check_int(int n)
{
    int arr[9]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++)
    {
        if(arr[i]==n)
        {
            return 1;
        }
    }
}
int main()
{
    int slot_size;
    cout<<"<----------------------------Welcome to Parking Lot System------------------------->"<<endl<<endl;
    cout<<"Enter size of parking lot = ";
    cin>>slot_size;
    if(check_int(slot_size)==1)
    {
        cout<<"Created a Parking lot with "<<slot_size<<" size !!"<<endl;
        int choice;
        park p[slot_size],p1;
        while(1)
        {
            cout<<"\nSelect Operation what you wanted to do !!"<<endl<<endl;
            cout<<"Enter 1 for parking !! "<<endl;
            cout<<"Enter 2 for Park your car on specific position !!"<<endl;
            cout<<"Enter 3 for see the status of parking lot !!"<<endl;
            cout<<"Enter 4 for search car details !!"<<endl;
            cout<<"Enter 5 for search Registration Number by car color !!"<<endl;
            cout<<"Enter 6 for search slot number by car color !!"<<endl;
            cout<<"Enter 7 for search registration number by slot number !!"<<endl;
            cout<<"Enter 8 for leaving !!"<<endl;
            cout<<"Enter 9 for exit from parking lot system !!"<<endl<<endl;

            cout<<"Enter your choice(Only integer value allowed) = ";
            cin>>choice;
            if(check_int(choice)==1)
            {
                switch(choice)
                {
                    case 1: p1.Parking(p,slot_size);
                        break;
                    case 2: p1.Parkon_specific_position(p,slot_size);
                        break;
                    case 3: p1.Status(p,slot_size);
                        break;
                    case 4: p1.SearchCar_Details(p,slot_size);
                        break;
                    case 5: p1.Find_reginumber_color(p, slot_size);
                        break;
                    case 6: p1.Find_slotnumber_color(p, slot_size);
                        break;
                    case 7: p1.SlotNumber_for_Rgnumber(p, slot_size);
                        break;
                    case 8: p1.unpark(p,slot_size);
                        break;
                    case 9: exit(1);
                        break;
                    default: cout<<"Select right choice (between 1 to 8)"<<endl;
                        break;
                }
            }
            else
            {
                cout<<"only integer values are allow !!"<<endl;
                break;
            }
        }
    }
    else
    {
        cout<<"\n please enter slot size of type integer !!"<<endl;
    }
    return 0;
}
