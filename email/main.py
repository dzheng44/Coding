import pymysql

import random

connection = pymysql.connect(host="localhost", user="root", password="", database="book_store")
cursor = connection.cursor()


# Will add sql calls into the init to add to database
class User:
    def __init__init(self, name, username, password, address, city, state, zip, paymentinfo, shippinginfo):
        self.name = name
        self.username = username
        self.password = password
        self.address = address
        self.city = city
        self.state = state
        self.zip = zip
        self.paymentinfo = paymentinfo
        self.shippinginfo = shippinginfo

    def RegisterUser(self):
        # gathering user information
        name = input("What is your name? ")
        username = input("What is your username? ")
        password = input("What is your password? ")
        address = input("What is your address? ")
        city = input("What is your city? ")
        state = input("What is your state? ")
        zip = input("What is your zip code? ")
        paymentinfo = input("What is your payment type (Card or Cash)? ")
        shippinginfo = input("What is your shipping address? ")
        print("Account created: " + username + "\n" + "#############################" + "\n")

        # Query to add a user into the database
        new_user = "INSERT INTO `user_info` (`Name`, `Username`, `Password`, `Address`, `City`, `State`," \
                   " `Zip Code`, `Payment Info`, `Shipping Info`) VALUES (%s,%s,%s,%s,%s,%s,%s,%s,%s)"
        cursor.execute(new_user, (name, username, password, address, city, state, zip, paymentinfo, shippinginfo))
        connection.commit()


def DeleteUser(username):
    # query to delete user from database
    sql = "DELETE FROM `user_info` WHERE Username = %s"
    cursor.execute(sql, (username))
    connection.commit()
    sql = "DELETE FROM `cart_history` WHERE Username = %s"
    cursor.execute(sql, (username))
    connection.commit()



class Books:
    def __init__(self, title, author, genre, isbn, price):
        self.title = title
        self.author = author
        self.genre = genre
        self.isbn = isbn
        self.price = price

    def updateprice(self, new_price):
        # This needs to be testedchange for the database.
        self.price = new_price


class Inventory(Books):
    def __init__(self, title, author, genre, isbn, stock, price):
        self.title = title
        self.author = author
        self.genre = genre
        self.isbn = isbn
        self.stock = stock
        self.price = price
        # Call a sql query to the book database and add a book

    ## This would do a sql query where it would search the inventory database and using the isbn, search the book database
    def viewInventory(self):
        cursor.execute("SELECT books.BookName, books.Author, books.Genre, books.ISBN, books.Price, inventory.Stock FROM books, inventory WHERE books.ISBN = inventory.ISBN")
        outputbooks = cursor.fetchall()

        print('\n')
        print('###################################################')
        print('Viewing all books')
        print('Book Title, Author, Genre, ISBN, Price, Stock')
        print('###################################################')
        for books in outputbooks:
            print(books[0], ',', books[1], ',', books[2], ',', books[3], ',', books[4], ',', books[5], '\n')

        connection.commit()

    # This will give an error if you type in the wrong ISBN when you add to cart.
    def decreaseStock(self, username):
        cursor.execute('SELECT `ISBN` FROM `cart` WHERE `Username` = %s', (username,))
        result = cursor.fetchall()
        findISBN = result[0][0]

        cursor.execute('SELECT `Stock` FROM `inventory` WHERE `ISBN` =  %s', (findISBN,))
        result = cursor.fetchall()
        invenstock = result[0][0]

        cursor.execute('SELECT `Stock` FROM `cart` WHERE `Username` = %s', (username,))
        result = cursor.fetchall()
        cartstock = result[0][0]

        invenstock -= cartstock

        cursor.execute('UPDATE `inventory` SET `Stock` = %s WHERE `ISBN` = %s', (invenstock, findISBN))

        connection.commit()


class Cart():
    def __init__(self, username, cartNumber, title, isbn, number, price, total):
        self.username = username
        self.cartNumber = cartNumber
        self.title = title
        self.isbn = isbn
        self.number = number
        self.price = price
        self.total = total

    def viewCart(self, username):
        cursor.execute('SELECT * FROM `cart` WHERE `Username` = %s', (username))
        outputcart = cursor.fetchall()
        print("\n")
        for books in outputcart:
            print(books, "\n")

        connection.commit()

    def emptyCart(self, username):
        cursor.execute('DELETE FROM `cart` WHERE `Username` = %s', (username))
        connection.commit()


class cart_history():
    def __init__(self, cartnum, ISBN, quantity, total_price, username):
        self.cartnum = cartnum
        self.ISBN = ISBN
        self.quantity = quantity
        self.total_price = total_price
        self.username = username

    def addhistory(self, username):
        cartnum = random.randint(1, 1200)

        cursor.execute('SELECT `ISBN` FROM `cart` WHERE `Username` = %s', (username))
        isbn = cursor.fetchall()

        cursor.execute('SELECT `Stock` FROM `cart` WHERE `Username` = %s AND `ISBN` = %s', (username, isbn))
        stock = cursor.fetchall()
        total_price = stock[0][0] * 10.99

        cursor.execute("INSERT INTO `cart_history`(`cart_number`, `ISBN`, `quantity`, `total_price`, `username`) VALUES (%s,%s,%s,%s,%s)",
            (cartnum, isbn, stock, total_price, username))
        connection.commit()

        # print this for user
        print("Cart number is ", cartnum)



    def viewhistory(self, username):
        # This shows the past orders
        print("Cart Number, ISBN, Quantity")
        cursor.execute(
            "SELECT `cart_number`, `ISBN`, `quantity` FROM `cart_history` WHERE `username` = %s",(username))
        outputhist = cursor.fetchall()

        for hist in outputhist:
            print(hist[0], ',', hist[1], ',', hist[2])

        # This part calculates the overall total of a particular order
        cart_num = int(input("What is the cart number you would like to view? "))
        cursor.execute('SELECT `quantity` FROM `cart_history` WHERE `cart_number` = %s', (cart_num,))
        result = cursor.fetchall()
        print("How many books did you order in total for order", cart_num, "?")
        cart_quant = int(input(''))

        total_price = cart_quant * 10.99
        print('Your total for cart number', cart_num, 'is: ', total_price)
        connection.commit()



def main():
    # This menu table is for the menu system to print out the message/options
    menu = {}
    menu['1'] = "View User Information "
    menu['2'] = "Cart Information "
    menu['3'] = "Checkout Cart "
    menu['4'] = "View Store Items "
    menu['5'] = "Log out"

    while True:
        print("Welcome to the store!")
        print(" 1 -- Login")
        print(" 2 -- Register User")
        print(" 3 -- Exit")
        pre_login = int(input("How can we help you? "))

        # It'll gather the username and password; then compare to the database and output an error otherwise
        if pre_login == 1:
            # This is the login menu
            # This is the variable keeping us in the store menu
            store_in = True
            while True:
                print("\nEnter Username and Password")
                username = input("Username: ")
                password = input("Password: ")

                # part after this will have to check the database and call break if it is in the database to exit this while loop
                cursor.execute('SELECT * FROM user_info WHERE username = %s AND password = %s', (username, password,))
                # Fetch one record and return result
                userexist = cursor.fetchone()

                if userexist:
                    break
                else:
                    print("Incorrect username or password \n")
                    store_in = False
                    break

            # This is the store menu
            while store_in:
                # Make main menu look nicer
                print("\n" + "###########")
                print("Home Page")
                print("###########")

                for key in menu.keys():
                    print(key, '--', menu[key])

                # User will decide/input option
                choice = int(input("Please Select: "))
                # Once User has inputted their choice, check for path

                # choice 1 goes into the User Menu to edit info, delete user account, and view past orders.
                if choice == 1:
                    print("\n" + "###########")
                    print("User Menu")
                    print("###########")
                    print(
                        "1 -- Edit Shipping info\n2 -- Edit Payment method\n3 -- Delete account\n4 -- View Order History\n5 -- Exit")

                    choice = int(input("Please Select: "))

                    if choice == 1:
                        new_ship = input("What is the new shipping address? ")
                        ship_command = 'UPDATE `user_info` SET `Shipping Info` = %s WHERE Username = %s'
                        cursor.execute(ship_command, (new_ship, username))
                        connection.commit()
                        print("Info has been edited.\n")
                    elif choice == 2:
                        new_pay = input("What is the new payment method? ")
                        pay_command = 'UPDATE `user_info` SET `Payment Info` = %s WHERE Username = %s'
                        cursor.execute(pay_command, (new_pay, username))
                        connection.commit()
                        print("Info has been edited.\n")
                    elif choice == 3:
                        confirm = input("Are you sure you want to delete this account (y/n)? ")
                        if confirm == "y":
                            DeleteUser(username)
                            print("User Account Deleted.")
                            # User no longer exist, exit store
                            store_in = False
                    elif choice == 4:
                        print('\n',"#########################")
                        print(username, " - Viewing Past Orders")
                        print("#########################", '\n')
                        viewhist = cart_history(None, None, None, None, username)
                        viewhist.viewhistory(username)
                    elif choice == 5:
                        print("Exiting User Menu")
                    else:
                        print("Invalid Menu option. Please try again!")

                # Cart menu
                elif choice == 2:
                    cart_in = True
                    while cart_in:
                        print("\n" + "###########")
                        print("Cart Menu")
                        print("###########")
                        print("1 -- Add item to Cart\n2 -- Remove a item from Cart\n3 -- View Cart\n4 -- Exit")
                        cart_input = int(input("What would you like to do with your cart? "))
                        if cart_input == 1:
                            addItem = input("What is the book's ISBN? ")
                            itemstock = int(input("How many would you like to add to cart? "))
                            if itemstock <= 0:
                                print("Please enter value greater than 0.")
                                break
                            else:
                                item_add = 'INSERT INTO `cart` (`Username`,`ISBN`, `Stock`,`Price`) VALUES (%s, %s, %s,"10.99")'
                                cursor.execute(item_add, (username, addItem, itemstock,))
                                connection.commit()
                                print("Item has been added to the cart!\n")
                        elif cart_input == 2:
                            removeItem = input("What is the book's ISBN to be removed? ")
                            cursor.execute('DELETE FROM `cart` WHERE ISBN = %s', (removeItem))
                            print("Item has been removed from the cart!\n")
                        elif cart_input == 3:
                            print('\n', '####################')
                            print("Viewing your cart")
                            print('####################')

                            view_cart = Cart(username, None, None, None, None, None, None)
                            view_cart.viewCart(username)
                        elif cart_input == 4:
                            print("Exiting Cart Menu")
                            cart_in = False
                        else:
                            print("Invalid Menu option. Please try again!")

                elif choice == 3:
                    print ('\n',"################")
                    print("Checkout Cart")
                    print ("################", '\n')

                    buy_cart = input("Would you like to buy this cart? y/n ")
                    ### change stock, save to past orders, clear cart/database
                    if buy_cart == 'y':
                        cartnum = random.randint(1, 1200)
                        cartlen = cursor.execute('SELECT cart.ISBN FROM `cart`')

                        print("Cart Bought!")

                        carted = Inventory(None, None, None, None, None, None)
                        carted.decreaseStock(username)
                        # Still runs with single item carts
                        for x in range(cartlen):
                            addtohist = cart_history(None, None, None, None, None)
                            addtohist.addhistory(username, cartnum)
                        empty_cart = Cart(None, None, None, None, None, None, None)
                        empty_cart.emptyCart(username)

                        # print this for user
                        print("Cart number is ", cartnum)

                    elif buy_cart == 'n':
                        print("Exiting Checkout!\n")
                    else:
                        break
                elif choice == 4:
                    print("View Store Items")

                    view = Inventory(None, None, None, None, None, None)
                    view.viewInventory()
                    # This exits the menu; not the program
                elif choice == 5:
                    print("You have been logged out.\n")
                    # Could have used break here instead as it would have left the loop, but this is more clean and consistent (look at user menu)
                    store_in = False
                else:
                    print("Invalid Menu option. Please try again!")

        # This will create a new user just by calling the class
        elif pre_login == 2:
            New_user = User()
            New_user.RegisterUser()

        # Will exit the program
        elif pre_login == 3:
            print("Have a nice day!")
            break


main()

connection.close()