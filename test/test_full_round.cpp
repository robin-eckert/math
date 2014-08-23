#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/math/special_functions/round.hpp>

#include <limits>

template<typename T>
void full_value_space_scan(const char *name)
{
   std::cout << "Testing rounding with type " << name << " against std::round" << std::endl;

   for(T x = std::numeric_limits<T>::lowest();
       x < std::numeric_limits<T>::max();
       x = std::nextafter(x, std::numeric_limits<T>::max()))
   {
      BOOST_CHECK_EQUAL(std::round(x), boost::math::round(x));
   }
}

BOOST_AUTO_TEST_CASE(test_float)
{
   full_value_space_scan<float>("float");
}
