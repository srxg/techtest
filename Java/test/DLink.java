package Java.test;

/*
 * Implementation of a node in a doubly linked-link
 */
public class DLink {
    private Integer e;
    private DLink next; 
    private DLink prev; 
    
    /**
     * Constructor
     * @param e the element this node should store
     * @param next the next node in the list
     * @param prev the previous node in the list
     */
    public DLink(Integer e, DLink next, DLink prev) {
        this.e = e;
        this.next = next;
        this.prev = prev;
    }

    
    /**     
     * Returns the next node in the list
     * @return the next node in the list
     */
    public DLink getNext() {
        return this.next;
    }

    /**
     * Sets the next node in the list
     * @param newNext the new next node in the list
     */
    public void setNext(DLink newNext) {
        this.next = newNext;
    }

    /**
     * Returns the pervious node in the list
     * @return the previous node in the list
     */
    public DLink getPrev() {
        return this.prev;
    }

    /**
     * Sets the previous node in the list
     * @param newPrev the new previous node in the list
     */
    public void setPrev(DLink newPrev) {
        this.prev = newPrev;
    }

    /**
     * Returns the integer stored in this node
     * @return the Integer held by this node
     */
    public Integer getElement() {
        return this.e;
    }
    
    /**
     * Sets the element of the current DLink object.
     * @param e the Integer this DLink should hold
     */
    public void setElement(Integer e) {
        this.e = e;
    }

    
}