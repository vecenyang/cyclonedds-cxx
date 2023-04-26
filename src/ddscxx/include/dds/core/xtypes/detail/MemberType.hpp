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
#ifndef OMG_DDS_CORE_XTYPES_DETAIL_TMEMBER_TYPE_HPP
#define OMG_DDS_CORE_XTYPES_DETAIL_TMEMBER_TYPE_HPP

#include <dds/core/xtypes/DynamicType.hpp>

namespace dds {
namespace core {
namespace xtypes {
namespace detail {
class MemberType
{
  public:
    MemberType(const std::string& name, xtypes::DynamicType& dt)
        : name_(name), dt_(dt), is_optional_(false), is_key_(false), id_(-1)
    {
    }

    void name(const std::string& name)
    {
        name_ = name;
    }

    void dt(const xtypes::DynamicType& dt)
    {
        dt_ = dt;
    }

    const std::string& name()
    {
        return name_;
    }

    const xtypes::DynamicType& dynamic_type()
    {
        return dt_;
    }

    MemberType& optional(bool value)
    {
        this->is_optional_ = value;
        return *this;
    }

    bool is_optional()
    {
        return is_optional_;
    }

    MemberType& key(bool value)
    {
        this->is_key_ = value;
        return *this;
    }

    bool is_key()
    {
        return is_key_;
    }

    MemberType& id(int32_t value)
    {
        this->id_ = value;
        return *this;
    }

    bool has_id()
    {
        return id_ == -1;
    }

    uint32_t get_id()
    {
        return id_;
    }

  private:

    std::string name_;
    xtypes::DynamicType dt_;
    bool is_optional_;
    bool is_key_;
    uint32_t id_;
};
}
}
}
}

#endif /* OMG_DDS_CORE_XTYPES_DETAIL_TMEMBER_TYPE_HPP */
