---
title: Modelos (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- template_cpp
dev_langs:
- C++
helpviewer_keywords:
- templates, C++
- templates [C++]
ms.assetid: 90fcc14a-2092-47af-9d2e-dba26d25b872
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 715927893ec07d08ca2f2bd6eefc5f10795d5574
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46083633"
---
# <a name="templates-c"></a>Modelos (C++)

Os modelos são a base para a programação genérica em C++. Como uma linguagem fortemente tipada, C++ exige que todas as variáveis para ter um tipo específico, explicitamente declarado pelo programador ou deduzido pelo compilador. No entanto, muitos algoritmos e estruturas de dados têm a mesma aparência independentemente do tipo que estejam operando em. Os modelos habilitam a definir as operações de uma classe ou função e permitir que o usuário especifique quais concreto tipos essas operações deve trabalhar em.

## <a name="defining-and-using-templates"></a>Definindo e usando modelos

Um modelo é uma construção que gera um tipo comum ou uma função em tempo de compilação com base nos argumentos que o usuário fornece para os parâmetros de modelo. Por exemplo, você pode definir um modelo de função como esta:

```cpp
template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

O código acima descreve um modelo para uma função genérica com um único parâmetro de tipo *T*, cujo valor de retorno e parâmetros (lhs e rhs) da chamada são todos esses tipos. Você pode nomear um parâmetro de tipo que é semelhante, mas, por convenção único letras maiusculas do alfabeto é mais comumente usados. *T* é um parâmetro de modelo; a **typename** palavra-chave diz que esse parâmetro é um espaço reservado para um tipo. Quando a função é chamada, o compilador substituirá todas as instâncias de `T` com o argumento de tipo concreto que é especificado pelo usuário ou deduzido pelo compilador. O processo no qual o compilador gera uma classe ou função de um modelo é conhecida como *instanciação do modelo*; `minimum<int>` é uma instanciação do modelo `minimum<T>`.

Em outro lugar, um usuário pode declarar uma instância do modelo que é especializada em int. Suponha que get_a() e get_b() são funções que retornam um int:

```cpp
int a = get_a();
int b = get_b();
int i = minimum<int>(a, b);
```

No entanto, como esse é um modelo de função e o compilador podem deduzir o tipo de `T` argumentech *um* e *b*, você pode chamá-lo como uma função comum:

```cpp
int i = minimum(a, b);
```

Quando o compilador encontra a última instrução, ele gera uma nova função na qual cada ocorrência de *T* no modelo é substituído pelo **int**:

```cpp
int minimum(const int& lhs, const int& rhs)
{
    return lhs < rhs ? lhs : rhs;
}
```

As regras para como o compilador executa a dedução de tipo em modelos de função são com base nas regras de funções comuns. Para obter mais informações, consulte [sobrecarregar resolução de modelo de chamadas de função](../cpp/overload-resolution-of-function-template-calls.md).

## <a id="type_parameters"></a> Parâmetros de tipo

No `minimum` modelo acima, observe que o parâmetro de tipo *T* não está qualificada de forma alguma até que ele seja usado nos parâmetros da chamada de função, em que a constante e qualificadores de referência são adicionados.

Não há nenhum limite prático para o número de parâmetros de tipo. Separe vários parâmetros por vírgulas:

```cpp
template <typename T, typename U, typename V> class Foo{};
```

A palavra-chave **classe** é equivalente a **typename** neste contexto. Você pode expressar o exemplo anterior, como:

```cpp
template <class T, class U, class V> class Foo{};
```

Você pode usar o operador de reticências (...) para definir um modelo que pega um número arbitrário de zero ou mais parâmetros de tipo:

```cpp
template<typename... Arguments> class vtclass;

vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;
```

Qualquer tipo interno ou definido pelo usuário pode ser usado como um argumento de tipo. Por exemplo, você pode usar std:: Vector na biblioteca padrão para armazenar inteiros, duplicatas, cadeias de caracteres, MyClass, MyClass const *, MyClass &. A principal restrição ao usar os modelos é que um argumento de tipo deve oferecer suporte a todas as operações que são aplicadas aos parâmetros de tipo. Por exemplo, se nós chamarmos mínimo usando MyClass, como neste exemplo:

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

Será gerado um erro do compilador porque MyClass não oferece uma sobrecarga para o < operador.

Não há nenhum requisito de inerente que os argumentos de tipo para qualquer modelo específico para todos os pertencerem à mesma hierarquia de objeto, embora seja possível definir um modelo que impõe uma restrição. Você pode combinar técnicas orientadas a objeto com modelos; Por exemplo, você pode armazenar um derivado * em um vetor\<Base\*>.    Observe que os argumentos devem ser ponteiros

```cpp
vector<MyClass*> vec;
   MyDerived d(3, L"back again", time(0));
   vec.push_back(&d);

   // or more realistically:
   vector<shared_ptr<MyClass>> vec2;
   vec2.push_back(make_shared<MyDerived>());
```

Os requisitos básicos que impõem de vetor e outros contêineres da biblioteca padrão nos elementos de `T` é que `T` ser atribuível a cópia e construível por cópia.

## <a name="non-type-parameters"></a>Parâmetros sem tipo

Ao contrário de tipos genéricos em outras linguagens como c# e Java, os modelos de C++ dão suporte a parâmetros sem tipo, também chamados de parâmetros de valor. Por exemplo, você pode fornecer um valor inteiro constante para especificar o comprimento de uma matriz, assim como acontece com este exemplo, que é semelhante à classe std:: array na biblioteca padrão:

```cpp
template<typename T, size_t L>
class MyArray
{
    T arr[L];
public:
    MyArray() { ... }
};
```

Observe a sintaxe na declaração de modelo. O valor de size_t é passado como um argumento de modelo em tempo de compilação e deve ser constante ou uma expressão constexpr. Você pode usá-lo assim:

```cpp
MyArray<MyClass*, 10> arr;
```

Outros tipos de valores, incluindo ponteiros e referências podem ser passados como parâmetros sem tipo. Por exemplo, você pode passar um ponteiro para uma função ou um objeto de função para personalizar algumas operação dentro do código de modelo.

## <a id="template_parameters"></a> Modelos como parâmetros de modelo

Um modelo pode ser um parâmetro de modelo. Neste exemplo, MyClass2 tem dois parâmetros de modelo: um parâmetro typename *T* e um parâmetro de modelo *Arr*:

```cpp
template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
    U u; //Error. U not in scope
};
```

Porque o *Arr* próprio parâmetro não tem nenhum corpo, seus nomes de parâmetro não são necessários. Na verdade, é um erro para fazer referência a *Arr*do typename ou classe de nomes de parâmetros de dentro do corpo de `MyClass2`. Por esse motivo, *Arr*do nomes de parâmetro de tipo podem ser omitidos, conforme mostrado neste exemplo:

```cpp
template<typename T, template<typename, int> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
};
```

## <a name="default-template-arguments"></a>Argumentos de modelo padrão

Modelos de classe e a função podem ter argumentos padrão. Quando um modelo tem um argumento padrão que você pode deixá-lo não for especificado quando você usá-lo. Por exemplo, o modelo de std:: Vector tem um argumento padrão para o alocador:

```cpp
template <class T, class Allocator = allocator<T>> class vector;
```

Na maioria dos casos a classe std:: allocator padrão é aceitável, para que você use um vetor como este:

```cpp
vector<int> myInts;
```

Mas se necessário você pode especificar um alocador personalizado da seguinte maneira:

```cpp
vector<int, MyAllocator> ints;
```

Para mais argumentos de modelo, todos os argumentos após o primeiro argumento padrão devem ter argumentos padrão.

Ao usar um modelo cujos parâmetros são padronizados, use colchetes angulares vazios:

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

Em alguns casos, não é possível ou desejável para um modelo definir exatamente o mesmo código para qualquer tipo. Por exemplo, você pode desejar definir um caminho de código a ser executado somente se o argumento de tipo for um ponteiro ou um std:: wstring, ou um tipo derivado de uma classe base específica.  Nesses casos, você pode definir um *especialização* do modelo para esse tipo específico. Quando um usuário cria uma instância do modelo com esse tipo, o compilador usa a especialização para gerar a classe e para todos os outros tipos, o compilador escolhe o modelo mais geral. Especializações em que são especializados em todos os parâmetros são *concluir especializações*. Se apenas alguns dos parâmetros são especializadas, ele é chamado uma *especialização parcial*.

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

Um modelo pode ter qualquer número de especializações desde que cada parâmetro de tipo especializado é exclusivo. Somente modelos de classe podem ser parcialmente especializados. Todas as especializações parciais e completas de um modelo devem ser declaradas no mesmo namespace que o modelo original.

Para obter mais informações, consulte [especialização de modelo](../cpp/template-specialization-cpp.md).