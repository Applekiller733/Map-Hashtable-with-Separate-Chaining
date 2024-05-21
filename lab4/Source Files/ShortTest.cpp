#include "../Header Files/ShortTest.h"
#include <assert.h>
#include "../Header Files/Map.h"
#include "../Header Files/MapIterator.h"

#include <iostream>

void testAll() { //call each function to see if it is implemented
	Map m;
	assert(m.isEmpty() == true);
	assert(m.size() == 0); //add elements
	assert(m.add(5,5)==NULL_TVALUE);
	assert(m.add(1,111)==NULL_TVALUE);
	assert(m.add(10,110)==NULL_TVALUE);
	assert(m.add(7,7)==NULL_TVALUE);
	assert(m.add(1,1)==111);
	assert(m.add(10,10)==110);
	assert(m.add(-3,-3)==NULL_TVALUE);
//    std::cout << "Reached here\n";
	assert(m.size() == 5);
	assert(m.search(10) == 10);
	assert(m.search(16) == NULL_TVALUE);
//    std::cout << "Reached here2\n";
	assert(m.remove(1) == 1);
	assert(m.remove(6) == NULL_TVALUE);
	assert(m.size() == 4);
//    std::cout << "Reached here3\n";

	TElem e;
	MapIterator id = m.iterator();
	id.first();
	int s1 = 0, s2 = 0;

//    std::cout << id.valid()<<"\n";
//    id.next(); id.next();
//    std::cout << id.getCurrent().second << "\n";
//    id.next(); id.next(); id.next(); id.next();
//    std::cout << id.valid() << "\n";
//    id.next();
//    std::cout << id.getCurrent().second << "\n";

	while (id.valid()) {
		e = id.getCurrent();
        //std::cout << e.first << " " << e.second << "\n";
		s1 += e.first;
		s2 += e.second;
		id.next();
	}
	assert(s1 == 22);
	assert(s2 == 22);

}


