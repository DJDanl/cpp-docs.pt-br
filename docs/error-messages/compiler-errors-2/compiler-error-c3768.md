---
title: Erro do compilador C3768
ms.date: 11/04/2016
f1_keywords:
- C3768
helpviewer_keywords:
- C3768
ms.assetid: 091f0d53-1dff-43fd-813d-5c43c85b6ab0
ms.openlocfilehash: e9c385fd178dc967e72f5e0ca7fab27b28ad962f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400208"
---
# <a name="compiler-error-c3768"></a>Erro do compilador C3768

> não é possível obter o endereço de uma função virtual vararg em código gerenciado puro

## <a name="remarks"></a>Comentários

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Ao compilar com **/clr: pure**, é possível tomar o endereço de uma máquina virtual `vararg` função.

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