---
title: C2085 de erro do compilador | Documentos do Microsoft
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ea242cdcd217ea64d6386fff6541a42a7da0ea1b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2085"></a>C2085 de erro do compilador
'identifier': não está na lista de parâmetros formal  
  
 O identificador foi declarado em uma definição de função, mas não na lista de parâmetros formais. ANSI C (apenas)  
  
 O exemplo a seguir gera C2085:  
  
```  
// C2085.c  
void func1( void )  
int main( void ) {}   // C2085  
```  
  
 Resolução possível:  
  
```  
// C2085b.c  
void func1( void );  
int main( void ) {}  
```  
  
 Com ponto e vírgula ausente, `func1()` parece com uma definição de função, não é um protótipo, então `main` é definido dentro de `func1()`, gerando o erro C2085 para identificador `main`.
