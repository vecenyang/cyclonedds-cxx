#include <dds/core/xtypes/PrimitiveTypes.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      const TypeKind dynamic_type_traits<uint8_t>::TYPE_ID = TypeKind::UINT_8_TYPE;
      const char* const dynamic_type_traits<uint8_t>::NAME = "uint8_t";

      const TypeKind dynamic_type_traits<int16_t>::TYPE_ID = TypeKind::INT_16_TYPE;
      const char* const dynamic_type_traits<int16_t>::NAME = "int16_t";

      const TypeKind dynamic_type_traits<uint16_t>::TYPE_ID = TypeKind::UINT_16_TYPE;
      const char* const dynamic_type_traits<uint16_t>::NAME = "uint16_t";

      const TypeKind dynamic_type_traits<int32_t>::TYPE_ID = TypeKind::INT_32_TYPE;
      const char* const dynamic_type_traits<int32_t>::NAME = "int32_t";

      const TypeKind dynamic_type_traits<uint32_t>::TYPE_ID = TypeKind::UINT_32_TYPE;
      const char* const dynamic_type_traits<uint32_t>::NAME = "uint32_t";
    }
  }
}