import org.junit.Test;
import static org.junit.Assert.*;

public class UnionFindTest {

    @Test
    public void testMakeSet() throws Exception {
        UnionFind<Integer> unionFind = new UnionFind<>();
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        unionFind.makeSet(3);

        assertEquals(3, unionFind.getSize());
    }

    @Test
    public void testDestroySet() throws Exception {
        UnionFind<Integer> unionFind = new UnionFind<>();
        unionFind.makeSet(1);
        unionFind.makeSet(2);
        unionFind.makeSet(3);

        unionFind.destroySet(2);

        assertEquals(2, unionFind.getSize());
    }

}
