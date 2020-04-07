#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
using namespace std;

struct Money {
private: 
    int Quantity; 
    char* Currency;//пробовал ввести сюда все валюты, но так гораздо проще и понятнее
public:
                       //Constructors:
    Money(void);       //по умолчанию: Student *s=new Student();
    Money( const char*, int); //currency and quantity 
                       //Student *s2=new Student("Petrov",210);
    Money(Money&);     //Copy
    ~Money();          //Destructor
    void setCurrency(char*); //Функции для получения 
    char* getCurrency(void); //и установки свойств
    void setMoneyQuantity(int);  //с атрибутом private
    int getMoneyQuantity(void);
    void showBalance(void);
    void operator=(const Money& rhs);
    //---------------------------------------------------------------------------
    Money operator+(const Money& rhs) {
        Money rez;
        rez.Quantity = this->Quantity + rhs.Quantity;
        return rez;
    };
        Money operator-(const Money & rhs) {
            Money rez;
            rez.Quantity = this->Quantity - rhs.Quantity;
            return rez;
        };
    
    //---------------------------------------------------------------
    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);
};

Money:: Money(void) {
    Currency = NULL; Quantity = 0;
    cout << "no params constructor working \n";
}
Money::Money( const char* newCurrency, int newQuantity = 0) {
    Currency = (char*)malloc((strlen(newCurrency) + 1) * sizeof(char));
    if (Currency != NULL) { strcpy(Currency, newCurrency); Quantity = 0; }
    Quantity = newQuantity;
}
Money::Money(Money& From) {
    setCurrency(From.Currency);
    setMoneyQuantity(From.Quantity);
    cout << "copy constructor working for (" << this->Currency << ';' << this->Quantity; ")\n";
}

Money::~Money() { delete Currency; }

void Money::setCurrency(char* Currency) {
    int n = strlen(Currency);
    if (n > 0) {
        this->Currency = new char[n + 1];
        if (this->Currency != NULL) strcpy(this->Currency, Currency);
    }
}

void Money::setMoneyQuantity(int g) { Quantity = g; }

char* Money::getCurrency() { return Currency; }

int Money::getMoneyQuantity() { return Quantity; }

void Money::showBalance(void) {
 cout<<Currency<<","<< Quantity;
}
void  Money::operator=(const  Money& rhs)//оператор присваивания
{
    cout << "= working for (" << rhs.Currency << ';' << rhs.Quantity<< ")\n";
    this->Currency = rhs.Currency;
    this->Quantity = rhs.Quantity;
 
}
void operator<<(ostream& out, const  Money& v)
{
    out << "(" << v.Currency << ';' << v.Quantity  << ")";
};

void operator>>(istream& in, Money& v)
{
    in >> v.Currency;
    in >> v.Quantity;
}

int main() {
    Money* rub = new Money();
    Money* dollar = new Money("dollar",9);
    rub->setMoneyQuantity(110000);
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