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
# include "string.h"

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
int getDaysInMonth(int month, int year, char* monthstr){
    int daysInMonth = 0;
    //int isLeap = false;

    switch (month)
    {
    case JANUARY:
        strncpy(monthstr, "JANUARY", 20);
        daysInMonth = 31;
        break;
    case FEBURARY:
        strncpy(monthstr, "FEBURARY", 20);
        if(checkIfLeap(year) == true) daysInMonth = 29;
            else daysInMonth = 28;
        break;
    case MARCH:
        strncpy(monthstr, "MARCH", 20);
        daysInMonth = 31;
        break;
    case APRIL:
        strncpy(monthstr, "APRIL", 20);
        daysInMonth = 30;
        break;
    case MAY:
        strncpy(monthstr, "MAY", 20);
        daysInMonth = 31;
        break;
    case JUNE:
        strncpy(monthstr, "JUNE", 20);
        daysInMonth = 30;
        break;
    case JULY:
        strncpy(monthstr, "JULY", 20);
        daysInMonth = 31;
        break;
    case AUGUST:
        strncpy(monthstr, "AUGUST", 20);
        daysInMonth = 31;
        break;
    case SEPTEMBER:
        strncpy(monthstr, "SEPTEMBER", 20);
        daysInMonth = 30;
        break;
    case OCTOBER:
        strncpy(monthstr, "OCTOBER", 20);
        daysInMonth = 31;
        break;
    case NOVEMBER:
        strncpy(monthstr, "NOVEMBER", 20) ; 
        daysInMonth = 30;
        break;
    case DECEMBER:
        strncpy(monthstr, "DECEMBER", 20);
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
void printCalendar(int firstDayOfTheMonth, int month, int year){
    char monthstr[20];
    int days = getDaysInMonth(month, year, monthstr);         // Stores the number of days in the target month
    int daycounter = 1;
    
    //printf("days:\t\t%d\n", days);
    
    //Printing the header
    printf("\n\n\t\t%s\n", monthstr);
    printf("SUN\nMON\tTUE\tWED\tTHU\tFRI\tSAT\n");

    //Print the first week
    for (int firstEmpty = 0; firstEmpty < firstDayOfTheMonth; firstEmpty++){
        printf("\t");
    }
    for (int firstEmpty = 0; firstEmpty < 7 -firstDayOfTheMonth; firstEmpty++){
        printf("%d\t", daycounter);
        daycounter++;
        days--;
    }
    printf("\n");

    // Printing the rest of the weeks;
    for(days; days > 0; ){
        for (int weekly = 0; weekly < 7; weekly++){
            if(days == 0) break;
            printf("%d\t", daycounter);
        daycounter++;
        days--;
        }
        //printf("%d\n", days);
        printf("\n");
    }
    printf("\n");


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
 * Sketchy user input
 *      returns true if user input was successful
 *      returns fals if user input failed
************************************************************************/
bool getUserInput(int* monthInput, int* yearInput){

    printf("Please enter the Desired year:\t\t");
    scanf("%d", yearInput);
    if (*yearInput < 0){
        printf("\nNot a valid year, try again\n\n");
        return false;
    }

    printf("Please enter the desired month:\t\t");
    scanf("%d", monthInput);
    if(*monthInput < 1 || *monthInput > 12){
        printf("\nNot a valid year, ie January = 1, Feburary = 2 ... December = 12\n");
        printf("Please try again\n\n");
        return false;
    }

    // Returns true if all user input was done correctly
    return true;
}


/************************************************************************
 * Main Function
************************************************************************/
int main(){

    //bool application_flag = true;
    int yearInput;
    int monthInput;
    char again[10];
    
    // Application loop here
    while (true){
        if(getUserInput(&monthInput, &yearInput)){          // Application runs as normal
            
            int firstDayOfTheMonth = calculate(monthInput, yearInput);
            printf("First day of the month is:\t\t%d\n", firstDayOfTheMonth);
            printCalendar(firstDayOfTheMonth, monthInput, yearInput);
        }
            
        printf("Try again? (yes or no)\t\t");
        scanf("%s", again);
        if(
            strncmp(again, "no", 2) || 
            strncmp(again, "No", 2) ||
            strncmp(again, "n", 1) || 
            strncmp(again, "N", 1) 
            )break;
    }

    printf("end\n");
    return 0;
}
