#ifndef _WORLD_WORLDMAIN_H_
#define _WORLD_WORLDMAIN_H_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <thread>

namespace World
{
	class WorldMain
	{
	private:
		// Thread for communication with the account server
		boost::asio::io_service account_connector_io_service;
		void start_account_connector_client();

		// Thread for communication with region servers
		boost::asio::io_service world_connector_server_io_service;
		void start_world_connector_server();

		// Generate all Models
		void startup();
	public:
		WorldMain();
		~WorldMain();
	};
}

#endif