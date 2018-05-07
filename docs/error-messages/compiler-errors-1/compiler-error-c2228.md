---
title: C2228 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2228
dev_langs:
- C++
helpviewer_keywords:
- C2228
ms.assetid: 901cadb1-ce90-4ae0-a360-547a9ba2ca18
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 969f622877c60bdc340dedf8a2416ac56b2ad0e0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2228"></a>C2228 de erro do compilador
esquerda de '.identifier' deve ter uma classe/struct/união  
  
 O operando à esquerda do período (.) não é uma classe, estrutura ou união.  
  
 O exemplo a seguir gera C2228:  
  
```  
// C2228.cpp  
int i;  
struct S {  
public:  
    int member;  
} s, *ps = &s;  
  
int main() {  
   i.member = 0;   // C2228 i is not a class type  
   ps.member = 0;  // C2228 ps is a pointer to a structure  
  
   s.member = 0;   // s is a structure type  
   ps->member = 0; // ps points to a structure S  
}  
```  
  
 Você também verá esse erro se você usar uma sintaxe incorreta ao usar extensões gerenciadas. Enquanto em outros idiomas do Visual Studio, você pode usar o operador ponto para acessar um membro de uma classe gerenciada, um ponteiro para o objeto em C++ significa que você deve usar o operador para acessar o membro ->:  
  
 Errado: `String * myString = checkedListBox1->CheckedItems->Item[0].ToString();`  
  
 Certo: `String * myString = checkedListBox1->CheckedItems->Item[0]->ToString();`