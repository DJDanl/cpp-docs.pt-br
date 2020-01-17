---
title: Inicializadores
ms.date: 07/29/2019
description: Como inicializar classes, structs, matrizes e tipos fundamentais no C++.
helpviewer_keywords:
- arrays [C++], array-element initializers
- aggregate initializers [C++]
ms.assetid: ce301ed8-aa1c-47b2-bb39-9f0541b4af85
ms.openlocfilehash: 2cc68f2384402ce1eb3ac06b414f597a6b3951f0
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123962"
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

### <a name="zero-initialization"></a>Inicialização zero

A inicialização do zero é a configuração de uma variável para um valor zero convertido implicitamente no tipo:

- As variáveis numéricas são inicializadas como 0 (ou 0,0 ou 0,0000000000, etc.).

- As variáveis Char são inicializadas para `'\0'`.

- Os ponteiros são inicializados para **nullptr**.

- Matrizes, classes de [Pod](../standard-library/is-pod-class.md) , structs e uniões têm seus membros inicializados para um valor zero.

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

### <a name="default_initialization"></a>Inicialização padrão

A inicialização padrão para classes, structs e uniões é a inicialização com um construtor padrão. O construtor padrão pode ser chamado sem nenhuma expressão de inicialização ou com a **nova** palavra-chave:

```cpp
MyClass mc1;
MyClass* mc3 = new MyClass;
```

Se a classe, estrutura ou união não tiver um construtor diferente, o compilador emitirá um erro.

As variáveis escalares são inicializadas por padrão quando são definidas sem nenhuma expressão de inicialização. Elas têm valores indeterminados.

```cpp
int i1;
float f;
char c;
```

As matrizes são inicializadas por padrão quando são definidas sem nenhuma expressão de inicialização. Quando uma matriz é inicializada por padrão, seus membros são inicializados por padrão e têm valores indeterminados, como no exemplo a seguir:

```cpp
int int_arr[3];
```

Se os membros da matriz não tiverem um construtor padrão, o compilador emitirá um erro.

#### <a name="default-initialization-of-constant-variables"></a>Inicialização padrão de variáveis constantes

As variáveis constantes devem ser declaradas juntamente com um inicializador. Se forem tipos escalares, eles causarão um erro de compilador e, se forem tipos de classe que têm um construtor padrão, causarão um aviso:

```cpp
class MyClass{};
int main() {
    //const int i2;   // compiler error C2734: const object must be initialized if not extern
    //const char c2;  // same error
    const MyClass mc1; // compiler error C4269: 'const automatic data initialized with compiler generated default constructor produces unreliable results
}
```

#### <a name="default-initialization-of-static-variables"></a>Inicialização padrão de variáveis estáticas

Variáveis estáticas declaradas com nenhum inicializador são inicializadas como 0 (implicitamente convertida para o tipo).

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

Para obter mais informações sobre a inicialização de objetos estáticos globais, consulte [principal função e argumentos de linha de comando](main-function-command-line-args.md).

### <a name="value-initialization"></a>Inicialização de valor

A inicialização do valor ocorre nos seguintes casos:

- um valor nomeado é inicializado usando a inicialização de chave vazia

- um objeto temporário anônimo é inicializado usando parênteses ou chaves vazias

- um objeto é inicializado com a **nova** palavra-chave mais parênteses vazios ou chaves

A inicialização do valor faz o seguinte:

- para classes com pelo menos um construtor público, o construtor padrão é chamado

- para classes não Union sem construtores declarados, o objeto é inicializado com zero e o construtor padrão é chamado

- para matrizes, cada elemento é inicializado por valor

- em todos os outros casos, a variável é zero inicializada

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

### <a name="copy-initialization"></a>Inicialização da cópia

A inicialização da cópia é a inicialização de um objeto usando um objeto diferente. Isso ocorre nos seguintes casos:

- uma variável é inicializada usando um sinal de igual

- um argumento é passado para uma função

- um objeto é retornado de uma função

- uma exceção é lançada ou detectada

- um membro de dados não estático é inicializado usando um sinal de igual

- Membros de classe, struct e Union são inicializados pela inicialização de cópia durante a inicialização de agregação. Consulte [inicialização de agregação](#agginit) para obter exemplos.

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

A inicialização da cópia não pode invocar construtores explícitos.

```cpp
vector<int> v = 10; // the constructor is explicit; compiler error C2440: cannot convert from 'int' to 'std::vector<int,std::allocator<_Ty>>'
regex r = "a.*b"; // the constructor is explicit; same error
shared_ptr<int> sp = new int(1729); // the constructor is explicit; same error
```

Em alguns casos, se o construtor de cópia da classe for excluído ou estiver inacessível, a inicialização de cópia emitirá um erro de compilador.

### <a name="direct-initialization"></a>Inicialização direta

A inicialização direta é a inicialização usando chaves (não vazias) ou parênteses. Diferentemente da inicialização de cópia, ela pode invocar construtores explícitos. Isso ocorre nos seguintes casos:

- uma variável foi inicializada com chaves não vazias ou parênteses

- uma variável é inicializada com a **nova** palavra-chave mais chaves não vazias ou parênteses

- uma variável é inicializada com **static_cast**

- em um construtor, as classes base e os membros não estáticos são inicializados com uma lista de inicializadores

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

### <a name="list-initialization"></a>Inicialização da lista

A inicialização da lista ocorre quando uma variável é inicializada usando uma lista de inicializadores de chaves. Listas de inicializadores de chaves podem ser usadas nos seguintes casos:

- uma variável foi inicializada

- uma classe é inicializada com a **nova** palavra-chave

- um objeto é retornado de uma função

- um argumento passado para uma função

- um dos argumentos em uma inicialização direta

- em um inicializador de membro de dados não estático

- em uma lista de inicializadores de Construtor

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

### <a name="agginit"></a>Inicialização de agregação

A inicialização de agregação é uma forma da inicialização de lista para tipos de classe ou matrizes (muitas vezes, uniões ou estruturas) que não tenham:

- nenhum membro privado ou protegido

- Não há construtores fornecidos pelo usuário, exceto para construtores explicitamente padronizados ou excluídos

- nenhuma classe base

- nenhuma função de membro virtual

> [!NOTE]
> <!--conformance note-->No Visual Studio 2015 e anterior, uma agregação não tem permissão para ter inicializadores de chave ou igual para membros não estáticos. Essa restrição foi removida no padrão C++ 14 e implementada no Visual Studio 2017.

Inicializadores agregados consistem em uma lista de inicialização entre chaves, com ou sem um sinal de igual, como no exemplo a seguir:

```cpp
#include <iostream>
using namespace std;

struct MyAggregate{
    int myInt;
    char myChar;
};

struct MyAggregate2{
    int myInt;
    char myChar = 'Z'; // member-initializer OK in C++14
};

int main() {
    MyAggregate agg1{ 1, 'c' };
    MyAggregate2 agg2{2};
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
agg2: Z: 2
myArr1: 1 2 3 4
myArr3: 8 9 10 0 0
```

> [!IMPORTANT]
> Membros de matriz que são declarados, mas não explicitamente inicializados durante a inicialização de agregação, são inicializados com zero, como em `myArr3` acima.

#### <a name="initializing-unions-and-structs"></a>Inicializando uniões e structs

Se uma União não tiver um construtor, você poderá inicializá-lo com um único valor (ou com outra instância de uma União). O valor é usado para inicializar o primeiro campo não estático. Essa inicialização é diferente da inicialização de estrutura, na qual o primeiro valor no inicializador é usado para inicializar o primeiro campo, o segundo valor para inicializar o segundo campo e assim por diante. Compare a inicialização de uniões e structs no exemplo a seguir:

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

Os tipos de agregação podem conter outros tipos de agregação, por exemplo matrizes de matrizes, matrizes de structs e assim por diante. Esses tipos são inicializados usando conjuntos aninhados de chaves, por exemplo:

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

- Declaração de uma variável explicitamente especificada como **externa**. Por exemplo:

    ```cpp
    extern int& iVal;
    ```

Ao inicializar uma variável do tipo de referência, o compilador usa o gráfico de decisão mostrado na figura a seguir para selecionar entre a criação de uma referência para um objeto ou a criação de um objeto temporário para o qual a referência aponta.

![Grafo de decisão para inicialização de tipos de referência](../cpp/media/vc38s71.gif "Grafo de decisão para inicialização de tipos de referência") <br/>
Grafo de decisão para inicialização de tipos de referência

Referências a **tipos voláteis** (declarados como *TypeName* de<strong>&</strong> de *identificador* **volátil** ) podem ser inicializadas com objetos **voláteis** do mesmo tipo ou com objetos que não foram declarados como **voláteis**. No entanto, eles não podem ser inicializados com objetos **const** desse tipo. Da mesma forma, as referências a tipos **const** (declarados como identificador **const** <strong>&</strong> *Identifier*) podem ser inicializadas com objetos **const** do mesmo tipo (ou qualquer coisa que tenha uma conversão para esse tipo ou com objetos que não tenham sido declarados como **const**). No entanto, eles não podem ser inicializados com objetos **voláteis** desse tipo.

As referências que não são qualificadas com a palavra-chave **const** ou **volatile** só podem ser inicializadas com objetos declarados como nem **const** nem **volátil**.

### <a name="initialization-of-external-variables"></a>Inicialização de variáveis externas

As declarações de variáveis automáticas, estáticas e externas podem conter inicializadores. No entanto, as declarações de variáveis externas podem conter inicializadores somente se as variáveis não forem declaradas como **extern**.
