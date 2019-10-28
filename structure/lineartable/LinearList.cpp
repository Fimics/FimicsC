//
// Created by pengju.li on 2019-10-28.
//

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;


class illegalParameterValue {
public:
    illegalParameterValue(string theMessage = "Illegal parameter value") {
        message = theMessage;
    }

    void outputMessage() { cout << message << endl; }

private:
    string message;
};

class illegalIndex {
public:
    illegalIndex(string theMessage = "Illegal index") //初始化
    {
        message = theMessage;
    }

    void outputMessage() { cout << message << endl; }

private:
    string message;

};


template<class T>
class LinearList {
public:
    virtual ~LinearList() {}

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual T &get(int index) const = 0;

    virtual int indexOf(const T &element) = 0;

    virtual void insert(int index, T &element) = 0;

    virtual void erase(int index) = 0;

    virtual void output(ostream &out) const = 0;
};

template<class T>
class ArrayList : public LinearList<T> {

public:

    //构造函数，复制构造函数，析构函数
    ArrayList(int initialCapacity = 10);

    ArrayList(const ArrayList<T> &);

    ~ArrayList() {
        delete[] element;
    }

    //ADT方法
    bool empty() const {
        return listSize == 0;
    }

    int size() const {
        return listSize;
    }

    T &get(int index) const;

    int indexOf(const T &element);

    void insert(int index, T &element);

    void erase(int index);

    void output(ostream &out) const;

    //其他方法
    int capacity() {
        return arrayLength;
    }

protected:
    void checkIndex(int index) const;

    //存储线性表元素的一维数组
    T *element;
    //数组容量
    int arrayLength;
    //线性表元素个个数
    int listSize;
};

template<class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    //构造函数
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity=" << initialCapacity << "Must be >0";
        throw illegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T> &srcList) {
    arrayLength = srcList.arrayLength;
    listSize = srcList.listSize;
    element = new T[arrayLength];
    //拷贝数组元素
    copy(srcList.element, srcList.element + listSize, element);
}

template<class T>
void ArrayList<T>::checkIndex(int index) const {
    //确定index在 0和listSize-1之间
    if (index < 0 || index > listSize) {
        ostringstream s;
        s << "index= " << index << " size =" << listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
T &ArrayList<T>::get(int index) const {
    checkIndex(index);
    return element[index];
}

/**
 * 返回元素第一次出现时的index,如果此元素不存在，返回-1
 * @tparam T
 * @param element
 * @return
 */
template<class T>
int ArrayList<T>::indexOf(const T &theElement) {
    //查找无毒 element
    int index = (int) (find(element, element + listSize, theElement) - element);

    //确定元素element是否找到
    if (index == listSize)
        return -1;
    else
        return index;
}

/**
 * 删除index的元素
 * @tparam T
 * @param index
 */
template<class T>
void ArrayList<T>::erase(int index) {
    checkIndex(index);
    //有效果索引，移动其索引大于index的元素
    copy(element + index + 1, element + listSize, element + index);
    //调用析构函数
    element[--listSize].~T();
}

/**
 * 改变一个数组的长度
 * @tparam T
 * @param a
 * @param oldLength
 * @param newLength
 */
template<class T>
void changeLengthlD(T *&a, int oldLength, int newLength) {
    if (newLength < 0) {
        throw illegalParameterValue("new length must be >=0");
    }

    T *temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

/**
 * 指定位置插入元素
 * @tparam T
 * @param index
 * @param theElement
 */
template<class T>
void ArrayList<T>::insert(int index, T &theElement) {
    if (index < 0 || index > listSize) {
        ostringstream s;
        s << "index= " << index << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    //有效索引，确定数组是否已满
    if (listSize == arrayLength) {
        //数组空间已满，数组长度倍增
        changeLengthlD(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    //把元素向右移动一个位置
    copy_backward(element + index, element + listSize, element + listSize + 1);
    element[index] = theElement;
    listSize++;
}

/**
 * 把线性表插入输出流
 * @tparam T
 * @param out
 */
template<class T>
void ArrayList<T>::output(ostream &out) const {
    copy(element, element + listSize, ostream_iterator<T>(cout, ", "));
}

template<class T>
ostream &operator<<(ostream &out, const ArrayList<T> &x) {
    x.output(out);
    return out;
}


int main() {
    //初始化数组
    LinearList<int> *list = new ArrayList<int>(100);
//    ArrayList<double> d(100);
//      ArrayList<char> c;
//      ArrayList<double > dcopy(d)

    cout << " is empty " << list->empty() << endl;

    for (int i = 0; i < 50; i++) {
        list->insert(i, i);
    }

    int value = list->get(8);
    int index = list->indexOf(9);
    cout<<"value = "<<value<<" index = "<<index<<endl;

    list->output(cout);


    return 0;
}