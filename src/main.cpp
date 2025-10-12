#include<openai/openai.hpp>
#include<iostream>

int main() 
{
  try {
    
    // initializes the client wrapper with the read in API key from my local .env
    openai::start();

    std::cout << "OpenAI Client Successfully Created.\n";

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  } catch (...) {
    std::cerr << "Unknown Error!" << '\n';
  }
}
