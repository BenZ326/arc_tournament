#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "jdhead.h"

class vehicle
{
public:
	static vehicle* createObj();
private:
	std::string _vehicle_type_id;	//车型编号
	std::string _vehicle_type_name;	//车型名称
	double _max_volume;		//最高装载容积(m^3)
	double _max_weight;		//核定载重(t)
	int _vehicle_cnt;		//车辆数量(台)
	int _driving_range;		//持续里程(m)
	double _charge_tm;		//充电时间(h)
	double _unit_trans_cost;	//每公里运输成本(元)
	double _vehicle_cost;		//车辆使用成本(元/天)
};


#endif