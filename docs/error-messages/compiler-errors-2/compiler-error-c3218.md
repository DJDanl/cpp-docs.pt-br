---
title: C3218 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3218
dev_langs:
- C++
helpviewer_keywords:
- C3218
ms.assetid: 0eea19e0-503e-4e07-ae8b-2cb2e95922cd
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 69ee49ece7354ce713fcfb86368aaca35b06cda7
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3218"></a>C3218 de erro do compilador
'type': não é permitido como uma restrição de tipo  
  
 Para um tipo para ser uma restrição, ele deve ser um tipo de valor ou uma referência a uma interface ou classe gerenciada.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3218.  
  
```  
// C3218.cpp  
// compile with: /clr /c  
class A {};  
ref class B {};  
  
// Delete the following 3 lines to resolve.  
generic <class T>  
where T : A   // C3218  
ref class C {};  
  
// OK  
generic <class T>  
where  T : B  
ref class D {};  
```
