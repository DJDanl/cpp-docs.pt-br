---
title: Aviso do compilador (nível 4) C4207
ms.date: 11/04/2016
f1_keywords:
- C4207
helpviewer_keywords:
- C4207
ms.assetid: f4e09e3e-ac87-4489-8e3f-c8f76b82e721
ms.openlocfilehash: 1ff669512f85dfed9bab307c2986e7858285461d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161380"
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
