---
title: Erro do compilador C2778
ms.date: 11/04/2016
f1_keywords:
- C2778
helpviewer_keywords:
- C2778
ms.assetid: b24cb732-2914-42cc-8928-e2d87b393428
ms.openlocfilehash: 247aba1b4dfe6b6d6db1e2b8f46f2aa08abf1a79
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739981"
---
# <a name="compiler-error-c2778"></a>Erro do compilador C2778

GUID formado de forma inadequada no __declspec (UUID ())

Um GUID incorreto é fornecido para o atributo estendido [UUID](../../cpp/uuid-cpp.md) .

O GUID deve ser uma cadeia de caracteres de números hexadecimais com o seguinte formato:

```cpp
// C2778a.cpp
// compile with: /c
struct __declspec(uuid("00000000-0000-0000-0000-000000000000")) A {};
struct __declspec(uuid("{00000000-0000-0000-0000-000000000000}")) B{};
```

O atributo estendido `uuid` aceita cadeias de caracteres reconhecidas por [CLSIDFromString](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromstring), com ou sem delimitadores de chaves.

O exemplo a seguir gera C2778:

```cpp
// C2778b.cpp
struct __declspec(uuid(" 00000000-0000-0000-0000-000000000000 ")) C { };   // C2778
struct __declspec(uuid("00000000000000000000000000000000")) D { };   // C2778
```
