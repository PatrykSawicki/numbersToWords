#include <iostream>
#include <vector>

using namespace std;
using ulong = unsigned long long;
string numtoString(ulong value);

int main()
{

    ulong number = 0, t;

    cin >> t;

    while(t--){

    cin >> number;
    cout << numtoString(number)<< endl;
    }
    return 0;
}

string numtoString(ulong value)
{
    vector < pair < ulong, char const * > > numString {
        {1000000000000000000, "trl. "},{1000000000000000, "bld. "},{1000000000000, "bln. "}, {1000000000, "mld. "},{1000000, "mln. "},
        {1000, "tys. "},{900, "dziewiecset "},{800, "osiemset "},{700, "siedemset "},{600, "szescset "},{500, "piecset "},{400, "czterysta "},
        {300, "trzysta "},{200, "dwiescie "},{100, "sto "}, {90, "dziewiecdziesiat "},{80, "osiemdziesiat "},{70, "siedemdziesiat "},
        {60, "szescdziesiat "},{50, "piecdziesiat "},{40, "czterdziesci "},{30, "trzydziesci "},{20, "dwadziescia "},{19, "dziewietnascie "},
        {18, "osiemnascie "},{17, "siedemnascie "},{16, "szesnascie "},{15, "pietnascie "}, {14, "czternascie "},{13, "trzynascie "},
        {12, "dwanascie "}, {11, "jedenascie "} , {10, "dziesiec "}, {9, "dziewiec "},{8, "osiem "},{7, "siedem "},{6, "szesc "},{5, "piec "},
        {4, "cztery "}, {3, "trzy "}, {2, "dwa "}, {1, "jeden "}
    };

    string result;
    for(auto const & kvp : numString)
    {
         while(value >= kvp.first){
             if(value >= 1000)
             {
                 ulong temp = value/kvp.first;
                 result += numtoString(temp);
                 value = kvp.first + value % kvp.first;
                 temp = 0;
             }
             result += kvp.second;
             value -= kvp.first;
         }
    }
    return result;
}
