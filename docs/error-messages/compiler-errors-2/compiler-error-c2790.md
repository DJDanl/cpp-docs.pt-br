---
title: C2790 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2790
dev_langs:
- C++
helpviewer_keywords:
- C2790
ms.assetid: 38d4fce1-ba00-413d-8bc1-e8aa43d7bc1f
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 11ea7285d20808f16f2588d50caebe99429c8da0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2790"></a>C2790 de erro do compilador
'super': esta palavra-chave só pode ser usado no corpo da função de membro de classe  
  
 Essa mensagem de erro será exibida se o usuário tentar usa a palavra-chave [super](../../cpp/super.md) fora do contexto de uma função de membro.  
  
 O exemplo a seguir gera C2790:  
  
```  
// C2790.cpp  
void f() {  
   __super::g();   // C2790  
}  
```
