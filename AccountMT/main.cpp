#include <iostream>

#include "Connector\RedisConnector.h"
#include "Server\AccountServer.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>

boost::asio::io_service io_service;

int main(int argc, char** argv)
{
	Account::AccountServer account_server(io_service, 6900);
	RedisAsyncClient redis_async(io_service);

	boost::asio::ip::address address = boost::asio::ip::address::from_string("127.0.0.1");
	const unsigned short port = 6379;

	RedisAsyncClient client(io_service);
	Connector::RedisConnector redis(io_service, client);
	boost::asio::ip::tcp::endpoint endpoint(address, port);

	client.asyncConnect(endpoint, boost::bind(&Connector::RedisConnector::onConnect, &redis, _1, _2));

	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	t.join();

	return 0;
}

