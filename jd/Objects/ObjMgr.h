#ifndef _OBJMGR_H_
#define _OBJMGR_H_
#include "jdhead.h"

class vehicle;
class place;
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
	void cleardump();
	void dump();
private:
	std::map<std::string,vehicle*> _vehicles;
	std::map<int,place*> _places;
	
};


#endif