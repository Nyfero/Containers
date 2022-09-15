#ifndef TESTER_HPP
# define TESTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <list>
# include <csignal>

class Tester
{
	private:
		std::string	_funcName;
		std::string	_nameTest;
		int			(*_function)(void);
		
	public:
		//	Constructors
		Tester(std::string func, std::string name, int (*function)(void));
		Tester(Tester const& src);
		Tester & operator=(Tester const& src);
		~Tester();
		
		//	Throw
		class	InvalidTestException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class	MissingTestException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class	ChildAbortException: public std::exception
		{
			public:
				virtual const char* what() const throw();
	 	};
		
		//	Functions
		std::string	GetFuncName() const;
		std::string GetNameTest() const;
		int			RunTest(std::vector<Tester> & src);
		void		ExecTest();
};

//	Display
std::ostream & operator << (std::ostream &out, const Tester &src);
std::string	Display_error(int status);
std::string	Display(int status);
#endif
