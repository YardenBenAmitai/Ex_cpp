#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
	ariel::Tree emptytree;
	ariel::Tree threetree;  
	threetree.insert(5);
	threetree.insert(7);
	threetree.insert(3);
        threetree.insert(0);
        threetree.insert(18);
        threetree.insert(14);
        threetree.insert(4);

	ariel::Tree mytree;  
	badkan::TestCase tc("Binary tree");
	tc
		.CHECK_EQUAL (emptytree.size(), 0)
		.CHECK_OK    (emptytree.insert(5))
		.CHECK_EQUAL (emptytree.size(), 1)
		.CHECK_EQUAL (emptytree.contains(5), true)
		.CHECK_OK    (emptytree.remove(5))
		.CHECK_EQUAL (emptytree.contains(5), false)
		.CHECK_THROWS(emptytree.remove(5))
		.CHECK_EQUAL (emptytree.size() ,0)
		.CHECK_EQUAL (threetree.size(), 7)
		.CHECK_EQUAL (threetree.root(), 5)
		.CHECK_EQUAL (threetree.parent(3), 5)
		.CHECK_EQUAL (threetree.parent(7), 5)
		.CHECK_EQUAL (threetree.left(5), 3)
		.CHECK_EQUAL (threetree.right(5), 7)
		.CHECK_THROWS(threetree.insert(3))
		.CHECK_THROWS(threetree.left(6))
		.CHECK_OK    (threetree.print())
                .CHECK_EQUAL (threetree.contains(13), false)
                .CHECK_OK    (threetree.insert(13))
                .CHECK_EQUAL (threetree.contains(13), true)
                .CHECK_THROWS(threetree.remove(17))
                .CHECK_EQUAL (threetree.size() ,8)
                .CHECK_EQUAL (threetree.right(7), 18)
                .CHECK_OK    (threetree.remove(5))
                .CHECK_EQUAL (threetree.root(), 4)
                .CHECK_EQUAL (threetree.parent(3), 4)
                .CHECK_EQUAL (threetree.parent(18), 7)
                .CHECK_EQUAL (threetree.left(4), 3)
                .CHECK_EQUAL (threetree.right(7), 18)
                .CHECK_THROWS(threetree.insert(18))
                .CHECK_EQUAL (threetree.left(3), 17)
                .CHECK_OK    (threetree.print())
		.print();
	cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
