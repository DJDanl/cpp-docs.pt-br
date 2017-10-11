---
title: "Sintaxe da expressão lambda | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- lambda expressions [C++], syntax
ms.assetid: 5d6154a4-f34d-4a15-970d-7e7de45f54e9
caps.latest.revision: 26
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9daa1ce8d7b55f71113dcf7559394715bd93c604
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="lambda-expression-syntax"></a>Sintaxe da expressão lambda
Esse artigo demonstra a sintaxe e os elementos estruturais das expressões lambda. Para obter uma descrição de expressões lambda, consulte [expressões Lambda](../cpp/lambda-expressions-in-cpp.md).  
  
## <a name="function-objects-vs-lambdas"></a>Objetos de função vs. Lambdas  
 Quando você escreve o código, você provavelmente usar ponteiros de função e objetos de função para solucionar problemas e executar cálculos, especialmente quando você usar [algoritmos da biblioteca padrão C++](../cpp/algorithms-modern-cpp.md). Ponteiros de função e objetos de função tem vantagens e desvantagens — por exemplo, ponteiros de função tem sobrecarga mínima de sintática mas não manter o estado em um escopo e objetos de função podem manter o estado mas exigem a sobrecarga sintática de um definição de classe.  
  
 Um lambda combina os benefícios dos ponteiros de função com os objetos de função e evita suas desvantagens. Como objetos de função, uma expressão lambda é flexível e pode manter o estado, mas ao contrário de um objeto de função, sua sintaxe compact não requer uma definição de classe explícita. Ao usar lambdas, você pode escrever código que seja menos inconveniente e menos sujeito a erros do que o código para um objeto de função equivalente.  
  
 Os exemplos a seguir comparam o uso de uma lambda ao uso de um objeto de função. O primeiro exemplo usa uma lambda para imprimir no console se cada elemento em um objeto `vector` é para ou ímpar. O segundo exemplo usa um objeto de função para realizar a mesma tarefa.  
  
## <a name="example-1-using-a-lambda"></a>Exemplo 1: Usando uma lambda  
 Este exemplo passa uma expressão lambda para o `for_each` função. O lambda imprime um resultado que indica se cada elemento em uma `vector` objeto é par ou ímpar.  
  
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
   // Create a vector object that contains 10 elements.  
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
  
### <a name="output"></a>Saída  
  
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
 No exemplo, o terceiro argumento para a função `for_each` é um lambda. A parte `[&evenCount]` especifica a cláusula capture da expressão, `(int n)` especifica a lista de parâmetros e a parte restante especifica o corpo da expressão.  
  
## <a name="example-2-using-a-function-object"></a>Exemplo 2: Usando um objeto de função  
 Às vezes, uma lambda seria muito pesada para se estender muito além do exemplo anterior. O próximo exemplo usa um objeto de função, em vez de uma lambada, juntamente com a função `for_each`, para gerar os mesmos resultados do Exemplo 1. Os dois exemplos armazenam a contagem de números pares em um objeto `vector`. Para manter o estado da operação, a classe `FunctorClass` armazena a variável `m_evenCount` por referência como uma variável de membro. Para executar a operação, `FunctorClass` implementa o operador da chamada de função, `operator()`. O compilador do Visual C++ gerencia o código que é comparável em tamanho e desempenho ao código da lambda no Exemplo 1. Para um problema básico como o deste artigo, o design da lambda mais simples é provavelmente melhor do que o design do objeto de função. No entanto, se achar que a funcionalidade pode exigir expansão significativa no futuro, use um design de objeto de função, assim, a manutenção do código será mais fácil.  
  
 Para obter mais informações sobre o `operator()`, consulte [chamada de função](../cpp/function-call-cpp.md). Para obter mais informações sobre o `for_each` funcionam, consulte [for_each](../standard-library/algorithm-functions.md#for_each).  
  
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
    // Create a vector object that contains 10 elements.  
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
  
## <a name="output"></a>Saída  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../cpp/lambda-expressions-in-cpp.md)   
 [Exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md)   
 [Gerar](../standard-library/algorithm-functions.md#generate)   
 [generate_n](../standard-library/algorithm-functions.md#generate_n)   
 [for_each](../standard-library/algorithm-functions.md#for_each)   
 [Especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md)   
 [Compilador C4297 de aviso (nível 1)](../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md)   
 [Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)
