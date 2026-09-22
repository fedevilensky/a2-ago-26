package adts.list;

import java.util.Iterator;

public class ArrayList<T> implements List<T> {
    private int count;
    private Object[] arr;

    class arrListIterator implements Iterator<T> {
        private int pos;
        private int count;
        private Object[] arr;

        arrListIterator(Object[] arr, int count) {
            this.pos = 0;
            this.count = count;
            this.arr = arr;
        }

        @Override
        public boolean hasNext() {
            return this.pos < this.count;
        }

        @Override
        public T next() {
            T elem = (T) this.arr[pos];
            pos++;
            return elem;
        }

    }

    private void grow() {
        int newCapacity = this.arr.length * 2;
        Object[] newArr = new Object[newCapacity];
        for (int i = 0; i < this.arr.length; i++) {
            newArr[i] = arr[i];
        }

        this.arr = newArr;
    }

    public ArrayList(int expectedSize) {
        this.arr = new Object[expectedSize];
    }

    @Override
    public void add(T data) {
        if (this.count == this.arr.length) {
            grow();
        }

        this.arr[count] = data;
        this.count++;
    }

    @Override
    public int size() {
        throw new RuntimeException("unimplemented method");
    }

    @Override
    public T getPos(int p) {
        assert (p < count);
        return (T) this.arr[p];
    }

    @Override
    public int findPos(T data) {
        throw new RuntimeException("unimplemented method");
    }

    @Override
    public void remove(T data) {
        throw new RuntimeException("unimplemented method");
    }

    @Override
    public void removePos(int pos) {
        throw new RuntimeException("unimplemented method");
    }

    @Override
    public Iterator<T> iterator() {
        return new arrListIterator(this.arr, this.count);
    }

}
