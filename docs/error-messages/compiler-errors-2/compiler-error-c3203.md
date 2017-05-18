---
title: C3203 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3203
dev_langs:
- C++
helpviewer_keywords:
- C3203
ms.assetid: 6356770e-22c1-434c-91fe-f60b0aa23b91
caps.latest.revision: 12
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 544d73ef569723891cc5b9a38a3449d5c686edc9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3203"></a>C3203 de erro do compilador
'type': modelo de classe não-especializado ou genérico não pode ser usado como um modelo ou um argumento genérico para o modelo ou parâmetro genérico 'param', esperado um tipo real  
  
 Você passou um argumento inválido para um modelo de classe ou genérico. O modelo de classe ou genérica espera um tipo como um parâmetro.  
  
 Esse erro pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: um modelo de classe não especializada não pode ser usado como um argumento de modelo em uma lista de classes base. Para resolver C3203, adicione explicitamente os parâmetros de tipo de modelo para o nome da classe de modelo ao usá-lo como um parâmetro de modelo em uma lista de classes base.  
  
```  
// C3203.cpp  
template< typename T >  
struct X {  
   void f(X) {}  
};  
  
template< typename T >  
struct Y : public X<Y> {   // C3203  
// try the following line instead  
// struct Y : public X<Y<T> > {  
   void f(Y) {}  
};  
  
int main() {  
   Y<int> y;  
}  
```  
  
 O exemplo a seguir gera C3203 e mostra como corrigi-lo:  
  
```  
// C3203_b.cpp  
// compile with: /c  
template <class T>  
struct S1 {};  
  
template <class T>  
class C1 {};  
  
typedef C1<S1> MyC1;   // C3203  
  
// OK  
template <template <class> class T>  
class C2 {};  
  
typedef C2<S1> MyC1;  
  
template <class T>  
class C3 {};  
  
typedef C3<S1<int> > MyC12;  
```  
  
 C3203 também pode ocorrer ao usar genéricos:  
  
```  
// C3203_c.cpp  
// compile with: /clr /c  
generic <class T>  
value struct GS1 {};  
  
generic <class T>  
value struct GC1 {};  
  
typedef GC1<GS1> MyGC1;   // C3203  
typedef GC1<GS1<int> > MyGC2;   // OK  
```
