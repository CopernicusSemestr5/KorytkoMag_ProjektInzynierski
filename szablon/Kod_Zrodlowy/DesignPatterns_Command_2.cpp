void DeviceScan::execute()
{
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr DeviceScan::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_DeviceScan();
}

void DeviceScan::executeImpl()
{
   hdlcCommunicator_->communicate(validatedUserInput_[IDX_OF_ADDRESS_],
                           getFrameBody());
}

std::string DeviceScan::handleResponse()
{
   return constraints::almag::L2::DEVICE_SCAN + DELIMITER;
}
