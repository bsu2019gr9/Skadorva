#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
using namespace std;
struct Money {
private:
    int QuantityBig;     // $,£ EURO,RUB
    int QuantitySmall;   // CENT,KOPEK
    char Currency$[4];   //for $,£ EURO,RUB
    char CurrencyCent[4];// for  CENT,KOPEK
public:
    //Constructors:
    Money(void);       
    Money(const char*, const char*, int, int);
                    
    Money(Money&);     //Copy
    ~Money();          //Destructor
    void setCurrency(const char*, const char*); //Функции для получения 
    char* getCurrency(void); //и установки свойств
    void setMoneyQuantity(int, int);
    int getMoneyQuantity(void);
    void showBalance(void);
    void operator=(const Money& rhs);
    //---------------------------------------------------------------------------
    Money operator+(const Money& rhs) {
        Money rez1, rez2;
        rez1.QuantityBig = this->QuantityBig + rhs.QuantityBig;
        rez2.QuantitySmall = this->QuantitySmall + rhs.QuantitySmall;
        if (rez2.QuantitySmall/100) {
            rez2.QuantitySmall %= 100;
            rez1.QuantityBig += 1;
        }
        return rez1, rez2;
    };
    Money operator-(const Money& rhs) {
        Money rez1, rez2;
        rez1.QuantityBig = this->QuantityBig - rhs.QuantityBig;
        rez2.QuantitySmall = this->QuantitySmall - rhs.QuantitySmall; 
        if(rez2.QuantitySmall <0) {
            rez2.QuantitySmall += 100;
            rez1.QuantityBig -= 1;
        }
        return rez1, rez2;
    };

    //---------------------------------------------------------------
    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);
};

Money::Money(void) {
    QuantityBig = 0; QuantitySmall = 0;
    strcpy(Currency$, "without_currency-$");
    strcpy(CurrencyCent, "without_currency-Cent");

    cout << "no params constructor working \n";
}
Money::Money(const char* newCurrency$, const char* newCurrencyCent, int newQuantityBig = 0, int newQuantitySmall = 0) {
    if (Currency$ != "without_currency-$" && CurrencyCent != "without_currency-Cent") { strcpy(Currency$, newCurrency$); QuantityBig = 0; QuantitySmall = 0; }
    QuantityBig = newQuantityBig;
    QuantitySmall = newQuantitySmall;
}
Money::Money(Money& From) {
    setCurrency(From.Currency$, From.CurrencyCent);
    setMoneyQuantity(From.QuantityBig, From.QuantitySmall);
    cout << "copy constructor working for (" << this->Currency$ << ';' << this->CurrencyCent<< ';' << this->QuantityBig << ';' << this->QuantitySmall; ")\n";
}
Money::~Money() { cout << "destructor working for"; }


void Money::setCurrency(const char* CurrencyNew$, const char* CurrencyNewCent) {
    if ((strlen(CurrencyNew$) && strlen(CurrencyNewCent))>0) {
        strcpy(Currency$, CurrencyNew$);
        strcpy(CurrencyCent, CurrencyNewCent);
    }
}

void Money::setMoneyQuantity(int g, int k) { QuantityBig = g; QuantitySmall = k; }

char* Money::getCurrency() { return Currency$,CurrencyCent; }

int Money::getMoneyQuantity() { return QuantityBig, QuantitySmall; }

void Money::showBalance(void) {
    cout <<"Your balance is : " << QuantityBig << Currency$ << " " << QuantitySmall << CurrencyCent;
}
void  Money::operator=(const  Money& rhs)//оператор присваивания
{
    cout << "= working for (" << rhs.Currency$  << ' ' << rhs.QuantityBig << ';' << rhs.CurrencyCent << rhs.QuantitySmall; ")\n";
    this->QuantityBig = rhs.QuantityBig;
    this->QuantitySmall = rhs.QuantitySmall;

}
void operator<<(ostream& out, const  Money& v)
{
    out << "(" << v.Currency$ << ' ' << v.QuantityBig << ';' << v.Currency$ << v.QuantitySmall << ")";
};

void operator>>(istream& in, Money& v)
{
    in >> v.Currency$;
    in >> v.CurrencyCent;
    in >> v.QuantityBig;
    in >> v.QuantitySmall;
}

int main() {
    Money* rub = new Money();
    Money* dollar = new Money("dollar","cent", 9,25);
    rub->setMoneyQuantity(58, 20);
    Money* Euro = new Money("Euro","centEuropa", 319,24);
    rub->showBalance();
    dollar->showBalance();
    Euro->showBalance();
    delete Euro;
    Money Rub("Rub","kopek", 21,50);
    Rub.showBalance();
    Rub = *dollar;
    Rub.showBalance();
    system("pause");
    return 0;
}
