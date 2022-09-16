#ifndef TESTER_HPP
# define TESTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <csignal>
# include <sys/time.h>
# include <sys/wait.h>

namespace MyContainerTester {
	
	class Tester
	{
		private:
			std::string	_funcName;
			std::string	_nameTest;
			int			(*_funcPtr)(void);
		
		public:
			//	Constructors
			Tester(std::string funcName, std::string name, int (*funcPtr)(void));
			Tester(Tester const& src);
			Tester & operator=(Tester const& src);
			~Tester();
		
			//	Throw
			class InvalidTestException: public std::exception
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
	int		Display_error(int status);
	int		Display(int status);
}

#endif
