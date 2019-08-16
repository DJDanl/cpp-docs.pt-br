---
title: Erro do compilador C2778
ms.date: 11/04/2016
f1_keywords:
- C2778
helpviewer_keywords:
- C2778
ms.assetid: b24cb732-2914-42cc-8928-e2d87b393428
ms.openlocfilehash: 98b5bf0a1315236f3ce96fd4b8c140ce1ab70a9f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501045"
---
# <a name="compiler-error-c2778"></a>Erro do compilador C2778

GUID formado de forma inadequada em _ declspec (UUID ())

Um GUID incorreto é fornecido para o atributo estendido [UUID](../../cpp/uuid-cpp.md) .

O GUID deve ser uma cadeia de caracteres de números hexadecimais com o seguinte formato:

```
// C2778a.cpp
// compile with: /c
struct __declspec(uuid("00000000-0000-0000-0000-000000000000")) A {};
struct __declspec(uuid("{00000000-0000-0000-0000-000000000000}")) B{};
```

O `uuid` atributo estendido aceita cadeias de caracteres reconhecidas por [CLSIDFromString](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromstring), com ou sem delimitadores de chaves.

O exemplo a seguir gera C2778:

```
// C2778b.cpp
struct __declspec(uuid(" 00000000-0000-0000-0000-000000000000 ")) C { };   // C2778
struct __declspec(uuid("00000000000000000000000000000000")) D { };   // C2778
```