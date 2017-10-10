---
title: C2909 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2909
dev_langs:
- C++
helpviewer_keywords:
- C2909
ms.assetid: 1c9df8ae-925d-4002-a5f8-a71413c45f9e
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e2163decefb2530a6a89b6db47e283878dd3abf7
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2909"></a>C2909 de erro do compilador
'Identificador': instanciação explícita de template de função requer tipo de retorno  
  
 Uma instanciação explícita de um modelo de função exige a especificação explícita de seu tipo de retorno. Especificação de tipo de retorno implícita não funciona.  
  
 O exemplo a seguir gera C2909:  
  
```  
// C2909.cpp  
// compile with: /c  
template<class T> int f(T);  
template f<int>(int);         // C2909  
template int f<int>(int);   // OK  
```
