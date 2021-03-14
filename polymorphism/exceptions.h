
class typeException : std::exception { public: const char*  message = "problem with type conversion"; } ;

class zeroDivisionException : std::exception { public: const char*  message = "zero division problem.."; } ;