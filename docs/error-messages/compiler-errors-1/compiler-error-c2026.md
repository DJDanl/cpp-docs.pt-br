---
title: Erro do compilador C2026
description: Descreve o erro C2026 do compilador C/C++ da Microsoft, suas causas e como resolvê-los.
ms.date: 09/25/2020
f1_keywords:
- C2026
helpviewer_keywords:
- C2026
ms.assetid: 8e64b6e1-b967-479b-be97-d12dc4a8e389
ms.openlocfilehash: 39195568f964f07c6131fa43ef4a0f06121795da
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414042"
---
# <a name="compiler-error-c2026"></a>Erro do compilador C2026

> cadeia muito grande, caracteres à direita truncados

A cadeia de caracteres era maior do que o limite de 16380 caracteres de byte único.

## <a name="remarks"></a>Comentários

Antes que as cadeias de caracteres adjacentes sejam concatenadas, uma cadeia de caracteres não pode ter mais de 16380 caracteres de byte único.

Uma cadeia de caracteres Unicode de aproximadamente uma metade desse comprimento também geraria esse erro.

## <a name="example"></a>Exemplo

Se você tiver uma cadeia de caracteres definida da seguinte maneira, ela gerará C2026:

```C
char sz[] =
"\
imagine a really, really \
long string here\
";
```

Você pode dividi-lo da seguinte maneira:

```C
char sz[] =
"\
imagine a really, really "
"long string here\
";
```

Talvez você queira armazenar literais de cadeia de caracteres muito grandes (32K ou mais) em um recurso personalizado ou em um arquivo externo. Para obter mais informações, consulte [para criar um novo recurso personalizado ou de dados](../../windows/binary-editor.md#to-create-a-new-custom-or-data-resource).
