class Parent:

    def showParent(self):
        print("This is parent class.")


class Child(Parent):

    def showChild(self):
        print("This is a child class.")

if __name__ == "__main__":

    par = Parent()
    chi = Child()

    par.showParent()
    chi.showChild()
    chi.showParent()
