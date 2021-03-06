/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: message.proto */

#ifndef PROTOBUF_C_message_2eproto__INCLUDED
#define PROTOBUF_C_message_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Followifier__ESP32Metadata Followifier__ESP32Metadata;
typedef struct _Followifier__ESP32Message Followifier__ESP32Message;
typedef struct _Followifier__Batch Followifier__Batch;


/* --- enums --- */


/* --- messages --- */

struct  _Followifier__ESP32Metadata
{
  ProtobufCMessage base;
  char *devicemac;
  char *ssid;
  int64_t timestamp;
  int32_t rssi;
};
#define FOLLOWIFIER__ESP32_METADATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&followifier__esp32_metadata__descriptor) \
    , NULL, NULL, 0, 0 }


struct  _Followifier__ESP32Message
{
  ProtobufCMessage base;
  Followifier__ESP32Metadata *metadata;
  ProtobufCBinaryData frame_hash;
};
#define FOLLOWIFIER__ESP32_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&followifier__esp32_message__descriptor) \
    , NULL, {0,NULL} }


struct  _Followifier__Batch
{
  ProtobufCMessage base;
  char *boardmac;
  size_t n_messages;
  Followifier__ESP32Message **messages;
};
#define FOLLOWIFIER__BATCH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&followifier__batch__descriptor) \
    , NULL, 0,NULL }


/* Followifier__ESP32Metadata methods */
void   followifier__esp32_metadata__init
                     (Followifier__ESP32Metadata         *message);
size_t followifier__esp32_metadata__get_packed_size
                     (const Followifier__ESP32Metadata   *message);
size_t followifier__esp32_metadata__pack
                     (const Followifier__ESP32Metadata   *message,
                      uint8_t             *out);
size_t followifier__esp32_metadata__pack_to_buffer
                     (const Followifier__ESP32Metadata   *message,
                      ProtobufCBuffer     *buffer);
Followifier__ESP32Metadata *
       followifier__esp32_metadata__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   followifier__esp32_metadata__free_unpacked
                     (Followifier__ESP32Metadata *message,
                      ProtobufCAllocator *allocator);
/* Followifier__ESP32Message methods */
void   followifier__esp32_message__init
                     (Followifier__ESP32Message         *message);
size_t followifier__esp32_message__get_packed_size
                     (const Followifier__ESP32Message   *message);
size_t followifier__esp32_message__pack
                     (const Followifier__ESP32Message   *message,
                      uint8_t             *out);
size_t followifier__esp32_message__pack_to_buffer
                     (const Followifier__ESP32Message   *message,
                      ProtobufCBuffer     *buffer);
Followifier__ESP32Message *
       followifier__esp32_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   followifier__esp32_message__free_unpacked
                     (Followifier__ESP32Message *message,
                      ProtobufCAllocator *allocator);
/* Followifier__Batch methods */
void   followifier__batch__init
                     (Followifier__Batch         *message);
size_t followifier__batch__get_packed_size
                     (const Followifier__Batch   *message);
size_t followifier__batch__pack
                     (const Followifier__Batch   *message,
                      uint8_t             *out);
size_t followifier__batch__pack_to_buffer
                     (const Followifier__Batch   *message,
                      ProtobufCBuffer     *buffer);
Followifier__Batch *
       followifier__batch__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   followifier__batch__free_unpacked
                     (Followifier__Batch *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Followifier__ESP32Metadata_Closure)
                 (const Followifier__ESP32Metadata *message,
                  void *closure_data);
typedef void (*Followifier__ESP32Message_Closure)
                 (const Followifier__ESP32Message *message,
                  void *closure_data);
typedef void (*Followifier__Batch_Closure)
                 (const Followifier__Batch *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor followifier__esp32_metadata__descriptor;
extern const ProtobufCMessageDescriptor followifier__esp32_message__descriptor;
extern const ProtobufCMessageDescriptor followifier__batch__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_message_2eproto__INCLUDED */
