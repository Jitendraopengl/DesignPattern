#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
//define main_function_H
class Singleton
{
public:
	static Singleton& getInstance();
private:
	Singleton() { std::cout << "Ctor\n"; };
	~Singleton() { std::cout << "Dtor\n"; };
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
};

Singleton& Singleton::getInstance()
{
	//Mutex mutex;
	//ScopedLock(&mutex;);  // to unlock mutex on exit
	static Singleton instance;
	return instance;
}

#ifdef main_function_H
int main()
{
	
	singlelton *s1 = singlelton::getInstance();
	singlelton *s2 = singlelton::getInstance();

	getchar();
	return 0;
}
#endif // main_function_H
