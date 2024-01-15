import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        clearScreen();

        Scanner sc = new Scanner(System.in);

        var unionFind = new UnionFind<Double>();
        double element;
        int index;

        while (true) {
            menu();

            int op = sc.nextInt();

            switch (op) {
                case 1:
                    clearScreen();
                    System.out.println("--- Criar um novo conjunto ---");
                    element = input();
                    unionFind.makeSet(element);
                    break;
                case 2:
                    clearScreen();
                    System.out.println("--- Destruir um conjunto por elemento ---");
                    element = input();
                    unionFind.destroySet(element);
                    break;
                case 3:
                    clearScreen();
                    System.out.println("--- Destruir um conjunto por index ---");
                    System.out.print("\nDigite o index do elemento: ");
                    index = sc.nextInt();
                    unionFind.destroySet(index);
                    break;
                case 4:
                    clearScreen();
                    System.out.println("--- Achar o conjunto que contêm o elemento ---");
                    element = input();
                    showSet(unionFind, element);
                    break;
                case 5:
                    clearScreen();
                    System.out.println("--- Unir dois conjuntos que contêm os elementos ---");
                    showAllSets(unionFind);
                    double element1 = input();
                    double element2 = input();
                    unionFind.union(element1, element2);
                    break;
                case 6:
                    clearScreen();
                    System.out.println("--- Mostrar o conjunto que contêm o elemento ---");
                    element = input();
                    showSet(unionFind, element);
                    break;
                case 7:
                    clearScreen();
                    System.out.println("--- Mostrar o conjunto pelo index ---");
                    System.out.print("\nDigite o index do elemento: ");
                    index = sc.nextInt();
                    showSet(unionFind, index);
                    break;
                case 8:
                    clearScreen();
                    System.out.println("--- Mostrar todos os conjuntos ---");
                    System.out.println();
                    showAllSets(unionFind);
                    break;
                case 9:
                    clearScreen();
                    System.out.println("--- Mostrar o tamanho do conjunto que contêm o elemento ---");
                    element = input();
                    sizeSet(unionFind, element);
                    break;
                case 10:
                    clearScreen();
                    System.out.println("--- Mostrar o tamanho do conjunto pelo index ---");
                    System.out.print("\nDigite o index do elemento: ");
                    index = sc.nextInt();
                    sizeSet(unionFind, index);
                    break;
                case 0:
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("\n\033[0;31mOpção inválida.\033[0m");
                    break;
            }
        }
    }

    public static void menu() {
        System.out.println("\n---- Union Find ----\n");
        System.out.println("1 - Criar um novo conjunto.");
        System.out.println("2 - Destruir um conjunto por elemento.");
        System.out.println("3 - Destruir um conjunto por index.");
        System.out.println("4 - Achar o conjunto que contêm o elemento.");
        System.out.println("5 - Unir dois conjuntos que contêm os elementos.");
        System.out.println("6 - Mostrar o conjunto que contêm o elemento.");
        System.out.println("7 - Mostrar o conjunto pelo index.");
        System.out.println("8 - Mostrar todos os conjuntos.");
        System.out.println("9 - Mostrar o tamanho do conjunto que contêm o elemento.");
        System.out.println("10 - Mostrar o tamanho do conjunto pelo index.");
        System.out.println("0 - Sair.\n");
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
        var set = uf.find(data);

        if (set == null) {
            System.out.println("\n\033[0;31mElemento não existe.\033[0m");
            return;
        }

        int index = uf.getSets().indexOf(set);
        System.out.print("\nS_" + index + ": ");
        printList(uf.find(data));
    }

    public static void showSet(UnionFind<Double> uf, int index) {
        var set = uf.getSets().get(index);

        if (set.empty()) {
            System.out.println("\n\033[0;31mIndex não existe.\033[0m");
            return;
        }

        System.out.print("\nS_" + index + ": ");
        printList(set);
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

    public static void sizeSet(UnionFind<Double> uf, Double data) {
        var set = uf.find(data);

        if (set == null) {
            System.out.println("\n\033[0;31mElemento não existe.\033[0m");
            return;
        }

        int index = uf.getSets().indexOf(set);
        int size = uf.getSet(index).getSize();
        System.out.println("\nS_" + index + ": " + size);
    }

    public static void sizeSet(UnionFind<Double> uf, int index) {
        var set = uf.getSets().get(index);

        if (set.empty()) {
            System.out.println("\n\033[0;31mIndex não existe.\033[0m");
            return;
        }

        int size = uf.getSet(index).getSize();
        System.out.println("\nS_" + index + ": " + size);
    }

    public static double input() {
        System.out.print("\nDigite o valor para o elemento: ");
        Scanner sc = new Scanner(System.in);
        return sc.nextDouble();
    }
}
