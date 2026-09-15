package adts.list;

public interface List<T> extends Iterable<T>{
    void add(T data);
    int size();
    T getPos(int p);
    int findPos(T data);
    void remove(T data);
    void removePos(int pos);
}