//
// Created by matteo on 28/10/19.
//
#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include "../gen/message.pb.h"
#ifndef CORE_DATABASE_H
#define CORE_DATABASE_H
class database {
    mongoc_client_t *client;
    mongoc_collection_t *collection;

public:
    explicit database();

     void insert_message(followifier::ESP32Message message);
     void destroy_database_connection();
};

#endif //CORE_DATABASE_H