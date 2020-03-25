---
title: Erro do compilador C2150
ms.date: 11/04/2016
f1_keywords:
- C2150
helpviewer_keywords:
- C2150
ms.assetid: 21e82a10-c1d4-4c0d-9dc6-c5d92ea42a31
ms.openlocfilehash: 57c21f7ee9435220a9ca0b50bb85567506b6ad3e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80207214"
---
# <a name="compiler-error-c2150"></a>Erro do compilador C2150

> '*Identifier*': o campo de bits deve ter o tipo ' int ', ' signed int ' ou ' unsigned int '

É necessário que o tipo de base para um campo de bits seja `int`, `signed int`ou `unsigned int`.

## <a name="example"></a>Exemplo

Este exemplo mostra como você pode encontrar C2150 e como você pode corrigi-lo:

```cpp
// C2150.cpp
// compile with: /c
struct A {
   float a : 8;    // C2150
   int i : 8;      // OK
};
```
