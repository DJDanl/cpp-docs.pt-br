---
title: "Compilador (nível 4) de aviso C4130 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4130
dev_langs: C++
helpviewer_keywords: C4130
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 282f9755470baca115d0595b002b929874619a93
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4130"></a>Compilador C4130 de aviso (nível 4)
'operator': operação lógica em endereço de constante de cadeia de caracteres  
  
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
  
 O **se** instrução compara o valor armazenado no ponteiro `pc` para o endereço da cadeia de caracteres "Hello", que é alocada separadamente cada vez que a cadeia de caracteres ocorre no código. O **se** instrução não compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Olá".  
  
 Para comparar cadeias de caracteres, use o `strcmp` função.