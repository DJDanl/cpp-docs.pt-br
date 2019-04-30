---
title: Erro do compilador C2537
ms.date: 11/04/2016
f1_keywords:
- C2537
helpviewer_keywords:
- C2537
ms.assetid: aee81d8e-300e-4a8b-b6c4-b3828398b34e
ms.openlocfilehash: 437727b334087aef496dbb0a1f3f1c8cf2b45458
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345593"
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