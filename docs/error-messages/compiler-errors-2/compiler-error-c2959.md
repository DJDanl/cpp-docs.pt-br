---
title: C2959 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2959
dev_langs:
- C++
helpviewer_keywords:
- C2959
ms.assetid: d66bb2a8-70c3-4209-a358-b0c47f111a50
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce13a340812bce7cd6e5a0e4f8b2601b530fd3a2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33243787"
---
# <a name="compiler-error-c2959"></a>C2959 de erro do compilador
uma classe genérica ou função não pode ser um membro de um modelo  
  
 Para obter mais informações, consulte [Windows Runtime e modelos gerenciados](../../windows/windows-runtime-and-managed-templates-cpp-component-extensions.md) e [genéricos](../../windows/generics-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2959.  
  
```  
// C2959.cpp  
// compile with: /clr /c  
template <class T> ref struct S {  
   generic <class U> ref struct GR1;   // C2959  
};  
```