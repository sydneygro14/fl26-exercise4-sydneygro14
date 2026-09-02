// ECE 3574 Exercise: Templates - starter code

template <class T>
MyVector<T>::MyVector() : m_data(nullptr), m_capacity(0), m_size(0)
{
    // do nothing
}

template <class T>
MyVector<T>::MyVector(const MyVector<T> &obj)
{ 

    //copy over size and capacity
    m_capacity = obj.m_capacity;
    m_size = obj.m_size;

    // making a new array if space allows
    if (m_capacity > 0) {
        m_data = new T[m_capacity];

        for (int i = 0; i < m_size; i++) {
            m_data[i] = obj.m_data[i]; 
        }
    }
    else {
        m_data = nullptr;
    }
}

template <class T>
MyVector<T>::~MyVector()
{
    // delete the array when the vector is destroyed
    delete[] m_data;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj)
{
// make sure we are not assigning a vector to itself
    if (this != &obj) {

        T* new_data = nullptr;

        // make a new array if needed
        if (obj.m_capacity > 0) {
            new_data = new T[obj.m_capacity];

            // copy all the values over
            for (int i = 0; i < obj.m_size; i++) {
                new_data[i] = obj.m_data[i];
            }
        }

        // get rid of the old array
        delete[] m_data;

        // update the data, size, and capacity
        m_data = new_data;
        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
    }

    return *this;
}

template <class T>
int MyVector<T>::size()
{
    // returns however many items are in the vector
    return m_size;
}

template <class T>
bool MyVector<T>::empty()
{
    // true if no items in vector
    return m_size == 0;
}

template <class T>
void MyVector<T>::push_back(const T& value)
{
 // if the array is full, make a bigger one
    if (m_size == m_capacity) {

        int new_capacity;

        // start with room for one item
        if (m_capacity == 0) {
            new_capacity = 1;
        }
        else {
            // double the space when the array fills up
            new_capacity = m_capacity * 2;
        }

        // create the new larger array
        T* new_data = new T[new_capacity];

        // copy the old values into it
        for (int i = 0; i < m_size; i++) {
            new_data[i] = m_data[i];
        }

        // delete the old array
        delete[] m_data;

        // update the pointer and capacity
        m_data = new_data;
        m_capacity = new_capacity;
    }

    // add the new value to the end
    m_data[m_size] = value;
    m_size++;
}

template <class T>
T& MyVector<T>::at(int i)
{
    // checking if index is outside of the vector
    if (i < 0 || i >=m_size) {
        std::cerr << "Index out of range" << std::endl;
    }

    return m_data[i];
}
