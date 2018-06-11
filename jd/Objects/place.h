#ifndef _PLACE_H_
#define _PLACE_H_
#include "jdhead.h"


class place
{
public:
	static place* createObj(const std::vector<std::string> &cells);
	int Idx() const {return _idx;}
	int TypeIdx() const {return _type_idx;}
	double Lng() const {return _lng;}
	double Lat() const {return _lat;}
	double PackTotalWeight() const {return _pack_total_weight;}
	double PackTotalVolume() const {return _pack_total_volume;}
	boost::posix_time::time_duration FRT() const {return _first_receive_tm;}
	boost::posix_time::time_duration LRT() const {return _last_receive_tm;}
private:
	int _idx;		//主键序号
	int _type_idx;	//类型的id，1代表配送中心，2代表商家，3代表充电站
	double _lng;	//经度
	double _lat;	//纬度
	double _pack_total_weight;	//包裹总重量(t)
	double _pack_total_volume;	//包裹总体积(m^3)
	boost::posix_time::time_duration _first_receive_tm;	//商家最早收货时间
	boost::posix_time::time_duration _last_receive_tm;	//商家最晚收货时间
};

#endif