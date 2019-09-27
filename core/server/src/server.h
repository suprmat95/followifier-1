//
// Created by simona on 22/09/19.
//

#ifndef CORE_SERVER_H
#define CORE_SERVER_H


#include <boost/asio.hpp>
#include "connection.h"


class server {

    const size_t port = 12345;

public:
    explicit server(boost::asio::io_service &io_service);

private:
    void start_accept();

    void handle_accept(const connection::pointer& new_connection,
                       const boost::system::error_code &error);

    tcp::acceptor acceptor_;
};


#endif //CORE_SERVER_H