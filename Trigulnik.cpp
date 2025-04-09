#include <iostream>
using namespace std;

class Triugulnik{
    private:
    unsigned a=1;
    unsigned b=1;
    unsigned c=1;
    
    public:
    Triugulnik(unsigned x, unsigned y, unsigned z){
        if(x<y+z && y<x+z && z<x+y){
            a=x;
            b=y;
            c=z;
            cout<< "Sustestvuva takuv triugulnik"<< endl;
        }
        else{
            cout<< "Ne sustestvuva takuv triugulnik"<< endl;
        }
    }
    ~Triugulnik(){
        cout<< "\n Triugulnikut e iztrit"<< endl;
    }
    unsigned P(){
        cout<< "P= ";
        return a+b+c;
    }
    void setA(unsigned A){
        if(A>0 && A<100){
            a=A;
        }
        else{
            a=100;
        }
    }
    unsigned getA(){
        return a;
    }
    void setB(unsigned B){
        if(B>0 && B<100){
            b=B;
        }
        else{
            b=100;
        }
    }
    unsigned getB(){
        return b;
    }
    void setC(unsigned C){
        if(C>0 && C<100){
            c=C;
        }
        else{
            c=100;
        }
    }
    unsigned getC(){
        return c;
    }
};
int main()
{
    unsigned a1, b1, c1;
    cout<< "Vuvedi stranite na triugulnika: ";
    cin>> a1>> b1>> c1;
    Triugulnik tr1(a1, b1, c1);
    cout<< tr1.P();   
    tr1.setA(a1++);
    tr1.setB(++b1);
    tr1.setC(++c1);
    cout<< "\n a= "<< tr1.getA();
    cout<< "\n b= "<< tr1.getB();
    cout<< "\n a1= "<< a1;
}