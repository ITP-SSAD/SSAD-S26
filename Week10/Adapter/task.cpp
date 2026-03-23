#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

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

class PaymentProvider {
    // implementation of PaymentProvider class
};

class PaymentGateWay {
private:
    unordered_map<string, PaymentProvider *> paymentProviders;

public:
    PaymentGateWay() {
        paymentProviders = unordered_map<string, PaymentProvider *>();
    }
    void addPaymentProvider(string providerName, PaymentProvider *paymentProvider) {
        paymentProviders[providerName] = paymentProvider;
    }
    void processPayment(string providerName, string paymentInfo) {
        // implementation of processPayment method
    }
    void refundPayment(string providerName, string refundInfo) {
        // implementation of refundPayment method
    }
    void verifyPayment(string providerName, string paymentInfo) {
        // implementation of verifyPayment method
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
