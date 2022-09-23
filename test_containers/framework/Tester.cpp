#include "../class/Tester.hpp"

namespace MyContainerTester {
	

//					//
//	Constructors	//
//					//

Tester::Tester(std::string func, std::string name, int (*funcPtr)(void)):
_funcName(func), _nameTest(name), _funcPtr(funcPtr) {
	if (_funcName.empty() || _nameTest.empty() || (*_funcPtr) == NULL)
		throw InvalidTestException();
}

Tester::Tester(Tester const& src):
_funcName(src._funcName), _nameTest(src._nameTest), _funcPtr(src._funcPtr)
{
	if (_funcName.empty() || _nameTest.empty() || (*_funcPtr) == NULL)
		throw InvalidTestException();
}

Tester & Tester::operator=(Tester const& src) {
	this->_funcName = src._funcName;
	this->_nameTest = src._nameTest;
	this->_funcPtr = src._funcPtr;
	if (_funcName.empty() || _nameTest.empty() || (*_funcPtr) == NULL)
		throw InvalidTestException();
	return (*this);
}

Tester::~Tester() {}

//			//
//	Throw	//
//			//

const char* Tester::InvalidTestException::what() const throw() {
	return ("\e[91mError: Unable to create this test\e[39m");
}

const char* Tester::MissingTestException::what() const throw() {
	return ("\e[91mError: No test provided\e[39m");
}

const char* Tester::ChildAbortException::what() const throw() {
	return ("\e[91mError: PID = -1\e[39m");
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
	std::vector<int>::size_type i = 0;
	int	res = 0;

	if (test.empty())
		throw MissingTestException();
	while (i < test.size())
	{
		pid = fork();
		if (pid == -1)
			throw ChildAbortException();
		if (pid != 0)
			test.at(i).ExecTest();
		else
		{
			pid = wait(&status);
			if (WIFSIGNALED(status))
				res = Display_error(status); 
			else
				res = Display(status);
		}
		i++;
	}
	return (res);
}

void		Tester::ExecTest() {
	int	res;

	res = this->_funcPtr();
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

int		Display_error(int status) {
	int	signal;

	signal = WTERMSIG(status);
	if (signal == 11)
		std::cout << "\e[91m[SIGSEGV]\e[39m" << std::endl;
	else if (signal == 7)
		std::cout << "\e[91m[SIGBUS]\e[39m" << std::endl;
	return (-1);
}

int		Display(int status) {
	if (!status)
	{
		std::cout << "\e[92m[OK]\e[39m" << std::endl;
		return (0);
	}
	std::cout << "\e[91m[KO]\e[39m" << std::endl;
	return (-1);
}

}