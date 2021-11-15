/************************************************************************
 * 
 *          Rewriting my calendar application
 * 
 * For the Gregorian calendar, Zeller's congruence is
        h = ( q + ⌊ 13 ( m + 1 ) 5 ⌋ + K + ⌊ K 4 ⌋ + ⌊ J 4 ⌋ − 2 J ) mod 7 

    for the Julian calendar it is
        h = ( q + ⌊ 13 ( m + 1 ) 5 ⌋ + K + ⌊ K 4 ⌋ + 5 − J ) mod 7 ,
    
    where
        h is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
        q is the day of the month
        m is the month (3 = March, 4 = April, 5 = May, ..., 14 = February)
        K the year of the century ( y e a r mod 1 00 ).
        J is the zero-based century (actually ⌊ y e a r / 100 ⌋ {\displaystyle \lfloor year/100\rfloor } \lfloor year/100\rfloor ) For example, the zero-based centuries for 1995 and 2000 are 19 and 20 respectively (not to be confused with the common ordinal century enumeration which indicates 20th for both cases).
        ⌊ . . . ⌋ {\displaystyle \lfloor ...\rfloor } {\displaystyle \lfloor ...\rfloor } is the floor function or integer part
        mod is the modulo operation or remainder after division

    In this algorithm January and February are counted as months 13 and 14 of the previous year. E.g. if it is 2 February 2010, the algorithm counts the date as the second day of the fourteenth month of 2009 (02/14/2009 in DD/MM/YYYY format) 

 * 
************************************************************************/

# include "stdio.h"
# include "stdbool.h"

// Enums to help with code readability
enum week{
    SATURDAY        = 0,
    SUNDAY          = 1,
    MONDAY          = 2,
    TUESDAY         = 3,
    WEDNESDAY       = 4,
    THURSDAY        = 5,
    FRIDAY          = 6
};

enum month{
    JANUARY         = 1,
    FEBURARY        = 2,
    MARCH           = 3,
    APRIL           = 4,
    MAY             = 5,
    JUNE            = 6,
    JULY            = 7,
    AUGUST          = 8,
    SEPTEMBER       = 9,
    OCTOBER         = 10,
    NOVEMBER        = 11,
    DECEMBER        = 12
};


/************************************************************************
 * Checks if a given year is a leap year
 *      returns true if leap year
 *      returns false if not leap year
************************************************************************/
bool checkIfLeap(int year){
    if(year % 4 == 0) return true;
        else return false;
}


/************************************************************************
 * Determines how many days are in any given month
************************************************************************/
int getDaysInMonth(int month, int year){
    int daysInMonth = 0;
    //int isLeap = false;

    switch (month)
    {
    case JANUARY:
        daysInMonth = 31;
        break;
    case FEBURARY:
        if(checkIfLeap == true) daysInMonth = 29;
            else daysInMonth = 28;
        break;
    case MARCH:
        daysInMonth = 31;
        break;
    case APRIL:
        daysInMonth = 30;
        break;
    case MAY:
        daysInMonth = 31;
        break;
    case JUNE:
        daysInMonth = 30;
        break;
    case JULY:
        daysInMonth = 31;
        break;
    case AUGUST:
        daysInMonth = 31;
        break;
    case SEPTEMBER:
        daysInMonth = 30;
        break;
    case OCTOBER:
        daysInMonth = 31;
        break;
    case NOVEMBER:
        daysInMonth = 30;
        break;
    case DECEMBER:
        daysInMonth = 31;
        break;
        
    default:
        break;
    }
    return daysInMonth;
}


/************************************************************************
 * Prints the calendar
************************************************************************/
void printCalendar(int month, int year){
    int days = getDaysInMonth(month, year);
    printf("days:\t\t%d\n", days);
}


/************************************************************************
 * Returns the day of the week the month starts
 * 0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday
 * 
 * Follows the gregorian calendar
************************************************************************/
int calculate(int month, int year){
    int dayOfTheMonth = 0;
    //int month = month;
    int yearOfTheCentury = year % 100;
    int zeroBasedCentury = year / 100;

    int dayOfTheWeek = (dayOfTheMonth + ( ( ( 13 * (month + 1) ) ) / 5) + yearOfTheCentury + (yearOfTheCentury / 4) + (zeroBasedCentury / 4) - (2 * zeroBasedCentury)) %7;

    return dayOfTheWeek;
}


/************************************************************************
 * Main Function
************************************************************************/
int main(){

    bool application_flag = true;

    
    // Application loop here
    while (true){
        int yearInput;
        int monthInput;
        printf("Please enter the Desired year:\t\t");
        scanf("%d", &yearInput);
        printf("Please enter the desired month:\t\t");
        scanf("%d", &monthInput);

        int FirstDayOfTheMonth = calculate(monthInput, yearInput);
        printf("First day of the month is:\t\t%d\n", FirstDayOfTheMonth);

        printCalendar(monthInput, yearInput);

    }
    return 0;
}
