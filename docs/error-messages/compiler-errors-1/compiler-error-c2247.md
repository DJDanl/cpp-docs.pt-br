---
title: C2247 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2247
dev_langs:
- C++
helpviewer_keywords:
- C2247
ms.assetid: 72efa03e-615e-4ef9-aede-0a98654b20fd
caps.latest.revision: 13
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
ms.openlocfilehash: fbee361d4a80ca9feabc2a828b5b1f04b1cbd514
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2247"></a>C2247 de erro do compilador
'identifier' não está acessível porque 'class' usa 'especificador' para herdar de 'class'  
  
 `identifier`é herdada de uma classe declarada com acesso particular ou protegido.  
  
 O exemplo a seguir gera C2247:  
  
```  
// C2247.cpp  
class A {  
public:  
   int i;  
};  
class B : private A {};    // B inherits a private A  
class C : public B {} c;   // so even though C's B is public  
int j = c.i;               // C2247, i not accessible  
```  
  
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: controle com membros protegidos de acesso. Um membro protegido (n) só pode ser acessado através de uma função de membro de uma classe (B) que herda da classe (A) dos quais (n) é um membro.  
  
 Para código que seja válido no Visual Studio .NET 2003 e o Visual Studio .NET em versões do Visual C++, declare o membro a ser um amigo do tipo. Herança pública também pode ser usada.  
  
```  
// C2247b.cpp  
// compile with: /c  
// C2247 expected  
class A {  
public:  
   void f();  
   int n;  
};  
  
class B: protected A {  
   // Uncomment the following line to resolve.  
   // friend void A::f();  
};  
  
void A::f() {  
   B b;  
   b.n;  
}  
```  
  
 C2247 também podem ser gerados como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: agora classes base privada inacessíveis. Uma classe (A) é uma classe base particular para um tipo não (B) deve estar acessível para um tipo (C) que usa B como uma classe base.  
  
 Para o código que é válido no Visual Studio .NET 2003 e no versões do Visual Studio .NET do Visual C++, use o operador de escopo.  
  
```  
// C2247c.cpp  
// compile with: /c  
struct A {};  
  
struct B: private A {};  
  
struct C : B {  
   void f() {  
      A *p1 = (A*) this;   // C2247  
      // try the following line instead  
      // ::A *p2 = (::A*) this;  
   }  
};  
```
