/* ui.h */
#ifndef UI_H
#define UI_H

#include "models.h"          // ←  bring the list typedefs into scope

/* ────── role selection ────── */
int  screen_role_selection(void);

/* ────── shop-owner flow ────── */
int  screen_owner_auth(const ShopList *shops,
                       int *out_shop_index);        // returns 0=back, 1=logged-in
void screen_owner_menu(ShopList *shops,
                       CylList  *cyls,
                       BookList *books);

/* ────── customer flow ────── */
int  screen_customer_auth(const CustList *custs,
                          int *out_cust_index);
void screen_customer_menu(CustList *custs,
                          CylList  *cyls,
                          BookList *books);

/* ────── browsing & booking ────── */
void screen_browse(CylList *cyls,
                   int      custIdx,
                   BookList *books);

void screen_search(CylList *cyls,
                   int      custIdx,
                   BookList *books);

void screen_view_details(CylList *cyls,
                         int      cylIdx,
                         int      custIdx,
                         BookList *books);

void screen_booking_flow(CylList *cyls,
                         int      cylIdx,
                         int      custIdx,
                         BookList *books);

#endif /* UI_H */
