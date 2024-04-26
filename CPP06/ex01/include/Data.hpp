#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private:

	public:
		Data(void);
		Data(Data const & src);
		~Data(void);

		Data &operator=(Data const & src);

		int	nb;
};

#endif