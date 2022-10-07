#include "TVChannelEmployee.h"
#include"IdentityData.h"

TVChannelEmployee::TVChannelEmployee()
{
	this->place_of_work = "News";
}
TVChannelEmployee::~TVChannelEmployee()
{

}
void TVChannelEmployee::create_data()
{
	identity_data.create_identity_data();
}
void TVChannelEmployee::print_data()
{
	identity_data.print_identity_data();
}
employeeTypes TVChannelEmployee::type_checker()
{
	if (typeid(*this) == typeid(Anchorman))
		return anchorman;
	if (typeid(*this) == typeid(Operator))
		return _operator;
	if (typeid(*this) == typeid(StageManager))
		return stage_manager;
	if (typeid(*this) == typeid(Editor))
		return editor;
}