---
title: Melhorias de conformidade do C++ | Microsoft Docs
ms.custom: ''
ms.date: 03/11/2018
ms.technology:
- cpp-language
ms.topic: conceptual
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ed2165f75103f5e2aecd3d73dfe9518341d926e
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37042323"
---
# <a name="c-conformance-improvements-in-visual-studio-2017-versions-150-153improvements153-155improvements155-156improvements156-157improvements157"></a>Melhorias de conformidade do C++ no Visual Studio 2017 versões 15.0, [15.3](#improvements_153), [15.5](#improvements_155), [15.6](#improvements_156) e [15.7](#improvements_157)

Com suporte para constexpr generalizado e NSDMI para agregações, agora o compilador do Microsoft Visual C++ está completo com relação aos recursos adicionados no padrão C++14. Observe que o compilador ainda não tem alguns recursos dos padrões C++11 e C++98. Confira [Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md) para ver uma tabela que mostra o estado atual do compilador.

## <a name="c11"></a>C++11

### <a name="expression-sfinae-support-in-more-libraries"></a>Suporte da expressão SFINAE em mais bibliotecas

O compilador do Visual C++ continua melhorando seu suporte da expressão SFINAE, necessário para dedução e substituição de argumentos de modelo em que as expressões decltype e constexpr podem ser exibidas como parâmetros de modelo. Para obter mais informações, consulte [Expression SFINAE improvements in Visual Studio 2017 RC (Melhorias da expressão SFINAE no Visual Studio 2017 RC)](https://blogs.msdn.microsoft.com/vcblog/2016/06/07/expression-sfinae-improvements-in-vs-2015-update-3).

## <a name="c-14"></a>C++ 14

### <a name="nsdmi-for-aggregates"></a>NSDMI para agregações

Uma agregação é uma matriz ou uma classe sem nenhum construtor fornecido pelo usuário, sem membros de dados não estáticos privados ou protegidos, sem classes base e sem funções virtuais. Começando pelo C ++14, as agregações podem conter inicializadores de membro. Para obter mais informações, consulte [Member initializers and aggregates (Inicializadores de membro e agregações)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3605.html).

### <a name="extended-constexpr"></a>Constexpr estendida

Agora as expressões declaradas como constexpr podem conter alguns tipos de declaração, instruções if e switch, declarações de loop e mutação de objetos cujo tempo de vida começou dentro da avaliação da expressão constexpr. Além disso, não há mais o requisito de que uma função membro não estática constexpr seja implicitamente const. Para obter mais informações, consulte [Relaxing constraints on constexpr functions (Relaxando restrições em funções constexpr)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html).

## <a name="c17"></a>C++17

### <a name="terse-staticassert"></a>Static_assert concisa

o parâmetro de mensagem para static_assert é opcional. Para obter mais informações, consulte [Extending static_assert, v2 (Estendendo static_assert, v2)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf).

### <a name="fallthrough-attribute"></a>Atributo [[fallthrough]]

No modo **/std:c++17**, o atributo [[fallthrough]] pode ser usado no contexto de instruções switch como uma dica para o compilador de que o comportamento de fall-through é intencional. Isso impede o compilador de emitir avisos em tais casos. Para obter mais informações, consulte [Wording for [[fallthrough]] attribute (Expressão para atributo [[fallthrough]])](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r0.pdf).

### <a name="generalized-range-based-for-loops"></a>Generalizados baseados em intervalo para loops

Baseada em intervalo para loops que não exigem mais que begin() e end() retornem objetos do mesmo tipo. Isso permite que end() retorne uma sentinela conforme usado por intervalos em [range-v3](https://github.com/ericniebler/range-v3) e Especificações técnicas de intervalos concluídos, mas não publicados. Para obter mais informações, consulte [Generalizando o loop “for” baseado em intervalo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html).

## <a name="improvements_153"></a> Melhorias no Visual Studio 2017 versão 15.3

### <a name="constexpr-lambdas"></a>Lambdas constexpr

Expressões Lambda agora podem ser usadas em expressões de constante. Para saber mais, veja [Constexpr lambda](http://open-std.org/JTC1/SC22/WG21/docs/papers/2015/n4487.pdf).

### <a name="if-constexpr-in-function-templates"></a>if constexpr em modelos de função

Um modelo de função pode conter instruções `if constexpr` para habilitar a ramificação de tempo de compilação. Para saber mais, veja [if constexpr](http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0128r1.html).

### <a name="selection-statements-with-initializers"></a>Instruções de seleção com inicializadores

Uma instrução `if` pode conter um inicializador que apresenta uma variável no escopo de bloco dentro da instrução em si. Para saber mais, veja [Instruções de seleção com inicializador](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0305r1.html).

### <a name="maybeunused-and-nodiscard-attributes"></a>Atributos [[maybe_unused]] e [[nodiscard]]

Novos atributos para silenciar avisos quando uma entidade não for usada ou criar um aviso se o valor retornado de uma chamada de função for descartado. Para saber mais, veja [Palavras para o atributo maybe_unused](http://open-std.org/JTC1/SC22/WG21/docs/papers/2016/p0212r0.pdf) e [Proposta de atributos unused, nodiscard e fallthrough](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0068r0.pdf).

### <a name="using-attribute-namespaces-without-repetition"></a>Uso de namespaces de atributo sem repetição

Nova sintaxe para permitir apenas um único identificador de namespace em uma lista de atributos. Para saber mais, veja [Atributos em C++](cpp/attributes.md).

### <a name="structured-bindings"></a>Associações estruturadas

Agora é possível em uma única declaração armazenar um valor com os nomes individuais de seus componentes, quando o valor é uma matriz, std::tuple ou std::pair ou tem todos os membros de dados não estáticos públicos. Para saber mais, veja [Associações estruturadas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0144r0.pdf).

### <a name="construction-rules-for-enum-class-values"></a>Regras de construção para valores de classe de enumeração

Agora há uma conversão implícita/não restrição do tipo subjacente de uma enumeração com escopo para a enumeração em si, quando sua definição não apresenta enumerador e a origem usa uma sintaxe de inicialização da lista. Para saber mais, veja [Regras de construção para valores de classe de enumeração](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2.pdf).

### <a name="capturing-this-by-value"></a>Captura de *this por valor

O objeto `*this` em uma expressão lambda agora pode ser capturado por valor. Isso permite cenários nos quais o lambda é invocado em operações paralelas e assíncronas, especialmente em arquiteturas de computadores mais recentes. Para saber mais, veja [Captura de Lambda de \*this por Valor como [=,\*this]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html).

### <a name="removing-operator-for-bool"></a>Remoção do operator++ de bool

`operator++` não é mais compatível em tipos `bool`. Para saber mais, veja [Remover operator++(bool) preterido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0002r1.html).

### <a name="removing-deprecated-register-keyword"></a>Remoção da palavra-chave "register" preterida

A palavra-chave `register`, anteriormente preterida (e ignorada pelo compilador), agora foi removida da linguagem. Para saber mais, veja [Remover uso preterido da palavra-chave register](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html).

Para obter uma lista das melhorias de conformidade até o Visual Studio 2015, Atualização 3, consulte [Visual C++ What's New 2003 through 2015 (Novidades do Visual C++ 2003 a 2015)](https://msdn.microsoft.com/en-us/library/mt723604.aspx).

## <a name="improvements_155"></a> Melhorias no Visual Studio 2017 versão 15.5

Recursos marcados com [14] estão disponíveis incondicionalmente, mesmo no modo **/std:c++14**.

### <a name="new-compiler-switch-for-extern-constexpr"></a>Nova opção de compilador do constexpr externo

Em versões anteriores do Visual Studio, o compilador sempre forneceu uma ligação interna variável `constexpr`, mesmo quando a variável era marcada como `extern`. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, [/Zc:externConstexpr](build/reference/zc-externconstexpr.md), habilita o comportamento correto em conformidade com os padrões. Para obter mais informações, consulte [vinculação de contexpr externo](#extern_linkage).

### <a name="removing-dynamic-exception-specifications"></a>Remoção de Especificações de Exceção Dinâmica

[P0003R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html) As especificações de exceções dinâmicas foram preteridas no C++11. o recurso será removido do C++17, mas a especificação `throw()` (ainda) preterida será mantida estritamente como um alias para `noexcept(true)`. Para obter mais informações, consulte [Remoção de especificação de exceção dinâmica e noexcept](#noexcept_removal).

### <a name="notfn"></a>not_fn()

[P0005R4](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0005r4.html) `not_fn` é uma substituição de `not1` e `not2`.

### <a name="rewording-enablesharedfromthis"></a>Reescrita de enable_shared_from_this

[P0033R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0033r1.html) `enable_shared_from_this` foi adicionada no C++ 11. O C++17 Standard atualiza a especificação para lidar melhor com certos casos de canto. [14]

### <a name="splicing-maps-and-sets"></a>União de mapas e conjuntos

[P0083R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf) Este recurso permite a extração de nós de contêineres associativos (por exemplo, map, set, unordered\_map, unordered\_set) que podem ser modificados e inseridos novamente no mesmo contêiner ou um contêiner diferente que usa o mesmo tipo de nó. (É um caso de uso comum extrair um nó de um `std::map`, alterar a chave e inseri-lo novamente.)

### <a name="deprecating-vestigial-library-parts"></a>Preterir partes residuais da biblioteca

[P0174R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0174r2.html) Vários recursos da Biblioteca padrão do C++ foram substituídos por novos recursos ao longo dos anos ou se mostraram pouco úteis ou problemáticos. Esses recursos foram oficialmente preteridos no C++17.

### <a name="removing-allocator-support-in-stdfunction"></a>Remoção do suporte ao alocador em std::function

[P0302R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0302r1.html) Antes do C++17, o modelo de classe `std::function` tinha vários construtores que usavam um argumento de alocador. No entanto, o uso de alocadores neste contexto era problemático e a semântica era confusa. Portanto, esses construtores foram removidos.

### <a name="fixes-for-notfn"></a>Correções para not_fn()

[P0358R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0358r1.html) As novas palavras para `std::not_fn` dão suporte à propagação de categoria de valor no caso de invocação do wrapper.

### <a name="sharedptrt-sharedptrtn"></a>shared_ptr\<T[]>, shared_ptr\<T[N]>

[P0414R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html) Mesclando alterações do `shared_ptr` dos Princípios básicos de biblioteca para o C++17. [14]

### <a name="fixing-sharedptr-for-arrays"></a>Correção de shared_ptr para matrizes

[P0497R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0497r0.html) Correções para o suporte de shared_ptr para matrizes. [14]

### <a name="clarifying-insertreturntype"></a>Esclarecimento de insert_return_type

[P0508R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0508r0.html) Os contêineres associativos e não ordenados, ambos com chaves exclusivas, têm uma função de membro `insert` que retorna um tipo aninhado `insert_return_type`. O tipo de retorno agora é definido como uma especialização de um tipo com parâmetros no iterador e NodeType do contêiner.

### <a name="inline-variables-for-the-stl"></a>Variáveis embutidas para a STL

[P0607R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0607r0.html)

### <a name="annex-d-features-deprecated"></a>Recursos preteridos do anexo D

O anexo D do C++ padrão contém todos os recursos que foram preteridos, incluindo `shared_ptr::unique()`, `<codecvt>` e `namespace std::tr1`. Quando a opção do compilador **/std:c++17** está definida, quase todos os recursos da Biblioteca Padrão do anexo D são marcados como preteridos. Para obter mais informações, consulte [Recursos da Biblioteca Padrão no Anexo D estão marcados como preteridos](#annex_d).

O namespace `std::tr2::sys` em `<experimental/filesystem>` agora emite um aviso de substituição em **/std:c++14** por padrão e agora será removido em **/std:c++17** por padrão.

Melhoria na conformidade em iostreams, evitando uma extensão não padrão (especializações explícitas na classe).

A Biblioteca Padrão agora usa modelos de variável internamente.

A Biblioteca Padrão foi atualizada em resposta às alterações do compilador do C++17, incluindo a adição de noexcept no sistema de tipos e a remoção de especificações de exceção dinâmica.

## <a name="improvements_156"></a> Melhorias no Visual Studio 2017 versão 15.6

### <a name="c17-library-fundamentals-v1"></a>Princípios básicos da biblioteca C++17 V1

O [P0220R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) incorpora a especificação técnica dos princípios básicos da biblioteca para o C++17 no padrão. Ele aborda as atualizações a \<experimental/tuple>, \<experimental/optional>, \<experimental/functional>, \<experimental/any>, \<experimental/string_view>, \<experimental/memory>, \<experimental/memory_resource> e \<experimental/algorithm>.

### <a name="c17-improving-class-template-argument-deduction-for-the-stl"></a>Melhorias do C++17 na dedução de argumento de modelo de classe para STL

O [P0739R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0739r0.html) move o `adopt_lock_t` para a frente da lista de parâmetros para `scoped_lock` a fim de habilitar o uso consistente de `scoped_lock`. Permite que o construtor `std::variant` participe na resolução de sobrecarga em mais casos, a fim de habilitar a atribuição de cópia.

## <a name="improvements_157"></a> Melhorias no Visual Studio 2017 versão 15.7

### <a name="c17-rewording-inheriting-constructors"></a>C++17 reescrevendo construtores de herança

O [P0136R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0136r1.html) especifica que uma declaração **using** que nomeia um construtor, agora torna os construtores de classe base correspondentes visíveis para inicializações da classe derivada em vez de declarar construtores de classe derivada adicionais. Essa é uma alteração do C++14. No Visual Studio 2017 versão 15.7 e posterior, no modo **/std:c++17**, o código que é válido no C++14 e usa os construtores de herança, pode não ser válido ou pode ter semântica diferente.

O exemplo a seguir mostra o comportamento do C++14:

```cpp
struct A {
    template<typename T>
    A(T, typename T::type = 0);
    A(int);
};

struct B : A {
    using A::A;
    B(int n) = delete; // Error C2280
};

B b(42L); // Calls B<long>(long), which calls A(int)
          //  due to substitution failure in A<long>(long).
```

A exemplo a seguir mostra o comportamento do modo **/std:c++17** no Visual Studio 15.7:

```cpp
struct A {
    template<typename T>
    A(T, typename T::type = 0);
    A(int);
};

struct B : A {
    using A::A;
    B(int n)
    {
        //do something
    }
};

B b(42L); // now calls B(int)
```

### <a name="c17-extended-aggregate-initialization"></a>C++17 Inicialização de agregação estendida

[P0017R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html)

quando o construtor de uma classe base não é não público, mas é acessível a uma classe derivada, então, no modo **/std:c++17**, no Visual Studio versão 15.7, não é mais possível usar chaves vazias para inicializar um objeto do tipo derivado.

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

No C++17, `Derived` agora é considerado um tipo de agregação; portanto, a inicialização de `Base` por meio do construtor padrão privado acontece diretamente como parte da regra de inicialização de agregação estendida. Anteriormente, o construtor privado `Base` era chamado por meio do construtor `Derived`, e isso era bem-sucedido devido à declaração friend.

O exemplo a seguir mostra o comportamento do C++17 no Visual Studio versão 15.7, no modo **/std:c++17**:

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

### <a name="c17-declaring-non-type-template-parameters-with-auto"></a>C++17 Declarando parâmetros de modelo de não tipo com auto

[P0127R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2.html)

No modo **/std:c++17**, o compilador agora pode deduzir o tipo de um argumento de modelo de não tipo que é declarado com **auto**:

```cpp
template <auto x> constexpr auto constant = x;

auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
```

Um impacto desse novo recurso é que um código válido do C++14 pode não ser válido ou pode ter semântica diferente. Por exemplo, algumas sobrecargas que eram anteriormente inválidas agora são válidas. O exemplo a seguir mostra um código do C++14 que é compilado porque a chamada a `foo(p)` está associada a `foo(void*);`. No Visual Studio 2017 versão 15.7, no modo **/std:c++17**, o modelo da função `foo` é a melhor correspondência.

```cpp
template <int N> struct A;
template <typename T, T N> int foo(A<N>*) = delete;

void foo(void *);

void bar(A<0> *p)
{
    foo(p); // OK in C++14
}
```

O exemplo a seguir mostra um código do C++17 no Visual Studio 15.7, no modo **/std:c++17**:

```cpp
template <int N> struct A;
template <typename T, T N> int foo(A<N>*);

void foo(void *);

void bar(A<0> *p)
{
    foo(p); // C2280: 'int foo<int,0>(A<0>*)': attempting to reference a deleted function
}
```

### <a name="c17-elementary-string-conversions-partial"></a>C++17 Conversões elementares de cadeia de caracteres (parcial)

[P0067R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html) funções de nível baixo, independentes de localidade para conversões entre cadeias de caracteres e inteiros e entre cadeias de caracteres e números de ponto flutuante. (A partir do Visual Studio 15.7 Preview 2, compatível somente com números inteiros).

### <a name="c20-avoiding-unnecessary-decay-partial"></a>C++20 Evitando decaimento desnecessário (parcial)

[P0777R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0777r1.pdf) Adiciona diferenciação entre o conceito de "decaimento" e o da simples remoção de const ou de qualificadores de referência.  A característica de novo tipo de `remove_reference_t` substitui `decay_t` em alguns contextos. O suporte para `remove_cvref_t` ainda não foi implementado no Visual Studio 2017 versão 15.7 Preview 2.

### <a name="c17-parallel-algorithms"></a>C++17 Algoritmos paralelos

[P0024R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html) A TS de paralelismo será incorporada no padrão, com pequenas modificações.

### <a name="c17-hypotx-y-z"></a>C++17 hypot(x, y, z)

[P0030R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0030r1.pdf) Adiciona três novas sobrecargas para `std::hypot`, para os tipos **float**, **double** e **long double**, cada um deles com três parâmetros de entrada.

### <a name="c17-filesystem"></a>C++17 \<filesystem>

[P0218R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0218r1.html) Adota a TS do sistema de arquivos no padrão, com algumas modificações de frase.

### <a name="c17-mathematical-special-functions"></a>C++17 Funções matemáticas especiais

[P0226R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) Adota especificações técnicas anteriores para as funções matemáticas especiais no cabeçalho \<cmath> padrão.

### <a name="c17-deduction-guides-for-the-stl"></a>C++17 Guias de dedução da STL

[P0433R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0433r2.html) Atualizações ao STL para aproveitar a adoção do [P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html) pelo C++17, que adiciona suporte à dedução de argumento de modelo de classe.

### <a name="c17-repairing-elementary-string-conversions"></a>C++17 Reparação de conversões de cadeia de caracteres elementares

[P0682R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0682r1.html) Mover as novas funções de conversão de cadeia de caracteres elementares do P0067R5 para um novo cabeçalho \<charconv> e fazer outras melhorias, incluindo mudanças no tratamento de erro para usar `std::errc` em vez de `std::error_code`.

### <a name="c17-constexpr-for-chartraits-partial"></a>C++17 constexpr para char_traits (parcial)

[P0426R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0426r1.html) Alterações em funções de membro `std::traits_type`, `length`, `compare` e `find`, para fazer com que `std::string_view` possa ser usado em expressões constantes. (No Visual Studio 2017 versão 15.6, compatível somente com Clang/LLVM. Na versão 15.7 Preview 2, há compatibilidade quase concluída com ClXX também).

## <a name="bug-fixes-in-visual-studio-versions-150-153update153-155update155-157update157-and-158update158"></a>Correções de bug nas versões do Visual Studio 15.0, [15.3](#update_153), [15.5](#update_155), [15.7](#update_157) e [15.8](#update_158)

### <a name="copy-list-initialization"></a>Inicialização de lista de cópia

O Visual Studio 2017 gera corretamente erros de compilador relacionados à criação de objetos usando listas de inicializador que não foram detectadas no Visual Studio 2015 e que podem causar falhas ou comportamento indefinido do tempo de execução. De acordo com a N4594 13.3.1.7p1, na inicialização de lista de cópia, o compilador deverá considerar um construtor explícito para resolução de sobrecarga, mas deverá gerar um erro se essa sobrecarga for realmente escolhida.

Os dois exemplos a seguir são compilados no Visual Studio 2015, mas não no Visual Studio 2017.

```cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    A a1 = { 1 }; // error C3445: copy-list-initialization of 'A' cannot use an explicit constructor
    const A& a2 = { 1 }; // error C2440: 'initializing': cannot convert from 'int' to 'const A &'

}
```

Para corrigir o erro, use a inicialização direta:

```cpp
A a1{ 1 };
const A& a2{ 1 };
```

No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga. No exemplo a seguir, o Visual Studio 2015 escolhe MyInt(23), mas o Visual Studio 2017 gera o erro corretamente.

```cpp
// From http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_closed.html#1228
struct MyStore {
    explicit MyStore(int initialCapacity);
};

struct MyInt {
    MyInt(int i);
};

struct Printer {
    void operator()(MyStore const& s);
    void operator()(MyInt const& i);
};

void f() {
    Printer p;
    p({ 23 }); // C3066: there are multiple ways that an object of this type can be called with these arguments
}
```

Esse exemplo é semelhante ao anterior, mas gera um erro diferente. Ele tem êxito no Visual Studio 2015 e falha no Visual Studio 2017 com C2668.

```cpp
struct A {
    explicit A(int) {}
};

struct B {
    B(int) {}
};

void f(const A&) {}
void f(const B&) {}

int main()
{
    f({ 1 }); // error C2668: 'f': ambiguous call to overloaded function
}
```

### <a name="deprecated-typedefs"></a>Typedefs preteridos

Agora o Visual Studio 2017 emite o aviso correto para typedefs preteridos declarados em uma classe ou em um struct. O exemplo a seguir é compilado sem avisos no Visual Studio 2015, mas gera C4996 no Visual Studio 2017.

```cpp
struct A
{
    // also for __declspec(deprecated)
    [[deprecated]] typedef int inttype;
};

int main()
{
    A::inttype a = 0; // C4996 'A::inttype': was declared deprecated
}
```

### <a name="constexpr"></a>constexpr

O Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional é inválido em um contexto constexpr. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017 (C3615 a função constexpr 'f' não pode resultar em uma expressão de constante):

```cpp
template<int N>
struct array
{
    int size() const { return N; }
};

constexpr bool f(const array<1> &arr)
{
    return arr.size() == 10 || arr.size() == 11; // C3615
}
```

Para corrigir o erro, declare a função `array::size()` como `constexpr` ou remova o qualificador `constexpr` de `f`.

### <a name="class-types-passed-to-variadic-functions"></a>Tipos de classe passados para funções variadic

No Visual Studio de 2017, as classes ou structs passados para uma função variadic como printf devem ser facilmente copiados. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

```cpp
#include <atomic>
#include <memory>
#include <stdio.h>

int main()
{
    std::atomic<int> i(0);
    printf("%i\n", i); // error C4839: non-standard use of class 'std::atomic<int>'
                        // as an argument to a variadic function.
                        // note: the constructor and destructor will not be called;
                        // a bitwise copy of the class will be passed as the argument
                        // error C2280: 'std::atomic<int>::atomic(const std::atomic<int> &)':
                        // attempting to reference a deleted function

    struct S {
        S(int i) : i(i) {}
        S(const S& other) : i(other.i) {}
        operator int() { return i; }
    private:
        int i;
    } s(0);
    printf("%i\n", s); // warning C4840 : non-portable use of class 'main::S'
                      // as an argument to a variadic function
}
```

Para corrigir o erro, é possível chamar uma função membro que retorna um tipo facilmente copiado,

```cpp
    std::atomic<int> i(0);
    printf("%i\n", i.load());
```

ou realiza uma conversão estática para converter o objeto antes de passá-lo:

```cpp
    struct S {/* as before */} s(0);
    printf("%i\n", static_cast<int>(s))
```

Para cadeias de caracteres criadas e gerenciadas usando o CString, o `operator LPCTSTR()` fornecido deve ser usado para converter um objeto CString no ponteiro do C esperado pela cadeia de caracteres de formato.

```cpp
CString str1;
CString str2 = _T("hello!");
str1.Format(_T("%s"), static_cast<LPCTSTR>(str2));
```

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe

No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, isso pode gerar uma falha ou comportamento inesperado do tempo de execução. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro de compilador no Visual Studio 2017:

```cpp
struct S
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```

Para corrigir o erro, declare `operator int()` como `const`.

### <a name="access-checking-on-qualified-names-in-templates"></a>Verificação de acesso em nomes qualificados em modelos

As versões anteriores do compilador não realizavam a verificação de acesso em nomes qualificados em alguns contextos de modelo. Isso pode interferir no comportamento SFINAE esperado quando a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no tempo de execução devido ao compilador ter chamado incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador. O erro específico pode variar, mas geralmente é "C2672 nenhuma função sobrecarregada correspondente encontrada". O código a seguir é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017:

```cpp
#include <type_traits>

template <class T> class S {
    typedef typename T type;
};

template <class T, std::enable_if<std::is_integral<typename S<T>::type>::value, T> * = 0>
bool f(T x);

int main()
{
    f(10); // C2672: No matching overloaded function found.
}
```

### <a name="missing-template-argument-lists"></a>Listas de argumentos de modelo ausentes

No Visual Studio 2015 e anteriores, o compilador não diagnosticava listas de argumentos de modelo ausentes quando o modelo era exibido em uma lista de parâmetro de modelo (por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de não tipo de modelo). Isso pode resultar em comportamento imprevisível, incluindo falhas do compilador ou comportamento inesperado do tempo de execução. O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```cpp
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```

### <a name="expression-sfinae"></a>Expressão SFINAE

Para dar suporte à expressão SFINAE, agora o compilador analisa argumentos decltype quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente é encontrada no argumento decltype, ela não é adiada para o momento de instanciação e é processada imediatamente. Qualquer erro resultante é diagnosticado nesse momento.

O exemplo a seguir mostra esse erro do compilador gerado no momento da declaração:

```cpp
#include <utility>
template <class T, class ReturnT, class... ArgsT>
class IsCallable
{
public:
    struct BadType {};

    template <class U>
    static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>

    template <class U>
    static BadType Test(...);

    static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");
```

### <a name="classes-declared-in-anonymous-namespaces"></a>Classes declaradas em namespaces anônimos

De acordo com o padrão C++, uma classe declarada dentro de um namespace anônimo tem vinculação interna e, portanto, não pode ser exportada. No Visual Studio 2015 e anteriores, essa regra não foi aplicada. No Visual Studio 2017, a regra foi parcialmente aplicada. O exemplo a seguir gera este erro no Visual Studio 2017: "erro C2201: const anonymous namespace::S1::vftable: deve ter vinculação externa para poder ser exportado/importado".

```cpp
struct __declspec(dllexport) S1 { virtual void f() {} }; //C2201
```

### <a name="default-initializers-for-value-class-members-ccli"></a>Inicializadores padrão para membros de classe de valor (C++/CLI)

No Visual Studio 2015 e nas versões anteriores, o compilador permitia (mas ignorava) um inicializador de membro padrão para um membro de uma classe de valor. A inicialização padrão de uma classe de valor sempre inicializa os membros em zero; um construtor padrão não é permitido. No Visual Studio 2017, os inicializadores de membro padrão geram um erro de compilador, conforme mostrado neste exemplo:

```cpp
value struct V
{
    int i = 0; // error C3446: 'V::i': a default member initializer
               // is not allowed for a member of a value class
};
```

### <a name="default-indexers-ccli"></a>Indexadores padrão (C++/CLI)

No Visual Studio 2015 e em versões anteriores, o compilador, em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. É possível resolver o problema usando o identificador `default` para acessar a propriedade. A solução em si se tornou um problema depois que `default` foi introduzido como uma palavra-chave no C++ 11. Portanto, no Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos, e agora o compilador gera um erro quando o `default` é usado para acessar a propriedade padrão de uma classe.

```cpp
//class1.cs

using System.Reflection;
using System.Runtime.InteropServices;

namespace ClassLibrary1
{
    [DefaultMember("Value")]
    public class Class1
    {
        public int Value
        {
            // using attribute on the return type triggers the compiler bug
            [return: MarshalAs(UnmanagedType.I4)]
            get;
        }
    }
    [DefaultMember("Value")]
    public class Class2
    {
        public int Value
        {
            get;
        }
    }
}

// code.cpp
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value; // error
       r1->default;
       r2->Value;
       r2->default; // error
}
```

No Visual Studio de 2017, é possível acessar ambas as propriedades Value pelo nome:

```cpp
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value;
       r2->Value;
}
```

## <a name="update_153"></a> Correções de bugs no Visual Studio 2017 versão 15.3

### <a name="calls-to-deleted-member-templates"></a>Chamadas para modelos de membros excluídos

Nas versões anteriores do Visual Studio, em alguns casos o compilador falhará ao emitir um erro para chamadas malformados para um modelo de membro excluído que poderia potencialmente causar falhas em tempo de execução. Agora, o código a seguir produz C2280, "'int S\<int>::f\<int>(void)': tentativa de fazer referência a uma função excluída":

```cpp
template<typename T>
struct S {
   template<typename U> static int f() = delete;
};

void g()
{
   decltype(S<int>::f<int>()) i; // this should fail
}
```

Para corrigir o erro, declare i como `int`.

### <a name="pre-condition-checks-for-type-traits"></a>Verificações de pré-condição para características de tipo

O Visual Studio 2017 versão 15.3 melhora as verificações de pré-condição para características de tipo para seguir o padrão mais estritamente. Uma verificação assim destina-se aos atribuíveis. O código a seguir produz C2139 no Visual Studio 2017 versão 15.3:

```cpp
struct S;
enum E;

static_assert(!__is_assignable(S, S), "fail"); // C2139 in 15.3
static_assert(__is_convertible_to(E, E), "fail"); // C2139 in 15.3
```

### <a name="new-compiler-warning-and-runtime-checks-on-native-to-managed-marshaling"></a>Novas verificações de tempo de execução e o aviso do compilador em marshaling nativo para gerenciado

Chamar desde funções gerenciadas para funções nativas requer o marshaling. O CLR realiza marshaling, mas não entende a semântica do C++. Se você passar um objeto nativo por valor, o CLR chamará o construtor de cópia do objeto ou usará BitBlt, o que poderá causar um comportamento indefinido em tempo de execução.

Agora, o compilador emitirá um aviso se puder saber em tempo de compilação que um objeto nativo com o construtor de cópia excluído será passado entre limites nativos e gerenciados por valor. Nos casos em que o compilador não souber em tempo de compilação, ele injetará uma verificação de tempo de execução para que o programa chame `std::terminate` imediatamente quando um empacotamento malformado ocorrer. No Visual Studio 2017 versão 15.3, o código a seguir produz o aviso C4606 "'A': passar o argumento por valor entre limites nativo e gerenciado exige um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução é indefinido".

```cpp
class A
{
public:
   A() : p_(new int) {}
   ~A() { delete p_; }

   A(A const &) = delete;
   A(A &&rhs) {
   p_ = rhs.p_;
}

private:
   int *p_;
};

#pragma unmanaged

void f(A a)
{
}

#pragma managed

int main()
{
    f(A()); // This call from managed to native requires marshalling. The CLR doesn't understand C++ and uses BitBlt, which results in a double-free later.
}
```

Para corrigir o erro, remova a política `#pragma managed` para marcar o chamador como nativo e evitar o empacotamento.

### <a name="experimental-api-warning-for-winrt"></a>Aviso de API experimental para WinRT

As APIs do WinRT lançadas para experimentação e comentários são decoradas com `Windows.Foundation.Metadata.ExperimentalAttribute`. No Visual Studio 2017 versão 15.3, o compilador gera o aviso C4698 quando encontrar o atributo. Algumas APIs em versões anteriores do SDK do Windows já tinham sido decoradas com o atributo, e chamadas para essas APIs agora começam a disparar esse aviso do compilador. Os SDKs mais recentes têm o atributo removido de todos os tipos enviados, mas se você estiver usando um SDK mais antigo, precisará suprimir esses avisos para todas as chamadas para tipos enviados.

O código a seguir produz o aviso C4698: "'Windows::Storage::IApplicationDataStatics2::GetForUserAsync' é para fins de avaliação e está sujeito a alteração ou remoção em atualizações futuras":

```cpp
Windows::Storage::IApplicationDataStatics2::GetForUserAsync(); //C4698
```

Para desabilitar o aviso, adicione um #pragma:

```cpp
#pragma warning(push)
#pragma warning(disable:4698)

Windows::Storage::IApplicationDataStatics2::GetForUserAsync();

#pragma warning(pop)
```

### <a name="out-of-line-definition-of-a-template-member-function"></a>Definição fora da linha de uma função de membro de modelo

O Visual Studio 2017 versão 15.3 produz um erro ao encontrar uma definição fora da linha de uma função de membro de modelo que não foi declarada na classe. Agora, o código a seguir produz o erro C2039: 'f': não é membro de 'S':

```cpp
struct S {};

template <typename T>
void S::f(T t) {} //C2039: 'f': is not a member of 'S'
```

Para corrigir o erro, adicione uma declaração à classe:

```cpp
struct S {
    template <typename T>
    void f(T t);
};
template <typename T>
void S::f(T t) {}
```

### <a name="attempting-to-take-the-address-of-this-pointer"></a>Tentativa de obter o endereço do ponteiro "this"

Em C++, `this` é um prvalue do tipo ponteiro para X. Você não pode obter o endereço de `this` nem o associar a uma referência de lvalue. Nas versões anteriores do Visual Studio, o compilador permitia evitar essa restrição, executando uma conversão. No Visual Studio 2017 versão 15.3, o compilador produz o erro C2664.

### <a name="conversion-to-an-inaccessible-base-class"></a>Conversão em uma classe base inacessível

O Visual Studio 2017 versão 15.3 produz um erro durante a tentativa de converter um tipo em uma classe base que está inacessível. O compilador agora gera "erro C2243: 'conversão de tipo': a conversão de 'D *' em 'B *' existe, mas está inacessível". O código a seguir está malformado e poderá causar uma falha em tempo de execução. Agora, o compilador produz C2243 ao encontrar código como este:

```cpp
#include <memory>

class B { };
class D : B { }; // C2243. should be public B { };

void f()
{
   std::unique_ptr<B>(new D());
}
```

### <a name="default-arguments-are-not-allowed-on-out-of-line-definitions-of-member-functions"></a>Os argumentos padrão não são permitidos em definições fora de linha de funções de membro

Argumentos padrão não são permitidos em definições fora de linha de funções de membro em classes de modelo. O compilador emitirá um aviso em **/permissive** e um erro de hardware em **/permissive-**.

Nas versões anteriores do Visual Studio, o código malformado a seguir pode causar uma falha de tempo de execução. O Visual Studio 2017 versão 15.3 produz o aviso C5034: 'A\<T>::f': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão:

```cpp
template <typename T>
struct A {
    T f(T t, bool b = false);
};

template <typename T>
T A<T>::f(T t, bool b = false) // C5034
{
    // ...
}
```

Para corrigir o erro, remova o argumento padrão `= false`.

### <a name="use-of-offsetof-with-compound-member-designator"></a>Uso de offsetof com o designador de membro composto

No Visual Studio 2017 versão 15.3, usar `offsetof(T, m)`, em que *m* é um “designador membro composto", resulta em um aviso quando você compilar com a opção **/Wall**. O código a seguir está malformado e pode causar falhas em tempo de execução. O Visual Studio 2017 versão 15.3 produz o "aviso C4841: extensão não padrão usada: designador de membro composto em offsetof":

```cpp
struct A {
   int arr[10];
};

// warning C4841: non-standard extension used: compound member designator in offsetof
constexpr auto off = offsetof(A, arr[2]);
```

Para corrigir o código, desabilite o aviso com um pragma ou altere o código para não usar `offsetof`:

```cpp
#pragma warning(push)
#pragma warning(disable: 4841)
constexpr auto off = offsetof(A, arr[2]);
#pragma warning(pop)
```

### <a name="using-offsetof-with-static-data-member-or-member-function"></a>Uso do offsetof com o membro de dados estáticos ou função de membro

No Visual Studio 2017 versão 15.3, usar `offsetof(T, m)`, em que *m* se refere a um membro de dados estático ou uma função de membro, resultará em um erro. O código a seguir produz o "erro C4597: comportamento indefinido: offsetof aplicado à função de membro 'foo'" e "erro C4597: comportamento indefinido: offsetof aplicado ao membro de dados estáticos 'bar'":

```cpp
#include <cstddef>

struct A {
   int foo() { return 10; }
   static constexpr int bar = 0;
};

constexpr auto off = offsetof(A, foo);
constexpr auto off2 = offsetof(A, bar);
```

Esse código está malformado e pode causar falhas em tempo de execução. Para corrigir o erro, altere o código para não invocar mais um comportamento indefinido. Este é o código não portátil que não é permitido pelo padrão de C++.

### <a name="declspec"></a> Novo aviso de atributos declspec

No Visual Studio 2017 versão 15.3, o compilador não ignora os atributos se `__declspec(...)` é aplicado antes da especificação de vinculação `extern "C"`. Anteriormente, o compilador ignorava o atributo, o que podia ter implicações de tempo de execução. Quando as opções **/Wall** e **/WX** são definidas, o código a seguir produz o "aviso C4768: atributos __declspec antes da especificação de vinculação são ignorados":

```cpp
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

Para corrigir o aviso, coloque o "C" externo em primeiro lugar:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```

Esse aviso é desativado por padrão na versão 15.3, mas ativado por padrão na 15.5, e só afeta o código compilado com **/Wall** **/WX**.

### <a name="decltype-and-calls-to-deleted-destructors"></a>decltype e chamadas para destruidores excluídos

Nas versões anteriores do Visual Studio, o compilador não detectava quando ocorria uma chamada para um destruidor excluído no contexto de expressão associado 'decltype'. No Visual Studio 2017 versão 15.3, o código a seguir produz o "Erro C2280: 'A\<T>::~A(void)': ao tentar fazer referência a uma função excluída":

```cpp
template<typename T>
struct A
{
   ~A() = delete;
};

template<typename T>
auto f() -> A<T>;

template<typename T>
auto g(T) -> decltype((f<T>()));

void h()
{
   g(42);
}
```

### <a name="uninitialized-const-variables"></a>Variáveis constantes não inicializadas

A versão do Visual Studio 2017 RTW tinha uma regressão em que o compilador do C++ não emitia um diagnóstico se uma variável 'const' não fosse inicializada. Essa regressão foi corrigida no Visual Studio 2017 versão 15.3. Agora, o código a seguir produz o "aviso C4132: 'Value': objeto const deve ser inicializado":

```cpp
const int Value; //C4132
```

Para corrigir o erro, atribua um valor a `Value`.

### <a name="empty-declarations"></a>Declarações vazias

O Visual Studio 2017 versão 15.3 agora avisa sobre declarações vazias para todos os tipos, não apenas tipos internos. Agora, o código a seguir produz um aviso C4091 de nível 2 para todas as quatro declarações:

```cpp
struct A {};
template <typename> struct B {};
enum C { c1, c2, c3 };

int;    // warning C4091 : '' : ignored on left of 'int' when no variable is declared
A;      // warning C4091 : '' : ignored on left of 'main::A' when no variable is declared
B<int>; // warning C4091 : '' : ignored on left of 'B<int>' when no variable is declared
C;      // warning C4091 : '' : ignored on left of 'C' when no variable is declared
```

Para remover os avisos, simplesmente comente ou remova as declarações vazias. Em casos em que o objeto nomeado não se destinar a ter um efeito colateral (como RAII), deverá receber um nome.

O aviso é excluído em **/Wv:18** e é ativado por padrão em W2 de nível de aviso.

### <a name="stdisconvertible-for-array-types"></a>std::is_convertible para tipos de matriz

As versões anteriores do compilador forneciam resultados incorretos para [std::is_convertible](standard-library/is-convertible-class.md) para tipos de matriz. Isso exigia que gravadores de biblioteca tratassem o compilador Microsoft Visual C++ de forma especial ao usar a característica de tipo `std::is_convertible<...>`. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 versão 15.3:

```cpp
#include <type_traits>

using Array = char[1];

static_assert(std::is_convertible<Array, Array>::value);
static_assert(std::is_convertible<const Array, const Array>::value, "");
static_assert(std::is_convertible<Array&, Array>::value, "");
static_assert(std::is_convertible<Array, Array&>::value, "");
```

`std::is_convertible<From, To>` é calculada para verificar se uma definição de função imaginária está bem formada:

```cpp
   To test() { return std::declval<From>(); }
```

### <a name="private-destructors-and-stdisconstructible"></a>Destruidores particulares e std::is_constructible

As versões anteriores do compilador ignoravam se um destruidor era particular quando decidia o resultado de [std::is_constructible](standard-library/is-constructible-class.md). Agora ele os considera. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 versão 15.3:

```cpp
#include <type_traits>

class PrivateDtor {
   PrivateDtor(int) { }
private:
   ~PrivateDtor() { }
};

// This assertion used to succeed. It now correctly fails.
static_assert(std::is_constructible<PrivateDtor, int>::value);
```

Os destruidores particulares fazem com que um tipo não seja construível. `std::is_constructible<T, Args...>` é calculada como se a declaração a seguir estivesse escrita:

```cpp
   T obj(std::declval<Args>()...)
```

Essa chamada implica em uma chamada de destruidor.

### <a name="c2668-ambiguous-overload-resolution"></a>C2668: resolução de sobrecarga ambígua

As versões anteriores do compilador falhavam algumas vezes ao detectar ambiguidade quando encontravam vários candidatos, tanto por meio de declarações using quanto de pesquisas dependentes de argumento. Isso poderia levar à escolha errada de sobrecarga e ao comportamento inesperado de tempo de execução. No exemplo a seguir, o Visual Studio 2017 versão 15.3 aciona corretamente o C2668 'f': chamada ambígua à função sobrecarregada:

```cpp
namespace N {
   template<class T>
   void f(T&, T&);

   template<class T>
   void f();
}

template<class T>
void f(T&, T&);

struct S {};
void f()
{
   using N::f;

   S s1, s2;
   f(s1, s2); // C2668
}
```

Para corrigir o código, remova o uso da instrução `N::f` se você pretende chamar `::f()`.

### <a name="c2660-local-function-declarations-and-argument-dependent-lookup"></a>C2660: declarações de função local e pesquisa dependente de argumento

As declarações de função local ocultam a declaração da função no escopo delimitador e desabilitam a pesquisa dependente de argumento. No entanto, as versões anteriores do compilador executavam a pesquisa dependente de argumento nesse caso, possivelmente resultando na escolha errada de sobrecarga e em comportamento inesperado de tempo de execução. Normalmente, o erro é devido a uma assinatura incorreta da declaração da função local. No exemplo a seguir, o Visual Studio 2017 versão 15.3 aciona corretamente o C2660 'f': função não recebe 2 argumentos:

```cpp
struct S {};
void f(S, int);

void g()
{
   void f(S); // C2660 'f': function does not take 2 arguments:
   // or void f(S, int);
   S s;
   f(s, 0);
}
```

Para corrigir o problema, altere a assinatura `f(S)` ou remova-a.

### <a name="c5038-order-of-initialization-in-initializer-lists"></a>C5038: ordem de inicialização em listas de inicializador

Os membros de classe são inicializados na ordem em que são declarados e não na ordem em que aparecem em listas de inicializador. As versões anteriores do compilador não avisavam quando a ordem da lista de inicializador era diferente da ordem da declaração. Isso poderia resultar em comportamento indefinido de tempo de execução, caso a inicialização de um membro dependesse de outro membro na lista que já estivesse sendo inicializada. No exemplo a seguir, o Visual Studio 2017 versão 15.3 (com **/Wall**) aciona o "aviso C5038: membro de dados 'A::y' será inicializados após o membro de dados 'A::x'":

```cpp
struct A
{
    A(int a) : y(a), x(y) {} // Initialized in reverse, y reused
    int x;
    int y;
};
```

Para corrigir o problema, organize a lista de inicializador para que tenha a mesma ordem que as declarações. Um aviso semelhante é gerado quando um ou ambos os inicializadores fazem referência a membros de classe base.

Observe que o aviso está desativado por padrão e afeta somente o código compilado com **/Wall**.

## <a name="update_155"></a> Correções de bugs e outras alterações de comportamento no Visual Studio 2017 versão 15.5

### <a name="partial-ordering-change"></a>Alteração de ordenação parcial

O compilador agora rejeita corretamente o código a seguir e oferece a mensagem de erro correta:

```cpp
template<typename... T>
int f(T* ...)
{
    return 1;
}

template<typename T>
int f(const T&)
{
    return 2;
}

int main()
{
    int i = 0;
    f(&i);    // C2668
}
```

```Output
t161.cpp
t161.cpp(16): error C2668: 'f': ambiguous call to overloaded function
t161.cpp(8): note: could be 'int f<int*>(const T &)'
        with
        [
            T=int*
        ]
t161.cpp(2): note: or       'int f<int>(int*)'
t161.cpp(16): note: while trying to match the argument list '(int*)'
```

O problema no exemplo acima é que há duas diferenças nos tipos (const versus não const e pacote versus não pack). Para eliminar o erro do compilador, remova uma das diferenças. Isso permite ao compilador ordenar inequivocamente as funções.

```cpp
template<typename... T>
int f(T* ...)
{
    return 1;
}

template<typename T>
int f(T&)
{
    return 2;
}

int main()
{
    int i = 0;
    f(&i);
}
```

### <a name="exception-handlers"></a>Manipuladores de exceção

Manipuladores de referência para o tipo de matriz ou função nunca são uma correspondência para qualquer objeto de exceção. O compilador agora segue corretamente essa regra e aciona um aviso de nível 4. Ele também não corresponde mais a um manipulador de `char*` ou `wchar_t*` para um literal de cadeia de caracteres quando **/ZC: strictStrings** é usado.

```cpp
int main()
{
    try {
        throw "";
    }
    catch (int (&)[1]) {} // C4843 (This should always be dead code.)
    catch (void (&)()) {} // C4843 (This should always be dead code.)
    catch (char*) {} // This should not be a match under /Zc:strictStrings
}
```

```Output
warning C4843: 'int (&)[1]': An exception handler of reference to array or function type is unreachable, use 'int*' instead
warning C4843: 'void (__cdecl &)(void)': An exception handler of reference to array or function type is unreachable, use 'void (__cdecl*)(void)' instead
```

O código a seguir evita o erro:

```cpp
catch (int (*)[1]) {}
```

### <a name="tr1"></a>std::tr1 namespace foi preterido

O namespace não padrão `std::tr1` está marcado como preterido nos modos C++14 e C++17. No Visual Studio 2017 versão 15.5, o código a seguir aciona C4996:

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    std::tr1::function<int (int, int)> f = std::plus<int>(); //C4996
    cout << f(3, 5) << std::endl;
    f = std::multiplies<int>();
    cout << f(3, 5) << std::endl;
}
```

```Output
warning C4996: 'std::tr1': warning STL4002: The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.
```

Para corrigir o erro, remova a referência ao namespace `tr1`:

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    std::function<int (int, int)> f = std::plus<int>();
    cout << f(3, 5) << std::endl;
    f = std::multiplies<int>();
    cout << f(3, 5) << std::endl;
}
```

### <a name="annex_d"></a>Recursos da Biblioteca Padrão no Anexo D estão marcados como preteridos

Quando a opção do compilador do modo **/std:c++17** está definida, quase todos os recursos da Biblioteca Padrão do anexo D são marcados como preteridos.

No Visual Studio 2017 versão 15.5, o código a seguir aciona C4996:

```cpp
#include <iterator>

class MyIter : public std::iterator<std::random_access_iterator_tag, int> {
public:
    // ... other members ...
};

#include <type_traits>

static_assert(std::is_same<MyIter::pointer, int*>::value, "BOOM");
```

```Output
warning C4996: 'std::iterator<std::random_access_iterator_tag,int,ptrdiff_t,_Ty*,_Ty &>::pointer': warning STL4015: The std::iterator class template (used as a base class to provide typedefs) is deprecated in C++17. (The <iterator> header is NOT deprecated.) The C++ Standard has never required user-defined iterators to derive from std::iterator. To fix this warning, stop deriving from std::iterator and start providing publicly accessible typedefs named iterator_category, value_type, difference_type, pointer, and reference. Note that value_type is required to be non-const, even for constant iterators. You can define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
```

Para corrigir o erro, siga as instruções no texto de aviso, conforme demonstrado no código a seguir:

```cpp
#include <iterator>

class MyIter {
public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef int value_type;
    typedef ptrdiff_t difference_type;
    typedef int* pointer;
    typedef int& reference;

    // ... other members ...
};

#include <type_traits>

static_assert(std::is_same<MyIter::pointer, int*>::value, "BOOM");
```

### <a name="unreferenced-local-variables"></a>Variáveis locais não referenciadas

No Visual Studio 15.5, o aviso C4189 é emitido em mais casos, conforme mostrado no código a seguir:

```cpp
void f() {
    char s[2] = {0}; // C4189. Either use the variable or remove it.
}
```

```Output
warning C4189: 's': local variable is initialized but not referenced
```

Para corrigir o erro, remova a variável não usada.

### <a name="single-line-comments"></a>Comentários de linha única

No Visual Studio 2017 versão 15.5, os avisos C4001 e C4179 não são emitidos pelo compilador C. Anteriormente, eles somente eram emitidos na opção do compilador **/Za**.  Os avisos não são mais necessários porque comentários de linha única fazem parte de C padrão desde C99.

```cpp
/* C only */
#pragma warning(disable:4001) //C4619
#pragma warning(disable:4179)
// single line comment
//* single line comment */
```

```Output
warning C4619: #pragma warning: there is no warning number '4001'
```

Se o código não precisar ser compatível com versões anteriores, você poderá evitar o aviso removendo a supressão de C4001/C4179. Se o código precisar ser compatível com versões anteriores, suprima somente C4619.

```C

/* C only */

#pragma warning(disable:4619)
#pragma warning(disable:4001)
#pragma warning(disable:4179)

// single line comment
/* single line comment */
```

### <a name="declspec-attributes-with-extern-c-linkage"></a>Atributos __declspec com vínculo “C” externo

Em versões anteriores do Visual Studio, o compilador ignorou atributos `__declspec(...)` quando `__declspec(...)` foi aplicado antes da especificação de vinculação `extern "C"`. Esse comportamento faz com que seja gerado código não pretendido pelo usuário, com possíveis consequências no tempo de execução. O aviso foi adicionado no Visual Studio versão 15.3, mas era desativado por padrão. No Visual Studio 2017 versão 15.5, o aviso está habilitado por padrão.

```cpp
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

```Output
warning C4768: __declspec attributes before linkage specification are ignored
```

Para corrigir o erro, coloque a especificação de vinculação antes do atributo __declspec:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```

Esse novo aviso C4768 é determinado em alguns cabeçalhos do SDK do Windows que foram fornecidos com o Visual Studio 2017 15.3 ou anterior (por exemplo: versão 10.0.15063.0, também conhecido como SDK do RS2). No entanto, as versões posteriores dos cabeçalhos do SDK do Windows (especificamente, ShlObj.h e ShlObj_core.h) foram corrigidas para que não produzam este aviso. Quando você vir esse aviso proveniente de cabeçalhos do SDK do Windows, poderá executar estas ações:

1. Mude para o SDK do Windows mais recente que acompanha o Visual Studio 2017 versão 15.5.
2. Desligue o aviso ao redor de #include da instrução de cabeçalho do SDK do Windows:

```cpp
   #pragma warning (push)
   #pragma warning(disable:4768)
   #include <shlobj.h>
   #pragma warning (pop)
   ```

### <a name="extern_linkage"></a>Vinculação de constexpr externo

Em versões anteriores do Visual Studio, o compilador sempre forneceu uma ligação interna variável `constexpr`, mesmo quando a variável era marcada como `extern`. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, (**/Zc:externConstexpr**), habilita o comportamento correto em conformidade com os padrões. Eventualmente, isso se tornará o padrão.

```cpp
extern constexpr int x = 10;
```

```Output
error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada `extern constexpr`, ele precisará ser marcado como `__declspec(selectany)` para que suas declarações duplicadas sejam combinadas corretamente:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

### <a name="typeid-cant-be-used-on-incomplete-class-type"></a>TypeId não pode ser usado em um tipo de classe incompleto

Em versões anteriores do Visual Studio, o compilador permitia incorretamente o código a seguir, resultando em informações de tipo potencialmente incorretas. No Visual Studio 2017 versão 15.5, o compilador produz corretamente um erro:

```cpp
#include <typeinfo>

struct S;

void f() { typeid(S); } //C2027 in 15.5
```

```Output
error C2027: use of undefined type 'S'
```

### <a name="stdisconvertible-target-type"></a>Tipo de destino std::is_convertible

`std::is_convertible` requer que o tipo de destino seja um tipo de retorno válido. Em versões anteriores do Visual Studio, o compilador permitia incorretamente tipos abstratos, que podem levar à resolução de sobrecarga incorreta e ao comportamento de tempo de execução imprevisto.  O código a seguir agora aciona C2338 corretamente:

```cpp
#include <type_traits>

struct B { virtual ~B() = 0; };
struct D : public B { virtual ~D(); };

static_assert(std::is_convertible<D, B>::value, "fail"); // C2338 in 15.5
```

Para evitar o erro, você deve comparar tipos de ponteiro ao usar `is_convertible`, pois uma comparação de tipo que não é de ponteiro poderá falhar se um tipo for abstrato:

```cpp
#include <type_traits>

struct B { virtual ~B() = 0; };
struct D : public B { virtual ~D(); };

static_assert(std::is_convertible<D *, B *>::value, "fail");
```

### <a name="noexcept_removal"></a> Remoção de especificação de exceção dinâmica e noexcept

No C++ 17, `throw()` é um alias para `noexcept`, `throw(<type list>)` e `throw(...)` foram removidos e determinados tipos podem incluir `noexcept`. Isso pode causar problemas de compatibilidade de origem com o código que está em conformidade com a C + + 14 ou anterior. A opção **/Zc:noexceptTypes-** pode ser usada para reverter para a versão C++14 do `noexcept` ao usar o modo C++17 em geral. Isso permite que você atualize seu código-fonte para estar em conformidade com a C++17 sem precisar reescrever todo o código `throw()` ao mesmo tempo.

O compilador agora também diagnostica mais especificações de exceção incompatíveis em declarações no modo C++17 ou com **/permissive-** com o novo aviso C5043.

O código a seguir gera C5043 e C5040 no Visual Studio 2017 versão 15.5 quando a opção **/std:c++17** é aplicada:

```cpp
void f() throw(); // equivalent to void f() noexcept;
void f() {} // warning C5043
void g() throw(); // warning C5040

struct A {
    virtual void f() throw();
};

struct B : A {
    virtual void f() { } // error C2694
};
```

Para remover os erros enquanto estiver usando **/std:c++17**, adicione a opção **/Zc:noexceptTypes-** à linha de comando ou atualize o código para usar `noexcept`, conforme mostrado no exemplo a seguir:

```cpp
void f() noexcept;
void f() noexcept { }
void g() noexcept(false);

struct A {
    virtual void f() noexcept;
};

struct B : A {
    virtual void f() noexcept { }
};
```

### <a name="inline-variables"></a>Variáveis embutidas

Membros de dados constexpr estáticos agora são implicitamente embutidos, o que significa que sua declaração em uma classe agora é sua definição. Usar uma definição fora de linha para um membro de dados constexpr estáticos é redundante e agora está preterido. No Visual Studio 2017 versão 15.5 quando a opção **/std:c++17** é aplicada, o código a seguir agora produz o aviso C5041 *'size': a definição fora de linha para o membro de dados estáticos constexpr não é necessária e foi preterida no C++17*:

```cpp
struct X {
    static constexpr int size = 3;
};
const int X::size; // C5041
```

### <a name="extern-c-declspec-warning-c4768-now-on-by-default"></a>O aviso de “C” __declspec(...) externo C4768 agora é ativado por padrão

O aviso foi adicionado no Visual Studio versão 2017 versão 15.3, mas era desativado por padrão. No Visual Studio 2017 versão 15.5 ele está ativado por padrão. Consulte [Novo aviso de atributos declspec](#declspec) para ver mais informações.

### <a name="defaulted-functions-and-declspecnothrow"></a>Funções padronizadas e __declspec(nothrow)

O compilador permitia anteriormente que funções padronizadas fossem declaradas com `__declspec(nothrow)` quando as funções de base/membro correspondente permitiam exceções. Esse comportamento é contrário ao C++ Standard e pode causar um comportamento indefinido no tempo de execução. O padrão exige que tais funções sejam definidas como excluídas se houver uma incompatibilidade de especificação de exceção.  No **/std:c++17**, o código a seguir aciona um C2280 *tentativa de fazer referência a uma função excluída. A função foi excluída implicitamente porque a especificação de exceção explícita é incompatível com aquela da declaração implícita.*:

```cpp
struct A {
    A& operator=(const A& other) { // No exception specification; this function may throw.
        ...
    }
};

struct B : public A {
    __declspec(nothrow) B& operator=(const B& other) = default;
};

int main()
{
    B b1, b2;
    b2 = b1; // error C2280
}
```

Para corrigir esse código, remova o __declspec(nothrow) da função padronizada ou o `= default` e forneça uma definição para a função juntamente com qualquer manipulação de exceção necessária:

```cpp
struct A {
    A& operator=(const A& other) {
        // ...
    }
};

struct B : public A {
    B& operator=(const B& other) = default;
};

int main()
{
    B b1, b2;
    b2 = b1;
}
```

### <a name="noexcept-and-partial-specializations"></a>Especializações parciais e noexcept

Com noexcept no sistema de tipos, as especializações parciais para correspondência de tipos “chamáveis” específicos podem falhar ao compilar ou escolher o modelo primário devido a uma especialização parcial ausente para ponteiros para funções noexcept.

Nesses casos, pode ser necessário acrescentar especializações parciais adicionais para tratar os ponteiros de função noexcept e ponteiros noexcept para funções de membro. Essas sobrecargas só são válidas no modo **/std:c++17**. Se for necessário manter a compatibilidade com a C++14 e você estiver escrevendo código que outras pessoas consumirão, será necessário proteger essas novas sobrecargas dentro de diretivas `#ifdef`. Se você estiver trabalhando em um módulo independente, em vez de usar proteções `#ifdef`, será possível compilar simplesmente com a opção **/Zc:noexceptTypes-**.

O código a seguir é compilado em **/std:c++14**, mas falha em **/std:c++17** com "erro C2027: uso do tipo indefinido 'A\<T>'":

```cpp
template <typename T> struct A;

template <>
struct A<void(*)()>
{
    static const bool value = true;
};

template <typename T>
bool g(T t)
{
    return A<T>::value;
}

void f() noexcept {}

int main()
{
    return g(&f) ? 0 : 1; // C2027
}
```

O código a seguir terá êxito em **/std:c++17** porque o compilador escolhe a nova especialização parcial `A<void (*)() noexcept>`:

```cpp
template <typename T> struct A;

template <>
struct A<void(*)()>
{
    static const bool value = true;
};

template <>
struct A<void(*)() noexcept>
{
    static const bool value = true;
};

template <typename T>
bool g(T t)
{
    return A<T>::value;
}

void f() noexcept {}

int main()
{
    return g(&f) ? 0 : 1; // OK
}
```

## <a name="update_157"></a> Correções de bug e outras alterações de comportamento no Visual Studio 2017 versão 15.7

### <a name="c17-default-argument-in-the-primary-class-template"></a>C++17 Argumento padrão no modelo de classe primária

Essa alteração de comportamento é uma pré-condição para a [Dedução de argumento de modelo para modelos de classe – P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html), que é planejada para ser totalmente compatível com uma versão prévia posterior do Visual Studio 2017 versão 15.7.

Anteriormente, o compilador ignorava o argumento padrão no modelo de classe primária.

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int = 0) {} // Re-definition necessary
```

No modo **/std:c++17**, no Visual Studio 2017 versão 15.7, o argumento padrão não é ignorado:

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int) {} // Default argument is used
```

### <a name="dependent-name-resolution"></a>Resolução de nome dependente

Essa alteração de comportamento é uma pré-condição para a [Dedução de argumento de modelo para modelos de classe – P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html), que é planejada para ser totalmente compatível com uma versão prévia posterior do Visual Studio 2017 versão 15.7.

No exemplo a seguir, o compilador do Visual Studio 15.6 e anterior resolve `D::type` como `B<T>::type` no modelo de classe primária.

```cpp
template<typename T>
struct B {
    using type = T;
};

template<typename T>
struct D : B<T*> {
    using type = B<T*>::type;
};
```

O Visual Studio 2017 versão 15.7, no modo **/std:c++17**, exige a palavra-chave `typename`, na instrução `using` em D. Sem o `typename`, o compilador gerará o aviso C4346: *'B<T\*>::type': o nome dependente não é um tipo* e o erro C2061: *erro de sintaxe: identificador 'type'*:

```cpp
template<typename T>
struct B {
    using type = T;
};

template<typename T>
struct D : B<T*> {
    using type = typename B<T*>::type;
};
```

### <a name="c17-nodiscard-attribute---warning-level-increase"></a>C++17 Atributo [[nodiscard]] – aumento do nível de aviso

No Visual Studio 2017 versão 15.7 no modo **/std:c++17**, o nível de aviso de C4834 ("descartando o valor retornado da função com o atributo 'nodiscard'") é aumentado de W3 para W1. Você pode desabilitar o aviso com uma conversão para `void`, ou passando **/wd:4834** para o compilador

```cpp
[[nodiscard]] int f() { return 0; }

int main() {
    f(); // warning: discarding return value
         // of function with 'nodiscard'
}
```

### <a name="variadic-template-constructor-base-class-initialization-list"></a>Lista de inicialização de classe base do construtor de modelo Variadic

Em edições anteriores do Visual Studio, uma lista de inicialização de classe base do construtor de modelo variadic que não continha argumentos de modelos foi erroneamente permitida sem erro. No Visual Studio 2017 versão 15.7 é gerado um erro do compilador.

O seguinte exemplo de código do Visual Studio 2017 versão 15.7 gera o *erro C2614: D\<int>: inicialização de membro inválida: 'B' não é uma base ou membro*

```cpp
template<typename T>
struct B {};

template<typename T>
struct D : B<T>
{

    template<typename ...C>
    D() : B() {} // C2614. Missing template arguments to B.
};

D<int> d;
```

Para corrigir o erro, altere a expressão de B() para B\<T>().

### <a name="constexpr-aggregate-initialization"></a>Inicialização de agregação constexpr

As versões anteriores do compilador C++ tratavam incorretamente a inicialização de agregação constexpr; ela aceita o código inválido na qual a agregação init-list possui muitos elementos e produz um codegen incorreto para ele. O código a seguir é um exemplo desse código: 

```cpp
#include <array>
struct X {
    unsigned short a;
    unsigned char b;
};

int main() {
    constexpr std::array<X, 2> xs = {
        { 1, 2 },
        { 3, 4 }
    };
    return 0;
}

```

No Visual Studio 2017 versão 15.7 atualização 3 e versões posteriores, o exemplo anterior agora gera o erro *C2078 muitos inicializadores*. O exemplo a seguir mostra como corrigir o código. Ao inicializar um `std::array` com chaves init-lists aninhadas, forneça para matriz interna uma lista entre chaves própria:

```cpp
#include <array>
struct X {
    unsigned short a;
    unsigned char b;
};

int main() {
    constexpr std::array<X, 2> xs = {{ // note double braces
        { 1, 2 },
        { 3, 4 }
    }}; // note double braces
    return 0;
}

```

## <a name="update_158"></a> Correções de bugs e alterações de comportamento no Visual Studio 2017 versão 15.8

### <a name="typename-on-unqualified-identifiers"></a>typename em identificadores não qualificados

No modo [/permissive-](build/reference/permissive-standards-conformance.md), palavras-chave `typename` falsas em identificadores não qualificados nas definições de modelo de alias não são mais aceitas pelo compilador. O código a seguir agora produz C7511 *'T': a palavra-chave 'typename' precisa ser seguida por um nome qualificado*:

```cpp
template <typename T>
using  X = typename T;
```

Para corrigir o erro, basta alterar a segunda linha para `using  X = T;`.

### <a name="declspec-on-right-side-of-alias-template-definitions"></a>__declspec() no lado direito das definições de modelo de alias

[__declspec](cpp/declspec.md) não é mais permitido no lado direito de uma definição de modelo de alias. Ele era aceito anteriormente pelo compilador, mas era completamente ignorado e nunca resultava em um aviso de preterimento quando o alias era usado.

O atributo C++ padrão [\[\[preterido\]\]](cpp/attributes.md) pode ser usado nesse caso e será respeitado a partir do Visual Studio 2017 versão 15.6. O código a seguir agora produz C2760 *erro de sintaxe: token inesperado '__declspec', era esperado 'type specifier'*:

```cpp
template <typename T>
using X = __declspec(deprecated("msg")) T;
```

Para corrigir o erro, altere o código da seguinte forma (com o atributo colocado antes de '=' da definição do alias):

```cpp
template <typename T>
using  X [[deprecated("msg")]] = T;
```

### <a name="two-phase-name-lookup-diagnostics"></a>Diagnóstico de pesquisa de nome em duas fases

A pesquisa de nome em duas fases requer que os nomes não dependentes usados nos corpos do modelo fiquem visíveis para o modelo no tempo de definição. Anteriormente, o compilador C++ da Microsoft não pesquisava um nome não localizado até os tempos de instanciação. Agora, ele exige que os nomes não dependentes estejam vinculados no corpo do modelo.

Uma forma em que isso se manifesta é com a pesquisa em classes base dependentes. Anteriormente, o compilador permitia o uso de nomes definidos nas classes base dependentes porque a pesquisa deles acontecia durante o tempo de instanciação quando todos os tipos eram resolvidos. Agora, esse código é tratado como um erro. Nesses casos, você pode forçar a pesquisa da variável no tempo de instanciação qualificando-a com o tipo de classe base ou, de outro modo, tornando-a dependente, por exemplo, adicionando um ponteiro `this->`.

No modo **/permissive-**, o código a seguir agora gera C3861: *'base_value': identificador não encontrado*:

```cpp
template <class T>
struct Base {
    int base_value = 42;
};

template <class T>
struct S : Base<T> {
    int f() {
        return base_value;
    }
};

```

Para corrigir o erro, altere a instrução `return` para `return this->base_value;`.

### <a name="forward-declarations-and-definitions-in-namespace-std"></a>Declarações e definições de encaminhamento no namespace std

O padrão C++ não permite que um usuário adicione declarações ou definições de encaminhamento no namespace `std`. A adição de declarações ou de definições no namespace `std` ou em um namespace no namespace std agora resulta em um comportamento indefinido.

Em algum momento no futuro a Microsoft mudará o local em que alguns tipos STL são definidos. Quando isso acontecer, ela interromperá o código existente que adiciona as declarações de encaminhamento ao namespace `std`. Um novo aviso, o C4643, ajuda a identificar esses problemas de origem. O aviso está habilitado no modo **/default** e fica desativado por padrão. Ele afetará os programas que são compilados com **/Wall** ou **/WX**. 

O código a seguir agora gera C4643: *O 'vector' da declaração de encaminhamento no namespace std não é permitido pelo C++ Standard*. 


```cpp
namespace std { 
    template<typename T> class vector; 
} 
```

Para corrigir o erro, use uma diretiva **include** em vez de uma declaração de encaminhamento:

```cpp
#include <vector>
```

### <a name="constructors-that-delegate-to-themselves"></a>Construtores que delegam a si mesmos

O C++ Standard sugere que um compilador deve emitir um diagnóstico quando um construtor de delegação delega a si mesmo. O compilador C++ da Microsoft nos modos [/std:c++17](build/reference/std-specify-language-standard-version.md) e [/std:c++latest](build/reference/std-specify-language-standard-version.md) agora gera C7535: *'X::X': o construtor de delegação chama a si mesmo*.

Sem esse erro, o programa a seguir será compilado, mas gerará um loop infinito:

```cpp
class X { 
public: 
    X(int, int); 
    X(int v) : X(v){}
}; 
```

Para evitar o loop infinito, delegue para um construtor diferente:

```cpp
class X { 
public: 

    X(int, int); 
    X(int v) : X(v, 0) {} 
}; 
```

### <a name="offsetof-with-constant-expressions"></a>offsetof com expressões de constantes

[offsetof](c-runtime-library/reference/offsetof-macro.md) normalmente tem sido implementado usando uma macro que requer um [reinterpret_cast](cpp/reinterpret-cast-operator.md). Isso não é válido em contextos que requerem uma expressão de constante, mas usualmente o compilador C++ da Microsoft tem permitido isso. A macro offsetof que é fornecida como parte do STL usa corretamente um compilador intrínseco (**__builtin_offsetof**), mas muitas pessoas têm usado o truque da macro para definir seu próprio **offsetof**.  

No Visual Studio 2017 versão 15.8, o compilador restringe as áreas em que esses reinterpret_casts podem aparecer no modo padrão para ajudar o código a ficar em conformidade com o comportamento do C++ Standard. Em [/permissive-](build/reference/permissive-standards-conformance.md), as restrições são ainda mais rígidas. O uso do resultado de um offsetof em locais que requerem expressões de constante pode resultar em um código que emite o aviso C4644 *uso do padrão offsetof baseado em macro em expressões de constantes não padrão; nesse caso, use offsetof definido na biblioteca C++ Standard* ou C2975 *argumento de modelo inválido, uma expressão de constante em tempo de compilação é esperada*.

O código a seguir gera C4644 nos modos **/default** e **/std:c++17** e C2975 no modo **/permissive-**: 

```cpp
struct Data { 
    int x; 
}; 

// Common pattern of user-defined offsetof 
#define MY_OFFSET(T, m) (unsigned long long)(&(((T*)nullptr)->m)) 

int main() 

{ 
    switch (0) { 
    case MY_OFFSET(Data, x): return 0; 
    default: return 1; 
    } 
} 
```

Para corrigir o erro, use **offsetof** conforme a definição por meio de \<cstddef>:

```cpp
#include <cstddef>  

struct Data { 
    int x; 
};  

int main() 
{ 
    switch (0) { 
    case offsetof(Data, x): return 0; 
    default: return 1; 
    } 
} 
```


### <a name="cv-qualifiers-on-base-classes-subject-to-pack-expansion"></a>qualificadores de cv em classes base sujeitos a expansão de pacote

As versões anteriores do compilador C++ da Microsoft não detectavam que uma classe base tinha qualificadores de cv quando também estavam sujeitas à expansão de pacote. 

No Visual Studio 2017 versão 15.8, no modo **/permissive-** o código a seguir gera C3770 *'const S': não é uma classe base válida*: 

```cpp
template<typename... T> 
class X : public T... { };  

class S { };  

int main() 
{ 
    X<const S> x; 
} 
```
### <a name="template-keyword-and-nested-name-specifiers"></a>Palavra-chave de modelo e especificadores de nome aninhados

No modo **/permissive-**, o compilador agora requer que a palavra-chave `template` preceda um nome de modelo quando ela vier após um especificador de nome aninhado que seja dependente. 

O código a seguir no modo **/permissive-** agora gera C7510: *'foo': o uso do nome de modelo dependente precisa ser prefixado com 'template'. Observação: confira a referência à instanciação do modelo de classe ' X<T>' que está sendo compilado*:

```cpp
template<typename T> struct Base
{
    template<class U> void foo() {} 
}; 

template<typename T> 
struct X : Base<T> 
{ 
    void foo() 
    { 
        Base<T>::foo<int>(); 
    } 
}; 
```

Para corrigir o erro, adicione a palavra-chave `template` à instrução `Base<T>::foo<int>();`, conforme é mostrado no exemplo a seguir:

```cpp
template<typename T> struct Base
{
    template<class U> void foo() {}
};
 
template<typename T> 
struct X : Base<T> 
{ 
    void foo() 
    { 
        // Add template keyword here:
        Base<T>::template foo<int>(); 
    } 
}; 
```

## <a name="see-also"></a>Consulte também

[Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md)
