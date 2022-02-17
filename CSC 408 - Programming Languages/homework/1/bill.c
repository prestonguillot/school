#include <stdio.h>
#include <stdlib.h>

typedef struct customer customer;

struct customer {
    char name[33];
    char type;
    double kwatts;
    double amount;
};

#define MAX 100

int read_customers ( customer c[], int max );
void compute_bill ( customer *c );
void compute_bills ( customer c[], int n );
void report ( customer c[], int n );
int compare_amount ( const void *a, const void *b );

int read_customers ( customer c[], int max )
{
    int i;
    char type[2];

    for ( i = 0; i < max; i++ ) {
        if ( scanf("%32[^\n] %1s %lf ", c[i].name, type, &c[i].kwatts ) != 3 ){
            break;
        }
        c[i].type = type[0];
    }
    return i;
}

void compute_bill ( customer *c )
{
    double base, base_cost, cost_kwatt;

    switch ( c->type ) {
        case 'C':
            base_cost = 100;
            base = 10000;
            cost_kwatt = 0.53;
            break;
        case 'D':
            base_cost = 15;
            base = 1000;
            cost_kwatt = 0.17;
            break;
        case 'E':
            base_cost = 50;
            base = 5000;
            cost_kwatt = 0.12;
            break;
        default:
            printf("Error bad type (%c) for %s\n", c->type, c->name );
            return;
    }
    c->amount = base_cost;
    if ( c->kwatts > base ) {
        c->amount += (c->kwatts - base) * cost_kwatt;
    }
}

void compute_bills ( customer c[], int n )
{
    int i;

    for ( i = 0; i < n; i++ ) {
        compute_bill ( c+i );
    }
}

void report ( customer c[], int n )
{
    int i;

    for ( i = 0; i < n; i++ ) {
        printf("%-32s     %c    %10.1f  %10.2f\n",
                c[i].name, c[i].type, c[i].kwatts, c[i].amount );
    }
}

int compare_amount ( const void *a, const void *b )
{
    const customer *x;
    const customer *y;

    x = a;
    y = b;
    if ( x->amount < y->amount ) return 1;
    if ( x->amount > y->amount ) return -1;
    return 0;
}

int main ( void )
{
    customer customers[MAX];
    int n;

    n = read_customers ( customers, MAX );
    compute_bills ( customers, n );
    qsort ( customers, n, sizeof(customer), compare_amount );
    report ( customers, n );
    return 0;
}
