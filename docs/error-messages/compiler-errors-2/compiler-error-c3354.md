---
title: Erro do compilador C3354 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3354
dev_langs:
- C++
helpviewer_keywords:
- C3354
ms.assetid: 185de401-231e-4999-a149-172ee4c69d84
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 40f86702be19259bed7899cdbc5106346d6c6594
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46058530"
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
