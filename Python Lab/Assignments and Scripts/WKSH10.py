class Car:
    def __init__(this, company):
        ''' Use of constructor '''
        print("Making Car....")
        this.manufacturer = company

    def drive(this):
        ''' Functions '''
        print("This car can drive @80 kmph.")

    def show(this):
        ''' Use of this keyword '''
        print(f'{this.manufacturer} has made this car')


class Tesla(Car):

    def __init__(this, model='Roadster'):
        ''' Use of Inheritance '''
        super().__init__('Tesla')
        this.model = model
        print("Making Tesla.")

    def drive(this, speed=100):
        ''' Function Overriding and Overloading '''
        this.speed = speed
        print(f"{this.model} has max speed of {this.speed} kmph.")

    def modelName(this):
        print(f"This is a {this.model} made by {this.manufacturer}")


if __name__ == '__main__':

    roadster = Tesla() # use of objects
    roadster.drive()
    roadster.show() # use of Inheritance
    roadster.modelName()
    print()
    model3 = Tesla('Model 3') # use of constructor overloading
    model3.drive(120) # use of function overloading
    model3.show()
    model3.modelName()

