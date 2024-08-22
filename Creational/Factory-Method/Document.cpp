#include <iostream>
#include <memory>

// Product Interface
class Document {
public:
    virtual void print() const = 0;  // Pure virtual function
    virtual ~Document() = default;   // Virtual destructor
};

// Concrete Product: Report
class Report : public Document {
public:
    void print() const override {
        std::cout << "Printing Report document." << std::endl;
    }
};

// Concrete Product: Invoice
class Invoice : public Document {
public:
    void print() const override {
        std::cout << "Printing Invoice document." << std::endl;
    }
};

// Creator (Factory Method) Interface
class DocumentCreator {
public:
    virtual std::unique_ptr<Document> createDocument() const = 0;  // Factory Method
    virtual ~DocumentCreator() = default;
};

// Concrete Creator: Report Creator
class ReportCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> createDocument() const override {
        return std::make_unique<Report>();
    }
};

// Concrete Creator: Invoice Creator
class InvoiceCreator : public DocumentCreator {
public:
    std::unique_ptr<Document> createDocument() const override {
        return std::make_unique<Invoice>();
    }
};

// Client code
void clientCode(const DocumentCreator &creator) {
    // The client code works with an instance of a creator,
    // but the concrete product's class is determined by the subclass.
    std::unique_ptr<Document> doc = creator.createDocument();
    doc->print();
}

int main() {
    // Create a Report using the ReportCreator
    std::cout << "Client: I'm creating a Report." << std::endl;
    ReportCreator reportCreator;
    clientCode(reportCreator);

    // Create an Invoice using the InvoiceCreator
    std::cout << "Client: I'm creating an Invoice." << std::endl;
    InvoiceCreator invoiceCreator;
    clientCode(invoiceCreator);

    return 0;
}
