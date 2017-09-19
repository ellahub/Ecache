// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CommonData.proto

#ifndef PROTOBUF_CommonData_2eproto__INCLUDED
#define PROTOBUF_CommonData_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
class CommonData;
class CommonDataDefaultTypeInternal;
extern CommonDataDefaultTypeInternal _CommonData_default_instance_;

namespace protobuf_CommonData_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_CommonData_2eproto

// ===================================================================

class CommonData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CommonData) */ {
 public:
  CommonData();
  virtual ~CommonData();

  CommonData(const CommonData& from);

  inline CommonData& operator=(const CommonData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CommonData(CommonData&& from) noexcept
    : CommonData() {
    *this = ::std::move(from);
  }

  inline CommonData& operator=(CommonData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommonData& default_instance();

  static inline const CommonData* internal_default_instance() {
    return reinterpret_cast<const CommonData*>(
               &_CommonData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CommonData* other);
  friend void swap(CommonData& a, CommonData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CommonData* New() const PROTOBUF_FINAL { return New(NULL); }

  CommonData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CommonData& from);
  void MergeFrom(const CommonData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CommonData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes tag = 1;
  bool has_tag() const;
  void clear_tag();
  static const int kTagFieldNumber = 1;
  const ::std::string& tag() const;
  void set_tag(const ::std::string& value);
  #if LANG_CXX11
  void set_tag(::std::string&& value);
  #endif
  void set_tag(const char* value);
  void set_tag(const void* value, size_t size);
  ::std::string* mutable_tag();
  ::std::string* release_tag();
  void set_allocated_tag(::std::string* tag);

  // required bytes data = 2;
  bool has_data() const;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // required uint32 cond = 3;
  bool has_cond() const;
  void clear_cond();
  static const int kCondFieldNumber = 3;
  ::google::protobuf::uint32 cond() const;
  void set_cond(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:CommonData)
 private:
  void set_has_tag();
  void clear_has_tag();
  void set_has_data();
  void clear_has_data();
  void set_has_cond();
  void clear_has_cond();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr tag_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::uint32 cond_;
  friend struct protobuf_CommonData_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CommonData

// required bytes tag = 1;
inline bool CommonData::has_tag() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CommonData::set_has_tag() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CommonData::clear_has_tag() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CommonData::clear_tag() {
  tag_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_tag();
}
inline const ::std::string& CommonData::tag() const {
  // @@protoc_insertion_point(field_get:CommonData.tag)
  return tag_.GetNoArena();
}
inline void CommonData::set_tag(const ::std::string& value) {
  set_has_tag();
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CommonData.tag)
}
#if LANG_CXX11
inline void CommonData::set_tag(::std::string&& value) {
  set_has_tag();
  tag_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CommonData.tag)
}
#endif
inline void CommonData::set_tag(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_tag();
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CommonData.tag)
}
inline void CommonData::set_tag(const void* value, size_t size) {
  set_has_tag();
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CommonData.tag)
}
inline ::std::string* CommonData::mutable_tag() {
  set_has_tag();
  // @@protoc_insertion_point(field_mutable:CommonData.tag)
  return tag_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommonData::release_tag() {
  // @@protoc_insertion_point(field_release:CommonData.tag)
  clear_has_tag();
  return tag_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommonData::set_allocated_tag(::std::string* tag) {
  if (tag != NULL) {
    set_has_tag();
  } else {
    clear_has_tag();
  }
  tag_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), tag);
  // @@protoc_insertion_point(field_set_allocated:CommonData.tag)
}

// required bytes data = 2;
inline bool CommonData::has_data() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CommonData::set_has_data() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CommonData::clear_has_data() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CommonData::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_data();
}
inline const ::std::string& CommonData::data() const {
  // @@protoc_insertion_point(field_get:CommonData.data)
  return data_.GetNoArena();
}
inline void CommonData::set_data(const ::std::string& value) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CommonData.data)
}
#if LANG_CXX11
inline void CommonData::set_data(::std::string&& value) {
  set_has_data();
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CommonData.data)
}
#endif
inline void CommonData::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CommonData.data)
}
inline void CommonData::set_data(const void* value, size_t size) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CommonData.data)
}
inline ::std::string* CommonData::mutable_data() {
  set_has_data();
  // @@protoc_insertion_point(field_mutable:CommonData.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommonData::release_data() {
  // @@protoc_insertion_point(field_release:CommonData.data)
  clear_has_data();
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommonData::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    set_has_data();
  } else {
    clear_has_data();
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:CommonData.data)
}

// required uint32 cond = 3;
inline bool CommonData::has_cond() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CommonData::set_has_cond() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CommonData::clear_has_cond() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CommonData::clear_cond() {
  cond_ = 0u;
  clear_has_cond();
}
inline ::google::protobuf::uint32 CommonData::cond() const {
  // @@protoc_insertion_point(field_get:CommonData.cond)
  return cond_;
}
inline void CommonData::set_cond(::google::protobuf::uint32 value) {
  set_has_cond();
  cond_ = value;
  // @@protoc_insertion_point(field_set:CommonData.cond)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CommonData_2eproto__INCLUDED