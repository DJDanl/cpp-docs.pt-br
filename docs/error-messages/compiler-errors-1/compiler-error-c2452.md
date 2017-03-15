---
title: C2452 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a8e9139ba289f38d60c1e4dd00dc59a1cd97d068
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2452"></a>C2452 de erro do compilador
'type': o tipo de origem inválido para safe_cast  
  
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
