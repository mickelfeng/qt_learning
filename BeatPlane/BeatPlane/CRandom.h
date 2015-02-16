//随机数生成类

#ifndef CRANDOM_H
#define CRANDOM_H

#include <ctime>
#include <cstdlib>

class CRandom
{
public:
    CRandom();

    static int random(double a,double b)
    {
        return a + (b - a)*rand() / (RAND_MAX + 1.0);
    }

private:

};

#endif // CRANDOM_H
