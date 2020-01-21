

class Foo {
private:
    promise<bool> F;
    promise<bool> S;
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        printFirst();
        F.set_value(1);
    }

    void second(function<void()> printSecond) {
        F.get_future().wait();
        printSecond();
        S.set_value(1);
    }

    void third(function<void()> printThird) {
        S.get_future().wait();
        printThird();
    }
};