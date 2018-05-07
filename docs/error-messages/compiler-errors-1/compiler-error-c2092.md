---
title: C2092 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2092
dev_langs:
- C++
helpviewer_keywords:
- C2092
ms.assetid: 037e44ae-16c8-489a-a512-dcdf7f7795a6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 22b33680258358648737a9ae235c6f45f3592992
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2092"></a>C2092 de erro do compilador
tipo de elemento de matriz 'nome de matriz' não pode ser uma função  
  
 Matrizes de funções não são permitidas. Use uma matriz de ponteiros para funções.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2092:  
  
```  
// C2092.cpp  
typedef void (F) ();  
typedef F AT[10];   // C2092  
```  
  
## <a name="example"></a>Exemplo  
 Possível solução:  
  
```  
// C2092b.cpp  
// compile with: /c  
typedef void (F) ();  
typedef F * AT[10];  
```