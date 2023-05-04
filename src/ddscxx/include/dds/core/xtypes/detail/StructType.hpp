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
#ifndef OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_
#define OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_

#include <dds/core/xtypes/DynamicType.hpp>
#include <dds/core/xtypes/MemberType.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      namespace detail {
        class StructType : public xtypes::DynamicType {
          public:
            StructType(const std::string& name)
              :  xtypes::DynamicType(name, xtypes::TypeKind::STRUCTURE_TYPE), parent_(nullptr)
            {
            }

            StructType(const std::string& name, const StructType& parent, const std::vector<xtypes::MemberType>& members)
              : xtypes::DynamicType(name, xtypes::TypeKind::STRUCTURE_TYPE), parent_(&parent), members_(members)
            {
            }

            template <typename MemberIter>
            StructType(const std::string& name, const StructType& parent, MemberIter begin, MemberIter end)
              : xtypes::DynamicType(name, xtypes::TypeKind::STRUCTURE_TYPE), parent_(&parent)
            {
              members_.reserve(members_.size() + (end - begin));
              for (auto it = begin; it != end; it++)
                members_.emplace_back(*it);
            }

          public:
            bool has_parent() const { return this->parent_ == nullptr; }
            void parent(const StructType& parent) { this->parent_ = &parent; }
            const StructType& parent() const { return *(this->parent_); }
            void add_member(const xtypes::MemberType& member) { this->members_.emplace_back(member); }

          private:
            const StructType* parent_;
            std::vector<xtypes::MemberType> members_;
        };

        // bool isFinal(const StructType& s) { return false; }

        // bool isExtensible(const StructType& s) { return false; }

        // bool isMutable(const StructType& s) { return false; }

        // bool isNested(const StructType& s) { return false; }
      }
    }
  }
}



#endif /* OMG_DDS_CORE_XTYPES_DETAIL_STRUCT_TYPE_HPP_ */
