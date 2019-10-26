# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: message.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='message.proto',
  package='followifier',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=_b('\n\rmessage.proto\x12\x0b\x66ollowifier\"_\n\x0c\x45SP32Message\x12\r\n\x05\x61pMac\x18\x01 \x02(\t\x12\x0c\n\x04ssid\x18\x02 \x02(\t\x12\x11\n\ttimestamp\x18\x03 \x02(\x03\x12\x12\n\nframe_hash\x18\x04 \x02(\t\x12\x0b\n\x03rsi\x18\x05 \x02(\x05\"F\n\x05\x42\x61tch\x12\x10\n\x08\x62oardMac\x18\x01 \x02(\t\x12+\n\x08messages\x18\x02 \x03(\x0b\x32\x19.followifier.ESP32Message')
)




_ESP32MESSAGE = _descriptor.Descriptor(
  name='ESP32Message',
  full_name='followifier.ESP32Message',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='apMac', full_name='followifier.ESP32Message.apMac', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ssid', full_name='followifier.ESP32Message.ssid', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='followifier.ESP32Message.timestamp', index=2,
      number=3, type=3, cpp_type=2, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='frame_hash', full_name='followifier.ESP32Message.frame_hash', index=3,
      number=4, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='rsi', full_name='followifier.ESP32Message.rsi', index=4,
      number=5, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=30,
  serialized_end=125,
)


_BATCH = _descriptor.Descriptor(
  name='Batch',
  full_name='followifier.Batch',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='boardMac', full_name='followifier.Batch.boardMac', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='messages', full_name='followifier.Batch.messages', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=127,
  serialized_end=197,
)

_BATCH.fields_by_name['messages'].message_type = _ESP32MESSAGE
DESCRIPTOR.message_types_by_name['ESP32Message'] = _ESP32MESSAGE
DESCRIPTOR.message_types_by_name['Batch'] = _BATCH
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ESP32Message = _reflection.GeneratedProtocolMessageType('ESP32Message', (_message.Message,), dict(
  DESCRIPTOR = _ESP32MESSAGE,
  __module__ = 'message_pb2'
  # @@protoc_insertion_point(class_scope:followifier.ESP32Message)
  ))
_sym_db.RegisterMessage(ESP32Message)

Batch = _reflection.GeneratedProtocolMessageType('Batch', (_message.Message,), dict(
  DESCRIPTOR = _BATCH,
  __module__ = 'message_pb2'
  # @@protoc_insertion_point(class_scope:followifier.Batch)
  ))
_sym_db.RegisterMessage(Batch)


# @@protoc_insertion_point(module_scope)
