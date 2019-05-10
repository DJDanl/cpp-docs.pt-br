---
title: Expressões lambda em C++
ms.date: 05/07/2019
helpviewer_keywords:
- lambda expressions [C++]
- lambda expressions [C++], overview
- lambda expressions [C++], vs. function objects
ms.assetid: 713c7638-92be-4ade-ab22-fa33417073bf
ms.openlocfilehash: c7543b3558da88b41102fa7b790bb9d9f3f18463
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222374"
---
# <a name="lambda-expressions-in-c"></a>Expressões lambda em C++

No C++ 11 e posterior, uma expressão lambda — geralmente chamado de um *lambda*— é uma maneira conveniente de definir um objeto de função anônima (um *fechamento*) à direita no local onde ele é invocado ou passado como um argumento para uma função. Normalmente, lambdas são usados para encapsular algumas linhas de código que são passadas para algoritmos ou métodos assíncronos. Este artigo define o que são as lambdas, as compara a outras técnicas de programação, descreve suas vantagens e fornece um exemplo básico.

## <a name="related-topics"></a>Tópicos relacionados

- [Expressões lambda vs. objetos de função](lambda-expression-syntax.md)
- [Trabalhando com expressões lambda](examples-of-lambda-expressions.md)
- [expressões lambda constexpr](lambda-expressions-constexpr.md)

## <a name="parts-of-a-lambda-expression"></a>Partes de uma expressão Lambda

O padrão ISO C++ mostra um lambda simple que é passado como o terceiro argumento para o `std::sort()` função:

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

Esta ilustração mostra as partes de uma lambda:

![Os elementos estruturais de uma expressão lambda](../cpp/media/lambdaexpsyntax.png "elementos estruturais de uma expressão lambda")

1. *cláusula Capture* (também conhecido como o *lambda-introducer* na especificação do C++.)

1. *lista de parâmetros* opcional. (Também conhecido como o *Declarador de lambda*)

1. *especificação mutável* opcional.

1. *especificação de exceção* opcional.

1. *trailing-return-type* opcional.

1. *corpo do lambda*.

### <a name="capture-clause"></a>Cláusula capture

Um lambda pode introduzir novas variáveis em seu corpo (no **c++14**) e ele também pode acessar, ou *capturar*, variáveis de escopo ao redor. Um lambda começa com a cláusula de captura (*lambda-introducer* na sintaxe padrão), que especifica quais variáveis são capturadas e se a captura é por valor ou por referência. Variáveis que têm o prefixo E comercial (`&`) são acessadas por referência e variáveis que não têm o prefixo são acessadas por valor.

Uma cláusula de captura vazia, `[ ]`, indica que o corpo da expressão lambda não acessa variáveis no escopo delimitador.

Você pode usar o modo de captura padrão (*padrão de captura* na sintaxe padrão) para indicar como capturar qualquer fora de variáveis que são referenciadas no lambda: `[&]` significa que todas as variáveis que você se referir a são capturadas pelo referência, e `[=]` significa que elas são capturadas por valor. Você pode usar um modo de captura padrão e, em seguida, especifique o modo oposto explicitamente para variáveis específicas. Por exemplo, se um corpo de lambda acessar a variável externa `total` por referência e a variável externa `factor` por valor, as seguintes cláusulas de captura serão equivalentes:

```cpp
[&total, factor]
[factor, &total]
[&, factor]
[factor, &]
[=, &total]
[&total, =]
```

Somente as variáveis que são mencionadas na lambda são capturadas quando um padrão de captura é usado.

Se uma cláusula de captura inclui um padrão de captura `&`, então nenhum `identifier` em um `capture` da que capturam a cláusula pode ter o formato `& identifier`. Da mesma forma, se a cláusula capture incluir um padrão de captura `=`, então nenhum `capture` de que capturam a cláusula pode ter o formato `= identifier`. Um identificador ou **isso** não pode aparecer mais de uma vez em uma cláusula de captura. O snippet de código a seguir ilustra alguns exemplos.

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

Uma captura seguida por reticências é uma expansão de pacote, conforme mostrado nesta [modelo variadic](../cpp/ellipses-and-variadic-templates.md) exemplo:

```cpp
template<class... Args>
void f(Args... args) {
    auto x = [args...] { return g(args...); };
    x();
}
```

Para usar expressões lambda no corpo de um método de classe, passe o **isso** ponteiro para a cláusula de captura para fornecer acesso aos membros de dados e métodos da classe delimitadora.

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O **isso** ponteiro pode ser capturado por valor especificando `*this` na cláusula de captura. Captura por valor significa que toda *fechamento*, que é o objeto de função anônima que encapulates a expressão lambda, que é copiada para cada site de chamada em que o lambda é invocado. Captura por valor é útil quando o lambda será executado em operações assíncronas ou paralelas, especialmente em determinadas arquiteturas de hardware, como NUMA.

Para obter um exemplo que mostra como usar expressões lambda com métodos de classe, consulte "exemplo: Usando uma expressão Lambda em um método"em [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).

Ao usar a cláusula de captura, nós recomendamos que você mantenha esses pontos em mente, especialmente ao usar lambdas com multithreading:

- As capturas de referência podem ser usadas para modificar variáveis externas, mas as capturas de valor não. (**mutável** permite que cópias sejam modificadas, mas não os originais.)

- As capturas de referência refletem atualizações para variáveis externas, mas as capturas de valor não.

- As capturas de referência introduzem uma dependência de tempo de vida, mas as capturas de valor não possuem dependências de tempo de vida. Isso é especialmente importante quando o lambda é executado de forma assíncrona. Se você capturar um local por referência em um lambda assíncrono, esse local será muito possivelmente não existe mais no momento em que o lambda é executado, resultando em uma violação de acesso em tempo de execução.

### <a name="generalized-capture-c-14"></a>Captura generalizada (C++ 14)

No C++ 14, você pode introduzir e inicializar novas variáveis na cláusula de captura, sem a necessidade de ter essas variáveis existem no escopo de fechamento da função lambda. A inicialização pode ser expresso como qualquer expressão arbitrária; o tipo da nova variável é deduzido do tipo produzido pela expressão. Um benefício desse recurso é que, no C++ 14, você pode capturar variáveis somente de movimentação (por exemplo, std:: unique_ptr) do escopo ao redor e usá-los em um lambda.

```cpp
pNums = make_unique<vector<int>>(nums);
//...
      auto a = [ptr = move(pNums)]()
        {
           // use ptr
        };
```

### <a name="parameter-list"></a>Lista de parâmetros

Além de capturar variáveis, uma lambda pode aceitar parâmetros de entrada. Uma lista de parâmetros (*Declarador de lambda* na sintaxe padrão) é opcional e na maioria dos aspectos é semelhante à lista de parâmetros para uma função.

```cpp
auto y = [] (int first, int second)
{
    return first + second;
};
```

Na **C++ 14**, se o tipo de parâmetro for genérico, você pode usar a palavra-chave auto como o especificador de tipo. Isso informa ao compilador para criar o operador de chamada de função como um modelo. Cada instância de auto, uma lista de parâmetros é equivalente a um parâmetro de tipo diferente.

```cpp
auto y = [] (auto first, auto second)
{
    return first + second;
};
```

Uma expressão lambda pode usar outra expressão lambda como seu argumento. Para obter mais informações, consulte "Expressões Lambda de ordem mais" no tópico [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).

Como uma lista de parâmetros é opcional, você pode omitir os parênteses vazios se você não passa argumentos para a expressão lambda e não contém seu lambda-declarator *especificação de exceção*,  *trailing-return-type*, ou **mutável**.

### <a name="mutable-specification"></a>Especificação mutável

Normalmente, o operador de chamada de função de uma lambda é constante por valor, mas usar o **mutável** palavra-chave neutraliza esse efeito. Membros de dados mutáveis não são produzidos. A especificação mutável permite que o corpo de uma expressão lambda modifique variáveis capturadas por valor. Alguns dos exemplos neste artigo mostram como usar **mutável**.

### <a name="exception-specification"></a>Especificação de exceção

É possível usar a especificação de exceção `noexcept` para indicar que a expressão lambda não lança nenhuma exceção. Assim como acontece com as funções comuns, o Microsoft C++ aviso do compilador gera [C4297](../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md) se uma expressão lambda declarar a `noexcept` especificação de exceção e o corpo lambda lançar uma exceção, conforme mostrado aqui:

```cpp
// throw_lambda_expression.cpp
// compile with: /W4 /EHsc
int main() // C4297 expected
{
   []() noexcept { throw 5; }();
}
```

Para obter mais informações, consulte [especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md).

### <a name="return-type"></a>Tipo de retorno

O tipo de retorno de uma expressão lambda é deduzido automaticamente. Você não precisa usar o [automática](../cpp/auto-cpp.md) palavra-chave, a menos que você especifique uma *trailing-return-type*. O *trailing-return-type* se parece com a parte return-type de um método ou função normal. No entanto, o tipo de retorno deve seguir a lista de parâmetros e você deve incluir a palavra-chave trailing-return-type `->` antes do tipo de retorno.

É possível omitir a parte return-type de uma expressão lambda se o corpo lambda contiver apenas uma instrução de retorno ou se a expressão lambda não retornar um valor. Se o corpo lambda contém uma instrução de retorno, o compilador deduzirá o tipo de retorno do tipo da expressão de retorno. Caso contrário, o compilador deduzirá o tipo de retorno para serem **void**. Considere os snippets de código do exemplo a seguir que ilustram esse princípio.

```cpp
auto x1 = [](int i){ return i; }; // OK: return type is int
auto x2 = []{ return{ 1, 2 }; };  // ERROR: return type is void, deducing
                                  // return type from braced-init-list is not valid
```

Uma expressão lambda pode gerar outra expressão lambda como seu valor de retorno. Para obter mais informações, consulte "Expressões Lambda de ordem mais" na [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).

### <a name="lambda-body"></a>Corpo lambda

O corpo lambda (*compound-statement* na sintaxe padrão) de uma lambda, expressão pode conter qualquer coisa que o corpo de um método comum ou uma função pode conter. O corpo de uma função comum e de uma expressão lambda pode acessar os seguintes tipos de variáveis:

- Capturado variáveis no escopo delimitador, conforme descrito anteriormente.

- Parâmetros

- Variáveis declaradas localmente

- Membros de dados, de classe quando declarados dentro de uma classe e **isso** é capturado

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

Como a variável `n` é capturada pelo valor, seu valor permanece `0` após a chamada para a expressão lambda. O **mutável** permite a especificação `n` seja modificada na lambda.

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

O exemplo de código a seguir usa a função do exemplo anterior e adiciona um exemplo de uma expressão lambda que usa o algoritmo da biblioteca padrão C++ `generate_n`. Essa expressão lambda atribui um elemento de um objeto `vector` à soma dos dois elementos anteriores. O **mutável** palavra-chave é usada para que o corpo da expressão lambda possa modificar suas cópias das variáveis externas `x` e `y`, que a expressão lambda captura por valor. Uma vez que a expressão lambda captura as variáveis originais `x` e `y` por valor, seus valores permanecem `1` depois que a lambda é executada.

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

## <a name="constexpr-lambda-expressions"></a>expressões lambda constexpr

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): Uma expressão lambda pode ser declarada como `constexpr` ou usado em uma expressão constante, quando a inicialização de cada membro de dados que ele captura ou apresenta é permitida dentro de uma expressão constante.

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

Um lambda é implicitamente `constexpr` se seu resultado satisfaz os requisitos de um `constexpr` função:

```cpp
    auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);
```

Se uma lambda é implicitamente ou explicitamente `constexpr`, a conversão em um ponteiro de função produz um `constexpr` função:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```

## <a name="microsoft-specific"></a>Específico da Microsoft

Lambdas não dá suporte as entidades common language runtime (CLR) gerenciado seguintes: **classe ref**, **ref struct**, **classe de valor**, ou **struct de valor** .

Se você estiver usando um modificador específico da Microsoft, como [declspec](../cpp/declspec.md), você pode inseri-lo em uma expressão lambda imediatamente após o `parameter-declaration-clause`— por exemplo:

```cpp
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };
```

Para determinar se um modificador tem suporte por lambdas, consulte o artigo sobre ela na [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md) seção da documentação.

Além do padrão de lambda funcionalidades C++11, o Visual Studio suporta lambdas sem monitoração de estado, que são conversíveis omni para ponteiros de função que usam convenções de chamada arbitrárias.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Objetos de função na Biblioteca Padrão C++](../standard-library/function-objects-in-the-stl.md)<br/>
[Chamada de função](../cpp/function-call-cpp.md)<br/>
[for_each](../standard-library/algorithm-functions.md#for_each)
