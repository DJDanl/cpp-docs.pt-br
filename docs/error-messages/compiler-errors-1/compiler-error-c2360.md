---
title: C2360 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2360
dev_langs:
- C++
helpviewer_keywords:
- C2360
ms.assetid: 51bfd2ee-8108-4777-aa93-148b9cebfa83
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 12b62d31c125dfc353623fa7cf10fce578698332
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2360"></a>C2360 de erro do compilador
inicialização de 'Identificador' é ignorada por rótulo 'case'  
  
 A inicialização de `identifier` pode ser ignorado em um `switch` instrução. Você não pode ir além de uma declaração com um inicializador, a menos que a declaração é incluída em um bloco. (A menos que ela é declarada dentro de um bloco, a variável está no escopo até o término do `switch` instrução.)  
  
 O exemplo a seguir gera C2360:  
  
```  
// C2360.cpp  
int main() {  
   int x = 0;  
   switch ( x ) {  
   case 0 :  
      int i = 1;  
      { int j = 1; }  
   case 1 :   // C2360  
      int k = 1;  
   }  
}  
```  
  
 Possível solução:  
  
```  
// C2360b.cpp  
int main() {  
   int x = 0;  
   switch ( x ) {  
   case 0 :  
      { int j = 1; int i = 1;}  
   case 1 :  
      int k = 1;  
   }  
}  
```
