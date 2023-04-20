package Java.test;

/**
 * The doubly linked list implementation
 */
public class DLinkedList {
    
    /**
     * head of the doubly linked list.
     */
    private DLink head;
    
    /**
     * tail of the doubly linked list.
     */
    private DLink tail;

    /**
     * Constructs an empty doubly linked list.
     */
    public DLinkedList() {
        this.head = null;
        this.tail = null;
    } 

    /**
     * Adds an element to the beginning of the doubly linked list
     * @param e the element to add
     */
    public void addFirst(Integer e) {
        DLink newHead = new DLink(e, null, null);
        if(this.head == null) {
            this.tail = newHead;
            this.head = newHead;
        } else {
            newHead.setNext(this.head);
            this.head.setPrev(newHead);
            this.head = newHead;
        }
    }

    /**
     * Adds an element to the end of the doubly linked list
     * @param e the element to add
     */
    public void addLast(Integer e) {
        DLink newTail = new DLink(e, null, null);
        if(this.tail == null) {
            this.head = newTail;
            this.tail = newTail;
       } else {
            this.tail.setNext(newTail);
            newTail.setPrev(this.tail);
            this.tail = newTail;
       }
    }

    /**
     * Sets the head of the doubly linked list
     * @param newHead the new head of the list
     */
    public void setHead(DLink newHead) {
        this.head = newHead;
    }

    /**
     * Sets the tail of the doubly linked list.
     * @param newTail the new tail of the doubly linked list
     */
    public void setTail(DLink newTail) {
        this.tail = newTail;
    }

    /**
     * Returns the first element of the list
     * @return the first element of the list
     */
    public Integer getFirst() {
        return this.head.getElement();
    }

    /**
     * Returns the last element of the list
     * @return the last element of the list
     */
    public Integer getLast() {
        return this.tail.getElement();
    }

    /**
     * Removes a referenced node from the list
     * @param toRemove the referenced node to be removed
     */
    public void remove(DLink toRemove) {
        if(toRemove == null) {
            return;
        }
        
        if(this.head == toRemove) {
            this.head = this.head.getNext();
            if(this.head != null) {
                this.head.setPrev(null);
            }
        } else if(this.tail == toRemove) {
            this.tail = this.tail.getPrev();
            this.tail.setNext(null);
        } else {
            DLink temp = this.head.getNext();
            // need to check temp != null,
            // otherwise the loop would run forever
            // if the referenced node was not in t
            while(temp != toRemove && temp != null) {
                temp = temp.getNext();
            }
            if(temp != null) {
                // we essentially forget about the toRemove node
                temp.getPrev().setNext(temp.getNext());
                temp.getNext().setPrev(temp.getPrev());
            }
        }
    }

    /**
     * Returns the head of the doubly linked list.
     * @return the head of the doubly linked list
     */
    public DLink getHead() {
        return this.head;
    }

    /**
     * Returns the tail of the doubly linked list.
     * @return the tail of the doubly linked list
     */
    public DLink getTail() {
        return this.tail;
    }
}
