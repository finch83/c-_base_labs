#include "../include/lecture_02.hpp"

int main()
{
    int iTask{};
    amelnyk::lecture02::Tasks eTask = amelnyk::lecture02::Tasks::LAST_TASK;
	bool isValid = true;

	while (isValid) {
        amelnyk::input::inputVal<int>(amelnyk::lecture02::strUsageMain, iTask);
        eTask = static_cast<amelnyk::lecture02::Tasks>(iTask);
		switch (eTask){
        case amelnyk::lecture02::Tasks::EXIT_TASK:
			isValid = false;
            std::cout << "Good luck\n";\
            break;
        case amelnyk::lecture02::Tasks::EQUALS:
            amelnyk::lecture02::wrapEquals();
            break;
        case amelnyk::lecture02::Tasks::SETBIT:
            amelnyk::lecture02::wrapSetBit();
            break;
        case amelnyk::lecture02::Tasks::REVERTBIT:
            amelnyk::lecture02::wrapRevertBit();
            break;
        case amelnyk::lecture02::Tasks::ADDVECTOR:
            amelnyk::lecture02::wrapAddVector();
            break;
        case amelnyk::lecture02::Tasks::LAST_TASK:
		default:
			std::cout << "Wrong input" << std::endl;
            amelnyk::input::usage(amelnyk::lecture02::strUsageMain);
			break;
		}
	}

return 0;
}
