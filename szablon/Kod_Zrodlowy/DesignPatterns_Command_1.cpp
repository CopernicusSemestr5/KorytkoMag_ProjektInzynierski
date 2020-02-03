class ICommand
{
public:
   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;
   void registerResponseHandler(std::function<void(void)> responseHandler);
   virtual ~ICommand();
protected:
   ICommand();
   using AlmagControllerInformer = boost::signals2::signal<void(void)>;
   AlmagControllerInformer informControllerAboutResult_;
};