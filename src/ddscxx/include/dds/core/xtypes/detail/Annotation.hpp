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
#ifndef OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_
#define OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_

#include <dds/core/xtypes/TypeKind.hpp>

namespace dds {
  namespace core {
    namespace xtypes {
      namespace detail {
        class Annotation {
          public:
            Annotation(AnnotationKind ak) : ak_(ak) {}
#if defined (OMG_DDS_X_TYPES_DYNAMIC_TYPE_SUPPORT)
            dds::core::xtypes::TypeKind kind() const { return dds::core::xtypes::TypeKind::ANNOTATION_TYPE; }
#endif
            const AnnotationKind& akind() { return ak_; }
          protected:
            AnnotationKind ak_;
        };

        class IdAnnotation : public  Annotation {
          public:
            IdAnnotation(uint32_t id) : Annotation(dds::core::xtypes::AnnotationKind::ID_ANNOTATION_TYPE), id_(id) {}
            IdAnnotation(Annotation& a) : Annotation(AnnotationKind::ID_ANNOTATION_TYPE), id_(static_cast<const detail::IdAnnotation&>(a).id()) { }
            void id(uint32_t id) { this->id_ = id; }
            uint32_t id() const { return this->id_; }
            template<typename Q,template <typename> class K>
            operator K<Q>&(){ return reinterpret_cast<K<Q>&>(*this);}

          private:
            uint32_t id_;
        };

        class KeyAnnotation : public  Annotation { };

        class SharedAnnotation : public  Annotation  { };

        class NestedAnnotation : public  Annotation  { };

        class ExtensibilityAnnotation : public  Annotation  { };

        class MustUnderstandAnnotation : public  Annotation { };

        class VerbatimAnnotation : public  Annotation { };

        class BitsetAnnotation : public  Annotation { };

        class BitBoundAnnotation : public  Annotation  { };
      }
    }
  }
}
#endif /* OMG_DDS_CORE_XTYPES_DETAIL_ANNOTATIONS_HPP_ */
