#include<iostream>
#include<string>

#include<vector>
#include<map>

#include<iomanip>
#include<cmath>

void new_initilazing_methods();

int main()
{
    new_initilazing_methods();
    return 0;
}




template<typename T, typename U>
auto add(T t, U u)->decltype(t+u)//for c++11
{
    return t+u;
}
auto AutoDecltype()->int//for c++11
{
    auto a=0;
    auto b =123.f;
    auto c =L"hello";
    auto d = {1,2,3};

    std::map<std::string,std::vector<double>> ticks;

    std::map<std::string,std::vector<double>>::iterator it = ticks.begin();
    auto auto_it = ticks.begin();


    std::vector<double> values;


    typedef decltype(values.begin()) dvi;

    typedef decltype(42) myint;

    typedef decltype(add(3,4.5)) qtype;

    typedef decltype(42,'z') mychar;
    

    return 42;
}




struct Address
{
    /* data */
};

struct Person
{
    std::string name;
    int age;
    Address address;

    Person(const std::string& name, int age):name(name),age(age){}
    explicit Person(const Address& address):address(address){}
};
struct Exchange
{
    int count;
    float rates[2];
    Exchange(std::initializer_list<float> r){
        if(r.size()<2)return;

        auto i = r.begin();
        rates[0]=*i;
        i++;
        rates[1]=*i;
    }
};

void new_initilazing_methods(){

    Exchange ex{2,3};
    std::cout<<ex.rates[1]<<std::endl;

    int a=1;
    int n{4};

    std::string s{"foo"};

    std::vector<int> values{1,2,3};

    std::map<std::string,std::string> capitals{{"UK","London"}};

    Person person(Address());//Person is function decleration this is error
    //person.age=5;//Error
    
    Person person_true{Address()};


}