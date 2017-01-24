---
title: "Sintaxe da express&#227;o lambda | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "VCF1 Lambda_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "expressões lambda [C++], sintaxe"
ms.assetid: 5d6154a4-f34d-4a15-970d-7e7de45f54e9
caps.latest.revision: 26
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sintaxe da express&#227;o lambda
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esse artigo demonstra a sintaxe e os elementos estruturais das expressões lambda.  Para obter uma descrição das expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
## Objetos de função vs.Lambdas  
 Ao escrever um código, você provavelmente usa ponteiros de função e objetos de função para resolver problemas e realizar cálculos, especialmente quando você usa [algoritmos STL](../cpp/algorithms-modern-cpp.md).  Ponteiros de função e objetos de função têm vantagens e desvantagens — por exemplo, ponteiros de função têm sobrecarga sintática mínima, mas não retêm estado dentro de um escopo e objetos de função podem manter o estado, mas exigem sobrecarga sintática de uma definição de classe.  
  
 Um lambda combina os benefícios dos ponteiros de função com os objetos de função e evita suas desvantagens.  Como um objeto de função, uma lambda é flexível e pode manter o estado, mas ao contrário de um objeto de função, sua sintaxe compacta não exige uma definição de classe explícita.  Ao usar lambdas, você pode escrever código que seja menos inconveniente e menos sujeito a erros do que o código para um objeto de função equivalente.  
  
 Os exemplos a seguir comparam o uso de uma lambda ao uso de um objeto de função.  O primeiro exemplo usa uma lambda para imprimir no console se cada elemento em um objeto `vector` é para ou ímpar.  O segundo exemplo usa um objeto de função para realizar a mesma tarefa.  
  
## Exemplo 1: Usando uma lambda  
 Este exemplo passa um lambda de `for_each` função.  Lambda imprime um resultado que indica se cada elemento em uma `vector` objeto é par ou ímpar.  
  
### Código  
  
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
  
### Saída  
  **1 é ímpar**  
**2 é par**  
**3 é ímpar**  
**4 é par**  
**5 é ímpar**  
**6 é par**  
**7 é ímpar**  
**8 é par**  
**9 é ímpar**  
**Existem 4 números pares no vetor.**   
### Comentários  
 No exemplo, o terceiro argumento para a função `for_each` é um lambda.  A parte `[&evenCount]` especifica a cláusula capture da expressão, `(int n)` especifica a lista de parâmetros e a parte restante especifica o corpo da expressão.  
  
## Exemplo 2: Usando um objeto de função  
 Às vezes, uma lambda seria muito pesada para se estender muito além do exemplo anterior.  O próximo exemplo usa um objeto de função, em vez de uma lambada, juntamente com a função `for_each`, para gerar os mesmos resultados do Exemplo 1.  Os dois exemplos armazenam a contagem de números pares em um objeto `vector`.  Para manter o estado da operação, a classe `FunctorClass` armazena a variável `m_evenCount` por referência como uma variável de membro.  Para executar a operação, `FunctorClass` implementa o operador da chamada de função, `operator()`.  O compilador do Visual C\+\+ gerencia o código que é comparável em tamanho e desempenho ao código da lambda no Exemplo 1.  Para um problema básico como o deste artigo, o design da lambda mais simples é provavelmente melhor do que o design do objeto de função.  No entanto, se achar que a funcionalidade pode exigir expansão significativa no futuro, use um design de objeto de função, assim, a manutenção do código será mais fácil.  
  
 Para obter mais informações sobre o `operator()`, consulte [Chamada de função](../Topic/Function%20Call%20\(C++\).md).  Para obter mais informações sobre o `for_each` funcionam, consulte [for\_each](../Topic/for_each.md).  
  
### Código  
  
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
  
## Saída  
  **1 é ímpar**  
**2 é par**  
**3 é ímpar**  
**4 é par**  
**5 é ímpar**  
**6 é par**  
**7 é ímpar**  
**8 é par**  
**9 é ímpar**  
**Existem 4 números pares no vetor.**   
## Consulte também  
 [Expressões lambda](../cpp/lambda-expressions-in-cpp.md)   
 [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md)   
 [generate](../Topic/generate.md)   
 [generate\_n](../Topic/generate_n.md)   
 [for\_each](../Topic/for_each.md)   
 [Especificações de exceção \(lançar\)](../cpp/exception-specifications-throw-cpp.md)   
 [Aviso do compilador \(nível 1\) C4297](../Topic/Compiler%20Warning%20\(level%201\)%20C4297.md)   
 [Modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md)