#include <string>
static bool get_mac_address(std::string & mac_address);
static bool get_mac_address_by_system(std::string & mac_address);
static void parse_mac_address(const char * file_name, const char * match_words, std::string & mac_address);
bool get_mac_address_by_ioctl(std::string & mac_address);
const char * getmac();