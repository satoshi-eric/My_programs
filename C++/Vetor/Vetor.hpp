template <class type>
class Vetor
{
public:
    Vetor();
    append(type element);
    remove(int index);

protected:
    type *array;
    int length;
}