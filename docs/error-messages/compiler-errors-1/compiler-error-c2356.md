---
title: Erro do compilador C2356
ms.date: 11/04/2016
f1_keywords:
- C2356
helpviewer_keywords:
- C2356
ms.assetid: 84d5a816-9a61-4d45-9978-38e485bbf767
ms.openlocfilehash: e306c5a8f9175bc3c7902b20263aa2e451944182
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759926"
---
# <a name="compiler-error-c2356"></a>Erro do compilador C2356

o segmento de inicialização não deve ser alterado durante a unidade de tradução

Possíveis causas:

- `#pragma init_seg` precedido pelo código de inicialização do segmento

- `#pragma init_seg` precedido por outro `#pragma init_seg`

Para resolver, mova o código de inicialização do segmento para o início do módulo. Se várias áreas precisarem ser inicializadas, mova-as para módulos separados.

O exemplo a seguir gera C2356:

```cpp
// C2356.cpp
#pragma warning(disable : 4075)

int __cdecl myexit(void (__cdecl *)());
int __cdecl myexit2(void (__cdecl *)());

#pragma init_seg(".mine$m",myexit)
#pragma init_seg(".mine$m",myexit2)   // C2356
```
