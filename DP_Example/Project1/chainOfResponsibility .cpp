// Example program
#include <iostream>
#include <string>
//#define main_function_H
class AbstractLogger
{
public:
	static int INFO;
	static int DEBUG;
	static int ERROR;
protected:
	int level;
	//next element in chain or responsibility
	AbstractLogger *nextLogger;

public:
	void setNextLogger(AbstractLogger *nextLogger) {
		this->nextLogger = nextLogger;
	}

	void logMessage(int level, std::string message) {
		if (this->level <= level) 
		{
			write(message);
		}
		if (nextLogger != NULL)
		{
			nextLogger->logMessage(level, message);
		}
	}
protected:
	virtual  void write(std::string message) = 0;
	/*{
		std::cout << "base class " << message << "\n";;
	}*/
};
int AbstractLogger::INFO  = 1;
int AbstractLogger::DEBUG = 2;
int AbstractLogger::ERROR = 3;
class ConsoleLogger :public AbstractLogger
{
public:
	ConsoleLogger(int level)
	{
		this->level = level;
	}
	void write(std::string message) {
		std::cout << " Standered Console::Logger: " << message << "\n" << "\n";
	}
};
class ErrorLogger :public AbstractLogger
{
public:
	ErrorLogger(int level)
	{
		this->level = level;
	}
	void write(std::string message) {
		std::cout << "ErrorLogger::Logger: " << message << "\n"<< "\n";
	}
};
class FileLogger :public AbstractLogger
{
public:
	FileLogger(int level)
	{
		this->level = level;
	}
	void write(std::string message) {
		std::cout << " FileLogger::Logger: " << message << "\n" << "\n";
	}
};
class ChainPatternDemo
{
public:
	ChainPatternDemo()
	{}
	 AbstractLogger *getChainOfLoggers()
	{

		AbstractLogger *errorLogger = new ErrorLogger(AbstractLogger::ERROR);
		AbstractLogger *fileLogger = new FileLogger(AbstractLogger::DEBUG);
		AbstractLogger *consoleLogger = new ConsoleLogger(AbstractLogger::INFO);

		errorLogger->setNextLogger(fileLogger);
		fileLogger->setNextLogger(consoleLogger);

		return errorLogger;
	}
};
#ifdef main_function_H
int main()
{
	ChainPatternDemo c1;
	AbstractLogger *loggerChain = c1.getChainOfLoggers();

	loggerChain->logMessage(AbstractLogger::INFO,
		"This is an information.");

	loggerChain->logMessage(AbstractLogger::DEBUG,
		"This is an debug level information.");

	loggerChain->logMessage(AbstractLogger::ERROR,
		"This is an error information.");
	std::string name;
	std::cout << "What is your name? ";
	getline(std::cin, name);
	std::cout << "Hello, " << name << "!\n";
}
#endif // main_function_H