void AlmagControllerNull::addCommands(const StringsMatrix& validatedUserInput)
{ LOG(debug); }

bool AlmagControllerNull::executeCommand()
{ LOG(debug); return true; }

void AlmagControllerNull::handleCommandsResult()
{ LOG(debug); }

std::string AlmagControllerNull::getFinalResultCode()
{ return defaultVals::FOR_STRING; }