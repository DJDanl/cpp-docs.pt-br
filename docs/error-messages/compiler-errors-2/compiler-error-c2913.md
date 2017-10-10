---
title: C2913 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2913
dev_langs:
- C++
helpviewer_keywords:
- C2913
ms.assetid: c6cf6090-02e8-49a5-913f-5bc6f864b769
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 156c4cd921dc9ac7d55b28114f6bb457f15b8a4a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2913"></a>C2913 de erro do compilador
especialização explícita; 'declaration' não é uma especialização de um modelo de classe  
  
 Não é possível especializar uma classe diferente do modelo.  
  
 O exemplo a seguir gera C2913:  
  
```  
// C2913.cpp  
// compile with: /c  
class X{};  
template <class T> class Y{};  
  
template<> class X<int> {};   // C2913  
template<> class Y<int> {};  
```
