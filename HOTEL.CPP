#include<iostream.h>
#include<conio.h>
#include<string.h>
#define max 100
//class customer
class customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};
class Room
{
public:
char type,stype,ac;
int roomnumber,rent,status;

class customer cust;
class Room addRoom(int);
void searchRoom(int);
void displayRoom(Room);
};
//global declaration
class Room rooms[max];
int count=0;

Room Room::addRoom(int rno)
{
class Room room;
room.roomnumber=rno;
cout<<"\nType AC/Non-AC(A/N):";
cin>>room.ac;
cout<<"\nType Comfort(s/N):";
cin>>room.type;
cout<<"\nType size(B/S):";
cin>>room.stype;
cout<<"\nDaily rent";
cin>>room.rent;
room.status=0;
cout<<"\nRoom added successfully";
getch();
return room;
}

void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomnumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"Room Details\n";
if(rooms[i].status==1)
{
cout<<"\nRoom is reserved";
}
else
{
cout<<"\nRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nRoom not found";
getch();
}
}
void Room::displayRoom(Room tempRoom)
{
cout<<"\nRoom number:\t"<<tempRoom.roomnumber;
cout<<"\nType AC/Non-AC(A/N)"<<tempRoom.ac;
cout<<"\nEnter Comfort(S/N)"<<tempRoom.stype;
cout<<"\nTypr size(B/S)"<<tempRoom.stype;
cout<<"\nRent:"<<tempRoom.rent;
}
//hotel management classes
class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char*);
void checkOut(int);
void guestSummaryReport();
};
void HotelMgnt::guestSummaryReport()
{
if(count==0)
{
cout<<"\nNo guest in hotel!!";
}
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\nCustomer First Name:"<<rooms[i].cust.name;
cout<<"\nRoom Number:"<<rooms[i].roomnumber;
cout<<"\nAddress(only city):"<<rooms[i].cust.address;
cout<<"\nPhone:"<<rooms[i].cust.phone;
cout<<"\n------------------------------";
}
}
getch();
}
//hotel management reservation for room
void HotelMgnt::checkIn()
{
int i,found=0,rno;
class Room room;
cout<<"\nEnter Room Number:";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomnumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
cout<<"\nRoom is already booked";
getch();
return;
}
cout<<"\nEnter booking id:";
cin>>rooms[i].cust.booking_id;
cout<<"\nEnter customer name(first name):";
cin>>rooms[i].cust.name;
cout<<"\nEnter address(only city):";
cin>>rooms[i].cust.address;
cout<<"\nEnter phone";
cin>>rooms[i].cust.phone;
cout<<"\nEnter from date";
cin>>rooms[i].cust.from_date;
cout<<"\nEnter to date";
cin>>rooms[i].cust.to_date;
cout<<"\nEnter advance payment";
cin>>rooms[i].cust.payment_advance;
rooms[i].status=1;
cout<<"\nCustomer Checked-in Sucessfully..";
getch();
}
}
//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\nPress enter for next room";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nAllrooms are reserved";
getch();
}
}
//shows all persons that have booked room
void HotelMgnt::searchCustomer(char*pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1&&stricmp(rooms[i].cust.name,pname)==0)
{
cout<<"\nCustomer name:"<<rooms[i].cust.name;
cout<<"\nRoom number:"<<rooms[i].roomnumber;
cout<<"\n\nPress enter for next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nPerson not found";
getch();
}
}
//generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1&&rooms[i].roomnumber==roomNum)
{
//rno=rooms[i].roomnumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
cout<<"\nEnter number of days:\t";
cin>>days;
billAmount=days*rooms[i].rent;
cout<<"\n\t########CheckOut Details########\n";
cout<<"\nCustomer name:"<<rooms[i].cust.name;
cout<<"\nRoom number:"<<rooms[i].roomnumber;
cout<<"\nAddress:"<<rooms[i].cust.address;
cout<<"\nPhone:"<<rooms[i].cust.phone;
cout<<"\nTotal amount due:"<<billAmount<<"/";
cout<<"\nAdvance Paid:"<<rooms[i].cust.payment_advance<<"/";
cout<<"\n***Total Payable:"<<billAmount-rooms[i].cust.payment_advance<<"/only";
rooms[i].status=0;
}
getch();
}
//managing rooms
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
clrscr();
cout<<"\n###Manage Rooms###";
cout<<"\n1.Add room";
cout<<"\n2.Search room";
cout<<"\n3.Back to main menu";
cout<<"\n\nEnter option";
cin>>opt;
//switch statement
switch(opt)
{
case 1:
cout<<"\nEnter room number:";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomnumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nRoom is present.\nPlease enter unique number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nEnter room number:";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
cout<<"\nPlease enter correct option";
break;
}
}while(opt!=3);
}
int main()
{
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];
clrscr();
do
{
clrscr();
cout<<"########Hotel Management########";
cout<<"\n1.Manage rooms";
cout<<"\n2.Check-In rooms";
cout<<"\n3.Available rooms";
cout<<"\n4.Search Customer";
cout<<"\n5.Check-Out room";
cout<<"\n6.Guest Summary Report";
cout<<"\n7.Exit";
cout<<"\n\nEnter option:";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the room first";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the room first";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\nRooms are not availablr.\nPlease add the room first";
getch();
}
else
{
cout<<"enter customer name";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\nRooms are not availablr.\nPlease add the room first";
getch();
}
else
{
cout<<"Enter room number";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();
break;
case 7:
cout<<"\nTHANK YOU!FOR USING SOFTWARE";
break;
default:
cout<<"\nPlease enter correct option";
break;
}
}while(opt!=7);
getch();
}

