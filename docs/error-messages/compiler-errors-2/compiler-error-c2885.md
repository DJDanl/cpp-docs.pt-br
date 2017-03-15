---
title: C2885 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: 94ced7b380be42d6a04f6e5d7660ac8d38fd80a0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2885"></a>C2885 de erro do compilador
'class::identifier': não uma válida usando declaração no escopo da classe não  
  
 Você usou um [usando](../../cpp/using-declaration.md) declaração incorretamente.  
  
## <a name="example"></a>Exemplo  
 Esse erro pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: ele não é mais válido ter um `using` declaração para um tipo aninhado; explicitamente, você deve qualificar cada referência feitas para o tipo aninhado, colocar o tipo em um namespace, ou criar um typedef.  
  
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
