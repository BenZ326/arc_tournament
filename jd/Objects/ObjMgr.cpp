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
	std::ofstream ofs("loaded_places.dump");
	for(std::list<place*>::const_iterator iter=places_loaded.begin();
		iter!=places_loaded.end();++iter)
	{
		place* item=const_cast<place*>(*iter);
		_places.insert(std::make_pair(item->Idx(),item));
		ofs<<item->Idx()<<","<<item->TypeIdx()<<","<<item->Lng()<<","<<item->Lat()
			<<","<<item->PackTotalWeight()<<","<<item->PackTotalVolume()<<","
			<<item->FRT()<<","<<item->LRT()<<std::endl;
	}
	ofs.close();
}


