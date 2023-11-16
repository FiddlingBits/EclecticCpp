/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include "Eclectic/Source/Crc/CrcConfiguration.h"

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace Eclectic
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** CRC8 Configuration ***/
    /* Constructor */
    Crc8Configuration::Crc8Configuration(const std::string Name, const std::uint8_t Check, const std::uint8_t Polynomial, const std::uint8_t Initial, const bool Reflect, const std::uint8_t XOrOut)
        : name {Name}, check {Check}, polynomial {Polynomial}, initial {Initial}, reflect {Reflect}, xOrOut {XOrOut}
    {
    }

    /* Method */
    Crc8Configuration Crc8Configuration::get(const Algorithm A)
    {
        switch(A)
        {
            case Algorithm::CRC_8: return Crc8Configuration("CRC-8", 0xF4, 0x07, 0x00, false, 0x00);
            case Algorithm::CRC_8_CDMA2000: return Crc8Configuration("CRC-8/CDMA2000", 0xDA, 0x9B, 0xFF, false, 0x00);
            case Algorithm::CRC_8_DARC: return Crc8Configuration("CRC-8/DARC", 0x15, 0x39, 0x00, true, 0x00);
            case Algorithm::CRC_8_DVB_S2: return Crc8Configuration("CRC-8/DVB-S2", 0xBC, 0xD5, 0x00, false, 0x00);
            case Algorithm::CRC_8_EBU: return Crc8Configuration("CRC-8/EBU", 0x97, 0x1D, 0xFF, true, 0x00);
            case Algorithm::CRC_8_I_CODE: return Crc8Configuration("CRC-8/I-CODE", 0x7E, 0x1D, 0xFD, false, 0x00);
            case Algorithm::CRC_8_ITU: return Crc8Configuration("CRC-8/ITU", 0xA1, 0x07, 0x00, false, 0x55);
            case Algorithm::CRC_8_MAXIM: return Crc8Configuration("CRC-8/MAXIM", 0xA1, 0x31, 0x00, true, 0x00);
            case Algorithm::CRC_8_ROHC: return Crc8Configuration("CRC-8/ROHC", 0xD0, 0x07, 0xFF, true, 0x00);
            case Algorithm::CRC_8_WCDMA: return Crc8Configuration("CRC-8/WCDMA", 0x25, 0x9B, 0x00, true, 0x00);
        }
    }

    std::string Crc8Configuration::toString() const
    {
        std::string string {std::format("Name: {}\n", name)};
        string += std::format("Check: 0x{:02X}\n", check);
        string += std::format("Polynomial: 0x{:02X}\n", polynomial);
        string += std::format("Initial: 0x{:02X}\n", initial);
        string += std::format("Reflect: {}\n", reflect ? "True" : "False");
        string += std::format("XOR Out: 0x{:02X}\n", xOrOut);
        return string;
    }

    /*** CRC16 Configuration ***/
    /* Constructor */
    Crc16Configuration::Crc16Configuration(const std::string Name, const std::uint16_t Check, const std::uint16_t Polynomial, const std::uint16_t Initial, const bool Reflect, const std::uint16_t XOrOut)
        : name {Name}, check {Check}, polynomial {Polynomial}, initial {Initial}, reflect {Reflect}, xOrOut {XOrOut}
    {
    }

    /* Method */
    Crc16Configuration Crc16Configuration::get(const Algorithm A)
    {
        switch(A)
        {
            case Algorithm::CRC_16_ARC: return Crc16Configuration("CRC-16/ARC", 0xBB3D, 0x8005, 0x0000, true, 0x0000);
            case Algorithm::CRC_16_AUG_CCITT: return Crc16Configuration("CRC-16/AUG-CCITT", 0xE5CC, 0x1021, 0x1D0F, false, 0x0000);
            case Algorithm::CRC_16_BUYPASS: return Crc16Configuration("CRC-16/BUYPASS", 0xFEE8, 0x8005, 0x0000, false, 0x0000);
            case Algorithm::CRC_16_CCITT_FALSE: return Crc16Configuration("CRC-16/CCITT-FALSE", 0x29B1, 0x1021, 0xFFFF, false, 0x0000);
            case Algorithm::CRC_16_CDMA2000: return Crc16Configuration("CRC-16/CDMA2000", 0x4C06, 0xC867, 0xFFFF, false, 0x0000);
            case Algorithm::CRC_16_DDS_110: return Crc16Configuration("CRC-16/DDS-110", 0x9ECF, 0x8005, 0x800D, false, 0x0000);
            case Algorithm::CRC_16_DECT_R: return Crc16Configuration("CRC-16/DECT-R", 0x007E, 0x0589, 0x0000, false, 0x0001);
            case Algorithm::CRC_16_DECT_X: return Crc16Configuration("CRC-16/DECT-X", 0x007F, 0x0589, 0x0000, false, 0x0000);
            case Algorithm::CRC_16_DNP: return Crc16Configuration("CRC-16/DNP", 0xEA82, 0x3D65, 0x0000, true, 0xFFFF);
            case Algorithm::CRC_16_EN_13757: return Crc16Configuration("CRC-16/EN-13757", 0xC2B7, 0x3D65, 0x0000, false, 0xFFFF);
            case Algorithm::CRC_16_GENIBUS: return Crc16Configuration("CRC-16/GENIBUS", 0xD64E, 0x1021, 0xFFFF, false, 0xFFFF);
            case Algorithm::CRC_16_KERMIT: return Crc16Configuration("CRC-16/KERMIT", 0x2189, 0x1021, 0x0000, true, 0x0000);
            case Algorithm::CRC_16_MAXIM: return Crc16Configuration("CRC-16/MAXIM", 0x44C2, 0x8005, 0x0000, true, 0xFFFF);
            case Algorithm::CRC_16_MCRF4XX: return Crc16Configuration("CRC-16/MCRF4XX", 0x6F91, 0x1021, 0xFFFF, true, 0x0000);
            case Algorithm::CRC_16_MODBUS: return Crc16Configuration("CRC-16/MODBUS", 0x4B37, 0x8005, 0xFFFF, true, 0x0000);
            case Algorithm::CRC_16_RIELLO: return Crc16Configuration("CRC-16/RIELLO", 0x63D0, 0x1021, 0xB2AA, true, 0x0000);
            case Algorithm::CRC_16_T10_DIF: return Crc16Configuration("CRC-16/T10-DIF", 0xD0DB, 0x8BB7, 0x0000, false, 0x0000);
            case Algorithm::CRC_16_TELEDISK: return Crc16Configuration("CRC-16/TELEDISK", 0x0FB3, 0xA097, 0x0000, false, 0x0000);
            case Algorithm::CRC_16_TMS37157: return Crc16Configuration("CRC-16/TMS37157", 0x26B1, 0x1021, 0x89EC, true, 0x0000);
            case Algorithm::CRC_16_USB: return Crc16Configuration("CRC-16/USB", 0xB4C8, 0x8005, 0xFFFF, true, 0xFFFF);
            case Algorithm::CRC_16_X_25: return Crc16Configuration("CRC-16/X-25", 0x906E, 0x1021, 0xFFFF, true, 0xFFFF);
            case Algorithm::CRC_16_XMODEM: return Crc16Configuration("CRC-16/XMODEM", 0x31C3, 0x1021, 0x0000, false, 0x0000);
            case Algorithm::CRC_A: return Crc16Configuration("CRC-A", 0xBF05, 0x1021, 0xC6C6, true, 0x0000);
        }
    }

    std::string Crc16Configuration::toString() const
    {
        std::string string{std::format("Name: {}\n", name)};
        string += std::format("Check: 0x{:04X}\n", check);
        string += std::format("Polynomial: 0x{:04X}\n", polynomial);
        string += std::format("Initial: 0x{:04X}\n", initial);
        string += std::format("Reflect: {}\n", reflect ? "True" : "False");
        string += std::format("XOR Out: 0x{:04X}\n", xOrOut);
        return string;
    }

    /*** CRC32 Configuration ***/
    /* Constructor */
    Crc32Configuration::Crc32Configuration(const std::string Name, const std::uint32_t Check, const std::uint32_t Polynomial, const std::uint32_t Initial, const bool Reflect, const std::uint32_t XOrOut)
        : name {Name}, check {Check}, polynomial {Polynomial}, initial {Initial}, reflect {Reflect}, xOrOut {XOrOut}
    {
    }

    /* Method */
    Crc32Configuration Crc32Configuration::get(const Algorithm A)
    {
        switch(A)
        {
            case Algorithm::CRC_32: return Crc32Configuration("CRC-32", 0xCBF43926, 0x04C11DB7, 0xFFFFFFFF, true, 0xFFFFFFFF);
            case Algorithm::CRC_32_BZIP2: return Crc32Configuration("CRC-32/BZIP2", 0xFC891918, 0x04C11DB7, 0xFFFFFFFF, false, 0xFFFFFFFF);
            case Algorithm::CRC_32_JAMCRC: return Crc32Configuration("CRC-32/JAMCRC", 0x340BC6D9, 0x04C11DB7, 0xFFFFFFFF, true, 0x00000000);
            case Algorithm::CRC_32_MPEG_2: return Crc32Configuration("CRC-32/MPEG-2", 0x0376E6E7, 0x04C11DB7, 0xFFFFFFFF, false, 0x00000000);
            case Algorithm::CRC_32_POSIX: return Crc32Configuration("CRC-32/POSIX", 0x765E7680, 0x04C11DB7, 0x00000000, false, 0xFFFFFFFF);
            case Algorithm::CRC_32_SATA: return Crc32Configuration("CRC-32/SATA", 0xCF72AFE8, 0x04C11DB7, 0x52325032, false, 0x00000000);
            case Algorithm::CRC_32_XFER: return Crc32Configuration("CRC-32/XFER", 0xBD0BE338, 0x000000AF, 0x00000000, false, 0x00000000);
            case Algorithm::CRC_32C: return Crc32Configuration("CRC-32C", 0xE3069283, 0x1EDC6F41, 0xFFFFFFFF, true, 0xFFFFFFFF);
            case Algorithm::CRC_32D: return Crc32Configuration("CRC-32D", 0x87315576, 0xA833982B, 0xFFFFFFFF, true, 0xFFFFFFFF);
            case Algorithm::CRC_32Q: return Crc32Configuration("CRC-32Q", 0x3010BF7F, 0x814141AB, 0x00000000, false, 0x00000000);
        }
    }

    std::string Crc32Configuration::toString() const
    {
        std::string string{std::format("Name: {}\n", name)};
        string += std::format("Check: 0x{:08X}\n", check);
        string += std::format("Polynomial: 0x{:08X}\n", polynomial);
        string += std::format("Initial: 0x{:08X}\n", initial);
        string += std::format("Reflect: {}\n", reflect ? "True" : "False");
        string += std::format("XOR Out: 0x{:08X}\n", xOrOut);
        return string;
    }
}
