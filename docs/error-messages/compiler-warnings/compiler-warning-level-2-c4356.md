---
title: "Compilador aviso (nível 2) C4356 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4356
dev_langs:
- C++
helpviewer_keywords:
- C4356
ms.assetid: 3af3defe-de33-43b6-bd6c-2c2e09e34f3f
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 335754557454c8ed8a6cb30052ae39848385494b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4356"></a>Compilador C4356 de aviso (nível 2)
'member': membro de dados estático não pode ser inicializado por meio da classe derivada  
  
 A inicialização de um membro de dados estáticos ill foi formada. O compilador aceita a inicialização.  
  
 Isso é uma alteração significativa no compilador do Visual C++ .NET 2003.  
  
 Para o código que funciona da mesma forma em todas as versões do Visual C++, inicialize o membro por meio da classe base.  
  
 Use o [aviso](../../preprocessor/warning.md) pragma para suprimir esse aviso.  
  
 O exemplo a seguir gera C4356:  
  
```  
// C4356.cpp  
// compile with: /W2 /EHsc  
#include <iostream>  
  
template <class T>  
class C {  
   static int n;  
};  
  
class D : C<int> {};  
  
int D::n = 0; // C4356  
// try the following line instead  
// int C<int>::n = 0;  
  
class A {  
public:  
   static int n;  
};  
  
class B : public A {};  
  
int B::n = 10;   // C4356  
// try the following line instead  
// int A::n = 99;  
  
int main() {  
   using namespace std;  
   cout << B::n << endl;  
}  
```
