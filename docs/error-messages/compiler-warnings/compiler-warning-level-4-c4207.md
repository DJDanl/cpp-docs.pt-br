---
title: Aviso do compilador (nível 4) C4207
ms.date: 11/04/2016
f1_keywords:
- C4207
helpviewer_keywords:
- C4207
ms.assetid: f4e09e3e-ac87-4489-8e3f-c8f76b82e721
ms.openlocfilehash: e694f96d7f6271686d1b2a19e5a12e5e08e1cfbe
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219944"
---
# <a name="compiler-warning-level-4-c4207"></a>Aviso do compilador (nível 4) C4207

extensão não padrão usada: formulário de inicializador estendido

Com o Microsoft Extensions (/Ze), você pode inicializar uma matriz sem tamanho **`char`** usando uma cadeia de caracteres entre chaves.

## <a name="example"></a>Exemplo

```c
// C4207.c
// compile with: /W4
char c[] = { 'a', 'b', "cdefg" }; // C4207

int main()
{
}
```

Essas inicializações são inválidas sob compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
