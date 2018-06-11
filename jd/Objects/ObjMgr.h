#ifndef _OBJMGR_H_
#define _OBJMGR_H_
#include "jdhead.h"

class vehicle;
class place;

struct distance
{
public:
	distance(int rd,int td):_road_distance(rd),_time_distance(td){}
	int _road_distance;
	int _time_distance;
};
class ObjMgr
{
public:
	static ObjMgr* instance();
	ObjMgr(){}
protected:
	static ObjMgr* _instance;
public:
	void loadvehicles();
	void loadplaces();
	void loaddistance();
	void cleardump();
	void dump();
private:
	std::map<int,vehicle*> _vehicles;
	std::map<int,place*> _places;
	std::map<int,std::map<int,distance>> _distanceMatrix;			//第一个int是from node的idx，第二个int是to node的idx
};


#endif