#include <iostream>
#include <cstdarg>

class MainWindow
{
public:
	void addFormattedMessage(const char* format, ...)
	{
		char str[512];

		va_list args;
		va_start(args, format);

		vsnprintf(str, sizeof(str), format, args);
		std::cout << new std::string(str) << std::endl;

		va_end(args);
	}

	void addMessage(std::string message)
	{
		std::cout << message << std::endl;
	}
};

extern MainWindow* mainWindow = new MainWindow();
