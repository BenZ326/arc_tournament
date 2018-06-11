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
	int _idx;		//�������
	int _type_idx;	//���͵�id��1�����������ģ�2�����̼ң�3������վ
	double _lng;	//����
	double _lat;	//γ��
	double _pack_total_weight;	//����������(t)
	double _pack_total_volume;	//���������(m^3)
	boost::posix_time::time_duration _first_receive_tm;	//�̼������ջ�ʱ��
	boost::posix_time::time_duration _last_receive_tm;	//�̼������ջ�ʱ��
};

#endif