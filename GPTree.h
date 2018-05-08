#ifndef GPTREE_H
#define GPTREE_H


class Ans
{
public:
	void init();
	void read();
	void save();
	void load();
	void build_tree();

	int get_min_distance(int S, int T);

	void test();

};
#endif
