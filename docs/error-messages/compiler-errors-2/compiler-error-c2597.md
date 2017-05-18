---
title: C2597 de erro do compilador | Documentos do Microsoft
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
ms.openlocfilehash: d61701fb5c33fe5849457a1130190590b0e0f119
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2597"></a>C2597 de erro do compilador
referência ilegal para membro não estático 'Identificador'  
  
 Possíveis causas:  
  
1.  Um membro não estático é especificado em uma função de membro estático. Para acessar o membro não estático, você deve passar ou criar uma instância da classe local e usar um operador de acesso de membro (`.` ou `->`).  
  
2.  O identificador especificado não é um membro de uma classe, estrutura ou união. Verifica a ortografia de identificador.  
  
3.  Um operador de acesso de membro se refere a uma função não-membro.  
  
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
