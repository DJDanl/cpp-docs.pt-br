---
title: Aviso do compilador (nível 2) C4094
ms.date: 11/04/2016
f1_keywords:
- C4094
helpviewer_keywords:
- C4094
ms.assetid: e68929fb-3a1c-4be7-920b-d5f79f534f99
ms.openlocfilehash: c90ad202e193f21955d396dd2aff6b39d3a968c7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174330"
---
# <a name="compiler-warning-level-2-c4094"></a>Aviso do compilador (nível 2) C4094

' token ' não marcado não declarou nenhum símbolo

O compilador detectou uma declaração vazia usando uma estrutura, União ou classe não marcada. A declaração é ignorada.

## <a name="example"></a>Exemplo

```cpp
// C4094.cpp
// compile with: /W2
struct
{
};   // C4094

int main()
{
}
```

Essa condição gera um erro em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
