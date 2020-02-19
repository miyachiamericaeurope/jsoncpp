#include "json/json.h"
#include <iostream>
/**
 * \brief Parse a raw string into Value object using the CharReaderBuilder
 * class, or the legacy Reader class.
 * Example Usage:
 * $g++ readFromString.cpp -ljsoncpp -std=c++11 -o readFromString
 * $./readFromString
 * colin
 * 20
 */
int main() {
  //const std::string rawJson = R"({"Age": 20, "Name": "colin"})";
  const std::string rawJson = R"({"timestamp": "2020-02-19T16:36:43.962976", "src_uuid": "40a9244e2b274b47b3747fa5c2bed258", "data": "#22 REPORT 1\r\n2503582,1,0.103,-0.0020,200,0\r\n\n"})";
  const auto rawJsonLength = static_cast<int>(rawJson.length());
  constexpr bool shouldUseOldWay = false;
  JSONCPP_STRING err;
  Json::Value root;

  if (shouldUseOldWay) {
    Json::Reader reader;
    reader.parse(rawJson, root);
  } else {
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
                       &err)) {
      std::cout << "error" << std::endl;
      return EXIT_FAILURE;
    }
  }
  //const std::string name = root["Name"].asString();
  //const int age = root["Age"].asInt();
  const std::string timestamp = root["timestamp"].asString();
  const std::string src_uuid = root["src_uuid"].asString();
  const std::string data = root["data"].asString();


  std::cout << timestamp << std::endl;
  std::cout << src_uuid << std::endl;
  std::cout << data << std::endl;

  return EXIT_SUCCESS;
}
