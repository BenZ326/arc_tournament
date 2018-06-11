#include "vehicle.h"
#include "jdhead.h"

vehicle* vehicle::createObj(const std::vector<std::string> &cells)
{
	vehicle* obj=new vehicle();
	int index=0;
	obj->_vehicle_type_id=std::stoi(cells[index++]);
	obj->_vehicle_type_name=cells[index++];
	obj->_max_volume=std::stod(cells[index++]);
	obj->_max_weight=std::stod(cells[index++]);
	obj->_vehicle_cnt=99999;
	index++;
	obj->_driving_range=std::stoi(cells[index++]);
	obj->_charge_tm=std::stod(cells[index++]);
	obj->_unit_trans_cost=std::stod(cells[index++]);
	obj->_vehicle_cost=std::stod(cells[index++]);
	return obj;
}