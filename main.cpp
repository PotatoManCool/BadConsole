#include <iostream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;


string getCommand(string input){
    string out;
    for(int i = 0;i<4;i++){
        out.push_back(input[i]);
    }
    return out;
}

string getArgs(string input){
    string out;
    for(int i = 5;i<input.size();i++){
        out.push_back(input[i]);
    }
    return out;
}

typedef basic_string<wchar_t> wstring;

//код из stack overflow https://stackoverflow.com/questions/875249/how-to-get-current-directory
std::string GetExeFileName()
{
  char buffer[MAX_PATH];
  GetModuleFileName( NULL, buffer, MAX_PATH );
  return std::string(buffer);
}

std::string GetExePath() 
{
  std::string f = GetExeFileName();
  return f.substr(0, f.find_last_of( "\\/" ));
}

int main(int argc, char * argv[]){
    bool running = 1;
    string input, command, args;
    string currDir;

    //Стандарт комманд - 4 символа
    map<string, string> commands;
    commands["echo"] = "it's make echo";
    commands["what"] = "It's show description for command";
    commands["cler"] = "It's clear terminal";
    commands["exit"] = "It's exit from console";
    commands["help"] = "It's show all commands";
    commands["sysc"] = "It's do standart windows commands";

    while (running)
    {
        cout << GetExePath() << "$ ";
        input = "";
        getline(cin, input);
        command = getCommand(input);
        args = getArgs(input);

        if(command == "echo"){
            cout << args << '\n';
        }
        else if(command == "what"){
            cout << commands[args] << '\n';
        }
        else if(command=="cler"){
            system("cls");
        }
        else if(command=="exit"){
            cout << "exiting..." << "\n";
            break;
        }
        else if(command=="help"){
            cout << "to get more info type: what <command>\n";
            for(const auto i : commands){
                cout << i.first << "\n";
            }
        }
        else if(command=="sysc"){
            const char* call = args.c_str();
            system(call);
        }
        else{
            cout << command << ": command not found\n";
        }
    }
    
    return 0;
}