---
title: C3254 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3254
dev_langs:
- C++
helpviewer_keywords:
- C3254
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
caps.latest.revision: 9
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
ms.openlocfilehash: 4eae5cb3e7aa6bc91c7caee1b5ef3fbcd0b24139
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3254"></a>C3254 de erro do compilador
'substituição explícita': classe contém 'substituição de substituição explícita', mas não é derivada de uma interface que contém a declaração de função  
  
 Quando você [substituir explicitamente](../../cpp/explicit-overrides-cpp.md) um método, a classe que contém a substituição deve derivam, direta ou indiretamente, do tipo que contém a função que você está substituindo.  
  
 O exemplo a seguir gera C3254:  
  
```  
// C3254.cpp  
__interface I  
{  
   void f();  
};  
  
__interface I1 : I  
{  
};  
  
struct A /* : I1 */  
{  
   void I1::f()  
   {   // C3254, uncomment : I1 to resolve this C3254  
   }  
};  
  
int main()  
{  
}  
```
