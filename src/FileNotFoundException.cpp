#include "FileNotFoundException.hpp"

FileNotFoundException::FileNotFoundException() {
    message_ = defaultMessage;
}

FileNotFoundException::FileNotFoundException(std::string custom_message) {
    message_ = custom_message;
}

std::string FileNotFoundException::GetMessage() {
    return message_;
}