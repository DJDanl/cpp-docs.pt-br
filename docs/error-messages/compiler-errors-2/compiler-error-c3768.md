---
title: C3768 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3768
dev_langs:
- C++
helpviewer_keywords:
- C3768
ms.assetid: 091f0d53-1dff-43fd-813d-5c43c85b6ab0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5e6b7a2d1617591609f75b2b07f1a94983ee22f4
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704952"
---
# <a name="compiler-error-c3768"></a>C3768 de erro do compilador

> não é possível obter o endereço de uma função virtual vararg em código gerenciado puro

## <a name="remarks"></a>Comentários

O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Ao compilar com **/clr: pure**, você não pode obter o endereço de uma máquina virtual `vararg` função.

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