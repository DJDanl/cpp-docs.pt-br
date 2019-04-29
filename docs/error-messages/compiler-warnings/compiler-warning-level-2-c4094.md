---
title: Compilador aviso (nível 2) C4094
ms.date: 11/04/2016
f1_keywords:
- C4094
helpviewer_keywords:
- C4094
ms.assetid: e68929fb-3a1c-4be7-920b-d5f79f534f99
ms.openlocfilehash: 73805afc897d14c6d2cc87490dfa0769a8de5193
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350498"
---
# <a name="compiler-warning-level-2-c4094"></a>Compilador aviso (nível 2) C4094

sem marcas 'token' não declarou nenhum símbolo

O compilador detectou uma declaração vazia usando uma estrutura sem marcas, união ou classe. A declaração é ignorada.

## <a name="example"></a>Exemplo

```
// C4094.cpp
// compile with: /W2
struct
{
};   // C4094

int main()
{
}
```

Essa condição gera um erro em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).