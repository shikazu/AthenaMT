#include "ConnectorClient.h"

using namespace Connector;


ConnectorClient::ConnectorClient(boost::asio::io_service& IO_Service, tcp::resolver::iterator EndPointIter)
	: m_IOService(IO_Service), m_Socket(IO_Service)
{
	tcp::endpoint EndPoint = *EndPointIter;

	m_BufLen = 4096;

	m_Socket.async_connect(EndPoint,
		boost::bind(&ConnectorClient::OnConnect, this, boost::asio::placeholders::error, ++EndPointIter));
}

void ConnectorClient::Close()
{
	m_IOService.post(
		boost::bind(&ConnectorClient::DoClose, this));
}
void ConnectorClient::OnConnect(const boost::system::error_code& ErrorCode,
	tcp::resolver::iterator EndPointIter)
{
	if (ErrorCode == 0)
		// Successful connected
	{
		m_Socket.async_receive(boost::asio::buffer(m_Buffer.data(), m_BufLen),
			boost::bind(&ConnectorClient::OnReceive, this, boost::asio::placeholders::error));

	}
	else if (EndPointIter != tcp::resolver::iterator())
	{
		m_Socket.close();
		tcp::endpoint EndPoint = *EndPointIter;

		m_Socket.async_connect(EndPoint,
			boost::bind(&ConnectorClient::OnConnect, this, boost::asio::placeholders::error, ++EndPointIter));
	}
}

void ConnectorClient::OnReceive(const boost::system::error_code& ErrorCode)
{
	if (ErrorCode == 0)
	{
		std::cout << m_Buffer.data() << std::endl;

		m_Socket.async_receive(boost::asio::buffer(m_Buffer.data(), m_BufLen),
			boost::bind(&ConnectorClient::OnReceive, this, boost::asio::placeholders::error));
	}
	else 
	{
		DoClose();
	}
}

void ConnectorClient::DoClose()
{
	m_Socket.close();
}
