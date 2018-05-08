#include"GPTree.h"
#include<iostream>
#include"car.h"
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;


#define TIME_TICK_START gettimeofday( &tv, NULL ); ts = tv.tv_sec * 100000 + tv.tv_usec / 10;
#define TIME_TICK_END gettimeofday( &tv, NULL ); te = tv.tv_sec * 100000 + tv.tv_usec / 10;
#define TIME_TICK_PRINT(T) printf("%s RESULT: %lld (0.01MS)\r\n", (#T), te - ts );


struct timeval tv;
long long ts, te;

vector<vector<int>> permutations[5]; //全排列

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
	//ans.init();
	//ans.read();
	//ans.build_tree();
	ans.load();

	for(int i = 0; i < 5; ++i)	build_permutations(0, i);
}

bool is_access[5];
int min_distance;
vector<int> positions;

void build_permutations(int num, int max)
{
	if(num == 0)
	{
		for(int i = 0; i < 5; ++i) is_access[i] = false;
		positions.clear();

	}
	if(num == max)
	{
		vector<int> tmp = points;
		permutations[max].push_back(tmp);

	}
	else
	{
		for(int i = 0; i < destinations.size(); ++i)
		{
			if(!is_access[i])
			{
				positions.push_back(i);
				is_access[i] = true;
				build_permutations(num + 1, max);

				is_access[i] = false;
				positions.pop_back();
			}
		}
	}

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



/*void calculate_distance(vector<int> &destinations, int car_position, int num)
{
	if(num == 0)
	{
		for(int i = 0; i < 5; ++i) is_access[i] = false;
		min_distance = 2147483647;
		positions.clear();

	}
	if(num == destinations.size())
	{
		int curr = car_position;
		int distance = 0;

		for(int i = 0; i < positions.size(); ++i)
		{
			//cout << positions[i] << " ";
			distance += ans.get_min_distance(curr, destinations[positions[i]]);
			curr = destinations[positions[i]];
		}
		//out << endl;

		if(distance < min_distance) min_distance = distance;
	}
	else
	{
		for(int i = 0; i < destinations.size(); ++i)
		{
			if(!is_access[i])
			{
				positions.push_back(i);
				is_access[i] = true;
				calculate_distance(destinations, car_position, num + 1);

				is_access[i] = false;
				positions.pop_back();
			}
		}
	}

}*/

int main()
{
	int current_position, destination; // node No
	//Ans ans;
	//ans.init();
	//ans.load();
	//ans.read();
	init();

	//ans.build_tree();

	///ans.save();
	read_cars();

	

	//print_cars();

	//ans.output();
	
	cout << "please input your position: ";
	cin >> current_position;
	cout << "please input your destination: ";
	cin >> destination;

	for(int i = 0; i < 5; ++i)
	{
		cout << i << endl;
		for(int j = 0; j < permutations[i].size(); ++j)
		{
			for(int k = 0; k < permutations[i][j].size(); ++k)
				cout << permutations[i][j][k] << " "
			cout << endl;
		}
	}
	//cout << Euclidean_Dist(S, T) << endl;

	//TIME_TICK_START

	
	/*int cnt = 0;
	for(int i = 0; i < 100000; ++i)
	{
		//cout << cars[i].position << " " << pos << endl;
		double distance = Euclidean_Dist(cars[i].position, current_position);
		if(distance < 11000)
		{
			//cout << i << endl;
			cnt ++;
			if(cars[i].num < 4)  // 
			{
				int D2 = ans.get_min_distance(cars[i].position, current_position);
				int D4 = ans.get_min_distance(current_position, destination);
				
				cars[i].passenger.push_back(destination);


				//cout << cars[i].num << endl;
				calculate_distance(cars[i].passenger, cars[i].position, 0);
				int D3 = min_distance;
				if(D3 - D4 > 10000) continue;

				cars[i].passenger.pop_back();

				calculate_distance(cars[i].passenger, cars[i].position, 0);

				int D1 = min_distance;
				if(D2 + D3 - D1 > 10000) continue;

				cout << i << endl;

				
				///cout << "min_distance = " << min_distance << endl;
				//if(cnt > 10) return 0;
			}


		}
	}
	cout << cnt << endl;*/
	//TIME_TICK_END
	//TIME_TICK_PRINT("haipa");

	//ans.test();
	
	return 0;
}
