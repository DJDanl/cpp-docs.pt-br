---
title: Erro do compilador C3768
ms.date: 11/04/2016
f1_keywords:
- C3768
helpviewer_keywords:
- C3768
ms.assetid: 091f0d53-1dff-43fd-813d-5c43c85b6ab0
ms.openlocfilehash: 534be9e3873276313335ca921264be92c9259b93
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165737"
---
# <a name="compiler-error-c3768"></a>Erro do compilador C3768

> Não é possível obter o endereço de uma função virtual vararg em código gerenciado puro

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Ao compilar com **/CLR: Pure**, você não pode tomar o endereço de uma função de `vararg` virtual.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3768:

```cpp
// C3768.cpp
// compile with: /clr:pure
struct A
{
   virtual void f(...);
};

int main()
{
   &(A::f);   // C3768
}
```
