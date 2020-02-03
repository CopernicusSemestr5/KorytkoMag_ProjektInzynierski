class ICommandValidation
{
public:
   virtual ~ICommandValidation() = default;
   MaybeStrings execute(Strings userInput);
protected:
   virtual MaybeStrings validateInputCorrectness(Strings userInput) = 0;
   virtual MaybeStrings modifyIfRequired(Strings validatedUserInput) = 0;
};