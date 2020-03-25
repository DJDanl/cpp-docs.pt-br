---
title: Sintaxe da expressão lambda
ms.date: 05/07/2019
helpviewer_keywords:
- lambda expressions [C++], syntax
ms.assetid: 5d6154a4-f34d-4a15-970d-7e7de45f54e9
ms.openlocfilehash: 9ac2fdea1a8fc8dcf2b03059455c3141daf86aa8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179647"
---
# <a name="lambda-expression-syntax"></a>Sintaxe da expressão lambda

Esse artigo demonstra a sintaxe e os elementos estruturais das expressões lambda. Para obter uma descrição das expressões lambda, consulte [expressões lambda](../cpp/lambda-expressions-in-cpp.md).

## <a name="function-objects-vs-lambdas"></a>Objetos de função vs. lambdas

Quando você escreve o código, provavelmente usa ponteiros de função e objetos de função para resolver problemas e executar cálculos, especialmente quando você usa [ C++ algoritmos de biblioteca padrão](../cpp/algorithms-modern-cpp.md). Os ponteiros de função e os objetos de função têm vantagens e desvantagens — por exemplo, os ponteiros de função têm sobrecarga sintática mínima, mas não retêm o estado em um escopo, e os objetos de função podem manter o estado, mas exigem a sobrecarga sintática de um definição de classe.

Um lambda combina os benefícios dos ponteiros de função com os objetos de função e evita suas desvantagens. Como os objetos de função, um lambda é flexível e pode manter o estado, mas ao contrário de um objeto de função, sua sintaxe de compactação não requer uma definição de classe explícita. Ao usar lambdas, você pode escrever código que seja menos inconveniente e menos sujeito a erros do que o código para um objeto de função equivalente.

Os exemplos a seguir comparam o uso de uma lambda ao uso de um objeto de função. O primeiro exemplo usa uma lambda para imprimir no console se cada elemento em um objeto `vector` é para ou ímpar. O segundo exemplo usa um objeto de função para realizar a mesma tarefa.

## <a name="example-1-using-a-lambda"></a>Exemplo 1: Usando uma lambda

Este exemplo passa um lambda para a função **for_each** . O lambda imprime um resultado que indica se cada elemento em um objeto `vector` é par ou ímpar.

### <a name="code"></a>Código

```cpp
// even_lambda.cpp
// compile with: cl /EHsc /nologo /W4 /MTd
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // Create a vector object that contains 9 elements.
   vector<int> v;
   for (int i = 1; i < 10; ++i) {
      v.push_back(i);
   }

   // Count the number of even numbers in the vector by
   // using the for_each function and a lambda.
   int evenCount = 0;
   for_each(v.begin(), v.end(), [&evenCount] (int n) {
      cout << n;
      if (n % 2 == 0) {
         cout << " is even " << endl;
         ++evenCount;
      } else {
         cout << " is odd " << endl;
      }
   });

   // Print the count of even numbers to the console.
   cout << "There are " << evenCount
        << " even numbers in the vector." << endl;
}
```

```Output
1 is odd
2 is even
3 is odd
4 is even
5 is odd
6 is even
7 is odd
8 is even
9 is odd
There are 4 even numbers in the vector.
```

### <a name="comments"></a>Comentários

No exemplo, o terceiro argumento para a função **for_each** é um lambda. A parte `[&evenCount]` especifica a cláusula capture da expressão, `(int n)` especifica a lista de parâmetros e a parte restante especifica o corpo da expressão.

## <a name="example-2-using-a-function-object"></a>Exemplo 2: Usando um objeto de função

Às vezes, uma lambda seria muito pesada para se estender muito além do exemplo anterior. O exemplo a seguir usa um objeto de função em vez de um lambda, junto com a função **for_each** , para produzir os mesmos resultados que o exemplo 1. Os dois exemplos armazenam a contagem de números pares em um objeto `vector`. Para manter o estado da operação, a classe `FunctorClass` armazena a variável `m_evenCount` por referência como uma variável de membro. Para executar a operação, `FunctorClass` implementa o operador de chamada de função, **operador ()** . O compilador C++ da Microsoft gera código que é comparável em tamanho e desempenho para o código lambda no exemplo 1. Para um problema básico como o deste artigo, o design da lambda mais simples é provavelmente melhor do que o design do objeto de função. No entanto, se achar que a funcionalidade pode exigir expansão significativa no futuro, use um design de objeto de função, assim, a manutenção do código será mais fácil.

Para obter mais informações sobre o **operador ()** , consulte [chamada de função](../cpp/function-call-cpp.md). Para obter mais informações sobre a função **for_each** , consulte [for_each](../standard-library/algorithm-functions.md#for_each).

### <a name="code"></a>Código

```cpp
// even_functor.cpp
// compile with: /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctorClass
{
public:
    // The required constructor for this example.
    explicit FunctorClass(int& evenCount)
        : m_evenCount(evenCount) { }

    // The function-call operator prints whether the number is
    // even or odd. If the number is even, this method updates
    // the counter.
    void operator()(int n) const {
        cout << n;

        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++m_evenCount;
        } else {
            cout << " is odd " << endl;
        }
    }

private:
    // Default assignment operator to silence warning C4512.
    FunctorClass& operator=(const FunctorClass&);

    int& m_evenCount; // the number of even variables in the vector.
};

int main()
{
    // Create a vector object that contains 9 elements.
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

    // Count the number of even numbers in the vector by
    // using the for_each function and a function object.
    int evenCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(evenCount));

    // Print the count of even numbers to the console.
    cout << "There are " << evenCount
        << " even numbers in the vector." << endl;
}
```

```Output
1 is odd
2 is even
3 is odd
4 is even
5 is odd
6 is even
7 is odd
8 is even
9 is odd
There are 4 even numbers in the vector.
```

## <a name="see-also"></a>Confira também

[Expressões Lambda](../cpp/lambda-expressions-in-cpp.md)<br/>
[Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md)<br/>
[generate](../standard-library/algorithm-functions.md#generate)<br/>
[generate_n](../standard-library/algorithm-functions.md#generate_n)<br/>
[for_each](../standard-library/algorithm-functions.md#for_each)<br/>
[Especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md)<br/>
[Aviso do compilador (nível 1) C4297](../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md)<br/>
[Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)
