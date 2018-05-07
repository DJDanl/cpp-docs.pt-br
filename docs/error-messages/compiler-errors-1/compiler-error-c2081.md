---
title: C2081 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2081
dev_langs:
- C++
helpviewer_keywords:
- C2081
ms.assetid: 7db9892d-364d-4178-a49d-f8398ece09a0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 165217b3ea4d50dc965927419786a01a6cc92af3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2081"></a>C2081 de erro do compilador
'Identificador': nome ilegal da lista de parâmetros formais  
  
 O identificador causou um erro de sintaxe.  
  
 Esse erro pode ser causado por meio de estilo antigo para a lista de parâmetros formais. Você deve especificar o tipo de parâmetros formais na lista de parâmetros formais.  
  
 O exemplo a seguir gera C2081:  
  
```  
// C2081.c  
void func( int i, j ) {}  // C2081, no type specified for j  
```  
  
 Possível solução:  
  
```  
// C2081b.c  
// compile with: /c  
void func( int i, int j ) {}  
```