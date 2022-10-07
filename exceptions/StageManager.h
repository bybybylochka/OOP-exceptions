#pragma once
#include "TVChannelEmployee.h"
enum Genre {
	sport,
	news,
	weather
};
class StageManager: public TVChannelEmployee
{
	Genre genre;
public:
	StageManager();
	~StageManager();
	void set_genre(Genre);
	Genre get_genre();
	void create_data();
	void print_data();
};

