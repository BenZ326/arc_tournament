#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "jdhead.h"

class vehicle
{
public:
	static vehicle* createObj();
private:
	std::string _vehicle_type_id;	//���ͱ��
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