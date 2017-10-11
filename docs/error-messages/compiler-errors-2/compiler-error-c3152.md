---
title: C3152 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3152
dev_langs:
- C++
helpviewer_keywords:
- C3152
ms.assetid: 4ee6e2cd-5d19-4b73-833d-765c35797e4b
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 222a45a8a8820c426902ef3584a3663103b63fa2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3152"></a>C3152 de erro do compilador
'Criar': 'palavra-chave' só pode ser aplicado a uma classe, struct ou função membro virtual  
  
 Determinadas palavras-chave só pode ser aplicado a uma classe do C++.  
  
 O exemplo a seguir gera C3152 e mostra como corrigi-lo:  
  
```  
// C3152.cpp  
// compile with: /clr /c  
ref class C {  
   int (*pfn)() sealed;   // C3152  
   virtual int g() sealed;   // OK  
};  
```  

