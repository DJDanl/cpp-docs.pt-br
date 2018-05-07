---
title: Compilador (nível 2) do aviso C4396 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4396
dev_langs:
- C++
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b937b6ecebedc6984279502a5f64b287f09bd2d9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4396"></a>Compilador C4396 de aviso (nível 2)
"name": o especificador embutido não pode ser usado quando uma declaração friend se refere a uma especialização de um modelo de função  
  
 Uma especialização de um modelo de função não é possível especificar qualquer uma da [embutido](../../cpp/inline-functions-cpp.md) especificadores. O compilador emite o aviso C4396 e ignora o especificador embutido.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `inline`, `__inline`, ou `__forceinline` especificador de declaração da função friend.  
  
## <a name="example"></a>Exemplo  
 O código exemplo seguinte mostra um amigo inválido função declaração com um `inline` especificador.  
  
```  
// C4396.cpp  
// compile with: /W2 /c  
  
class X;   
template<class T> void Func(T t, int i);  
  
class X {  
    friend inline void Func<char>(char t, int i);  //C4396  
// try the following line instead  
//    friend void Func<char>(char t, int i);   
    int i;  
};  
```