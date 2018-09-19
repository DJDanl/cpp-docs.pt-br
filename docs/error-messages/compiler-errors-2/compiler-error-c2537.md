---
title: Erro do compilador C2537 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2537
dev_langs:
- C++
helpviewer_keywords:
- C2537
ms.assetid: aee81d8e-300e-4a8b-b6c4-b3828398b34e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 65db4fa66d147cc46c1a6013d07048892dfa0800
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46136017"
---
# <a name="compiler-error-c2537"></a>Erro do compilador C2537

'especificador de ': especificação de vínculo inválida

Possíveis causas:

1. Não há suporte para o especificador de vinculação. Há suporte para o especificador de vinculação "C".

1. Vínculo "C" é especificado para mais de uma função em um conjunto de funções sobrecarregadas. Isso não é permitido.

O exemplo a seguir gera C2537:

```
// C2537.cpp
// compile with: /c
extern "c" void func();   // C2537
extern "C" void func2();   // OK
```