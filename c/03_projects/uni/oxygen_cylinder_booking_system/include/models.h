#ifndef MODELS_H
#define MODELS_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME     50
#define MAX_USER     20
#define MAX_PASS     20
#define MAX_COLOR    15
#define MAX_ADDR     80
#define MAX_PHONE    15
#define MAX_EMAIL    50

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
    char   email[MAX_EMAIL];
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

/* private helper */
static void *grow(void *ptr, size_t *cap, size_t elem, size_t len) {
    if (len < *cap) return ptr;
    size_t newCap = (*cap == 0) ? 4 : (*cap * 2);
    void *tmp = realloc(ptr, newCap * elem);
    if (!tmp) { perror("realloc"); exit(EXIT_FAILURE); }
    *cap = newCap;
    return tmp;
}

/* ───── Shop helpers ───── */
int add_shop(ShopList *l, const char *name,
             const char *user, const char *pass)
{
    l->data = grow(l->data, &l->cap, sizeof(Shop), l->len);
    Shop *s = &l->data[l->len];
    s->id = (int)(l->len ? l->data[l->len-1].id + 1 : 1);
    snprintf(s->name,     MAX_NAME, "%s", name);
    snprintf(s->username, MAX_USER, "%s", user);
    snprintf(s->password, MAX_PASS, "%s", pass);
    return (int)l->len++;              /* return index of new shop */
}

int find_shop_by_username(const ShopList *l, const char *user)
{
    for (size_t i = 0; i < l->len; ++i)
        if (strcmp(l->data[i].username, user) == 0) return (int)i;
    return -1;
}

/* Will expand later for customers, cylinders, bookings */

void free_all_lists(ShopList *s, CustList *c, CylList *y, BookList *b)
{
    free(s->data);  free(c->data);  free(y->data);  free(b->data);
}

/* after grow() helper and shop functions ---------------------------- */

int add_cylinder(CylList *l, int shop_id,
                 const char *size, float vol,
                 float price, const char *color, int stock)
{
    l->data = grow(l->data, &l->cap, sizeof(Cylinder), l->len);
    Cylinder *c = &l->data[l->len];
    c->id      = (int)(l->len ? l->data[l->len-1].id + 1 : 1);
    c->shop_id = shop_id;
    snprintf(c->size,  MAX_NAME,  "%s", size);
    c->volume  = vol;
    c->price   = price;
    snprintf(c->color, MAX_COLOR, "%s", color);
    c->stock   = stock;
    return (int)l->len++;
}

void list_cylinders_for_shop(const CylList *l, int shop_id)
{
    puts("\nID | Size   | Vol | Price | Color | Stock");
    puts("-----------------------------------------------");
    for (size_t i = 0; i < l->len; ++i) {
        const Cylinder *c = &l->data[i];
        if (c->shop_id != shop_id) continue;
        printf("%-3d| %-6s| %-4.1f| %-6.0f| %-6s| %-5d\n",
               c->id, c->size, c->volume, c->price, c->color, c->stock);
    }
}

/* ───── Customer helpers ───── */
int add_customer(CustList *l, const char *name, const char *phone, 
                 const char *email,
                 const char *addr, const char *pass)
{
    l->data = grow(l->data, &l->cap, sizeof(Customer), l->len);
    Customer *c = &l->data[l->len];
    c->id = (int)(l->len ? l->data[l->len-1].id + 1 : 1);
    snprintf(c->name,    MAX_NAME,  "%s", name);
    snprintf(c->phone,   MAX_PHONE, "%s", phone);
    snprintf(c->email,   MAX_EMAIL, "%s", email);
    snprintf(c->address, MAX_ADDR,  "%s", addr);
    snprintf(c->password,MAX_PASS,  "%s", pass);
    return (int)l->len++;
}

int find_customer_by_email(const CustList *l, const char *email)
{
    for (size_t i = 0; i < l->len; ++i)
        if (strcmp(l->data[i].email, email) == 0) return (int)i;
    return -1;
}


#endif
