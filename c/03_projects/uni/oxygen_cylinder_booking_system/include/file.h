/* file.h */
#ifndef FILE_H
#define FILE_H

#include "models.h"   // <— add this

void load_all(ShopList *shops,
              CustList *custs,
              CylList  *cyls,
              BookList *books);

void save_all(const ShopList *shops,
              const CustList *custs,
              const CylList  *cyls,
              const BookList *books);

#endif /* FILE_H */
