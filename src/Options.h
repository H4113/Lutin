/**
 * Project Lutin
 */

#ifndef _OPTIONS_H
#define _OPTIONS_H

struct Options
{
	bool a,o,p,e;
	
	Options():a(false),o(false),p(false),e(false){}

	void AddOption( const char* o )
	{
		std::string str(o);
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		
		if( str.compare("-a") )
		{
			this->a = true;
		} else if( str.compare("-e") )
		{
			this->e = true;
		} else if( str.compare("-p") )
		{
			this->p = true;
		} else if( str.compare("-o") )
		{
			this->o = true;
		}
	}
};

#endif //_OPTIONS_H

