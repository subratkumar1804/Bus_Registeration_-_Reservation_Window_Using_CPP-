/*Bus Registeration and Reservation Window using C++*/

//Made by: Subrat Kumar

/*This Project is based on the process of registering a bus by a comapany, booking seats by passengers in it and checking if seats are available for further booking on a particular
route, buses on different routes are classified using the bus numbers*/
/*This project in C++ is based on the concept of object oriented programming(OOPs) in C++*/

/*Coding*/

//header files

#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<time.h> 

using namespace std;

//Basic initialisation
static int pass = 0;
void vline(char);
void delay(int);

//Bus class
class Bus{
	//Data members
	private:
		char busn[10];
		char driver[10];
		char arrival[10];
		char depart[10];
		char from[10];
		char to[10];
		char seat[8][4][10];
	//Member functions 
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}bus[10];

/*Member functions definition*/

//function to register bus

void Bus::install(){
	cout<<"\nEnter Bus Number: ";
	cin>>bus[pass].busn;
	cout<<"\nEnter Driver's Name: ";
	cin>>bus[pass].driver;
	cout<<"\nArrival Time: ";
	cin>>bus[pass].arrival;
	cout<<"\nDeparture Time: ";
	cin>>bus[pass].depart;
	cout<<"\nFrom: ";
	cin>>bus[pass].from;
	cout<<"\nTo: ";
	cin>>bus[pass].to;
	bus[pass].empty();
	pass++;
	cout<<"\nRegistering......";
	delay(1);
	cout<<"\n\nBus Registered Successfully.";
	delay(1);
}

//function for seat allotment

void Bus::allotment(){
	int seat;
	char number[5];
	top:
	cout<<"Bus No. : ";
	cin>>number;
	int temp;
	for(temp=0;temp<=pass;temp++){
		if(strcmp(bus[temp].busn, number)==0)
		break;
	}
	while(temp<=pass){
		cout<<"\nEnter Seat Number: ";
		cin>>seat;
		if(seat>32){
			cout<<"\nOnly 32 seats are there in this bus.";
		}
		else{
			if(strcmp(bus[temp].seat[seat/4][(seat%4)-1], "Empty")==0){
				cout<<"\nEnter Passenger's Name: ";
				cin>>bus[temp].seat[seat/4][(seat%4)-1];
				cout<<"\nAlloting....";
		        delay(1);
		        cout<<"\n\nSeat Alloted.";
		        delay(1);
				break;
			}
			else{
				cout<<"\n\nThe Seat Number is already reserved.\n";
			}
		}
	}
	if(temp>pass){
		cout<<"Enter correct bus number.\n";
		goto top;
	}
}

//function to install seats in recently registered bus
 
void Bus::empty(){
	for(int i=0;i<8;i++){
		for(int j=0;j<4;j++){
			strcpy(bus[pass].seat[i][j], "Empty");
		}
	}
}

//function to show bus information

void Bus::show(){
	int temp;
	char number[10];
	cout<<"Enter Bus Number: ";
	cin>>number;
	cout<<"\n\nSearching........."<<endl<<endl;
	delay(2);
	for(temp=0;temp<=pass;temp++){
		if(strcmp(bus[temp].busn,number)==0){
			break;
		}
	}
	while(temp<=pass){
		vline('*');
		cout<<"\tBus No.: "<<bus[temp].busn;
		cout<<"\nDriver Name: "<<bus[temp].driver;
		cout<<"\t\tArrival Time: "<<bus[temp].arrival;
		cout<<"\tDeparture Time:"<<bus[temp].depart;
		cout<<"\nFrom: "<<bus[temp].from;
		cout<<"\t\t\tTo: "<<bus[temp].to<<"\n";
		vline('*');
		bus[0].position(temp);
		int c=1;
		for(int i=0;i<8;i++){
			for(int j=0;j<4;j++){
				c++;
				if(strcmp(bus[temp].seat[i][j],"Empty")!=0){
					cout<<"\nThe seat number "<<(c-1)<<" is reserverd for "<<bus[temp].seat[i][j]<<".";
				}
			}
		}
		break;
	}
	if(temp>pass){
		cout<<"Enter correct bus number. ";
	}
}
void Bus::position(int l){
	int s=0;
	int p=0;
	for(int i=0;i<8;i++){
		cout<<"\n";
		for(int j=0;j<4;j++){
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty")==0){
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
			else{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\nThere are "<<p<<" seats empty in the Bus No.: "<<bus[l].busn;
}

//function to check availability of seats

void Bus::avail(){
	for(int temp=0;temp<pass;temp++){
		vline('*');
		cout<<"\tBus No.: "<<bus[temp].busn;
		cout<<"\nDriver Name: "<<bus[temp].driver;
		cout<<"\t\tArrival Time: "<<bus[temp].arrival;
		cout<<"\tDeparture Time:"<<bus[temp].depart;
		cout<<"\nFrom: "<<bus[temp].from;
		cout<<"\t\t\tTo: "<<bus[temp].to<<"\n";
		vline('*');
		cout<<endl;
	}
}

//fuction to improve visual design
void vline(char ch){
	for(int i=80;i>0;i--){
		cout<<ch;
	}
}

//function to produce delay
void delay(int number_of_seconds) { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

//Main function

int main(){
	char enter;
	cout<<"\t\t\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t\t\tWELCOME TO BUS REGISTERATION AND RESERVATION WINDOW"<<endl;
	cout<<"\t\t\t\t---------------------------------------------------"<<endl<<endl;
	cout<<"\tMade By: SUBRAT KUMAR";
	cout<<endl<<endl;
	do{
	   cout<<"\tPRESS ENTER TO CONTINUE: ";
	   scanf("%c",&enter);
	   if(enter==10){
		    system("cls");
		    int choice;
		    int set=0;
		    while(1){
		    	cout<<"\n\n";
		    	cout<<"\t\t\t\t\t-----------"<<endl;
		    	cout<<"\t\t\t\t\t MAIN MENU"<<endl;
		    	cout<<"\t\t\t\t\t-----------"<<endl;
			    cout<<"\n\n\n\tPRESS 1: Register Bus\t\t\t"<<endl<<endl;
			    cout<<"\tPRESS 2: Reserve Seat(Reservation)\t\t\t"<<endl<<endl;
			    cout<<"\tPRESS 3: Show Bus Status\t\t\t"<<endl<<endl;
			    cout<<"\tPRESS 4: Number Of Buses Available\t\t\t"<<endl<<endl;
			    cout<<"\tPRESS 5: EXIT"<<endl<<endl;
			    cout<<"\nEnter Your Choice: ";
			    cin>>choice;
			    switch(choice){
				    case 1:{
				    	cout<<"\n\nLoading.....";
				    	delay(1);
				    	system("cls");
					    bus[pass].install();
					    system("cls");
					    break;
				    }
				    case 2:{
				    	cout<<"\n\nLoading......";
				    	delay(1);
				    	system("cls");
					    bus[pass].allotment();
					    system("cls");
					    break;
				    }
				    case 3:{
				    	cout<<"\n\nLoading......";
				    	delay(1);
				    	system("cls");
					    bus[0].show();
					    break;
				    }
				    case 4:{
				    	cout<<"\n\nLoading......";
				    	delay(1);
				    	system("cls");
					    bus[0].avail();
					    break;
				    }
				    case 5:{
				    	cout<<"\n\nQuiting......"<<endl<<endl;
				    	delay(1);
					    cout<<"\t\t\t\tTHANK YOU!!!VISIT AGAIN!";
					    delay(1);
					    exit(0);
					    break;
				    }
			    }
		    }
	    }
	    else{
	    	cout<<"\n\nTry Again!! Choose the correct input."<<endl<<endl;
		}
    }while(enter!=10);
	return 0;
}
/*THANK YOU*/
