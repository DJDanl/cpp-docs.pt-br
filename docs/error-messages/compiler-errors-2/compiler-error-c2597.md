---
title: C2597 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2597
dev_langs:
- C++
helpviewer_keywords:
- C2597
ms.assetid: 2e48127d-e3ff-4a40-8156-2863e45b1a38
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d110b67adda70ef47cfd9b06addd4370e22c5788
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2597"></a>C2597 de erro do compilador
referência inválida para membro não estático 'Identificador'  
  
 Possíveis causas:  
  
1.  Um membro não estático é especificado em uma função de membro estático. Para acessar o membro não estático, você deve passar ou criar uma instância da classe de local e usar um operador de acesso de membro (`.` ou `->`).  
  
2.  O identificador especificado não é um membro de uma classe, estrutura ou união. Verifique a ortografia do identificador.  
  
3.  Um operador de acesso de membro se refere a uma função não membro.  
  
4.  O exemplo a seguir gera C2597 e mostra como corrigi-lo:  
  
```  
// C2597.cpp  
// compile with: /c  
struct s1 {  
   static void func();  
   static void func2(s1&);  
   int i;  
};  
  
void s1::func() {  
   i = 1;    // C2597 - static function can't access non-static data member  
}  
  
// OK - fix by passing an instance of s1  
void s1::func2(s1& a) {  
   a.i = 1;  
}  
```
