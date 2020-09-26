---
title: Bem-vindo de volta ao C++ – C++ moderno
description: Descreve as novas linguagens de programação no C++ moderno e suas lógicas.
ms.date: 05/17/2020
ms.topic: conceptual
ms.assetid: 1cb1b849-ed9c-4721-a972-fd8f3dab42e2
ms.openlocfilehash: 05c1fe80086e5b98d3f8a9c66c6759fddab39fa0
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91353045"
---
# <a name="welcome-back-to-c---modern-c"></a>Bem-vindo de volta ao C++ – C++ moderno

Desde sua criação, o C++ tornou-se uma das linguagens de programação mais amplamente usadas do mundo. os programas bem escritos que a utilizam são rápidos e eficientes. A linguagem é mais flexível do que outras linguagens: ela pode funcionar nos níveis mais altos de abstração e no nível do silício. O C++ fornece bibliotecas padrão altamente otimizadas. Ele permite o acesso a recursos de hardware de baixo nível, para maximizar a velocidade e minimizar os requisitos de memória. Usando o C++, você pode criar uma ampla variedade de aplicativos. Jogos, drivers de dispositivo e software científico de alto desempenho. Programas inseridos. Aplicativos cliente do Windows. Até mesmo bibliotecas e compiladores para outras linguagens de programação são escritos em C++.

Um dos requisitos originais da C++ é a compatibilidade com as versões anteriores da linguagem C. Como resultado, o C++ sempre permitiu a programação C-Style, com ponteiros brutos, matrizes, cadeias de caracteres com terminação nula e outros recursos. Eles podem permitir um ótimo desempenho, mas também podem gerar bugs e complexidade. A evolução do C++ tem recursos enfatizados que reduzem muito a necessidade de usar os idiomas do estilo C. Os antigos recursos de programação de C estão lá quando você precisa deles, mas com código C++ moderno você deve precisar deles menos e menos. O código C++ moderno é mais simples, seguro, mais elegante e ainda tão rápido quanto nunca.

As seções a seguir fornecem uma visão geral dos principais recursos do C++ moderno. A menos que indicado de outra forma, os recursos listados aqui estão disponíveis no C++ 11 e posterior. No compilador do Microsoft C++, você pode definir a [`/std`](../build/reference/std-specify-language-standard-version.md) opção do compilador para especificar qual versão do padrão usar para seu projeto.

## <a name="resources-and-smart-pointers"></a>Recursos e ponteiros inteligentes

Uma das principais classes de bugs na programação em estilo C é o *vazamento de memória*. Os vazamentos são frequentemente causados por uma falha ao chamar a **`delete`** memória que foi alocada com o **`new`** . O C++ moderno enfatiza o princípio de que a *aquisição de recursos é a inicialização* (RAII). A ideia é simples. Os recursos (memória de heap, identificadores de arquivo, soquetes e assim por diante) devem *pertencer* a um objeto. Esse objeto cria, ou recebe, o recurso recém alocado em seu construtor e o exclui em seu destruidor. O princípio do RAII garante que todos os recursos sejam retornados corretamente para o sistema operacional quando o objeto proprietário sai do escopo.

Para dar suporte à adoção fácil de princípios RAII, a biblioteca padrão C++ fornece três tipos de ponteiro inteligente: [`std::unique_ptr`](../standard-library/unique-ptr-class.md) , [`std::shared_ptr`](../standard-library/shared-ptr-class.md) e [`std::weak_ptr`](../standard-library/weak-ptr-class.md) . Um ponteiro inteligente manipula a alocação e a exclusão da memória que ela possui. O exemplo a seguir mostra uma classe com um membro de matriz que é alocado no heap na chamada para `make_unique()` . As chamadas para **`new`** e **`delete`** são encapsuladas pela `unique_ptr` classe. Quando um `widget` objeto sai do escopo, o destruidor unique_ptr será invocado e liberará a memória que foi alocada para a matriz.  

```cpp
#include <memory>
class widget
{
private:
    std::unique_ptr<int> data;
public:
    widget(const int size) { data = std::make_unique<int>(size); }
    void do_something() {}
};

void functionUsingWidget() {
    widget w(1000000);   // lifetime automatically tied to enclosing scope
                // constructs w, including the w.data gadget member
    // ...
    w.do_something();
    // ...
} // automatic destruction and deallocation for w and w.data

```

Sempre que possível, use um ponteiro inteligente ao alocar memória heap. Se você precisar usar os operadores novo e excluir explicitamente, siga o princípio de RAII. Para obter mais informações, consulte [tempo de vida do objeto e gerenciamento de recursos (RAII)](object-lifetime-and-resource-management-modern-cpp.md).

## <a name="stdstring-and-stdstring_view"></a>`std::string` e `std::string_view`

As cadeias de caracteres C-style são outra grande fonte de bugs. Usando o [ `std::string` e `std::wstring` ](../standard-library/basic-string-class.md)o, você pode eliminar praticamente todos os erros associados a cadeias de caracteres de estilo C. Você também tem o benefício das funções de membro para pesquisar, acrescentar, aguardar e assim por diante. Ambos são altamente otimizados para velocidade. Ao passar uma cadeia de caracteres para uma função que requer somente acesso somente leitura, no C++ 17, você pode usar [`std::string_view`](../standard-library/basic-string-view-class.md) para obter um benefício de desempenho ainda maior.

## <a name="stdvector-and-other-standard-library-containers"></a>`std::vector` e outros contêineres de biblioteca padrão

Todos os contêineres de biblioteca padrão seguem o princípio de RAII. Eles fornecem iteradores para a passagem segura de elementos. E eles são altamente otimizados para desempenho e foram totalmente testados quanto à exatidão. Ao usar esses contêineres, você elimina o potencial de bugs ou ineficiências que podem ser introduzidos em estruturas de dados personalizadas. Em vez de matrizes brutas, use [`vector`](../standard-library/vector-class.md) como um contêiner sequencial em C++.

```cpp
vector<string> apples;
apples.push_back("Granny Smith");
```

Use [`map`](../standard-library/map-class.md) (não `unordered_map` ) como o contêiner associativo padrão. Use [`set`](../standard-library/set-class.md) , [`multimap`](../standard-library/multimap-class.md) e [`multiset`](../standard-library/multiset-class.md) para degenerações e vários casos.

```cpp
map<string, string> apple_color;
// ...
apple_color["Granny Smith"] = "Green";
```

Quando a otimização de desempenho for necessária, considere o uso de:

- O [`array`](../standard-library/array-class-stl.md) tipo ao inserir é importante, por exemplo, como um membro de classe.

- Contêineres associativos não ordenados, como [`unordered_map`](../standard-library/unordered-map-class.md) . Elas têm uma sobrecarga por elemento menor e uma pesquisa em tempo constante, mas podem ser mais difíceis de usar de forma correta e eficiente.

- Classificado `vector` . Para obter mais informações, consulte [Algoritmos](../standard-library/algorithms.md).

Não use matrizes de estilo C. Para APIs mais antigas que precisam de acesso direto aos dados, use métodos de acessador, como `f(vec.data(), vec.size());` em vez disso. Para obter mais informações sobre contêineres, consulte [contêineres de biblioteca padrão C++](../standard-library/stl-containers.md).

## <a name="standard-library-algorithms"></a>Algoritmos de biblioteca padrão

Antes de supor que você precisa escrever um algoritmo personalizado para seu programa, primeiro examine os [algoritmos](../standard-library/algorithm.md)de biblioteca padrão do C++. A biblioteca padrão contém uma variedade cada vez maior de algoritmos para muitas operações comuns, como pesquisa, classificação, filtragem e randomização. A biblioteca de matemática é extensa. A partir do C++ 17, são fornecidas versões paralelas de muitos algoritmos.

Aqui estão alguns exemplos importantes:

- `for_each`, o algoritmo de passagem padrão (juntamente com loops baseados em intervalos `for` ).

- `transform`, para modificação não in-loco de elementos de contêiner

- `find_if`, o algoritmo de pesquisa padrão.

- `sort`, `lower_bound` e os outros algoritmos de classificação e pesquisa padrão.

Para escrever um comparador, use estrito **`<`** e use *lambdas nomeados* quando possível.

```cpp
auto comp = [](const widget& w1, const widget& w2)
     { return w1.weight() < w2.weight(); }

sort( v.begin(), v.end(), comp );

auto i = lower_bound( v.begin(), v.end(), comp );
```

## <a name="auto-instead-of-explicit-type-names"></a>`auto` em vez de nomes de tipo explícitos

O c++ 11 introduziu a [`auto`](auto-cpp.md) palavra-chave para uso em declarações de variáveis, funções e modelos. **`auto`** informa ao compilador para deduzir o tipo do objeto para que você não precise digitá-lo explicitamente. **`auto`** é especialmente útil quando o tipo deduzido é um modelo aninhado:

```cpp
map<int,list<string>>::iterator i = m.begin(); // C-style
auto i = m.begin(); // modern C++
```

## <a name="range-based-for-loops"></a>Loops baseados em intervalo `for`

A iteração em estilo C em matrizes e contêineres é propenso a indexação de erros e também é entediante de digitar. Para eliminar esses erros e tornar seu código mais legível, use loops baseados em intervalo **`for`** com contêineres de biblioteca padrão e matrizes brutas. Para obter mais informações, consulte [ `for` instrução baseada em intervalo](../cpp/range-based-for-statement-cpp.md).

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {1,2,3};

    // C-style
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
    }

    // Modern C++:
    for(auto& num : v)
    {
        std::cout << num;
    }
}
```

## <a name="constexpr-expressions-instead-of-macros"></a>`constexpr` expressões em vez de macros

As macros em C e C++ são tokens que são processados pelo pré-processador antes da compilação. Cada instância de um token de macro é substituída pelo seu valor ou expressão definido antes de o arquivo ser compilado. As macros são comumente usadas na programação em estilo C para definir valores constantes de tempo de compilação. No entanto, as macros são propensas a erros e são difíceis de depurar. No C++ moderno, você deve preferir [`constexpr`](constexpr-cpp.md) variáveis para constantes de tempo de compilação:

```cpp
#define SIZE 10 // C-style
constexpr int size = 10; // modern C++
```

### <a name="uniform-initialization"></a>Inicialização uniforme

No C++ moderno, você pode usar a inicialização de chaves para qualquer tipo. Essa forma de inicialização é especialmente conveniente ao inicializar matrizes, vetores ou outros contêineres. No exemplo a seguir, `v2` é inicializado com três instâncias do `S` . `v3` é inicializado com três instâncias do `S` que são inicializadas usando chaves. O compilador infere o tipo de cada elemento com base no tipo declarado de `v3` .

```cpp
#include <vector>

struct S
{
    std::string name;
    float num;
    S(std::string s, float f) : name(s), num(f) {}
};

int main()
{
    // C-style initialization
    std::vector<S> v;
    S s1("Norah", 2.7);
    S s2("Frank", 3.5);
    S s3("Jeri", 85.9);

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    // Modern C++:
    std::vector<S> v2 {s1, s2, s3};

    // or...
    std::vector<S> v3{ {"Norah", 2.7}, {"Frank", 3.5}, {"Jeri", 85.9} };

}
```

Para obter mais informações, consulte [inicialização de chaves](initializing-classes-and-structs-without-constructors-cpp.md).

## <a name="move-semantics"></a>Mover semântica

O C++ moderno fornece *semântica de movimentação*, o que possibilita eliminar cópias de memória desnecessárias. Em versões anteriores do idioma, as cópias eram inevitáveis em determinadas situações. Uma operação de *movimentação* transfere a propriedade de um recurso de um objeto para o seguinte sem fazer uma cópia. Algumas classes têm recursos como memória de heap, identificadores de arquivos e assim por diante. Ao implementar uma classe de propriedade de recurso, você pode definir um *Construtor de movimentação* e *mover o operador de atribuição* para ele. O compilador escolhe esses membros especiais durante a resolução de sobrecarga em situações em que uma cópia não é necessária. Os tipos de contêiner de biblioteca padrão invocarão o Construtor move em objetos, se houver um definido. Para obter mais informações, consulte [mover construtores e mover operadores de atribuição (C++)](move-constructors-and-move-assignment-operators-cpp.md).

## <a name="lambda-expressions"></a>Expressões lambda

Na programação em estilo C, uma função pode ser passada para outra função usando um *ponteiro de função*. Ponteiros de função são inconvenientes de manter e entender. A função à qual eles se referem pode ser definida em outro lugar no código-fonte, longe do ponto em que ele é invocado. Além disso, eles não são de tipo seguro. O C++ moderno fornece *objetos de função*, classes que substituem o [`operator()`](function-call-operator-parens.md) operador, o que permite que eles sejam chamados como uma função. A maneira mais conveniente de criar objetos de função é com [expressões lambda](../cpp/lambda-expressions-in-cpp.md)embutidas. O exemplo a seguir mostra como usar uma expressão lambda para passar um objeto de função, que a `for_each` função invocará em cada elemento no vetor:

```cpp
    std::vector<int> v {1,2,3,4,5};
    int x = 2;
    int y = 4;
    auto result = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });
```

A expressão lambda `[=](int i) { return i > x && i < y; }` pode ser lida como "função que usa um único argumento do tipo **`int`** e retorna um booliano que indica se o argumento é maior que `x` e menor que `y` ". Observe que as variáveis `x` e `y` do contexto ao redor podem ser usadas no lambda. O `[=]` especifica que essas variáveis são *capturadas* por valor; em outras palavras, a expressão lambda tem suas próprias cópias desses valores.

## <a name="exceptions"></a>Exceções

O C++ moderno enfatiza exceções em vez de códigos de erro como a melhor maneira de relatar e tratar condições de erro. Para obter mais informações, consulte [práticas recomendadas do C++ moderno para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md).

## `std::atomic`

Use o struct da biblioteca padrão C++ [`std::atomic`](../standard-library/atomic-structure.md) e os tipos relacionados para mecanismos de comunicação entre threads.

## <a name="stdvariant-c17"></a>`std::variant` (C++ 17)

As uniões são comumente usadas na programação em estilo C para conservar a memória, permitindo que os membros de diferentes tipos ocupem o mesmo local de memória. No entanto, as uniões não são de tipo seguro e estão sujeitas a erros de programação. O c++ 17 apresenta a [`std::variant`](../standard-library/variant-class.md) classe como uma alternativa mais robusta e segura para as uniões. A [`std::visit`](../standard-library/variant-functions.md#visit) função pode ser usada para acessar os membros de um `variant` tipo de maneira segura de tipo.

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)\
[Expressões lambda](../cpp/lambda-expressions-in-cpp.md)\
[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)\
[Tabela de conformidade da linguagem Microsoft C++](../overview/visual-cpp-language-conformance.md)
