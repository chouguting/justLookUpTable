#include "book.h"
ostream& operator<<(ostream& os, const book& b)
{
	os << "bookName:" << *(b.bookName)
		<< "\tauthors:" << *(b.authors)
		<< "\tprice:" << b.price << endl;
	return os;
}