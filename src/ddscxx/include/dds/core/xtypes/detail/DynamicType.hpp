/*
 * Copyright(c) 2006 to 2020 ZettaScale Technology and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef OMG_DDS_CORE_DETAIL_XTYPES_DYNAMIC_TYPE_HPP_
#define OMG_DDS_CORE_DETAIL_XTYPES_DYNAMIC_TYPE_HPP_

#include <dds/core/conformance.hpp>
#include <dds/core/xtypes/TypeKind.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      namespace detail {
        class DynamicType {
          public:
            DynamicType() : kind_(xtypes::TypeKind::NO_TYPE) {}

            void name(const std::string& name)
            {
              this->name_ = name;
            }

            const std::string& name() const
            {
              return name_;
            }

            void kind(xtypes::TypeKind kind)
            {
              this->kind_ = kind;
            }

            const xtypes::TypeKind& kind() const
            {
              return kind_;
            }

            DynamicType(const DynamicType& other) : kind_(other.kind())
            {
              this->name_ = other.name();
            }

          private:
            std::string name_;
            xtypes::TypeKind kind_;
        };
      }
    }
  }
}
#endif /* OMG_DDS_CORE_DETAIL_XTYPES_DYNAMIC_TYPE_HPP_ */
