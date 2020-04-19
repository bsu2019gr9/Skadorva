#define _CRT_SECURE_NO_WARNINGS
//Класс деньги(рубли/доллары/евро,копейки/центы/евроценты).
#include <iostream>
#include <fstream>
using namespace std;
struct Money {
private:
   char* BankAccountArray= nullptr;//это чо?????
    int QuantityBig;     // $,£ EURO,RUB
    int QuantitySmall;   // CENT,KOPEK
    char Currency$[20];   //for $,£ EURO,RUB // 20??? зачем так много???????? разве 4 не хватит????????
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
    Money operator+(const Money& rhs) { //совсем плохо!!!!
        Money rez;//никаких проверок что с чем складываем!!!!! Т.е. я могу 2$+3руб 50коп
        rez.QuantityBig = this->QuantityBig + rhs.QuantityBig;
        return rez;
    };
    Money operator-(const Money& rhs) {//плохо
        Money rez;
        rez.QuantityBig = this->QuantityBig - rhs.QuantityBig;
        return rez;
    };
    bool operator==( const Money& rhs) {//неверно!!!!
        if (this->QuantityBig == rhs.QuantityBig) return true; //т.е. у тебя 2$50c равно 2$55c
        else return false;
    }
    bool operator!=(const Money& rhs) {//плохо
        return !(this->QuantityBig == rhs.QuantityBig);//классически оператор != реализуется через уже к этому моменту написаному оператору ==
    };

    //---------------------------------------------------------------
    friend void operator<<(ostream& out, const  Money& v);
    friend void operator>>(istream& in, Money& v);
};
typedef  int pToArr;
void PrintArray(int* b, int* e) {
    for (int* p = b; b < e; ++p)
        cout << *p;
};
void reverse(int* b, int* e) {
    --e;
    while (b < e) {swap(*b, *e); ++b; --e;}
};
void inputArray(int* b, int* e) {
    for (int* p = b; b < e; ++p)
        cin >> *p;
}

void freeMemory(pToArr*& p) { delete[] p; p = nullptr; };//
void initArray(int* b, int* e, const int m) {
    for (int* p = b; b < e; ++p)
        *p = m;
};
void initRandomArray(int* b, int* e, const int m = -10, const int M = 10) {
    int d = (M - m + 1);
    for (int* p = b; b < e; ++ * p)
        *p = rand() % d + m;
};
void initSortRandArr(int* b, int* e, const int m = -10, const int M = 10) {
    int d = (M - m + 1);
    for (int* p = b; b < e; ++ * p)
        *p = rand() % d + m;
}
int findMax(int* b, int* e) {
    int max = *b;
    for (int* p = 0; b < e; ++ * p)if (*p > max)max = *p;
    return max;
}
int findMin(int* b, int* e) {
    int min = *b;
    for (int* p = 0; b < e; ++ * p)if (*p > min)min = *p;
    return min;
}
int findSum(int* b, int* e) {
    int s = 0;
    for (int* p = 0; b < e; ++p)
        s += *p;
    return s;
}
void BubbleSort(int* b, int* e)
{
    for (int* ip = b; ip < e; ++ip)
        for (int* jp = b; jp < e; ++jp)
        {
            if (*ip > * jp)swap(*ip, *jp);
        }
}
void mkOFarr(int n, int *p) {//ой, как плохо!!!!! р в main НЕ ПОМЕНЯЕТСЯ!!!!!!!!
    p = new (nothrow) int[n];
    if (!p) exit(404);
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
void ReadFile( char* UsersAccount, int size) {
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
int main() {
    int MAX_SIZE = 1000000;
    char* BankAccountArray1 = new char[MAX_SIZE];
    ReadFile(BankAccountArray1, MAX_SIZE);

    char* BankAccountArray2 = new char[MAX_SIZE];
    int*  dest = nullptr;
    inputArray(dest, dest + MAX_SIZE);

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
