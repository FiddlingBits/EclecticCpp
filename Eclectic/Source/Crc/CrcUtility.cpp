/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Eclectic/Source/Crc/CrcUtility.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace Eclectic
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    std::uint8_t CrcUtility::reflect(const std::uint8_t Data)
    {
        std::uint8_t reflectedData {0x00};
        for(int bit = 0; bit < 8; bit++)
            reflectedData |= ((Data & (1 << bit)) >> bit) << (7 - bit);
        return reflectedData;
    }

    std::uint16_t CrcUtility::reflect(const std::uint16_t Data)
    {
        std::uint16_t reflectedData {0x0000};
        for(int bit = 0; bit < 16; bit++)
            reflectedData |= ((Data & (1 << bit)) >> bit) << (15 - bit);
        return reflectedData;
    }

    std::uint32_t CrcUtility::reflect(const std::uint32_t Data)
    {
        std::uint32_t reflectedData {0x00000000};
        for(int bit = 0; bit < 32; bit++)
            reflectedData |= ((Data & (1 << bit)) >> bit) << (31 - bit);
        return reflectedData;
    }
}
