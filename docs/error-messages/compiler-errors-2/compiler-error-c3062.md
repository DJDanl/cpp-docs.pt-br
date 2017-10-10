---
title: C3062 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3062
dev_langs:
- C++
helpviewer_keywords:
- C3062
ms.assetid: 78632e6d-255f-42c3-b124-31a9194ff86d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1eebf751c267e9688eebb8c679fe801f77cfa4c0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3062"></a>C3062 de erro do compilador
'enum': enumerador requer valor porque o tipo subjacente é 'type'  
  
 Você pode especificar um tipo subjacente para uma enumeração. No entanto, alguns tipos exigem atribuir valores para cada enumerador.  
  
 Para obter mais informações sobre enumerações, consulte [classe enum](../../windows/enum-class-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3062:  
  
```  
// C3062.cpp  
// compile with: /clr  
  
enum class MyEnum : bool { a };   // C3062  
enum class MyEnum2 : bool { a = true};   // OK  
```
