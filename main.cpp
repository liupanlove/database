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

vector<vector<int> > permutations[5]; //全排列

Ans ans;

vector<Car> cars;

int distance_matrix[6][6];

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


bool is_access[5];
//int min_distance;
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
		vector<int> tmp = positions;
		permutations[max].push_back(tmp);

	}
	else
	{
		for(int i = 0; i < max; ++i)
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


void init()
{
	//ans.init();
	//ans.read();
	//ans.build_tree();
	ans.load();

	for(int i = 0; i < 5; ++i)	build_permutations(0, i);

	for(int i = 0; i < 6; ++i) distance_matrix[i][i] = 0;
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



int calculate_distance(vector<int> &destinations, int car_position, bool is_repeat = false)
{
	int min_distance = 2147483647;
	int size = destinations.size();
	//cout << size << endl;

	if(!is_repeat)
	{
		for(int i = 1; i <= size; ++i)
		{
			distance_matrix[0][i] = ans.get_min_distance(car_position, destinations[i - 1]);

			distance_matrix[i][0] = distance_matrix[0][i];
		}

		for(int i = 1; i <= size; ++i)
		{
			for(int j = i + 1; j <= size; ++j)
			{
				distance_matrix[i][j] = ans.get_min_distance(destinations[i - 1], destinations[j - 1]);
				distance_matrix[j][i] = distance_matrix[i][j];
			}
		}
	}

	/*for(int i = 0; i <= size; ++i)
	{
		for(int j = 0; j <= size; ++j) cout << distance_matrix[i][j] << " ";
		cout << endl;
	}
	*/


	for(int i = 0; i < permutations[size].size(); ++i)
	{
		/*int distance = 0;
		int current = car_position;
		for(int j = 0; j < size; ++j)
		{
			distance += ans.get_min_distance(current, destinations[permutations[size][i][j]]);
			current = destinations[permutations[size][i][j]];
		}*/

		int distance = 0;
		if(size > 0)
		{
			distance = distance_matrix[0][permutations[size][i][0] + 1];
			//int current = permutations[size][0][0] + 1;

			for(int j = 1; j < size; ++j)
			{
				//cout << permutations[size][i][j - 1] + 1 << "  " << permutations[size][i][j] + 1 << endl;
				distance += distance_matrix[permutations[size][i][j - 1] + 1][permutations[size][i][j] + 1];
			}
		}
		if(distance < min_distance) min_distance = distance;
	}

//	cout << "min_distance: " << min_distance << endl;
	return min_distance;
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


bool is_cars(int current_position, int destination, int car_num)
{
	
}
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
	
	/*cout << "please input your position: ";
	cin >> current_position;
	cout << "please input your destination: ";
	cin >> destination;*/
	//current_position = 285434;
//	destination = 227465;

	/*for(int i = 0; i < 5; ++i)
	{
		cout << i << endl;
		for(int j = 0; j < permutations[i].size(); ++j)
		{
			for(int k = 0; k < permutations[i][j].size(); ++k)
				cout << permutations[i][j][k] << " ";
			cout << endl;
		}
	}*/
	//cout << Euclidean_Dist(S, T) << endl;

	//long long cnt = 0;
	TIME_TICK_START

	for(int m = 0; m < 1; ++m){
		//cout << m << endl;
		current_position = 285434;//rand() % 338024;
		destination = 227465;//rand() % 338024;
		for(int i = 0; i < 100000; ++i) //
		{
			//cout << cars[i].position << " " << pos << endl;
			//TIME_TICK_START
			double distance = Euclidean_Dist(cars[i].position, current_position);
			//TIME_TICK_END
			
			//cnt += (te- ts);
			if(distance < 11000)
			{
				//cout << i << endl;
				//cnt ++;
				if(cars[i].num < 4)  // 
				{
					//TIME_TICK_START
					int D2 = ans.get_min_distance(cars[i].position, current_position);
					int D4 = ans.get_min_distance(current_position, destination);
					
				//	TIME_TICK_END
			
					//cnt += (te- ts);
					
					
					cars[i].passenger.push_back(destination);


					//cout << cars[i].num << endl;
					//TIME_TICK_START
					int  D3 = calculate_distance(cars[i].passenger, current_position);
					//TIME_TICK_END
					//cnt += (te- ts);


					cars[i].passenger.pop_back();
					if(D3 - D4 > 10000) continue;
					
					//cout << "haipa" << endl;
					//TIME_TICK_START

					int D1 = calculate_distance(cars[i].passenger, cars[i].position); //, true);
					//TIME_TICK_END
					//cnt += (te- ts);


					if(D2 + D3 - D1 > 10000) continue;


					//cout << "car_num: "  << i << endl;
					///cout << "min_distance = " << min_distance << endl;
					//if(cnt > 10) return 0;

				//	if(i > 10) break;
				}


			}
			//break;
		}
	}

	//cout << cnt << endl;
	TIME_TICK_END
	TIME_TICK_PRINT("haipa");

	//ans.test();
	
	return 0;
}
