void ZMqReqRepPrimaryStrategy::setupSend(const std::string& address)
{
   tcpPortAddress = tcpPortAddressHeader + address;
   socket_.connect(tcpPortAddress);
}

void ZMqReqRepPrimaryStrategy::setupReceive(const std::string& address)
{ throw std::runtime_error("Redundant function"); }

bool ZMqReqRepPrimaryStrategy::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   const std::string sentMessage = toString(frame->build());
   return s_send(socket_, sentMessage);
}

HDLCFramePtr ZMqReqRepPrimaryStrategy::receive(const std::string &address)
{
   std::string message = s_recv(socket_);
   auto recFrame{
           std::make_shared<HDLCFrame>(HDLCFrameBodyInterpreter().apply(message)) };
   return recFrame;
}

HDLCFramePtr ZMqReqRepPrimaryStrategy::communicate(const std::string& address, HDLCFrameBodyPtr frame)
{
   send(tcpPortAddress, frame);
   std::this_thread::sleep_for(1s);
   receive(tcpPortAddress);
   return nullptr;
}