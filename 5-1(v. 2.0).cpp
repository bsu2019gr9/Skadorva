#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
using namespace std;
struct Money {
private: 
    int QuantityBig; 
    int QuantitySmall;
    char Currency[4];//пробовал ввести сюда все валюты, но так гораздо проще и понятнее
public:
                       //Constructors:
    Money(void);       //по умолчанию: Student *s=new Student();
    Money( const char*, int,int); //currency and quantity 
                       //Student *s2=new Student("Petrov",210);
    Money(Money&);     //Copy
    ~Money();          //Destructor
    void setCurrency( const char*); //Функции для получения 
    char* getCurrency(void); //и установки свойств
    void setMoneyQuantity(int, int);  //с атрибутом private
    int getMoneyQuantity(void);
    void showBalance(void);
    void operator=(const Money& rhs);
    //---------------------------------------------------------------------------
    Money operator+(const Money& rhs) {
        Money rez1,rez2;
        rez1.QuantityBig = this->QuantityBig + rhs.QuantityBig;
        rez2.QuantitySmall = this->QuantitySmall + rhs.QuantitySmall;
        if (rez2.QuantitySmall >= 100) {//очень очень неоптимальный код!!!!! есть же операторы %100 и /100
            rez2.QuantitySmall %= 100;
            rez1.QuantityBig += 1;
        }
        return rez1,rez2;
    };
        Money operator-(const Money & rhs) {
            Money rez1, rez2;
            rez1.QuantityBig = this->QuantityBig - rhs.QuantityBig;
            rez2.QuantitySmall = this->QuantitySmall - rhs.QuantitySmall; // а есои копеек больше у rhs!!!!!!!!!!
            return rez1,rez2;
        };
    
    //---------------------------------------------------------------
    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);
};

Money:: Money(void) {
     QuantityBig = 0; QuantitySmall = 0;
     const char* s("without_currency");
     int i(0);
     do//про strcpy не слышал!!!!! зачем свой велосипед???????????????7
     {
        Currency[i] = s[i];
     } while (s[i++] != '\0');

    cout << "no params constructor working \n";
}
Money::Money(const char* newCurrency, int newQuantityBig = 0, int newQuantitySmall = 0) {
    if (Currency != "without_currency") { strcpy(Currency, newCurrency); QuantityBig = 0; QuantitySmall = 0; }
    QuantityBig = newQuantityBig;
    QuantitySmall = newQuantitySmall;
}
Money::Money(Money& From) {
    setCurrency(From.Currency);
    setMoneyQuantity(From.QuantityBig, From.QuantitySmall);
    cout << "copy constructor working for (" << this->Currency << ';' << this->QuantityBig<<';' << this->QuantitySmall; ")\n";
}

Money::~Money() { delete Currency; }

void Money::setCurrency(  const char* CurrencyNew) {
    int n = strlen(CurrencyNew);
    if (n > 0) {
        strcpy(Currency, CurrencyNew);
    }
}

void Money::setMoneyQuantity(int g, int k) { QuantityBig = g; QuantitySmall = 0; }

char* Money::getCurrency() { return Currency; }

int Money::getMoneyQuantity() { return QuantityBig,QuantitySmall; }

void Money::showBalance(void) {
 cout<<Currency<<","<< QuantityBig << ","<< QuantitySmall;
}
void  Money::operator=(const  Money& rhs)//оператор присваивания
{
    cout << "= working for (" << rhs.Currency << ';' << rhs.QuantityBig << ';' << rhs.QuantitySmall; ")\n";
    this->QuantityBig = rhs.QuantityBig;
    this->QuantitySmall = rhs.QuantitySmall;
 
}
void operator<<(ostream& out, const  Money& v)
{
    out << "(" << v.Currency << ';' << v.QuantityBig  << v.QuantitySmall<<")";
};

void operator>>(istream& in, Money& v)
{
    in >> v.Currency;
    in >> v.QuantityBig;
    in >> v.QuantitySmall;
}

int main() {
    Money* rub = new Money();
    Money* dollar = new Money("dollar",9);
    rub->setMoneyQuantity(58,20);
    Money* centEuropa = new Money("centEuropa", 319);
    rub->showBalance();
    dollar->showBalance();
    centEuropa->showBalance();
    delete centEuropa;
    Money kopek("kopek", 21);
    kopek.showBalance();
    kopek = *dollar;
    kopek.showBalance();
    system("pause");
    return 0;
}
