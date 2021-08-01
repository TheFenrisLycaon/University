package com.race;

import java.util.Random;

public class src implements Runnable {
    private String name;
    private int lazinessRate, Velocity;
    private boolean WakeStatus = true;
    private boolean reWake = true;

    public String getRacerName() {
        return name;
    }

    public src(String name, int lazinessRate, int Velocity) {
        this.name = name;
        this.lazinessRate = lazinessRate;
        this.Velocity = Velocity;
        System.out.println("New racer :\t"+ this.name);
        System.out.println(("Stats::\nAvg. Speed::\t"+ this.Velocity+"\nLaziness Rate::\t"+ this.lazinessRate));
        System.out.println("\n----------------------------------------\n");
    }

    @Override
    public void run() {
        int DistanceCovered = 0;
        Random rn = new Random();
        Thread ct = Thread.currentThread();
        ct.setName(name);
        while (!ct.isInterrupted()) {
            if ((rn.nextInt(100) + lazinessRate) / 2 > lazinessRate) {
                DistanceCovered += Velocity;
                System.out.println(this.name + "::\t" + DistanceCovered + " meters");
            } else {
                if (DistanceCovered <= 500) {
                    DistanceCovered += Velocity;
                    System.out.println(this.name + "::\t" + DistanceCovered + " meters");
                } else if (WakeStatus) {
                    try {
                        System.out.println();
                        System.out.println(this.name + "::\tImma go to sleep !!!\n");
                        Thread.sleep(2500);
                        WakeStatus = false;
                    } catch (InterruptedException ex) {
                        break;
                    }
                } else {
                    if (reWake){
                        System.out.println();
                        System.out.println(this.name + "::\tLet's win this race !!!\n");
                        reWake = false;
                    } 
                    else{
                        DistanceCovered += Velocity;
                        System.out.println(this.name + "::\t" + DistanceCovered + " meters");
                    }
                }
            }
            try {
                Thread.sleep(250);
            } catch (InterruptedException ex) {
                break;
            }
            if (DistanceCovered >= 1000) {
                System.out.println(this.name + "::\tI've won!");
                Main.finished(ct);
                return;
            }
        }
    }
}
