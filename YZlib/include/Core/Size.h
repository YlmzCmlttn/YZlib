#ifndef YZ_SIZE_H
#define YZ_SIZE_H
#include <iostream>
namespace YZlib{
    struct Size
    {
    public:
        uint rows;
        uint cols;
    private:
        uint size_;
        void update();
    public:    
        Size();
        Size(const uint& _rows,const uint& _cols);
        uint size();
        friend std::ostream& operator <<(std::ostream& os, const Size& _s) {
            os<<"H(rows): "<< _s.rows <<" W(cols): "<< _s.cols;
            return os;
        }
    };
}
#endif