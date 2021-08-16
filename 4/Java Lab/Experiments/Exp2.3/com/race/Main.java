package com.race;

public class Main {
    static Thread hare = new Thread(new src("Hare", 90, 100));
    static Thread tortoise = new Thread(new src("Tortoise", 0, 50));

    public static void main(String[] args) {
        System.out.println(("Let the race begin !!!\n\n"));
        hare.start();
        tortoise.start();
    }

    synchronized public static void finished(Thread winner) {
        if (winner.isInterrupted()) {
            return;
        }
        if (winner.getName().equals("Hare"))
            tortoise.interrupt();
        else if (winner.getName().equals("Tortoise"))
            hare.interrupt();
    }
}