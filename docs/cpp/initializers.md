---
title: Inicializadores
ms.date: 11/19/2018
helpviewer_keywords:
- array-element initializers
- initializing arrays [C++], initializers
- arrays [C++], array-element initializers
- declarators, as initializers
- initializers, array element
ms.assetid: ce301ed8-aa1c-47b2-bb39-9f0541b4af85
ms.openlocfilehash: 1890899fb2ad63bff06d514ae8b18f9dc3ff9e21
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183513"
---
# <a name="initializers"></a>Inicializadores

Um inicializador especifica o valor inicial de uma variável. Você pode inicializar variáveis nestes contextos:

- Na definição de uma variável:

    ```cpp
    int i = 3;
    Point p1{ 1, 2 };
    ```

- Como um dos parâmetros de uma função:

    ```cpp
    set_point(Point{ 5, 6 });
    ```

- Como o valor de retorno de uma função:

    ```cpp
    Point get_new_point(int x, int y) { return { x, y }; }
    Point get_new_point(int x, int y) { return Point{ x, y }; }
    ```

Os inicializadores podem usar estes formatos:

- Uma expressão (ou uma lista de expressões separadas por vírgulas) entre parênteses:

    ```cpp
    Point p1(1, 2);
    ```

- Um sinal de igual seguido por uma expressão:

    ```cpp
    string s = "hello";
    ```

- Uma lista de inicializadores entre chaves. A lista pode estar vazia ou pode consistir em um conjunto de listas, como no exemplo a seguir:

    ```cpp
    struct Point{
        int x;
        int y;
    };
    class PointConsumer{
    public:
        void set_point(Point p){};
        void set_points(initializer_list<Point> my_list){};
    };
    int main() {
        PointConsumer pc{};
        pc.set_point({});
        pc.set_point({ 3, 4 });
        pc.set_points({ { 3, 4 }, { 5, 6 } });
    }
    ```

## <a name="kinds-of-initialization"></a>Tipos de inicialização

Há vários tipos de inicialização que podem ocorrer em pontos diferentes na execução do programa. Os tipos diferentes de inicialização não são mutuamente exclusivos — por exemplo, a inicialização de lista pode acionar a inicialização de valor e, em outras circunstâncias, pode acionar a inicialização de agregação.

### <a name="zero-initialization"></a>Inicialização do zero

A inicialização do zero é a configuração de uma variável para um valor zero convertido implicitamente no tipo:

- As variáveis numéricas são inicializadas como 0 (ou 0,0 ou 0,0000000000, etc.).

- As variáveis char são inicializadas para `'\0'`.

- Os ponteiros são inicializados para **nullptr**.

- Matrizes [POD](../standard-library/is-pod-class.md) classes, estruturas e uniões têm seus membros inicializados como um valor igual a zero.

A inicialização do zero é executada em diferentes momentos:

- Na inicialização do programa, para todas as variáveis nomeadas que têm a duração estática. Essas variáveis podem ser inicializadas novamente mais tarde.

- Durante a inicialização de valor, para tipos escalares e tipos de classe POD que são inicializados usando chaves vazias.

- Para matrizes que têm apenas um subconjunto de seus membros inicializado.

Veja alguns exemplos de inicialização do zero:

```cpp
struct my_struct{
    int i;
    char c;
};

int i0;              // zero-initialized to 0
int main() {
    static float f1;  // zero-initialized to 0.000000000
    double d{};     // zero-initialized to 0.00000000000000000
    int* ptr{};     // initialized to nullptr
    char s_array[3]{'a', 'b'};  // the third char is initialized to '\0'
    int int_array[5] = { 8, 9, 10 };  // the fourth and fifth ints are initialized to 0
    my_struct a_struct{};   // i = 0, c = '\0'
}
```

### <a name="default_initialization"></a> Inicialização padrão

Inicialização padrão para classes, estruturas e uniões é a inicialização com um construtor padrão. O construtor padrão pode ser chamado sem expressão de inicialização ou com o **novo** palavra-chave:

```cpp
MyClass mc1;
MyClass* mc3 = new MyClass;
```

Se a classe, estrutura ou união não tiver um construtor diferente, o compilador emitirá um erro.

Variáveis escalares são inicializado quando são definidas com nenhuma expressão de inicialização do padrão. Elas têm valores indeterminados.

```cpp
int i1;
float f;
char c;
```

As matrizes são inicializado quando são definidas com nenhuma expressão de inicialização do padrão. Quando uma matriz é inicializada por padrão, seus membros são inicializado por padrão e têm valores indeterminados, como no exemplo a seguir:

```cpp
int int_arr[3];
```

Se os membros da matriz não tiverem um construtor padrão, o compilador emitirá um erro.

#### <a name="default-initialization-of-constant-variables"></a>Inicialização padrão de variáveis constantes

As variáveis constantes devem ser declaradas juntamente com um inicializador. Se eles forem tipos escalares que causem um erro do compilador, e se eles forem tipos de classe que tem um construtor padrão elas geram um aviso:

```cpp
class MyClass{};
int main() {
    //const int i2;   // compiler error C2734: const object must be initialized if not extern
    //const char c2;  // same error
    const MyClass mc1; // compiler error C4269: 'const automatic data initialized with compiler generated default constructor produces unreliable results
}
```

#### <a name="default-initialization-of-static-variables"></a>Inicialização padrão de variáveis estáticas

Variáveis estáticas que são declaradas com nenhum inicializador são inicializadas como 0 (implicitamente convertido no tipo).

```cpp
class MyClass {
private:
    int m_int;
    char m_char;
};

int main() {
    static int int1;       // 0
    static char char1;     // '\0'
    static bool bool1;   // false
    static MyClass mc1;     // {0, '\0'}
}
```

Para obter mais informações sobre inicialização de objetos estáticos globais, consulte [considerações adicionais de inicialização](../cpp/additional-startup-considerations.md).

### <a name="value-initialization"></a>Inicialização de valor

Inicialização de valor ocorre nos seguintes casos:

- um valor nomeado é inicializado usando a inicialização de chaves vazias

- um objeto temporário anônimo é inicializado usando parênteses ou chaves vazios

- um objeto é inicializado com o **novo** palavra-chave mais parênteses ou chaves vazios

Inicialização de valor faz o seguinte:

- para classes com pelo menos um construtor público, o construtor padrão é chamado.

- para classes de não união com nenhum construtor declarado, o objeto é inicializada do zero e o construtor padrão é chamado

- para matrizes, cada elemento é inicializado por valor

- em todos os outros casos, a variável é inicializado do zero

```cpp
class BaseClass {
private:
    int m_int;
};

int main() {
    BaseClass bc{};     // class is initialized
    BaseClass*  bc2 = new BaseClass();  // class is initialized, m_int value is 0
    int int_arr[3]{};  // value of all members is 0
    int a{};     // value of a is 0
    double b{};  // value of b is 0.00000000000000000
}
```

### <a name="copy-initialization"></a>Inicialização de cópia

Inicialização de cópia é a inicialização de um objeto usando um objeto diferente. Ele ocorre nos seguintes casos:

- uma variável é inicializada usando um sinal de igual

- um argumento é passado para uma função

- um objeto é retornado de uma função

- uma exceção é lançada ou capturada

- um membro de dados não estático é inicializado usando um sinal de igual

- classe, struct e membros de união são inicializados pela inicialização de cópia durante a inicialização de agregação. Ver [inicialização de agregação](#agginit) para obter exemplos.

O código a seguir mostra vários exemplos de inicialização de cópia:

```cpp
#include <iostream>
using namespace std;

class MyClass{
public:
    MyClass(int myInt) {}
    void set_int(int myInt) { m_int = myInt; }
    int get_int() const { return m_int; }
private:
    int m_int = 7; // copy initialization of m_int

};
class MyException : public exception{};
int main() {
    int i = 5;              // copy initialization of i
    MyClass mc1{ i };
    MyClass mc2 = mc1;      // copy initialization of mc2 from mc1
    MyClass mc1.set_int(i);    // copy initialization of parameter from i
    int i2 = mc2.get_int(); // copy initialization of i2 from return value of get_int()

    try{
        throw MyException();
    }
    catch (MyException ex){ // copy initialization of ex
        cout << ex.what();
    }
}
```

Inicialização de cópia não pode invocar construtores explícitos.

```cpp
vector<int> v = 10; // the constructor is explicit; compiler error C2440: cannot convert from 'int' to 'std::vector<int,std::allocator<_Ty>>'
regex r = "a.*b"; // the constructor is explicit; same error
shared_ptr<int> sp = new int(1729); // the constructor is explicit; same error
```

Em alguns casos, se o construtor de cópia da classe for excluído ou estiver inacessível, a inicialização de cópia emitirá um erro de compilador.

### <a name="direct-initialization"></a>Inicialização direta

Inicialização direta é inicialização usando chaves ou parênteses (não vazios). Diferentemente da inicialização de cópia, ela pode invocar construtores explícitos. Ele ocorre nos seguintes casos:

- uma variável é inicializada com chaves ou parênteses não vazios

- uma variável é inicializada com o **novo** palavra-chave além de não-chaves ou parênteses vazios

- uma variável é inicializada com **static_cast**

- em um construtor de classes base e membros não estáticos são inicializados com uma lista de inicializadores

- na cópia de uma variável capturada dentro de uma expressão lambda

O código a seguir mostra alguns exemplos de inicialização direta:

```cpp
class BaseClass{
public:
    BaseClass(int n) :m_int(n){} // m_int is direct initialized
private:
    int m_int;
};

class DerivedClass : public BaseClass{
public:
    // BaseClass and m_char are direct initialized
    DerivedClass(int n, char c) : BaseClass(n), m_char(c) {}
private:
    char m_char;
};
int main(){
    BaseClass bc1(5);
    DerivedClass dc1{ 1, 'c' };
    BaseClass* bc2 = new BaseClass(7);
    BaseClass bc3 = static_cast<BaseClass>(dc1);

    int a = 1;
    function<int()> func = [a](){  return a + 1; }; // a is direct initialized
    int n = func();
}
```

### <a name="list-initialization"></a>Inicialização de lista

Inicialização de lista ocorre quando uma variável é inicializada usando uma lista de inicializadores entre chaves. De inicializadores entre chaves listas podem ser usadas nos seguintes casos:

- uma variável é inicializada

- uma classe é inicializada com o **novo** palavra-chave

- um objeto é retornado de uma função

- um argumento passado para uma função

- um dos argumentos em uma inicialização direta

- em um inicializador de membro de dados não estáticos

- em uma lista de inicializador de construtor

O código a seguir mostra alguns exemplos de inicialização de lista:

```cpp
class MyClass {
public:
    MyClass(int myInt, char myChar) {}
private:
    int m_int[]{ 3 };
    char m_char;
};
class MyClassConsumer{
public:
    void set_class(MyClass c) {}
    MyClass get_class() { return MyClass{ 0, '\0' }; }
};
struct MyStruct{
    int my_int;
    char my_char;
    MyClass my_class;
};
int main() {
    MyClass mc1{ 1, 'a' };
    MyClass* mc2 = new MyClass{ 2, 'b' };
    MyClass mc3 = { 3, 'c' };

    MyClassConsumer mcc;
    mcc.set_class(MyClass{ 3, 'c' });
    mcc.set_class({ 4, 'd' });

    MyStruct ms1{ 1, 'a', { 2, 'b' } };
}
```

### <a name="agginit"></a> Inicialização de agregação

A inicialização de agregação é uma forma da inicialização de lista para tipos de classe ou matrizes (muitas vezes, uniões ou estruturas) que não tenham:

- Não há membros particulares ou protegidos

- Nenhum construtor fornecido pelo usuário, exceto construtores explicitamente padronizados ou excluídos

- sem classes base

- Nenhuma função membro virtual

> [!NOTE]
> <!--conformance note-->No Visual Studio 2015 e anteriores, uma agregação não é permitida ter inicializadores de chave-or-equal para membros não estáticos. Essa restrição foi removida no padrão de 14 C + + e implementada no Visual Studio 2017.

Os inicializadores de agregação consistem em uma lista de inicialização entre chaves, com ou sem um sinal de igual, como no exemplo a seguir:

```cpp
#include <iostream>
using namespace std;

struct MyAggregate{
    int myInt;
    char myChar;
};

int main() {
    MyAggregate agg1{ 1, 'c' };

    cout << "agg1: " << agg1.myChar << ": " << agg1.myInt << endl;
    cout << "agg2: " << agg2.myChar << ": " << agg2.myInt << endl;

    int myArr1[]{ 1, 2, 3, 4 };
    int myArr2[3] = { 5, 6, 7 };
    int myArr3[5] = { 8, 9, 10 };

    cout << "myArr1: ";
    for (int i : myArr1){
        cout << i << " ";
    }
    cout << endl;

    cout << "myArr3: ";
    for (auto const &i : myArr3) {
        cout << i << " ";
    }
    cout << endl;
}
```

Você deverá ver a seguinte saída:

```Output
agg1: c: 1
agg2: d: 2
myArr1: 1 2 3 4
myArr3: 8 9 10 0 0
```

> [!IMPORTANT]
> Membros da matriz que são declarados, mas não explicitamente inicializados durante a inicialização de agregação são inicializadas em zero, como em `myArr3` acima.

#### <a name="initializing-unions-and-structs"></a>Inicializando uniões e estruturas

Se uma união não tiver um construtor, você pode inicializá-lo com um único valor (ou com outra instância de uma união). O valor é usado para inicializar o primeiro campo não estático. Essa inicialização é diferente da inicialização de estrutura, na qual o primeiro valor no inicializador é usado para inicializar o primeiro campo, o segundo valor para inicializar o segundo campo e assim por diante. Compare a inicialização de uniões e estruturas no exemplo a seguir:

```cpp
struct MyStruct {
    int myInt;
    char myChar;
};
union MyUnion {
    int my_int;
    char my_char;
    bool my_bool;
    MyStruct my_struct;
};

int main() {
    MyUnion mu1{ 'a' };  // my_int = 97, my_char = 'a', my_bool = true, {myInt = 97, myChar = '\0'}
    MyUnion mu2{ 1 };   // my_int = 1, my_char = 'x1', my_bool = true, {myInt = 1, myChar = '\0'}
    MyUnion mu3{};      // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
    MyUnion mu4 = mu3;  // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
    //MyUnion mu5{ 1, 'a', true };  // compiler error: C2078: too many initializers
    //MyUnion mu6 = 'a';            // compiler error: C2440: cannot convert from 'char' to 'MyUnion'
    //MyUnion mu7 = 1;              // compiler error: C2440: cannot convert from 'int' to 'MyUnion'

    MyStruct ms1{ 'a' };            // myInt = 97, myChar = '\0'
    MyStruct ms2{ 1 };              // myInt = 1, myChar = '\0'
    MyStruct ms3{};                 // myInt = 0, myChar = '\0'
    MyStruct ms4{1, 'a'};           // myInt = 1, myChar = 'a'
    MyStruct ms5 = { 2, 'b' };      // myInt = 2, myChar = 'b'
}
```

#### <a name="initializing-aggregates-that-contain-aggregates"></a>Inicializando agregações que contêm agregações

Tipos de agregação podem conter outros tipos de agregação, por exemplo, as matrizes de matrizes, matrizes de structs e assim por diante. Esses tipos são inicializados usando conjuntos de chaves, aninhados, por exemplo:

```cpp
struct MyStruct {
    int myInt;
    char myChar;
};
int main() {
    int intArr1[2][2]{{ 1, 2 }, { 3, 4 }};
    int intArr3[2][2] = {1, 2, 3, 4};
    MyStruct structArr[]{ { 1, 'a' }, { 2, 'b' }, {3, 'c'} };
}
```

### <a name="reference-initialization"></a>Inicialização de referência

Variáveis do tipo de referência devem ser inicializadas com um objeto do tipo do qual o tipo de referência é derivado, ou com um objeto de um tipo que possa ser convertido para o tipo do qual o tipo de referência é derivado. Por exemplo:

```cpp
// initializing_references.cpp
int iVar;
long lVar;
int main()
{
    long& LongRef1 = lVar;        // No conversion required.
    long& LongRef2 = iVar;        // Error C2440
    const long& LongRef3 = iVar;  // OK
    LongRef1 = 23L;               // Change lVar through a reference.
    LongRef2 = 11L;               // Change iVar through a reference.
    LongRef3 = 11L;               // Error C3892
}
```

A única maneira de inicializar uma referência com um objeto temporário é inicializar um objeto temporário constante. Após a inicialização, uma variável de tipo de referência sempre aponta para o mesmo objeto; ela não pode ser modificada para apontar para outro.

Embora a sintaxe possa ser a mesma, a inicialização das variáveis do tipo de referência e atribuição para as variáveis do tipo de referência são semanticamente diferentes. No exemplo anterior, as atribuições que modificam `iVar` e `lVar` são semelhantes às inicializações, mas têm efeitos diferentes. A inicialização especifica o objeto para o qual os pontos das variáveis do tipo de referência apontam; a atribuição atribui o objeto mencionado pela referência.

Como passam um argumento do tipo de referência para uma função e retornam um valor do tipo de referência de uma função que são inicializações, os argumentos formais para uma função são inicializados corretamente e as referências são retornadas.

As variáveis do tipo de referência podem ser declaradas sem inicializadores, apenas na seguinte maneira:

- Declarações de função (protótipos). Por exemplo:

    ```cpp
    int func( int& );
    ```

- Declarações de tipo de retorno de função. Por exemplo:

    ```cpp
    int& func( int& );
    ```

- Declaração de um membro da classe do tipo referência. Por exemplo:

    ```cpp
    class c {public:   int& i;};
    ```

- Declaração de uma variável especificada explicitamente como **extern**. Por exemplo:

    ```cpp
    extern int& iVal;
    ```

Ao inicializar uma variável do tipo de referência, o compilador usa o gráfico de decisão mostrado na figura a seguir para selecionar entre a criação de uma referência para um objeto ou a criação de um objeto temporário para o qual a referência aponta.

![Gráfico de decisão para a inicialização de tipos de referência](../cpp/media/vc38s71.gif "gráfico de decisão para a inicialização de tipos de referência") <br/>
Gráfico de decisão para a inicialização de tipos de referência

Referências aos **volátil** tipos (declaradas como **volátil** *typename* <strong>&</strong> *identificador*) pode ser inicializado com **volátil** objetos do mesmo tipo ou com objetos que não tenham sido declarados como **volátil**. Eles não é possível, no entanto, ser inicializado com **const** objetos desse tipo. Da mesma forma, as referências a **const** tipos (declaradas como **const** *typename* <strong>&</strong> *identificador* ) pode ser inicializado com **const** objetos do mesmo tipo (ou qualquer coisa que tem uma conversão para esse tipo ou com objetos que não tenham sido declarados como **const**). Eles não é possível, no entanto, ser inicializado com **volátil** objetos desse tipo.

As referências que não são qualificadas com o **const** ou **volátil** palavra-chave pode ser inicializado somente com objetos não declarados como **const** nem  **volátil**.

### <a name="initialization-of-external-variables"></a>Inicialização de variáveis externas

Declarações de variáveis automáticas, estáticas e externas podem conter inicializadores. No entanto, as declarações de variáveis externas podem conter inicializadores apenas se as variáveis não são declaradas como **extern**.