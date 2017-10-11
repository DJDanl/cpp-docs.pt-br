---
title: C2477 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2477
dev_langs:
- C++
helpviewer_keywords:
- C2477
ms.assetid: 60bc324b-6605-4833-8099-a291efc712e7
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 72b83b09ec97a2e7e68b2ee28429eeb31567178c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2477"></a>C2477 de erro do compilador
'member': membro de dados estático não pode ser inicializado via classe derivada  
  
 Um membro de dados estático de uma classe de modelo foi inicializado incorretamente. Isso é uma alteração significativa com versões do compilador Visual C++ antes do Visual Studio .NET 2003 para estar de acordo com o padrão ISO C++.  
  
 O exemplo a seguir gera C2477:  
  
```  
// C2477.cpp  
// compile with: /Za /c  
template <class T>  
struct S {  
   static int n;  
};  
  
struct X {};  
struct A: S<X> {};  
  
int A::n = 0;   // C2477  
  
template<>  
int S<X>::n = 0;  
```
