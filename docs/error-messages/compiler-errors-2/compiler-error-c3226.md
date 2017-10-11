---
title: C3226 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3226
dev_langs:
- C++
helpviewer_keywords:
- C3226
ms.assetid: 636106ca-6f4e-4303-a6a0-8803221ec67d
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4dbba2964b99dd059f27d4bc4917a74fec664ab2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3226"></a>C3226 de erro do compilador
Uma declaração de modelo não é permitida em uma declaração de generic  
  
 Use uma declaração de generic dentro de uma classe genérica.  
  
 O exemplo a seguir gera C3226:  
  
```  
// C3226.cpp  
// compile with: /clr  
generic <class T>  
ref class C {  
   template <class T1>   // C3226  
   ref struct S1 {};  
};  
```  
  
 O exemplo a seguir demonstra uma possível resolução:  
  
```  
// C3226b.cpp  
// compile with: /clr /c  
generic <class T>  
ref class C {  
   generic <class T1>  
   ref struct S1 {};  
};  
```
