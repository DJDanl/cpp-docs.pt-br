---
title: "Instru&#231;&#227;o break (C++) | Microsoft Docs"
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
  - "break_cpp"
  - "break"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave break [C++]"
ms.assetid: 63739928-8985-4b05-93ce-016322e6da3d
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o break (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `break` encerra a execução do loop delimitador mais próximo ou da instrução condicional na qual ele aparece.  O controle passa para a instrução que segue o encerramento da instrução, se houver.  
  
## Sintaxe  
  
```  
break;  
```  
  
## Comentários  
 A instrução `break` é usada com a instrução condicional [switch](../cpp/switch-statement-cpp.md) e com as instruções de loop [do](../cpp/do-while-statement-cpp.md), [for](../cpp/for-statement-cpp.md) e [while](../cpp/while-statement-cpp.md).  
  
 Em uma instrução `switch`, a instrução `break` faz com que o programa execute a próxima instrução fora da instrução `switch`.  Sem uma instrução `break`, cada instrução do rótulo `case` correspondente até o fim da instrução `switch`, incluindo a cláusula `default`, é executada.  
  
 Em loops, a instrução `break` encerra a execução da instrução delimitadora `do`, `for` ou `while` mais próxima.  O controle passa para a instrução que segue a instrução encerrada, se houver.  
  
 Em instruções aninhadas, a instrução `break` encerra apenas a instrução `do`, `for`, `switch` ou `while` que a delimita imediatamente.  Você pode usar uma instrução `return` ou `goto` para transferir o controle de estruturas mais profundamente aninhadas.  
  
## Exemplo  
 O código a seguir mostra como usar a instrução `break` em um loop `for`.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    // An example of a standard for loop  
    for (int i = 1; i < 10; i++)  
    {  
        cout << i << '\n';  
        if (i == 4)  
            break;  
    }  
  
    // An example of a range-based for loop  
int nums []{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
  
    for (int i : nums) {  
        if (i == 4) {  
            break;  
        }  
        cout << i << '\n';  
    }  
}  
```  
  
  **Em cada caso:**   
**1**  
**2**  
**3** O código a seguir mostra como usar `break` em um loop `while` e em um loop `do`.  
  
```cpp  
  
#include <iostream>  
using namespace std;  
  
int main() {  
    int i = 0;  
  
    while (i < 10) {  
        if (i == 4) {  
            break;  
        }  
        cout << i << '\n';  
        i++;  
    }  
  
    i = 0;  
    do {  
        if (i == 4) {  
            break;  
        }  
        cout << i << '\n';  
        i++;  
    } while (i < 10);  
}  
```  
  
  **Em cada caso:**  
**0**  
**1**  
**2**  
**3** O código a seguir mostra como usar `break` em uma instrução switch.  Você deve usar `break` em todos os casos se desejar tratar cada caso separadamente; se `break` não for usada, a execução do código falhará no próximo caso.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
enum Suit{ Diamonds, Hearts, Clubs, Spades };  
  
int main() {  
  
    Suit hand;  
    . . .  
    // Assume that some enum value is set for hand  
    // In this example, each case is handled separately  
    switch (hand)  
    {  
    case Diamonds:  
        cout << "got Diamonds \n";  
        break;  
    case Hearts:  
        cout << "got Hearts \n";  
        break;  
    case Clubs:  
        cout << "got Clubs \n";  
        break;  
    case Spades:  
        cout << "got Spades \n";  
        break;  
    default:   
          cout << "didn't get card \n";  
    }  
    // In this example, Diamonds and Hearts are handled one way, and  
    // Clubs, Spades, and the default value are handled another way  
    switch (hand)  
    {  
    case Diamonds:  
    case Hearts:  
        cout << "got a red card \n";  
        break;  
    case Clubs:  
    case Spades:   
    default:  
        cout << "didn't get a red card \n";  
    }  
}  
```  
  
## Consulte também  
 [Instruções de salto](../cpp/jump-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução continue](../cpp/continue-statement-cpp.md)