---
title: C2502 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2502
dev_langs:
- C++
helpviewer_keywords:
- C2502
ms.assetid: affa0b86-15fc-4e17-b7f2-6aad4a3771c4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 093980d1e604eacde92a8ea7aa029f77f57d48b7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2502"></a>C2502 de erro do compilador
'Identificador': muitos modificadores de acesso na classe base  
  
 A classe base tiver mais de um modificador de acesso. Modificador de acesso de somente um (`public`, `private`, ou `protected`) é permitido.  
  
 O exemplo a seguir gera C2502:  
  
```  
// C2502.cpp  
// compile with: /c  
class A { };  
class B { };  
class C : private public A { };   // C2502  
  
// OK  
class D : private A {};  
class E : public A, private B {};  
```