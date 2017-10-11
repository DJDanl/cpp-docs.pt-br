---
title: C3666 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3666
dev_langs:
- C++
helpviewer_keywords:
- C3666
ms.assetid: 459e51dd-cefb-4346-99b3-644f2d8b65b2
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0bd78e2d14805ab84f1d32300f1cf95a1daf91d0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3666"></a>C3666 de erro do compilador
'construtor': especificador 'palavra-chave' não é permitido em um construtor de substituição  
  
 Um especificador de substituição foi usado em um construtor e que não é permitido. Para obter mais informações, consulte [especificadores de substituição](../../windows/override-specifiers-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3666.  
  
```  
// C3666.cpp  
// compile with: /clr /c  
ref struct R {  
   R() new {}   // C3666  
   R(int i) {}   // OK  
};  
```
