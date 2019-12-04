---
title: Erro do compilador C2833
ms.date: 11/04/2016
f1_keywords:
- C2833
helpviewer_keywords:
- C2833
ms.assetid: b9418ce1-e2ee-4599-8959-6fde89c27569
ms.openlocfilehash: c1467a3c67cccf28cc6b9bd0f987fe77b8da8988
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757872"
---
# <a name="compiler-error-c2833"></a>Erro do compilador C2833

' operator Operator ' não é um operador ou tipo reconhecido

A palavra `operator` deve ser seguida por um operador que você deseja substituir ou um tipo que você deseja converter.

Para obter uma lista dos operadores que você pode definir em um tipo gerenciado, consulte [operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).

O exemplo a seguir gera C2833:

```cpp
// C2833.cpp
// compile with: /c
class A {};

void operator ::* ();   // C2833
void operator :: ();   // OK
```
