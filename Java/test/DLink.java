package Java.test;

public class DLink {
    private Integer e;  
    private DLink next; 
    private DLink prev; 
    
    /**
     * Constructor
     * @param e the element this node (link) holds
     * @param next the next element in the list
     * @param prev the previous element in the list
     */
    public DLink(Integer e, DLink next, DLink prev) {
        this.e = e;
        this.next = next;
        this.prev = prev;
    }

    
    /**     
     * @return the DLink object to which the current object points as being next in 
     *         the list
     */
    public DLink getNext() {
        return this.next;
    }

    /**
     * @param newNext the DLink object to which the current object will point as being
     *                next in the list
     */
    public void setNext(DLink newNext) {
        this.next = newNext;
    }

    /**
     * 
     * @return the DLink object to which the current objects points as being next in
     *         the list.
     */
    public DLink getPrev() {
        return this.prev;
    }

    /**
     * 
     * @param newPrev the DLink object to which the current object will point as being
     *                (directly) previous in the list
     */
    public void setPrev(DLink newPrev) {
        this.prev = newPrev;
    }

    /**
     * Sets the element of the current DLink object.
     * @param e the Integer this DLink should hold
     */
    public void setElement(Integer e) {
        this.e = e;
    }

    /**
     * Gets the element of the current DLink object
     * @return the Integer this DLink object holds.
     */
    public Integer getElement() {
        return this.e;
    }
}