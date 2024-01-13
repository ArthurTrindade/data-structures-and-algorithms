public class Main {
    public static void main(String[] args) throws Exception {

        UnionFind<Double> unionFind = new UnionFind<>();
        unionFind.makeSet(1.0);
        unionFind.makeSet(2.0);
        unionFind.makeSet(3.0);
        
        showSet(unionFind, 2.0);
        showSet(unionFind, 2);
    }

    public static void showSet(UnionFind<Double> uf, Double data) {
        var set = uf.find(data);
        int index = uf.getSets().indexOf(set);
        System.out.print("S_" + index + ": ");
        printList(uf.find(data));
    }

    public static void showSet(UnionFind<Double> uf, int index) {
        System.out.print("S_" + index + ": ");
        printList(uf.getSets().get(index));
    }

    public static void printList(LinkedList<Double> list) {
        var temp = list.getHead();
        System.out.print("{ ");
        while (temp != null) {
            System.out.print(temp.getData() + ", ");
            temp = temp.getNext();
        }
        System.out.println("}");
    }
}
