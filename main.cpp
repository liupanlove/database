#include"GPTree.h"
#include<iostream>
#include"car.h"
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

Ans ans;

vector<Car> cars;

string split_string(const string& s, const string& c)
{
	vector<string> ret;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        ret.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        ret.push_back(s.substr(pos1));
    //return ret;
	return ret[ret.size() - 1];
}

void init()
{
	ans.init();
	ans.read();
	ans.build_tree();

}

void read_cars()
{
	ifstream fin("data/car.txt");
	//while(!fin.eof())
	for(int i = 0; i < 100000; ++i)
	{
		Car car;

		int tmp;
		string str;
		fin >> tmp >> car.num; // >> tmp1 >> tmp2;
		fin >> str;
		car.position = atoi(split_string(str, ",").c_str());

		for(int j = 0; j < car.num; ++j)
		{
			fin >> str;
			int tmp = atoi(split_string(str, ",").c_str());

			car.passenger.push_back(tmp);
		}

		cars.push_back(car);
	}
	fin.close();
}

void print_cars()
{
	for(int i = 0; i < cars.size(); ++i)
	{
		cout << i << " ";
		cout << cars[i].position << " " << cars[i].num << " ";

		for(int j = 0; j < cars[i].num; ++j)
		{
			cout << cars[i].passenger[j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	//Ans ans;
	ans.init();
	ans.load();
	/*ans.read();

	ans.build_tree();*/

	//ans.save();
	read_cars();

	print_cars();
	
	ans.test();
	
	return 0;
}
