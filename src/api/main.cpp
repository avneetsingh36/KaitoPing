#include<openai/openai.hpp>
#include<iostream>
#include<format>
#include<string>
#include <string_view>

void run(const std::string& instr, const std::string& message){
  try {
    // initializes the client wrapper with the read in API key from my local .env
    openai::start();
    std::cout << "OpenAI Client Successfully Created.\n\n";

    // build the request body in json
    openai::Json req {
      {"model", "gpt-5"},
      {"messages", openai::Json::array({
          {{"role", "system"}, {"content", instr}},
          {{"role", "user"}, {"content", message}}
          })}
    };

    // makes the HTTP call through client wrapper
    openai::Json res = openai::chat().create(req);

    // uncomment if you want to see the entire json response
    // std::cout << res.dump(2) << '\n';

    if (!res.contains("choices") || res["choices"].empty())
      throw std::runtime_error("No choices returned");
    
    std::cout << std::format("Model: {}", res["model"].get<std::string>()) << '\n';
    std::cout << std::format("Message: {}", res["choices"][0]["message"]["content"].get<std::string>()) << '\n';

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "Unknown Error!" << '\n';
  }
}

int main(int argc, char* argv[]) 
{
  if (argc != 3){
    std::cout << "You didn't input a message or instruction.";
    return 1;
  }

  std::string instr = argv[1];
  std::string message = argv[2];
  std::cout << message << '\n';

  run(instr, message);

  return 0;
}
