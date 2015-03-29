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
		
		if( str.compare("-a") == 0 )
		{
			this->a = true;
		}
		else if( str.compare("-e") == 0 )
		{
			this->e = true;
		}
		else if( str.compare("-p") == 0 )
		{
			this->p = true;
		}
		else if( str.compare("-o") == 0 )
		{
			this->o = true;
		}
	}
};

#endif //_OPTIONS_H

