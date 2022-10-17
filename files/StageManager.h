#pragma once
#include "TVChannelEmployee.h"

class StageManager : public TVChannelEmployee
{
	Genre genre;
public:
	StageManager();
	StageManager(IdentityData identityData);
	~StageManager();
	void set_genre(Genre);
	Genre get_genre();
	void create_data();
	/*friend istream& operator>>(istream& in, StageManager& obj);
	friend ostream& operator<<(ostream& out, StageManager& obj);*/
};