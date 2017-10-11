---
title: C2092 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2092
dev_langs:
- C++
helpviewer_keywords:
- C2092
ms.assetid: 037e44ae-16c8-489a-a512-dcdf7f7795a6
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 45178f653871aea85071aa5df643ebd579f05419
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
