#include "../class/Tester.hpp"

//					//
//	Constructors	//
//					//

Tester::Tester(std::string func, std::string name, int (*function)(void)):
_funcName(func), _nameTest(name), _function(function)
{
	if (!(_funcName && _nameTest && (*(_function))))
		throw InvalidTestException();
}

Tester::Tester(Tester const& src):
_funcName(src._funcName), _nameTest(src._nameTest), _function(src._function)
{
	if (!(_funcName && _nameTest && (*(_function))))
		throw InvalidTestException();
}

Tester & Tester::operator=(Tester const& src) {
	this->_funcName = src._funcName;
	this->_nameTest = src._nameTest;
	this->_function = src._function;
	if (!(_funcName && _nameTest && (*(_function))))
		throw InvalidTestException();
	return (*this);
}

Tester::~Tester() {}

//			//
//	Throw	//
//			//

const char* Tester::InvalidTestException::what() const throw() {
	return ("\e[91mError: Unable to create this test\e[39m\n");
}

const char* Tester::MissingTestException::what() const throw() {
	return ("\e[91mError: No test provided\e[39m\n");
}

const char* Tester::ChildAbortException::what() const throw() {
	return ("\e[91mError: PID = -1\e[39m\n");
}

//				//
//	Functions	//
//				//

std::string	Tester::GetFuncName() const {
	return (this->_funcName);
}

std::string Tester::GetNameTest() const {
	return (this->_nameTest);
}

int	Tester::RunTest(std::vector<Tester> & test) {
	int	pid = 0;
	int	status = 0;
	int	i = 0;
	int	res = 0;
	
	if (!test)
		throw MissingTestException();
	while (i < test.size())
	{
		pid = fork();
		if (pid == -1)
			throw ChildAbortException();
		if (pid == 1)
			test.at(i).ExecTest();
		else
		{
			wait(&status);
			if (WIFSIGNALED(status))
				res = Display_error(status); 
			else
				res = Display(status);
		}
		i++;
	}
	
}

void		Tester::ExecTest() {
	int	res;
	
	res = this->_function;
	if (res)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

//			//
//	Display	//
//			//

std::ostream & operator << (std::ostream &out, const Tester &src) {
	return (out << "Test: " << src.GetNameTest() << " from: " << src.GetFuncName());
}

std::string	Display_error(int status) {
	int	signal;

	signal = WTERMSIG(status);
	if (signal == 11)
		std::cout << "\e[91m[SIGSEGV]\e[39m" << std::endl;
	else if (signal == 7)
		std::cout << "\e[91m[SIGBUS]\e[39m" << std::endl;
	return (-1);
}

std::string	Display(int status) {
	if (!status)
		std::cout << "\e[92m[OK]\e[39m" << std::endl;
	else
		std::cout << "\e[91m[KO]\e[39m" << std::endl;
	if (status)
		return (-1);
	return (0);
}
