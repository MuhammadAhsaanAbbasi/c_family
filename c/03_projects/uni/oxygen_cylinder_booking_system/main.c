#include <stdio.h>
#include "include/models.h"
#include "include/file.h"
#include "include/ui.h"


int main(void) {
    ShopList shops = {0};
    CustList custs = {0};
    CylList  cyls  = {0};
    BookList books = {0};

    load_all(&shops, &custs, &cyls, &books);
    int running = 1;

    while (running) {
        switch (screen_role_selection()) {
            case 1: /* todo owner flow */ break;
            case 2: /* todo customer flow */ break;
            case 0: running = 0; break;
        }
    }

    save_all(&shops, &custs, &cyls, &books);
    puts("Saving data… Goodbye!");
    return 0;
}
