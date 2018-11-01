---
title: Erro do compilador C2084
ms.date: 11/04/2016
f1_keywords:
- C2084
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
ms.openlocfilehash: 9aaf3a88e63234dfb842e4b48afd6e55595e96ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50571308"
---
# <a name="compiler-error-c2084"></a>Erro do compilador C2084

função '*função*' já tem um corpo

A função já foi definida.

Nas versões do Visual C++ anteriores ao Visual Studio 2002,

- O compilador aceite várias especializações de modelo que é resolvido para o mesmo tipo real, embora as definições adicionais nunca estarão disponíveis. Agora, o compilador detecta essas várias definições.

- `__int32` e `int` foram tratados como tipos separados. O compilador agora trata `__int32` como um sinônimo para `int`. Isso significa que o compilador detecta se uma função estiver sobrecarregada em ambas as várias definições `__int32` e `int` e apresentará um erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2084:

```cpp
// C2084.cpp
void Func(int);
void Func(int) {}   // define function
void Func(int) {}   // C2084 second definition
```

Para corrigir esse erro, remova a definição duplicada:

```
// C2084b.cpp
// compile with: /c
void Func(int);
void Func(int) {}
```