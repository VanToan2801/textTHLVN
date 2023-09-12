#include <iostream>
#include <fstream>
#include <cstring>
#include<string.h>

using namespace std;

struct Student
{
	string name;
	int age;
	float gpa;
};

void inputStudent(struct Student &s);
void printStudent(struct Student s);
void inputListOfStudent(struct Student list[], int n);
void printListOfStudent(struct Student list[], int n);
int findStudent(struct Student list[], int n, string name);
void writeToFile(struct Student list[], int n, string fname);
void listOfGoodStudent(struct Student list[], int n);
int appendStudent(struct Student list[], int n, struct Student s);
string getLastName (string name);
int countFirstName(struct Student list[], int n);
string convertName(string name);
void sortVNName(struct Student list[], int n);

int main()
{
	struct Student m[100];
	struct Student s;
	string name;
	int k, sl, count;
	inputListOfStudent(m, 2);
	system("cls");
	printListOfStudent(m, 2);
	fflush(stdin);
	cout << "Input name for find: "; 
	getline(cin, name);
	k = findStudent(m, 2, name);
	if (k == -1)
		cout << "Not found!";
		else
	printStudent(m[k]);
//	writeToFile(m, 2, "dssv.txt");
	cout<<"\nList of Good Student: "<<endl;
	listOfGoodStudent(m, 2);
	cout <<"input the student that you want to add at the last of list"<<endl;
	inputStudent(s);
	int n=2;
	sl	= appendStudent(m, n, s);
	cout << "done!"<<endl;
	printListOfStudent(m, sl);
	count = countFirstName(m,sl);
	cout <<"count the last name is 'Nguyen': "<<count<<endl;
	sortVNName(m, sl);
	cout <<"the list after sort a-z"<<endl;
	printListOfStudent(m, sl);
	sortVNName(m, sl);
}

void inputStudent(struct Student &s)
{
	cout << "Name: "; getline(cin, s.name);
	cout << "Age: "; cin >> s.age;
	cout << "GPA: "; cin >> s.gpa;
}

void printStudent(struct Student s)
{
	cout << "Name: " << s.name << endl;
	cout << "Age: " << s.age << endl;
	cout << "GPA: " << s.gpa << endl;
}

void inputListOfStudent(struct Student list[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		cout <<"student "<<i+1<<endl;
		inputStudent(list[i]);
	}
}

void printListOfStudent(struct Student list[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	printStudent(list[i]);
}

int findStudent(struct Student list[], int n, string name)
{
	int i;
	for(i = 0; i < n; i++)
	if(list[i].name == name)
		return i;
	return -1;
}

//void writeToFile(struct Student list[], int n, string fname)
//{
//	fstream out;
//	out.open(fname, ios::out);
//	for (int i=0; i<n; i++)
//		out << list[i].name <<", "<<list[i].age<<", "<<list[i].gpa<<endl;
//	out.close();
//}

void listOfGoodStudent(struct Student list[], int n)
{
	for (int i=0; i<n; i++)
	if (list[i].gpa>=8.0)
	printStudent(list[i]);	
}

int appendStudent(struct Student list[], int n, struct Student s)
{	
	list[n] = s;
	return n+1;
}

string getLastName (string name, int c)
{
	return name.substr(0, c);
}

int countFirstName(struct Student list[], int n)
{
	int count=0;
	string st;
	
	for (int i =0; i<n; i++ )
	{
		st= getLastName(list[i].name, 6);
		if (st=="nguyen")
			count++;
	}
	return count;
}

string convertName(string name)
{
	int location;
	location = name.rfind(" ");
	return name.substr(location+1)+" "+name.substr(0,location);
}

void sortVNName(struct Student list[], int n)
{
	string s1, s2, temp;
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
	{
		s1 = convertName(list[i].name);
		s2 = convertName(list[j].name);
		
		//		st1=s1.substr(0,1);
//		st2 = s2.substr(0,1);
		if (strcmp(s1,s2)==1) 
		{
			Student s=list[i];
			list[i]=list[j];
			list[j]=s;
		}
	}
}
