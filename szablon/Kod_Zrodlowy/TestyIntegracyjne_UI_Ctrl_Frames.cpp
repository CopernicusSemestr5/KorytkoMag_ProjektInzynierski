TEST_P(UI_Controller_RoundTripHDLC, ExecuteCommandAndExpectSentFrame)
{
   const auto& returnCode = ui_.runPredefinedCommands(
       GetParam().inCommands
   );
   auto sentFrames = hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR)
       ->receive(BUFFER_TO_SEND_VAL_1);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(sentFrames);
   ASSERT_EQ(sentFrames->build(), GetParam().expectedFrameHexes);
}
INSTANTIATE_TEST_CASE_P(BaseFixtureWithDB,
   UI_Controller_RoundTripHDLC,
   ::testing::Values(
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()).build()
      },
      ReceivedCommand_ExpectedFrameHexes{
         {{ L2::LINK_ESTABLISHMENT, BUFFER_TO_SEND_VAL_1 }},
         HDLCFrame(hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()).build()
      }
   )
)