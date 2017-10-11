---
title: C3379 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3379
dev_langs:
- C++
helpviewer_keywords:
- C3379
ms.assetid: a66c2c4e-091c-4426-9cde-7c4cfb2ffce1
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e6fa111a525d81c418d3285c05af86b700e8cb08
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3379"></a>C3379 de erro do compilador
'class': uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração  
  
 Quando aplicado a um tipo gerenciado, como a classe ou estrutura, o [pública](../../cpp/public-cpp.md) e [privada](../../cpp/private-cpp.md) palavras-chave que indicam se a classe será exposta por meio de metadados do assembly. `public`ou `private` não pode ser aplicado a uma classe aninhada, que herda o acesso de assembly da classe de delimitador.  
  
 Quando usado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md), o `ref` e `value` palavras-chave que indicam que uma classe seja gerenciada (consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md)).  
  
 O exemplo a seguir gera C3379:  
  
```  
// C3379a.cpp  
// compile with: /clr  
using namespace System;  
  
public ref class A {  
public:  
   static int i = 9;  
  
   public ref class BA {   // C3379  
   // try the following line instead  
   // ref class BA {  
   public:  
      static int ii = 8;  
   };  
};  
  
int main() {  
  
   A^ myA = gcnew A;  
   Console::WriteLine(myA->i);  
  
   A::BA^ myBA = gcnew A::BA;  
   Console::WriteLine(myBA->ii);  
}  
```  

