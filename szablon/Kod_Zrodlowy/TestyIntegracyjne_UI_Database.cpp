TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByOT_BufferToSend_Once)
{
   const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_OT, "bufferToSend", BUFFER_TO_SEND_VAL_1}});
   auto& received = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(received);
   ASSERT_TRUE(received->bufferToSend);
   ASSERT_EQ(received->bufferToSend.value(), BUFFER_TO_SEND_VAL_1);
}