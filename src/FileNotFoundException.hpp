#ifndef FILE_NOT_FOUND_EXCEPTION_HPP
#define FILE_NOT_FOUND_EXCEPTION_HPP

#include <string>

class FileNotFoundException {
    public:
        FileNotFoundException();
        FileNotFoundException(std::string custom_message);
        std::string GetMessage();

    private:
        std::string defaultMessage = "The file cannot be found";
        std::string message_;
};

#endif