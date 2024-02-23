#include "web.h"

using namespace std;

int main()
{
    User user;
    user.login();
    user.viewOrderHistory();

    user.logout();

    Product laptop;
    laptop.productId = 1;
    laptop.name = "Laptop";
    laptop.price = 999.99;
    laptop.stockQuantity = 10;
    laptop.category = "Electronics";

    laptop.view_detail();
    laptop.checkAvailability();
    laptop.addToCart();
    laptop.removeFromCart();
    laptop.getReview();

    Order order;
    order.orderId = 123;
    order.items = {"Product 1", "Product 2", "Product 3"};
    order.totalPrice = 500.0;

    order.getInvoice();

    Payment payment;
    payment.paymentId = 456;
    payment.userId = 789;
    payment.orderId = 123;
    payment.paymentMethod = "Credit Card";
    payment.amount = 100.0;

    payment.processPayment();
    payment.verifyPayment();
    payment.generateReceipt();
    payment.refundPayment();
    payment.Update();

    Review review;
    review.productId = 123;

    review.submitReview();
    review.editReview();
    review.viewReviews();
    review.averageRating();

    return 0;
}
