#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    double Id;
    string Name;
    string Gender;
public:
    Customer(double id=0, string name="", string gender=""): Id(id), Name(name), Gender(gender) {}

    int getid() const {
        return this->Id;
    }
    string getName() const {
        return this->Name;
    }
    string getGender() const {
        return this->Gender;
    }
};

class Flight {
public:
    int country;
    vector<string> flightnumber;
    vector<string> country_name;
    vector<int> ticket_prices;
    int selected_flight_index;
    string destination;

    Flight(int c = 0, vector<string> f = {}, vector<int> tp = {}, vector<string> cn = {})
        : country(c), flightnumber(f), ticket_prices(tp), country_name(cn) {}

    void displayflight();
    void selectFlight();
    string getCountryName() const;
    int getTicketPrice() const;
};

class Tickets {
public:
    const Customer* customer;
    const Flight* flight;

    Tickets(const Customer* customer, const Flight* flight) : customer(customer), flight(flight) {}
    void print() const;
};

void Flight::displayflight() {
    cout << endl;
    cout << "---Welcome to Airlines--" << endl;
    cout << "|   1.To India\t\t|" << endl;
    cout << "|   2.To Canada\t\t|" << endl;
    cout << "|   3.To Japan\t\t|" << endl;
    cout << "|   4.To London\t\t|" << endl;
    cout << "|   5.To Dubai\t\t|" << endl;
    cout << "--------------------------" << endl << endl;
}

void Flight::selectFlight() {
    displayflight();
    cout << "Select your country you want to go: ";
    cin >> country;
    country_name = {"India", "Canada", "Japan", "London", "Dubai"};
    cout << "\nEnjoy the journey to " << country_name[country - 1] << endl;
    cout << "See your flight time and Tickets" << endl << endl;

    destination = country_name[country - 1];
	
	int flightNo;
    if (country == 1) {
        flightnumber = {"No-120", "No-180", "No-471"};
        ticket_prices = {35000, 30000, 37000};
        
        cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 10.00AM Rs. "<<ticket_prices[0]<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. "<<ticket_prices[1]<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-471"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. "<<ticket_prices[2]<<endl;
        
    }
    
    if(country==2){
    	flightnumber = {"No-120", "No-180", "No-471"};
        ticket_prices = {35000, 30000, 37000};
		
		cout<<"1. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 10.00AM Rs. "<<ticket_prices[0]<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-280"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. "<<ticket_prices[1]<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-571"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. "<<ticket_prices[2]<<endl;
	}
	
    if (country == 3) {
        flightnumber = {"No-120", "No-180", "No-471"};
        ticket_prices = {35000, 30000, 37000};
        
        cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 10.00AM Rs. "<<ticket_prices[0]<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. "<<ticket_prices[1]<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-471"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. "<<ticket_prices[2]<<endl;
    }
    
    if (country == 4) {
        flightnumber = {"No-120", "No-100", "No-071"};
        ticket_prices = {35000, 30000, 37000};
        
        cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 10.00AM Rs. "<<ticket_prices[0]<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-100"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. "<<ticket_prices[1]<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-071"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. "<<ticket_prices[2]<<endl;
    }
    
    if (country == 5) {
        flightnumber = {"No-120", "No-180", "No-471"};
        ticket_prices = {35000, 30000, 37000};
        
        cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 10.00AM Rs. "<<ticket_prices[0]<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. "<<ticket_prices[1]<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-471"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. "<<ticket_prices[2]<<endl;
    }
    

    cout << "\nEnter your desired flight: ";
    cin >> flightNo;
    selected_flight_index = flightNo - 1;
    cout << "Successfully booked flight- " << destination << "-" << flightnumber[flightNo - 1] << endl << endl;
}

string Flight::getCountryName() const {
    return destination;
}

int Flight::getTicketPrice() const {
    return ticket_prices[selected_flight_index];
}

void Tickets::print() const {
    cout << "\n\n****Sri Lankan Airlines*****" << endl;
    cout << "\tYour ticket is printed\n";
    cout << "\n\tName: " << customer->getName();
    cout << "\n\tID: " << customer->getid();
    cout << "\n\tGender: " << customer->getGender();
    cout << "\n\tDestination: " << flight->getCountryName();
    cout << "\n\tFlight Number: " << flight->flightnumber[flight->selected_flight_index];
    cout << "\n\tTicket Price: Rs. " << flight->getTicketPrice() << endl;
}

int main() {
    double ID;
    string Na;
    string gender;
    int choose;

    Customer c;
    Flight f;
    Tickets t(&c, &f);

    do {
        cout << "1. Customer details" << endl;
        cout << "2. Flight registration" << endl;
        cout << "3. Tickets and case" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choose;

        switch (choose) {
            case 1: {
                cout << "\nEnter customer Id: ";
                cin >> ID;
                cout << "Enter customer name: ";
                cin >> Na;
                cout << "Enter customer Gender: ";
                cin >> gender;

                c = Customer(ID, Na, gender);
                break;
            }
            case 2: {
                f.selectFlight();
                break;
            }
            case 3: {
                t.print();
                break;
            }
            case 4: {
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        cout << endl;
    } while (choose != 4);

    return 0;
}



/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer{
	protected:
		int Id;
		string Name;
		string Gender;
	public:
		Customer(int id=0,string name="",string gender=""):Id(id),Name(name), Gender(gender){}
		
		int getid(){
			return this->Id;
		}
		string getName(){
			return this->Name;
		}
		string  getGender(){
			return this->Gender;
		}				
};


class Flight{
	protected:
		int country;
		vector<string> flightnumber;
		vector<string> country_name;
		
	public:
		Flight(int c = 0, vector<string> f = {}) : country(c), flightnumber(f) {}	
		void displayfight();
		string selectcountry();
		
		string getcountyname(){
			
		}
			
};

class Tickets{
	public:
		Customer *customer;
		Flight *flight;
		Tickets(Customer *customer,Flight *flight):customer(customer),flight(flight){
		}	
		void print(){
			cout<<"\n\n****Sri Lankan Airlines*****"<<endl;
			cout<<"\tYour ticket is printed\n";
			cout<<"\n\tname: "<<customer->getName();
			cout<<"\n\tId: "<<customer->getid();
			cout<<"\n\tGender: "<<customer->getGender();
		}
};


void Flight::displayfight(){
	cout<<endl;
	cout<<"---Wel Come to Airlines--"<<endl;
	cout<<"|   1.To india\t\t|"<<endl;
	cout<<"|   2.To canada\t\t|"<<endl;
	cout<<"|   3.To japan\t\t|"<<endl;
	cout<<"|   4.To London\t\t|"<<endl;
	cout<<"|   5.To Dubai\t\t|"<<endl;
	cout<<"--------------------------"<<endl<<endl;
}

string Flight::selectcountry(){
	displayfight();
	cout<<"Select your contry you want to go:";
	cin>>country;
	country_name={"india","canada","japan","london","dubali"};
	cout<<"\nenjoy the journy to "<<country_name[country-1]<<endl;
	cout<<"see your fight time and Tickets"<<endl<<endl;
	string destination = country_name[country-1];


	if(country==1){
		int flightNo;
		flightnumber = {"No-120","No-180","No-471"};
		int ticket[]= {35000,30000,37000};
		int n =sizeof(ticket)/sizeof(ticket[1]);
		
		for(int i=0;i<n;i++){
			cout<<i+1<<". "<<country_name[country-1]<<flightnumber[i]<<endl;
			cout<<"\t\t04.03.2024 12.00AM Rs. "<<ticket[i]<<endl;
		}
		
		cout<<"\nEnter you Want flight: ";
		cin>>flightNo;
		switch(flightNo){
			case 1:{
				cout<<"Succesfully booked flight- "<<country_name[country-1]<<"-"<< flightnumber[flightNo-1];
				break;
			}
			case 2:{
				cout<<"Succesfully booked flight- "<<country_name[country-1]<<"-"<< flightnumber[flightNo-1];
				break;
			}
			case 3:{
				cout<<"Succesfully booked flight- "<<country_name[country-1]<<"-"<< flightnumber[flightNo-1];
				break;
			}
			default:{
				cout<<"please correctly enter!!!"<<endl;
				break;
			}
		}
		cout<<endl<<endl;
	}
	
	/*if(country==2){
		
		string flightnumber[] = {"No-180","No-280","No-571"};
		cout<<"1. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00AM Rs. 35000"<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-280"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. 30000"<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-571"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. 37000"<<endl;
		
		cout<<"\n Enter you Want flight: ";
		cin>>flightNo;
	}
	
	if(country==3){
		
		string flightnumber[] = {"No-120","No-180","No-471"};
		
		cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 12.00AM Rs. 35000"<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. 30000"<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-471"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. 37000"<<endl;
		
		cout<<"\n Enter you Want flight: ";
		cin>>flightNo;
	}
	
	if(country==4){
		string flightnumber[] = {"No-120","No-110","No-600"};
		
		cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 12.00AM Rs. 35000"<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-110"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. 30000"<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-600"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. 37000"<<endl;
		
		cout<<"\n Enter you Want flight: ";
		cin>>flightNo;
	}
	
	if(country==5){
		string flightnumber[] = {"No-120","No-180","No-471"};
		cout<<"1. "<<country_name[country-1]<<" No-120"<<endl;
		cout<<"\t\t04.03.2024 12.00AM Rs. 35000"<<endl;
		
		cout<<"2. "<<country_name[country-1]<<" No-180"<<endl;
		cout<<"\t\t04.03.2024 12.00PM Rs. 30000"<<endl;
		
		cout<<"3. "<<country_name[country-1]<<" No-471"<<endl;
		cout<<"\t\t04.03.2024 02.00AM Rs. 37000"<<endl;
		
		cout<<"\n Enter you Want flight: ";
		cin>>flightNo;
	}
	





int main(){
    int ID;
    string Na;
    string gender;
    int choose;
   
    Customer c;
	Flight f;
	
	

	do{ 
		cout<<"1.Customer details"<<endl;
		cout<<"2.Flight registrasion"<<endl;
		cout<<"3.Tikets and case"<<endl;
	    cout<<"4.Exit"<<endl;
	    cout<<"enter your chosse:";
	    cin>>choose;
		switch(choose){
			case 1:{
				cout<<endl;
					cout<<"Enter customer Id: ";
					cin>>ID;
					cout<<"Enter customer name: ";
					cin>>Na;
					cout<<"Enter customer Gender: ";
					cin>>gender;
					
					c = Customer(ID,Na,gender);		
				break;
			}
			case 2:{
			//	cout<<f.selectcountry();
				break;
			}
			case 3:{
				Tickets t(&c,&f);
				t.print();
				break;
			}
			case 4:{
				break;
			}
		}
		cout<<endl;
	}while(choose!=4);
	
} 


*/


