---
title: Erro do compilador C2632
ms.date: 11/04/2016
f1_keywords:
- C2632
helpviewer_keywords:
- C2632
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
ms.openlocfilehash: b92d44bcfd04d4de7b39c5bdab5ee146d9b6693b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437911"
---
# <a name="compiler-error-c2632"></a>Erro do compilador C2632

'type1' seguido de 'type2' é ilegal

Esse erro pode ser causado se faltar código entre dois especificadores de tipo.

O exemplo a seguir gera C2632:

```
// C2632.cpp
int float i;   // C2632
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003. `bool` Agora é um tipo adequado. Nas versões anteriores, `bool` era um typedef, e você pode criar identificadores com esse nome.

O exemplo a seguir gera C2632:

```
// C2632_2.cpp
// compile with: /LD
void f(int bool);   // C2632
```

Para resolver esse erro para que o código é válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, renomeie o identificador.