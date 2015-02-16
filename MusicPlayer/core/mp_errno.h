/**
 *  
 *  功能描述：错误定义
 *  作者    ：LiuYun
 *  邮箱    ：wolf_coming@sina.cn
 *
 */

#ifndef __MY_ERRNO_H__
#define __MY_ERRNO_H__

namespace mp {

#define SUCCESS     0x0

#define EUNKNOW      0x200
#define ENOFOUND     0x201
#define EUNSUPPORT   0x202
#define ELONGFILENAME   0x203

#define ENOPLAYING  0x250
#define ENOSUSPEND  0x251

#define ETHREAD     0x300

#define EEVENT      0x350 

#define ECMD        0x400
#define EACK        0x401
};
#endif  
