#include "Equal.h"

bool is_equal(double x, double y) 
{
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();    
}
