#include "SFOParser.hpp"
#include <iostream>
#include <cstring>

SFOParser::SFOParser(const std::string& filename) : filename(filename) {}

bool SFOParser::parse() {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return false;
    }

    if (!readHeader(file)) {
        std::cerr << "Invalid header.\n";
        return false;
    }

    printHeader();
    return true;
}

bool SFOParser::readHeader(std::ifstream& file) {
    file.read(reinterpret_cast<char*>(&header), sizeof(SFOHeader));
    
    if (std::strncmp(header.magic, "\0PSF", 4) != 0) {
        return false;
    }

    return true;
}

void SFOParser::printHeader() const {
    std::cout << "Magic: " << std::string(header.magic, 4) << "\n";
    std::cout << "Version: " << std::hex << header.version << "\n";
    std::cout << "Key Table Offset: " << header.keyTableStart << "\n";
    std::cout << "Data Table Offset: " << header.dataTableStart << "\n";
    std::cout << "Entries Count: " << header.entriesCount << "\n";
}
