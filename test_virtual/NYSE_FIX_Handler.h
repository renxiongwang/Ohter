//TO_DO ************
//please finish the following NYSE_FIX_Handler.h
//file 2
//NYSE_FIX_Handler.h
 
#incldue "Application.h"
#include <ext/hash_map>
#include <string>
#include "Handler.h"

//TO_DO *************
//create a class NYSE_FIX_Handler, which is a protected inheritant of Handler
//http://www.fixtradingcommunity.org/pg/main/what-is-fix 
//FIX uses tag 34 value as seqno
  
class NYSE_FIX_Handler:protected Handler
{
public:
  size_t parse(const string&& , size_t len) {
  }
};
