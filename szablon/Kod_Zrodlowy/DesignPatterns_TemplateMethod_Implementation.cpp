MaybeStrings ICommandValidation::execute(Strings userInput)
{
   if (auto successfulyValidatedInput = 
        validateInputCorrectness(userInput))
      return modifyIfRequired(*successfulyValidatedInput);
   return boost::none;
}
