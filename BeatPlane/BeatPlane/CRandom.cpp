/*************************************************
Author:Micooz
Date:2013-10-23
Description:随机数实现
**************************************************/
#include "CRandom.h"

CRandom::CRandom()
{
    srand(unsigned(time(0)));
}
