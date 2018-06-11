#include "Objects\jdhead.h"
#include "Objects\ObjMgr.h"

int main()
{

	ObjMgr::instance()->loadplaces();
	ObjMgr::instance()->loadvehicles();
	ObjMgr::instance()->loaddistance();
	system("pause");




}