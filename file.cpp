#include <iostream>
#include <unordered_map>
#include <string>

class File {
public:
    std::string name;
    std::string content;

    File(const std::string& name) : name(name), content("") {}
};

class FileSystem {
private:
    std::unordered_map<std::string, File> files;

public:
    void createFile(const std::string& name) {
        if (files.find(name) != files.end()) {
            std::cout << "File already exists.\n";
            return;
        }
        files[name] = File(name);
        std::cout << "File '" << name << "' created.\n";
    }

    void writeFile(const std::string& name, const std::string& content) {
        if (files.find(name) == files.end()) {
            std::cout << "File not found.\n";
            return;
        }
        files[name].content = content;
        std::cout << "Written to '" << name << "'.\n";
    }

    void readFile(const std::string& name) {
        if (files.find(name) == files.end()) {
            std::cout << "File not found.\n";
            return;
        }
        std::cout << "Content of '" << name << "':\n" << files[name].content << "\n";
    }

    void deleteFile(const std::string& name) {
        if (files.erase(name)) {
            std::cout << "File '" << name << "' deleted.\n";
        } else {
            std::cout << "File not found.\n";
        }
    }

    void listFiles() {
        if (files.empty()) {
            std::cout << "No files in the system.\n";
            return;
        }
        std::cout << "Files:\n";
        for (const auto& pair : files) {
            std::cout << "- " << pair.first << "\n";
        }
    }
};

int main() {
    FileSystem fs;
    std::string command, filename, content;

    std::cout << "Simple Virtual File System\n";

    