#ifndef PAGE_H
#define PAGE_H

#include <string>

class Page{
    public:
        Page* PageYes;
        Page* PageNo;
        std::string question;
        std::string photoPath;
        std::string description;
        std::string wikiLink;
        bool isLast;

        Page(bool isLast, std::string question, Page* PY, Page* PN);
        Page(bool isLast, std::string question, std::string photo, std::string description, std::string wiki);
};
#endif