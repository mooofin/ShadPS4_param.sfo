#ifndef SFOPARSER_HPP
#define SFOPARSER_HPP

#include <string>
#include <fstream>
#include <vector>
#include <cstdint>

struct SFOHeader {
    char magic[4];         // Should be "\0PSF"
    uint32_t version;
    uint32_t keyTableStart;
    uint32_t dataTableStart;
    uint32_t entriesCount;
};

class SFOParser {
public:
    SFOParser(const std::string& filename);
    bool parse();

private:
    std::string filename;
    SFOHeader header;

    bool readHeader(std::ifstream& file);
    void printHeader() const;
};

#endif // SFOPARSER_HPP
