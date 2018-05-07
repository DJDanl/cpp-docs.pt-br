---
title: Compilador (nível 4) de aviso C4516 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4516
dev_langs:
- C++
helpviewer_keywords:
- C4516
ms.assetid: 6677bb1f-d26e-4ab9-8644-6b5a2a8f4ff8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d5ca56734d5bd9f2ddf66732ed894d805e368664
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4516"></a>Compilador C4516 de aviso (nível 4)
'class::symbol': declarações de acesso são preteridas; declarações de using membro fornecem uma alternativa melhor  
  
 O Comitê de C++ ANSI declarou declarações de acesso (alterando o acesso de um membro em uma classe derivada sem a [usando](../../cpp/using-declaration.md) palavra-chave) fiquem desatualizados. Declarações de acesso podem não ter suporte em versões futuras do C++.  
  
 O exemplo a seguir gera C4516:  
  
```  
// C4516.cpp  
// compile with: /W4  
class A  
{  
public:  
   void x(char);  
};  
  
class B : protected A  
{  
public:  
   A::x;  // C4516 on access-declaration  
   // use the following line instead  
   // using A::x; // using-declaration, ok  
};  
  
int main()  
{  
}  
```