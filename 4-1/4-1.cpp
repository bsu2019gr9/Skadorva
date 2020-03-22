//Отсортировать строки по количеству слов заданной длины.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

int main() {
    const int N1 = 5000, L = 1000;
    int i = 0;
    int n(0);
    int *coincide[N1] = { 0 };// число совпадений
    cin >> n;//длина текущего слова
    char* all_words[N1] = { nullptr };
    int all_len[N1] = { 0 };
    int len[100];
    char sep[] = "` .,'\":;";
    int count = 0;
    const int N = 700;
    char* buff = new char[N];


    ifstream fffff("War_and_Peace.txt"); // отсюда читаем (поток типа ifstream= input file stream)
    ofstream ggggg("OurOutput.txt");//сюда пишем (поток типа ofstream= output file stream)
    if (!fffff) { cout << "No file War_and_Peace.txt. Can't open\n"; exit(1); }
    if (!ggggg) { cout << "   file OurOutput.txt/ Can't create\n"; exit(1); }
    while (1) {
        fffff.getline(buff, N - 1); //читаем ПОСТРОЧНО.
        char* p = strtok(buff, sep);
    //Если будет в строке файла больше N-1 символов, то getline() поместит в буфер N-1 символов, в конец 
   //поместит '\0', установит флаг ошибки (failbit), поток станет нерабочим, не введённое останется в очереди ввода.
        if (fffff.fail()) fffff.clear();


        //----с этого момента у меня вопросы--- как переделать чтобы переместить строки местами -----------
       /* while (p) {
            len[i] = strlen(p);//длина текущего слова
            len[all_len[i]]++;
            all_words[i] = new (nothrow) char[all_len[i] + 1];
            strcpy(all_words[i], p);
            ++i;
            p = strtok(nullptr, sep);//очередное слово
        }
        count++;// number of lines(articles)
        for (int ip = 1; ip < i; ++p) {//how to compare two strings
            for (int jp = ip; (jp > 0) && (all_len[jp] < all_len[jp - 1]); --jp) {
                swap(all_len[jp - 1], all_len[jp]);
                swap(all_words[jp - 1], all_words[ip]);
            }
        }
        for (size_t ii = 0; ii < 20; ii++)
        {
            cout << ii << ":" << len[ii] << '\n';*/
        while (p) {
            len[i] = strlen(p);//длина текущего слова
            len[all_len[i]]++;
            if (len[i] == n) {
                count++;
            }
            all_words[i] = new (nothrow) char[all_len[i] + 1];
            strcpy(all_words[i], p);
            ++i;
            p = strtok(nullptr, sep);//очередное слово
        }
        int j(0);
       coincide[j]= count;// тут не понимаю как реализовать подсчёт совпадений в строке
       j++;
       count = 0;
        for (int ip = 1; ip < i; ++p) {//how to compare two strings
            for (int jp = ip; (jp > 0) && (coincide[jp] < coincide[jp - 1]); --jp) {
                swap(all_len[jp - 1], all_len[jp]);
                swap(all_words[jp - 1], all_words[ip]);
            }
        }
        for (size_t ii = 0; ii < 20; ii++)
        {
            cout << ii << ":" << len[ii] << '\n';

        }//getline при переполнении выставляет бит состояния =1. Его проверяем fail'ом.А потом подчищаем буфер
        cout << buff << '\n'; //на экран
        ggggg << buff << "***";//в файл

        if (fffff.eof()) break; //читаем пока не кончится исходный файл. Т.е. пока не прочитаем EOF.
        ggggg << '\n';//переход на новую строку пишем в date2.txt только, если в строке 16 мы прочитали действительно
        //СТРОКУ (до endl), а не последнюю строку афйла в которой EOF, а не endl
    }
    delete[] buff;
    fffff.close();//закрыли файл
    ggggg.close();//закрыли файл
    system("pause");
}