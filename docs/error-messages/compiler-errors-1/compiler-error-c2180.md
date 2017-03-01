---
title: C2180 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2180
dev_langs:
- C++
helpviewer_keywords:
- C2180
ms.assetid: ea71b39e-b977-48a7-b7bd-af68ef5e263b
caps.latest.revision: 11
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
ms.openlocfilehash: 73fd87cc48abed22f74a5b59395d59b5606312fb
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2180"></a>C2180 de erro do compilador
Controlando a expressão tem o tipo 'type'  
  
 A expressão de controle em uma `if`, `while`, `for`, ou `do` instrução é uma expressão convertida em `void`. Para corrigir esse problema, altere a expressão de controle para uma que produza um `bool` ou um tipo que pode ser convertido em `bool`.  
  
 O exemplo a seguir gera C2180:  
  
```  
// C2180.c  
  
int main() {  
   while ((void)1)   // C2180  
      return 1;  
   while (1)         // OK  
      return 0;  
}  
```
