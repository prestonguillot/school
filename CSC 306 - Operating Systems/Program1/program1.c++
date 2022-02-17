#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {

	int InputFile,InputFileSize,OutputFile,SpaceCount = 0,CRCount = 0;
	char InputFileArray[2000],SpaceCountArray[2],CRCountArray[2];
	char SpaceOutputString[] = "\nNumber of Spaces: ", CROutputString[] = "\nNumber of Lines: ";
	
    InputFile = open("program1.c++",O_RDONLY);
	OutputFile = open("output",O_RDWR|O_CREAT);
	InputFileSize = read(InputFile,InputFileArray,2000);
	
	for(int x = 0; x < InputFileSize; x++) {
		
		if(InputFileArray[x] == ' ')
			SpaceCount++;
		else if(InputFileArray[x] == '\n')
			CRCount++;
	}
	
	SpaceCountArray[0] = char((SpaceCount / 10) + '0');
	SpaceCountArray[1] = char((SpaceCount % 10) + '0');
	CRCountArray[0] = char((CRCount / 10) + '0');
	CRCountArray[1] = char((CRCount % 10) + '0');

	write(OutputFile,InputFileArray,InputFileSize);
	write(OutputFile,SpaceOutputString,19);
	write(OutputFile,SpaceCountArray,2);
	write(OutputFile,CROutputString,18);
	write(OutputFile,CRCountArray,2);

	return 0;

}
