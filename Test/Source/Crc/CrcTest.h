/****************************************************************************************************
 * Pragma
 ****************************************************************************************************/

#pragma once

/****************************************************************************************************
 * Include
 ****************************************************************************************************/

#include <cstdint>
#include "Eclectic/Source/Crc/Crc.h"
#include "Eclectic/Source/Crc/CrcConfiguration.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>

/****************************************************************************************************
 * Class
 ****************************************************************************************************/

class Crc8Test : public testing::Test
{
    public:
        /*** Variable ***/
        const std::vector<Eclectic::Crc8Configuration::Algorithm> Algorithms =
        {
            Eclectic::Crc8Configuration::Algorithm::CRC_8,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_CDMA2000,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_DARC,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_DVB_S2,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_EBU,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_ITU,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_I_CODE,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_MAXIM,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_ROHC,
            Eclectic::Crc8Configuration::Algorithm::CRC_8_WCDMA
        };
        const std::vector<std::uint8_t> Data {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

class Crc16Test : public testing::Test
{
    public:
        /*** Variable ***/
        const std::vector<Eclectic::Crc16Configuration::Algorithm> Algorithms =
        {
            Eclectic::Crc16Configuration::Algorithm::CRC_16_ARC,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_AUG_CCITT,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_BUYPASS,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_CCITT_FALSE,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_CDMA2000,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_DDS_110,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_DECT_R,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_DECT_X,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_DNP,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_EN_13757,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_GENIBUS,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_KERMIT,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_MAXIM,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_MCRF4XX,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_MODBUS,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_RIELLO,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_T10_DIF,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_TELEDISK,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_TMS37157,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_USB,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_X_25,
            Eclectic::Crc16Configuration::Algorithm::CRC_16_XMODEM,
            Eclectic::Crc16Configuration::Algorithm::CRC_A
        };
        const std::vector<std::uint8_t> Data{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

class Crc32Test : public testing::Test
{
    public:
        /*** Variable ***/
        const std::vector<Eclectic::Crc32Configuration::Algorithm> Algorithms =
        {
            Eclectic::Crc32Configuration::Algorithm::CRC_32,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_BZIP2,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_JAMCRC,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_MPEG_2,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_POSIX,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_SATA,
            Eclectic::Crc32Configuration::Algorithm::CRC_32_XFER,
            Eclectic::Crc32Configuration::Algorithm::CRC_32C,
            Eclectic::Crc32Configuration::Algorithm::CRC_32D,
            Eclectic::Crc32Configuration::Algorithm::CRC_32Q
        };
        const std::vector<std::uint8_t> Data{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};
