#ifndef _CONNECTOR_CONNECTORCLIENT_H_
#define _CONNECTOR_CONNECTORCLIENT_H_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <string>

using boost::asio::ip::tcp;

namespace Connector
{
	class ConnectorClient
	{
	public:
		ConnectorClient(boost::asio::io_service& IO_Service, tcp::resolver::iterator EndPointIter);

		void Write();
		void Close();
	private:
		boost::asio::io_service& m_IOService;
		tcp::socket m_Socket;

		boost::array<char, 4096> m_Buffer;
		size_t m_BufLen;

	private:
		void OnConnect(const boost::system::error_code& ErrorCode, tcp::resolver::iterator EndPointIter);

		void OnReceive(const boost::system::error_code& ErrorCode);

		void DoClose();
	};
}

#endif
