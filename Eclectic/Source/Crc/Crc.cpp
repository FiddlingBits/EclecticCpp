/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Eclectic/Source/Crc/Crc.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace Eclectic
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** CRC8 ***/
    /* Constructor */
    Crc8::Crc8(const Crc8Configuration& Configuration)
        : Configuration {Configuration}
    {
    }

    /* Method */
    std::uint8_t Crc8::calculate(const std::vector<std::uint8_t> Data) const
    {
        std::uint8_t crc {Configuration.initial};
        for(int i = 0; i < Data.size(); i++)
            crc = calculate(Data[i], crc, i == (Data.size() - 1));
        return crc;
    }

    std::uint8_t Crc8::calculate(const std::uint8_t Data, std::uint8_t crc, const bool Last) const
    {
        if(lookupTable.size() == 256)
        {
            crc = lookupTable[crc ^ Data];
            if(Last)
                crc ^= Configuration.xOrOut;
        }
        else
        {
            if(Configuration.reflect)
                crc ^= CrcUtility::reflect(Data);
            else
                crc ^= Data;
            for(int bit = 0; bit < 8; bit++)
            {
                if((crc & 0x80) == 0x80)
                    crc = (crc << 1) ^ Configuration.polynomial;
                else
                    crc <<= 1;
            }
            if(Last)
            {
                crc ^= Configuration.xOrOut;
                if(Configuration.reflect)
                    crc = CrcUtility::reflect(crc);
            }
        }
        return crc;
    }

    void Crc8::generateLookupTable()
    {
        for(int i = 0; i < 256; i++)
        {
            std::uint8_t value {static_cast<std::uint8_t>(i)};
            lookupTable.push_back(calculate(value, 0x00, true) ^ Configuration.xOrOut);
        }
    }

    std::string Crc8::toString() const
    {
        std::string string {Configuration.toString()};
        if(lookupTable.size() == 256)
        {
            string += "Lookup Table:\n";
            for(int i = 0; i < 256; i++)
            {
                if((i % 16) == 0)
                    string += "  ";
                string += std::format("0x{:02X}, ", lookupTable[i]);
                if(((i + 1) % 16) == 0)
                    string.replace(string.size() - 2, 2, ",\n"); // Replace Final ", " With ",\n"
            }
            string.replace(string.size() - 2, 2, "\n"); // Replace Final ",\n" With "\n"
        }
        return string;
    }

    /*** CRC16 ***/
    /* Constructor */
    Crc16::Crc16(const Crc16Configuration& Configuration)
        : Configuration {Configuration}
    {
    }

    /* Method */
    std::uint16_t Crc16::calculate(const std::vector<std::uint8_t> Data) const
    {
        std::uint16_t crc {Configuration.initial};
        for(int i = 0; i < Data.size(); i++)
            crc = calculate(Data[i], crc, i == 0, i == (Data.size() - 1));
        return crc;
    }

    std::uint16_t Crc16::calculate(const std::uint8_t Data, std::uint16_t crc, const bool First, const bool Last) const
    {
        if(lookupTable.size() == 256)
        {
            if(Configuration.reflect)
            {
                if(First)
                    crc = CrcUtility::reflect(crc);
                crc = (crc >> 8) ^ lookupTable[(crc ^ Data) % 256];
            }
            else
            {
                crc = (crc << 8) ^ lookupTable[(crc >> 8) ^ Data];
            }
            if(Last)
                crc ^= Configuration.xOrOut;
        }
        else
        {
            if(Configuration.reflect)
                crc ^= (CrcUtility::reflect(Data) << 8);
            else
                crc ^= (Data << 8);
            for(int bit = 0; bit < 8; bit++)
            {
                if((crc & 0x8000) == 0x8000)
                    crc = (crc << 1) ^ Configuration.polynomial;
                else
                    crc <<= 1;
            }
            if(Last)
            {
                crc ^= Configuration.xOrOut;
                if(Configuration.reflect)
                    crc = CrcUtility::reflect(crc);
            }
        }
        return crc;
    }

    void Crc16::generateLookupTable()
    {
        for(int i = 0; i < 256; i++)
        {
            std::uint8_t value {static_cast<std::uint8_t>(i)};
            lookupTable.push_back(calculate(value, 0x0000, true, true) ^ Configuration.xOrOut);
        }
    }

    std::string Crc16::toString() const
    {
        std::string string {Configuration.toString()};
        if(lookupTable.size() == 256)
        {
            string += "Lookup Table:\n";
            for(int i = 0; i < 256; i++)
            {
                if((i % 16) == 0)
                    string += "  ";
                string += std::format("0x{:04X}, ", lookupTable[i]);
                if(((i + 1) % 16) == 0)
                    string.replace(string.size() - 2, 2, ",\n"); // Replace Final ", " With ",\n"
            }
            string.replace(string.size() - 2, 2, "\n"); // Replace Final ",\n" With "\n"
        }
        return string;
    }

    /*** CRC32 ***/
    /* Constructor */
    Crc32::Crc32(const Crc32Configuration& Configuration)
        : Configuration {Configuration}
    {
    }

    /* Method */
    std::uint32_t Crc32::calculate(const std::vector<std::uint8_t> Data) const
    {
        std::uint32_t crc {Configuration.initial};
        for(int i = 0; i < Data.size(); i++)
            crc = calculate(Data[i], crc, i == 0, i == (Data.size() - 1));
        return crc;
    }

    std::uint32_t Crc32::calculate(const std::uint8_t Data, std::uint32_t crc, const bool First, const bool Last) const
    {
        if(lookupTable.size() == 256)
        {
            if(Configuration.reflect)
            {
                if(First)
                    crc = CrcUtility::reflect(crc);
                crc = (crc >> 8) ^ lookupTable[(crc ^ Data) % 256];
            }
            else
            {
                crc = (crc << 8) ^ lookupTable[(crc >> 24) ^ Data];
            }
            if(Last)
                crc ^= Configuration.xOrOut;
        }
        else
        {
            if(Configuration.reflect)
                crc ^= (CrcUtility::reflect(Data) << 24);
            else
                crc ^= (Data << 24);
            for(int bit = 0; bit < 8; bit++)
            {
                if((crc & 0x80000000) == 0x80000000)
                    crc = (crc << 1) ^ Configuration.polynomial;
                else
                    crc <<= 1;
            }
            if(Last)
            {
                crc ^= Configuration.xOrOut;
                if(Configuration.reflect)
                    crc = CrcUtility::reflect(crc);
            }
        }
        return crc;
    }

    void Crc32::generateLookupTable()
    {
        for(int i = 0; i < 256; i++)
        {
            std::uint8_t value {static_cast<std::uint8_t>(i)};
            lookupTable.push_back(calculate(value, 0x00000000, true, true) ^ Configuration.xOrOut);
        }
    }

    std::string Crc32::toString() const
    {
        std::string string {Configuration.toString()};
        if(lookupTable.size() == 256)
        {
            string += "Lookup Table:\n";
            for(int i = 0; i < 256; i++)
            {
                if((i % 16) == 0)
                    string += "  ";
                string += std::format("0x{:08X}, ", lookupTable[i]);
                if(((i + 1) % 16) == 0)
                    string.replace(string.size() - 2, 2, ",\n"); // Replace Final ", " With ",\n"
            }
            string.replace(string.size() - 2, 2, "\n"); // Replace Final ",\n" With "\n"
        }
        return string;
    }
}
