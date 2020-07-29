---
title: Expressões lambda em C++
ms.date: 05/07/2019
helpviewer_keywords:
- lambda expressions [C++]
- lambda expressions [C++], overview
- lambda expressions [C++], vs. function objects
ms.assetid: 713c7638-92be-4ade-ab22-fa33417073bf
ms.openlocfilehash: 6fcc26c3ed86c86264773a70ac16501c102e1861
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213327"
---
# <a name="lambda-expressions-in-c"></a>Expressões lambda em C++

No C++ 11 e posteriores, uma expressão lambda – geralmente chamada de *lambda*— é uma maneira conveniente de definir um objeto de função anônima (um *fechamento*) diretamente no local onde ele é invocado ou passado como um argumento para uma função. Normalmente, as Lambdas são usadas para encapsular algumas linhas de código que são passadas para algoritmos ou métodos assíncronos. Este artigo define o que são as lambdas, as compara a outras técnicas de programação, descreve suas vantagens e fornece um exemplo básico.

## <a name="related-topics"></a>Tópicos Relacionados

- [Expressões lambda versus objetos de função](lambda-expression-syntax.md)
- [Trabalhando com expressões lambda](examples-of-lambda-expressions.md)
- [Expressões lambda constexpr](lambda-expressions-constexpr.md)

## <a name="parts-of-a-lambda-expression"></a>Partes de uma expressão lambda

O padrão ISO C++ mostra um lambda simples que é passado como o terceiro argumento para a `std::sort()` função:

```cpp
#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}
```

Esta ilustração mostra as partes de um lambda:

![Elementos estruturais de uma expressão lambda](../cpp/media/lambdaexpsyntax.png "Elementos estruturais de uma expressão lambda")

1. *Capture a cláusula* (também conhecida como *lambda-apresentador* na especificação C++.)

1. *lista de parâmetros* Adicional. (Também conhecido como *Declarador lambda*)

1. *especificação mutável* Adicional.

1. *especificação de exceção* Adicional.

1. *tipo de retorno à direita* Adicional.

1. *corpo lambda*.

### <a name="capture-clause"></a>Cláusula capture

Um lambda pode introduzir novas variáveis em seu corpo (em **C++ 14**) e também pode acessar, ou *capturar*, variáveis do escopo ao redor. Um lambda começa com a cláusula Capture (*lambda-apresentador* na sintaxe padrão), que especifica quais variáveis são capturadas e se a captura é por valor ou por referência. Variáveis que têm o prefixo E comercial (`&`) são acessadas por referência e variáveis que não têm o prefixo são acessadas por valor.

Uma cláusula de captura vazia, `[ ]`, indica que o corpo da expressão lambda não acessa variáveis no escopo delimitador.

Você pode usar o modo de captura padrão (*captura-padrão* na sintaxe padrão) para indicar como capturar todas as variáveis externas que são referenciadas no lambda: `[&]` significa que todas as variáveis que você faz referência são capturadas pelas referências e `[=]` significa que elas são capturadas por valor. Você pode usar um modo de captura padrão e especificar o modo oposto explicitamente para variáveis específicas. Por exemplo, se um corpo de lambda acessar a variável externa `total` por referência e a variável externa `factor` por valor, as seguintes cláusulas de captura serão equivalentes:

```cpp
[&total, factor]
[factor, &total]
[&, factor]
[factor, &]
[=, &total]
[&total, =]
```

Somente variáveis mencionadas no lambda são capturadas quando um padrão de captura é usado.

Se uma cláusula Capture incluir uma captura-padrão `&` , não `identifier` em uma `capture` dessa cláusula de captura poderá ter o formulário `& identifier` . Da mesma forma, se a cláusula Capture incluir uma captura-padrão `=` , nenhuma `capture` dessa cláusula Capture poderá ter o formulário `= identifier` . Um identificador ou **`this`** não pode aparecer mais de uma vez em uma cláusula Capture. O snippet de código a seguir ilustra alguns exemplos.

```cpp
struct S { void f(int i); };

void S::f(int i) {
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}
```

Uma captura seguida por uma elipse é uma expansão de pacote, conforme mostrado neste exemplo de [modelo Variadic](../cpp/ellipses-and-variadic-templates.md) :

```cpp
template<class... Args>
void f(Args... args) {
    auto x = [args...] { return g(args...); };
    x();
}
```

Para usar expressões lambda no corpo de um método de classe, passe o **`this`** ponteiro para a cláusula Capture para fornecer acesso aos métodos e membros de dados da classe delimitadora.

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): o **`this`** ponteiro pode ser capturado por valor especificando **`*this`** na cláusula Capture. Captura por valor significa que o *fechamento*inteiro, que é o objeto de função anônima que encapulates a expressão lambda, é copiado para cada site de chamada onde o lambda é invocado. A captura por valor é útil quando o lambda será executado em operações paralelas ou assíncronas, especialmente em determinadas arquiteturas de hardware, como o NUMA.

Para obter um exemplo que mostra como usar expressões lambda com métodos de classe, consulte "exemplo: usando uma expressão lambda em um método" em [exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).

Ao usar a cláusula de captura, nós recomendamos que você mantenha esses pontos em mente, especialmente ao usar lambdas com multithreading:

- As capturas de referência podem ser usadas para modificar variáveis externas, mas as capturas de valor não. ( **`mutable`** permite que as cópias sejam modificadas, mas não originais).

- As capturas de referência refletem atualizações para variáveis externas, mas as capturas de valor não.

- As capturas de referência introduzem uma dependência de tempo de vida, mas as capturas de valor não possuem dependências de tempo de vida. Isso é especialmente importante quando o lambda é executado de forma assíncrona. Se você capturar um local por referência em um lambda assíncrono, esse local possivelmente estará no momento em que o lambda é executado, resultando em uma violação de acesso no tempo de execução.

### <a name="generalized-capture-c-14"></a>Captura generalizada (C++ 14)

No C++ 14, você pode introduzir e inicializar novas variáveis na cláusula Capture, sem a necessidade de ter essas variáveis no escopo delimitador da função lambda. A inicialização pode ser expressa como qualquer expressão arbitrária; o tipo da nova variável é deduzido do tipo produzido pela expressão. Um benefício desse recurso é que, no C++ 14, você pode capturar variáveis somente de movimentação (como std:: unique_ptr) do escopo ao redor e usá-las em um lambda.

```cpp
pNums = make_unique<vector<int>>(nums);
//...
      auto a = [ptr = move(pNums)]()
        {
           // use ptr
        };
```

### <a name="parameter-list"></a>Lista de parâmetros

Além de capturar variáveis, um lambda pode aceitar parâmetros de entrada. Uma lista de parâmetros (*Declarador lambda* na sintaxe padrão) é opcional e, na maioria dos aspectos, é semelhante à lista de parâmetros para uma função.

```cpp
auto y = [] (int first, int second)
{
    return first + second;
};
```

No **C++ 14**, se o tipo de parâmetro for genérico, você poderá usar a **`auto`** palavra-chave como o especificador de tipo. Isso informa o compilador para criar o operador de chamada de função como um modelo. Cada instância do **`auto`** em uma lista de parâmetros é equivalente a um parâmetro de tipo distinto.

```cpp
auto y = [] (auto first, auto second)
{
    return first + second;
};
```

Uma expressão lambda pode usar outra expressão lambda como seu argumento. Para obter mais informações, consulte "expressões lambda de ordem superior" no tópico [exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).

Como uma lista de parâmetros é opcional, você pode omitir os parênteses vazios se não passar argumentos para a expressão lambda e seu Declarador lambda não contiver uma *especificação de exceção*, de *retorno à direita*ou **`mutable`** .

### <a name="mutable-specification"></a>Especificação mutável

Normalmente, um operador de chamada de função de lambda é constante por valor, mas o uso da **`mutable`** palavra-chave cancela isso. Ele não produz membros de dados mutáveis. A especificação mutável permite que o corpo de uma expressão lambda modifique variáveis capturadas por valor. Alguns dos exemplos mais adiante neste artigo mostram como usar o **`mutable`** .

### <a name="exception-specification"></a>Especificação de exceção

Você pode usar a **`noexcept`** especificação de exceção para indicar que a expressão lambda não lança nenhuma exceção. Assim como acontece com funções comuns, o compilador do Microsoft C++ gera o aviso [C4297](../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md) se uma expressão lambda declara a **`noexcept`** especificação de exceção e o corpo lambda gera uma exceção, como mostrado aqui:

```cpp
// throw_lambda_expression.cpp
// compile with: /W4 /EHsc
int main() // C4297 expected
{
   []() noexcept { throw 5; }();
}
```

Para obter mais informações, consulte [especificações de exceção (throw)](../cpp/exception-specifications-throw-cpp.md).

### <a name="return-type"></a>Tipo de retorno

O tipo de retorno de uma expressão lambda é deduzido automaticamente. Você não precisa usar a [`auto`](../cpp/auto-cpp.md) palavra-chave, a menos que especifique um *tipo de retorno à direita*. O *tipo de retorno à direita* é semelhante à parte de tipo de retorno de um método ou função comum. No entanto, o tipo de retorno deve seguir a lista de parâmetros e você deve incluir a palavra-chave de tipo de retorno à direita **`->`** antes do tipo de retorno.

É possível omitir a parte return-type de uma expressão lambda se o corpo lambda contiver apenas uma instrução de retorno ou se a expressão lambda não retornar um valor. Se o corpo lambda contém uma instrução de retorno, o compilador deduzirá o tipo de retorno do tipo da expressão de retorno. Caso contrário, o compilador deduzirá o tipo de retorno como **`void`** . Considere os snippets de código do exemplo a seguir que ilustram esse princípio.

```cpp
auto x1 = [](int i){ return i; }; // OK: return type is int
auto x2 = []{ return{ 1, 2 }; };  // ERROR: return type is void, deducing
                                  // return type from braced-init-list is not valid
```

Uma expressão lambda pode gerar outra expressão lambda como seu valor de retorno. Para obter mais informações, consulte "expressões lambda de ordem superior" em [exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).

### <a name="lambda-body"></a>Corpo lambda

O corpo lambda (*instrução composta* na sintaxe padrão) de uma expressão lambda pode conter qualquer coisa que o corpo de um método ou função comum possa conter. O corpo de uma função comum e de uma expressão lambda pode acessar os seguintes tipos de variáveis:

- Variáveis capturadas do escopo delimitador, conforme descrito anteriormente.

- parâmetros

- Variáveis declaradas localmente

- Membros de dados de classe, quando declarados dentro de uma classe e **`this`** são capturados

- Qualquer variável que possui a duração de armazenamento estático como, por exemplo, variáveis globais

O exemplo a seguir contém uma expressão lambda que captura explicitamente a variável `n` por valor e que captura implicitamente a variável `m` por referência:

```cpp
// captures_lambda_expression.cpp
// compile with: /W4 /EHsc
#include <iostream>
using namespace std;

int main()
{
   int m = 0;
   int n = 0;
   [&, n] (int a) mutable { m = ++n + a; }(4);
   cout << m << endl << n << endl;
}
```

```Output
5
0
```

Como a variável `n` é capturada pelo valor, seu valor permanece `0` após a chamada para a expressão lambda. A **`mutable`** especificação permite que `n` seja modificada dentro do lambda.

Embora uma expressão lambda possa capturar apenas variáveis que tenham a duração automática de armazenamento, você pode usar variáveis que tenham a duração de armazenamento estático no corpo de uma expressão lambda. O exemplo a seguir usa a função `generate` e uma expressão lambda para atribuir um valor para cada elemento em um objeto `vector`. A expressão lambda modifica a variável estática para gerar o valor do próximo elemento.

```cpp
void fillVector(vector<int>& v)
{
    // A local static variable.
    static int nextValue = 1;

    // The lambda expression that appears in the following call to
    // the generate function modifies and uses the local static
    // variable nextValue.
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //WARNING: this is not thread-safe and is shown for illustration only
}
```

Para obter mais informações, consulte [gerar](../standard-library/algorithm-functions.md#generate).

O exemplo de código a seguir usa a função do exemplo anterior e adiciona um exemplo de uma expressão lambda que usa o algoritmo de biblioteca padrão C++ `generate_n` . Essa expressão lambda atribui um elemento de um objeto `vector` à soma dos dois elementos anteriores. A **`mutable`** palavra-chave é usada para que o corpo da expressão lambda possa modificar suas cópias das variáveis externas `x` e `y` , que a expressão lambda captura por valor. Uma vez que a expressão lambda captura as variáveis originais `x` e `y` por valor, seus valores permanecem `1` depois que a lambda é executada.

```cpp
// compile with: /W4 /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    // A local static variable.
    static int nextValue = 1;

    // The lambda expression that appears in the following call to
    // the generate function modifies and uses the local static
    // variable nextValue.
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //WARNING: this is not thread-safe and is shown for illustration only
}

int main()
{
    // The number of elements in the vector.
    const int elementCount = 9;

    // Create a vector object with each element set to 1.
    vector<int> v(elementCount, 1);

    // These variables hold the previous two elements of the vector.
    int x = 1;
    int y = 1;

    // Sets each element in the vector to the sum of the
    // previous two elements.
    generate_n(v.begin() + 2,
        elementCount - 2,
        [=]() mutable throw() -> int { // lambda is the 3rd parameter
        // Generate current value.
        int n = x + y;
        // Update previous two values.
        x = y;
        y = n;
        return n;
    });
    print("vector v after call to generate_n() with lambda: ", v);

    // Print the local variables x and y.
    // The values of x and y hold their initial values because
    // they are captured by value.
    cout << "x: " << x << " y: " << y << endl;

    // Fill the vector with a sequence of numbers
    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    // Fill the vector with the next sequence of numbers
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);
}
```

```Output
vector v after call to generate_n() with lambda: 1 1 2 3 5 8 13 21 34
x: 1 y: 1
vector v after 1st call to fillVector(): 1 2 3 4 5 6 7 8 9
vector v after 2nd call to fillVector(): 10 11 12 13 14 15 16 17 18
```

Para obter mais informações, consulte [generate_n](../standard-library/algorithm-functions.md#generate_n).

## <a name="constexpr-lambda-expressions"></a>`constexpr`expressões lambda

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) ): uma expressão lambda pode ser declarada como **`constexpr`** ou usada em uma expressão constante quando a inicialização de cada membro de dados que captura ou apresenta é permitida em uma expressão constante.

```cpp
    int y = 32;
    auto answer = [y]() constexpr
    {
        int x = 10;
        return y + x;
    };

    constexpr int Increment(int n)
    {
        return [n] { return n + 1; }();
    }
```

Um lambda é implicitamente **`constexpr`** se o resultado satisfizer os requisitos de uma **`constexpr`** função:

```cpp
    auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);
```

Se uma lambda for implícita ou explicitamente **`constexpr`** , a conversão para um ponteiro de função produzirá uma **`constexpr`** função:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```

## <a name="microsoft-specific"></a>Específico da Microsoft

Não há suporte para lambdas nas seguintes entidades gerenciadas do Common Language Runtime (CLR): **`ref class`** , **`ref struct`** , **`value class`** ou **`value struct`** .

Se você estiver usando um modificador específico da Microsoft [`__declspec`](../cpp/declspec.md) , como, poderá inseri-lo em uma expressão lambda imediatamente após o `parameter-declaration-clause` – por exemplo:

```cpp
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };
```

Para determinar se um modificador é suportado por lambdas, consulte o artigo sobre ele na seção de [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md) da documentação.

Além da funcionalidade lambda padrão do C++ 11, o Visual Studio dá suporte a lambdas sem monitoração de estado, que são conversíveis pelo Omni para funções que usam convenções de chamada arbitrárias.

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Objetos de função na biblioteca padrão C++](../standard-library/function-objects-in-the-stl.md)<br/>
[Chamada de função](../cpp/function-call-cpp.md)<br/>
[`for_each`](../standard-library/algorithm-functions.md#for_each)
