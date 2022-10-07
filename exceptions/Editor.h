#pragma once
#include "TVChannelEmployee.h"
#include"StageManager.h"

class Editor : public TVChannelEmployee
{
	Genre genre;
public:
	Editor();
	~Editor();
	void set_genre(Genre);
	Genre get_genre();
	void create_data();
	void print_data();
};

