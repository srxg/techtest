package Java.test;

public class DLink {
    private Integer e;
    private DLink next;
    private DLink prev;
    
    
    public DLink(Integer e, DLink next, DLink prev) {
        this.e = e;
        this.next = next;
        this.prev = prev;
    }

    public DLink getNext() {
        return this.next;
    }

    public void setNext(DLink newNext) {
        this.next = newNext;
    }

    public DLink getPrev() {
        return this.prev;
    }

    public void setPrev(DLink newPrev) {
        this.prev = newPrev;
    }


    public void setElement(Integer e) {
        this.e = e;
    }

    public Integer getElement() {
        return this.e;
    }
}