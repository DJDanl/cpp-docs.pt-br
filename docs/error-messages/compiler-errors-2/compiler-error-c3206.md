---
title: C3206 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3206
dev_langs:
- C++
helpviewer_keywords:
- C3206
ms.assetid: d62995b5-e349-4418-bbe8-8a5e776ca7b0
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 600ea77821fc457a631f96d48b2416f958dce667
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3206"></a>C3206 de erro do compilador
'function': argumento de tipo inválido para 'param', faltando lista de argumentos de tipo no tipo de classe 'typename'  
  
 Um modelo de função é definido como colocar um argumento de tipo de modelo. No entanto, foi passado um argumento de modelo do modelo.  
  
 O exemplo a seguir gera C3206:  
  
```  
// C3206.cpp  
template <class T>  
void f() {}  
  
template <class T>  
struct S {};  
  
void f1() {  
   f<S>();   // C3206  
   // try the following line instead  
   // f<S<int> >();  
}  
```  
  
 Possível solução:  
  
```  
// C3206b.cpp  
// compile with: /c  
template <class T>  
void f() {}  
  
template <class T>  
struct S {};  
  
void f1() {  
   f<S<int> >();  
}  
```  
  
 C3206 também pode ocorrer ao usar genéricos:  
  
```  
// C3206c.cpp  
// compile with: /clr  
generic <class GT1>  
void gf() {}  
  
generic <class T>  
value struct GS {};  
  
int main() {  
   gf<GS>();   // C3206  
}  
```  
  
 Possível solução:  
  
```  
// C3206d.cpp  
// compile with: /clr  
generic <class GT1>  
void gf() {}  
  
generic <class T>  
value struct GS {};  
  
int main() {  
   gf<GS<int> >();  
}  
```  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador do Visual C++ .NET 2003, onde os modelos de classe não são permitidos como argumento de tipo de modelo.  
  
 Um modelo de classe não é permitido como argumento de tipo de modelo. Isso funcionou no Visual C++ .NET 2003, mas é C++ inválido.  
  
 O exemplo a seguir é compilado no Visual C++ .NET 2002 mas falharão no Visual C++ .NET 2003:  
  
```  
// C3206e.cpp  
template <class T>  
struct S {};  
  
template <class T>  
void func() {   // takes a type  
   T<int> t;  
}  
  
int main() {  
   func<S>();   // C3206 S is not a type.  
}  
```  
  
 Possível solução:  
  
```  
// C3206f.cpp  
template <class T>  
struct S {};  
  
template <class T>  
void func() {   // takes a type  
   T t;  
}  
  
int main() {  
   func<S<int> >();  
}  
```  
  
 Se um parâmetro de modelo for necessário, a resolução para o erro que é válido no Visual C++ .NET 2003 e versões do Visual C++ .NET 2002 requerem a encapsular a função em uma classe de modelo que usa um parâmetro de modelo:  
  
```  
// C3206g.cpp  
template <class T>  
struct S {};  
  
template<template<class> class TT>  
struct X {  
   static void func() {  
      TT<int> t1;  
      TT<char> t2;  
   }  
};  
  
int main() {  
   X<S>::func();  
}  
```
