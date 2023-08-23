#Notes about this MODULE.

/*
    !Add size attribute. iinit it by 0 when calling the default cons.. And by lenght passed as parameter when calling the parametered comnstructor.
    !overload the [] subscript operator
    ! Handle case of accessing an invalid element inside the array by throwing an exception.

    * This fucking day is finished.
    * This Fucking day is about generic Functions and generic class, all this happens in  compile time polymorphism
    * So the compiler will generate another version from th function or the class that respects the type wanted, for templates classes or function.
    * For template function: in compile time, the compiler, will creat an instence from the template function with the parameter types passed to it in the call.
    * 
    * Ready to push it.
*/

/*
    * The class contains two private attributes:
    1- T *ptr : this pointer will holde the address of the new array after creating it
    2- lenght: an integer holds the size of the array.
*/

/*
    * The default constructor is about creating an empty array and initialize it to the pointer.
        *+ The Lenght of an empty array is 0.
    * The parametred constructor will creat a new array "Allocated using new" the constructor will take the lenght of the array as parameter.
    * The copy constructor will Copy the array of the RightHand object to the array on the left by using it's sizeto allocate new array and init it's size;
    * The overloaded = operator will  do the same operation as the copy assignment operator, just before copying data, needs to check if the rightHand is the same object in the leftHand.
    * Overloading the sebscript operator [] this operator will return an the index passed to it if the index is out of the bond, then an exception will be throwen.
    * Design the exception What() method and it's class OutOfTheBond , This exception will be throwen in case of accessing an element that doesn't exist.
    * Provide geters to lenght attribute.
    * Implement the insertion overloaded operator <<, This operator will just store the the array content inside ostream object and will return an ostream object,
    ! The destructor will delete [] the array
    ! And Don't forget to do more tests....
*/
