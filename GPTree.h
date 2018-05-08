#ifndef GPTREE_H
#define GPTREE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<ctime>
#include<fstream>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<sys/time.h>
#include<metis.h>

double Euclidean_Dist(int S,int T);

class Ans
{
public:
	void init();
	void read();
	void save();
	void load();
	void build_tree();

	int get_min_distance(int S, int T);

	//void test();
	void read_node();
	void output();

};
#endif
