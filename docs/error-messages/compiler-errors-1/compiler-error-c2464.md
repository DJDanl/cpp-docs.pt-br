---
title: C2464 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2464
dev_langs:
- C++
helpviewer_keywords:
- C2464
ms.assetid: ace953d6-b414-49ee-bfef-90578a8da00c
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7e2600608ae490363d9042ad72ad91bf7cfe32d2
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2464"></a>C2464 de erro do compilador
'Identificador': não é possível usar 'new' para alocar uma referência  
  
 Um identificador de referência foi alocado com o `new` operador. Referências não são objetos de memória, portanto `new` não pode retornar um ponteiro para eles. Use a sintaxe de declaração de variável padrão para declarar uma referência.  
  
 O exemplo a seguir gera C2464:  
  
```  
// C2464.cpp  
int main() {  
   new ( int& ir );   // C2464  
}  
```
