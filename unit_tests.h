#include "container.h"
#include <cassert>

class unit_tests{
	public:
		void run_tests();
	private:
		void test_size_after_add();
		void test_link_in_container();
		void test_read_write();
		void test_sort();
		void test_filter();
		void test_calculated_volume();
};
