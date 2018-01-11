---
title: C2663 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2663
dev_langs: C++
helpviewer_keywords: C2663
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2a9c0ded6888855528867ec7993bcc28eac8045c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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