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
	int _vehicle_type_id;	//���ͱ��
	std::string _vehicle_type_name;	//��������
	double _max_volume;		//���װ���ݻ�(m^3)
	double _max_weight;		//�˶�����(t)
	int _vehicle_cnt;		//��������(̨)
	int _driving_range;		//�������(m)
	double _charge_tm;		//���ʱ��(h)
	double _unit_trans_cost;	//ÿ��������ɱ�(Ԫ)
	double _vehicle_cost;		//����ʹ�óɱ�(Ԫ/��)
};


#endif