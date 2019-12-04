---
title: Erro do compilador C2084
ms.date: 11/04/2016
f1_keywords:
- C2084
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
ms.openlocfilehash: 881ae051b2779fe674b31b64a7cbe7be7cf63705
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757885"
---
# <a name="compiler-error-c2084"></a>Erro do compilador C2084

a função '*Function*' já tem um corpo

A função já foi definida.

Antes do Visual Studio 2002,

- O compilador aceitaria várias especializações de modelo que resolveram para o mesmo tipo real, embora as definições adicionais nunca estejam disponíveis. O compilador agora detecta essas várias definições.

- `__int32` e `int` foram tratados como tipos separados. O compilador agora trata `__int32` como um sinônimo para `int`. Isso significa que o compilador detecta várias definições se uma função está sobrecarregada em `__int32` e `int` e fornece um erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2084:

```cpp
// C2084.cpp
void Func(int);
void Func(int) {}   // define function
void Func(int) {}   // C2084 second definition
```

Para corrigir esse erro, remova a definição duplicada:

```cpp
// C2084b.cpp
// compile with: /c
void Func(int);
void Func(int) {}
```
