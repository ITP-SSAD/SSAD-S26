#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Text interface
class Text {
public:
    virtual string write() const = 0;
    virtual ~Text() {}
};

// PlainText class
class PlainText : public Text {
private:
    string text;
public:
    PlainText(const string& text) : text(text) {}
    string write() const override {
        return text;
    }
};

// TextDecorator abstract class
class TextDecorator : public Text {
protected:
    shared_ptr<Text> wrappedText;
public:
    TextDecorator(shared_ptr<Text> text) : wrappedText(text) {}
    virtual string write() const override {
        return wrappedText->write();
    }
};

// Bold decorator
class Bold : public TextDecorator {
public:
    Bold(shared_ptr<Text> text) : TextDecorator(text) {}
    string write() const override {
        // ANSI escape code for bold text
        return "\033[1m" + TextDecorator::write() + "\033[0m";
    }
};

// Italic decorator
class Italic : public TextDecorator {
public:
    Italic(shared_ptr<Text> text) : TextDecorator(text) {}
    string write() const override {
        // ANSI escape code for italic text
        return "\033[3m" + TextDecorator::write() + "\033[0m";
    }
};

// Underline decorator
class Underline : public TextDecorator {
public:
    Underline(shared_ptr<Text> text) : TextDecorator(text) {}
    string write() const override {
        // ANSI escape code for underline text
        return "\033[4m" + TextDecorator::write() + "\033[0m";
    }
};

int main() {
    // Plain text
    shared_ptr<Text> plainText = make_shared<PlainText>("Hello, World!");

    // Adding decorators dynamically
    shared_ptr<Text> boldText = make_shared<Bold>(plainText);
    shared_ptr<Text> italicBoldText = make_shared<Italic>(boldText);
    shared_ptr<Text> underlinedItalicBoldText = make_shared<Underline>(italicBoldText);

    // Display styled text
    cout << plainText->write() << endl;
    cout << boldText->write() << endl;
    cout << italicBoldText->write() << endl;
    cout << underlinedItalicBoldText->write() << endl;

    return 0;
}
