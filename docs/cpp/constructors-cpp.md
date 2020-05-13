---
title: Construtores (C++)
ms.date: 12/27/2019
helpviewer_keywords:
- constructors [C++]
- objects [C++], creating
- instance constructors
ms.assetid: 3e9f7211-313a-4a92-9584-337452e061a9
ms.openlocfilehash: 4640bcf5f21bbe018a8744a6c5206bdd09509c98
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749652"
---
# <a name="constructors-c"></a>Construtores (C++)

Para personalizar como os membros da classe são inicializados ou para invocar funções quando um objeto de sua classe é criado, defina um *construtor*. Um construtor tem o mesmo nome da classe e nenhum valor de retorno. Você pode definir quantos construtores sobrecarregados forem necessários para personalizar a inicialização de várias maneiras. Normalmente, os construtores têm acessibilidade pública para que o código fora da definição de classe ou hierarquia de herança possa criar objetos da classe. Mas você também pode declarar um construtor como **protegido** ou **privado.**

Os construtores podem, opcionalmente, levar uma lista de membros. Esta é uma maneira mais eficiente de inicializar os membros da classe do que atribuir valores no corpo construtor. O exemplo a `Box` seguir mostra uma classe com três construtores sobrecarregados. Os dois últimos membros usam listas init:

```cpp
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};
```

Quando você declara uma instância de uma classe, o compilador escolhe qual construtor invocar com base nas regras de resolução de sobrecarga:

```cpp
int main()
{
    Box b; // Calls Box()

    // Using uniform initialization (preferred):
    Box b2 {5}; // Calls Box(int)
    Box b3 {5, 8, 12}; // Calls Box(int, int, int)

    // Using function-style notation:
    Box b4(2, 4, 6); // Calls Box(int, int, int)
}
```

- Os construtores podem ser declarados **inline,** [explícitos,](#explicit_constructors) **amigos** ou [constexpr](#constexpr_constructors).
- Um construtor pode inicializar um objeto que tenha sido declarado **const,** **volátil** ou **volátil**. O objeto torna-se **const** depois que o construtor completa.
- Para definir um construtor em um arquivo de implementação, dê-lhe um nome qualificado como em qualquer outra função de membro: `Box::Box(){...}`.

## <a name="member-initializer-lists"></a><a name="member_init_list"></a>Listas de inicializadores de membros

Um construtor pode opcionalmente ter uma lista inicializadora de membros, que inicializa os membros da classe antes da execução do corpo do construtor. (Observe que uma lista inicializadora de membros não é a mesma coisa que uma *lista inicializadora* de [socs do tipo::initializer_list\<T>](../standard-library/initializer-list-class.md).)

O uso de uma lista inicializadora de membros é preferível ao atribuir valores no corpo do construtor porque ele inicializa diretamente o membro. No exemplo a seguir, a lista inicializadora de membros consiste em todas as expressões **do identificador (argumento)** após o cólon:

```cpp
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}
```

O identificador deve se referir a um membro da classe; é inicializado com o valor do argumento. O argumento pode ser um dos parâmetros do construtor, uma chamada de função ou um [\<std::initializer_list T>](../standard-library/initializer-list-class.md).

**membros do const** e membros do tipo de referência devem ser inicializados na lista inicialização de membros.

As chamadas para construtores de classe base parametrizadas devem ser feitas na lista inicializadora para garantir que a classe base seja totalmente inicializada antes da execução do construtor derivado.

## <a name="default-constructors"></a><a name="default_constructors"></a>Construtores padrão

*Os construtores padrão* normalmente não têm parâmetros, mas podem ter parâmetros com valores padrão.

```cpp
class Box {
public:
    Box() { /*perform any required default initialization steps*/}

    // All params have default values
    Box (int w = 1, int l = 1, int h = 1): m_width(w), m_height(h), m_length(l){}
...
}
```

Os construtores padrão são uma das [funções especiais dos membros.](special-member-functions.md) Se nenhum construtor for declarado em uma classe, o compilador fornece um construtor padrão **inline** implícito.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int Volume() {return m_width * m_height * m_length;}
private:
    int m_width { 0 };
    int m_height { 0 };
    int m_length { 0 };
};

int main() {
    Box box1; // Invoke compiler-generated constructor
    cout << "box1.Volume: " << box1.Volume() << endl; // Outputs 0
}
```

Se você confiar em um construtor padrão implícito, certifique-se de inicializar membros na definição de classe, como mostrado no exemplo anterior. Sem esses iniciadores, os membros não seriam inicializados e a chamada Volume() produziria um valor de lixo. Em geral, é uma boa prática inicializar os membros dessa forma mesmo quando não depende de um construtor padrão implícito.

Você pode impedir que o compilador gere um construtor padrão implícito definindo-o como [excluído:](#explicitly_defaulted_and_deleted_constructors)

```cpp
    // Default constructor
    Box() = delete;
```

Um construtor padrão gerado pelo compilador será definido como excluído se algum membro da classe não for construído como padrão. Por exemplo, todos os membros do tipo de classe, e seus membros de classe, devem ter um construtor padrão e destruidores que estejam acessíveis. Todos os membros de dados do tipo de referência, bem como membros **do Const,** devem ter um inicializador de membros padrão.

Quando você chama um construtor padrão gerado pelo compilador e tenta usar parênteses, um aviso é emitido:

```cpp
class myclass{};
int main(){
myclass mc();     // warning C4930: prototyped function not called (was a variable definition intended?)
}
```

Este é um exemplo do problema Most Vexing Parse. Como a expressão de exemplo pode ser interpretada como a declaração de uma função ou como invocação de um construtor padrão, e como os analisadores de C++ preferem as declarações a outras coisas, a expressão é tratada como uma declaração de função. Para obter mais informações, consulte [Most Vexing Parse](https://en.wikipedia.org/wiki/Most_vexing_parse).

Se algum construtor não padrão for declarado, o compilador não fornecerá um construtor padrão:

```cpp
class Box {
public:
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height){}
private:
    int m_width;
    int m_length;
    int m_height;

};

int main(){

    Box box1(1, 2, 3);
    Box box2{ 2, 3, 4 };
    Box box3; // C2512: no appropriate default constructor available
}
```

Se uma classe não tiver um construtor padrão, uma matriz de objetos dessa classe não poderá ser construída usando apenas a sintaxe de colchete. Por exemplo, dado o bloco de códigos anterior, uma matriz de caixas não pode ser declarada assim:

```cpp
Box boxes[3]; // C2512: no appropriate default constructor available
```

No entanto, você pode usar um conjunto de listas de inicializadores para inicializar uma matriz de objetos da Caixa:

```cpp
Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
```

Para obter mais informações, consulte [Inicializantes](initializers.md).

## <a name="copy-constructors"></a><a name="copy_and_move_constructors"></a>Copiar construtores

Um *construtor de cópia* inicializa um objeto copiando os valores do membro de um objeto do mesmo tipo. Se os membros da sua classe são todos tipos simples, como valores escalares, o construtor de cópias gerado pelo compilador é suficiente e você não precisa definir o seu próprio. Se sua classe exigir uma inicialização mais complexa, então você precisa implementar um construtor de cópia personalizado. Por exemplo, se um membro de classe é um ponteiro, então você precisa definir um construtor de cópia para alocar uma nova memória e copiar os valores do objeto apontado para o outro. O construtor de cópias gerado pelo compilador simplesmente copia o ponteiro, de modo que o novo ponteiro ainda aponta para o local de memória do outro.

Um construtor de cópias pode ter uma dessas assinaturas:

```cpp
    Box(Box& other); // Avoid if possible--allows modification of other.
    Box(const Box& other);
    Box(volatile Box& other);
    Box(volatile const Box& other);

    // Additional parameters OK if they have default values
    Box(Box& other, int i = 42, string label = "Box");
```

Quando você define um construtor de cópias, você também deve definir um operador de atribuição de cópia (=). Para obter mais informações, consulte construtores [de atribuição](assignment.md) e [cópia e operadores de atribuição de cópia](copy-constructors-and-copy-assignment-operators-cpp.md).

Você pode impedir que seu objeto seja copiado definindo o construtor de cópias como excluído:

```cpp
    Box (const Box& other) = delete;
```

Tentar copiar o objeto produz erro *C2280: tentando referenciar uma função excluída*.

## <a name="move-constructors"></a><a name="move_constructors"></a>Mover construtores

Um *construtor de movimentos* é uma função de membro especial que move a propriedade dos dados de um objeto existente para uma nova variável sem copiar os dados originais. Ele toma uma referência de valor como seu primeiro parâmetro, e quaisquer parâmetros adicionais devem ter valores padrão. Os construtores move podem aumentar significativamente a eficiência do seu programa ao passar em torno de objetos grandes.

```cpp
Box(Box&& other);
```

O compilador escolhe um construtor de movimentos em certas situações onde o objeto está sendo inicializado por outro objeto do mesmo tipo que está prestes a ser destruído e não precisa mais de seus recursos. O exemplo a seguir mostra um caso quando um construtor de movimento é selecionado por resolução de sobrecarga. Na construtora que `get_Box()`chama, o valor retornado é um *valor xvalue* (valor eXpiring). Ele não é atribuído a nenhuma variável e, portanto, está prestes a sair do escopo. Para fornecer motivação para este exemplo, vamos dar ao Box um grande vetor de strings que representam seu conteúdo. Em vez de copiar o vetor e suas cordas, o construtor move "rouba" do valor de expiração "caixa" de modo que o vetor agora pertence ao novo objeto. O chamado `std::move` é tudo o que `vector` `string` é necessário porque ambos e classes implementam seus próprios construtores move.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Box {
public:
    Box() { std::cout << "default" << std::endl; }
    Box(int width, int height, int length)
       : m_width(width), m_height(height), m_length(length)
    {
        std::cout << "int,int,int" << std::endl;
    }
    Box(Box& other)
       : m_width(other.m_width), m_height(other.m_height), m_length(other.m_length)
    {
        std::cout << "copy" << std::endl;
    }
    Box(Box&& other) : m_width(other.m_width), m_height(other.m_height), m_length(other.m_length)
    {
        m_contents = std::move(other.m_contents);
        std::cout << "move" << std::endl;
    }
    int Volume() { return m_width * m_height * m_length; }
    void Add_Item(string item) { m_contents.push_back(item); }
    void Print_Contents()
    {
        for (const auto& item : m_contents)
        {
            cout << item << " ";
        }
    }
private:
    int m_width{ 0 };
    int m_height{ 0 };
    int m_length{ 0 };
    vector<string> m_contents;
};

Box get_Box()
{
    Box b(5, 10, 18); // "int,int,int"
    b.Add_Item("Toupee");
    b.Add_Item("Megaphone");
    b.Add_Item("Suit");

    return b;
}

int main()
{
    Box b; // "default"
    Box b1(b); // "copy"
    Box b2(get_Box()); // "move"
    cout << "b2 contents: ";
    b2.Print_Contents(); // Prove that we have all the values

    char ch;
    cin >> ch; // keep window open
    return 0;
}
```

Se uma classe não definir um construtor de movimentos, o compilador gerará um implícito se não houver um construtor de cópia declarado pelo usuário, o operador de atribuição de cópia, o operador de atribuição de movimento ou o destructor. Se nenhum construtor de movimento explícito ou implícito for definido, operações que de outra forma usariam um construtor de movimento sustecem o construtor de cópias. Se uma classe declarar um construtor de movimento ou operador de atribuição de movimento, o construtor de cópias implicitamente declarado será definido como excluído.

Um construtor de movimentos implicitamente declarado é definido como excluído se algum membro que seja do tipo de classe não tiver um destruidor ou o compilador não puder determinar qual construtor usar para a operação de movimento.

Para obter mais informações sobre como escrever um construtor de movimentos não triviais, consulte [Mover Construtores e Mover Operadores de Atribuição (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md).

## <a name="explicitly-defaulted-and-deleted-constructors"></a><a name="explicitly_defaulted_and_deleted_constructors"></a>Construtores explicitamente inadimplentes e excluídos

Você pode explicitamente *copiar* construtores, construtores padrão, mover construtores, copiar operadores de atribuição, mover operadores de atribuição e destruidores. Você pode *excluir* explicitamente todas as funções especiais de membros.

```cpp
class Box
{
public:
    Box2() = delete;
    Box2(const Box2& other) = default;
    Box2& operator=(const Box2& other) = default;
    Box2(Box2&& other) = default;
    Box2& operator=(Box2&& other) = default;
    //...
};
```

Para obter mais informações, consulte [Funções explicitamente padrão e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md).

## <a name="constexpr-constructors"></a><a name="constexpr_constructors"></a>construtores constexpr

Um construtor pode ser declarado como [constexpr](constexpr-cpp.md) se

- ou é declarado inadimplente ou então satisfaz todas as condições para [funções de constexpr](constexpr-cpp.md#constexpr_functions) em geral;
- a classe não tem classes de base virtuais;
- cada um dos parâmetros é um [tipo literal;](trivial-standard-layout-and-pod-types.md#literal_types)
- o corpo não é uma função try-block;
- todos os membros de dados não estáticos e subobjetos de classe base são inicializados;
- se a classe é (a) um sindicato com membros variantes, ou (b) tem sindicatos anônimos, apenas um dos membros do sindicato é inicializado;
- todos os membros de dados não estáticos do tipo de classe, e todos os subobjetos de classe base têm um construtor constexpr

## <a name="initializer-list-constructors"></a><a name="init_list_constructors"></a>Construtores da lista de inicializadores

Se um construtor tomar um [\<std::initializer_list T\> ](../standard-library/initializer-list-class.md) como parâmetro e quaisquer outros parâmetros tiverem argumentos padrão, esse construtor será selecionado na resolução de sobrecarga quando a classe estiver instanciada através da inicialização direta. Você pode usar o initializer_list para inicializar qualquer membro que possa aceitá-lo. Por exemplo, suponha que a classe `std::vector<string>` `m_contents`Caixa (mostrada anteriormente) tenha um membro . Você pode fornecer um construtor como este:

```cpp
    Box(initializer_list<string> list, int w = 0, int h = 0, int l = 0)
        : m_contents(list), m_width(w), m_height(h), m_length(l)
{}
```

E então criar objetos box como este:

```cpp
    Box b{ "apples", "oranges", "pears" }; // or ...
    Box b2(initializer_list<string> { "bread", "cheese", "wine" }, 2, 4, 6);
```

## <a name="explicit-constructors"></a><a name="explicit_constructors"></a>Construtores explícitos

Se uma classe tiver um construtor com um único parâmetro, ou se todos os parâmetros, exceto um, tiverem um valor padrão, o tipo de parâmetro pode ser implicitamente convertido para o tipo de classe. Por exemplo, `Box` se a classe tem um construtor como este:

```cpp
Box(int size): m_width(size), m_length(size), m_height(size){}
```

É possível inicializar uma caixa como esta:

```cpp
Box b = 42;
```

Ou passar um int para uma função que leva uma Caixa:

```cpp
class ShippingOrder
{
public:
    ShippingOrder(Box b, double postage) : m_box(b), m_postage(postage){}

private:
    Box m_box;
    double m_postage;
}
//elsewhere...
    ShippingOrder so(42, 10.8);
```

Tais conversões podem ser úteis em alguns casos, mas mais frequentemente podem levar a erros sutis, mas graves em seu código. Como regra geral, você deve usar a palavra-chave **explícita** em um construtor (e operadores definidos pelo usuário) para evitar esse tipo de conversão implícita de tipo:

```cpp
explicit Box(int size): m_width(size), m_length(size), m_height(size){}
```

Quando o construtor é explícito, esta linha causa `ShippingOrder so(42, 10.8);`um erro do compilador: .  Para obter mais informações, consulte [Conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

## <a name="order-of-construction"></a><a name="order_of_construction"></a>Ordem de construção

Um construtor executa seu trabalho nesta ordem:

1. Chama a classe base e os construtores membros na ordem da declaração.

1. Se a classe for derivada de classes base virtuais, ela inicializará os ponteiros de base virtuais do objeto.

1. Se a classe tiver ou herdar funções virtuais, ela inicializará os ponteiros de função virtual do objeto. Os ponteiros de função virtual apontam para a tabela de função virtual da classe para permitir a associação de chamadas de função virtual ao código.

1. Executa qualquer código no corpo de sua função.

O exemplo a seguir mostra a ordem em que a classe base e os construtores membros são chamados no construtor para uma classe derivada. Primeiro, o construtor de base é chamado, depois os membros da classe base são inicializados na ordem em que aparecem na declaração de classe e, em seguida, o construtor derivado é chamado.

```cpp
#include <iostream>

using namespace std;

class Contained1 {
public:
    Contained1() { cout << "Contained1 ctor\n"; }
};

class Contained2 {
public:
    Contained2() { cout << "Contained2 ctor\n"; }
};

class Contained3 {
public:
    Contained3() { cout << "Contained3 ctor\n"; }
};

class BaseContainer {
public:
    BaseContainer() { cout << "BaseContainer ctor\n"; }
private:
    Contained1 c1;
    Contained2 c2;
};

class DerivedContainer : public BaseContainer {
public:
    DerivedContainer() : BaseContainer() { cout << "DerivedContainer ctor\n"; }
private:
    Contained3 c3;
};

int main() {
    DerivedContainer dc;
}
```

Este é o resultado:

```Output
Contained1 ctor
Contained2 ctor
BaseContainer ctor
Contained3 ctor
DerivedContainer ctor
```

Um construtor de classe derivada sempre chama um construtor de classe base, de modo que possa confiar em classes base completamente construídas antes que qualquer trabalho adicional seja feito. Os construtores de classe base são chamados por ordem `ClassA` de derivação — por exemplo, se `ClassB`for derivado , que é derivado `ClassC`, o `ClassC` construtor é chamado primeiro, depois o `ClassB` construtor, depois o `ClassA` construtor.

Se uma classe base não tiver um construtor padrão, você deverá fornecer os parâmetros do construtor de classe base no construtor de classe derivada:

```cpp
class Box {
public:
    Box(int width, int length, int height){
       m_width = width;
       m_length = length;
       m_height = height;
    }

private:
    int m_width;
    int m_length;
    int m_height;
};

class StorageBox : public Box {
public:
    StorageBox(int width, int length, int height, const string label&) : Box(width, length, height){
        m_label = label;
    }
private:
    string m_label;
};

int main(){

    const string aLabel = "aLabel";
    StorageBox sb(1, 2, 3, aLabel);
}
```

Se um construtor gerar uma exceção, a ordem de destruição será a inversa da ordem de construção:

1. O código no corpo da função de construtor é liberado.

1. Os objetos de classe base e de membros são destruídos, na ordem inversa da declaração.

1. Se o construtor não for representante, todos os objetos da classe base e membros completamente construídos serão destruídos. No entanto, como o próprio objeto não está totalmente construído, o destruidor não é executado.

## <a name="derived-constructors-and-extended-aggregate-initialization"></a><a name="extended_aggregate"></a>Construtores derivados e inicialização agregada estendida

Se o construtor de uma classe base não for público, mas acessível a uma classe derivada, então sob **/std:c++17** no visual studio 2017 e depois você não pode usar aparelhos vazios para inicializar um objeto do tipo derivado.

O exemplo a seguir mostra o comportamento de conformidade do C++14:

```cpp
struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {}
};

struct Derived : Base {};

Derived d1; // OK. No aggregate init involved.
Derived d2 {}; // OK in C++14: Calls Derived::Derived()
               // which can call Base ctor.
```

No C++ 17, `Derived` agora é considerado um tipo de agregação. Isso significa que a inicialização de `Base` por meio do construtor padrão privado acontece diretamente como parte da regra de inicialização de agregação estendida. Anteriormente, o construtor privado `Base` era chamado por meio do construtor `Derived`, e isso era bem-sucedido devido à declaração friend.

O exemplo a seguir mostra o comportamento de C++17 no Visual Studio 2017 e posteriormente no modo **/std:c++17:**

```cpp
struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {}
};

struct Derived : Base {
    Derived() {} // add user-defined constructor
                 // to call with {} initialization
};

Derived d1; // OK. No aggregate init involved.

Derived d2 {}; // error C2248: 'Base::Base': cannot access
               // private member declared in class 'Base'
```

### <a name="constructors-for-classes-that-have-multiple-inheritance"></a>Construtores para classes que têm herança múltipla

Se uma classe for derivada de várias classes base, os construtores de classe base serão chamados na ordem em que estão listados na declaração da classe derivada:

```cpp
#include <iostream>
using namespace std;

class BaseClass1 {
public:
    BaseClass1() { cout << "BaseClass1 ctor\n"; }
};
class BaseClass2 {
public:
    BaseClass2() { cout << "BaseClass2 ctor\n"; }
};
class BaseClass3 {
public:
    BaseClass3() { cout << "BaseClass3 ctor\n"; }
};
class DerivedClass : public BaseClass1,
                     public BaseClass2,
                     public BaseClass3
                     {
public:
    DerivedClass() { cout << "DerivedClass ctor\n"; }
};

int main() {
    DerivedClass dc;
}
```

O seguinte resultado é esperado:

```Output
BaseClass1 ctor
BaseClass2 ctor
BaseClass3 ctor
DerivedClass ctor
```

## <a name="delegating-constructors"></a><a name="delegating_constructors"></a>Construtores delegantes

Um *construtor delegador* chama um construtor diferente na mesma classe para fazer parte do trabalho de inicialização. Isso é útil quando você tem vários construtores que todos têm que realizar trabalhos semelhantes. Você pode escrever a lógica principal em um construtor e invocá-la de outros. No exemplo trivial a seguir, box(int) delega seu trabalho à Caixa (int,int,int):

```cpp
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    Box(int i) :  Box(i, i, i);  // delegating constructor
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}
    //... rest of class as before
};
```

O objeto criado pelos construtores é inicializado totalmente assim que o construtor é concluído. Para obter mais informações, consulte [Delegating Constructors](../cpp/delegating-constructors.md).

## <a name="inheriting-constructors-c11"></a><a name="inheriting_constructors"></a>Construtores hereditários (C++11)

Uma classe derivada pode herdar os construtores de uma classe base direta usando uma declaração **de uso** como mostrado no exemplo a seguir:

```cpp
#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base()" << endl; }
    Base(const Base& other) { cout << "Base(Base&)" << endl; }
    explicit Base(int i) : num(i) { cout << "Base(int)" << endl; }
    explicit Base(char c) : letter(c) { cout << "Base(char)" << endl; }

private:
    int num;
    char letter;
};

class Derived : Base
{
public:
    // Inherit all constructors from Base
    using Base::Base;

private:
    // Can't initialize newMember from Base constructors.
    int newMember{ 0 };
};

int main()
{
    cout << "Derived d1(5) calls: ";
    Derived d1(5);
    cout << "Derived d1('c') calls: ";
    Derived d2('c');
    cout << "Derived d3 = d2 calls: " ;
    Derived d3 = d2;
    cout << "Derived d4 calls: ";
    Derived d4;
}

/* Output:
Derived d1(5) calls: Base(int)
Derived d1('c') calls: Base(char)
Derived d3 = d2 calls: Base(Base&)
Derived d4 calls: Base()*/
```

::: moniker range=">=vs-2017"

**Visual Studio 2017 e posterior**: A declaração **de uso** no modo **/std:c++17** traz em escopo todos os construtores da classe base, exceto aqueles que têm uma assinatura idêntica aos construtores na classe derivada. Em geral, é melhor usar construtores hereditários quando a classe derivada não declara novos membros de dados ou construtores. Veja também [Melhorias no Visual Studio 2017 versão 15.7](https://docs.microsoft.com/cpp/overview/cpp-conformance-improvements?view=vs-2017#improvements_157).

::: moniker-end

Um modelo de classe pode herdar todos os construtores a partir de um argumento de tipo se esse tipo especificar uma classe base:

```cpp
template< typename T >
class Derived : T {
    using T::T;   // declare the constructors from T
    // ...
};
```

Uma classe derivada não pode herdar de várias classes de base se essas classes base tiverem construtores que tenham uma assinatura idêntica.

## <a name="constructors-and-composite-classes"></a><a name="constructors_in_composite_classes"></a>Construtores e classes compostas

As classes que contêm membros do tipo de classe são conhecidas como *classes compostas*. Quando um membro do tipo classe de uma classe composta é criado, o construtor é chamado antes do próprio construtor da classe. Quando uma classe contida não possuir um construtor padrão, você deverá usar uma lista de inicialização no construtor da classe composta. No exemplo anterior de `StorageBox`, se você alterar o tipo da variável de membro `m_label` para uma nova classe `Label`, deverá chamar o construtor da classe base e inicializar a variável `m_label` no construtor `StorageBox`:

```cpp
class Label {
public:
    Label(const string& name, const string& address) { m_name = name; m_address = address; }
    string m_name;
    string m_address;
};

class StorageBox : public Box {
public:
    StorageBox(int width, int length, int height, Label label)
        : Box(width, length, height), m_label(label){}
private:
    Label m_label;
};

int main(){
// passing a named Label
    Label label1{ "some_name", "some_address" };
    StorageBox sb1(1, 2, 3, label1);

    // passing a temporary label
    StorageBox sb2(3, 4, 5, Label{ "another name", "another address" });

    // passing a temporary label as an initializer list
    StorageBox sb3(1, 2, 3, {"myname", "myaddress"});
}
```

## <a name="in-this-section"></a>Nesta seção

- [Copiar construtores e copiar operadores de atribuição](copy-constructors-and-copy-assignment-operators-cpp.md)
- [Mova construtores e mova operadores de atribuição](move-constructors-and-move-assignment-operators-cpp.md)
- [Construtores delegantes](delegating-constructors.md)

## <a name="see-also"></a>Confira também

[Aulas e estruturas](classes-and-structs-cpp.md)
