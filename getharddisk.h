#include <string>
static bool get_disk_name(std::string & disk_name);
static void trim_serial(const void * serial, size_t serial_len, std::string & serial_no);
static bool get_disk_serial_by_way_1(const std::string & disk_name, std::string & serial_no);
static bool scsi_io(
                int fd, unsigned char * cdb,
                unsigned char cdb_size, int xfer_dir,
                unsigned char * data, unsigned int data_size,
                unsigned char * sense, unsigned int sense_len
            );
static bool get_disk_serial_by_way_2(const std::string & disk_name, std::string & serial_no);
static bool parse_serial(const char * line, int line_size, const char * match_words, std::string & serial_no);
static void get_serial(const char * file_name, const char * match_words, std::string & serial_no);
static bool get_disk_serial_by_way_3(const std::string & disk_name, std::string & serial_no);
static bool get_disk_serial_by_way_4(std::string & serial_no);
static bool get_disk_serial_number(std::string & serial_no);

const char* get_harddisk();
