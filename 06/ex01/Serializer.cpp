#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
  *this = other;
  return;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &rhs) {
  (void)rhs;
  return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
