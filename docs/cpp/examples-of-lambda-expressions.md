---
title: Exemplos de expressões lambda
ms.date: 11/04/2016
helpviewer_keywords:
- lambda expressions [C++], examples
ms.assetid: 52506b15-0771-4190-a966-2f302049ca86
ms.openlocfilehash: 6854c5710d8a27093078c0f2013d691ac22c5870
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50663939"
---
# <a name="examples-of-lambda-expressions"></a>Exemplos de expressões lambda

Este artigo mostra como usar expressões lambda em seus programas. Para obter uma visão geral das expressões lambda, consulte [expressões Lambda](../cpp/lambda-expressions-in-cpp.md). Para obter mais informações sobre a estrutura de uma expressão lambda, consulte [sintaxe de expressão Lambda](../cpp/lambda-expression-syntax.md).

##  <a name="declaringLambdaExpressions"></a> Declarando expressões Lambda

### <a name="example-1"></a>Exemplo 1

Como uma expressão lambda é digitada, você pode atribuí-lo para um **automática** variável ou uma [função](../standard-library/function-class.md) do objeto, como mostrado aqui:

### <a name="code"></a>Código

```cpp
// declaring_lambda_expressions1.cpp
// compile with: /EHsc /W4
#include <functional>
#include <iostream>

int main()
{

    using namespace std;

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;
}
```

### <a name="output"></a>Saída

```Output
5
7
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [automática](../cpp/auto-cpp.md), [classe function](../standard-library/function-class.md), e [chamada de função](../cpp/function-call-cpp.md).

Embora as expressões lambda geralmente são declaradas no corpo de uma função, você pode declará-los em qualquer lugar que você pode inicializar uma variável.

### <a name="example-2"></a>Exemplo 2

O compilador do Visual C++ associa uma expressão lambda às suas variáveis capturadas quando a expressão é declarada, e não quando a expressão é chamada. O exemplo a seguir mostra uma expressão lambda que captura a variável local `i` por valor e a variável local `j` por referência. Como a expressão lambda é capturada `i` por valor, a reatribuição posterior de `i` no programa não afetará o resultado da expressão. No entanto, como a expressão lambda captura `j` por referência, a reatribuição de `j` afetará o resultado da expressão.

### <a name="code"></a>Código

```cpp
// declaring_lambda_expressions2.cpp
// compile with: /EHsc /W4
#include <functional>
#include <iostream>

int main()
{
   using namespace std;

   int i = 3;
   int j = 5;

   // The following lambda expression captures i by value and
   // j by reference.
   function<int (void)> f = [i, &j] { return i + j; };

   // Change the values of i and j.
   i = 22;
   j = 44;

   // Call f and print its result.
   cout << f() << endl;
}
```

### <a name="output"></a>Saída

```Output
47
```

[[Neste artigo](#top)]

##  <a name="callingLambdaExpressions"></a> Chamando expressões Lambda

Você poderá chamar uma expressão lambda imediatamente, conforme mostrado no próximo snippet de código. O segundo trecho mostra como passar um lambda como um argumento para algoritmos da biblioteca padrão C++, como `find_if`.

### <a name="example-1"></a>Exemplo 1

Este exemplo declara uma expressão lambda que retorna a soma de dois inteiros e chama a expressão imediatamente com os argumentos `5` e `4`:

### <a name="code"></a>Código

```cpp
// calling_lambda_expressions1.cpp
// compile with: /EHsc
#include <iostream>

int main()
{
   using namespace std;
   int n = [] (int x, int y) { return x + y; }(5, 4);
   cout << n << endl;
}
```

### <a name="output"></a>Saída

```Output
9
```

### <a name="example-2"></a>Exemplo 2

Este exemplo passa uma expressão lambda como argumento para a função `find_if`. Retorna a expressão lambda **verdadeira** se o parâmetro for um número par.

### <a name="code"></a>Código

```cpp
// calling_lambda_expressions2.cpp
// compile with: /EHsc /W4
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;

    // Create a list of integers with a few initial elements.
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    // Use the find_if function and a lambda expression to find the
    // first even number in the list.
    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(),[](int n) { return (n % 2) == 0; });

    // Print the result.
    if (result != numbers.end()) {
        cout << "The first even number in the list is " << *result << "." << endl;
    } else {
        cout << "The list contains no even numbers." << endl;
    }
}
```

### <a name="output"></a>Saída

```Output
The first even number in the list is 42.
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o `find_if` , consulte [find_if](../standard-library/algorithm-functions.md#find_if). Para obter mais informações sobre as funções de biblioteca padrão C++ que executam algoritmos comuns, consulte [ \<algoritmo >](../standard-library/algorithm.md).

[[Neste artigo](#top)]

##  <a name="nestingLambdaExpressions"></a> Aninhando expressões Lambda

### <a name="example"></a>Exemplo

É possível aninhar uma expressão lambda dentro de outra, como mostrado neste exemplo. A expressão lambda interna multiplica seu argumento por 2 e retorna o resultado. A expressão lambda externa chama a expressão lambda interna com seu argumento e adiciona 3 ao resultado.

### <a name="code"></a>Código

```cpp
// nesting_lambda_expressions.cpp
// compile with: /EHsc /W4
#include <iostream>

int main()
{
    using namespace std;

    // The following lambda expression contains a nested lambda
    // expression.
    int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);

    // Print the result.
    cout << timestwoplusthree << endl;
}
```

### <a name="output"></a>Saída

```Output
13
```

### <a name="remarks"></a>Comentários

Neste exemplo, `[](int y) { return y * 2; }` representa a expressão lambda aninhada.

[[Neste artigo](#top)]

##  <a name="higherOrderLambdaExpressions"></a> Funções Lambda de ordem superior

### <a name="example"></a>Exemplo

O conceito de dar suporte a várias linguagens de programação um *função de ordem superior.* Uma função de ordem superior é uma expressão lambda que usa outra expressão lambda como seu argumento ou retorna uma expressão lambda. Você pode usar o [função](../standard-library/function-class.md) classe para habilitar uma expressão lambda C++ se comporte como uma função de ordem superior. O exemplo a seguir mostra uma expressão lambda que retorna um objeto `function` e uma expressão lambda que usa um objeto `function` como seu argumento.

### <a name="code"></a>Código

```cpp
// higher_order_lambda_expression.cpp
// compile with: /EHsc /W4
#include <iostream>
#include <functional>

int main()
{
    using namespace std;

    // The following code declares a lambda expression that returns
    // another lambda expression that adds two numbers.
    // The returned lambda expression captures parameter x by value.
    auto addtwointegers = [](int x) -> function<int(int)> {
        return [=](int y) { return x + y; };
    };

    // The following code declares a lambda expression that takes another
    // lambda expression as its argument.
    // The lambda expression applies the argument z to the function f
    // and multiplies by 2.
    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    // Call the lambda expression that is bound to higherorder.
    auto answer = higherorder(addtwointegers(7), 8);

    // Print the result, which is (7+8)*2.
    cout << answer << endl;
}
```

### <a name="output"></a>Saída

```Output
30
```

[[Neste artigo](#top)]

##  <a name="methodLambdaExpressions"></a> Usando uma expressão Lambda em uma função

### <a name="example"></a>Exemplo

Você pode usar expressões lambda no corpo de uma função. A expressão lambda pode acessar qualquer membro de dados ou função que a função pode acessar. Você pode capturar explicita ou implicitamente a **isso** ponteiro para fornecer acesso a membros de funções e os dados da classe delimitadora.
**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std:c++17 + + 17](../build/reference/std-specify-language-standard-version.md)): capturar **isso** por valor (`[*this]`) quando o lambda será usado em operações assíncronas ou paralelas em que o código pode ser executado após o objeto original sai do escopo.

Você pode usar o **isso** ponteiro explicitamente em uma função, conforme mostrado aqui:

```cpp
// capture "this" by reference
void ApplyScale(const vector<int>& v) const
{
   for_each(v.begin(), v.end(),
      [this](int n) { cout << n * _scale << endl; });
}

// capture "this" by value (Visual Studio 2017 version 15.3 and later)
void ApplyScale2(const vector<int>& v) const
{
   for_each(v.begin(), v.end(),
      [*this](int n) { cout << n * _scale << endl; });
}
```

Você também pode capturar o **isso** ponteiro implicitamente:

```cpp
void ApplyScale(const vector<int>& v) const
{
   for_each(v.begin(), v.end(),
      [=](int n) { cout << n * _scale << endl; });
}
```

O exemplo a seguir mostra a classe `Scale`, que encapsula um valor da escala.

```cpp
// function_lambda_expression.cpp
// compile with: /EHsc /W4
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Scale
{
public:
    // The constructor.
    explicit Scale(int scale) : _scale(scale) {}

    // Prints the product of each element in a vector object
    // and the scale value to the console.
    void ApplyScale(const vector<int>& v) const
    {
        for_each(v.begin(), v.end(), [=](int n) { cout << n * _scale << endl; });
    }

private:
    int _scale;
};

int main()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

    // Create a Scale object that scales elements by 3 and apply
    // it to the vector object. Does not modify the vector.
    Scale s(3);
    s.ApplyScale(values);
}
```

### <a name="output"></a>Saída

```Output
3
6
9
12
```

### <a name="remarks"></a>Comentários

O `ApplyScale` função usa uma expressão lambda para imprimir o produto do valor da escala e cada elemento em um `vector` objeto. A expressão lambda captura implicitamente **isso** para que ele possa acessar o `_scale` membro.

[[Neste artigo](#top)]

##  <a name="templateLambdaExpressions"></a> Usando expressões Lambda com modelos

### <a name="example"></a>Exemplo

Como as expressões lambda são digitadas, é possível usá-las com modelos C++. O exemplo a seguir mostra as funções `negate_all` e `print_all`. O `negate_all` função aplica o operador unário **operador -** a cada elemento no `vector` objeto. A função `print_all` imprime cada elemento no objeto `vector` para o console.

### <a name="code"></a>Código

```cpp
// template_lambda_expression.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Negates each element in the vector object. Assumes signed data type.
template <typename T>
void negate_all(vector<T>& v)
{
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}

// Prints to the console each element in the vector object.
template <typename T>
void print_all(const vector<T>& v)
{
    for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });
}

int main()
{
    // Create a vector of signed integers with a few elements.
    vector<int> v;
    v.push_back(34);
    v.push_back(-43);
    v.push_back(56);

    print_all(v);
    negate_all(v);
    cout << "After negate_all():" << endl;
    print_all(v);
}
```

### <a name="output"></a>Saída

```Output
34
-43
56
After negate_all():
-34
43
-56
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre modelos de C++, consulte [modelos](../cpp/templates-cpp.md).

[[Neste artigo](#top)]

##  <a name="ehLambdaExpressions"></a> Tratamento de exceções

### <a name="example"></a>Exemplo

O corpo de uma expressão lambda segue as regras para a manipulação de exceção estruturada (SEH) e o tratamento de exceções C++. Você pode manipular uma exceção gerada no corpo de uma expressão lambda ou adiar o tratamento de exceções para o escopo delimitador. O exemplo a seguir usa o **for_each** função e uma expressão lambda para preencher um `vector` objeto com os valores de outro. Ele usa um **tente**/**catch** bloco para lidar com acesso inválido ao primeiro vetor.

### <a name="code"></a>Código

```cpp
// eh_lambda_expression.cpp
// compile with: /EHsc /W4
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // Create a vector that contains 3 elements.
    vector<int> elements(3);

    // Create another vector that contains index values.
    vector<int> indices(3);
    indices[0] = 0;
    indices[1] = -1; // This is not a valid subscript. It will trigger an exception.
    indices[2] = 2;

    // Use the values from the vector of index values to
    // fill the elements vector. This example uses a
    // try/catch block to handle invalid access to the
    // elements vector.
    try
    {
        for_each(indices.begin(), indices.end(), [&](int index) {
            elements.at(index) = index;
        });
    }
    catch (const out_of_range& e)
    {
        cerr << "Caught '" << e.what() << "'." << endl;
    };
}
```

### <a name="output"></a>Saída

```Output
Caught 'invalid vector<T> subscript'.
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o tratamento de exceção, consulte [tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md).

[[Neste artigo](#top)]

##  <a name="managedLambdaExpressions"></a> Usando expressões Lambda com tipos gerenciados (C + + / CLI)

### <a name="example"></a>Exemplo

A cláusula de captura de uma expressão lambda não pode conter uma variável que tenha um tipo gerenciado. No entanto, você pode passar um argumento que tenha um tipo gerenciado para uma lista de parâmetros de uma expressão lambda. O exemplo a seguir contém uma expressão lambda que captura a variável local não gerenciada `ch` por valor e usa um objeto <xref:System.String?displayProperty=fullName> como seu parâmetro.

### <a name="code"></a>Código

```cpp
// managed_lambda_expression.cpp
// compile with: /clr
using namespace System;

int main()
{
    char ch = '!'; // a local unmanaged variable

    // The following lambda expression captures local variables
    // by value and takes a managed String object as its parameter.
    [=](String ^s) {
        Console::WriteLine(s + Convert::ToChar(ch));
    }("Hello");
}
```

### <a name="output"></a>Saída

```Output
Hello!
```

### <a name="remarks"></a>Comentários

Você também pode usar expressões lambda com a biblioteca STL/CLR. Para obter mais informações, consulte [referência da biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md).

> [!IMPORTANT]
>  Lambdas não têm suporte nessas entidades de runtime (CLR) gerenciado do common language: **classe ref**, **ref struct**, **classe de valor**, e **deestruturadevalor**.

[[Neste artigo](#top)]

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../cpp/lambda-expressions-in-cpp.md)<br/>
[Sintaxe da expressão lambda](../cpp/lambda-expression-syntax.md)<br/>
[auto](../cpp/auto-cpp.md)<br/>
[Classe function](../standard-library/function-class.md)<br/>
[find_if](../standard-library/algorithm-functions.md#find_if)<br/>
[\<algorithm>](../standard-library/algorithm.md)<br/>
[Chamada de função](../cpp/function-call-cpp.md)<br/>
[Modelos](../cpp/templates-cpp.md)<br/>
[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)<br/>
[Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)