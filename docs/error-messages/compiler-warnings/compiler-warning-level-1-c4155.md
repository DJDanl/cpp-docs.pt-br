---
title: "Compilador (nível 1) de aviso C4155 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4155
dev_langs: C++
helpviewer_keywords: C4155
ms.assetid: ba233353-09e3-4195-8127-13a27ddd8d70
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 34f0654042e063f757f9ae70f2b94caee455dae5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4155"></a>Compilador C4155 de aviso (nível 1)
exclusão de uma expressão de matriz sem o uso da forma matricial de 'delete'  
  
 A forma matricial de **excluir** deve ser usado para excluir uma matriz. Este aviso ocorre apenas sob compatibilidade ANSI (/Za).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4155:  
  
```  
// C4155.cpp  
// compile with: /Za /W1  
#include <stdio.h>  
  
int main(void)  
{  
    int (*array)[ 10 ] = new int[ 5 ] [ 10 ];  
    array[0][0] = 8;  
  
    printf_s("%d\n", array[0][0]);  
  
   delete array;   // C4155  
    // try the following line instead  
    // delete [] array;   // C4155  
}  
```