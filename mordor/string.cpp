// Copyright (c) 2009 - Decho Corp.

#include "mordor/pch.h"

#include <algorithm>

#include <string.h>

#include <openssl/md5.h>
#include <openssl/sha.h>

#include "mordor/string.h"

#include "assert.h"
#include "exception.h"

#ifdef MSVC
#pragma comment(lib, "libeay32")
#endif

namespace Mordor {

std::string
base64decode(const std::string &src)
{
    std::string result;
    result.resize(src.size() * 3 / 4);
    char *writeBuf = &result[0];

    const char* ptr = src.c_str();
    const char* end = ptr + src.size();

    while(ptr < end) {
        int i = 0;
        int padding = 0;
        int packed = 0;
        for(; i < 4 && ptr < end; ++i, ++ptr) {
            if(*ptr == '=') {
                ++padding;
                packed <<= 6;
                continue;
            }

            int val = 0;
            if(*ptr >= 'A' && *ptr <= 'Z')
                val = *ptr - 'A';
            else if(*ptr >= 'a' && *ptr <= 'z')
                val = *ptr - 'a' + 26;
            else if(*ptr >= '0' && *ptr <= '9')
                val = *ptr - '0' + 52;
            else if(*ptr == '+')
                val = 62;
            else if(*ptr == '/')
                val = 63;
            else
                return "";

            packed = (packed << 6) | val;
        }
        if (i != 4)
            MORDOR_ASSERT(false);
        if (padding > 0 && ptr != end)
            MORDOR_ASSERT(false);
        if (padding > 2)
            MORDOR_ASSERT(false);

        *writeBuf++ = (char)((packed >> 16) & 0xff);
        if(padding != 2)
            *writeBuf++ = (char)((packed >> 8) & 0xff);
        if(padding == 0)
            *writeBuf++ = (char)(packed & 0xff);
    }

    result.resize(writeBuf - result.c_str());
    return result;
}

std::string
base64encode(const std::string& data)
{
    return base64encode(data.c_str(), data.size());
}

std::string
base64encode(const void* data, size_t len)
{
    const char* base64 =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string ret;
    ret.reserve(len * 4 / 3 + 2);

    const unsigned char* ptr = (const unsigned char*)data;
    const unsigned char* end = ptr + len;

    while(ptr < end) {
        unsigned int packed = 0;
        int i = 0;
        int padding = 0;
        for(; i < 3 && ptr < end; ++i, ++ptr)
            packed = (packed << 8) | *ptr;
        if(i == 2)
            padding = 1;
        else if (i == 1)
            padding = 2;
        for(; i < 3; ++i)
            packed <<= 8;

        ret.append(1, base64[packed >> 18]);
        ret.append(1, base64[(packed >> 12) & 0x3f]);
        if(padding != 2)
            ret.append(1, base64[(packed >> 6) & 0x3f]);
        if(padding == 0)
            ret.append(1, base64[packed & 0x3f]);
        ret.append(padding, '=');
    }

    return ret;
}

std::string
md5(const std::string &data)
{
    return hexstringFromData(md5sum(data).c_str(), MD5_DIGEST_LENGTH);
}

std::string
sha1(const std::string &data)
{
	return hexstringFromData(sha1sum(data).c_str(), SHA_DIGEST_LENGTH);
}

std::string
md5sum(const void *data, size_t len)
{
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, data, len);
    std::string result;
    result.resize(MD5_DIGEST_LENGTH);
    MD5_Final((unsigned char*)&result[0], &ctx);
    return result;
}

std::string
md5sum(const std::string &data)
{
    return md5sum(data.c_str(), data.size());
}

std::string
sha1sum(const void *data, size_t len)
{
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, data, len);
    std::string result;
    result.resize(SHA_DIGEST_LENGTH);
    SHA1_Final((unsigned char*)&result[0], &ctx);
    return result;
}

std::string
sha1sum(const std::string &data)
{
    return sha1sum(data.c_str(), data.size());
}

struct xorStruct
{
    xorStruct(char value) : m_value(value) {}
    char m_value;
    char operator()(char in) const { return in ^ m_value; }
};

std::string
hmacMd5(const std::string &text, std::string key)
{
    const unsigned int B = 64;
    const unsigned int L = MD5_DIGEST_LENGTH;
    if (key.size() > B)
        key = md5sum(key);
    key.append(B - key.size(), '\0');
    std::string ipad = key, opad = key;
    std::transform(ipad.begin(), ipad.end(), ipad.begin(), xorStruct(0x36));
    std::transform(opad.begin(), opad.end(), opad.begin(), xorStruct(0x5c));
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, ipad.c_str(), B);
    MD5_Update(&ctx, text.c_str(), text.size());
    std::string result;
    result.resize(L);
    MD5_Final((unsigned char *)&result[0], &ctx);
    MD5_Init(&ctx);
    MD5_Update(&ctx, opad.c_str(), B);
    MD5_Update(&ctx, result.c_str(), L);
    MD5_Final((unsigned char *)&result[0], &ctx);
    return result;
}

std::string
hmacSha1(const std::string &text, std::string key)
{
    const unsigned int B = 64;
    const unsigned int L = SHA_DIGEST_LENGTH;
    if (key.size() > B)
        key = sha1sum(key);
    key.append(B - key.size(), '\0');
    std::string ipad = key, opad = key;
    std::transform(ipad.begin(), ipad.end(), ipad.begin(), xorStruct(0x36));
    std::transform(opad.begin(), opad.end(), opad.begin(), xorStruct(0x5c));
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, ipad.c_str(), B);
    SHA1_Update(&ctx, text.c_str(), text.size());
    std::string result;
    result.resize(L);
    SHA1_Final((unsigned char *)&result[0], &ctx);
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, opad.c_str(), B);
    SHA1_Update(&ctx, result.c_str(), L);
    SHA1_Final((unsigned char *)&result[0], &ctx);
    return result;
}

void
hexstringFromData(const void *data, size_t len, void *output)
{
    const unsigned char *buf = (const unsigned char *)data;
    char *hex = (char *)output;
    size_t i, j;
    for (i = j = 0; i < len; ++i) {
        char c;
        c = (buf[i] >> 4) & 0xf;
        c = (c > 9) ? c + 'a' - 10 : c + '0';
        hex[j++] = c;
        c = (buf[i] & 0xf);
        c = (c > 9) ? c + 'a' - 10 : c + '0';
        hex[j++] = c;
    }
    hex[j] = '\0';
}

std::string
hexstringFromData(const void *data, size_t len)
{
    if (len == 0)
        return "";
    std::string result;
    result.resize(len * 2);
    hexstringFromData(data, len, &result[0]);
    return result;
}

void
replace(std::string &str, char find, char replaceWith)
{
    size_t index = str.find(find);
    while (index != std::string::npos) {
        str[index] = replaceWith;
        index = str.find(find, index + 1);
    }
}

std::vector<std::string>
split(const std::string &str, char delim, size_t max)
{
    MORDOR_ASSERT(max > 1);
	std::vector<std::string> result;

	size_t last = 0;
	size_t pos = str.find(delim);
	while (pos != std::string::npos) {
		result.push_back(str.substr(last, pos - last));
		last = pos + 1;
        if (--max == 1)
            break;
		pos = str.find(delim, last);
	}
    result.push_back(str.substr(last));
	return result;
}

std::vector<std::string>
split(const std::string &str, const char *delims, size_t max)
{
    MORDOR_ASSERT(max > 1);
	std::vector<std::string> result;

	size_t last = 0;
	size_t pos = str.find_first_of(delims);
	while (pos != std::string::npos) {
		result.push_back(str.substr(last, pos - last));
		last = pos + 1;
        if (--max == 1)
            break;
		pos = str.find_first_of(delims, last);
	}
    result.push_back(str.substr(last));
	return result;
}

#ifdef WINDOWS
std::string
toUtf8(const wchar_t *str, size_t len)
{
    if (len == (size_t)~0)
        len = wcslen(str);
    MORDOR_ASSERT(len < 0x80000000u);
    std::string result;
    if (len == 0)
        return result;
    int ret = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, str, (int)len, NULL, 0, NULL, NULL);
    if (ret == 0)
        MORDOR_THROW_EXCEPTION_FROM_LAST_ERROR_API("WideCharToMultiByte");
    result.resize(ret);
    ret = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, str, (int)len, &result[0], ret, NULL, NULL);
    if (ret == 0)
        MORDOR_THROW_EXCEPTION_FROM_LAST_ERROR_API("WideCharToMultiByte");
    MORDOR_ASSERT(ret == result.size());

    return result;
}

std::string
toUtf8(const std::wstring &str)
{
    MORDOR_ASSERT(str.size() < 0x80000000u);
    return toUtf8(str.c_str(), str.size());
}

std::wstring
toUtf16(const char *str, size_t len)
{
    if (len == (size_t)~0)
        len = strlen(str);
    MORDOR_ASSERT(len < 0x80000000u);
    std::wstring result;
    if (len == 0)
        return result;
    int ret = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str, (int)len, NULL, 0);
    if (ret == 0)
        MORDOR_THROW_EXCEPTION_FROM_LAST_ERROR_API("MultiByteToWideChar");
    result.resize(ret);
    ret = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str, (int)len, &result[0], ret);
    if (ret == 0)
        MORDOR_THROW_EXCEPTION_FROM_LAST_ERROR_API("MultiByteToWideChar");
    MORDOR_ASSERT(ret == result.size());

    return result;
}

std::wstring
toUtf16(const std::string &str)
{
    MORDOR_ASSERT(str.size() < 0x80000000u);
    return toUtf16(str.c_str(), str.size());
}
#endif

bool
caseinsensitiveless::operator ()(const std::string &lhs, const std::string &rhs) const
{
    return stricmp(lhs.c_str(), rhs.c_str()) < 0;
}

std::ostream &operator <<(std::ostream &os, const charslice &slice)
{
    for (size_t i = 0; i < slice.m_len; ++i) {
        os.put(slice.m_slice[i]);
    }
    return os;
}

}