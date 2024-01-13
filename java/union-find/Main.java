public class Main {
    public static void main(String[] args) throws Exception {
        var uf = new UnionFind<Double>();

        uf.makeSet(1.0);
        uf.makeSet(2.0);
        uf.makeSet(4.0);
        uf.makeSet(5.0);
        uf.makeSet(10.0);

        uf.union(4.0, 10.0);
        uf.union(1.0, 4.0);
        
        uf.makeSet(3.0);
        uf.makeSet(6.0);

        uf.union(2.0,5.0);
        uf.union(3.0,10.0);

        uf.destroySet(6.0);

        uf.makeSet(1.0);

        uf.printUnion();

        System.out.println(uf.getSize());
    }
}
