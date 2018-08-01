---
title: Instrução break (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- break_cpp
dev_langs:
- C++
helpviewer_keywords:
- break keyword [C++]
ms.assetid: 63739928-8985-4b05-93ce-016322e6da3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 30910f6850fc3728ee101ab0662638fdebcd3775
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405438"
---
# <a name="break-statement-c"></a>Instrução break (C++)
O **quebra** instrução finaliza a execução do delimitador mais próximo loop ou instrução condicional, na qual ele aparece. O controle passa para a instrução que segue o encerramento da instrução, se houver.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
break;  
```  
  
## <a name="remarks"></a>Comentários  
 O **quebra** instrução é usada com a condicional [alternar](../cpp/switch-statement-cpp.md) instrução e com o [fazer](../cpp/do-while-statement-cpp.md), [para](../cpp/for-statement-cpp.md), e [ao](../cpp/while-statement-cpp.md) instruções de loop.  
  
 Em um **alternar** instrução, o **quebra** instrução faz com que o programa executar a próxima instrução fora o **alternar** instrução. Sem um **quebra** instrução, cada instrução do correspondente **caso** rótulo ao final dos **alternar** instrução, incluindo o **padrão**cláusula, é executada.  
  
 Em loops, o **quebra** instrução finaliza a execução do delimitadora mais próxima **fazer**, **para**, ou **enquanto** instrução. O controle passa para a instrução que segue a instrução encerrada, se houver.  
  
 Em instruções aninhadas, a **quebra** instrução termina somente os **fazer**, **para**, **alternar**, ou **enquanto**instrução que a delimita imediatamente. Você pode usar um **retornar** ou **goto** instrução para transferir o controle de mais profundamente aninhada estruturas.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **quebra** instrução em um **para** loop.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    // An example of a standard for loop  
    for (int i = 1; i < 10; i++)  
    {  
        if (i == 4) {  
            break;  
        }  
        cout << i << '\n';  
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
  
```Output  
In each case:   
1  
2  
3  
```  
  
 O código a seguir mostra como usar **quebra** em um **enquanto** loop e uma **fazer** loop.  
  
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
  
```Output  
In each case:  
0123  
```  
  
 O código a seguir mostra como usar **quebra** em uma instrução switch. Você deve usar **quebra** em todos os casos se desejar tratar cada caso separadamente; se você não usar **quebra**, a execução do código falhará no próximo caso.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Hiperlink](../cpp/jump-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução continue](../cpp/continue-statement-cpp.md)