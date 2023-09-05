
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain( std::string const & level ) const;
		void	complain( std::string const & level, int n ) const;

	private:
		void	_debug( void ) const;
		void	_info( void ) const;
		void	_warning( void ) const;
		void	_error( void ) const;

};

#endif