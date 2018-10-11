#include "std_lib_facilities.h"

const double m=100,in=2.54,ft=12;

void rendezes(vector<double> &szamok)
{
vector<double> rendezett;
double rendez=0;
for(int i=0;i<=szamok.size()-1;i++)
{
	for(int k=0;k<szamok.size();k++)
	{
		if(szamok[i]<szamok[k])
		{
			rendez=szamok[i];
			szamok[i]=szamok[k];
			szamok[k]=rendez;
		}
	}
}

}




int main()
{	double max=0,min=0,szum=0;
	vector<double> szamok;
	double szam1;
	string mt="";
	int mtsz,counter=0;




	while(!cin.fail())
	{
		double kul=1.0/100;
		cout<<"Add meg a szamot,mertekegyseget[0-cm,1-m,2-in,3-ft]:";
		cin>>szam1>>mt;



		if(mt=="cm")
			{mtsz=0;}
		else if(mt=="m")
			{mtsz=1;}
		else if(mt=="in")
			{mtsz=2;}
		else if(mt=="ft")
			{mtsz=3;}


		switch(mtsz)
		{
			case 0:szam1=szam1/m; break;
			case 1:szam1=szam1; break;
			case 2:szam1=(szam1*in)/m; break;
			case 3:szam1=(szam1*(ft*in))/m; break;
			default: cout<<"Hibás mértékegység!"<<endl;
		}


		szum+=szam1;
		szamok.push_back(szam1);

	}


	szamok.erase(szamok.begin()+(szamok.size()-1));
	max=szamok[0];
	min=szamok[0];


	for(int i=1;i<szamok.size();i++)
	{
		if(szamok[i]>max)
			{max=szamok[i];}
		if(szamok[i]<min)
			{min=szamok[i];}
	}



	counter=szamok.size();
	cout<<"The largerst number: "<<max<<" the smallest number: "<<min<<endl;
	cout<<"osszeg="<<szum<<"m"<<endl;
	cout<<"Elemek szama:"<<counter<<endl;

	rendezes(szamok);
	for(unsigned int k=0;k<szamok.size();k++)
		{cout<<szamok[k]<<"m"<<endl;}



return 0;
}

