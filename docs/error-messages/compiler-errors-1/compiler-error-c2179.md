---
title: C2179 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2179
dev_langs:
- C++
helpviewer_keywords:
- C2179
ms.assetid: f929bfc6-3964-4e54-87d6-7529b9b6c0b9
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c0f311bcdbbdaa721e3897eae0a90ae892cf75d8
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2179"></a>C2179 de erro do compilador
'type': um argumento de atributo não é possível usar parâmetros de tipo  
  
 Um parâmetro de tipo genérico é resolvido em tempo de execução. No entanto, um parâmetro de atributo deve ser resolvido em tempo de compilação. Portanto, você não pode usar um parâmetro de tipo genérico como um argumento para um atributo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2179.  
  
```  
// C2179.cpp  
// compile with: /clr  
using namespace System;  
  
public ref struct Attr : Attribute {  
   Attr(Type ^ a) {  
      x = a;  
   }  
  
   Type ^ x;  
};  
  
ref struct G {};  
  
generic<typename T>   
public ref class Z {   
public:  
   Type ^ d;  
   [Attr(T::typeid)]   // C2179  
   // try the following line instead  
   // [Attr(G::typeid)]  
   T t;  
};  
```
