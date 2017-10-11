---
title: C3857 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3857
dev_langs:
- C++
helpviewer_keywords:
- C3857
ms.assetid: 9f746d1e-9708-4945-bc29-3150d5371d3c
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e9c553adf8eb9b326bcb2b3b35a381973c9c4a50
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3857"></a>C3857 de erro do compilador
'type': várias listas de parâmetros de tipo não são permitidas  
  
 Mais de um modelo ou genérico foi especificado para o mesmo tipo, que não é permitido.  
  
 O exemplo a seguir gera C3857:  
  
```  
// C3857.cpp  
template <class T, class TT>  
template <class T2>    // C3857  
struct B {};  
```  
  
 Possível solução:  
  
```  
// C3857b.cpp  
// compile with: /c  
template <class T, class TT, class T2>   
struct B {};  
```  
  
 C3857 também pode ocorrer ao usar genéricos:  
  
```  
// C3857c.cpp  
// compile with: /clr  
generic <typename T>  
generic <typename U>  
ref class GC;   // C3857  
```  
  
 Possível solução:  
  
```  
// C3857d.cpp  
// compile with: /clr /c  
generic <typename U>  
ref class GC;  
```
