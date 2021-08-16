package com.serialization;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class StudentData {
  private static final StudentData instance;

  static {
    instance = new StudentData();
  }

  public static StudentData getInstance() {
    return instance;
  }

  private StudentData() {
  }

  public void saveStudents(ArrayList<Student> StudentArrayList) {
    try (ObjectOutputStream toFile = new ObjectOutputStream(new FileOutputStream(new File("Students.dat")))) {
      for (Student e : StudentArrayList) {
        toFile.writeObject(e);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public ArrayList<Student> loadStudents() {
    ArrayList<Student> StudentArrayList = new ArrayList<>();
    try (ObjectInputStream fromFile = new ObjectInputStream(new FileInputStream("Students.dat"))) {
      while (true) {
        StudentArrayList.add((Student) fromFile.readObject());
      }
    } catch (IOException | ClassNotFoundException e) {
      return StudentArrayList;
    }
  }
}
