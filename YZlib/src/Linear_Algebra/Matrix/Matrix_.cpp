#include "Linear_Algebra/Matrix/Matrix_.h"
namespace YZlib{
    uint from2Dto1D(const uint& row,const uint& col,const Size& s,const Major_Order& raw_majored){
        if(raw_majored==Major_Order::Row_Major){
            return(row * s.cols) + col;
        }else{
            return(col * s.rows) + row;
        }
    }
    Size from1Dto2D(const uint& index,const Size& s,const Major_Order& raw_majored){
        if(raw_majored==Major_Order::Row_Major){
            return Size(index%s.rows,(index-(index%s.rows))/s.rows);
        }else{
            return Size((index-(index%s.cols))/s.cols,index%s.cols);
        }
    }
}