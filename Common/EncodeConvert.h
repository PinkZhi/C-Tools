#ifndef ENCODE_CONVERT
#define ENCODE_CONVERT

#include <string>

bool WsToS(const std::wstring& src, std::string& ret);
bool SToWs(const std::string& src, std::wstring& ret);

#endif //ENCODE_CONVERT