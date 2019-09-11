#include <iostream>
#include <string>
using namespace std;

class info
{
public:
	info(string, string, int, int);
	void increment_age();
	int get_age() const;
	string get_name() const;
private:
	string first;
	string last;
	int age;
	int ssn;
};
////////////////////////////////////////////////////////////////
class user
{
public:
	user(string, string, int, string, int);
	void increment_age();
	string get_name() const;
	int get_age() const;

private:
	string username;
	info user_info; //this is the whole point of composition
};

/*-------------------------------------------------------
info class function implementations
-------------------------------------------------------*/

/*-------------------------------------------------------
info class constructor that sets first name, last name,
age, and social fields
-------------------------------------------------------*/
info::info(string fname, string lname, int a, int social)
{
	first = fname;
	last = lname;
	age = a;
	ssn = social;
}

/*-------------------------------------------------------
increments the age field
-------------------------------------------------------*/
void info::increment_age()
{
	age++;
}

/*-------------------------------------------------------
returns age field
-------------------------------------------------------*/
int info::get_age() const
{
	return age;
}

/*-------------------------------------------------------
returns the first and last name
-------------------------------------------------------*/
string info::get_name() const
{
	return first + " " + last;
}

/*-------------------------------------------------------
user class function implementations
-------------------------------------------------------*/

/*-------------------------------------------------------
constructor that sets user name and the user_info object
-------------------------------------------------------*/
user::user(string fname, string lname, int a, string uname, int ssn)
{
	username = uname;
}

/*-------------------------------------------------------
increments user object's age by calling user_info object's
increment_age()
-------------------------------------------------------*/
void user::increment_age()
{
	
}
/*-------------------------------------------------------
returns the user object's name by calling user_info object's
get_name() function
-------------------------------------------------------*/
string user::get_name() const
{
	
}
/*-------------------------------------------------------
returns user object's age by calling user_info object's
get_age() function
-------------------------------------------------------*/
int user::get_age() const
{
	
}

int main()
{
	user person("John", "Smith", 26, "john1989", 123456789);

	cout << person.get_name() << endl;
	cout << person.get_age() << endl;
	person.increment_age();
	cout << person.get_age() << endl;
	
	return 0;
}