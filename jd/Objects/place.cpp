#include"place.h"

place* place::createObj(const std::vector<std::string> &cells)
{
	assert(cells.size()==8);
	place* obj=new place();
	int index=0;
	obj->_idx=std::stoi(cells[index++]);
	obj->_type_idx=std::stoi(cells[index++]);
	obj->_lng=std::stod(cells[index++]);
	obj->_lat=std::stod(cells[index++]);
	if(obj->_type_idx==1)			//如果是配送中心
	{
	obj->_pack_total_weight=NULL;
	obj->_pack_total_volume=NULL;
	index++;
	index++;
	obj->_first_receive_tm=boost::posix_time::duration_from_string(cells[index++]);
	obj->_last_receive_tm=boost::posix_time::duration_from_string(cells[index++]);
	
	}
	if(obj->_type_idx==2)			//如果是客户点
	{
		obj->_pack_total_weight=std::stod(cells[index++]);
		obj->_pack_total_volume=std::stod(cells[index++]);	
		obj->_first_receive_tm=boost::posix_time::duration_from_string(cells[index++]);
		obj->_last_receive_tm=boost::posix_time::duration_from_string(cells[index++]);
	}
	if(obj->_type_idx==3)
	{
		obj->_pack_total_weight=NULL;
		obj->_pack_total_volume=NULL;	
		obj->_first_receive_tm=boost::posix_time::duration_from_string("00:00:00");
		obj->_last_receive_tm=boost::posix_time::duration_from_string("00:00:00");
	}
	std::cout<<obj->_first_receive_tm.hours()<<"h"<<obj->_first_receive_tm.minutes()<<std::endl;
	return obj;
}
