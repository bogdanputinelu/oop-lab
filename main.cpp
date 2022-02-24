#include <iostream>
#include <math.h>
using namespace std;
class Numar_Complex{
    double re,im;
public:
    Numar_Complex(double re_,double im_){
        re=re_;
        im=im_;
    }
    Numar_Complex(const Numar_Complex &nr){
        re=nr.re;
        im=nr.im;
    }
    double getRe() const {
        return re;
    }

    void setRe(double re) {
        Numar_Complex::re = re;
    }

    double getIm() const {
        return im;
    }

    void setIm(double im) {
        Numar_Complex::im = im;
    }

    void afisare() {
        if(re!=0)
            cout<<re;
        if(im<0)
            cout<<im<<"i";
        else
            if(im>0)
                cout<<"+"<<im<<"i";
    }
    double modul(){
        return sqrt(im*im+re*re);
    }

    Numar_Complex operator+(const Numar_Complex &rhs) const {
        return Numar_Complex(re+rhs.re,im+rhs.im);
    }
    Numar_Complex operator*(const Numar_Complex &rhs) const {
        return Numar_Complex(re*rhs.re-im*rhs.im,re*rhs.im+im*rhs.re);
    }
    Numar_Complex operator/(const Numar_Complex &rhs) const {
        return Numar_Complex((re*rhs.re+im*rhs.im)/(rhs.re*rhs.re+rhs.im*rhs.im),(rhs.re*im-re*rhs.im)/(rhs.re*rhs.re+rhs.im*rhs.im));
    }
};
int main(){
    Numar_Complex z(3,4);
    Numar_Complex x(1,2);
    Numar_Complex h=z/x;
    h.afisare();
    return 0;
}
