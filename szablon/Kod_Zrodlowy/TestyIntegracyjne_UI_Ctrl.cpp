TEST_P(KorytkoMagControllerShouldPar, Execute_Command_Expect_ResultCode)
{
   ctrl_->addCommands(GetParam().inCommands);
   ctrl_->executeCommand();

   ASSERT_EQ(ctrl_->getFinalResultCode(), GetParam().expectedHdlcFrame);
}
INSTANTIATE_TEST_CASE_P(BaseFixtureWithDBAndHDLC,
   KorytkoMagControllerShouldPar,
   ::testing::Values(
      CommandsToExpectedFrame{
         {{ L2::DEVICE_SCAN, BUFFER_TO_SEND_VAL_1 }},
         L2::DEVICE_SCAN + DELIMITER
      },
      CommandsToExpectedFrame{
         {{ L2::ADDRESS_ASSIGNMENT, BUFFER_TO_SEND_VAL_1 }},
         L2::ADDRESS_ASSIGNMENT + DELIMITER
      }
   )
)