/* file.h  –  CSV version  --------------------------------------------------*/
#ifndef FILE_H
#define FILE_H

#include "models.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#ifdef _WIN32
#include <direct.h> /* _mkdir */
#endif

#define DATA_DIR "data"
#define SHOPS_FILE DATA_DIR "/shops.csv"
#define CYLS_FILE DATA_DIR "/inventory.csv"
#define CUST_FILE DATA_DIR "/customers.csv"
#define BOOK_FILE DATA_DIR "/bookings.csv"

/* ───── helpers ───── */
static void *xmalloc(size_t n)
{
    void *p = malloc(n);
    if (!p)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return p;
}

/* create ./data if missing */
static int ensure_data_dir(void)
{
#ifdef _WIN32
    return (_mkdir(DATA_DIR) == 0 || errno == EEXIST) ? 0 : -1;
#else
    return (mkdir(DATA_DIR, 0755) == 0 || errno == EEXIST) ? 0 : -1;
#endif
}

/* ───── CSV – ShopList only (add others later) ───── */
static void save_shops_csv(const ShopList *shops)
{
    FILE *f = fopen(SHOPS_FILE, "w");
    if (!f)
    {
        perror("open shops.csv for write");
        exit(EXIT_FAILURE);
    }

    /* header row */
    fprintf(f, "id,name,username,password\n");

    /* each record */
    for (size_t i = 0; i < shops->len; ++i)
    {
        const Shop *s = &shops->data[i];
        fprintf(f, "%d,%s,%s,%s\n",
                s->id, s->name, s->username, s->password);
    }
    fclose(f);
}

static void save_cyls_csv(const CylList *cyls)
{
    FILE *f = fopen(CYLS_FILE, "w");
    if (!f)
    {
        perror("open inventory.csv for write");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "id,shop_id,size,volume,price,color,stock\n");
    for (size_t i = 0; i < cyls->len; ++i)
    {
        const Cylinder *c = &cyls->data[i];
        fprintf(f, "%d,%d,%s,%.2f,%.2f,%s,%d\n",
                c->id, c->shop_id, c->size, c->volume, c->price, c->color, c->stock);
    }
    fclose(f);
}

static void save_cust_csv(const CustList *custs)
{
    FILE *f = fopen(CUST_FILE, "w");
    if (!f)
    {
        perror("open customers.csv");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "id,name,email,phone,address,password\n");
    for (size_t i = 0; i < custs->len; ++i)
    {
        const Customer *c = &custs->data[i];
        fprintf(f, "%d,%s,%s,%s,%s,%s\n",
                c->id, c->name, c->email, c->phone, c->address, c->password);
    }
    fclose(f);
}

static void save_book_csv(const BookList *books)
{
    FILE *f = fopen(BOOK_FILE, "w");
    if (!f)
    {
        perror("open bookings.csv");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "id,cust_id,cyl_id,qty,total,date,status\n");
    for (size_t i = 0; i < books->len; ++i)
    {
        const Booking *b = &books->data[i];
        fprintf(f, "%d,%d,%d,%d,%.2f,%ld,%s\n",
                b->id, b->customer_id, b->cylinder_id,
                b->qty, b->total, (long)b->date, b->status);
    }
    fclose(f);
}

static void load_shops_csv(ShopList *shops)
{
    FILE *f = fopen(SHOPS_FILE, "r");
    if (!f)
        return; /* first run – file not there */

    char line[256];

    /* discard header */
    if (!fgets(line, sizeof line, f))
    {
        fclose(f);
        return;
    }

    while (fgets(line, sizeof line, f))
    {
        /* strip newline */
        line[strcspn(line, "\r\n")] = 0;

        /* parse four comma-separated fields */
        Shop s = {0};
        char name[MAX_NAME], user[MAX_USER], pass[MAX_PASS];
        if (sscanf(line, "%d,%49[^,],%19[^,],%19[^,\n]",
                   &s.id, name, user, pass) == 4)
        {
            snprintf(s.name, MAX_NAME, "%s", name);
            snprintf(s.username, MAX_USER, "%s", user);
            snprintf(s.password, MAX_PASS, "%s", pass);

            /* grow list and append */
            shops->data = realloc(shops->data, (shops->len + 1) * sizeof(Shop));
            shops->data[shops->len++] = s;
            shops->cap = shops->len;
        }
    }
    fclose(f);
}

static void load_cyls_csv(CylList *cyls)
{
    FILE *f = fopen(CYLS_FILE, "r");
    if (!f)
        return;
    char line[256];
    fgets(line, sizeof line, f); /* header */
    while (fgets(line, sizeof line, f))
    {
        line[strcspn(line, "\r\n")] = 0;
        Cylinder c = {0};
        if (sscanf(line, "%d,%d,%49[^,],%f,%f,%14[^,],%d",
                   &c.id, &c.shop_id, c.size, &c.volume, &c.price, c.color, &c.stock) == 7)
        {
            cyls->data = realloc(cyls->data, (cyls->len + 1) * sizeof(Cylinder));
            cyls->data[cyls->len++] = c;
            cyls->cap = cyls->len;
        }
    }
    fclose(f);
}

static void load_cust_csv(CustList *custs)
{
    FILE *f = fopen(CUST_FILE, "r");
    if (!f)
        return;
    char line[256];
    fgets(line, sizeof line, f); /* header */
    while (fgets(line, sizeof line, f))
    {
        line[strcspn(line, "\r\n")] = 0;
        Customer c = {0};
        if (sscanf(line,
                   "%d,%49[^,],%49[^,],%14[^,],%79[^,],%19[^,]",
                   &c.id, c.name, c.email, c.phone, c.address, c.password) == 6)
        {
            custs->data = realloc(custs->data, (custs->len + 1) * sizeof(Customer));
            custs->data[custs->len++] = c;
            custs->cap = custs->len;
        }
    }
    fclose(f);
}

static void load_book_csv(BookList *books)
{
    FILE *f = fopen(BOOK_FILE, "r");
    if (!f)
        return;
    char line[256];
    fgets(line, sizeof line, f); /* header */
    while (fgets(line, sizeof line, f))
    {
        line[strcspn(line, "\r\n")] = 0;
        Booking b = {0};
        if (sscanf(line, "%d,%d,%d,%d,%f,%ld,%9[^,]",
                   &b.id, &b.customer_id, &b.cylinder_id,
                   &b.qty, &b.total, &b.date, b.status) == 7)
        {
            books->data = realloc(books->data, (books->len + 1) * sizeof(Booking));
            books->data[books->len++] = b;
            books->cap = books->len;
        }
    }
    fclose(f);
}

/* ───── public API ───── */
static void load_all(ShopList *s, CustList *c, CylList *y, BookList *b)
{
    ensure_data_dir();
    load_shops_csv(s);
    load_cust_csv(c);
    load_cyls_csv(y);
    load_book_csv(b); /* NEW */
}

static void save_all(const ShopList *s, const CustList *c,
                     const CylList *y, const BookList *b)
{
    ensure_data_dir();
    save_shops_csv(s);
    save_cust_csv(c);
    save_cyls_csv(y);
    save_book_csv(b); /* NEW */
}

#endif /* FILE_H */
