#include "amper.h"

double amper::get_value() const
{
   getCount () ++;
   return m_value;
}

int amper::totalCount () const
{
	return getCount ();
}
