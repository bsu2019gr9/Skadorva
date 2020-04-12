#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
using namespace std;
struct Money {
private:
    int QuantityBig;     // $,£ EURO,RUB
    int QuantitySmall;   // CENT,KOPEK
    char Currency$[20];   //for $,£ EURO,RUB
    char CurrencyCent[20];// for  CENT,KOPEK
public:
    //Constructors:
    Money( void);       
    Money(const char*, const char*,  const int,const  int);
                    
    Money( const Money&);     //Copy
    ~Money();          //Destructor
    void setCurrency(const char*, const char*); //Функции для получения 
    char* getCurrency(void); //и установки свойств
    void setMoneyQuantity( const int,  const int);
    int getMoneyQuantity(void);
    void showBalance(void);
    void operator=(const Money& rhs);
    //---------------------------------------------------------------------------
    Money operator+(const Money& rhs) {
        Money rez;
        rez.QuantityBig = this->QuantityBig + rhs.QuantityBig;
        return rez;
    };
    Money operator-(const Money& rhs) {
        Money rez;
        rez.QuantityBig = this->QuantityBig - rhs.QuantityBig;
        return rez;
    };
    bool operator==( const Money& rhs) {
        if (this->QuantityBig == rhs.QuantityBig) return true;
        else return false;
    }
    bool operator!=(const Money& rhs) {
        return !(this->QuantityBig == rhs.QuantityBig);
    };

    //---------------------------------------------------------------
    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);
};

Money::Money(void) {
    QuantityBig = 0; QuantitySmall = 0;
    strcpy(Currency$, "no_currency-$");
    strcpy(CurrencyCent, "no_currency-Cent");

    cout << "no params constructor working \n";
}
Money::Money(const char* newCurrency$, const char* newCurrencyCent,  const int newQuantityBig = 0,const int newQuantitySmall = 0) {
    if (Currency$ != "without_currency-$" && CurrencyCent != "without_currency-Cent") { strcpy(Currency$, newCurrency$); strcpy(CurrencyCent, newCurrencyCent); }
    QuantityBig = newQuantityBig*100+ newQuantitySmall;
    QuantitySmall=0;
}
Money::Money( const Money& From) {
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

void Money::setMoneyQuantity( const int g,const int k) { QuantityBig = g * 100 + k;//all money in cents
 QuantitySmall = 0; }

char* Money::getCurrency() { return Currency$,CurrencyCent; }

int Money::getMoneyQuantity() { return QuantityBig/100, QuantityBig%100; }

void Money::showBalance(void) {
    cout <<"Your balance is : " << QuantityBig/100 << Currency$ << " " << QuantityBig%100 << CurrencyCent;
}
void  Money::operator=(const  Money& rhs)//оператор присваивания
{
    cout << "= working for (" << rhs.Currency$  << ' ' << rhs.QuantityBig/100 << ';' << rhs.CurrencyCent << rhs.QuantityBig%100; ")\n";
    this->QuantityBig = rhs.QuantityBig/100;
    this->QuantitySmall = rhs.QuantityBig%100;

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
