import java.util.ArrayList;

public class UnionFind<T> {
    public static final int MAX_SETS = 100;

    private ArrayList<LinkedList<T>> sets;

    public UnionFind() {
        this.sets = new ArrayList<>();

        for (int i = 0; i < MAX_SETS; i++) {
            sets.add(new LinkedList<T>());
        }
    }

    public void makeSet(T data) throws Exception {
        var newSet = new LinkedList<T>();

        var temp = find(data);

        if (temp != null) {
            throw new Exception("Elemento já existe.");
        }

        newSet.push(data);

        for (var s : sets) {
            if (s.empty()) {
                sets.set(sets.indexOf(s), newSet);
                return;
            }
        }
    }

    public void destroySet(T data) throws Exception {
        var set = find(data);

        if (set == null) {
            throw new Exception("Elemento não existe.");
        }

        sets.set(sets.indexOf(set), new LinkedList<T>());
    }

    public LinkedList<T> find(T data) {
        for (var s : sets) {
            var temp = s.getHead();
            while (temp != null) {
                if (temp.getData().equals(data)) {
                    return s;
                }
                temp = temp.getNext();
            }
        }
        return null;
    }

    public void union(T data1, T data2) throws Exception {
        var set1 = find(data1);
        var set2 = find(data2);

        if (set1 == null || set2 == null) {
            throw new Exception("Um dos elementos não existe.");
        }

        set1.merge(set2);
        sets.set(sets.indexOf(set2), new LinkedList<T>());
    }

    public int getSize() {
        return sets.size();
    }
    
    public ArrayList<LinkedList<T>> getSets() {
        return sets;
    }

    public LinkedList<T> getSet(int index) {
        return sets.get(index);
    } 
}


