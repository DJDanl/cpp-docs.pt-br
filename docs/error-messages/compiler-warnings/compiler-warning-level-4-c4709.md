---
title: "Compilador (nível 4) de aviso C4709 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4709
dev_langs: C++
helpviewer_keywords: C4709
ms.assetid: 8abfdd45-8c70-4c27-b0fb-ca0c3f0fccf9
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b60ee80f9b08914a7f8f2004bc4c6afecc80186a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4709"></a>Compilador C4709 de aviso (nível 4)
operador vírgula dentro de expressão de índice de matriz  
  
 Quando ocorre uma vírgula em uma expressão de índice de matriz, o compilador usa o valor após a última vírgula.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4709:  
  
```  
// C4709.cpp  
// compile with: /W4  
#include <stdio.h>  
  
int main()   
{  
    int arr[2][2];  
    arr[0][0] = 10;  
    arr[0][1] = 11;  
  
    // Prints 10, not 11  
    printf_s("\n%d",arr[0][1,0]);   // C4709  
}  
```