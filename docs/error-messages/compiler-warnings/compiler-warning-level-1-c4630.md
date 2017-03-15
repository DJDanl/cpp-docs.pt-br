---
title: "Compilador aviso (nível 1) C4630 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4630
dev_langs:
- C++
helpviewer_keywords:
- C4630
ms.assetid: d8926376-7acc-4fc7-8438-6f0de3468870
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6f91d3c87703ead6fc009c16b0746ac8037fdd21
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4630"></a>Compilador C4630 de aviso (nível 1)
'symbol': especificador de classe de armazenamento 'extern' inválida na definição de membro  
  
 Um membro de dados ou uma função de membro é definida como `extern`. Membros não podem ser externos, embora podem objetos inteiros. O compilador ignora o `extern` palavra-chave. O exemplo a seguir gera C4630:  
  
```  
// C4630.cpp  
// compile with: /W1 /LD  
class A {  
   void func();  
};  
  
extern void A::func() {   // C4630, remove 'extern' to resolve  
}  
```
