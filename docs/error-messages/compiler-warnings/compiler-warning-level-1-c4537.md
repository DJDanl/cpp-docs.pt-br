---
title: "Compilador aviso (nível 1) C4537 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4537
dev_langs:
- C++
helpviewer_keywords:
- C4537
ms.assetid: 9454493c-d419-475e-8f35-9c00233c9329
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8204d93513582dea21182d98507d4692c67120a2
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4537"></a>Compilador C4537 de aviso (nível 1)
'object': 'operador' aplicado ao tipo UDT não  
  
 Uma referência foi passada em que um objeto (tipo definido pelo usuário) era esperado. Uma referência não é um objeto, mas o código de assembler embutido não é capaz de fazer a distinção. O compilador gera código como se ***objeto*** foram uma instância.  
  
 O exemplo a seguir gera C4537:  
  
```  
// C4537.cpp  
// compile with: /W1 /c  
// processor: x86  
struct S {  
   int member;  
};  
  
void f1(S &s) {  
   __asm mov eax, s.member;   // C4537  
   // try the following code instead  
   // or, make the declaration "void f1(S s)"  
   /*  
   mov eax, s  
   mov eax, [eax]s.member  
   */  
}  
```
