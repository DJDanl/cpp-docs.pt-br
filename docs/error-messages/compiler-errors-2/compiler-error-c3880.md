---
title: C3880 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3880
dev_langs:
- C++
helpviewer_keywords:
- C3880
ms.assetid: b0e05d1e-32d0-4034-9246-f37d23573ea9
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5e86108e0ab2608f7f59f160d9f7a849b83ef71a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3880"></a>C3880 de erro do compilador
'var': não pode ser um membro de dados literal  
  
 O tipo de um [literal](../../windows/literal-cpp-component-extensions.md) atributo deve ser, ou em tempo de compilação conversível para um dos seguintes tipos:  
  
-   tipo integral  
  
-   cadeia de caracteres  
  
-   enumeração com um tipo integral ou subjacente  
  
 O exemplo a seguir gera C3880:  
  
```  
// C3880.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   literal System::Decimal staticConst1 = 10;   // C3880  
   literal int staticConst2 = 10;   // OK  
};  
```
