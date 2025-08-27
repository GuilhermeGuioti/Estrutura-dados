#ifndef BAG_H
#define BAG_H
const int maximum = 20;
class Bag{
    public:
        Bag();
        void insert(int number);//acrescenta um numero na bag
        bool full();//verifica se a bag está cheia
        int size();//retorna a quantidade de números guardados atualmente na bag
        int occurrence(int number);//informa quantos "number" existem atualmente na bag
        void remove(int number);//remove uma ocorrência de "number" da bag
    private:
        int numbers[maximum+1];//vetor que guarda os números que estão atualmente na bag
        int count;//quantidade de números guardados atualmente na bag
};
#endif