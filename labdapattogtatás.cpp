#include "std_lib_facilities.h"
#include <unistd.h>

void draw(vector<string> v, int x, int y, char c);

int main()
{
	vector<string> v; ///a p�lya, amin pattog a labda
	v.push_back("##########################################################");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("##########################################################");

	int xlen=v[0].length()-1;  ///a "p�lya" sz�less�ge-1
	int ylen=v.size()-1;		 ///a "p�lya" magass�ga-1

	int i=1; ///sz�ml�l�



	int x=1,y=1; ///koordin�t�k �s kezd��rt�k ad�s
	while(1)
	{
		x=abs(xlen-i%(2*xlen)); ///x koordin�t�k sz�m�t�sa
		y=abs(ylen-i%(2*ylen)); ///y koordin�t�k sz�m�t�sa
		draw(v,x,y,'@');
		i++;
		usleep(50000);
	}
	return 0;
}

void draw(vector<string> v, int x, int y, char c) ///Rajzol�s�rt felel�s f�ggv�ny
{
	system("clear");
	v[y][x]=c;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}


}
