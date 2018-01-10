---
title: "Com base em intervalo de instrução (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
ms.assetid: 5750ba1d-ba48-4236-a923-e32de8345c2d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 43ded324227878b44f997e6539e060145ad0fb66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="range-based-for-statement-c"></a>Instrução for com base em intervalo (C++)
Executa `statement` repetidamente e em sequência para cada elemento em `expression`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      for ( for-range-declaration : expression )  
   statement   
```  
  
## <a name="remarks"></a>Comentários  
 Use o intervalo com base em `for` instrução para construir loops que devem ser executado por meio de um "intervalo", que é definido como qualquer coisa que você pode percorrer — por exemplo, `std::vector`, ou qualquer outra sequência de biblioteca padrão C++ cujo intervalo é definido por um `begin()` e `end()`. O nome que é declarado na parte `for-range-declaration` é local para a instrução `for` e não pode ser declarado novamente em `expression` ou em `statement`. Observe que o [automática](../cpp/auto-cpp.md) palavra-chave é preferido a `for-range-declaration` parte da instrução. 

 **Novo no Visual Studio de 2017:** baseada em intervalo de loops não exigem que () e end retornam objetos do mesmo tipo. Isso permite que end() retorne um objeto sentinela como usado por intervalos, conforme definido na proposta Ranges-V3. Para obter mais informações, consulte [Generalizing the Range-Based For Loop (Generalizando o loop “for” baseado em intervalo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html) e [range-v3 library on GitHub (Biblioteca range-v3 no GitHub)](https://github.com/ericniebler/range-v3).
  
 Este código mostra como usar com base em intervalo `for` loops para iterar por meio de uma matriz e um vetor de:  
  
```cpp  
// range-based-for.cpp  
// compile by using: cl /EHsc /nologo /W4  
#include <iostream>  
#include <vector>  
using namespace std;  
  
int main()   
{  
    // Basic 10-element integer array.  
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  
  
    // Range-based for loop to iterate through the array.  
    for( int y : x ) { // Access by value using a copy declared as a specific type.   
                       // Not preferred.  
        cout << y << " ";  
    }  
    cout << endl;  
  
    // The auto keyword causes type inference to be used. Preferred.  
  
    for( auto y : x ) { // Copy of 'x', almost always undesirable  
        cout << y << " ";  
    }  
    cout << endl;  
  
    for( auto &y : x ) { // Type inference by reference.  
        // Observes and/or modifies in-place. Preferred when modify is needed.  
        cout << y << " ";  
    }  
    cout << endl;  
  
    for( const auto &y : x ) { // Type inference by const reference.  
        // Observes in-place. Preferred when no modify is needed.  
        cout << y << " ";  
    }  
    cout << endl;  
    cout << "end of integer array test" << endl;  
    cout << endl;  
  
    // Create a vector object that contains 10 elements.  
    vector<double> v;  
    for (int i = 0; i < 10; ++i) {  
        v.push_back(i + 0.14159);  
    }  
  
    // Range-based for loop to iterate through the vector, observing in-place.  
    for( const auto &j : v ) {  
        cout << j << " ";  
    }  
    cout << endl;  
    cout << "end of vector test" << endl;  
}  
  
```  
  
 Este é o resultado:  
  
 `1 2 3 4 5 6 7 8 9 10`  
  
 `1 2 3 4 5 6 7 8 9 10`  
  
 `1 2 3 4 5 6 7 8 9 10`  
  
 `1 2 3 4 5 6 7 8 9 10`  
  
 `end of integer array test`  
  
 `0.14159 1.14159 2.14159 3.14159 4.14159 5.14159 6.14159 7.14159 8.14159 9.14159`  
  
 `end of vector test`  
  
 Um intervalo com base em `for` loop será encerrado quando uma destas opções na `statement` é executado: um [quebra](../cpp/break-statement-cpp.md), [retornar](../cpp/return-statement-cpp.md), ou [goto](../cpp/goto-statement-cpp.md) para uma instrução rotulada fora do com base em intervalo **para** loop. Um [continuar](../cpp/continue-statement-cpp.md) instrução em um intervalo com base em `for` loop finaliza somente a iteração atual.  
  
 Lembre-se destes fatos sobre a instrução `for` baseada em intervalo:  
  
-   Reconhece matrizes automaticamente.  
  
-   Reconhece os contêineres que têm `.begin()` e `.end()`.  
  
-   Usa a pesquisa dependente de argumentos `begin()` e `end()` para qualquer outra coisa.  
  
## <a name="see-also"></a>Consulte também  
 [Automático](../cpp/auto-cpp.md)   
 [Instruções de Iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução while (C++)](../cpp/while-statement-cpp.md)   
 [Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)   
 [Instrução for (C++)](../cpp/for-statement-cpp.md)