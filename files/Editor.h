#pragma once
#include"StageManager.h"

class Editor : public TVChannelEmployee
{
	Genre genre;
public:
	Editor();
	Editor(IdentityData identityData);
	~Editor();
	void set_genre(Genre);
	Genre get_genre();
	void create_data();
	/*friend istream& operator>>(istream& in, Editor& obj);
	friend ostream& operator<<(ostream& out, Editor& obj);*/
};