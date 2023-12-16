#ifndef JSON_TO_STRING_H
#define JSON_TO_STRING_H

#include <json/json.h>
#include <string>

std::string JsonToString(const Json::Value& root);

#endif // JSON_TO_STRING_H
