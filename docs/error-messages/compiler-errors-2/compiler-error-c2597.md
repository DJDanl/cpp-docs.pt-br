---
title: C2597 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2597
dev_langs:
- C++
helpviewer_keywords:
- C2597
ms.assetid: 2e48127d-e3ff-4a40-8156-2863e45b1a38
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 45cf9054736117526ee5e79c0bafdd8fdee7c2e2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33229344"
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