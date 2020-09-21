---
title: Erro do compilador C2021
ms.date: 11/04/2016
f1_keywords:
- C2021
helpviewer_keywords:
- C2021
ms.assetid: 064f32e2-3794-48d5-9767-991003dcb36a
ms.openlocfilehash: 97d1776bb3b29b3691ae31bb060410a83d581e2d
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743289"
---
# <a name="compiler-error-c2021"></a>Erro do compilador C2021

valor de expoente esperado, não ' character '

O caractere usado como o expoente de uma constante de ponto flutuante não é um número válido. Certifique-se de usar um expoente que esteja no intervalo.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2021:

```cpp
// C2021.cpp
float test1=1.175494351E;   // C2021
```

Resolução possível:

```cpp
// C2021b.cpp
// compile with: /c
float test2=1.175494351E8;
```
