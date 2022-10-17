#pragma once
#include"StageManager.h"
#include"Employees.h"
#include<vector>
class TVShow
{
	string name;
	Genre genre;
	vector<TVChannelEmployee*> team;
	Employees employee;
public:
	TVShow();
	TVShow(Employees employee);
	TVShow(const TVShow&);
	~TVShow();
	void set_name(string);
	void set_genre(Genre);
	string get_name();
	Genre get_genre();
	void create_TVShow();
	void print_TVShow();
};