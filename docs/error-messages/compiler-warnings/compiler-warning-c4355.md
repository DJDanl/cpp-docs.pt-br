---
title: Aviso do compilador C4355
ms.date: 11/04/2016
f1_keywords:
- C4355
helpviewer_keywords:
- C4355
ms.assetid: b819ecab-8a07-42d7-8fa4-1180d51626c0
ms.openlocfilehash: ddc0d1968ae373ff1e81c98a513e6f84fdb885e1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165321"
---
# <a name="compiler-warning-c4355"></a>Aviso do compilador C4355

'this' : usado na lista de inicializadores do membro base

**Esse** ponteiro é válido somente dentro de funções de membro não estáticas. Ele não pode ser usado na lista de inicializadores para uma classe base.

Os construtores de classe base e construtores de membro de classe são chamados antes **desse** Construtor. Na verdade, você passou um ponteiro para um objeto não construído para outro construtor. Se esses outros construtores acessarem quaisquer membros ou chamarem funções de membro, o resultado será indefinido. Você não deve usar o ponteiro até que **toda a construção** tenha sido concluída.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4355:

```cpp
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
