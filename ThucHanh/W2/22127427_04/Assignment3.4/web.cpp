#include "web.h"

using namespace std;

void User::login()
{
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Welcome, " << username << "!\n";
}

void User::logout()
{
    cout << "Goodbye, " << username << "!\n";
}

void User::viewCart()
{
    cout << "Shopping Cart:" << endl;
    for(int i = 0; i < cart.size(); i++)
    {
        cout << "-" << cart[i] << endl;
    }
}

void User::placeOrder()
{
    if(!cart.empty())
    {
        history.push_back("Order place: " + username);
        cart.clear();  // Clear the cart
        cout << "Order placed successfully!\n";
    } 
    else 
    {
        cout << "Your cart is empty. Add items before placing an order.\n";
    }
}

void User::viewOrderHistory()
{
    cout << "Order history: " << endl;
    for(int i = 0; i < history.size(); i++)
    {
        cout << history[i] <<endl;
    }
}

void Product::view_detail()
{
    cout << "Product Details:" << endl;
    cout << "ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Stock Quantity: " << stockQuantity << endl;
    cout << "Category: " << category << endl;
}

void Product::checkAvailability()
{
    if(stockQuantity > 0)
        cout << "Product is available.";
    cout << "Product is out of stock." << endl;
}

void Product::addToCart()
{
    if(stockQuantity > 0)
    {
        cout << "Added " << name << "to the cart." << endl;
        stockQuantity--;
    }
    else
    cout << "Product is out of stock. Cannot add to the cart." << endl;
}

void Product::removeFromCart()
{
    if(stockQuantity < INT_MAX)
    {
        cout << "Removed " << name << "from the cart." << endl;
        stockQuantity++;
    }
    else
    cout << "Can't remove from the cart. Invalid stock quantity.\n";
}

void Product::getReview()
{
    cout << "Product Reviews: " << endl;
}

void Order::trackOrder()
{
    cout << "Oder ID: " << orderId << " - Status: " << orderStatus << endl;
}

void Order::cancelOrder()
{
    orderStatus = "Cancelled";
    cout << "Oder cancelled successfully." << endl;
}

int Order::getInvoice()
{
    cout << "Invoice for Order ID " << orderId << ":" << endl;
    for (int i = 0; i < items.size(); ++i) 
    {
        cout << "- " << items[i] << endl;
    }

    double taxRate = 0.1; // Assume a tax rate of 10%
    double discount = 0.2; // Assume a discount of 20%

    // total = sum - sum*discount + sum*tax
    double taxAmount = totalPrice * taxRate;
    double discountedPrice = totalPrice - discount*totalPrice + taxAmount;

    cout << "Subtotal: $" << totalPrice << endl;
    cout << "Tax (" << (taxRate * 100) << "%): $" << taxAmount << endl;
    cout << "Discount:" << (discount*100) << "%" << endl;
    cout << "Total: $" << discountedPrice << endl;
    return discountedPrice;
}

void Order::confirmDelivery() 
{
    orderStatus = "Delivered";
    cout << "Order confirmed as delivered." << endl;
}

void Order::calculateTotalPrice() 
{
    totalPrice = 0.0;
    totalPrice = getInvoice();
    cout << "Total Price calculated." << endl;
}

void Payment::processPayment()
{
    cout << "Processing payment..." << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Payment method: " << paymentMethod << endl;
    cout << "Payment processed successfully." << endl;
}

void Payment::verifyPayment()
{
    cout << "Verifying payment..." << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Payment method: " << paymentMethod << endl;

    cout << "Payment verified successfully." << endl;
}

void Payment::generateReceipt()
{
    cout << "Payment Receipt for Order ID " << orderId << ":" << endl;
    cout << "Payment ID: " << paymentId << endl;
    cout << "User ID: " << userId << endl;
    cout << "Order ID: " << orderId << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Receipt generated successfully." << endl;
}

void Payment::refundPayment() 
{
    cout << "Refunding payment..." << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Payment refunded successfully." << endl;
}

void Payment::Update() 
{
    cout << "Updating payment details..." << endl;
    cout << "Payment details updated successfully." << endl;
}

void Review::submitReview()
{
    cout << "Enter your rating (1-5) star:";
    cin >> rating;

    cin.ignore();
    cout << "Enter your comment: ";
    getline(cin, comment);

    reviewId = reviews.size() + 1;
    reviews.push_back(*this);

    cout << "Review submitted successfully.\n";
}

void Review::editReview()
{
    cout << "Enter the review ID you want to edit: ";

    int editID;
    cin >> editID;

    for(int i = 0; i < reviews.size(); i++)
    {
        if (reviews[i].reviewId == editID) 
        {
            cout << "Enter your new rating (1-5): ";
            cin >> reviews[i].rating;

            cout << "Enter your new comment: ";
            cin.ignore(); 
            getline(cin, reviews[i].comment);

            cout << "Review edited successfully." << endl;
            return;
        }
    }
    cout << "Review not found." << endl;
}

void Review::viewReviews()
{
    cout << "Reviews for Product ID " << productId << ":" << endl;

        // Display all reviews for the product
    for (int i = 0; i < reviews.size(); i++)
    {
        if (reviews[i].productId == productId) 
        {
            cout << "Review ID: " << reviews[i].reviewId << endl;
            cout << "Rating: " << reviews[i].rating << "/5" << endl;
            cout << "Comment: " << reviews[i].comment << endl;
            cout << "------------------------" << endl;
        }
    }
}

void Review::deleteReview() 
{
    cout << "Enter the review ID you want to delete: ";
    int deleteId;
    cin >> deleteId;

    for (size_t i = 0; i < reviews.size(); i++) 
    {
        if (reviews[i].reviewId == deleteId) 
        {
            reviews.erase(reviews.begin() + i);
            cout << "Review deleted successfully." << endl;
            return;
        }
    }

    cout << "Review not found." << endl;
}

double Review::averageRating() 
{
    if (reviews.empty()) 
    {
        cout << "No reviews available." << endl;
    }

    double totalRating = 0.0;


    for (int i = 0; i < reviews.size(); i++)
    {
        if (reviews[i].productId == productId) 
        {
            totalRating += reviews[i].rating;
        }
    }

    double average = totalRating / reviews.size();
    cout << "Average Rating: " << average << "/5" << endl;

    return average;
}
