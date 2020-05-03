#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
using namespace std;

struct Money {
private:
    int  QuantityBig;    
    int  QuantitySmall;  
    char Currency$[20];
    char CurrencyCent[20];
public:
    Money(void);
    Money(const char*, const char*, const int, const  int);
    Money(const Money&);    
    ~Money();  

    void setCurrency(const char*, const char*);
    char* getCurrency(void);
    void setMoneyQuantity(const int, const int);
    int getMoneyQuantity(void);
    void showBalance(void);

    friend Money operator+(const Money&, const Money&);
    friend Money operator-(const Money&, const Money&);

    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);

    void operator=(const Money& );
    bool operator==(const Money& rhs) const {return QuantityBig == rhs.QuantityBig; }
    bool operator!=(const Money& rhs) const {return !(rhs == *this);}
    bool operator>(const Money&) const;
    bool operator>=(const Money&) const;
    bool operator<(const Money&) const;
    bool operator<=(const Money&) const;
    friend void operator<<(ostream&, const Money& );
    friend void operator>>(istream&, Money&);
   

};
void ReadFile(char*, int);
void PrintArray(Money*, Money*);
void inputArray(Money*, Money*);
int main() {
    int MAX_SIZE = 1000000;
    char* BankAccountArray1 = new char[MAX_SIZE];
    ReadFile(BankAccountArray1, MAX_SIZE);

    Money* BankAccountArray2 = new Money[MAX_SIZE];
    Money* dest = nullptr;
    inputArray(dest, dest + MAX_SIZE);

    Money* rub = new Money();
    Money* dollar = new Money("dollar", "cent", 9, 25);
    rub->setMoneyQuantity(58, 20);
    Money* Euro = new Money("Euro", "centEuropa", 319, 24);
    rub->showBalance();
    dollar->showBalance();
    Euro->showBalance();
    delete Euro;
    Money Rub("Rub", "kopek", 21, 50);
    Rub.showBalance();
    Rub = *dollar;
    Rub.showBalance();
    system("pause");
    return 0;
}

typedef  int pToArr;
void PrintArray(Money* b, Money* e) {
    for (Money* p = b; b < e; ++p)
        cout << *p;
};
void reverse(Money* b, Money* e) {
    --e;
    while (b < e) { swap(*b, *e); ++b; --e; }
};
void inputArray(Money* b, Money* e) {
    for (Money* p = b; b < e; ++p)
        cin >> *p;
}

void freeMemory(pToArr*& p) { delete[] p; p = nullptr; };//
void initArray(Money* b, Money* e,  const Money m) {
    for (Money* p = b; b < e; ++p)
        *p = m;
};
void initRandomArray(Money* b, Money* e, const int m = -10, const int M = 10) {
    int d = (M - m + 1);
    for (Money* p = b; b < e; ++p)
        *p = {"$", "cent", rand() % d + m, rand() % d + m};
};
void initSortRandArr(Money* b, Money* e, const int m = -10, const int M = 10) {
    int d = (M - m + 1);
    for (Money* p = b; b < e; ++p)
        *p = { "$", "cent", rand() % d + m, rand() % d + m };
}
Money findMax(Money* b, Money* e) {
    Money max = *b;
    for (Money* p = 0; b < e; ++p)if (*p > max)max = *p;
    return max;
}
Money findMin(Money* b, Money* e) {
    Money min = *b;
    for (Money* p = 0; b < e; ++p)if (*p > min)min = *p;
    return min;
}
Money findSum(Money* b, Money* e) {
    Money s;
    for (Money* p = 0; b < e; ++p)
        s =s+ *p;
    return s;
}
void BubbleSort(Money* b, Money* e)
{
    for (Money* ip = b; ip < e; ++ip)
        for (Money* jp = b; jp < e; ++jp)
        {
            if (*ip > * jp)swap(*ip, *jp);
        }
}
Money* mkOFarr(int n, Money* p) {
    p = new (nothrow) Money[n];
    if (!p) exit(404);
    return p;
};
Money::Money(void) {
    QuantityBig = 0; QuantitySmall = 0;
    strcpy(Currency$, "no_currency-$");
    strcpy(CurrencyCent, "no_currency-Cent");

    cout << "no params constructor working \n";
}
Money::Money(const char* newCurrency$, const char* newCurrencyCent, const int newQuantityBig = 0, const int newQuantitySmall = 0) {
    if (Currency$ != "without_currency-$" && CurrencyCent != "without_currency-Cent") { strcpy(Currency$, newCurrency$); strcpy(CurrencyCent, newCurrencyCent); }
    QuantityBig = newQuantityBig * 100 + newQuantitySmall;
    QuantitySmall = 0;
}
Money::Money(const Money& From) {
    setCurrency(From.Currency$, From.CurrencyCent);
    setMoneyQuantity(From.QuantityBig, From.QuantitySmall);
    cout << "copy constructor working for (" << this->Currency$ << ';' << this->CurrencyCent << ';' << this->QuantityBig << ';' << this->QuantitySmall; ")\n";
}
Money::~Money() { cout << "destructor working for"; }
void Money::setCurrency(const char* CurrencyNew$, const char* CurrencyNewCent) {
    if ((strlen(CurrencyNew$) && strlen(CurrencyNewCent)) > 0) {
        strcpy(Currency$, CurrencyNew$);
        strcpy(CurrencyCent, CurrencyNewCent);
    }
}

void Money::setMoneyQuantity(const int g, const int k) {
    QuantityBig = g * 100 + k;//all money in cents
    QuantitySmall = 0;
}
char* Money::getCurrency() { return Currency$, CurrencyCent; }
int Money::getMoneyQuantity() { return QuantityBig / 100, QuantityBig % 100; }
void Money::showBalance(void) {
    cout << "Your balance is : " << QuantityBig / 100 << Currency$ << " " << QuantityBig % 100 << CurrencyCent;
}
void  Money::operator=(const  Money& rhs)//оператор присваивания
{
    cout << "= working for (" << rhs.Currency$ << ' ' << rhs.QuantityBig / 100 << ';' << rhs.CurrencyCent << rhs.QuantityBig % 100; ")\n";
    this->QuantityBig = rhs.QuantityBig / 100;
    this->QuantitySmall = rhs.QuantityBig % 100;

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

Money operator+(const Money& w1, const Money& w2){ 
    Money rez;
    Money fail("please,","try again :",0,0);
    if (w1.Currency$ == w2.Currency$) {
        rez.QuantityBig = w1.QuantityBig + w2.QuantityBig;
        return rez;
    }  else return fail;
};
Money operator-(const Money& w1, const Money& w2){
    Money rez;
    Money fail("please,","try again :",0,0);
    if (w1.Currency$ == w2.Currency$) {
    rez.QuantityBig = w1.QuantityBig - w2.QuantityBig;
    return rez;
    }   
    else return fail;
};
bool Money::operator>(const Money& m) const
{
    return(QuantityBig/100 + QuantityBig%100 > m.QuantityBig / 100+ m.QuantityBig % 100);
}
bool  Money::operator<(const  Money& m) const
{
    return(QuantityBig / 100 + QuantityBig % 100 < m.QuantityBig / 100 + m.QuantityBig % 100);
}
bool  Money::operator<=(const  Money& m) const
{
    return(QuantityBig / 100 + QuantityBig % 100 <= m.QuantityBig / 100 + m.QuantityBig % 100);
}
bool  Money::operator>=(const  Money& m) const
{
    return(QuantityBig / 100 + QuantityBig % 100 >= m.QuantityBig / 100 + m.QuantityBig % 100);
}


void ReadFile(char* UsersAccount, int size) {
    ifstream fin("input.txt");
    ofstream fout("result.txt");
    int curr_account = 0;
    while (true)
    {

        fin.getline(UsersAccount, size);
        if (fin.eof())
            break;
        if (fin.fail()) fin.clear();
        char* Account = strtok(UsersAccount, " ,…–][:;*.( )«—»!? -\"\t");
        while (Account)
        {
            fout << curr_account << ": ";
            for (int i = 0; i < 5; i++) {// Ivanov 15 dollars 24 cents
                fout << Account << " ";
                Account = strtok(NULL, " ,…–[]:;*.( )«»—!? -\"\t");
            }
            fout << "\n";
            curr_account++;
        }
    }
}

