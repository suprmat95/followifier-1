#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.h"

server::server(boost::asio::io_service &io_service) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port_num)) {
    start_accept();
}

void server::start_accept() {
    connection::pointer new_connection =
            connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&::server::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
}

void server::handle_accept(connection::pointer new_connection,
                           const boost::system::error_code &error) {
    if (!error) {
        new_connection->start();
    }

    start_accept();
}