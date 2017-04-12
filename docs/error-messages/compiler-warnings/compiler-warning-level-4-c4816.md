---
title: "Compilador aviso (nível 4) C4816 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4816
dev_langs:
- C++
helpviewer_keywords:
- C4816
ms.assetid: 60f730ae-d942-4db9-ab97-41d4a874d8da
caps.latest.revision: 7
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
ms.openlocfilehash: 536525ab3b15a1fc588313e7cdc5487465ee9c7f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4816"></a>Compilador C4816 de aviso (nível 4)
'param': o parâmetro tem uma matriz de tamanho zero que será truncada (a menos que o objeto é passado por referência)  
  
 Um parâmetro para um objeto com uma matriz de tamanho zero não foi passado por referência. A matriz não será copiada quando o objeto é passado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4816:  
  
```  
// C4816.cpp  
// compile with: /W4  
#include <stdio.h>  
  
extern "C" int printf_s(const char *, ...);  
  
#pragma warning(disable : 4200)  
  
struct S1  
{  
    int i;  
    char cArr[];  
};  
  
void TestErr(S1 s1)   // C4816 param with zero-array   
                      // not passed by reference  
{  
    printf_s("%d %c %c\n", s1.i, s1.cArr[0], s1.cArr[1]);  
}  
  
void TestOk(S1 &s1)  
{  
    printf_s("%d %c %c\n", s1.i, s1.cArr[0], s1.cArr[1]);  
}  
  
int main()  
{  
    S1 myS_1 = { 6, 'a', 'b', 'c' };  
    TestErr(myS_1);  
    TestOk(myS_1);  
}  
```
