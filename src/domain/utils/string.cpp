/*
 * string.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: twiik
 */

#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



