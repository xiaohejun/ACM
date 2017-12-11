#include "stdafx.h"
/*
2965:玛雅历（枚举）
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define HAAB_MONTH_NUM 19
#define HAAB_DAYS_OF_YEAR 365
#define HADD_NORMAL_DAYS_OF_MONTH 20


#define HOLLY_DAY_NAME_NUM 20
#define HOLLY_DAY_NUM_NUM 13

using namespace std;

char haad_months[HAAB_MONTH_NUM][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet" };//0-19
int hadd_days_of_month[HAAB_MONTH_NUM] = { 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,5 };

char holly_day_names[HOLLY_DAY_NAME_NUM][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };


int main()
{   
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    cout << n << endl;
    int day, year;
    char month[20];
    int m_days;
    int year1, day_num, day_name;
    while (n--)
    {
        scanf("%d. %s%d", &day, month, &year);

        //count days
        m_days = 0;
        m_days += HAAB_DAYS_OF_YEAR * year;

        for (int i = 0; i < HAAB_MONTH_NUM; i++)
        {
            if (!strcmp(month, haad_months[i]))
            {
                m_days += i * HADD_NORMAL_DAYS_OF_MONTH;
                break;
            }
        }

        m_days += day;

        year1 = m_days / (HOLLY_DAY_NAME_NUM * HOLLY_DAY_NUM_NUM);
        //m_days -= year1 * (HOLLY_DAY_NAME_NUM * HOLLY_DAY_NUM_NUM);
        day_num = m_days % HOLLY_DAY_NUM_NUM;
        day_name = m_days % HOLLY_DAY_NAME_NUM;
        cout << (day_num + 1) << ' ' << holly_day_names[day_name] << ' ' << year1 << endl;

    }
    fclose(stdin);
    return 0;
}


