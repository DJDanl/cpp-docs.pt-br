---
title: Erro do compilador C2632
ms.date: 11/04/2016
f1_keywords:
- C2632
helpviewer_keywords:
- C2632
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
ms.openlocfilehash: 8ea3a106e8819bf067203f220ca51e17b87bfe46
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225456"
---
# <a name="compiler-error-c2632"></a>Erro do compilador C2632

' type1 ' seguido de ' type2 ' é inválido

Esse erro pode ser causado se houver um código ausente entre dois especificadores de tipo.

O exemplo a seguir gera C2632:

```cpp
// C2632.cpp
int float i;   // C2632
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003. **`bool`** Agora é um tipo adequado. Em versões anteriores, **`bool`** era um typedef, e você poderia criar identificadores com esse nome.

O exemplo a seguir gera C2632:

```cpp
// C2632_2.cpp
// compile with: /LD
void f(int bool);   // C2632
```

Para resolver esse erro para que o código seja válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do Visual C++, renomeie o identificador.
