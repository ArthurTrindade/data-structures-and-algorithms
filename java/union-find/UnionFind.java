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

    public void makeSet(T data) {
        var newSet = new LinkedList<T>();

        var temp = find(data);

        if (temp != null) {
            System.out.println("\n\033[0;31mElemento já existe.\033[0m");
            return;
        }

        newSet.push(data);

        for (var s : sets) {
            if (s.empty()) {
                sets.set(sets.indexOf(s), newSet);
                return;
            }
        }
    }

    public void destroySet(T data) {
        var set = find(data);

        if (set == null) {
            System.out.println("\n\033[0;31mElemento não existe.\033[0m");
            return;
        }

        sets.set(sets.indexOf(set), new LinkedList<T>());
    }

    public void destroySet(int index) {
        sets.set(index, new LinkedList<T>());
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

    public void union(T data1, T data2) {

        if (data1.equals(data2)) {
            System.out.println("\n\033[0;31mOs elementos já estão no mesmo conjunto.\033[0m");
            return;
        }

        var set1 = find(data1);
        var set2 = find(data2);

        if (set1 == null || set2 == null) {
            System.out.println("\n\033[0;31mUm dos elementos não existe.\033[0m");
            return;
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


