---
title: C2452 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2452
dev_langs:
- C++
helpviewer_keywords:
- C2452
ms.assetid: a4ec7642-6660-4c7a-9866-853d1cc67daf
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 06841629167a2567f33c1e731bc2b7593e58c118
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2452"></a>C2452 de erro do compilador
'type': tipo de fonte inválido para safe_cast  
  
 O tipo de fonte para [safe_cast](../../windows/safe-cast-cpp-component-extensions.md) não era válido.  Por exemplo, todos os tipos em um `safe_cast` operação deve ser tipos CLR.  
  
 O exemplo a seguir gera C2452:  
  
```  
// C2452.cpp  
// compile with: /clr  
  
struct A {};  
struct B : public A {};  
  
ref struct C {};  
ref struct D : public C{};  
  
int main() {  
   A a;  
   safe_cast<B*>(&a);   // C2452  
  
   // OK  
   C ^ c = gcnew C;  
   safe_cast<D^>(c);  
}  
```
