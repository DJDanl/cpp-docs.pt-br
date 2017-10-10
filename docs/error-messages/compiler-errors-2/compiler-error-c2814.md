---
title: C2814 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2814
dev_langs:
- C++
helpviewer_keywords:
- C2814
ms.assetid: 7d165136-a08b-4497-a76d-60a21bb19404
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1572d547ee8b6eb8b534e6d99027e63dae39c54d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2814"></a>C2814 de erro do compilador
'member': um tipo nativo não pode ser aninhado dentro de um gerenciado ou WinRT ' tipo '  
  
## <a name="example"></a>Exemplo  
 Um tipo nativo não pode ser aninhado em um tipo CLR ou WinRT. O exemplo a seguir gera C2814 e mostra como corrigi-lo.  
  
```  
// C2814.cpp  
// compile with: /clr /c  
ref class A {  
   class B {};   // C2814  
   ref class C {};   // OK  
};  
```  

