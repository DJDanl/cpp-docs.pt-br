---
title: Bem-vindo de volta ao C++ - C++ moderno
description: Descreve as novas expressões de programação em C++ modernos e sua lógica.
ms.date: 01/10/2020
ms.topic: conceptual
ms.assetid: 1cb1b849-ed9c-4721-a972-fd8f3dab42e2
ms.openlocfilehash: 7d0fcb623162713b845107bbf00669af7ae5ca98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369500"
---
# <a name="welcome-back-to-c---modern-c"></a>Bem-vindo de volta ao C++ - C++ moderno

Desde sua criação, o C++ tornou-se uma das linguagens de programação mais utilizadas no mundo. os programas bem escritos que a utilizam são rápidos e eficientes. A língua é mais flexível do que outras línguas: pode funcionar nos níveis mais altos de abstração, e abaixo no nível do silício. O C++ fornece bibliotecas padrão altamente otimizadas. Ele permite o acesso a recursos de hardware de baixo nível, para maximizar a velocidade e minimizar os requisitos de memória. Usando C++, você pode criar uma ampla gama de aplicativos. Jogos, drivers de dispositivos e software científico de alto desempenho. Programas incorporados. Aplicativos cliente do Windows. Até bibliotecas e compiladores para outras linguagens de programação são escritos em C++.

Um dos requisitos originais da C++ é a compatibilidade com as versões anteriores da linguagem C. Como resultado, c++ sempre permitiu programação no estilo C, com ponteiros brutos, matrizes, seqüências de caracteres com término nulo e outros recursos. Eles podem permitir um ótimo desempenho, mas também podem gerar bugs e complexidade. A evolução do C++ enfatizou características que reduzem muito a necessidade de usar expressões no estilo C. As antigas instalações de programação C estão lá quando você precisa delas, mas com o código C++ moderno você deve precisar deles cada vez menos. O código C++ moderno é mais simples, seguro, mais elegante e ainda tão rápido como sempre.

As seções a seguir fornecem uma visão geral das principais características do C++moderno. Salvo observação em contrário, os recursos listados aqui estão disponíveis em C++11 e posteriores. No compilador Microsoft C++, você pode definir a opção [/std](../build/reference/std-specify-language-standard-version.md) compilador para especificar qual versão do padrão usar para o seu projeto.

## <a name="resources-and-smart-pointers"></a>Recursos e ponteiros inteligentes

Uma das principais classes de bugs na programação estilo C é o vazamento de *memória*. Vazamentos são muitas vezes causados por uma falha na chamada **exclusão** de memória que foi alocada com **novo**. O C++ moderno enfatiza que o princípio da aquisição de *recursos é a inicialização* (RAII). A ideia é simples. Os recursos (memória heap, alças de arquivo, soquetes e assim por diante) devem ser *de propriedade de* um objeto. Esse objeto cria, ou recebe, o recurso recém-alocado em seu construtor, e o exclui em seu destruidor. O princípio da RAII garante que todos os recursos sejam devidamente devolvidos ao sistema operacional quando o objeto possuidores sair do escopo.

Para apoiar a fácil adoção dos princípios RAII, a Biblioteca Padrão C++ fornece três tipos de ponteiros inteligentes: [std:unique_ptr](../standard-library/unique-ptr-class.md), [std:shared_ptr](../standard-library/shared-ptr-class.md)e [std::weak_ptr](../standard-library/weak-ptr-class.md). Um ponteiro inteligente lida com a alocação e exclusão da memória que possui. O exemplo a seguir mostra uma classe com um membro de `make_unique()`matriz que é alocado no heap na chamada para . As chamadas para **novo** e **exclusão** são encapsuladas pela `unique_ptr` classe. Quando `widget` um objeto sai do escopo, o unique_ptr destructor será invocado e liberará a memória que foi alocada para a matriz.  

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

Sempre que possível, use um ponteiro inteligente ao alocar memória heap. Se você deve usar os novos e excluir operadores explicitamente, siga o princípio do RAII. Para obter mais informações, consulte [Object lifetime and resource management (RAII)](object-lifetime-and-resource-management-modern-cpp.md).

## <a name="stdstring-and-stdstring_view"></a>std::string e std::string_view

As cordas no estilo C são outra grande fonte de bugs. Usando [std::string e std::wstring](../standard-library/basic-string-class.md), você pode eliminar praticamente todos os erros associados às strings estilo C. Você também ganha o benefício das funções de membro para pesquisa, anexação, pré-pendente, e assim por diante. Ambos são altamente otimizados para a velocidade. Ao passar uma seqüência para uma função que requer apenas acesso somente à leitura, em C++17 você pode usar [std::string_view](../standard-library/basic-string-view-class.md) para um benefício de desempenho ainda maior.

## <a name="stdvector-and-other-standard-library-containers"></a>dst::vetor e outros contêineres da Biblioteca Padrão

Os contêineres da Biblioteca Padrão seguem o princípio do RAII. Eles fornecem dispositivos para uma travessia segura de elementos. E, eles são altamente otimizados para o desempenho e foram completamente testados para a correção. Ao usar esses recipientes, você elimina o potencial de bugs ou ineficiências que podem ser introduzidos em estruturas de dados personalizadas. Em vez de matrizes cruas, use [o vetor](../standard-library/vector-class.md) como um recipiente seqüencial em C++.

```cpp
vector<string> apples;
apples.push_back("Granny Smith");
```

Use [o](../standard-library/map-class.md) `unordered_map`mapa (não) como o recipiente associativo padrão. Use [conjunto,](../standard-library/set-class.md) [multimapa](../standard-library/multimap-class.md)e [multiconjunto](../standard-library/multiset-class.md) para casos degenerados e multi-casos.

```cpp
map<string, string> apple_color;
// ...
apple_color["Granny Smith"] = "Green";
```

Quando a otimização de desempenho for necessária, considere usar:

- O tipo [de matriz](../standard-library/array-class-stl.md) ao incorporar é importante, por exemplo, como membro de classe.

- Recipientes associativos não ordenados, como [unordered_map.](../standard-library/unordered-map-class.md) Estes têm menor sobrecarga por elemento e busca de tempo constante, mas podem ser mais difíceis de usar de forma correta e eficiente.

- Ordenado. `vector` Para obter mais informações, consulte [Algoritmos](../cpp/algorithms-modern-cpp.md).

Não use matrizes estilo C. Para APIs mais antigas que precisam de acesso direto `f(vec.data(), vec.size());` aos dados, use métodos acessórios como, em vez disso. Para obter mais informações sobre contêineres, consulte [C++ Standard Library Containers](../standard-library/stl-containers.md).

## <a name="standard-library-algorithms"></a>Algoritmos padrão da Biblioteca

Antes de assumir que você precisa escrever um algoritmo personalizado para o seu programa, primeiro revise os [algoritmos](../standard-library/algorithm.md)da Biblioteca Padrão C++. A Biblioteca Padrão contém uma variedade crescente de algoritmos para muitas operações comuns, como pesquisa, classificação, filtragem e randomização. A biblioteca de matemática é extensa. A partir de C++17, versões paralelas de muitos algoritmos são fornecidas.

Aqui estão alguns exemplos importantes:

- **for_each**, o algoritmo transversal padrão (juntamente com o range-based para loops).

- **transformar**, para modificação não-no-lugar de elementos de contêiner

- **find_if**, o algoritmo de pesquisa padrão.

- **classificar**, **lower_bound**, e os outros algoritmos padrão de classificação e busca.

Para escrever um comparador, **<** use rigoroso e use *lambdas chamados* quando puder.

```cpp
auto comp = [](const widget& w1, const widget& w2)
     { return w1.weight() < w2.weight(); }

sort( v.begin(), v.end(), comp );

auto i = lower_bound( v.begin(), v.end(), comp );
```

## <a name="auto-instead-of-explicit-type-names"></a>auto em vez de nomes de tipo explícito

C++11 introduziu a palavra-chave [automática](auto-cpp.md) para uso em declarações variáveis, de função e de modelo. **auto** diz ao compilador para deduzir o tipo do objeto para que você não tenha que digitá-lo explicitamente. **auto** é especialmente útil quando o tipo deduzido é um modelo aninhado:

```cpp
map<int,list<string>>::iterator i = m.begin(); // C-style
auto i = m.begin(); // modern C++
```

## <a name="range-based-for-loops"></a>Range-based para loops

A iteração no estilo C sobre matrizes e contêineres é propensa a erros de indexação e também é tediosa para digitar. Para eliminar esses erros e tornar seu código mais legível, use loops baseados em intervalos com recipientes da Biblioteca Padrão e arrays brutos. Para obter mais informações, consulte [Faixa baseada em declaração](../cpp/range-based-for-statement-cpp.md).

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

## <a name="constexpr-expressions-instead-of-macros"></a>expressões constexpr em vez de macros

Macros em C e C++ são tokens que são processados pelo pré-processador antes da compilação. Cada instância de um token de macro é substituída por seu valor ou expressão definido satisfaz antes que o arquivo seja compilado. As macros são comumente usadas na programação no estilo C para definir valores constantes de tempo de compilação. No entanto, as macros são propensas a erros e difíceis de depurar. No C++moderno, você deve preferir variáveis [constexpr](constexpr-cpp.md) para compilar constantes de tempo:

```cpp
#define SIZE 10 // C-style
constexpr int size = 10; // modern C++
```

### <a name="uniform-initialization"></a>Inicialização uniforme

No C++, você pode usar a inicialização da cinta para qualquer tipo. Esta forma de inicialização é especialmente conveniente ao inicializar matrizes, vetores ou outros recipientes. No exemplo a `v2` seguir, é inicializado com três instâncias de `S`. `v3`é inicializado com `S` três instâncias das que são iniciadas usando aparelhos. O compilador infere o tipo de cada elemento `v3`com base no tipo declarado de .

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

Para obter mais informações, consulte [a inicialização do Brace](initializing-classes-and-structs-without-constructors-cpp.md).

## <a name="move-semantics"></a>Mova semântica

O C++ moderno fornece *semântica de movimento,* o que torna possível eliminar cópias de memória desnecessárias. Em versões anteriores do idioma, as cópias eram inevitáveis em certas situações. Uma operação *de movimentação* transfere a propriedade de um recurso de um objeto para o outro sem fazer uma cópia. Ao implementar uma classe que possui um recurso (como memória de pilha, alças de arquivo e assim por diante), você pode definir um *construtor de movimentos* e *mover o operador de atribuição* para ele. O compilador escolherá esses membros especiais durante a resolução de sobrecarga em situações em que uma cópia não é necessária. Os tipos de contêiner da Biblioteca Padrão invocam o construtor de movimento em objetos se um for definido. Para obter mais informações, consulte [Mover Construtores e Mover Operadores de Atribuição (C++)](move-constructors-and-move-assignment-operators-cpp.md).

## <a name="lambda-expressions"></a>Expressões lambda

Na programação estilo C, uma função pode ser passada para outra função usando um *ponteiro de função*. Ponteiros de função são inconvenientes para manter e entender. A função a que eles se referem pode ser definida em outro lugar no código fonte, longe do ponto em que é invocada. Além disso, eles não são do tipo seguros. O C++ moderno fornece *objetos de função,* classes que sobrepõem o [()](function-call-operator-parens.md) operador, o que permite que eles sejam chamados como uma função. A maneira mais conveniente de criar objetos de função é com [expressões lambda inline](../cpp/lambda-expressions-in-cpp.md). O exemplo a seguir mostra como usar uma expressão lambda para passar um objeto de função, que a `for_each` função invocará em cada elemento no vetor:

```cpp
    std::vector<int> v {1,2,3,4,5};
    int x = 2;
    int y = 4;
    auto result = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });
```

`[=](int i) { return i > x && i < y; }` A expressão lambda pode ser lida como "função `int` que pega um único argumento do `x` tipo e `y`retorna um booleano que indica se o argumento é maior do que e menor do que ." Observe que as `x` `y` variáveis e do contexto circundante podem ser usados na lambda. O `[=]` especifica que essas variáveis são *capturadas* por valor; em outras palavras, a expressão lambda tem suas próprias cópias desses valores.

## <a name="exceptions"></a>Exceções

O C++ moderno enfatiza exceções em vez de códigos de erro como a melhor maneira de relatar e lidar com condições de erro. Para obter mais informações, consulte [as práticas recomendadas modernas C++ para exceções e manipulação de erros.](errors-and-exception-handling-modern-cpp.md)

## <a name="stdatomic"></a>dst::atomic

Use a Biblioteca Padrão C++ [std::estrutura atômica](../standard-library/atomic-structure.md) e tipos relacionados para mecanismos de comunicação entre segmentos.

## <a name="stdvariant-c17"></a>dst::variante (C++17)

Sindicatos são comumente usados na programação estilo C para conservar a memória, permitindo que membros de diferentes tipos ocupem o mesmo local de memória. No entanto, os sindicatos não são seguros para tipos e são propensos a erros de programação. C++17 introduz a classe [std::variante](../standard-library/variant-class.md) como uma alternativa mais robusta e segura aos sindicatos. A função [std::visit](../standard-library/variant-functions.md#visit) pode ser usada `variant` para acessar os membros de um tipo de forma segura.

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](../cpp/cpp-language-reference.md)\
[Expressões Lambda](../cpp/lambda-expressions-in-cpp.md)\
[Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md)\
[Tabela de conformidade de idioma Microsoft C++](../overview/visual-cpp-language-conformance.md)
