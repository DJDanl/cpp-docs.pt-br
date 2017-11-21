---
title: "Compilador (nível 2) do aviso C4396 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4396
dev_langs: C++
helpviewer_keywords: C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5bee2614d479ec54bf9d49c92deb336eee05d285
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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