#ifndef MODELS_H
#define MODELS_H
#include <time.h>

#define MAX_NAME     50
#define MAX_USER     20
#define MAX_PASS     20
#define MAX_COLOR    15
#define MAX_ADDR     80
#define MAX_PHONE    15

typedef struct {
    int    id;
    char   name[MAX_NAME];
    char   username[MAX_USER];
    char   password[MAX_PASS];
} Shop;

typedef struct {
    int    id;
    char   name[MAX_NAME];
    char   phone[MAX_PHONE];
    char   address[MAX_ADDR];
    char   password[MAX_PASS];
} Customer;

typedef struct {
    int  id;
    int  shop_id;           // FK → Shop
    char size[MAX_NAME];    // Small/Medium/Large …
    float volume;           // kg or L
    float price;
    char color[MAX_COLOR];
    int  stock;
} Cylinder;

typedef struct {
    int      id;
    int      customer_id;   // FK
    int      cylinder_id;   // FK → inventory row
    int      qty;
    float    total;
    time_t   date;
    char     status[10];    // "Active" / "Cancelled"
} Booking;

/* === In-memory pools (growable) === */
typedef struct { Shop      *data; size_t len, cap; } ShopList;
typedef struct { Customer  *data; size_t len, cap; } CustList;
typedef struct { Cylinder  *data; size_t len, cap; } CylList;
typedef struct { Booking   *data; size_t len, cap; } BookList;

#endif
