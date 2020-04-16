// An interface for command
#include <iostream>
#include <string>
#//define main_function_H
class document
{
	virtual void update() = 0;
};

class cView :public document
{

};
class glView :public document
{

};
#ifdef main_function_H
int main()
{
	return 0;
}
#endif // main_function_H