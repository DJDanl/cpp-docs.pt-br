---
title: Erro do compilador C2632
ms.date: 11/04/2016
f1_keywords:
- C2632
helpviewer_keywords:
- C2632
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
ms.openlocfilehash: f69d43bf50f5f13957e49d1e9ffa798a3db5a7b3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754687"
---
# <a name="compiler-error-c2632"></a>Erro do compilador C2632

' type1 ' seguido de ' type2 ' é inválido

Esse erro pode ser causado se houver um código ausente entre dois especificadores de tipo.

O exemplo a seguir gera C2632:

```cpp
// C2632.cpp
int float i;   // C2632
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003. `bool` agora é um tipo adequado. Nas versões anteriores, `bool` era um typedef, e você poderia criar identificadores com esse nome.

O exemplo a seguir gera C2632:

```cpp
// C2632_2.cpp
// compile with: /LD
void f(int bool);   // C2632
```

Para resolver esse erro para que o código seja válido nas versões do Visual Studio .NET 2003 e do Visual Studio .NET do Visual C++, renomeie o identificador.
