---
title: Construtores (C++)
ms.date: 04/06/2018
helpviewer_keywords:
- constructors [C++]
- objects [C++], creating
- instance constructors
ms.assetid: 3e9f7211-313a-4a92-9584-337452e061a9
ms.openlocfilehash: a45cee1abd9351a8fef56769706fe8944a7965b8
ms.sourcegitcommit: b72a10a7b12e722fd91a17406b91b270026f763a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/03/2019
ms.locfileid: "58898733"
---
# <a name="constructors-c"></a>Construtores (C++)

Para personalizar como os membros de classe são inicializados ou para invocar funções quando um objeto da classe é criado, defina uma *construtor*. Um construtor tem o mesmo nome que a classe e nenhum valor de retorno. Você pode definir quantos construtores sobrecarregados, conforme necessário, para personalizar a inicialização de várias maneiras. Normalmente, construtores ter acessibilidade pública, para que o código fora da hierarquia de herança ou definição de classe pode criar objetos da classe. Mas você também pode declarar um construtor como **protegidos** ou **privada**.

Os construtores podem usar, opcionalmente, um membro de lista de inicialização. Essa é uma maneira mais eficiente para inicializar membros de classe de atribuir valores no corpo do construtor. O exemplo a seguir mostra uma classe `Box` com três construtores sobrecarregados. As duas últimas usam listas de inicialização de membro:

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

Quando você declara uma instância de uma classe, o compilador escolhe qual construtor a ser invocado com base nas regras de resolução de sobrecarga:

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

- Construtores podem ser declarados como **embutido**, [explícita](#explicit_constructors), **amigo** ou [constexpr](#constexpr_constructors).
- Um construtor pode inicializar um objeto que foi declarado como **const**, **volátil** ou **const volátil**. O objeto se torna **const** depois que o construtor for concluído.
- Para definir um construtor em um arquivo de implementação, dê a ele um nome qualificado assim como acontece com qualquer outra função de membro: `Box::Box(){...}`.

## <a name="member_init_list"></a> Listas de inicializadores de membro

Um construtor pode, opcionalmente, ter uma lista de inicializador de membro, que inicializa membros de classe antes da execução do corpo do construtor. (Observe que uma lista de inicializadores de membro não é a mesma coisa que um *lista de inicializadores* do tipo [std:: initializer_list\<T >](../standard-library/initializer-list-class.md).)

Usar uma lista de inicializadores de membro é preferível atribuindo valores no corpo do construtor porque ela inicializa diretamente o membro. No exemplo a seguir mostra o inicializador de membro lista consiste em todos os **identifier(argument)** expressões após os dois-pontos:

```cpp
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}
```

O identificador deve se referir a um membro de classe; ele é inicializado com o valor do argumento. O argumento pode ser um dos parâmetros do construtor, uma chamada de função ou um [std:: initializer_list\<T >](../standard-library/initializer-list-class.md).

**Const** membros e membros de tipo de referência devem ser inicializados na lista de inicializadores de membro.

Chamadas para construtores de classe base com parâmetros devem ser feitas na lista de inicializadores para garantir que a classe base é totalmente inicializada antes da execução do construtor derivado.

## <a name="default_constructors"></a> Construtores padrão

*Padrão de construtores* normalmente não têm parâmetros, mas eles podem ter parâmetros com valores padrão.

```cpp
class Box {
public:
    Box() { /*perform any required default initialization steps*/}

    // All params have default values
    Box (int w = 1, int l = 1, int h = 1): m_width(w), m_height(h), m_length(l){}
...
}
```

Construtores padrão são um dos [funções de membro especial](special-member-functions.md). Se nenhum construtor for declarado em uma classe, o compilador fornece implícito **embutido** construtor padrão.

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

Se você confiar em um construtor padrão implícito, certifique-se de inicializar membros na definição de classe, conforme mostrado no exemplo anterior. Sem esses inicializadores, os membros seria não inicializados e a chamada Volume() produziria um valor de lixo. Em geral, é uma boa prática para inicializar os membros dessa forma, mesmo quando não se baseia em um construtor padrão implícito.

Você pode impedir que o compilador gerar um construtor padrão implícito, definindo-o como [excluído](#explicitly_defaulted_and_deleted_constructors):

```cpp
    // Default constructor
    Box() = delete;
```

Um construtor padrão gerado pelo compilador será definido como excluído se nenhum membro de classe não pode ser construído por padrão. Por exemplo, todos os membros de tipo de classe e seus membros de tipo de classe, devem ter um construtor padrão e os destruidores são acessíveis. Todos os membros de dados de referência de tipo, bem como **const** membros devem ter um inicializador de membro padrão.

Quando você chama um construtor padrão gerado pelo compilador e tenta usar parênteses, um aviso é emitido:

```cpp
class myclass{};
int main(){
myclass mc();     // warning C4930: prototyped function not called (was a variable definition intended?)
}
```

Este é um exemplo do problema Most Vexing Parse. Como a expressão de exemplo pode ser interpretada como a declaração de uma função ou como invocação de um construtor padrão, e como os analisadores de C++ preferem as declarações a outras coisas, a expressão é tratada como uma declaração de função. Para obter mais informações, consulte [Most Vexing Parse](http://en.wikipedia.org/wiki/Most_vexing_parse).

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

No entanto, você pode usar um conjunto de listas de inicializadores para inicializar uma matriz de objetos de caixa:

```cpp
Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
```

Para obter mais informações, consulte [inicializadores](initializers.md).

## <a name="copy_and_move_constructors"></a> Construtores de cópia

Um *construtor de cópia* inicializa um objeto, copiando os valores de membro de um objeto do mesmo tipo. Se seus membros de classe são todos os tipos simples como valores escalares, o construtor de cópia gerado pelo compilador é suficiente e você não precisa definir seu próprio. Se sua classe requer inicialização mais complexa, em seguida, você precisa implementar um construtor de cópia personalizada. Por exemplo, se um membro de classe for um ponteiro, em seguida, você precisa definir um construtor de cópia para alocar nova memória e copie os valores dos outros apontado para objeto. O construtor de cópia gerado pelo compilador simplesmente copia o ponteiro, para que o novo ponteiro ainda aponta para o local da memória do outro.

Um construtor de cópia pode ter um dessas assinaturas:

```cpp
    Box(Box& other); // Avoid if possible--allows modification of other.
    Box(const Box& other);
    Box(volatile Box& other);
    Box(volatile const Box& other);

    // Additional parameters OK if they have default values
    Box(Box& other, int i = 42, string label = "Box");
```

Quando você define um construtor de cópia, você também deve definir um operador de atribuição (=). Para obter mais informações, consulte [atribuição](assignment.md) e [construtores de cópia e copie os operadores de atribuição](copy-constructors-and-copy-assignment-operators-cpp.md).

Você pode impedir que seu objeto sendo copiados, definindo o construtor de cópia excluído:

```cpp
    Box (const Box& other) = delete;
```

A tentativa de copiar o objeto produz o erro *C2280: tentativa de fazer referência a uma função excluída*.

## <a name="move_constructors"></a> Construtores de movimentação

Um *construtor de movimentação* é uma função de membro especial que move a propriedade dos dados de um objeto existente a uma nova variável sem copiar os dados originais. Ele utiliza uma referência de rvalue como seu primeiro parâmetro e quaisquer parâmetros adicionais devem ter valores padrão. Construtores de movimentação podem aumentar significativamente a eficiência do seu programa ao passar em torno de objetos grandes. Um construtor de movimentação usa uma referência de rvalue como seu primeiro parâmetro. Todos os outros parâmetros devem ter valores padrão.

```cpp
Box(Box&& other);
```

O compilador escolhe um construtor de movimentação em certas situações em que o objeto está sendo inicializado por outro objeto do mesmo tipo que está prestes a ser destruído e não precisa mais ele recursos. O exemplo a seguir mostra um caso de quando um construtor de movimentação é selecionado por resolução de sobrecarga. A variável *caixa de* retornado pela get_Box() é um *xvalue* (valor expirando) que está prestes a sair do escopo. Para fornecer a motivação para este exemplo, vamos dar o caixa um grande vetor de cadeias de caracteres que representam seu conteúdo. Em vez de copiar o vetor e suas cadeias de caracteres, o construtor de movimentação "roube" do valor de expiração "caixa" para que o vetor agora pertence ao novo objeto. A chamada para `std::move` é tudo o que é necessário porque ambos `vector` e `string` classes implementam seus próprios construtores de movimentação.

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
    void Get_Contents()
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
    b2.Get_Contents(); // Prove that we have all the values

    char ch;
    cin >> ch; // keep window open
    return 0;
}
```

Se uma classe não definir um construtor de movimentação, o compilador gera um implícito, se não houver nenhum construtor de cópia declarado pelo usuário, o operador de atribuição de cópia, o operador de atribuição de movimentação ou o destruidor. Se nenhum construtor de movimentação explícita ou implícita é definido, as operações que usam, caso contrário, um construtor de movimentação usam o construtor de cópia em vez disso. Se uma classe declara um construtor de movimentação ou um operador de atribuição de movimentação, o construtor de cópia declarado implicitamente é definido como excluído.

Um construtor de movimentação declarada implicitamente é definido como excluído se todos os membros que são tipos de classe não têm um destruidor ou o compilador não pode determinar qual construtor a ser usado para a operação de movimentação.

Para obter mais informações sobre como escrever um construtor de movimentação não triviais, consulte [construtores Move e operadores de atribuição Move (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md).

## <a name="explicitly_defaulted_and_deleted_constructors"></a> Construtores explicitamente usadas como padrão e excluído

Você pode explicitamente *padrão* construtores de cópia, padrão construtores, construtores de movimentação, operadores de atribuição de copiar, mover os operadores de atribuição e destruidores. Você pode explicitamente *excluir* todas as funções de membro especial.

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

Para obter mais informações, consulte [explicitamente usadas como padrão e excluídas funções](../cpp/explicitly-defaulted-and-deleted-functions.md).

## <a name="constexpr_constructors"></a> construtores de constexpr

Um construtor pode ser declarado como [constexpr](constexpr-cpp.md) se

- é uma declarada como assume o padrão; caso contrário ele atende a todas as condições para [funções de constexpr](constexpr-cpp.md#constexpr_functions) em geral;
- a classe tem sem classes base virtuais;
- cada um dos parâmetros é um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types);
- o corpo não é um função bloco try;
- todos os membros de dados não estáticos e subobjetos de classe base são inicializados;
- Se a classe é (a) uma união ter membros variantes ou (b) tem as uniões anônimas, apenas um dos membros da união é inicializado;
- cada membro de dados não estáticos do tipo de classe e todos os objetos de subpropriedades de classe base tem um construtor constexpr

## <a name="init_list_constructors"></a> Construtores de lista do inicializador

Se um construtor com um [std:: initializer_list\<T\> ](../standard-library/initializer-list-class.md) como seu parâmetro e quaisquer outros parâmetros têm argumentos padrão, esse construtor será selecionado na resolução de sobrecarga quando a classe é uma instância criada por meio de inicialização direta. Você pode usar o initializer_list para inicializar qualquer membro que pode aceitá-lo. Por exemplo, suponha que a classe de caixa (mostrada anteriormente) tem um `std::vector<string>` membro `m_contents`. Você pode fornecer um construtor como este:

```cpp
    Box(initializer_list<string> list, int w = 0, int h = 0, int l = 0)
        : m_contents(list), m_width(w), m_height(h), m_length(l)
{}
```

E, em seguida, criar objetos de caixa como este:

```cpp
    Box b{ "apples", "oranges", "pears" }; // or ...
    Box b2(initializer_list<string> { "bread", "cheese", "wine" }, 2, 4, 6);
```

## <a name="explicit_constructors"></a> Construtores explícitos

Se uma classe tem um construtor com um único parâmetro, ou se todos os parâmetros, exceto um tem um valor padrão, o tipo de parâmetro pode ser convertido implicitamente no tipo de classe. Por exemplo, se o `Box` classe tem um construtor como este:

```cpp
Box(int size): m_width(size), m_length(size), m_height(size){}
```

É possível inicializar uma caixa como esta:

```cpp
Box b = 42;
```

Ou passar um int para uma função que usa uma caixa:

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

Essas conversões podem ser útil em alguns casos, mas com mais frequência, eles podem levar a sutis, mas sérios erros em seu código. Como regra geral, você deve usar o **explícita** palavra-chave em um construtor (e operadores definidos pelo usuário) para impedir que esse tipo de conversão implícita de tipos:

```cpp
explicit Box(int size): m_width(size), m_length(size), m_height(size){}
```

Quando o construtor é explícito, esta linha faz com que um erro do compilador: `ShippingOrder so(42, 10.8);`.  Para obter mais informações, consulte [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

## <a name="order_of_construction"></a> Ordem de construção

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

Um construtor de classe derivada sempre chama um construtor de classe base, de modo que possa confiar em classes base completamente construídas antes que qualquer trabalho adicional seja feito. Os construtores de classe base são chamados na ordem de derivação — por exemplo, se `ClassA` é derivado de `ClassB`, que é derivado de `ClassC`, o `ClassC` construtor é chamado pela primeira vez, o `ClassB` construtor, em seguida, a `ClassA` construtor.

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

### <a name="constructors-for-classes-that-have-multiple-inheritance"></a>Construtores para classes que têm várias heranças

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

## <a name="virtual_functions_in_constructors"></a> Funções virtuais em construtores

Recomendamos que você seja cuidadoso ao chamar funções virtuais nos construtores. Como o construtor da classe base é sempre chamado antes do construtor de classe derivada, a função que é chamada no construtor de base é a versão da classe base, não a versão da classe derivada. No exemplo a seguir, construir `DerivedClass` faz com que a implementação de `BaseClass` de `print_it()` seja executada antes que o construtor de `DerivedClass` faça com que a implementação de `DerivedClass` de `print_it()` seja executada:

```cpp
#include <iostream>
using namespace std;

class BaseClass{
public:
    BaseClass(){
        print_it();
    }
    virtual void print_it() {
        cout << "BaseClass print_it" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass() {
        print_it();
    }
    virtual void print_it(){
        cout << "Derived Class print_it" << endl;
    }
};

int main() {

    DerivedClass dc;
}
```

Este é o resultado:

```Output
BaseClass print_it
Derived Class print_it
```

## <a name="delegating_constructors"></a> Delegação de construtores

Um *construtor de delegação* chama um construtor diferente na mesma classe para fazer parte do trabalho de inicialização. Isso é útil quando você tem vários construtores que todos precisam executar um trabalho semelhante. Você pode escrever a lógica principal em um construtor e invocá-lo de outras pessoas. No exemplo a seguir trivial, Box(int) delega seu trabalho para Box(int,int,int):

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

O objeto criado pelos construtores é inicializado totalmente assim que o construtor é concluído. Para obter mais informações, consulte [inicialização uniforme e delegação de construtores](../cpp/uniform-initialization-and-delegating-constructors.md).

## <a name="inheriting_constructors"></a> Herdar construtores (c++11)

Uma classe derivada pode herdar os construtores de uma classe base direta usando um **usando** declaração conforme mostrado no exemplo a seguir:

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

**Visual Studio 2017 versão 15.7 e posteriores**: O **usando** instrução no **/std: c + + 17** modo traz para o escopo de todos os construtores da classe base, exceto aqueles que têm uma assinatura idêntica à construtores na classe derivada. Em geral, é melhor usar herança construtores, quando a classe derivada não declara nenhum membro de dados novo ou construtores. Consulte também [melhorias no Visual Studio 2017 versão 15.7](../overview/cpp-conformance-improvements.md#improvements_157).

Um modelo de classe pode herdar todos os construtores de um argumento de tipo, se esse tipo Especifica uma classe base:

```cpp
template< typename T >
class Derived : T {
    using T::T;   // declare the constructors from T
    // ...
};
```

Uma classe derivada não pode herdar de múltiplas classes base se essas classes base têm construtores que têm uma assinatura idêntica.

## <a name="constructors_in_composite_classes"></a> Construtores e classes compostas

Classes que contêm membros de tipo de classe são conhecidas como *classes compostas*. Quando um membro do tipo classe de uma classe composta é criado, o construtor é chamado antes do próprio construtor da classe. Quando uma classe contida não possuir um construtor padrão, você deverá usar uma lista de inicialização no construtor da classe composta. No exemplo anterior de `StorageBox`, se você alterar o tipo da variável de membro `m_label` para uma nova classe `Label`, deverá chamar o construtor da classe base e inicializar a variável `m_label` no construtor `StorageBox`:

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
