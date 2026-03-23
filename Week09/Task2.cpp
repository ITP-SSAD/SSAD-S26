#include <iostream>
#include <string>

// Product
class Document {
public:
    void setHeader(const std::string& h) { header = h; }
    void setBody(const std::string& b) { body = b; }
    void setFooter(const std::string& f) { footer = f; }
    void show() { std::cout << header << "\n" << body << "\n" << footer << "\n"; }
private:
    std::string header, body, footer;
};

// Builder
class DocBuilder {
public:
    virtual ~DocBuilder() = default;
    virtual void buildHeader() = 0;
    virtual void buildBody() = 0;
    virtual void buildFooter() = 0;
    virtual Document getDoc() = 0;
};

// Concrete Builder
class ReportBuilder : public DocBuilder {
    Document doc;
public:
    void buildHeader() override { doc.setHeader("REPORT HEADER"); }
    void buildBody() override { doc.setBody("This is the report body"); }
    void buildFooter() override { doc.setFooter("Report Footer - Page 1"); }
    Document getDoc() override { return doc; }
};

// Director
class Writer {
    DocBuilder* builder;
public:
    void setBuilder(DocBuilder* b) { builder = b; }
    Document construct() {
        builder->buildHeader();
        builder->buildBody();
        builder->buildFooter();
        return builder->getDoc();
    }
};

// Usage
int main() {
    Writer writer;
    ReportBuilder builder;
    writer.setBuilder(&builder);

    Document doc = writer.construct();
    doc.show();
}
