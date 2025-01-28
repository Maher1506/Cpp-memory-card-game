    #ifndef CARD_H_INCLUDED
    #define CARD_H_INCLUDED

    class Card {
    private:
        bool faceUp;
        int number;

    public:
        //constructors
        Card();
        Card(int n);

        //methods
        void reveal();
        void hide();

        // abstract
        virtual void display() = 0;
        virtual bool isStandardCard() = 0;

        //setters and getters
        int getNumber();
        void setNumber(int n);
        void setFaceUp(bool f);
        bool getFaceUp();

        //destructor
        virtual ~Card();
    };

    #endif // CARD_H_INCLUDED
