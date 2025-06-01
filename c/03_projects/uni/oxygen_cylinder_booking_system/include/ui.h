/* ui.h */
#ifndef UI_H
#define UI_H

#include "models.h" // ←  bring the list typedefs into scope
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ───── helpers ───── */
static int read_int(const char *prompt, int min, int max)
{
    int x;
    for (;;)
    {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1 && x >= min && x <= max)
        {
            getchar();
            return x;
        }
        puts("Invalid input.");
        while (getchar() != '\n')
            ;
    }
}

static void read_line(const char *prompt, char *buf, size_t n)
{
    printf("%s", prompt);
    fgets(buf, (int)n, stdin);
    buf[strcspn(buf, "\n")] = 0;
}

/* ───── screen 1 ───── */
int screen_role_selection(void)
{
    puts("\n=== Oxygen Cylinder Booking System ===");
    puts("Select role:");
    puts("  1. Shop Owner");
    puts("  2. Customer");
    puts("  0. Exit");
    return read_int("Enter choice (0-2): ", 0, 2);
}

/* ───── shop-owner auth ───── */
static int register_owner(ShopList *shops)
{
    char name[64], user[32], pass[32];
    read_line("Shop name: ", name, sizeof name);
    for (;;)
    {
        read_line("Username: ", user, sizeof user);
        if (find_shop_by_username(shops, user) == -1)
            break;
        puts("Username already taken!");
    }
    read_line("Password: ", pass, sizeof pass);
    int idx = add_shop(shops, name, user, pass);
    printf("Registered! Your Shop ID is %d\n", shops->data[idx].id);
    return idx;
}

static int login_owner(ShopList *shops)
{
    char user[32], pass[32];
    read_line("Username: ", user, sizeof user);
    int idx = find_shop_by_username(shops, user);
    if (idx == -1)
    {
        puts("No such user.");
        return -1;
    }
    read_line("Password: ", pass, sizeof pass);
    if (strcmp(pass, shops->data[idx].password) != 0)
    {
        puts("Wrong password.");
        return -1;
    }
    puts("Login successful!");
    return idx;
}

int screen_owner_auth(ShopList *shops, int *outIdx)
{
    for (;;)
    {
        puts("\n=== Shop Owner ===");
        puts("1. Register New Shop");
        puts("2. Login as Shop Owner");
        puts("3. Back to Role Selection");
        int ch = read_int("Enter choice (1-3): ", 1, 3);
        if (ch == 1)
        {
            *outIdx = register_owner(shops);
            return 1;
        }
        if (ch == 2)
        {
            int idx = login_owner(shops);
            if (idx != -1)
            {
                *outIdx = idx;
                return 1;
            }
        }
        if (ch == 3)
            return 0;
    }
}

void owner_view_shop_bookings(const ShopList *shops, const CylList *cyls,
                              const BookList *books, int ownerIdx)
{
    int shopId = shops->data[ownerIdx].id;
    puts("\nID | CustID | CylID | Qty | Total | Status");
    puts("----------------------------------------------");
    int found = 0;
    for (size_t i = 0; i < books->len; ++i)
    {
        const Booking *b = &books->data[i];
        /* find cylinder to see which shop owns it */
        int cIdx = find_cylinder_by_id(cyls, b->cylinder_id);
        if (cIdx == -1)
            continue;
        if (cyls->data[cIdx].shop_id != shopId)
            continue;

        printf("%-3d| %-7d| %-6d| %-3d| %-6.0f| %s\n",
               b->id, b->customer_id, b->cylinder_id, b->qty, b->total, b->status);
        found = 1;
    }
    if (!found)
        puts("No bookings for your shop.");
    puts("Press Enter to return…");
    getchar();
}

void owner_add_cylinder(ShopList *shops, CylList *cyls, int ownerIdx)
{
    char size[32], color[16];
    float vol, price;
    int stock;
    read_line("Size (Small/Medium/Large): ", size, sizeof size);
    vol = (float)read_int("Volume (kg): ", 1, 100);
    printf("Price : ");
    scanf("%f", &price);
    getchar();
    read_line("Color : ", color, sizeof color);
    stock = read_int("Initial stock: ", 0, 1000);

    add_cylinder(cyls, shops->data[ownerIdx].id,
                 size, vol, price, color, stock);
    puts("Cylinder added!");
}

void owner_view_cylinders(const ShopList *shops,
                          const CylList *cyls,
                          int ownerIdx)
{
    (void)shops;
    list_cylinders_for_shop(cyls, shops->data[ownerIdx].id);
    puts("Press Enter to return…");
    getchar();
}

/* ─── customer register/login ─── */
static int register_customer(CustList *custs)
{
    char name[64], phone[32], addr[96], pass[32], email[64];
    read_line("Full name : ", name, sizeof name);
    read_line("Phone    : ", phone, sizeof phone);
    for (;;)
    {
        read_line("Email    : ", email, sizeof email);
        if (find_customer_by_email(custs, email) == -1)
            break;
        puts("Email already registered!");
    }
    read_line("Address   : ", addr, sizeof addr);
    read_line("Password  : ", pass, sizeof pass);
    int idx = add_customer(custs, name, phone, email, addr, pass);
    printf("Registered! Your Customer ID is %d\n",
           custs->data[idx].id);
    return idx;
}

static int login_customer(CustList *custs)
{
    char email[50], pass[32];
    read_line("Email    : ", email, sizeof email);
    int idx = find_customer_by_email(custs, email);
    if (idx == -1)
    {
        puts("Not found.");
        return -1;
    }
    read_line("Password : ", pass, sizeof pass);
    if (strcmp(pass, custs->data[idx].password) != 0)
    {
        puts("Wrong password.");
        return -1;
    }
    puts("Login successful!");
    return idx;
}

/* ────── customer flow ────── */
int screen_customer_auth(CustList *custs, int *outIdx)
{
    for (;;)
    {
        puts("\n=== Customer ===");
        puts("1. Register New Customer");
        puts("2. Login as Customer");
        puts("3. Back to Role Selection");
        int ch = read_int("Enter choice (1-3): ", 1, 3);
        if (ch == 1)
        {
            *outIdx = register_customer(custs);
            return 1;
        }
        if (ch == 2)
        {
            int idx = login_customer(custs);
            if (idx != -1)
            {
                *outIdx = idx;
                return 1;
            }
        }
        if (ch == 3)
            return 0;
    }
}

/* -------------------------------------------------- */
/* search cylinders by size / color / price           */
/* -------------------------------------------------- */
static int str_ieq(const char *a, const char *b) /* case-insensitive eq */
{
    while (*a && *b)
    {
        char ca = (char)tolower((unsigned char)*a++);
        char cb = (char)tolower((unsigned char)*b++);
        if (ca != cb)
            return 0;
    }
    return *a == *b;
}

void customer_search_cylinders(const CylList *cyls)
{
    puts("\nSearch by:");
    puts("  1. Size  (e.g. Small / Medium / Large)");
    puts("  2. Color (e.g. Blue)");
    puts("  3. Price range");
    int mode = read_int("Enter choice (1-3): ", 1, 3);

    char needle[32] = {0};
    float pmin = 0, pmax = 0;

    if (mode == 1)
        read_line("Size : ", needle, sizeof needle);
    else if (mode == 2)
        read_line("Color: ", needle, sizeof needle);
    else
    {
        printf("Min price (0 = no min): ");
        scanf("%f", &pmin);
        getchar();
        printf("Max price (0 = no max): ");
        scanf("%f", &pmax);
        getchar();
        if (pmax && pmin > pmax)
        {
            float tmp = pmin;
            pmin = pmax;
            pmax = tmp;
        }
    }

    /* header */
    puts("\nID | Size | Vol | Price | Color | Stock");
    puts("-----------------------------------------");

    int found = 0;
    for (size_t i = 0; i < cyls->len; ++i)
    {
        const Cylinder *c = &cyls->data[i];

        int match = 0;
        if (mode == 1)
            match = str_ieq(c->size, needle);
        else if (mode == 2)
            match = str_ieq(c->color, needle);
        else
        { /* price */
            int aboveMin = (pmin == 0 || c->price >= pmin);
            int belowMax = (pmax == 0 || c->price <= pmax);
            match = aboveMin && belowMax;
        }

        if (match)
        {
            printf("%-3d| %-4s| %-4.1f| %-6.0f| %-6s| %-5d\n",
                   c->id, c->size, c->volume, c->price, c->color, c->stock);
            found = 1;
        }
    }
    if (!found)
        puts("No cylinders match your criteria.");
    puts("Press Enter to return…");
    getchar();
}

void screen_browse(const CylList *cyls, BookList *books, int custIdx)
{
    size_t total = cyls->len, page = 0;
    for (;;)
    {
        size_t start = page * 10;
        if (start >= total)
        {
            puts("No more.");
            break;
        }
        size_t end = (start + 10 < total) ? start + 10 : total;
        puts("\nID | Size | Vol | Price | Color | Stock");
        puts("-----------------------------------------");
        for (size_t i = start; i < end; ++i)
        {
            const Cylinder *c = &cyls->data[i];
            printf("%-3d| %-4s| %-4.1f| %-6.0f| %-6s| %-5d\n",
                   c->id, c->size, c->volume, c->price, c->color, c->stock);
        }
        // printf("Showing %zu-%zu of %zu. (N)ext / (P)rev / (Q)uit: ",
        //        start+1,end,total);
        int id = read_int("Enter Cylinder ID for details (0 to quit, -1 next, -2 prev): ",
                          -2, 1000000);

        if (id == 0)
            break;
        if (id == -1)
        {
            page++;
            continue;
        }
        if (id == -2 && page)
        {
            page--;
            continue;
        }

        int idx = find_cylinder_by_id(cyls, id);
        if (idx == -1)
            puts("Invalid ID.");
        else
            screen_view_details(cyls, books, custIdx, idx);
    }
}

void screen_view_details(const CylList *cyls, BookList *books,
                         int custIdx, int cylIdx)
{
    const Cylinder *c = &cyls->data[cylIdx];
    printf("\n=== Cylinder Details ===\n"
           "ID: %d\nSize: %s\nVolume: %.1f\nPrice: %.0f\n"
           "Color: %s\nStock: %d\n",
           c->id, c->size, c->volume, c->price, c->color, c->stock);

    puts("\nOptions:\n  1. Book this Cylinder\n  2. Back");
    int ch = read_int("Enter choice (1-2): ", 1, 2);
    if (ch == 1)
        screen_booking_flow((CylList *)cyls, books, custIdx, cylIdx);
}

void screen_booking_flow(CylList *cyls, BookList *books,
                         int custIdx, int cylIdx)
{
    Cylinder *c = &cyls->data[cylIdx];
    printf("\n=== Book Cylinder ===\n");
    printf("Cylinder ID %d (%s / %.1f / %s)\nAvailable Stock: %d\n",
           c->id, c->size, c->volume, c->color, c->stock);

    if (c->stock == 0)
    {
        puts("Out of stock.");
        return;
    }

    int qty = read_int("Enter quantity: ", 1, c->stock);
    float total = qty * c->price;
    printf("Total cost = %d × %.0f = %.0f\n", qty, c->price, total);
    char confirm[8];
    read_line("Confirm booking? (y/n): ", confirm, sizeof confirm);
    if (confirm[0] != 'y' && confirm[0] != 'Y')
    {
        puts("Cancelled.");
        return;
    }

    /* update stock & add booking */
    c->stock -= qty;
    int bookIdx = add_booking(books, custIdx, c->id, qty, total, "Active");

    printf("Thank you! Your Booking ID is #%d.\n",
           books->data[bookIdx].id);
    puts("Press Enter to return to Browse…");
    getchar();
}

void customer_view_bookings(const BookList *books, int custIdx)
{
    puts("\nBooking ID | Cyl ID | Qty | Total | Status");
    puts("---------------------------------------------");
    int found = 0;
    for (size_t i = 0; i < books->len; ++i)
    {
        const Booking *b = &books->data[i];
        if (b->customer_id != custIdx)
            continue;
        printf("%-10d | %-6d | %-3d | %-5.0f | %s\n",
               b->id, b->cylinder_id, b->qty, b->total, b->status);
        found = 1;
    }
    if (!found)
        puts("You have no bookings.");
    puts("Press Enter to return…");
    getchar();
}

void customer_cancel_booking(BookList *books, CylList *cyls, int custIdx)
{
    int id = read_int("Enter Booking ID to cancel: ", 1, 1000000);
    int idx = find_booking_by_id(books, id);
    if (idx == -1 || books->data[idx].customer_id != custIdx)
    {
        puts("Booking not found.");
        return;
    }
    Booking *b = &books->data[idx];
    if (strcmp(b->status, "Cancelled") == 0)
    {
        puts("Already cancelled.");
        return;
    }
    char yn[8];
    read_line("Confirm cancel (y/n)? ", yn, sizeof yn);
    if (yn[0] != 'y' && yn[0] != 'Y')
    {
        puts("Aborted.");
        return;
    }

    restock_on_cancel(books, cyls, idx);
    puts("Booking cancelled and stock restored.");
}

void owner_update_remove_cylinder(ShopList *shops, CylList *cyls,
                                  BookList *books, int ownerIdx)
{
    int id = read_int("Enter Cylinder ID: ", 1, 1000000);
    int idx = find_cylinder_by_id(cyls, id);
    if (idx == -1 || cyls->data[idx].shop_id != shops->data[ownerIdx].id)
    {
        puts("Cylinder not found in your shop.");
        return;
    }
    Cylinder *c = &cyls->data[idx];
    printf("Selected → ID %d  (%s / %.1f / %s)  Price: %.0f  Stock: %d\n",
           c->id, c->size, c->volume, c->color, c->price, c->stock);

    puts("1. Update Stock");
    puts("2. Update Price");
    puts("3. Remove Cylinder");
    puts("4. Cancel");
    int choice = read_int("Choose (1-4): ", 1, 4);

    if (choice == 1)
    {
        int newStock = read_int("New stock: ", 0, 100000);
        c->stock = newStock;
        puts("Stock updated.");
    }
    else if (choice == 2)
    {
        float newPrice;
        printf("New price: ");
        scanf("%f", &newPrice);
        getchar();
        c->price = newPrice;
        puts("Price updated.");
    }
    else if (choice == 3)
    {
        if (has_active_bookings(books, c->id))
        {
            puts("Cannot delete: there are ACTIVE bookings for this cylinder.");
            return;
        }
        char yn[8];
        read_line("Really delete? (y/n): ", yn, sizeof yn);
        if (yn[0] == 'y' || yn[0] == 'Y')
        {
            delete_cylinder(cyls, idx);
            puts("Cylinder removed.");
        }
    }
}

/* ───── owner main menu stub (Milestone 3) ───── */
int screen_owner_menu(ShopList *shops, CylList *cyls, BookList *books, int ownerIdx)
{
    (void)books; /* bookings & appointments arrive later */
    int loop = 1;
    while (loop)
    {
        puts("\n=== Shop Owner Menu ===");
        puts("1. Add New Cylinder Type");
        puts("2. View All Cylinder Types");
        puts("3. Update / Remove Cylinder Type");
        puts("4. View All Customer Bookings");
        // puts("5. View Appointments");
        puts("5. Logout");
        switch (read_int("Enter choice (1-6): ", 1, 6))
        {
        case 1:
            owner_add_cylinder(shops, cyls, ownerIdx);
            break;
        case 2:
            owner_view_cylinders(shops, cyls, ownerIdx);
            break;
        case 3:
            owner_update_remove_cylinder(shops, cyls, books, ownerIdx);
            break;
        case 4:
            owner_view_shop_bookings(shops, cyls, books, ownerIdx);
            break;
        // case 5:
        //     puts("Feature coming in Milestone 8.");
        //     break;
        case 5:
            loop = 0;
            break;
        }
    }
    return 0;
}

// customer main menu
void screen_customer_menu(const CustList *custs,
                          const CylList *cyls,
                          const BookList *books,
                          int custIdx)
{
    (void)custs;
    (void)custIdx; /* bookings arrive later */
    int loop = 1;
    while (loop)
    {
        puts("\n=== Customer Menu ===");
        puts("1. Browse Cylinders");
        puts("2. Search Cylinders");
        puts("3. View My Bookings");
        puts("4. Cancel a Booking");
        puts("5. Logout");
        switch (read_int("Enter choice (1-5): ", 1, 5))
        {
        case 1:
            screen_browse(cyls, books, custIdx);
            break;
        case 2:
            customer_search_cylinders(cyls);
            break;
        case 3:
            customer_view_bookings(books, custIdx);
            break;
        case 4:
            customer_cancel_booking(books, (CylList *)cyls, custIdx);
            break;
        case 5:
            loop = 0;
            break;
        }
    }
}

// /* ────── browsing & booking ────── */
// void screen_browse(CylList *cyls,
//                    int      custIdx,
//                    BookList *books);

// void screen_search(CylList *cyls,
//                    int      custIdx,
//                    BookList *books);

// void screen_view_details(CylList *cyls,
//                          int      cylIdx,
//                          int      custIdx,
//                          BookList *books);

// void screen_booking_flow(CylList *cyls,
//                          int      cylIdx,
//                          int      custIdx,
//                          BookList *books);

#endif /* UI_H */
