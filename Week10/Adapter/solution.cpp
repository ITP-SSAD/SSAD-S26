
#include <iostream>
#include <unordered_map>

using namespace std;

class PaymentProvider {
public:
    virtual void processPayment(string paymentInfo) = 0;
    virtual void handleRefund(string refundInfo) = 0;
    virtual bool verifyPayment(string transactionId) = 0;
};

class PayPal {
public:
    void makePayment(string item) {
        cout << "Making PayPal payment for item: " << item << endl;
    }

    bool verifyPayment(string transactionId) {
        cout << "Verifying PayPal payment with transaction ID: " << transactionId << endl;
        return true;
    }

    void refundPayment(string item) {
        cout << "Refunding PayPal payment for item: " << item << endl;
    }
};


class PayPalAdapter: public PaymentProvider{
private:
    PayPal* paypal;

public:
    PayPalAdapter(PayPal* paypal) {
        this->paypal = paypal;
    }

    void processPayment(string item) override {
        paypal->makePayment(item);
    }

    bool verifyPayment(string transactionId) override {
       return paypal->verifyPayment(transactionId);
    }

    void handleRefund(string item) override {
        paypal->refundPayment(item);
    }
};

class Stripe {
public:
    void chargePayment(string item) {
        cout << "Charging Stripe payment for item: " << item << endl;
    }

    bool verifyCharge(string transactionId) {
        cout << "Verifying Stripe payment with transaction ID: " << transactionId << endl;
        return true;
    }

    void issueRefund(string item) {
        cout << "Issuing Refund for Stripe payment for item: " << item << endl;
    }
};

class StripeAdapter: public PaymentProvider {
private:
    Stripe* stripe;

public:
    StripeAdapter(Stripe* stripe) {
        this->stripe = stripe;
    }

    void processPayment(string item) override {
        stripe->chargePayment(item);
    }

    bool verifyPayment(string transactionId) override {
        return stripe->verifyCharge(transactionId);
    }

    void handleRefund(string item) override {
        stripe->issueRefund(item);
    }
};

class PaymentGateWay {
private:
    unordered_map<string, PaymentProvider*> paymentProviders;

public:
    void addPaymentProvider(string providerName, PaymentProvider* provider) {
        paymentProviders[providerName] = provider;
    }

    void processPayment(string providerName, string item) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->processPayment(item);
        } else {
            cout << "Payment provider not found: " << providerName << endl;
        }
    }

    void verifyPayment(string providerName, string transactionId) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->verifyPayment(transactionId);
        } else {
            cout << "Payment provider not found: " << providerName << endl;
        }
    }

    void refundPayment(string providerName, string item) {
        if (paymentProviders.find(providerName) != paymentProviders.end()) {
            paymentProviders[providerName]->handleRefund(item);
        } else {
            cout << "Payment provider not found: " << providerName << endl;
        }
    }
};

int main() {
    PayPalAdapter* paypalAdapter = new PayPalAdapter(new PayPal());
    StripeAdapter* stripeAdapter = new StripeAdapter(new Stripe());

    PaymentGateWay paymentGateWay;
    paymentGateWay.addPaymentProvider("STRIPE", stripeAdapter);
    paymentGateWay.processPayment("STRIPE", "SHEIN-SHOES");
    paymentGateWay.verifyPayment("STRIPE", "transactionId:001001");
    paymentGateWay.refundPayment("STRIPE", "Refund SHEIN-SHOES");
    cout << endl;
    paymentGateWay.addPaymentProvider("PAYPAL", paypalAdapter);
    paymentGateWay.processPayment("PAYPAL", "KAZAN-EXPRESS-HATS");
    paymentGateWay.verifyPayment("PAYPAL", "transactionId:061041");
    paymentGateWay.refundPayment("PAYPAL", "Refund KAZAN-EXPRESS-HATS");

    delete paypalAdapter;
    delete stripeAdapter;

    return 0;
}

