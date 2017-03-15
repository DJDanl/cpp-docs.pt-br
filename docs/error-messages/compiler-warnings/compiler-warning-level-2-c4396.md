---
title: "Compilador aviso (nível 2) C4396 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4396
dev_langs:
- C++
helpviewer_keywords:
- C4396
ms.assetid: 7cd6b283-db17-4574-b299-03e0b913ad70
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 84f0628de933344eb23dc6325679abdcd3699c3a
ms.openlocfilehash: 8e0538cc5a1ec9279c4d84cb9e23e0d6fabfd77e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4396"></a>Compilador C4396 de aviso (nível 2)
"nome": o especificador embutido não pode ser usado quando uma declaração de amigo se refere a uma especialização de um modelo de função  
  
 Uma especialização de um modelo de função não é possível especificar qualquer um do [embutido](../../cpp/inline-functions-cpp.md) especificadores. O compilador emite um aviso C4396 e ignora o especificador embutido.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `inline`, `__inline`, ou `__forceinline` especificador de declaração de função friend.  
  
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
