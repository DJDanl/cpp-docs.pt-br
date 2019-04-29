---
title: Erro do compilador C2026
ms.date: 11/04/2016
f1_keywords:
- C2026
helpviewer_keywords:
- C2026
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
ms.openlocfilehash: da4c03c681f95efaa5edb159869315b41d027e99
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303522"
---
# <a name="compiler-error-c2026"></a>Erro do compilador C2026

cadeia de caracteres muito grande, caracteres truncados à direita

A cadeia de caracteres era maior que o limite de caracteres de byte único 16380.

Antes de cadeias de caracteres adjacentes são concatenadas, uma cadeia de caracteres não pode ser maior do que 16380 caracteres de byte único.

Uma cadeia de caracteres Unicode de tamanho de aproximadamente metade essa também seria gerar esse erro.

Se você tiver uma cadeia de caracteres definida da seguinte maneira, ele gera C2026:

```
char sz[] =
"\
imagine a really, really \
long string here\
";
```

Você pode dividi-la da seguinte maneira:

```
char sz[] =
"\
imagine a really, really "
"long string here\
";
```

Você pode desejar armazenar excepcionalmente grande de cadeias de caracteres literais (32K ou mais) em um recurso personalizado ou um arquivo externo. Ver [criando um recurso de dados ou novo personalizado](../../windows/creating-a-new-custom-or-data-resource.md) para obter mais informações.