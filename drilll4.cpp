#include "std_lib_facilities.h"

int main(){

	cout<<"Enter the name of the person you want to write to:\n";
	String first_name;
	cin >> first_name;
	cout<<"Dear "<< first_name <<",\n";

	cout<<"How are you? I am fine. I miss you. \n";


	String friend_name;
	cout<<"Tell me someone from our friend group:\n";
	cin>> friend_name;
	cout<<"Have you seen "<<friend_name<<" lately?\n";

	char friend_sex;
	cout<<"Could you tell me "<<friend_name<<"'s sex? If male write \"m\", if female write \"f\" : \n";
	cin>>friend_sex;
	if( friend_sex == 'f')
	{
		cout<<"If you see "<<friend_name<<" please ask her to call me!\n";
	}
	if( friend_sex == 'm')
	{
		cout<<"If you see "<<friend_name<<" please ask him to call me!\n";
	}

	cout<<"How old are you ?\n";
	int age;
	cin>>age;

	if( age > 110 || age < 0)
	{
		simple_error("You're kidding!\n");
	}
	else
	{
		cout<<"I hear you just had a birthday and you are "<<age<<" years old!\n";
	}


	if(age < 12 )
	{
		cout<<"Next year you will be "<<age++<<"\n";
	}
	if( age == 17)
	{
		cout<<"Next year you will be able to vote\n";
	}
	if( age > 70 )
	{
		cout<<"I hope you are enjoying retirement.\n";
	}

	cout<<"Yours sincerely,  Patrik!\n";




}
