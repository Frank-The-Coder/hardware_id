#include<string.h>
static void parse_board_serial(const char * file_name, const char * match_words, std::string & board_serial);
static bool get_board_serial_by_system(std::string & board_serial,  char *dir);
static bool get_board_serial_number(std::string & board_serial,  char *dir);
const char *getboardserial(  char *dir);
