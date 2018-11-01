---
title: Erro do compilador C2356
ms.date: 11/04/2016
f1_keywords:
- C2356
helpviewer_keywords:
- C2356
ms.assetid: 84d5a816-9a61-4d45-9978-38e485bbf767
ms.openlocfilehash: 0166cce6011017b8a18821666083f7c47f58b7a9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508093"
---
# <a name="compiler-error-c2356"></a>Erro do compilador C2356

segmento de inicialização não deve mudar durante unidade de tradução

Possíveis causas:

- `#pragma init_seg` precedido pelo código de inicialização de segmento

- `#pragma init_seg` precedido por outra `#pragma init_seg`

Para resolver, mova o código de inicialização de segmento para o início do módulo. Se várias áreas devem ser inicializadas, mova-os para separar os módulos.

O exemplo a seguir gera C2356:

```
// C2356.cpp
#pragma warning(disable : 4075)

int __cdecl myexit(void (__cdecl *)());
int __cdecl myexit2(void (__cdecl *)());

#pragma init_seg(".mine$m",myexit)
#pragma init_seg(".mine$m",myexit2)   // C2356
```