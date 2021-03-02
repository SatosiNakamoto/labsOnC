#ifndef _AMPER_
#define _AMPER_

class amper
{

public:
	amper(double value) : m_value(value) { }

	double get_value() const;
    
	int totalCount () const;
	
private:
	double m_value;

	static int & getCount ()
	{
		static int theCount = 0;
   		return theCount;
	}
	
};

#endif
