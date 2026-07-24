#include <filesystem>
#include <iostream>
#include <queue>

int main(int argc , char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: list <path>" << std::endl;
        return 1;
    }
    const std::filesystem::path path = argv[1];
    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
    {
        std::cerr << "Invalid path!!" << std::endl;
    }
    std::queue<std::filesystem::path> queue;
    queue.push(path);
    while (!queue.empty())
    {
        const std::filesystem::path current = queue.front();
        queue.pop();
        for (const auto &entry : std::filesystem::directory_iterator(current))
        {
            if(std::filesystem::is_directory(entry.path()))
                queue.push(entry.path());
            else
                std::cout << entry.path() << std::endl;
        }
    }
}