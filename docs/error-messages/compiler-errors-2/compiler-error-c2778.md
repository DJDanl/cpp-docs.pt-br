---
title: Erro do compilador C2778
ms.date: 11/04/2016
f1_keywords:
- C2778
helpviewer_keywords:
- C2778
ms.assetid: b24cb732-2914-42cc-8928-e2d87b393428
ms.openlocfilehash: 56c316ac971d0bdd1a0ca27ef8d4282acbe24779
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490500"
---
# <a name="compiler-error-c2778"></a>Erro do compilador C2778

GUID formado incorretamente em __declspec(uuid())

Um GUID incorreto é fornecido para o [uuid](../../cpp/uuid-cpp.md) atributo estendido.

O GUID deve ser uma cadeia de caracteres de números hexadecimais com o seguinte formato:

```
// C2778a.cpp
// compile with: /c
struct __declspec(uuid("00000000-0000-0000-0000-000000000000")) A {};
struct __declspec(uuid("{00000000-0000-0000-0000-000000000000}")) B{};
```

O `uuid` atributo estendido aceita cadeias de caracteres reconhecidas pelo [CLSIDFromString](/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring), com ou sem delimitadores.

O exemplo a seguir gera C2778:

```
// C2778b.cpp
struct __declspec(uuid(" 00000000-0000-0000-0000-000000000000 ")) C { };   // C2778
struct __declspec(uuid("00000000000000000000000000000000")) D { };   // C2778
```