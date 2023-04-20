package Java.test;

import java.util.NoSuchElementException;

/**
 * Implementation of a Stack
 * Uses the doubly linked list defined in DLinkedList.java (and DLink.java) 
 **/
public class StackDLinkedList {
    /*
     * The top of the stack (head of the doubly linked list)
     */
    private DLink head;
    // no need for tail
    
    /*
     * Constructor
     * Sets the top of the stack to null
     */
    public StackDLinkedList() {
        this.head = null;        
    }

    /**
     * Returns the integer at the top of the stack
     * @return - the Integer at the top of the stack
     */
    public DLink getHead() {
        return this.head;
    }

    /**
     * Checks if the stack is empty.
     * @return true if the stack is empty, false otherwise
     */
    public boolean isEmpty() {
        return (this.head == null);
    }

    /**
     * Pushes an element onto the stack
     * @param item the element to push onto the stack
     * @throws NullPointerException if the element is null
     */
    public void push(Integer item) throws NullPointerException {
        if(item == null) {
            throw new NullPointerException("Null element passed as parameter to push");
        } else {
            if(this.head == null) {
                this.head = new DLink(item, null, null);
            } else {
                DLink temp = new DLink(item, this.head, null);
                this.head.setPrev(temp);
                this.head = temp;
            }
        }
    }

    /**
     * Removes and returns the top element of the stack
     * @return Integer - the top element of the stack
     * @throws NoSuchElementException if the stack is empty
     */
    public Integer pop() throws NoSuchElementException {
        if (this.head == null) {
            throw new NoSuchElementException("Stack is empty");
        }
        Integer temp = this.head.getElement();
        this.head = this.head.getNext();
        if(this.head != null) {
            this.head.setPrev(null);
        }
        return temp;
    }

    /**
     * Returns the top element of the stack but does not remove it
     * @return the top element of the stack
     * @throws NoSuchElementException if the stack is empty
     */
    public Integer peek() throws NoSuchElementException {
        if(this.head == null) {
            throw new NoSuchElementException("Stack is empty");
        }
        return this.head.getElement();
    }
}