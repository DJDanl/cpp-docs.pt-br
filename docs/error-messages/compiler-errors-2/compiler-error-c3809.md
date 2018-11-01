---
title: Erro do compilador C3809
ms.date: 11/04/2016
f1_keywords:
- C3809
helpviewer_keywords:
- C3809
ms.assetid: 37eca584-c20c-464e-8e45-a987214b7ce4
ms.openlocfilehash: 5ff57050980ddb770ea2fcfa4d0be4f42f5ee834
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50458793"
---
# <a name="compiler-error-c3809"></a>Erro do compilador C3809

'class': um gerenciado ou o tipo de WinRT não pode ter quaisquer funções/classes/interfaces de amigo

Tipos gerenciados e tipos de tempo de execução do Windows não permitir que amigos. Para corrigir esse erro, não declare amigos dentro gerenciado ou tipos de tempo de execução do Windows.

O exemplo a seguir gera C3809:

```
// C3809a.cpp
// compile with: /clr
ref class A {};

ref class B
{
public:
   friend ref class A;   // C3809
};

int main()
{
}
```