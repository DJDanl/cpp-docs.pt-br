---
title: Erro do compilador C2084 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2084
dev_langs:
- C++
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 09ce703b6908257e37c2b7ff1b2714f1426f941f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052097"
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