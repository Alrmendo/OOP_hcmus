#ifndef SHOPEE_H
#define SHOPEE_H
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

class User
{
public:
    int user_id;
    string username;
    string email;
    vector<string> cart;
    vector<string> history;

    void login();
    void logout();
    void viewCart();
    void placeOrder();
    void viewOrderHistory();

};

class Product
{
public:
    int productId;
    string name;
    double price;
    int stockQuantity;
    string category;

    void view_detail();
    void checkAvailability();
    void addToCart();
    void removeFromCart();
    void getReview();
};

class Order
{
public:
    int orderId;
    int userId;
    vector<string> items;
    double totalPrice;
    string orderStatus;

    void trackOrder();
    void cancelOrder();
    int getInvoice();
    void confirmDelivery();
    void calculateTotalPrice();
};

class Payment
{
public:
    int paymentId;
    int userId;
    int orderId;
    string paymentMethod;
    double amount;

    void processPayment();
    void verifyPayment();
    void generateReceipt();
    void refundPayment();
    void Update();
};

class Review
{
public:
    int reviewId;
    int userId;
    int productId;
    int rating;
    string comment;
    vector<Review> reviews; 

    void submitReview();
    void editReview();
    void deleteReview();
    void viewReviews();
    double averageRating();
};

#endif
