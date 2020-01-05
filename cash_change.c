/* Moamen Ihab's code
    Shop Clerk to recieve payment and return change
        regions suported: USA, Europe, Egypt
------------------------------------------------------
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//This struct to pass data from function back to main
struct check{
    int hun, fif, twn, ten, fiv, one;
    int q, d, n, p;
    int c;
    int fiv_hun, twn_cent, fif_cent;
};

void check_reg();
int get_reg();
struct check get_change_us();
struct check get_change_eu();
struct check get_change_eg();

bool usfunc = false;
bool eufunc = false;
bool egfunc = false;


//MY MAIN FUNCTION TO PRINT OUT RESULTS
int main(void){
    check_reg();

//check which region is selected and print results
    if (usfunc == true){
        struct check ch1 = get_change_us();
        printf("Number of hundred dollars note:%d\n",ch1.hun);
        printf("Number of fifty dollars note:%d\n",ch1.fif);
        printf("Number of twenty dollars note:%d\n",ch1.twn);
        printf("Number of ten dollars note:%d\n",ch1.ten);
        printf("Number of five dollars note:%d\n",ch1.fiv);
        printf("Number of one dollar note:%d\n",ch1.one);
        printf("Number of quarters:%d\n",ch1.q);
        printf("Number of dimes:%d\n",ch1.d);
        printf("Number of Nickels:%d\n",ch1.n);
        printf("Number of Pennys:%d\n",ch1.p);
        printf("Total number of coins & paper:%d\n", ch1.c);
    }
    else if (eufunc == true)
    {
        struct check ch2 = get_change_eu();
        printf("Number of five hundred euros note:%d\n",ch2.fiv_hun);
        printf("Number of hundred euros note:%d\n",ch2.hun);
        printf("Number of fifty euros note:%d\n",ch2.fif);
        printf("Number of twenty euros note:%d\n",ch2.twn);
        printf("Number of ten euros note:%d\n",ch2.ten);
        printf("Number of five euros note:%d\n",ch2.fiv);
        printf("Number of one euro note:%d\n",ch2.one);
        printf("Number of fifty cent coins:%d\n",ch2.fif_cent);
        printf("Number of twenty cent coins:%d\n",ch2.twn_cent);
        printf("Number of ten cent coins:%d\n",ch2.d);
        printf("Number of five cent coins:%d\n",ch2.n);
        printf("Number of one cent coins:%d\n",ch2.p);
        printf("Total number of coins & paper:%d\n", ch2.c);
    }
    else if (egfunc == true)
    {
        struct check ch3 = get_change_eg();
        printf("Number of hundred EGP note:%d\n",ch3.hun);
        printf("Number of fifty EGP note:%d\n",ch3.fif);
        printf("Number of twenty EGP note:%d\n",ch3.twn);
        printf("Number of ten EGP note:%d\n",ch3.ten);
        printf("Number of five EGP note:%d\n",ch3.fiv);
        printf("Number of one pound note:%d\n",ch3.one);
        printf("Number of half pound coins:%d\n",ch3.fif_cent);
        printf("Number of quarter pound coins:%d\n",ch3.twn_cent);
        printf("Number of penny coins:%d\n",ch3.p);
        printf("Total number of coins & paper:%d\n", ch3.c);

    }
    else
    {
        printf("error");
    }



}
//FUNCTION to check which region so we can choose from dollars or euros or egyptian pound
void check_reg(){
     int region = get_reg();
     switch(region){
         case 97:
            usfunc = true;
            break;
         case 98:
            eufunc = true;
            break;
         case 99:
            egfunc = true;
            break;
         default:
            check_reg();
     }

}

//prompt function to get user's choice
int get_reg(){
    char reg;
    printf("Please Choose Your Region:\na.USA\nb.Europe\nc.Egypt\n(choose a,b or c): ");
    scanf(" %c",&reg);
    return reg;
}
//Dollars change function
struct check get_change_us(){
    double bill = 0.0;
    double cash = 0.0;
    int counter = 0, hundred_note = 0, fifty_note = 0, twenty_note = 0, ten_note = 0, five_note = 0, one_note = 0;
    int quarter =0, dime = 0, nickel = 0, penny = 0;

    while (bill <1 || cash < bill){
         printf("Total Billed:");
        scanf(" %lf", &bill);
        printf("Cash Paid:");
        scanf(" %lf", &cash);
    }

    double k = cash - bill;
    int x = round(k * 100);

    while (x > 0)
    {
         if (x >= 10000)
        {
            hundred_note = hundred_note + (x / 10000);
            x = x % 10000;
        }
        else if (x >= 5000)
        {
            fifty_note = fifty_note + (x / 5000);
            x = x % 5000;
        }
        else if (x >= 2000)
        {
            twenty_note = twenty_note + (x / 2000);
            x = x % 2000;
        }
        else if (x >= 1000)
        {
            ten_note = ten_note + (x / 1000);
            x = x % 1000;
        }
        else if (x >= 500)
        {
            five_note = five_note + (x / 500);
            x = x % 500;
        }
        else if (x >= 100)
        {
            one_note = one_note + (x / 100);
            x = x % 100;
        }
        else if (x >= 25)
        {
            quarter = quarter + (x / 25);
            x = x % 25;
        }
        else if (x >= 10)
        {
            dime = dime + (x / 10);
            x = x % 10;
        }
        else if (x >= 5)
        {
            nickel = nickel + (x / 5);
            x = x % 5;
        }
        else if (x >= 1)
        {
            penny = penny + (x / 1);
            x = x % 1;
        }
    }

    counter = hundred_note + fifty_note + twenty_note + ten_note + five_note + one_note + quarter + dime + nickel + penny;
    struct check check1 = {hundred_note, fifty_note, twenty_note, ten_note, five_note, one_note, quarter, dime, nickel, penny, counter, 0, 0, 0};
    return check1;

}


//Euros change function
struct check get_change_eu(){
    double bill = 0.0;
    double cash = 0.0;
    int counter = 0, fivehun_note = 0, hundred_note = 0, fifty_note = 0, twenty_note = 0, ten_note = 0, five_note = 0, one_euro = 0;
    int fifty_cent =0, twenty_cent = 0, ten_cent = 0, five_cent = 0, one_cent = 0;

    while (bill <1 || cash < bill){
         printf("Total Billed:");
        scanf(" %lf", &bill);
        printf("Cash Paid:");
        scanf(" %lf", &cash);
    }

    double k = cash - bill;
    int x = round(k * 100);

    while (x > 0)
    {
          if (x >= 50000)
        {
            fivehun_note = fivehun_note + (x / 50000);
            x = x % 50000;
        }
         if (x >= 10000)
        {
            hundred_note = hundred_note + (x / 10000);
            x = x % 10000;
        }
        else if (x >= 5000)
        {
            fifty_note = fifty_note + (x / 5000);
            x = x % 5000;
        }
        else if (x >= 2000)
        {
            twenty_note = twenty_note + (x / 2000);
            x = x % 2000;
        }
        else if (x >= 1000)
        {
            ten_note = ten_note + (x / 1000);
            x = x % 1000;
        }
        else if (x >= 500)
        {
            five_note = five_note + (x / 500);
            x = x % 500;
        }
        else if (x >= 100)
        {
            one_euro = one_euro + (x / 100);
            x = x % 100;
        }
        else if (x >= 50)
        {
            fifty_cent = fifty_cent + (x / 50);
            x = x % 50;
        }
        else if (x >= 20)
        {
            twenty_cent = twenty_cent + (x / 20);
            x = x % 20;
        }
        else if (x >= 10)
        {
            ten_cent = ten_cent + (x / 10);
            x = x % 10;
        }
        else if (x >= 5)
        {
            five_cent = five_cent + (x / 5);
            x = x % 5;
        }
        else if (x >= 1)
        {
            one_cent = one_cent + (x / 1);
            x = x % 1;
        }
    }

    counter = fivehun_note + hundred_note + fifty_note + twenty_note + ten_note + five_note + one_euro + fifty_cent + twenty_cent + ten_cent + five_cent + one_cent;
    struct check check2 = {hundred_note, fifty_note, twenty_note, ten_note, five_note, one_euro, 0, ten_cent, five_cent, one_cent, counter, fivehun_note, fifty_cent, twenty_cent};
    return check2;

}
//egyptien pound change function
struct check get_change_eg(){
    double bill = 0.0;
    double cash = 0.0;
    int counter = 0, hundred_note = 0, fifty_note = 0, twenty_note = 0, ten_note = 0, five_note = 0, one_egp = 0;
    int half_pound =0, quarter_pound = 0, penny = 0;

    while (bill <1 || cash < bill){
         printf("Total Billed:");
        scanf(" %lf", &bill);
        printf("Cash Paid:");
        scanf(" %lf", &cash);
    }

    double k = cash - bill;
    int x = round(k * 100);

    while (x > 0)
    {
         if (x >= 10000)
        {
            hundred_note = hundred_note + (x / 10000);
            x = x % 10000;
        }
        else if (x >= 5000)
        {
            fifty_note = fifty_note + (x / 5000);
            x = x % 5000;
        }
        else if (x >= 2000)
        {
            twenty_note = twenty_note + (x / 2000);
            x = x % 2000;
        }
        else if (x >= 1000)
        {
            ten_note = ten_note + (x / 1000);
            x = x % 1000;
        }
        else if (x >= 500)
        {
            five_note = five_note + (x / 500);
            x = x % 500;
        }
        else if (x >= 100)
        {
            one_egp = one_egp + (x / 100);
            x = x % 100;
        }
        else if (x >= 50)
        {
            half_pound = half_pound + (x / 50);
            x = x % 50;
        }
        else if (x >= 25)
        {
            quarter_pound = quarter_pound + (x / 25);
            x = x % 25;
        }
        else if (x >= 1)
        {
            penny = penny + (x / 1);
            x = x % 1;
        }
    }

    counter = hundred_note + fifty_note + twenty_note + ten_note + five_note + one_egp + half_pound + quarter_pound + penny;
    struct check check3 = {hundred_note, fifty_note, twenty_note, ten_note, five_note, one_egp, quarter_pound, 0, 0, penny, counter, 0, half_pound, 0};
    return check3;

}
