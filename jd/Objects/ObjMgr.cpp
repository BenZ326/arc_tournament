#include "ObjMgr.h"
#include "place.h"
#include "vehicle.h"
#include "jdhead.h"
#include "../utility/csvloader.h"
#include "../utility/csvobj.h"

ObjMgr* ObjMgr::_instance=NULL;

ObjMgr* ObjMgr::instance()
{
	if(!_instance)
	{
		_instance=new ObjMgr();
	}
	return _instance;
}

void ObjMgr::cleardump()
{

}

void ObjMgr::loadplaces()
{
	const char* file_name="input_node.input";
	CSVRowMapper<place> mapper;
	mapper(file_name);
	std::cout<<"\n place loaded from "<<mapper.result.size()<<file_name<<std::endl;
	const std::list<place*>& places_loaded=mapper.result;
	for(std::list<place*>::const_iterator iter=places_loaded.begin();
		iter!=places_loaded.end();++iter)
	{
		place* item=const_cast<place*>(*iter);
		_places.insert(std::make_pair(item->Idx(),item));
	}
}
void ObjMgr::loadvehicles()
{
	const char* file_name="input_vehicle_type.input";
	CSVRowMapper<vehicle>mapper;
	mapper(file_name);
	std::cout<<"\n vehicle loaded from "<<mapper.result.size()<<file_name<<std::endl;
	const std::list<vehicle*>& vehicles_loaded=mapper.result;
	for(std::list<vehicle*>::const_iterator iter=vehicles_loaded.begin();
		iter!=vehicles_loaded.end();++iter)
	{
		vehicle* item=const_cast<vehicle*>(*iter);
		_vehicles.insert(std::make_pair(item->TypeId(),item));
	}
}

void ObjMgr::loaddistance()
{
	class distance_row
	{
	public:
		static distance_row* createObj(const std::vector<std::string> &cells)
		{
			distance_row* obj=new distance_row();
			int index=0;
			obj->_idx=std::stoi(cells[index++]);
			obj->_from_node_idx=std::stoi(cells[index++]);
			obj->_to_node_idx=std::stoi(cells[index++]);
			obj->_road_distance=std::stoi(cells[index++]);
			obj->_time_distance=std::stoi(cells[index++]);
			return obj;
		}
		int _idx;
		int _from_node_idx;
		int _to_node_idx;
		int _road_distance;
		int _time_distance;
	};
	const char* file_name="input_distance-time.txt";
	CSVRowMapper<distance_row> mapper;
	mapper(file_name);
	std::cout<<"\n place loaded from "<<mapper.result.size()<<file_name<<std::endl;
	const std::list<distance_row*>& distances_loaded=mapper.result;
	for(std::list<distance_row*>::const_iterator iter=distances_loaded.begin();
		iter!=distances_loaded.end();++iter)
	{
		distance_row* item=const_cast<distance_row*>(*iter);
		if(_distanceMatrix.find(item->_from_node_idx)==_distanceMatrix.end())
		{
			std::map<int,distance> buf_map;
			distance buf_d(item->_road_distance,item->_time_distance);
			buf_map.insert(std::make_pair(item->_to_node_idx,buf_d));
			_distanceMatrix.insert(std::make_pair(item->_from_node_idx,buf_map));
		}
		else
		{
			std::map<int,std::map<int,distance>>::iterator map_iter=_distanceMatrix.find(item->_from_node_idx);
			distance buf_d(item->_road_distance,item->_time_distance);
			map_iter->second.insert(std::make_pair(item->_to_node_idx,buf_d));
		}
	}
}





