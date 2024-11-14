#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed();
		Fixed& operator=(const Fixed& C);
		int		getRawBits( void ) const;
		int		getBit( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

	private:
		int value;
		static const int bit = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif