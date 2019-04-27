---
title: Aviso do compilador C4355
ms.date: 11/04/2016
f1_keywords:
- C4355
helpviewer_keywords:
- C4355
ms.assetid: b819ecab-8a07-42d7-8fa4-1180d51626c0
ms.openlocfilehash: 6b74c8dd5ce9860cb218d21790f12ba05e9be22f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62151819"
---
# <a name="compiler-warning-c4355"></a>Aviso do compilador C4355

'this' : usado na lista de inicializadores do membro base

O **isso** ponteiro é válido somente dentro de funções de membro não estático. Ele não pode ser usado na lista de inicializadores para uma classe base.

Os construtores de classe base e os construtores de membro de classe são chamados antes **isso** construtor. Na verdade, você passou um ponteiro para um objeto não construído para outro construtor. Se esses outros construtores acessar todos os membros ou chamam funções de membro sobre isso, o resultado será indefinido. Você não deve usar o **isso** ponteiro até que todos os construção seja concluída.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

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