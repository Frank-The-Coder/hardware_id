#include <string>
 static bool get_cpu_id(std::string & cpu_id);
 static bool get_cpu_id_by_system(std::string & cpu_id);
  static void parse_cpu_id(const char * file_name, const char * match_words, std::string & cpu_id);
  static bool get_cpu_id_by_asm(std::string & cpu_id);
const char * getcpu();