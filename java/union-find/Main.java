import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        var unionFind = new UnionFind<Double>();

        double elemento;
        int index;

        while (true) {

            // clearScreen();
            menu();

            int op = sc.nextInt();

            switch (op) {
                case 1:
                    System.out.print("\nDigite o elemento: ");
                    elemento = sc.nextDouble();
                    unionFind.makeSet(elemento);
                    break;
                case 2:
                    System.out.print("\nDigite o elemento: ");
                    elemento = sc.nextDouble();
                    unionFind.destroySet(elemento);
                    break;
                case 3:
                    System.out.print("\nDigite o elemento: ");
                    elemento = sc.nextDouble();
                    showSet(unionFind, elemento);
                    break;
                case 4:
                    System.out.print("\nDigite o elemento 1: ");
                    double elemento1 = sc.nextDouble();
                    System.out.print("\nDigite o elemento 2: ");
                    double elemento2 = sc.nextDouble();
                    unionFind.union(elemento1, elemento2);
                    break;
                case 5:
                    System.out.print("\nDigite o elemento: ");
                    elemento = sc.nextDouble();
                    showSet(unionFind, elemento);
                    break;
                case 6:
                    System.out.print("\nDigite o id: ");
                    index = sc.nextInt();
                    showSet(unionFind, index);
                    break;
                case 7:
                    showAllSets(unionFind);
                    break;
                case 8:
                    sc.close();
                    break;
                default:
                    System.out.println("Opção inválida.");
                    break;
            }
        }
    }

    public static void menu() {
        System.out.println("1. MakeSet");
        System.out.println("2. DestroySet");
        System.out.println("3. Find");
        System.out.println("4. Union");
        System.out.println("5. ShowSet por elemento");
        System.out.println("6. ShowSet por identificador");
        System.out.println("7. ShowAllSets");
        System.out.println("8. exit");
        System.out.print("Escolha umas das opções: ");
    }

    public static void clearScreen() {  
        System.out.print("\033[H\033[2J");  
        System.out.flush();  
    } 

    public static void showAllSets(UnionFind<Double> uf) {
        for (var s : uf.getSets()) {
            if (!s.empty()) {
                System.out.print("S_" + uf.getSets().indexOf(s) + ": ");
                printList(s);
            }
        }
    }

    public static void showSet(UnionFind<Double> uf, Double data) {

        try {
            var set = uf.find(data);
            int index = uf.getSets().indexOf(set);
            System.out.print("S_" + index + ": ");
            printList(uf.find(data));
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }
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
