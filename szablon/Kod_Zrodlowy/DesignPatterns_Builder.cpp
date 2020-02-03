HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameI_Calibrate() const
{
    const auto retFrame = FrameI()
        .setAddressByte(0x03)
        .setControlByte(frameI::BYTE_CONTROL::CALIBRATE_REQ)
        .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET)
        .setParameterLength(Hexes{ZERO, ZERO});
   return std::make_shared<FrameI>(retFrame);
}
