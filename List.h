#ifndef LIST_H_
#define LIST_H_

#include <cstddef>      //for NULL
#include <assert.h>     //Halts program if preconditions are not met
#include <iostream>

using namespace std;
template <class listdata>   
//declaring a template with a type parameter named listdata 
//This parameter can be any type that we specify when we use the template 
class List {
    private:
        struct Node{
            listdata data;  //Integer data within the node used to display node usage
            Node *next;     //pointer containing the address of the next node     
            Node *prev;     //pointer conitaing the address of the previous node

            Node(listdata newData){     //Node constructor
                data = newData;         //listdata generic data for new node
                next = NULL;            //initialized next node to null when new node is constructed 
                prev = NULL;            //initailaize prev node to null when new node is constructed
            }
        };
        Node *first;        // the lists reference to the head of the list
        Node *last;         // the lists reference to the tail of the list
        Node *iterator;     // the lists pointer to traverse the it
        int length;         // the length of the list

        /* Accessors */

        bool isSorted(Node *node) const;    
        //helper function for the public isSorted function
        //Recursively checks if the a list is in ascending order
    
    public:


        /****** Constructors & Destructures ******/


        List(); 
        //Default Constructor that initalizes an empty list
        //PostCondition: an instance of an empty list is created

        List(const List &list);
        //Copy Constructor: deep copies an existing list
        //PostCondition: A deep dopy of a list is created

        ~List();
        //Destructor: Frees memory allocated to the list
        //PostCodition: Dynamic memory allocated to create this list object is released 



        /****** Accessors ******/


        listdata getFirst() const;
        //Returns the first node in the list
        //Precondition: the list is not empty

        listdata getLast() const:
        //Returns the last node int the list
        //Precondition: the list is not empty

        bool isEmptyy() const;
        //Determines if the list is empty

        int getLength() const;
        //Returns the length of the list

        listdata getIterator() const;
        // Returns the element current pointed at by the iterator
        // Precondition: the iterator is not NULL

        bool offEnd() const;
        //Returns whether the iterator has reached the end of the list
        //Precondition: Returns true if iterator == NULL else false

        bool operator==(const List &list);
        // compares two lists to determine if the are equal
        //Postcondition: returns true if they're equal, false if the are not

        bool isSorted() const; 
        //wrapper funtion that calls the isSorted helper function to determine if a list is in ascending order or not
        //we consider a list to be sorted if its empty therefore no precondition is needed for this function

        int getIndex() const;
        //Returns the index of where the iterator is currently poiting to
        //Nodes are numbered in 1 based indexing
        //Precondition: iterator is !offEnd()

        int linearSearch(listdata data) const;
        //linearly search the list from head to tail
        //returns the index of the element if it is found in the list
        //returns -1 if element is not in the list
        //Precondition: the length of the list is not 0 
        //Postcondition: the iterator location has not been moved



        /****** Manipulators ******/


        void removeFirst();
        //Removes the value stored in the first element of the list
        //Precondition: the list is not empty
        //Postcondition: the value in the first node is now removed from the list

        void removeLast();
        //Removes the value stored in the last element of the list
        //Precodition: the list is not empty
        //PostConditon: the value in the last node is now removed from the list

        void insertFirst(listdata data);
        //Inserts new data at the beginning of the list
        //if the list is empty, the insert node becomes the new head and tail of the list
        //PostCondition: The new data is now in the front position of the list

        void insertLast(listdata data);
        // Inserts new data at the tail of the list
        // if the list is empty the new data becomes both the head and the tail of the list 
        // Postcondition: the new data is now at the last position of the list

        void startIterator();
        // points the iterator at the beginning of the list
        // Postcondition: The iterator is poiting at the first data in the list

        void removeIterator();
        // Removes the data at which the iterator is pointing to
        // Precondition: iterator != NULL
        // Postcondition: The data where the iterator was pointing is removed & iterator == NULL

        void insertIterator(listdata dat);
        // Inserts new data after the iterator
        //Precondition: iterator != NULL
        // Postconditon: A new node has been inserted after the iterator

        void advanceIterator();
        // Advances the iterator by one node in the list
        // Precondition: iterator != NULL
        // postCondition: The iterator has moved by one position forward

        void reverseIterator();
        // Reverse the iterator by one node in the list
        // Preconditon: iterator != NULL
        // Postcondition: the iterator has moved by one position in reverse

        void advanceToIdex(int index);
        //moves the iterator the index specified in the parameter
        // Nodes are 1 based indexed 
        // Precondition: size != 0
        // Postcondition: index <= size

        /****** Additional List Operators ******/

        List &operator=(const List &list);
        //overload the = operator

        void printList(ostream &out) const;
        //Takes the ostream type and outputs the value of each fata in the list sequentially

        void printNameNumberedList(ostream &out) const;
        // print the first and last name of Users in the list

        void printNumberedList() const;
        // Prints content of the list
        // format "# <element>" followed by a newLine

        void printInterests(ostream &out) const;
        //printst the interests of the users

        void printNamesAtInterests(ostream &out) const;
        // Prints users from the Interest Table based on the index

};
    //defines that the class "List" is a template clas, and it has a parameter named 'listdata' which means that the class can be used with different data types.
    // List<int> intList or List<string> stringList
    template <class listdata>
    List<listdata>::List(){
        head = NULL;
        tail = NULL;
        iterator = NULL;
        length = 0;
    }

    template <class listdata>
    List<listdata>::List(const List &list){
        //precondition list cannot be empty
        if(list->head==NULL){
            head = tail = iterator = NULL;
        }else{
            head = new Node(list->head->data);  //create a new head node with the data from the head of the original list
            Node *temp = list->head;            //set up a temp pointer to the head of the original list 
            iterator = head;                    //set the iterator to point to the head of the new list

            while(temp->next != NULL){                          //iterate the original list so we can copy it 
                temp = temp->next;                              //advance to the next node in the original list
                iterator->next = new Node(temp->data);          //connect the next pointer of the new list to a new node created with the data of the original list
                iterator->next->prev = iterator;                //connecting the new node's prev to point back to where the iterator is
                iterator = iterator->next;                      //advance the iterator to the new node connected 
            }
            tail = iterator;                    //iterator should be at the end of the list so now the tail should be where the iterator is
            iterator = NULL;                    //should not leave iterator anywhere unexepected
        }
        length = list.length;                   //copy the length of the original list to the new length 
    }

    template <class listdata>
    List<listdata>::~List(){
        Node *iterator = head;
        Node *dummy = NULL;
        while(iterator != NULL){
            dummy = iterator->next; //make dummy point to the iterators next
            delete iterator;        //delete the node pointed to by the iterator 
            iterator = dummy;       //reuse the iterator to point back to the dummy 
        }
    }

    template <class listdata>
    listdata List<listdata>::getFirst() const{
        assert(length != 0); //program halts execution if list is empty
        return head->data;
    }

    template <class listdata>
    listdata List<listdata>::getLast() const{
        assert(length != 0);
        return tail->data;
    }

    template <class listdata>
    bool List<listdata>::isEmptyy() const{
        return length == 0;
    }

    template <class listdata>
    int List<listdata>::getLength() const{
        return length;
    }

    template <class listdata>
    listdata List<listdata>::getIterator() const{
        assert(!offEnd());
        return iterator->data;
    }

    template <class listdata>
    bool List<listdata>::offEnd() const{
        return iterator == NULL;
    }
    

#endif /* LIST_H_*/