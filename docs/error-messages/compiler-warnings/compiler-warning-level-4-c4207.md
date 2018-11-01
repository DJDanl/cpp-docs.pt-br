---
title: Compilador aviso (nível 4) C4207
ms.date: 11/04/2016
f1_keywords:
- C4207
helpviewer_keywords:
- C4207
ms.assetid: f4e09e3e-ac87-4489-8e3f-c8f76b82e721
ms.openlocfilehash: 44f49705bf197d7a42b80e50983e47a4c0ce7bed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50541112"
---
# <a name="compiler-warning-level-4-c4207"></a>Compilador aviso (nível 4) C4207

extensão não padrão usada: formulário de inicializador estendido

Com as extensões da Microsoft (/Ze), você pode inicializar uma matriz sem tamanho de `char` usando uma cadeia de caracteres entre chaves.

## <a name="example"></a>Exemplo

```
// C4207.c
// compile with: /W4
char c[] = { 'a', 'b', "cdefg" }; // C4207

int main()
{
}
```

Essas inicializações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).