using System;

namespace List
{
    public class Node<Type>
    {
        public Type data { set; get; }
        public Node<Type> next { get; set; }
        public Node(Type data, Node<Type> next)
        {
            this.data = data;
            this.next = next;
        }
        public Node(Type data)
        {
            this.data = data;
            this.next = this;
        }
    }
    public class List<T>
    {
        public delegate void callback<Type>(Type value, int index);
        private int length { get; set; } = 0;
        private Node<T> list { get; set; }
        public void Push(T obj)
        {
            // Esta funcion es para agragar nuevos items
            // a la lista

            // T es un tipo de dato cualquiera
            var newObj = new Node<T>(obj);
            // newObj es una nodo donde se guarda el obj y una dirección hacia el
            // proximo nodo
            var temp = list;
            // temp es una variable temporal, es un puntero a un nodo

            // si el tamaño de la lista es 0, lo guarda en el primer nodo que es list
            if (length++ == 0)
                list = newObj;
            // si la lista no está vacia entonces guardara el obj en el ultimo nodo
            else if (temp != null)
            {
                while (temp.next != temp)
                    temp = temp.next;

                temp.next = newObj;
            }
        }
        public void Pop()
        {
            if (list != null && list.next != null)
            {
                list = list.next;
                length--;
            }

            else throw new Exception("List Empty!");
        }
        public T Get(uint index)
        {
            if (list == null)
                throw new Exception("List empty");

            T value = list.data;

            if (index < length)
            {
                Node<T> temp = list;

                for (int i = 0; i < index; i++)
                    temp = temp.next;

                value = temp.data;
            }
            else
                throw new IndexOutOfRangeException();

            return value;
        }
        public void ForEach(callback<T> callback)
        {
            if (list == null) return;

            Node<T> temp = list;
            for (int i = 0; i < length; i++)
            {
                callback(temp.data, i);
                temp = temp.next;
            }
        }
        public void Delete(int index)
        {
            if (list == null)
                return;

            if (index >= length)
                throw new IndexOutOfRangeException();

            if (index == 0)
            {
                Pop();
                return;
            }

            Node<T> temp = list;

            for (int i = 1; i < index; i++)
                temp = temp.next;

            temp.next = temp.next.next;
            length--;
        }
        public T[] GetArray()
        {
            var array = new T[length];
            ForEach((value, index) => {
                array[index] = value;
            });
            return array;
        }
    }
}

