/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: hash.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "hash.pb-c.h"
void   hello_request__init
                     (HelloRequest         *message)
{
  static const HelloRequest init_value = HELLO_REQUEST__INIT;
  *message = init_value;
}
size_t hello_request__get_packed_size
                     (const HelloRequest *message)
{
  assert(message->base.descriptor == &hello_request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t hello_request__pack
                     (const HelloRequest *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &hello_request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t hello_request__pack_to_buffer
                     (const HelloRequest *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &hello_request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
HelloRequest *
       hello_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (HelloRequest *)
     protobuf_c_message_unpack (&hello_request__descriptor,
                                allocator, len, data);
}
void   hello_request__free_unpacked
                     (HelloRequest *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &hello_request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor hello_request__field_descriptors[1] =
{
  {
    "name",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(HelloRequest, name),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned hello_request__field_indices_by_name[] = {
  0,   /* field[0] = name */
};
static const ProtobufCIntRange hello_request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor hello_request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "HelloRequest",
  "HelloRequest",
  "HelloRequest",
  "",
  sizeof(HelloRequest),
  1,
  hello_request__field_descriptors,
  hello_request__field_indices_by_name,
  1,  hello_request__number_ranges,
  (ProtobufCMessageInit) hello_request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
