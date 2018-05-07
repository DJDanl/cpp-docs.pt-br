---
title: Compilador (nível 4) de aviso C4213 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4213
dev_langs:
- C++
helpviewer_keywords:
- C4213
ms.assetid: 59fc3f61-ebd2-499e-99d7-f57bec11eda1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 407fac636ea33c8cbd31104460442e5ac2aaec65
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4213"></a>Compilador C4213 de aviso (nível 4)
extensão não padrão usada: conversão em l-value  
  
 Com as extensões do Microsoft padrão (/Ze), você pode usar conversões do lado esquerdo de uma instrução de atribuição.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4213.c  
// compile with: /W4  
void *a;  
void f()  
{  
   int   i[3];  
   a = &i;  
   *(( int * )a )++ = 3;  // C4213  
}  
  
int main()  
{  
}  
```  
  
 Essas conversões são inválidos em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).