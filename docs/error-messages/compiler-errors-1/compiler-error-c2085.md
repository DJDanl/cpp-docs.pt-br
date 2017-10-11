---
title: C2085 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2085
dev_langs:
- C++
helpviewer_keywords:
- C2085
ms.assetid: 0a86785c-8e6f-481b-8c7b-412220c1950d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 45805bbea2eca77ae81922088471e99de26be1e4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2085"></a>C2085 de erro do compilador
'Identificador': não está na lista de parâmetros formais  
  
 O identificador foi declarado em uma definição de função, mas não na lista de parâmetros formais. (Somente para ANSI C)  
  
 O exemplo a seguir gera C2085:  
  
```  
// C2085.c  
void func1( void )  
int main( void ) {}   // C2085  
```  
  
 Possível solução:  
  
```  
// C2085b.c  
void func1( void );  
int main( void ) {}  
```  
  
 Com o ponto e vírgula ausente `func1()` se parece com uma definição de função, não um protótipo, portanto `main` esteja definido no `func1()`, gerar erro C2085 do identificador `main`.
