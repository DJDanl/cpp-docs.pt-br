---
title: Erro do compilador C2021
ms.date: 11/04/2016
f1_keywords:
- C2021
helpviewer_keywords:
- C2021
ms.assetid: 064f32e2-3794-48d5-9767-991003dcb36a
ms.openlocfilehash: 6492dfffbb5a2f80ea543d4248c0f77759c0a521
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50513994"
---
# <a name="compiler-error-c2021"></a>Erro do compilador C2021

valor de expoente, não 'character' esperado

O caractere usado como o expoente de uma constante de ponto flutuante não é um número válido. Certifique-se de usar um expoente que está no intervalo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2021:

```
// C2021.cpp
float test1=1.175494351E;   // C2021
```

## <a name="example"></a>Exemplo

Solução possível:

```
// C2021b.cpp
// compile with: /c
float test2=1.175494351E8;
```