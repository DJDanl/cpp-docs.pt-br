---
title: "Compilador aviso (nível 4) C4130 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4130
dev_langs:
- C++
helpviewer_keywords:
- C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2b29e9ec659d03cbfa45f04601c2a6bcdfd071f3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4130"></a>Compilador C4130 de aviso (nível 4)
'operator': a operação lógica no endereço da constante de cadeia de caracteres  
  
 Usando o operador com o endereço de uma cadeia de caracteres literal produz código inesperado.  
  
 O exemplo a seguir gera C4130:  
  
```  
// C4130.cpp  
// compile with: /W4  
int main()  
{  
   char *pc;  
   pc = "Hello";  
   if (pc == "Hello") // C4130  
   {  
   }  
}  
```  
  
 O **se** instrução compara o valor armazenado no ponteiro `pc` para o endereço da cadeia de caracteres "Hello", que é alocada separadamente cada vez que a cadeia de caracteres ocorre no código. O **se** instrução compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Hello".  
  
 Para comparar cadeias de caracteres, use o `strcmp` função.
