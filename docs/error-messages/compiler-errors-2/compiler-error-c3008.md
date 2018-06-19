---
title: C3008 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3008
dev_langs:
- C++
helpviewer_keywords:
- C3008
ms.assetid: 04d93201-28e5-4be0-945c-aad616376f4b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3d70f065c8cff6154aa706203210973f67b82a73
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33245780"
---
# <a name="compiler-error-c3008"></a>C3008 de erro do compilador
'arg': argumento é de fechamento ausente ')' na diretiva de 'diretiva' OpenMP  
  
 Uma diretiva de OpenMP que usa um argumento não tinha um parêntese de fechamento.  
  
 O exemplo a seguir gera C3008:  
  
```  
// C3008.c  
// compile with: /openmp  
int main()  
{  
   int x, y, z;  
   #pragma omp parallel shared(x   // C3008  
   // Try the following line instead:  
   #pragma omp parallel shared(x)  
   {  
   }  
}  
```