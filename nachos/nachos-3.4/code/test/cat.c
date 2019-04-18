#include "syscall.h"
#define maxlen 32

int main()
{
	int Id, size, i;
	char c;
	char filename[maxlen];
	PrintString("\n------Show content of the file--------\n");
	
	PrintString("\n Enter of file name: ");
	ReadString(filename, maxlen);
	Id = Open(filename, 1); // Only Read
	if(Id != -1) // check isOpen
	{
		size = Seek(-1, Id); // Seek the end of file (size of file)
		Seek(0, Id); // Seek the begin of file
		for(; i < size; i++)
		{
		Read(&c, 1, Id);
		PrintChar(c);
		}
	Close(Id);
	}
	else
	PrintString("\n File not exist.");

	return 0;
}
