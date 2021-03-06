#include <iostream>
#include <filesystem>

#include <unistd.h>
#include <getopt.h>

#include "defs.h"
#include "clean.h"
#include "error.h"


static struct option longopts[] = {
   { "help", no_argument, NULL, 'h' },
   { 0, 0, 0, 0 }
};


static std::string usage()
{
    return "Usage: " NAME " clean [-h]";
}

static std::string help()
{
    const std::string message {
R"message(
Remove autogenerated files. These files are located in '.cp-build' directory of the current folder.
)message" };

    return usage() + message;
}

int remove_autogenerated_files()
{
    static const std::string autogen_files_dir { ".cp-build" };

    try {
        if (std::filesystem::remove_all(autogen_files_dir) == 0)
            std::cout << "No autogenerated files found.\n";
        else
            std::cout << "Done.\n";
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return CP_TOOLS_ERROR_CLEAN_DELETE_FILES;
    }

    return CP_TOOLS_OK;
}

int clean(int argc, char * const argv[])
{
    int option = -1;

    while ((option = getopt_long(argc, argv, "h", longopts, NULL)) != -1)
    {
        switch (option) {
        case 'h':
            std::cout << help() << '\n';
            return 0;

        default:
            std::cout << help() << '\n';
            return CP_TOOLS_ERROR_CLEAN_INVALID_OPTION;
        }
    }

    return remove_autogenerated_files();
}
