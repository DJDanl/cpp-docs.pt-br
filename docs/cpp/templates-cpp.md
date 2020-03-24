---
title: Modelos (C++)
ms.date: 12/27/2019
f1_keywords:
- template_cpp
helpviewer_keywords:
- templates, C++
- templates [C++]
ms.assetid: 90fcc14a-2092-47af-9d2e-dba26d25b872
ms.openlocfilehash: 5f8322d850084ca53e946dcff1b67dc81b493fe3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160769"
---
# <a name="templates-c"></a>Modelos (C++)

Os modelos são a base para a programação C++genérica no. Como uma linguagem fortemente tipada, C++ o requer que todas as variáveis tenham um tipo específico, explicitamente declarado pelo programador ou deduzido pelo compilador. No entanto, muitas estruturas de dados e algoritmos têm a mesma aparência, independentemente do tipo em que estão operando. Os modelos permitem que você defina as operações de uma classe ou função e permita que o usuário especifique em quais tipos concretos essas operações devem trabalhar.

## <a name="defining-and-using-templates"></a>Definindo e usando modelos

Um modelo é um constructo que gera um tipo ou função comum em tempo de compilação com base nos argumentos que o usuário fornece para os parâmetros de modelo. Por exemplo, você pode definir um modelo de função como este:

```cpp
template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

O código acima descreve um modelo para uma função genérica com um parâmetro de tipo único *T*, cujo valor de retorno e parâmetros de chamada (LHS e RHS) são todos desse tipo. Você pode nomear um parâmetro de tipo como desejar, mas por convenção letras maiúsculas únicas são usadas com mais frequência. *T* é um parâmetro de modelo; a palavra-chave **TypeName** indica que esse parâmetro é um espaço reservado para um tipo. Quando a função é chamada, o compilador substituirá todas as instâncias de `T` pelo argumento de tipo concreto que é especificado pelo usuário ou deduzido pelo compilador. O processo no qual o compilador gera uma classe ou função de um modelo é conhecida como *instanciação de modelo*; `minimum<int>` é uma instanciação do modelo `minimum<T>`.

Em outro lugar, um usuário pode declarar uma instância do modelo especializado para int. suponha que get_a () e get_b () sejam funções que retornam um int:

```cpp
int a = get_a();
int b = get_b();
int i = minimum<int>(a, b);
```

No entanto, como esse é um modelo de função e o compilador pode deduzir o tipo de `T` *dos argumentos a* e *b*, você pode chamá-lo exatamente como uma função comum:

```cpp
int i = minimum(a, b);
```

Quando o compilador encontra essa última instrução, ele gera uma nova função na qual cada ocorrência de *T* no modelo é substituída por **int**:

```cpp
int minimum(const int& lhs, const int& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

As regras de como o compilador executa a dedução de tipo nos modelos de função baseiam-se nas regras para funções comuns. Para obter mais informações, consulte [sobrecarga de chamadas de modelo de função](../cpp/overload-resolution-of-function-template-calls.md).

## <a name="type-parameters"></a><a id="type_parameters"></a>Parâmetros de tipo

No modelo de `minimum` acima, observe que o parâmetro de tipo *t* não está qualificado de forma alguma até que seja usado nos parâmetros de chamada de função, onde os qualificadores const e Reference são adicionados.

Não há nenhum limite prático para o número de parâmetros de tipo. Separe vários parâmetros por vírgulas:

```cpp
template <typename T, typename U, typename V> class Foo{};
```

A **classe** keyword é equivalente a **TypeName** neste contexto. Você pode expressar o exemplo anterior como:

```cpp
template <class T, class U, class V> class Foo{};
```

Você pode usar o operador de reticências (...) para definir um modelo que usa um número arbitrário de zero ou mais parâmetros de tipo:

```cpp
template<typename... Arguments> class vtclass;

vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;
```

Qualquer tipo interno ou definido pelo usuário pode ser usado como um argumento de tipo. Por exemplo, você pode usar [std:: vector](../standard-library/vector-class.md) na biblioteca padrão para armazenar variáveis do tipo **int**, **Double**, [std:: String](../standard-library/basic-string-class.md), `MyClass`, **const** `MyClass`*, `MyClass&`e assim por diante. A restrição principal ao usar modelos é que um argumento de tipo deve dar suporte a quaisquer operações que são aplicadas aos parâmetros de tipo. Por exemplo, se chamarmos `minimum` usando `MyClass` como neste exemplo:

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

Um erro do compilador será gerado porque `MyClass` não fornece uma sobrecarga para o operador **<** .

Não há nenhum requisito inerente de que os argumentos de tipo para qualquer modelo específico pertençam à mesma hierarquia de objetos, embora você possa definir um modelo que impõe tal restrição. Você pode combinar técnicas orientadas a objeto com modelos; por exemplo, você pode armazenar um * derivado em um vetor\<\*base >.    Observe que os argumentos devem ser ponteiros

```cpp
vector<MyClass*> vec;
   MyDerived d(3, L"back again", time(0));
   vec.push_back(&d);

   // or more realistically:
   vector<shared_ptr<MyClass>> vec2;
   vec2.push_back(make_shared<MyDerived>());
```

Os requisitos básicos que `std::vector` e outros contêineres de biblioteca padrão impõem elementos de `T` é que `T` ser Copy-atribuível e Copy-constructible.

## <a name="non-type-parameters"></a>Parâmetros sem tipo

Ao contrário dos tipos genéricos em outras linguagens, como C++ Java, os C# modelos oferecem suporte *a parâmetros não tipo*, também chamados de parâmetros de valor. Por exemplo, você pode fornecer um valor integral constante para especificar o comprimento de uma matriz, como com este exemplo semelhante à classe [std:: array](../standard-library/array-class-stl.md) na biblioteca padrão:

```cpp
template<typename T, size_t L>
class MyArray
{
    T arr[L];
public:
    MyArray() { ... }
};
```

Observe a sintaxe na declaração de modelo. O valor de `size_t` é passado como um argumento de modelo no momento da compilação e deve ser **const** ou uma expressão **constexpr** . Você o usa da seguinte maneira:

```cpp
MyArray<MyClass*, 10> arr;
```

Outros tipos de valores, incluindo ponteiros e referências, podem ser passados como parâmetros sem tipo. Por exemplo, você pode passar um ponteiro para um objeto Function ou Function para personalizar alguma operação dentro do código do modelo.

### <a name="type-deduction-for-non-type-template-parameters"></a>Dedução de tipo para parâmetros de modelo sem tipo

No Visual Studio 2017 e posterior, em **/std: modo c++ 17** o compilador deduz o tipo de um argumento de modelo não tipo declarado com **auto**:

```cpp
template <auto x> constexpr auto constant = x;

auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
```

## <a name="templates-as-template-parameters"></a><a id="template_parameters"></a>Modelos como parâmetros de modelo

Um modelo pode ser um parâmetro de modelo. Neste exemplo, MyClass2 tem dois parâmetros de template: um typeName de parâmetro *T* e um parâmetro de template *arr*:

```cpp
template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
    U u; //Error. U not in scope
};
```

Como o próprio parâmetro *arr* não tem corpo, seus nomes de parâmetro não são necessários. Na verdade, é um erro fazer referência aos nomes de parâmetro de classe ou TypeName de *arr*de dentro do corpo de `MyClass2`. Por esse motivo, os nomes de parâmetro de tipo de *arr*podem ser omitidos, conforme mostrado neste exemplo:

```cpp
template<typename T, template<typename, int> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
};
```

## <a name="default-template-arguments"></a>Argumentos de modelo padrão

Os modelos de classe e função podem ter argumentos padrão. Quando um modelo tem um argumento padrão, você pode deixá-lo não especificado ao usá-lo. Por exemplo, o modelo std:: vector tem um argumento padrão para o alocador:

```cpp
template <class T, class Allocator = allocator<T>> class vector;
```

Na maioria dos casos, a classe std:: alocador padrão é aceitável e, portanto, você usa um vetor como este:

```cpp
vector<int> myInts;
```

Mas, se necessário, você pode especificar um alocador personalizado como este:

```cpp
vector<int, MyAllocator> ints;
```

Para mais argumentos de modelo, todos os argumentos após o primeiro argumento padrão devem ter argumentos padrão.

Ao usar um modelo cujos parâmetros estão todos padronizados, use colchetes de ângulo vazios:

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

Em alguns casos, não é possível ou desejável que um modelo defina exatamente o mesmo código para qualquer tipo. Por exemplo, você pode desejar definir um caminho de código a ser executado somente se o argumento de tipo for um ponteiro ou um std:: wstring ou um tipo derivado de uma classe base específica.  Nesses casos, você pode definir uma *especialização* do modelo para esse tipo específico. Quando um usuário instancia o modelo com esse tipo, o compilador usa a especialização para gerar a classe e, para todos os outros tipos, o compilador escolhe o modelo mais geral. As especializações nas quais todos os parâmetros são especializados são *especializações completas*. Se apenas alguns dos parâmetros são especializados, ele é chamado de *especialização parcial*.

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

Um modelo pode ter qualquer número de especializações, desde que cada parâmetro de tipo especializado seja exclusivo. Somente modelos de classe podem ser parcialmente especializados. Todas as especializações completas e parciais de um modelo devem ser declaradas no mesmo namespace que o modelo original.

Para obter mais informações, consulte [especialização de modelo](../cpp/template-specialization-cpp.md).
