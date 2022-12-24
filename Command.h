#ifdef COMMAND_H
#define COMMAND_H

using file_t = int;// change to file
using initialCommand_t = int; // get_line from file
using command_t = int; // change to command

class CCommandHistory
{
public:
	virtual command_t GetCommandHistory() = 0;

private:
	command_t m_command;
};

class CommandHandler
{
	//Fetch()
	//Decode
	//Execute
};

#endif // COMMAND_H

