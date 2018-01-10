---
title: C4355 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4355
dev_langs: C++
helpviewer_keywords: C4355
ms.assetid: b819ecab-8a07-42d7-8fa4-1180d51626c0
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b7194431235e1bf375d4e6b99b66bf9a4b32e63a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4355"></a>C4355 de aviso do compilador
'this' : usado na lista de inicializadores do membro base  
  
 O **isso** ponteiro é válido somente dentro de funções de membro não estático. Ele não pode ser usado na lista de inicializador para uma classe base.  
  
 Os construtores de classe base e construtores de membro de classe são chamados antes **isso** construtor. Na verdade, passar um ponteiro para um objeto não construído para outro construtor. Se esses outros construtores acessar todos os membros ou chamam funções de membro sobre isso, o resultado será indefinido. Você não deve usar o **isso** ponteiro até que todos os construção seja concluída.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4355:  
  
```  
// C4355.cpp  
// compile with: /w14355 /c  
#include <tchar.h>  
  
class CDerived;  
class CBase {  
public:  
   CBase(CDerived *derived): m_pDerived(derived) {};  
   ~CBase();  
   virtual void function() = 0;  
  
   CDerived * m_pDerived;  
};  
  
class CDerived : public CBase {  
public:  
   CDerived() : CBase(this) {};   // C4355 "this" used in derived c'tor  
   virtual void function() {};  
};  
  
CBase::~CBase() {  
   m_pDerived -> function();  
}  
  
int main() {  
   CDerived myDerived;  
}  
```