#include "SFOParser.hpp"

int main() {
    SFOParser parser("sample.sfo");
    if (!parser.parse()) {
        return 1;
    }

    return 0;
}
