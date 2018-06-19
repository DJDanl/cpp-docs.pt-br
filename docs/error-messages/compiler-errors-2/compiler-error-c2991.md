---
title: C2991 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2991
dev_langs:
- C++
helpviewer_keywords:
- C2991
ms.assetid: a87e4404-26e8-4927-b3ee-5d02b3b8bee1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8b1605c7b12a08b0fdb3701a94b2b5cf2e649c98
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33243951"
---
# <a name="compiler-error-c2991"></a>C2991 de erro do compilador
redefinição do parâmetro de tipo 'parameter'  
  
 Houve um conflito de tipo entre duas definições genérico ou modelo de `parameter`. Ao definir vários parâmetros genéricos ou modelo, você deve usar tipos equivalentes.  
  
 O exemplo a seguir gera C2991:  
  
```  
// C2991.cpp  
// compile with: /c  
template<class T, class T> struct TC {};   // C2991  
// try the following line instead  
// template<class T, class T2> struct TC {};  
```  
  
 C2991 também pode ocorrer ao usar genéricos:  
  
```  
// C2991b.cpp  
// compile with: /clr /c  
generic<class T,class T> ref struct GC {};   // C2991  
// try the following line instead  
// generic<class T,class T2> ref struct GC {};  
```