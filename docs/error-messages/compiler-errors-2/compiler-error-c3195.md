---
title: C3195 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3195
dev_langs:
- C++
helpviewer_keywords:
- C3195
ms.assetid: 97e4f681-812b-49e8-ba57-24b7817e3cd8
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e6e95ce1592c98fae59869e0153ee27c0f727397
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3195"></a>C3195 de erro do compilador
'operator': é reservado e não pode ser usado como um membro de um tipo de valor ou classe ref. Operadores CLR ou WinRT devem ser definidas usando a palavra-chave 'operator'  
  
O compilador detectou uma definição de operador usando extensões gerenciadas para obter a sintaxe de C++. Você deve usar a sintaxe de C++ para operadores.  
  
O exemplo a seguir gera C3195 e mostra como corrigi-lo:  
  
```  
// C3195.cpp  
// compile with: /clr /LD  
#using <mscorlib.dll>  
value struct V {  
   static V op_Addition(V v, int i);   // C3195  
   static V operator +(V v, char c);   // OK for new C++ syntax   
};  
```
