#include <stdio.h>
#include "include/models.h"
#include "include/file.h"
#include "include/ui.h"

int main(void)
{
    ShopList shops = {0};
    CustList custs = {0};
    CylList cyls = {0};
    BookList books = {0};

    load_all(&shops, &custs, &cyls, &books);

    int running = 1;
    while (running)
    {
        switch (screen_role_selection())
        {
        case 1:
        {
            int ownerIdx = -1;
            if (screen_owner_auth(&shops, &ownerIdx))
                screen_owner_menu(&shops, &cyls, &books, ownerIdx);
            break;
        }
        case 2:
        {
            int custIdx = -1;
            if (screen_customer_auth(&custs, &custIdx))
                screen_customer_menu(&custs, &cyls, custIdx);
            break;
        }
        case 0:
            running = 0;
            break;
        }
    }

    save_all(&shops, &custs, &cyls, &books);
    free_all_lists(&shops, &custs, &cyls, &books);
    puts("Saving data… Goodbye!");
    return 0;
}
