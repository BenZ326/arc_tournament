#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "jdhead.h"

class vehicle
{
public:
	static vehicle* createObj(const std::vector<std::string> &cells);
	int TypeId() const {return _vehicle_type_id;}
	std::string TypeName() const {return _vehicle_type_name;}
	double MaxVolume() const {return _max_volume;}
	double MaxWeight() const {return _max_weight;}
	int VehicleCnt() const {return _vehicle_cnt;}
	int DrivingRange() const {return _driving_range;}
	double ChargeTm() const {return _charge_tm;}
	double UnitTransCost() const {return _unit_trans_cost;}
	double VehicleCost() const {return _vehicle_cost;}
private:
	int _vehicle_type_id;	//车型编号
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