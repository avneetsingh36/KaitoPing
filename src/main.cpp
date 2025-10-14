#include<openai/openai.hpp>
#include<iostream>

int main() 
{
  try {
    
    // initializes the client wrapper with the read in API key from my local .env
    openai::start();
    std::cout << "OpenAI Client Successfully Created.\n\n";

    // build the request body in json
    openai::Json req {
      {"model", "gpt-5"},
      {"messages", openai::Json::array({
          {{"role", "system"}, {"content", "You just respond with just 'TEST' for now."}},
          {{"role", "user"}, {"content", "Test Request"}}
          })}
    };

    // makes the HTTP call through client wrapper
    openai::Json res = openai::chat().create(req);

    std::cout << res.dump(2) << '\n';


  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "Unknown Error!" << '\n';
  }
}
