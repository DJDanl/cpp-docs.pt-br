---
title: Erro do compilador C2833
ms.date: 11/04/2016
f1_keywords:
- C2833
helpviewer_keywords:
- C2833
ms.assetid: b9418ce1-e2ee-4599-8959-6fde89c27569
ms.openlocfilehash: dad6a64f145c3d49d3b43044ea76a11d35827943
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460535"
---
# <a name="compiler-error-c2833"></a>Erro do compilador C2833

'operator operador' não é um operador ou tipo reconhecido

A palavra `operator` deve ser seguido por um operador que você deseja substituir ou um tipo que você deseja converter.

Para obter uma lista dos operadores que podem ser definidos em um tipo gerenciado, consulte [operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).

O exemplo a seguir gera C2833:

```
// C2833.cpp
// compile with: /c
class A {};

void operator ::* ();   // C2833
void operator :: ();   // OK
```