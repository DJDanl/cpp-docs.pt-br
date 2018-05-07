---
title: Compilador (nível 2) do aviso C4156 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4156
dev_langs:
- C++
helpviewer_keywords:
- C4156
ms.assetid: 9adf3acb-c0fe-42a8-a4db-5822b1493f77
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 249d90712b4a8b02f10deaa4d87cdbb7a7c17ae3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4156"></a>Compilador C4156 de aviso (nível 2)
exclusão de uma expressão de matriz sem o uso da forma matricial de 'delete'; forma matricial substituída  
  
 A forma de não-matriz de **excluir** não é possível excluir uma matriz. O compilador convertido **excluir** para o formulário de matriz.  
  
 Este aviso ocorre apenas sob extensões da Microsoft (/Ze).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4156.cpp  
// compile with: /W2  
int main()  
{  
   int (*array)[ 10 ] = new int[ 5 ][ 10 ];  
   delete array; // C4156, changed by compiler to "delete [] array;"  
}  
```