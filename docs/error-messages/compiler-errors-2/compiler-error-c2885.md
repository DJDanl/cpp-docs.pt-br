---
title: C2885 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2885
dev_langs:
- C++
helpviewer_keywords:
- C2885
ms.assetid: 7743e5f3-a034-44b4-9ee8-5a6254c27f8c
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a19f209d53d7d0b37cddbf559fa3dc02ee50db7e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2885"></a>C2885 de erro do compilador
'class::identifier': não uma declaração de using válida em escopo diferente de classe  
  
 Você usou um [usando](../../cpp/using-declaration.md) declaração incorretamente.  
  
## <a name="example"></a>Exemplo  
 Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: não é válido para ter um `using` declaração para um tipo aninhado; explicitamente, você deve qualificar cada feitas para o tipo aninhado, coloque o tipo em um nome de referência espaço ou criar um typedef.  
  
 O exemplo a seguir gera C2885.  
  
```  
// C2885.cpp  
namespace MyNamespace {  
   class X1 {};  
}  
  
struct MyStruct {  
   struct X1 {  
      int i;  
   };  
};  
  
int main () {  
   using MyStruct::X1;   // C2885  
  
   // OK  
   using MyNamespace::X1;  
   X1 myX1;  
  
   MyStruct::X1 X12;  
  
   typedef MyStruct::X1 abc;  
   abc X13;  
   X13.i = 9;  
}  
```  
  
## <a name="example"></a>Exemplo  
 Se você usar o `using` palavra-chave com um membro de classe C++ requer que você definir esse membro dentro de outra classe (uma classe derivada).  
  
 O exemplo a seguir gera C2885.  
  
```  
// C2885_b.cpp  
// compile with: /c  
class A {  
public:  
   int i;  
};  
  
void z() {  
   using A::i;   // C2885 not in a class  
}  
  
class B : public A {  
public:  
   using A::i;  
};  
```
