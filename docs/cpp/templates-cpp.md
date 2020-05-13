---
title: Modelos (C++)
ms.date: 12/27/2019
f1_keywords:
- template_cpp
helpviewer_keywords:
- templates, C++
- templates [C++]
ms.assetid: 90fcc14a-2092-47af-9d2e-dba26d25b872
ms.openlocfilehash: e47f00c7e387974c7d1756cf3ee3865f892e6951
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032337"
---
# <a name="templates-c"></a>Modelos (C++)

Os modelos são a base para a programação genérica em C++. Como uma linguagem fortemente digitada, c++ requer que todas as variáveis tenham um tipo específico, explicitamente declarado pelo programador ou deduzido pelo compilador. No entanto, muitas estruturas de dados e algoritmos parecem iguais, não importa em que tipo estejam operando. Os modelos permitem definir as operações de uma classe ou função e permitem que o usuário especifique em quais tipos de concreto essas operações devem funcionar.

## <a name="defining-and-using-templates"></a>Definição e utilização de modelos

Um modelo é um modelo que gera um tipo ou função comum no tempo de compilação com base nos argumentos que o usuário fornece para os parâmetros do modelo. Por exemplo, você pode definir um modelo de função como este:

```cpp
template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

O código acima descreve um modelo para uma função genérica com um parâmetro de tipo único *T*, cujo valor de retorno e parâmetros de chamada (lhs e rhs) são todos deste tipo. Você pode nomear um parâmetro de tipo o que quiser, mas por convenção letras maiúsculas são mais usadas. *T* é um parâmetro de modelo; a **palavra-chave tipo** diz que este parâmetro é um espaço reservado para um tipo. Quando a função é chamada, o compilador `T` substituirá todas as instâncias do argumento de tipo concreto que é especificado pelo usuário ou deduzido pelo compilador. O processo no qual o compilador gera uma classe ou função a partir de um modelo é referido como *instanciação do modelo;* `minimum<int>` é uma instanciação `minimum<T>`do modelo.

Em outros lugares, um usuário pode declarar uma instância do modelo especializado para int. Assuma que get_a() e get_b() são funções que retornam um int:

```cpp
int a = get_a();
int b = get_b();
int i = minimum<int>(a, b);
```

No entanto, como este é um modelo de função `T` e o compilador pode deduzir o tipo de dos argumentos *a* e *b,* você pode chamá-lo como uma função comum:

```cpp
int i = minimum(a, b);
```

Quando o compilador encontra essa última declaração, ele gera uma nova função na qual cada ocorrência de *T* no modelo é substituída por **int**:

```cpp
int minimum(const int& lhs, const int& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

As regras para o desempenho do compilador em modelos de função são baseadas nas regras para funções ordinárias. Para obter mais informações, consulte [A resolução de sobrecarga das chamadas do modelo de função](../cpp/overload-resolution-of-function-template-calls.md).

## <a name="type-parameters"></a><a id="type_parameters"></a>Parâmetros de tipo

No `minimum` modelo acima, observe que o parâmetro de tipo *T* não é qualificado de forma alguma até que seja usado nos parâmetros de chamada de função, onde os qualificadores de const e referência são adicionados.

Não há limite prático para o número de parâmetros do tipo. Separe vários parâmetros por commas:

```cpp
template <typename T, typename U, typename V> class Foo{};
```

A **classe** de palavras-chave é equivalente ao **nome de digitação** neste contexto. Você pode expressar o exemplo anterior como:

```cpp
template <class T, class U, class V> class Foo{};
```

Você pode usar o operador de elipse (...) para definir um modelo que leva um número arbitrário de parâmetros de tipo zero ou mais:

```cpp
template<typename... Arguments> class vtclass;

vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;
```

Qualquer tipo integrado ou definido pelo usuário pode ser usado como um argumento de tipo. Por exemplo, você pode usar [std::vetor](../standard-library/vector-class.md) na Biblioteca Padrão para armazenar variáveis do `MyClass`tipo **int,** **duplo**, [std::string](../standard-library/basic-string-class.md), **const** `MyClass`*, `MyClass&`e assim por diante. A principal restrição ao usar modelos é que um argumento de tipo deve suportar quaisquer operações que sejam aplicadas aos parâmetros do tipo. Por exemplo, se `minimum` `MyClass` chamarmos usar como neste exemplo:

```cpp
class MyClass
{
public:
    int num;
    std::wstring description;
};

int main()
{
    MyClass mc1 {1, L"hello"};
    MyClass mc2 {2, L"goodbye"};
    auto result = minimum(mc1, mc2); // Error! C2678
}
```

Um erro do compilador `MyClass` será gerado porque não **<** fornece uma sobrecarga para o operador.

Não há nenhuma exigência inerente de que os argumentos de tipo para qualquer modelo específico pertencem à mesma hierarquia de objeto, embora você possa definir um modelo que imponha tal restrição. Você pode combinar técnicas orientadas a objetos com modelos; por exemplo, você pode armazenar um\<Derivado* em uma base\* vetorial>.    Note que os argumentos devem ser ponteiros

```cpp
vector<MyClass*> vec;
   MyDerived d(3, L"back again", time(0));
   vec.push_back(&d);

   // or more realistically:
   vector<shared_ptr<MyClass>> vec2;
   vec2.push_back(make_shared<MyDerived>());
```

Os requisitos `std::vector` básicos que e outros contêineres de biblioteca padrão impõem aos elementos são `T` que `T` sejam atribuíveis à cópia e à cópia.

## <a name="non-type-parameters"></a>Parâmetros não-tipo

Ao contrário de tipos genéricos em outras línguas, como C# e Java, os modelos C++ suportam *parâmetros não-tipo,* também chamados de parâmetros de valor. Por exemplo, você pode fornecer um valor integral constante para especificar o comprimento de uma matriz, como com este exemplo que é semelhante à classe [std::array](../standard-library/array-class-stl.md) na Biblioteca Padrão:

```cpp
template<typename T, size_t L>
class MyArray
{
    T arr[L];
public:
    MyArray() { ... }
};
```

Observe a sintaxe na declaração do modelo. O `size_t` valor é passado como um argumento de modelo no momento da compilação e deve ser **const** ou uma expressão **constexpr.** Você usa assim:

```cpp
MyArray<MyClass*, 10> arr;
```

Outros tipos de valores, incluindo ponteiros e referências, podem ser passados como parâmetros não-tipo. Por exemplo, você pode passar em um ponteiro para uma função ou objeto de função para personalizar alguma operação dentro do código do modelo.

### <a name="type-deduction-for-non-type-template-parameters"></a>Dedução de tipo para parâmetros de modelo não-tipo

No Visual Studio 2017 e posteriormente, no modo **/std:c++17,** o compilador deduz o tipo de argumento de modelo não-tipo que é declarado com **auto**:

```cpp
template <auto x> constexpr auto constant = x;

auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
```

## <a name="templates-as-template-parameters"></a><a id="template_parameters"></a>Modelos como parâmetros de modelo

Um modelo pode ser um parâmetro de modelo. Neste exemplo, myClass2 tem dois parâmetros de modelo: um parâmetro de nome de digitação *T* e um parâmetro de modelo *Arr*:

```cpp
template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
    U u; //Error. U not in scope
};
```

Como o parâmetro *Arr* em si não tem corpo, seus nomes de parâmetros não são necessários. Na verdade, é um erro se referir ao nome de digitação ou `MyClass2`parâmetro de classe de *Arr*de dentro do corpo de . Por essa razão, os nomes dos parâmetros de tipo do *Arr*podem ser omitidos, como mostrado neste exemplo:

```cpp
template<typename T, template<typename, int> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
};
```

## <a name="default-template-arguments"></a>Argumentos de modelo padrão

Modelos de classe e função podem ter argumentos padrão. Quando um modelo tem um argumento padrão, você pode deixá-lo não especificado quando você o usa. Por exemplo, o modelo std::vector tem um argumento padrão para o alocador:

```cpp
template <class T, class Allocator = allocator<T>> class vector;
```

Na maioria dos casos, a classe padrão de dst::alocador é aceitável, então você usa um vetor como este:

```cpp
vector<int> myInts;
```

Mas, se necessário, você pode especificar um alocador personalizado como este:

```cpp
vector<int, MyAllocator> ints;
```

Para mais argumentos de modelo, todos os argumentos após o primeiro argumento padrão devem ter argumentos padrão.

Ao usar um modelo cujos parâmetros estão todos inadimplentes, use suportes de ângulo vazios:

```cpp
template<typename A = int, typename B = double>
class Bar
{
    //...
};
...
int main()
{
    Bar<> bar; // use all default type arguments
}
```

## <a name="template-specialization"></a>Especialização de modelo

Em alguns casos, não é possível ou desejável que um modelo defina exatamente o mesmo código para qualquer tipo. Por exemplo, você pode querer definir um caminho de código a ser executado apenas se o argumento de tipo for um ponteiro ou um std::wstring ou um tipo derivado de uma classe base específica.  Nesses casos, você pode definir uma *especialização* do modelo para esse tipo específico. Quando um usuário instancia o modelo com esse tipo, o compilador usa a especialização para gerar a classe, e para todos os outros tipos, o compilador escolhe o modelo mais geral. Especializações em que todos os parâmetros são especializados são *especializações completas.* Se apenas alguns dos parâmetros forem especializados, é chamada *de especialização parcial.*

```cpp
template <typename K, typename V>
class MyMap{/*...*/};

// partial specialization for string keys
template<typename V>
class MyMap<string, V> {/*...*/};
...
MyMap<int, MyClass> classes; // uses original template
MyMap<string, MyClass> classes2; // uses the partial specialization
```

Um modelo pode ter qualquer número de especializações, desde que cada parâmetro de tipo especializado seja único. Apenas modelos de classe podem ser parcialmente especializados. Todas as especializações completas e parciais de um modelo devem ser declaradas no mesmo namespace do modelo original.

Para obter mais informações, consulte [Especialização de modelos](../cpp/template-specialization-cpp.md).
