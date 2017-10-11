---
title: C3366 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3366
dev_langs:
- C++
helpviewer_keywords:
- C3366
ms.assetid: efc55bcf-c16d-43c1-a36f-87a6165fa2a8
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b862e606b86eca0a7eb7f2ad1e91f2776c8c0b23
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3366"></a>C3366 de erro do compilador
'variável': membros de dados estáticos gerenciados ou WinRTtypes devem ser definidos dentro da definição de classe  
  
 Você tentou fazer referência a um membro estático de uma classe de WinRT ou .NET ou interface fora da definição de classe ou interface.  
  
 O compilador precisa saber a definição completa da classe (para emitir os metadados após uma passagem) e requer que os membros de dados estáticos sejam inicializados dentro da classe.  
  
 Por exemplo, o exemplo a seguir gera C3366 e mostra como corrigi-lo:  
  
```  
// C3366.cpp  
// compile with: /clr /c  
ref class X {  
   public:  
   static int i;   // initialize i here to avoid C3366  
};  
  
int X::i = 5;      // C3366  
```  

