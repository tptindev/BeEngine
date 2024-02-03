#ifndef CXMLPARSER_H
#define CXMLPARSER_H

#include <map>
#include <vector>
#include <string>
#include <tinyxml.h>
#include <optional>

class   CXmlParser
{
private:
    TiXmlElement                                        *m_root;
    TiXmlDocument                                       m_document;
    std::map<std::string,std::vector<TiXmlElement*>>    m_nodes;


private:
    void iterateAllTags(TiXmlElement* e);

public:
    CXmlParser();
    bool loadFile(const char* file);
    const char* rootAttribute(const char* attribute);
    int count(const char* tag);
    const char* tagContentWith(int index, const char* tag);
    const char* parseTagWith(int index, const char* tag, const char* attribute);
    void x();

};

#endif // CXMLPARSER_H
