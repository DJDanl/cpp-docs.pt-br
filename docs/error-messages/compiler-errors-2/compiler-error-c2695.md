---
title: C2695 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2695
dev_langs:
- C++
helpviewer_keywords:
- C2695
ms.assetid: 3f6f2091-c38b-40ea-ab6c-f1846f5702d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 67dc97688dddde37323f25b96bd8bbc596660e2f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33231211"
---
# <a name="compiler-error-c2695"></a>C2695 de erro do compilador
'function1': função virtual de substituição difere de 'function2' apenas pela convenção de chamada  
  
 A assinatura de uma função em uma classe derivada não pode substituir uma função em uma classe base e alterar a convenção de chamada.  
  
 O exemplo a seguir gera C2695:  
  
```  
// C2695.cpp  
class C {  
   virtual void __fastcall func();  
};  
  
class D : public C {  
   virtual void __clrcall func();   // C2695  
};  
```