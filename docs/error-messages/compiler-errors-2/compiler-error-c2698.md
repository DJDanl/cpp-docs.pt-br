---
title: C2698 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2698
dev_langs:
- C++
helpviewer_keywords:
- C2698
ms.assetid: 3ebfe395-c20b-4c56-9980-ca9ed8653382
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c466e39702f1e408ad96d79c16c4a5953fa373f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233811"
---
# <a name="compiler-error-c2698"></a>C2698 de erro do compilador
a declaração using para ' declaração 1' não pode coexistir com a declaração de using existente para ' declaração 2'  
  
 Depois que você tiver um [usando declaração](../../cpp/using-declaration.md) para um membro de dados, uso de qualquer declaração no mesmo escopo que usa o mesmo nome não é permitida, como funções só podem ser sobrecarregadas.  
  
 O exemplo a seguir gera C2698:  
  
```  
// C2698.cpp  
struct A {  
   int x;  
};  
  
struct B {  
   int x;  
};  
  
struct C : A, B {  
   using A::x;  
   using B::x;   // C2698  
}  
```