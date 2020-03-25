---
title: Erro do compilador C2026
ms.date: 11/04/2016
f1_keywords:
- C2026
helpviewer_keywords:
- C2026
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
ms.openlocfilehash: 9747b1edadc76ceeb502b2c6fd03496b91769f5a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208059"
---
# <a name="compiler-error-c2026"></a>Erro do compilador C2026

cadeia muito grande, caracteres à direita truncados

A cadeia de caracteres era maior do que o limite de 16380 caracteres de byte único.

Antes de as cadeias de caracteres adjacentes serem concatenadas, uma cadeia de caracteres não pode ter mais de 16380 caracteres de byte único.

Uma cadeia de caracteres Unicode de aproximadamente uma metade desse comprimento também geraria esse erro.

Se você tiver uma cadeia de caracteres definida da seguinte maneira, ela gerará C2026:

```
char sz[] =
"\
imagine a really, really \
long string here\
";
```

Você pode dividi-lo da seguinte maneira:

```
char sz[] =
"\
imagine a really, really "
"long string here\
";
```

Talvez você queira armazenar literais de cadeia de caracteres muito grandes (32K ou mais) em um recurso personalizado ou em um arquivo externo. Consulte [criando um novo recurso personalizado ou de dados](../../windows/creating-a-new-custom-or-data-resource.md) para obter mais informações.
