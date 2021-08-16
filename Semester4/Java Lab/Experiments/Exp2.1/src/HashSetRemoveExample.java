package src;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class HashSetRemoveExample {
    public static void main(String[] args) {
        Set<Integer> numbers = new HashSet<>();
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(5);
        numbers.add(6);
        numbers.add(7);
        numbers.add(8);
        numbers.add(9);
        numbers.add(10);
        System.out.println("numbers : " + numbers);
        numbers.remove(10);
        System.out.println("After remove(10) => " + numbers);
        List<Integer> perfectSquares = new ArrayList<>();
        perfectSquares.add(4);
        perfectSquares.add(9);
        numbers.removeAll(perfectSquares);
        System.out.println("After removeAll(perfectSquares) => " + numbers);
        numbers.removeIf(num -> num % 2 == 0);
        System.out.println("After removeIf() => " + numbers);
        numbers.clear();
        System.out.println("After clear() => " + numbers);
    }
}