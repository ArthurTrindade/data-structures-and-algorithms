class Node<T> {
    private T data;
    private Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}

public class LinkedList<T> {
    private int size;
    private Node<T> head;
    private Node<T> tail;

    public LinkedList() {
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public void push(T data) {
        Node<T> newNode = new Node<>(data);

        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.setNext(newNode);
            tail = newNode;
        }

        size++;
    }

    public void merge(LinkedList<T> list) {
        if (head == null) {
            head = list.getHead();
            tail = list.getTail();
        } else {
            tail.setNext(list.getHead());
            tail = list.getTail();
        }

        size += list.getSize();
        list = null;
    }

    public LinkedList<T> search(T data) {
        if (head == null) {
            System.out.println("Lista está vazia.");
            return null;
        }

        Node<T> temp = head;
        while (temp != null) {
            if (temp.getData() == data) {
                return this;
            }
            temp = temp.getNext();
        }

        return null;
    }

    public boolean empty() {
        return head == null;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public Node<T> getHead() {
        return head;
    }

    public void setHead(Node<T> head) {
        this.head = head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public void setTail(Node<T> tail) {
        this.tail = tail;
    }
}
