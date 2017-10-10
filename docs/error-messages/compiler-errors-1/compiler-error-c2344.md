---
title: C2344 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2344
dev_langs:
- C++
helpviewer_keywords:
- C2344
ms.assetid: a84c7b37-c84e-4345-8691-c23abb2dc193
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c7044ae9c2e15caa7ea2e0992512d22a146ec22a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2344"></a>C2344 de erro do compilador
align(#): alinhamento deve ser uma potência de dois  
  
 Ao usar o [alinhar](../../cpp/align-cpp.md) palavra-chave, o valor que você passa deve ser uma potência de dois.  
  
 Por exemplo, o código a seguir gera C2344 porque 3 não é uma potência de dois:  
  
```  
// C2344.cpp  
// compile with: /c  
__declspec(align(3)) int a;   // C2344  
__declspec(align(4)) int b;   // OK  
```
