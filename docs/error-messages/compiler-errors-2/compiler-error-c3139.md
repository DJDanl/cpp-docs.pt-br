---
title: Erro do compilador C3139
ms.date: 11/04/2016
f1_keywords:
- C3139
helpviewer_keywords:
- C3139
ms.assetid: 95c92263-10ac-4ff3-b385-6312dd92adbc
ms.openlocfilehash: f224be74a94e0e769e7c26bc99b4790d69f6b65b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50521194"
---
# <a name="compiler-error-c3139"></a>Erro do compilador C3139

'struct': não é possível exportar um UDT sem membros

Você tentou aplicar a [exportar](../../windows/export.md) de atributo a um vazio UDT (tipo definido pelo usuário). Por exemplo:

```
// C3139.cpp
#include "unknwn.h"
[emitidl];
[module(name=xx)];

[export] struct MyStruct {   // C3139 empty type
};
int main(){}
```