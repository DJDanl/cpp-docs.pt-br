---
title: Erro do compilador C3354
ms.date: 11/04/2016
f1_keywords:
- C3354
helpviewer_keywords:
- C3354
ms.assetid: 185de401-231e-4999-a149-172ee4c69d84
ms.openlocfilehash: 1ff2967f602722c99b58b679324bd4f50575f109
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402600"
---
# <a name="compiler-error-c3354"></a>Erro do compilador C3354

'function': a função usada para criar um delegado não pode ter tipo de retorno 'type'

Os seguintes tipos são inválidos como tipos de retorno para um `delegate`:

- Ponteiro para função

- Ponteiro para membro

- Ponteiro para função de membro

- Referência à função

- Referência à função de membro

O exemplo a seguir gera C3354:

```
// C3354_2.cpp
// compile with: /clr /c
using namespace System;
typedef void ( *VoidPfn )();

delegate VoidPfn func(); // C3354
// try the following line instead
// delegate  void func();
```
