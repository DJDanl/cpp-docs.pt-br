---
title: Aviso do compilador (nível 4) C4207
ms.date: 11/04/2016
f1_keywords:
- C4207
helpviewer_keywords:
- C4207
ms.assetid: f4e09e3e-ac87-4489-8e3f-c8f76b82e721
ms.openlocfilehash: bd18964f8969bc75967de435e2ca3099b12213e0
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541875"
---
# <a name="compiler-warning-level-4-c4207"></a>Aviso do compilador (nível 4) C4207

extensão não padrão usada: formulário de inicializador estendido

Com o Microsoft Extensions (/Ze), você pode inicializar uma matriz sem tamanho de `char` usando uma cadeia de caracteres entre chaves.

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