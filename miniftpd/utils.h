#ifndef _UTILS_H_
#define _UTILS_H_

#define return_if_fail(condition)    \
        do  {   if(! condition) return false;    } while(0);

#define INFO(str)   \
    fprintf(stderr, "[Function -> %s: %d] %s\n", __func__, __LINE__, str);

#endif
