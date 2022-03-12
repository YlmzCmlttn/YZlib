#ifndef YZ_MATRIX_H
#define YZ_MATRIX_H
#include <memory>

#include <variant>
#include <functional>
#include "Linear_Algebra/Matrix/Matrix_.h"
namespace YZlib{    
    template <typename Tp>
    class Matrix_
    {
    private:
        size_t rows_;
        size_t cols_;
        size_t size_;
        Tp* data_;
        Major_Order majorOrder_;
        Parallel parallel_;
    public:
//Impl
        Matrix_();
        Matrix_(const Matrix_&);
        Matrix_(Matrix_&&) noexcept;
        Matrix_(const Parallel&);
        Matrix_(const Major_Order&);
        Matrix_(const Major_Order&,const Parallel&);
        Matrix_(const size_t&);
        Matrix_(const size_t&,const Parallel&);
        Matrix_(const size_t&,const Major_Order&);
        Matrix_(const size_t&,const Major_Order&,const Parallel&);
        Matrix_(const size_t&,const size_t&);
        Matrix_(const size_t&,const size_t&,const Parallel&);
        Matrix_(const size_t&,const size_t&,const Major_Order&);
        Matrix_(const size_t&,const size_t&,const Major_Order&,const Parallel&);
        Matrix_(const size_t&,const size_t&,const Tp&);
        Matrix_(const size_t&,const size_t&,const Tp& val,const Parallel&);
        Matrix_(const size_t&,const size_t&,const Tp&,const Major_Order&);
        Matrix_(const size_t&,const size_t&,const Tp& val,const Major_Order&,const Parallel&);
        Matrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&);
        Matrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Parallel&);
        Matrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Major_Order&);
        Matrix_(const size_t&,const size_t&,const std::unique_ptr<Tp[]>&,const Major_Order&,const Parallel&);
        Matrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&);
        Matrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Parallel&);
        Matrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Major_Order&);
        Matrix_(const size_t&,const size_t&,std::unique_ptr<Tp[]>&&,const Major_Order&,const Parallel&);
        Matrix_(const std::initializer_list<std::initializer_list<Tp>>& l);
        ~Matrix_();
//
//Operators
        Matrix_& operator=(const Matrix_&);
        Matrix_& operator=(Matrix_&&) noexcept;
        Tp& operator[](const size_t&);
        Tp& operator()(const size_t&,const size_t&);
        //Aritmetic operations
        Matrix_<Tp>& operator += (const Matrix_<Tp>&);
        Matrix_<Tp>& operator -= (const Matrix_<Tp>&);
        Matrix_<Tp>& operator *= (const Matrix_<Tp>&);
        Matrix_<Tp>& operator /= (const Matrix_<Tp>&);
        Matrix_<Tp>& operator %= (const Matrix_<Tp>&);
        Matrix_<Tp>& operator ^= (const Matrix_<Tp>&);

        Matrix_<Tp> operator + (const Matrix_<Tp>&)const;
        Matrix_<Tp> operator - (const Matrix_<Tp>&)const;
        Matrix_<Tp> operator * (const Matrix_<Tp>&)const;
        Matrix_<Tp> operator / (const Matrix_<Tp>&)const;
        Matrix_<Tp> operator % (const Matrix_<Tp>&)const;
        Matrix_<Tp> operator ^ (const Matrix_<Tp>&)const;

        Matrix_<Tp>& operator += (const Tp&);
        Matrix_<Tp>& operator -= (const Tp&);
        Matrix_<Tp>& operator *= (const Tp&);
        Matrix_<Tp>& operator /= (const Tp&);
        Matrix_<Tp>& operator %= (const Tp&);
        Matrix_<Tp>& operator ^= (const Tp&);

        Matrix_<Tp> operator + (const Tp&)const;
        Matrix_<Tp> operator - (const Tp&)const;
        Matrix_<Tp> operator * (const Tp&)const;
        Matrix_<Tp> operator / (const Tp&)const;
        Matrix_<Tp> operator % (const Tp&)const;
        Matrix_<Tp> operator ^ (const Tp&)const;

        //Conditional operations
        bool operator == (const Matrix_<Tp>&);
        bool operator != (const Matrix_<Tp>&);
        bool operator >  (const Matrix_<Tp>&);
        bool operator <  (const Matrix_<Tp>&);
        bool operator >= (const Matrix_<Tp>&);
        bool operator <= (const Matrix_<Tp>&);

        //Conversion
        explicit operator bool()const;
        template<typename newTp> explicit operator Matrix_<newTp>();
        
        //Friend operator
        template <typename Tp_> friend Matrix_<Tp_> operator + (const Tp_&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> operator - (const Tp_&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> operator * (const Tp_&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> operator / (const Tp_&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> operator % (const Tp_&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> operator ^ (const Tp_&,const Matrix_<Tp_>&);

        template <typename Tp_> friend std::ostream& operator <<(std::ostream&, const Matrix_<Tp_>&);
        template <typename Tp_> friend std::istream& operator <<(std::istream&, const Matrix_<Tp_>&);//NOT IMPLEMENTED
        template <typename Tp_> friend std::fstream& operator <<(std::fstream&, const Matrix_<Tp_>&);//NOT IMPLEMENTED
        template <typename Tp_> friend std::ifstream& operator <<(std::ifstream&, const Matrix_<Tp_>&);//NOT IMPLEMENTED
        template <typename Tp_> friend std::ofstream& operator <<(std::ofstream&, const Matrix_<Tp_>&);//NOT IMPLEMENTED
//
//Methods
        uint cols()const{return cols_;}
        uint rows()const{return rows_;}
        Tp get(const size_t&)const;
        void set(const size_t&,const Tp&);
        Tp get(const size_t&,const size_t&)const;
        void set(const size_t&,const size_t&,const Tp&);

        size_t getNumberofRows()const;
        void setNumberofRows(const size_t&);//DYNAMIC ALLOC NEEDED

        size_t getNumberofCols()const;
        void setNumberofCols(const size_t&);//DYNAMIC ALLOC NEEDED

        Size getSize()const;
        void setSize(const Size&);//NOT IMPLEMENTED (NOT POSSIBLE)


        Tp* getData();
        const Tp* getConstData()const;
        Tp* moveData();

        Major_Order getMajorOrder()const;
        void setMajorOrder(const Major_Order&);

        Parallel getParallel()const;
        void setParallel(const Parallel&);
        
        Matrix_<Tp> getRow(const size_t&)const;//NOT IMPLEMENTED
        void setRow(const Matrix_<Tp>&,const size_t&);//NOT IMPLEMENTED
        void setRow(const Tp&,const size_t&);//NOT IMPLEMENTED        
        void addRow(const Matrix_<Tp>&,const size_t&);//NOT IMPLEMENTED
        void addRow(const Tp&,const size_t&);//NOT IMPLEMENTED
        void pushRow(const Matrix_<Tp>&);//NOT IMPLEMENTED
        void pushRow(const Tp&);//NOT IMPLEMENTED

        Matrix_<Tp> getCol(const size_t&)const;//NOT IMPLEMENTED
        void setCol(const Matrix_<Tp>&,const size_t&);//NOT IMPLEMENTED
        void setCol(const Tp&,const size_t&);//NOT IMPLEMENTED        
        void addCol(const Matrix_<Tp>&,const size_t&);//NOT IMPLEMENTED
        void addCol(const Tp&,const size_t&);//NOT IMPLEMENTED
        void pushCol(const Matrix_<Tp>&);//NOT IMPLEMENTED
        void pushCol(const Tp&);//NOT IMPLEMENTED

        //Mathematical
        Matrix_<Tp> transpose()const;//NOT IMPLEMENTED
        Tp sum()const;//NOT IMPLEMENTED
        void fill(const Tp&);
//
    private:
        void copyData(const Tp*);
        
        void thread_operator_call(const Tp &_m, const std::function<Tp(Tp,Tp)>& f);
        void thread_operator_call(const Tp &_m, const std::function<Tp(Tp)>& f);
        void thread_operator_call(const Tp*,const std::function<Tp(Tp)>& f);
        void thread_operator_call(const Matrix_<Tp> &_m,const std::function<Tp(Tp,Tp)>& f);
        bool thread_bool_operator_call(const Matrix_<Tp> &_m,const std::function<bool(Tp,Tp)>& f);
        bool check_parallel()const;
    public:
//Functions
        //Trigonometric functions
        template <typename Tp_> friend Matrix_<Tp_> cos(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> sin(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> tan(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> acos(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> asin(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> atan(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> atan2(const Matrix_<Tp_>&);
        //Hyperbolic functions
        template <typename Tp_> friend Matrix_<Tp_> cosh(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> sinh(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> tanh(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> acosh(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> asinh(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> atanh(const Matrix_<Tp_>&);
        //Exponential and logarithmic functions
        template <typename Tp_> friend Matrix_<Tp_> exp(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> log(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> log10(const Matrix_<Tp_>&);
        //Power functions
        template <typename Tp_> friend Matrix_<Tp_> pow(const Matrix_<Tp_>&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> pow(const Matrix_<Tp_>&,const Tp_&);
        template <typename Tp_> friend Matrix_<Tp_> sqrt(const Matrix_<Tp_>&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> sqrt(const Matrix_<Tp_>&,const Tp_&);
        template <typename Tp_> friend Matrix_<Tp_> hypot(const Matrix_<Tp_>&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> hypot(const Matrix_<Tp_>&,const Tp_&);
        //Rounding and remainder functions        
        template <typename Tp_> friend Matrix_<Tp_> ceil(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> floor(const Matrix_<Tp_>&);        
        template <typename Tp_> friend Matrix_<Tp_> round(const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> fmod(const Matrix_<Tp_>&,const Matrix_<Tp_>&);
        template <typename Tp_> friend Matrix_<Tp_> fmod(const Matrix_<Tp_>&,const Tp_&);
        template <typename Tp_> friend Matrix_<Tp_> trunc(const Matrix_<Tp_>&);
        //Other functions
        template <typename Tp_> friend Matrix_<Tp_> abs(const Matrix_<Tp_>&);

        template <typename Tp_> friend Matrix_<Tp_> sigmoid(const Matrix_<Tp_>&);
        template<typename Tp_> friend Tp_ sum(const Matrix_<Tp_> &);
        template <typename Tp_> friend std::variant<Matrix_<Tp_>,Tp_> sum(const Matrix_<Tp_> &,bool );
        template<typename Tp_> friend Tp_ mean(const Matrix_<Tp_> &);
        // template <typename Tp_> friend Matrix_<Tp_> rand(const Matrix_<Tp_>&);
        // template <typename Tp_> friend Matrix_<Tp_> randn(const Matrix_<Tp_>&,unsigned seed);
//
    };
    
}
#include "Linear_Algebra/Matrix/Matrix_Impl.hpp"
#include "Linear_Algebra/Matrix/Matrix_Operators.hpp"
#include "Linear_Algebra/Matrix/Matrix_Methods.hpp"
#include "Linear_Algebra/Matrix/Matrix_Functions.hpp"
#endif