#include "H_IO.h"

void IO::getString(QString *_out_str){
    _out_str->clear();
     cin>>*_out_str;
    _out_str->trimmed();
    _out_str->simplified();
}
