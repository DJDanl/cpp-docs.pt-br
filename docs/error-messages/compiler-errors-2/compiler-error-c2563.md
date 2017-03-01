---
title: C2563 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2563
dev_langs:
- C++
helpviewer_keywords:
- C2563
ms.assetid: 54abba68-6458-4ca5-894d-3babdb7b3552
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
ms.openlocfilehash: 096db28208a1e72c7fe758f310ba73a28e9692d4
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2563"></a>C2563 de erro do compilador
incompatibilidade na lista de parâmetros formais  
  
 Lista de parâmetros formais de uma função (ou um ponteiro para uma função) não corresponde às de outra função (ou ponteiro para uma função de membro). Como resultado, a atribuição de funções ou ponteiros não pode ser feita.  
  
 O exemplo a seguir gera C2563:  
  
```  
// C2563.cpp  
void func( int );  
void func( int, int );  
int main() {  
   void *fp();  
   fp = func;   // C2563  
}  
```
