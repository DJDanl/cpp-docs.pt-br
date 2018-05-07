---
title: C2663 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2663
dev_langs:
- C++
helpviewer_keywords:
- C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f39f516b32aaf1159d47726d01623e253ee8b383
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2663"></a>C2663 de erro do compilador
'function': número sobrecargas não possuem nenhuma conversão legal para ponteiro 'this'  
  
 Não foi possível converter o compilador `this` para qualquer uma das versões sobrecarregadas da função de membro.  
  
 Esse erro pode ser causado por meio de invocação não`const` função de membro em uma `const` objeto.  Possíveis resoluções:  
  
1.  Remover o `const` na declaração de objeto.  
  
2.  Adicionar `const` para uma das sobrecargas de função de membro.  
  
 O exemplo a seguir gera C2663:  
  
```  
// C2663.cpp  
struct C {  
   void f() volatile {}  
   void f() {}  
};  
  
struct D {  
   void f() volatile;  
   void f() const {}  
};  
  
const C *pcc;  
const D *pcd;  
  
int main() {  
   pcc->f();    // C2663  
   pcd->f();    // OK  
}  
```