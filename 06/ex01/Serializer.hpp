#pragma once

#include <string>

struct Data {
  std::string s1;
  int n;
  std::string s2;
};

class Serializer {
private:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
