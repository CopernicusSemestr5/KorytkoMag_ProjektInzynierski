ReturnCode CMenu::interpretControllerCommand(const Strings& userInput)
{
   LOG(debug) << "Start";
   if (const auto validatedUserInput = almagCmdValidationMgr_->perform(userInput))
   {
      almagCtrl_->addCommands({*validatedUserInput});
      return almagCtrl_->executeCommand();
   }
   LOG(warning) << "Validation rejected the command";
   return true;
}