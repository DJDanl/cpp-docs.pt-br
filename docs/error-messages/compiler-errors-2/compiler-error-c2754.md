---
title: C2754 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2754
dev_langs:
- C++
helpviewer_keywords:
- C2754
ms.assetid: 1cab66c5-da9d-4b81-b7fb-9cdc48ff1ccc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5d6b6b3089f0fc345442777d1d254aeb20c08cb9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2754"></a>C2754 de erro do compilador
'especialização': uma especialização parcial não pode ter um parâmetro de modelo de tipo não dependentes  
  
 Foi feita uma tentativa para especializar parcialmente uma classe de modelo que tem um parâmetro de modelo de tipo não dependentes. Isso não é permitido.  
  
 O exemplo a seguir gera C2754:  
  
```  
// C2754.cpp  
// compile with: /c  
  
template<class T, T t>  
struct A {};  
  
template<class T, int N>  
struct B {};  
  
template<class T> struct A<T,5> {};   // C2754  
template<> struct A<int,5> {};   // OK  
template<class T> struct B<T,5> {};   // OK  
```
