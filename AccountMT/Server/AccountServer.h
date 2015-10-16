#ifndef _ACCOUNT_SERVER_H_
#define _ACCOUNT_SERVER_H_

#include <iostream>
#include <boost/asio.hpp>

#include "AccountSession.h"

using boost::asio::ip::tcp;

namespace Account
{
	class AccountServer
	{
	public:
		AccountServer(boost::asio::io_service &io_service, uint16_t port);
		~AccountServer();

	private:
		void do_accept();		

		tcp::acceptor acceptor;
		tcp::socket socket;
	};
}

#endif