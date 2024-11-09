#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <unistd.h> 
 //获取系统信息
static void parse_board_serial(const char * file_name, const char * match_words, std::string & board_serial)
{
    board_serial.c_str();
 
    std::ifstream ifs(file_name, std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
 
    char line[4096] = { 0 };
    while (!ifs.eof())
    {
        ifs.getline(line, sizeof(line));
		break;
       
 
         
        
       
		 
       
    }
	board_serial=line;
 
    ifs.close();
}
 
static bool get_board_serial_by_system(std::string & board_serial, char *dir)
{
    board_serial.c_str();
 //
   
	const char*filename="dmidecode_result.txt";
	char * dmidecode_result;
		dmidecode_result =(char*) malloc(strlen(filename)+strlen(dir)+1);
      strcpy(dmidecode_result,dir) ;
	  strcat(dmidecode_result,filename) ;
	printf("dmidecode:%s",dmidecode_result);
	   
    char command[512] = { 0 };
    snprintf(command, sizeof(command), "dmidecode -s system-serial-number > %s", dmidecode_result);
	system(command);
  // printf("system%s\n",system(command));
     //if (0 == system(command))
     //{
        parse_board_serial(dmidecode_result, "Serial Number:", board_serial);
    //}
 
    unlink(dmidecode_result);
	free(dmidecode_result);
    return(!board_serial.empty());
}
 
static bool get_board_serial_number(std::string & board_serial,  char *dir)
{
	 // printf("getuid%d\n",getuid());
    if (0 == getuid())
    {
        if (get_board_serial_by_system(board_serial,dir))
        {
            return(true);
        }
    }
    return(false);
}
 const char *getboardserial(  char *dir ){
	  std::string board_serial="";
    get_board_serial_number(board_serial,dir);
	return board_serial.c_str();
 }
 /*
static void test()
{
    std::string board_serial;
	char dir[]="/home/lighthouse/";
    if (get_board_serial_number(board_serial,dir))
    {
        printf("new_board_serial: [%s]\n", board_serial.c_str());
    }
    else
    {
        printf("cann not get board id\n");
    }
}
 
int main ()
{
	test();
	return 0;
} */

