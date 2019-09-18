---
title: Construtores (C++)
ms.date: 09/05/2019
helpviewer_keywords:
- constructors [C++]
- objects [C++], creating
- instance constructors
ms.assetid: 3e9f7211-313a-4a92-9584-337452e061a9
ms.openlocfilehash: 0e2e3536c8eb0a5b111ff18e43044783ea684f1f
ms.sourcegitcommit: bf724dfc639b16d5410fab72183f8e6b781338bc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2019
ms.locfileid: "71062025"
---
# <a name="constructors-c"></a>Construtores (C++)

Para personalizar como os membros de classe são inicializados ou para invocar funções quando um objeto da sua classe é criado, defina um *Construtor*. Um construtor tem o mesmo nome que a classe e nenhum valor de retorno. Você pode definir quantos construtores sobrecarregados forem necessários para personalizar a inicialização de várias maneiras. Normalmente, os construtores têm acessibilidade pública para que o código fora da definição de classe ou da hierarquia de herança possa criar objetos da classe. Mas você também pode declarar um construtor como **protegido** ou **privado**.

Os construtores podem, opcionalmente, usar uma lista inicial de membros. Essa é uma maneira mais eficiente de inicializar membros de classe do que atribuir valores no corpo do construtor. O exemplo a seguir mostra uma `Box` classe com três construtores sobrecarregados. As duas últimas usam listas de iniciais de membros:

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

Quando você declara uma instância de uma classe, o compilador escolhe qual Construtor invocar com base nas regras de resolução de sobrecarga:

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

- Os construtores podem ser declarados como **embutidos**, [explícitos](#explicit_constructors), **Friend** ou [constexpr](#constexpr_constructors).
- Um construtor pode inicializar um objeto que foi declarado como **const**, **volátil** ou **const volátil**. O objeto se torna **const** após a conclusão do construtor.
- Para definir um construtor em um arquivo de implementação, dê a ele um nome qualificado como com qualquer outra função `Box::Box(){...}`de membro:.

## <a name="member_init_list"></a>Listas de inicializadores de membros

Um construtor, opcionalmente, pode ter uma lista de inicializadores de membros, que Inicializa membros de classe antes da execução do corpo do construtor. (Observe que uma lista de inicializadores de membros não é a mesma coisa que uma *lista de inicializadores* do tipo [std::\<initializer_list T >](../standard-library/initializer-list-class.md).)

O uso de uma lista de inicializadores de membros é preferível ao atribuir valores no corpo do Construtor, pois inicializa diretamente o membro. No exemplo a seguir, mostra que a lista de inicializadores de membro consiste em todas as expressões de **identificador (argumento)** após os dois-pontos:

```cpp
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}
```

O identificador deve se referir a um membro de classe; Ele é inicializado com o valor do argumento. O argumento pode ser um dos parâmetros do Construtor, uma chamada de função ou um [std::\<initializer_list T >](../standard-library/initializer-list-class.md).

Membros **const** e membros do tipo de referência devem ser inicializados na lista de inicializadores de membros.

As chamadas para construtores de classe base com parâmetros devem ser feitas na lista de inicializadores para garantir que a classe base seja totalmente inicializada antes da execução do Construtor derivado.

## <a name="default_constructors"></a>Construtores padrão

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

Os construtores padrão são uma das [funções de membro especiais](special-member-functions.md). Se nenhum construtor for declarado em uma classe, o compilador fornecerá um construtor padrão **embutido** implícito.

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

Se você depender de um construtor padrão implícito, certifique-se de inicializar os membros na definição de classe, conforme mostrado no exemplo anterior. Sem esses inicializadores, os membros não são inicializados e a chamada de volume () produziria um valor de lixo. Em geral, é uma boa prática inicializar membros dessa maneira mesmo quando não depender de um construtor padrão implícito.

Você pode impedir que o compilador gere um construtor padrão implícito definindo-o como [excluído](#explicitly_defaulted_and_deleted_constructors):

```cpp
    // Default constructor
    Box() = delete;
```

Um construtor padrão gerado pelo compilador será definido como excluído se qualquer membro de classe não for default-constructible. Por exemplo, todos os membros do tipo de classe e seus membros de tipo de classe, devem ter um construtor padrão e destruidores acessíveis. Todos os membros de dados do tipo de referência, bem como membros **const** , devem ter um inicializador de membro padrão.

Quando você chama um construtor padrão gerado pelo compilador e tenta usar parênteses, um aviso é emitido:

```cpp
class myclass{};
int main(){
myclass mc();     // warning C4930: prototyped function not called (was a variable definition intended?)
}
```

Este é um exemplo do problema Most Vexing Parse. Como a expressão de exemplo pode ser interpretada como a declaração de uma função ou como invocação de um construtor padrão, e como os analisadores de C++ preferem as declarações a outras coisas, a expressão é tratada como uma declaração de função. Para obter mais informações, consulte [análise mais irritante](https://en.wikipedia.org/wiki/Most_vexing_parse).

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

No entanto, você pode usar um conjunto de listas de inicializadores para inicializar uma matriz de objetos Box:

```cpp
Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
```

Para obter mais informações, consulte [inicializadores](initializers.md).

## <a name="copy_and_move_constructors"></a>Copiar construtores

Um *Construtor de cópia* Inicializa um objeto copiando os valores de membro de um objeto do mesmo tipo. Se os membros de sua classe forem todos tipos simples, como valores escalares, o construtor de cópia gerado pelo compilador será suficiente e você não precisará definir o seu próprio. Se sua classe exigir inicialização mais complexa, você precisará implementar um construtor de cópia personalizado. Por exemplo, se um membro de classe for um ponteiro, você precisará definir um construtor de cópia para alocar uma nova memória e copiar os valores do objeto apontado de outro. O construtor de cópia gerado pelo compilador simplesmente copia o ponteiro, para que o novo ponteiro ainda aponte para o local da memória do outro.

Um construtor de cópia pode ter uma destas assinaturas:

```cpp
    Box(Box& other); // Avoid if possible--allows modification of other.
    Box(const Box& other);
    Box(volatile Box& other);
    Box(volatile const Box& other);

    // Additional parameters OK if they have default values
    Box(Box& other, int i = 42, string label = "Box");
```

Ao definir um construtor de cópia, você também deve definir um operador de atribuição de cópia (=). Para obter mais informações, consulte construtores de [atribuição](assignment.md) e de [cópia e operadores de atribuição de cópia](copy-constructors-and-copy-assignment-operators-cpp.md).

Você pode impedir que o objeto seja copiado definindo o construtor de cópia como excluído:

```cpp
    Box (const Box& other) = delete;
```

A tentativa de copiar o objeto produz o erro *C2280: tentando fazer referência a uma função excluída*.

## <a name="move_constructors"></a>Mover construtores

Um *Construtor move* é uma função de membro especial que move a propriedade dos dados de um objeto existente para uma nova variável sem copiar os dados originais. Ele usa uma referência rvalue como seu primeiro parâmetro e os parâmetros adicionais devem ter valores padrão. Os construtores de movimentação podem aumentar significativamente a eficiência do seu programa ao passar objetos grandes. Um construtor de movimentação usa uma referência rvalue como seu primeiro parâmetro. Quaisquer outros parâmetros devem ter valores padrão.

```cpp
Box(Box&& other);
```

O compilador escolhe um Construtor move em determinadas situações em que o objeto está sendo inicializado por outro objeto do mesmo tipo que está prestes a ser destruído e não precisa mais de recursos de ti. O exemplo a seguir mostra um caso quando um Construtor move é selecionado pela resolução de sobrecarga. A *caixa* variável retornada por get_Box () é um *xValue* (valor de expiração) que está prestes a sair do escopo. Para fornecer motivação para este exemplo, vamos dar ao box um grande vetor de cadeias de caracteres que representam seu conteúdo. Em vez de copiar o vetor e suas cadeias de caracteres, o Construtor move "rouba" do valor de expiração "box" para que o vetor agora pertença ao novo objeto. A chamada para `std::move` é tudo o que é necessário porque `vector` ambas `string` as classes e implementam seus próprios construtores de movimentação.

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

Se uma classe não definir um construtor de movimentação, o compilador gerará um implícito se não houver nenhum construtor de cópia declarado pelo usuário, operador de atribuição de cópia, operador de atribuição de movimento ou destruidor. Se nenhum construtor de movimentação explícito ou implícito for definido, as operações que, de outra forma, usarão um construtor de movimentação usarão o construtor de cópia em vez disso. Se uma classe declarar um Construtor mover ou mover o operador de atribuição, o construtor de cópia implicitamente declarado será definido como excluído.

Um construtor de movimentação implicitamente declarado é definido como excluído se qualquer membro que é de tipos de classe não tem um destruidor ou o compilador não pode determinar qual Construtor usar para a operação de movimentação.

Para obter mais informações sobre como escrever um construtor de movimentação não trivial, consulte [mover construtores e mover operadores de atribuição (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md).

## <a name="explicitly_defaulted_and_deleted_constructors"></a>Construtores padronizados e excluídos explicitamente

Você pode explicitamente *padronizar* construtores de cópia, construtores padrão, construtores de movimentação, operadores de atribuição de cópia, operadores de atribuição de movimento e destruidores. Você pode *excluir* explicitamente todas as funções de membro especiais.

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

Para obter mais informações, consulte [funções explicitamente padronizadas e excluídas](../cpp/explicitly-defaulted-and-deleted-functions.md).

## <a name="constexpr_constructors"></a>construtores constexpr

Um construtor pode ser declarado como [constexpr](constexpr-cpp.md) se

- Ele é declarado como padrão ou atende a todas as condições para [funções constexpr](constexpr-cpp.md#constexpr_functions) em geral;
- a classe não tem classes base virtuais;
- cada um dos parâmetros é um [tipo literal](trivial-standard-layout-and-pod-types.md#literal_types);
- o corpo não é uma função de bloco try;
- todos os membros de dados não estáticos e subobjetos de classe base são inicializados;
- se a classe for (a) uma União com membros de variante ou (b) tiver uniões anônimas, somente um dos membros da União será inicializado;
- cada membro de dados não estático do tipo de classe e todos os subobjetos de classe base têm um Construtor constexpr

## <a name="init_list_constructors"></a>Construtores da lista de inicializadores

Se um construtor usar um [std:: initializer_list\<\> ](../standard-library/initializer-list-class.md) como seu parâmetro e quaisquer outros parâmetros tiverem argumentos padrão, esse construtor será selecionado na resolução de sobrecarga quando a classe for instanciada por meio do Direct Initialization. Você pode usar o initializer_list para inicializar qualquer membro que possa aceitá-lo. Por exemplo, suponha que a classe Box (mostrada anteriormente) `std::vector<string>` tenha `m_contents`um membro. Você pode fornecer um construtor como este:

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

## <a name="explicit_constructors"></a>Construtores explícitos

Se uma classe tiver um construtor com um único parâmetro ou se todos os parâmetros, exceto um, tiverem um valor padrão, o tipo de parâmetro poderá ser convertido implicitamente no tipo de classe. Por exemplo, se a `Box` classe tiver um construtor como este:

```cpp
Box(int size): m_width(size), m_length(size), m_height(size){}
```

É possível inicializar uma caixa como esta:

```cpp
Box b = 42;
```

Ou passe um int para uma função que usa uma caixa:

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

Essas conversões podem ser úteis em alguns casos, mas com mais frequência elas podem levar a erros sutis e graves em seu código. Como regra geral, você deve usar a palavra-chave **Explicit** em um Construtor (e operadores definidos pelo usuário) para evitar esse tipo de conversão de tipo implícito:

```cpp
explicit Box(int size): m_width(size), m_length(size), m_height(size){}
```

Quando o construtor é explícito, essa linha causa um erro do compilador `ShippingOrder so(42, 10.8);`:.  Para obter mais informações, consulte [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).

## <a name="order_of_construction"></a>Ordem de construção

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

Um construtor de classe derivada sempre chama um construtor de classe base, de modo que possa confiar em classes base completamente construídas antes que qualquer trabalho adicional seja feito. Os construtores de classe base são chamados em ordem de derivação — por exemplo, `ClassA` se for derivado `ClassB`de, que é derivado `ClassC`de, `ClassC` o Construtor será chamado primeiro, depois `ClassB` o construtor e, em seguida, o `ClassA` Construtor.

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

## <a name="delegating_constructors"></a>Delegando construtores

Um *Construtor de delegação* chama um Construtor diferente na mesma classe para fazer parte do trabalho de inicialização. Isso é útil quando você tem vários construtores que têm de executar trabalho semelhante. Você pode gravar a lógica principal em um construtor e chamá-la de outras. No exemplo trivial a seguir, Box (int) Delega seu trabalho à caixa (int, int, int):

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

O objeto criado pelos construtores é inicializado totalmente assim que o construtor é concluído. Para obter mais informações, consulte [inicialização uniforme e construtores de delegação](../cpp/uniform-initialization-and-delegating-constructors.md).

## <a name="inheriting_constructors"></a>Herdando construtores (C++ 11)

Uma classe derivada pode herdar os construtores de uma classe base direta usando uma declaração **using** , conforme mostrado no exemplo a seguir:

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

**Visual Studio 2017 versão 15.7 e posteriores**: A instrução **using** no modo **/std: c++ 17** coloca em escopo todos os construtores da classe base, exceto aqueles que têm uma assinatura idêntica aos construtores na classe derivada. Em geral, é melhor usar construtores de herança quando a classe derivada declara não novos membros de dados ou construtores. Consulte também [aprimoramentos no Visual Studio 2017 versão 15,7](https://docs.microsoft.com/cpp/overview/cpp-conformance-improvements?view=vs-2017#improvements_157).

::: moniker-end

Um modelo de classe pode herdar todos os construtores de um argumento de tipo se esse tipo especificar uma classe base:

```cpp
template< typename T >
class Derived : T {
    using T::T;   // declare the constructors from T
    // ...
};
```

Uma classe derivada não pode herdar de várias classes base se essas classes base têm construtores que têm uma assinatura idêntica.

## <a name="constructors_in_composite_classes"></a>Construtores e classes compostas

As classes que contêm membros de tipo de classe são conhecidas como *classes compostas*. Quando um membro do tipo classe de uma classe composta é criado, o construtor é chamado antes do próprio construtor da classe. Quando uma classe contida não possuir um construtor padrão, você deverá usar uma lista de inicialização no construtor da classe composta. No exemplo anterior de `StorageBox`, se você alterar o tipo da variável de membro `m_label` para uma nova classe `Label`, deverá chamar o construtor da classe base e inicializar a variável `m_label` no construtor `StorageBox`:

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
