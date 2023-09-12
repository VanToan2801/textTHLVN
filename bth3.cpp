#include <iostream>
#include <vector>
#define max 100

using namespace std;

struct Customer
{
	string name;
	string address;
	vector <string> phoneNumbers;
};

struct ListOfCustomers
{
	Customer arrCus[max];
	int numOfCus;
};

void inputCustomer(Customer &c);
void inputListOfCustomers(ListOfCustomers& list);
void outputCustomer(Customer c);
void outputListOfCustomers(ListOfCustomers list);

//Inserst a customer into the list at the specified index
void insertCustomer(ListOfCustomers& list, Customer customer, int index);

//Delete a customer in the list at the specified index
void deleteCustomer(ListOfCustomers& list, int index);

//Search a customer in the list by name
int findCustomerByName(ListOfCustomers& list, string name);

//Delete a customer in the list by name
void deleteCustomerByName(ListOfCustomers &list, string name);

//Find a customer in the list by phone numbers
int findCustomerByPhone(ListOfCustomers list, string phone);
int main()
{
	Customer c, insC;
	ListOfCustomers l; 
	string name, nameFind, phone;
	int k, fN;
	inputListOfCustomers(l);
	outputListOfCustomers(l);
//	cout<<"import a new customer: "<<endl;
//	inputCustomer(insC);
//	cout<<"import the index you want to insert: "<<endl;
//	cin>>k;
//	insertCustomer(l,insC,k);
//	outputListOfCustomers(l);
//	
//	cout<<"import the index you want to delete: "<<endl;
//	cin>>k;
//	deleteCustomer(l, k);
//	outputListOfCustomers(l);
//	
//	cout << "Name of customer you want find: "; getline(cin, nameFind);
//	fN=findCustomerByName(l, nameFind);
//	if (fN==-1) cout<<"not found that name!"<<endl;
//	else cout <<"found with name at "<<fN<<endl;
//
//	name= "Nam";
//	deleteCustomerByName(l, name);
//	cout <<"deleted!"<<endl;
//	outputListOfCustomers(l);

	k = findCustomerByPhone(l, phone);
	if (k == -1) cout <<"not found!!"<<endl;
	else cout <<"the customer have a phone number: "<<phone<<"at "<<k<<endl;
	
}

void inputCustomer(Customer &c)
{
	int i, n; string phone;
	fflush(stdin);
	cout << "Name: "; getline(cin, c.name);
	cout << "Address: "; getline(cin, c.address);
	cout << "Num of phones: "; cin >> n;
	fflush(stdin);
	for (i = 0; i < n; i++)
	{
		cout << "Phone number " << i << " : "; getline(cin, phone);
		c.phoneNumbers.push_back(phone);
	}
}

void inputListOfCustomers(ListOfCustomers& list)
{
	cout << "Number of customers: "; cin >> list.numOfCus;
	for(int i = 0; i < list.numOfCus; i++)
	inputCustomer(list.arrCus[i]);
}

void outputCustomer(Customer c)
{
	int i;
	cout << "Name: " << c.name << endl;
	cout << "Address: " << c.address << endl;
	cout << "List of phones: " ;
	for (i = 0; i < c.phoneNumbers.size(); i++)
	cout << c.phoneNumbers[i] << " ";
	cout << endl;
}

void outputListOfCustomers(ListOfCustomers list)
{
	cout << "Number of customers: " << list.numOfCus << endl;
	for(int i = 0; i < list.numOfCus; i++)
	outputCustomer(list.arrCus[i]);
}

void insertCustomer(ListOfCustomers& list, Customer customer, int index)
{
	for (int i=list.numOfCus; i>index; i--)
		list.arrCus[i]=list.arrCus[i-1];
	list.arrCus[index]=	customer;
	list.numOfCus++;
}

void deleteCustomer(ListOfCustomers& list, int index)
{
	for (int i=index; i<list.numOfCus-1; i++)
	list.arrCus[i]=list.arrCus[i+1];
	list.numOfCus--;
}

int findCustomerByName(ListOfCustomers& list, string name)
{
	for (int i=0; i< list.numOfCus; i++)
	if (list.arrCus[i].name==name) return i;
	return -1;
}

void deleteCustomerByName(ListOfCustomers &list, string name)
{
	int in;
	in = findCustomerByName(list, name);
	deleteCustomer(list, in);
}

//int findCustomerByPhone(ListOfCustomers list, string phone)
//{
//	for (int i=0; i<list.numOfCus; i++)	
//	if (list.arrCus[i].phoneNumbers==phone)
//		return i;
//	return -1;
//}
